// Direct C++ vtable ABI test for the Gboard HMM engine.
//
// Phase 1 made append/fill/count/string/range/select/delete/prediction and
// segment/token direct. This test uses gboard_native_abi.h for those calls and
// checks the direct path against the C API (which is also direct now).
//
// Covers: short and long candidate strings, direct reset/append/fill, invalid
// candidate range, and the context/prediction path. The C API and the header
// are both direct in this build, so count/string equality is an internal
// consistency check, not an independent ABI oracle. Built by test.sh.

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
extern std::int32_t g_end_vertex;
}

#include "gboard_native_abi.h"

unsigned long gboard_abi_clear_count = 0;

static void fault(int sig, siginfo_t* si, void* ctx) {
    auto* uc = static_cast<ucontext_t*>(ctx);
    std::fprintf(stderr, "FAULT sig=%d addr=%p pc=%p lr=%p\n", sig, si->si_addr,
                 (void*)uc->uc_mcontext->__ss.__pc,
                 (void*)uc->uc_mcontext->__ss.__lr);
    _exit(99);
}

static bool append_chars(void* engine, const char* text, int* end_vertex) {
    int end = 0;
    for (const char* p = text; *p; p++) {
        char key[2] = { *p, '\0' };
        end = gboard_engine_append_one(engine, key, 0);
        if (end <= 0) return false;
    }
    *end_vertex = end;
    return true;
}

int main(int argc, char** argv) {
    if (argc < 3) return 64;
    struct sigaction sa = {};
    sa.sa_sigaction = fault; sa.sa_flags = SA_SIGINFO | SA_NODEFER;
    sigaction(SIGSEGV, &sa, nullptr); sigaction(SIGBUS, &sa, nullptr);

    if (!hmm_engine_init(argv[1], argv[2])) return 1;

    // C API path (direct since Phase 1).
    if (!hmm_engine_append("nihao")) return 2;
    char* baseline[1024] = {0};
    int baseline_n = hmm_engine_get_candidates(baseline, 1024);
    if (baseline_n <= 0) return 3;
    std::string baseline0 = baseline[0];
    for (int i = 0; i < baseline_n; i++) std::free(baseline[i]);

    void* engine = hmm_engine_native_handle();
    if (!engine) return 4;
    int count = gboard_engine_count(engine);
    GboardRange range0 = gboard_engine_range(engine, 0);
    char* string0 = gboard_engine_string_dup(engine, 0);
    if (count != baseline_n || !string0 || baseline0 != string0 ||
        range0.start < 0 || range0.end < range0.start) {
        std::free(string0);
        return 5;
    }
    std::free(string0);

    // Direct reset then direct append/fill/read.
    gboard_engine_reset(engine);
    g_end_vertex = 0;
    int end_vertex = 0;
    if (!append_chars(engine, "nihao", &end_vertex)) return 6;
    g_end_vertex = end_vertex;
    GboardRange fill_range = { 0, end_vertex };
    if (!gboard_engine_fill(engine, fill_range)) return 7;
    int direct_n = gboard_engine_count(engine);
    char* direct_s = gboard_engine_string_dup(engine, 0);
    GboardRange direct_r = gboard_engine_range(engine, 0);
    if (direct_n != baseline_n || !direct_s || baseline0 != direct_s ||
        direct_r.start < 0 || direct_r.end < direct_r.start) {
        std::free(direct_s);
        return 8;
    }
    std::free(direct_s);

    // A >22-byte candidate exercises the Android long-string path and clear.
    gboard_engine_reset(engine);
    g_end_vertex = 0;
    if (!hmm_engine_append("jintiantianqihenhaowomenyiqichuquwan")) return 9;
    char* long_buf[2048] = {0};
    int long_n = hmm_engine_get_candidates(long_buf, 2048);
    bool saw_long = false;
    for (int i = 0; i < long_n; i++) {
        if (std::strlen(long_buf[i]) > 22) {
            saw_long = true;
            unsigned long before = gboard_abi_clear_count;
            char *copy = gboard_engine_string_dup(engine, i);
            if (!copy) return 13;
            if (gboard_abi_clear_count != before + 1) { std::free(copy); return 15; }
            if (std::strlen(copy) != std::strlen(long_buf[i]) ||
                std::strcmp(copy, long_buf[i]) != 0) { std::free(copy); return 16; }
            std::free(copy);
        }
        std::free(long_buf[i]);
    }
    if (!saw_long) return 10;
    if (gboard_abi_clear_count == 0) return 17;

    // Invalid candidate index must not produce a range.
    GboardRange bad = gboard_engine_range(engine, -1);
    if (bad.start >= 0 || hmm_engine_get_candidate_consumed(-1) != -1) return 11;
    // Invalid fill range must return false (the !ok guard itself is not
    // reachable through the public API in this build).
    GboardRange invalid_fill = { -1, -1 };
    if (gboard_engine_fill(engine, invalid_fill)) return 12;

    // Exercise the context/prediction direct path (score 0.0f append).
    hmm_engine_set_context("你好");
    char* predictions[16] = {0};
    int prediction_n = hmm_engine_get_predictions(predictions, 16);
    for (int i = 0; i < prediction_n; i++) std::free(predictions[i]);
    if (prediction_n <= 0) return 14;

    std::fprintf(stderr,
                 "PASS baseline_n=%d direct_n=%d range=(%d,%d) long_n=%d pred=%d\n",
                 baseline_n, direct_n, direct_r.start, direct_r.end, long_n,
                 prediction_n);
    return 0;
}