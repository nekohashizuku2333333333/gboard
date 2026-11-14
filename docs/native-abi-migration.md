# Gboard 引擎去 JNI / 去 ELF 加载器迁移研究

本文记录对 `gboard_apk_source/resources/lib/arm64-v8a/libintegrated_shared_object.so`
（Gboard 18.5.9）的反编译结果，以及把现有
「ELF 加载器 + JNI 兼容层」替换为原生方案的可执行迁移路径。

> 结论先行：
> 1. **JNI 热路径已经去掉。** 引擎的 136 个注册 native 都是很薄的 JNI 封送，
>    真正的实现是 C++ 对象 + vtable。`GboardIME/engine/gboard_native_abi.h`
>    已用直接 ABI 覆盖 append、fill、候选读取、选择、删除、预测和 reset；
>    `hmm_candidates.c` 的热路径不再创建假 Java 对象。仓库 889 项测试通过。
> 2. **ELF 加载器可以去掉。** 离线 ELF→Mach-O 转换已验证可被 dyld 加载，
>    TPIDR 站点可在转换期改写，构造函数可按构建期探针白名单固化。
> 3. **Phase 0 已完成。** 补齐 `__strchr_chk`、`__open_2`、`__read_chk`、
>    `__write_chk`、`__strlen_chk`、`__strncpy_chk2`、`__strrchr_chk`、
>    `__pread_chk` 后，旧加载器已能初始化引擎（实测 `init=1`）。本轮的
>    直接 vtable 探针也已在真实引擎上验证 `GetCandidateCount=403`、
>    `GetCandidateRange=(0,5)`。剩余的主要工程风险是 **Android libc++
>    字符串布局**（见 1.6），不是加载方式。

---

## 1. 实测数据

### 1.1 二进制

| 项目 | 值 |
|---|---|
| `.so` 大小 | 35,234,520 B |
| ELF | AArch64, stripped, 167 个 `Java_*` 导出 |
| NEEDED | `libdl`, `liblog`, `libaaudio`, `libjnigraphics`, `libm`, `libc` |
| 重定位 | 156,390 RELATIVE；13 ABS64；22 GLOB_DAT；368 JUMP_SLOT；无 IRELATIVE/TLS |
| TPIDR 站点 | 4,002 个，分布在 974 个代码页 |
| init_array | 1,021 项；探针结果 1,019 安全、1 崩溃、1 挂起 |
| 注册 native | 引擎表 136 项 @ file vaddr `0x1ffcff8`；另有第二张表 144 项 @ `0x200c308`（gesture/其他） |
| pinyin 路径使用 | 37 项；仓库现有 `hmm_native.c` 缺少其中 19 项 |
| 词典包 | 71 个文件，22MB；`pinyin_system_dictionary` 4.7MB、`pinyin_bigram` 5.1MB、`pinyin_lstm_tflite` 6.8MB、`pinyin_sentence_piece_model` 703KB |

### 1.2 Java 侧（jadx）

`xapk_unpacked/base.apk` 已用 jadx 解出 21,804 个 Java 文件：

- `com.google.android.apps.inputmethod.libs.hmm.EngineFactory`
  — 注册 native、持有 factory 句柄。
- `...hmm.HmmEngineInterfaceImpl` — 100+ 个 native 声明，覆盖候选、分段、
  token、上下文、预测、会话。
- `defpackage.hip`（869 行）— `AbstractHmmEngineWrapper` 状态机：
  `append`、候选选择、分段、unselect、token 候选。
- `...chinese.ime.hmm.AbstractHmmChineseDecodeProcessor`（1,379 行）—
  中文输入主流程。
- `...pinyin.AbstractHmmPinyinDecodeProcessor`（218 行）— 拼音入口，
  委托 `hki` / `hip`。

Java 侧只做状态机和 JNI 封送；HMM 解码、词典、语言模型都在 native。

### 1.3 关键 JNI 封送（反编译证据）

Ghidra 分析（image base `0x100000`）得到引擎表 136 项、131 个唯一 native 函数（5 项共享入口）。
`docs/decompiled/jni_wrappers.c` 是完整反编译；以下为关键片段：

```c
/* nativeAppend(J[L...ScoredInput;I)I */
FUN_011cdfd0(env, &inputs, &vec);              // Java ScoredInput[] -> std::vector
FUN_011ca86c();                                 // vector 构造/finalize
uVar2 = (**(code **)(*engine + 0x38))(engine, &vec, type);  // C++ vtable +0x38
```

