// Direct C++ vtable ABI probe for the Gboard HMM engine.
//
// It uses the existing loader/JNI only to initialize the engine and append
// input, then reads the candidate count, range, and raw candidate string
// through the engine's vtable. `GetCandidateCount` and `GetCandidateRange`
// are ABI-safe; the raw string demonstrates that the engine returns an
// Android-layout std::string (not the macOS libc++ layout), so a direct bridge
// needs an explicit AndroidString adapter.
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
#include <ucontext.h>
#include <unistd.h>

extern "C" {
#include "hmm_engine.h"
}

template <class Fn>
static Fn slot(void* object, std::uintptr_t offset) {
    auto** vptr = *reinterpret_cast<void***>(object);
    return *reinterpret_cast<Fn*>(reinterpret_cast<char*>(vptr) + offset);
}

// The engine returns std::string in the Android libc++ layout. This buffer is
// initialized as an empty Android short string; the engine overwrites it.
struct AndroidString {
    unsigned char b[24];
    AndroidString() { std::memset(b, 0, sizeof(b)); b[0] = 1; }
    ~AndroidString() {}
};

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
    if (!hmm_engine_append("nihao")) return 2;

    char* wrapper[1024] = {0};
    int wrapper_n = hmm_engine_get_candidates(wrapper, 1024);
    for (int i = 0; i < wrapper_n; i++) std::free(wrapper[i]);

    void* engine = hmm_engine_native_handle();
    if (!engine) return 3;

    int direct_n = slot<int (*)(void*)>(engine, 0x1d0)(engine);
    Range range = slot<Range (*)(void*, int)>(engine, 0x220)(engine, 0);
    AndroidString raw = slot<AndroidString (*)(void*, int)>(engine, 0x200)(engine, 0);

    std::fprintf(stderr, "wrapper_n=%d direct_n=%d range=(%d,%d) raw=",
                 wrapper_n, direct_n, range.start, range.end);
    for (int i = 0; i < 24; i++) std::fprintf(stderr, "%02x", raw.b[i]);
    std::fprintf(stderr, "\n");

    bool ok = wrapper_n == direct_n && direct_n > 0 &&
              range.start <= range.end;
    return ok ? 0 : 4;
}