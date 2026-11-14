// Direct C++ vtable ABI probe for the Gboard HMM engine.
//
// Baseline: initialize through the existing loader/JNI and append "nihao".
// Then reset, append the same keys through the engine's C++ vtable only, and
// compare counts and candidate strings. This proves the pinyin hot path can
// run without the JNI compat layer.
//
// String rule (from the engine's own JNI conversion helper):
//   even byte0: short, len = byte0 >> 1, data = buf + 1
//   odd  byte0: long,  len = *(uint32_t*)(buf + 8), data = *(char**)(buf + 16)
//
// Usage: test_native_abi <libintegrated_shared_object.so> <hmmoemdata/current>
// Manual test: it needs the extracted APK and dictionary pack.

#define _XOPEN_SOURCE 700
#include <csignal>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <ucontext.h>
#include <unistd.h>

extern "C" {
#include "hmm_engine.h"
// The JNI-era candidate page uses this global for the fill range; a direct
// bridge keeps the same state after Append returns the new end vertex.
extern std::int32_t g_end_vertex;
}

template <class Fn>
static Fn slot(void* object, std::uintptr_t offset) {
    auto** vptr = *reinterpret_cast<void***>(object);
    return *reinterpret_cast<Fn*>(reinterpret_cast<char*>(vptr) + offset);
}

struct AndroidString {
    alignas(8) unsigned char b[24];
    AndroidString() { std::memset(b, 0, sizeof(b)); }
    ~AndroidString() {}
};

static AndroidString from_utf8(const std::string& s) {
    AndroidString out;
    if (s.size() <= 22) {
        out.b[0] = static_cast<unsigned char>(s.size() << 1);  // short
        std::memcpy(out.b + 1, s.data(), s.size());
    } else {
        // Long form is not needed for pinyin keys; leave it unsupported.
        out.b[0] = 1;  // odd => long
        *reinterpret_cast<std::uint32_t*>(out.b + 8) =
            static_cast<std::uint32_t>(s.size());
        char* data = static_cast<char*>(std::malloc(s.size() + 1));
        std::memcpy(data, s.data(), s.size());
        data[s.size()] = 0;
        *reinterpret_cast<char**>(out.b + 16) = data;
    }
    return out;
}

static std::string to_utf8(const AndroidString& s) {
    if (s.b[0] & 1) {
        std::uint32_t len = *reinterpret_cast<const std::uint32_t*>(s.b + 8);
        const char* data = *reinterpret_cast<char* const*>(s.b + 16);
        return std::string(data ? data : "", len);
    }
    return std::string(reinterpret_cast<const char*>(s.b + 1), s.b[0] >> 1);
}

struct ScoredInput {
    AndroidString input;  // 24 bytes
    float score;          // + 0x18, 0x20 per element
};

static_assert(sizeof(ScoredInput) == 0x20, "ScoredInput must be 0x20 bytes");

struct Range {
    std::int32_t start;
    std::int32_t end;
};

static void fault(int sig, siginfo_t* si, void* ctx) {
    auto* uc = static_cast<ucontext_t*>(ctx);
    std::fprintf(stderr, "FAULT sig=%d addr=%p pc=%p lr=%p\n", sig, si->si_addr,
                 (void*)uc->uc_mcontext->__ss.__pc, (void*)uc->uc_mcontext->__ss.__lr);
    _exit(99);
}

int main(int argc, char** argv) {
    if (argc < 3) return 64;
    struct sigaction sa = {};
    sa.sa_sigaction = fault; sa.sa_flags = SA_SIGINFO | SA_NODEFER;
    sigaction(SIGSEGV, &sa, nullptr); sigaction(SIGBUS, &sa, nullptr);

    if (!hmm_engine_init(argv[1], argv[2])) return 1;

    // Baseline through JNI.
    if (!hmm_engine_append("nihao")) return 2;
    char* base[1024] = {0};
    int base_n = hmm_engine_get_candidates(base, 1024);
    const std::string base0 = base_n > 0 ? base[0] : "";
    std::fprintf(stderr, "baseline n=%d s0=%s\n", base_n, base0.c_str());

    // Reset, then append the same keys through the vtable only.
    void* engine = hmm_engine_native_handle();
    if (!engine) return 3;
    slot<void (*)(void*)>(engine, 0xa0)(engine);  // Reset
    g_end_vertex = 0;
    auto append = slot<int (*)(void*, std::vector<ScoredInput>*, int)>(engine, 0x38);
    int end_vertex = 0;
    for (const char* p = "nihao"; *p; p++) {
        std::vector<ScoredInput> v;
        ScoredInput in;
        in.input = from_utf8(std::string(1, *p));
        in.score = 1.0f;
        v.push_back(in);
        int r = append(engine, &v, 0);  // INPUT_TYPE_SOURCE_INPUT_UNIT
        std::fprintf(stderr, "direct append '%c' -> %d\n", *p, r);
        if (r <= 0) return 5;
        end_vertex = r;
    }

    g_end_vertex = end_vertex;
    Range fill_range{0, end_vertex};
    bool filled = slot<bool (*)(void*, const Range*)>(engine, 0x1c8)(engine, &fill_range);
    std::fprintf(stderr, "direct fill -> %d\n", filled);

    int direct_n = slot<int (*)(void*)>(engine, 0x1d0)(engine);
    Range range = slot<Range (*)(void*, int)>(engine, 0x220)(engine, 0);
    AndroidString raw = slot<AndroidString (*)(void*, int)>(engine, 0x200)(engine, 0);
    const std::string direct_s = to_utf8(raw);

    std::fprintf(stderr, "direct n=%d s0=%s range=(%d,%d) end=%d\n",
                 direct_n, direct_s.c_str(), range.start, range.end, end_vertex);
    bool ok = filled && base_n == direct_n && base0 == direct_s &&
              range.start <= range.end;
    for (int i = 0; i < base_n; i++) std::free(base[i]);
    return ok ? 0 : 4;
}