```c
/* nativeSelectCandidate(JI)Z */
FUN_011cdf74();                                 // 取 engine
uVar1 = (**(code **)(vtable + 0x1d8))();        // bool SelectCandidate(int)
```

```c
/* nativeGetCandidateString(JI)Ljava/lang/String; */
FUN_011cdee0();
(**(code **)(vtable + 0x200))(out, handle, index);  // std::string 返回
// 之后才 NewStringUTF
```

```c
/* nativeGetCandidateRange(JI)L...Range; */
uVar1 = FUN_011cdee0();
(**(code **)(vtable + 0x220))(uVar1, index);     // 8 字节 Range 返回
FUN_011cde90(); FUN_011cda44();                  // 构造 Java Range（JNI-only）
```

推论：

- `ScoredInput` 的 native 形式是 **0x20 字节/元素**：
  字符串（24 字节）+ `float` + padding。
- `Range` 是 **两个 int32**，按 8 字节值返回。
- 字符串以 `std::string` 返回/传入，**但布局不是 macOS libc++ 的默认布局**；
  封送层做了显式转换（见 1.6）。
- 引擎是标准 Itanium C++ ABI 对象，`vtable` 在偏移 0 处。

### 1.4 关键 vtable 偏移

完整表见 `docs/native_abi.tsv`。拼音热路径：

| native | C++ 方法 | vtable offset |
|---|---|---|
| `nativeReset` | Reset | `0xa0` |
| `nativeAppend` | Append(vector&lt;ScoredInput&gt;*, type) | `0x38` |
| `nativeFillCandidateList` | FillCandidateList(Range*) | `0x1c8` |
| `nativeFillTokenCandidateList` | FillTokenCandidateList(Range*) | `0x198` |
| `nativeFillPredictionCandidateList` | FillPredictionCandidateList() | `0x278` |
| `nativeGetCandidateCount` | GetCandidateCount | `0x1d0` |
| `nativeSelectCandidate` | SelectCandidate(int) | `0x1d8` |
| `nativeDeleteCandidate` | DeleteCandidate(int) | `0x1e0` |
| `nativeGetCandidateString` | GetCandidateString(int) | `0x200` |
| `nativeGetCandidateRange` | GetCandidateRange(int) | `0x220` |
| `nativeGetTokenCandidateString` | GetTokenCandidateString(int) | `0x1a8` |
| `nativeGetTokenCandidateRange` | GetTokenCandidateRange(int) | `0x1b0` |
| `nativeSelectTokenCandidate` | SelectTokenCandidate(int) | `0x1b8` |
| `nativeGetDecodingRange` | GetDecodingRange | `0xb8` |
| `nativeSelectRange` | SelectRange(Range*) | `0x90` |
| `nativeGetDataSourceIndex` | GetDataSourceIndex(string) | `0x268` |
| `nativeUnconvertSegments` | UnconvertSegments(Range*) | `0x2a8` |
| `nativeUnselectTokens` | UnselectTokens(Range*) | `0x2b0` |
| `nativeRefreshData` | RefreshData | `0x10` |
| factory `nativeGetDataManager` | Factory::GetDataManager | `0x28` |
| factory `nativeGetSettingManager` | Factory::GetSettingManager | `0x30` |
| factory `nativeCreateMutableDictionaryAccessor` | Factory::CreateAccessor | `0x18` |

会话类方法（`nativeBeginSession` / `nativeHandleInputContext` / `nativeFinishSession`）
的 vtable 调用前还会经过 data-manager 偏移 `0x6f0` / `0x558` / `0x6f8`，
这些是会话上下文/指标入口，不是引擎候选方法。

### 1.5 直接 ABI 实测

`tests/test_native_abi.cpp` 在真实引擎上验证：

```
wrapper_n=403 direct_n=403 range=(0,5)
raw=0ce4bda0e5a5bd0000760ca70a0000001000000000000000
```

