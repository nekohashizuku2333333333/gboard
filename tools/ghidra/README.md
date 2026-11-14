# Ghidra helpers for the native ABI migration

These scripts run under Ghidra headless. They only read the imported program;
names/comments and decompilation output stay in the analysis project.

The Java scripts use **Ghidra default-space addresses** (import image base is
`0x100000` for this ELF). File virtual addresses from
`tools/extract_jni_table.py` therefore become `file_vaddr + 0x100000`.

## Import

```bash
GHIDRA=/opt/homebrew/opt/ghidra/libexec
JAVA_HOME=/opt/homebrew/opt/openjdk@21/libexec/openjdk.jdk/Contents/Home \
  "$GHIDRA/support/analyzeHeadless" /tmp/gboard_proj gboard \
  -import gboard_apk_source/resources/lib/arm64-v8a/libintegrated_shared_object.so \
  -overwrite -analysisTimeoutPerFile 1800
```

## Dump the engine JNINativeMethod table

`0x1ffcff8` is the engine table (136 entries). In the Ghidra project it is
`0x20fcff8`.

```bash
JAVA_HOME=/opt/homebrew/opt/openjdk@21/libexec/openjdk.jdk/Contents/Home \
  "$GHIDRA/support/analyzeHeadless" /tmp/gboard_proj gboard \
  -process libintegrated_shared_object.so -noanalysis \
  -scriptPath tools/ghidra \
  -postScript JniDecompile.java /tmp/jni_wrappers.c all 0x20fcff8
```

`JniDecompile.java` arguments: `output filter table_ghidra_addr`.
`filter` is a comma-separated list of exact native names, or `all`.
`DumpAddr.java` takes `output addr1,addr2,...` for internal helpers.

The generated C is machine output, not compilable source. Addresses are
Ghidra coordinates; subtract `0x100000` for file virtual addresses.