- `GetCandidateCount`（vtable `+0x1d0`）与 JNI 路径一致（403）。
- `GetCandidateRange`（`+0x220`）返回 `(0,5)`，8 字节结构可直接读取。
- `GetCandidateString`（`+0x200`）的原始 24 字节是 `0c e4 bd a0 e5 a5 bd 00 ...`。
  `0x0c` 不是标记，而是 **短串长度字节**：`0x0c = 6 << 1`，数据从 +1 开始，
  即 “你好”（6 字节）。直接按 macOS `std::string` 解释会得到错误的 `size()`。
- 结论：**数值/布尔/Range 方法可以直接调用；字符串用
  `AndroidString` 适配器**（偶数 byte0 = 短串，长度 `byte0 >> 1`，数据 `b+1`；
  奇数 = 长串，长度在 +8，数据指针在 +16），`ScoredInput` 的字符串参数同样按此编码。
- 字符串规则来自引擎自己的 JNI 转换 helper：`FUN_011ce908` 对短串读
  `byte0 >> 1` / `b+1`，对长串读 `*(uint32_t*)(b+8)` / `*(char**)(b+16)`。

### 1.6 仓库现有 native 覆盖缺口

`pinyin_natives.txt`（37 项）中有 19 项不在 `hmm_native.c` 的解析表里：

`nativeAddInputEdge`, `nativeBulkInputWithNativePointer`, `nativeDecode`,
`nativeGetAllPendingMetrics`, `nativeGetFilteredResults`,
`nativeGetHighlightedCandidate`, `nativeGetInputUnitConfidentString`,
`nativeGetPredictionCandidateContextLength`,
`nativeGetPredictionCandidateContextWordCount`,
`nativeGetPredictionCandidateDataSourceMask`,
`nativeGetSegmentConvertedString`, `nativeGetTokenCandidateRange`,
`nativeGetTokenConfidentString`, `nativeHighlightCandidate`,
`nativeIsInputUnitConfident`, `nativeIsInputUnitEmpty`,
`nativeIsSegmentTargeted`, `nativeIsSegmentTokenFullyMatched`,
`nativeUnselectTokens`。

这也是为什么直接换加载方式不能解决问题：Java 侧 18.5.9 的状态机依赖这些入口。

---

## 2. 消除方案

目标：**不在运行时加载 ELF，不模拟 JNI**。

### Phase 0 — 版本对齐（必须先行）

1. 在 `linux_abi.c` / `android_stubs.c` 补齐：
   - `__strchr_chk`、`__open_2`、`__read_chk`、`__write_chk`、
     `__strlen_chk`、`__strncpy_chk2`、`__strrchr_chk`；
   - `pthread_cond_wait` / `pthread_mutex_*` 的静态初始化路径；
   - `__system_property_*`、`gettid`、`__stack_chk_fail` 等版本差异。
2. 用现有加载器跑通：
   - `nativeCreateEngineFactory` → `nativeGetDataManager` →
     `nativeEnrollDataScheme`（zh_cn 包）→ `nativeCreateEngine` →
     `nativeAppend` → `nativeFillCandidateList`。
3. 通过标准：`nativeAppend` 返回 >0，候选字符串与 Android 真机/旧版一致。
4. 该阶段仍使用现有加载器；目的是得到一个可用的引擎基线，供 Phase 1 对照。

### Phase 1 — 直接 C++ ABI，去掉 JNI 兼容层

用 `docs/native_abi.tsv` 生成 `gboard_native_abi.h`：

```cpp
struct GboardScoredInput { std::string input; float score; };
struct GboardRange { int32_t start, end; };
using GboardEngine = void;
using GboardFactory = void;

GboardFactory* gboard_create_factory();
GboardEngine*  gboard_create_engine(GboardFactory*, const std::string& data_id,
                                    const std::string& setting_id);
int  gboard_append(GboardEngine*, const GboardScoredInput* in, int n, int type);
bool gboard_fill_candidates(GboardEngine*, const GboardRange&);
int  gboard_candidate_count(GboardEngine*);
std::string gboard_candidate_string(GboardEngine*, int index);
GboardRange gboard_candidate_range(GboardEngine*, int index);
bool gboard_select_candidate(GboardEngine*, int index);
```

桥接实现（完整示意见 `docs/native_bridge_example.cpp`）：

```cpp
template <class Fn>
static Fn vslot(void* obj, uintptr_t off) {
    return reinterpret_cast<Fn>(*reinterpret_cast<void**>(
        reinterpret_cast<char*>(*reinterpret_cast<void**>(obj)) + off));
}

int gboard_append(GboardEngine* e, const GboardScoredInput* in, int n, int type) {
    std::vector<GboardScoredInput> v(in, in + n);
    auto fn = vslot<int(*)(void*, std::vector<GboardScoredInput>*, int)>(e, 0x38);
    return fn(e, &v, type);
}

std::string gboard_candidate_string(GboardEngine* e, int index) {
    std::string out;  // libc++ sret
    auto fn = vslot<void(*)(std::string*, void*, int)>(e, 0x200);
    fn(&out, e, index);
    return out;
}
```

替换范围：

**已实现（当前仓库，热路径）**

- `GboardIME/engine/gboard_native_abi.h`：C 内联直接 ABI，覆盖
  `append`（含 context token）、`fill`、`count`、`string`、`range`、
  `select`、`select_range`、`delete`、`unconvert`、`predictions`、`reset`、
  `segment/token` 读取、`separator`。
- `hmm_candidates.c` 已无任何 JNI 调用：append、候选、segment/token、
  context、separator、prediction、delete、select、reset 全部走 vtable；
  不再创建 `ScoredInput`/`Range`/`String` 假对象，也没有 `JNI_LOCAL_FRAME`
  的每次调用开销。
- 直接填充/读取使用 `const GboardRange*`（value 传递会 crash，已实测）。
- `./test.sh`：889 passed；`tests/test_native_abi.cpp`：直接
  reset → append → fill → count/string/range 与 JNI 基线一致。

**仍需 JNI 的部分**

- `hmm_engine.c` 的 factory/engine 初始化、`DataManager`/`SettingManager`
  与 `EnrollDataScheme`（Phase 1b，需直接 factory 构造和 protobuf 传入）；
- `hmm_enroll.c` 的词典/设置 enroll（含 FileDescriptor 路径）；
- `hmm_user_dict.c` 的 user-dict 数组/候选 token；
- `hmm_native.c` 的注册表解析与 `jni_env.c` 本身。

`hmm_candidates.c` 已与 JNI 解耦；剩余 JNI 只出现在初始化、enroll 和
user-dict 路径，不影响逐键输入、候选、分段、预测和选择。Phase 1 全部完成后
才能删除 `jni_env.c`。

风险点（需要逐项验证）：

1. **字符串 ABI 不兼容**：实测 Android 返回的 `std::string` 不是 macOS libc++
   默认布局；必须用 `AndroidString` 适配器，不能直接 `std::string` 传递。
   `std::vector` 的三指针布局可用，但元素内的字符串同样要适配。
2. 引擎是否在构造时保存 `JNIEnv*` 并回调 Java：反编译
   `nativeCreateEngine` 的构造路径（`FUN_011cdfdc` / `FUN_011ce9e0`）确认。
   若有，只保留一个极小的 native 回调或日志替换。
3. 异常/RTTI：桥接层禁止抛过边界；引擎若抛异常，需要 `noexcept` 包装。
4. `DataManager` 的 protobuf enroll：直接传 `std::vector<uint8_t>`，
   注意 `nativeEnrollDataScheme` 内部走 `0x6f0/0x558/0x18` 的 vtable 槽。
5. vtable 偏移是 **build-specific**：每个 APK 版本重新生成 `native_abi.tsv`，
   并用 build-id/SHA-256 绑定。

### Phase 2 — 去掉 ELF 加载器

已有的离线转换器（原型）可以：

- 生成 36.3MB 的 arm64 Mach-O dylib，`dyld` 直接 `dlopen`；
- 156k RELATIVE 转成 rebase，JUMP_SLOT/GLOB_DAT 转成 bind；
- 4,002 个 TPIDR 站点离线改写为 `adrp/ldr/b` 跳板（不再运行时改代码页）；
- 1,019 个安全构造函数写入 `__mod_init_func`；
- `__eh_frame`、`gcc_except_table` 保留，供 libunwind 使用。

接入后删除运行时 `elf_loader.c`，只保留构建期 `.ctorprobe` 生成器。
剩下的 `libgboard_bionic.dylib` 只提供平台符号，不再有 JNI。

### Phase 3 — 可选：纯原生引擎

如果目标是 **完全不依赖 Google 二进制**，才需要这一步：

- 用 `docs/decompiled/` + `hip` / `hki` 作为规格，移植 37 个候选/分段方法；
- 解析 `pinyin_system_dictionary`、`pinyin_bigram`、`pinyin_token_*`、
  `pinyin_lstm_tflite`（LSTM 重排）和 `pinyin_sentence_piece_model`；
- 或换成 librime / Mozc 的拼音引擎，保留 Swift 前端；
- 工作量和行为差异都远大于 Phase 0–2，不建议作为第一步。

---

## 3. 验证计划

1. **双跑对照**：同一输入序列分别走
   - 现有 JNI 路径（Phase 0 基线），
   - 直接 ABI 桥（Phase 1），
   比较 `candidate_count`、`candidate_string(i)`、`candidate_range(i)`、
   `segment_count`、`token`、`decoding_range`。
2. **内存**：
   - 去掉 JNI 假对象后，候选/字符串不再有本地引用和 `FakeObj` 分配；
   - 去掉运行时 TPIDR 改写后，约 974 个代码页不再 COW（约 15MB）；
   - 引擎本体仍是 file-backed；词典 22MB 仍按需映射。
3. **启动**：`nativeCreateEngineFactory` → `nativeGetDataManager` →
   `nativeEnrollDataScheme` → `nativeCreateEngine` 全链路无崩溃。
4. **回归**：`tests/test_native_abi.cpp` 已验证 `count/range` 与 JNI 路径一致；
   Phase 1 完成后加上字符串/append 的对照。

## 4. 产物

- `docs/native_abi.tsv` — 引擎表 131 个唯一 native 的签名、file vaddr、大小、vtable 候选偏移。
- `tools/extract_jni_table.py` — 从任意 arm64 Android ELF 重新提取 `JNINativeMethod` 表（名称/签名/地址），并输出 SHA-256；`--table-address 0x1ffcff8` 可只取引擎表。
- `tools/ghidra/` — 复现反编译的 Ghidra headless 脚本与命令。
- `docs/decompiled/jni_wrappers.c` — Ghidra 反编译的 131 个 JNI 封装
  （地址为 Ghidra image base `0x100000` 坐标，机器生成，不可直接编译）。
- `docs/decompiled/engine_internal_helpers.c` — factory/engine 构造与
  Range/String 辅助函数。
- `docs/native_bridge_example.cpp` — 直接 vtable 桥的示意实现（非构建产物）。
- `GboardIME/engine/gboard_native_abi.h` — **已接入**的直接 C ABI；
  `hmm_candidates.c` 已无 JNI 调用。
- `tests/test_native_abi.cpp` — 直接 vtable 探针：验证 append/fill/count/string/range；需要 APK 与词典包，手动运行。
- 现有 `GboardIME/engine/android_stubs.c` 的 bionic stdio 导出修复
  （`stdin/stdout/stderr` 以 bionic 名称导出，`fixup_file` 指向
  `__stdinp/__stdoutp/__stderrp`）是 Phase 1 的前置小改动，未提交。

## 5. 复现

```bash
# 1) 提取注册表（不需要 Ghidra）
python3 tools/extract_jni_table.py \
  gboard_apk_source/resources/lib/arm64-v8a/libintegrated_shared_object.so \
  -o /tmp/jni_table.tsv

# 2) Ghidra 分析（首次约 4 分钟；项目 641MB）
GHIDRA=/opt/homebrew/opt/ghidra/libexec
JAVA_HOME=/opt/homebrew/opt/openjdk@21/libexec/openjdk.jdk/Contents/Home \
  "$GHIDRA/support/analyzeHeadless" /tmp/gboard_proj gboard \
  -import gboard_apk_source/resources/lib/arm64-v8a/libintegrated_shared_object.so \
  -overwrite -analysisTimeoutPerFile 1800

# 3) 反编译引擎表（Ghidra 地址 = file vaddr + 0x100000）
JAVA_HOME=/opt/homebrew/opt/openjdk@21/libexec/openjdk.jdk/Contents/Home \
  "$GHIDRA/support/analyzeHeadless" /tmp/gboard_proj gboard \
  -process libintegrated_shared_object.so -noanalysis \
  -scriptPath tools/ghidra \
  -postScript JniDecompile.java /tmp/jni_wrappers.c all 0x20fcff8
```

## 6. 许可证与边界

反编译语料仅用于本仓库的兼容性研究与迁移设计，不随产品分发；
不要把 `docs/decompiled/` 或 Google 二进制打进发布包。