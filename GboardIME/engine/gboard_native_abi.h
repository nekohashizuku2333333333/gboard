#pragma once
// Direct C++ vtable ABI for the Gboard HMM engine.
//
// The engine is still loaded by elf_loader.c and initialized through the JNI
// shim, but the pinyin hot path (append, fill, candidate reads, reset, select)
// no longer creates fake Java objects. The vtable offsets below are specific
// to the researched Gboard 18.5.9 build (see docs/native_abi.tsv); regenerate
// them for a different APK.
//
// String objects use the engine's Android libc++ layout, not the macOS
// libc++ layout:
//   even byte0: short, len = byte0 >> 1, data = buf + 1
//   odd  byte0: long,  len = *(uint32_t*)(buf + 8), data = *(char**)(buf + 16)

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#if defined(__cplusplus)
#define GBOARD_ALIGNAS(n) alignas(n)
#define GBOARD_STATIC_ASSERT static_assert
#else
#define GBOARD_ALIGNAS(n) _Alignas(n)
#define GBOARD_STATIC_ASSERT _Static_assert
#endif

typedef struct {
    GBOARD_ALIGNAS(8) unsigned char b[24];
} GboardString;

typedef struct {
    GboardString input;
    float score;
} GboardScoredInput;

typedef struct {
    GboardScoredInput *begin;
    GboardScoredInput *end;
    GboardScoredInput *cap;
} GboardVector;

typedef struct {
    int32_t start;
    int32_t end;
} GboardRange;

GBOARD_STATIC_ASSERT(sizeof(GboardString) == 24, "Android string is 24 bytes");
GBOARD_STATIC_ASSERT(sizeof(GboardScoredInput) == 32, "ScoredInput is 0x20 bytes");
GBOARD_STATIC_ASSERT(sizeof(GboardVector) == 24, "libc++ vector is 24 bytes");

static inline void *gboard_slot(void *object, size_t offset) {
    void **vptr = *(void ***)object;
    return *(void **)((char *)vptr + offset);
}

#define GBOARD_LOAD_FN(object, offset, fn)                    \
    do {                                                      \
        void *gb_p = gboard_slot((object), (offset));          \
        memcpy(&(fn), &gb_p, sizeof(fn));                      \
    } while (0)

static inline int gboard_string_set(GboardString *s, const char *utf8) {
    size_t len = strlen(utf8);
    if (len > 22) return 0;  /* pinyin keys and context tokens are short */
    memset(s, 0, sizeof(*s));
    s->b[0] = (unsigned char)(len << 1);
    memcpy(s->b + 1, utf8, len);
    return 1;
}

#ifdef GBOARD_ABI_TEST
extern unsigned long gboard_abi_clear_count;
#endif

// The engine's long strings are malloc-backed in this loader; free() matches
// the engine's sized operator delete on this platform.
static inline void gboard_string_clear(GboardString *s) {
#ifdef GBOARD_ABI_TEST
    gboard_abi_clear_count++;
#endif
    if (s->b[0] & 1) {
        char *data = NULL;
        memcpy(&data, s->b + 16, sizeof(data));
        free(data);
        memset(s, 0, sizeof(*s));
    }
}

static inline char *gboard_string_dup(const GboardString *s) {
    size_t len;
    const char *data;
    if (s->b[0] & 1) {
        uint32_t long_len = 0;
        char *long_data = NULL;
        memcpy(&long_len, s->b + 8, sizeof(long_len));
        memcpy(&long_data, s->b + 16, sizeof(long_data));
        len = long_len;
        data = long_data;
    } else {
        len = s->b[0] >> 1;
        if (len > 22) len = 22;  /* corrupt/short-flag mismatch */
        data = (const char *)s->b + 1;
    }
    if (!data && len) return NULL;
    char *out = (char *)malloc(len + 1);
    if (!out) return NULL;
    if (len) memcpy(out, data, len);
    out[len] = '\0';
    return out;
}

static inline int gboard_engine_append_scored(void *engine,
                                              const char *const *keys,
                                              int count, int type, float score) {
    if (!engine || !keys || count <= 0) return 0;
    GboardScoredInput *elems = (GboardScoredInput *)calloc((size_t)count, sizeof(*elems));
    if (!elems) return 0;
    int ok = 1;
    for (int i = 0; i < count; i++) {
        if (!keys[i] || !gboard_string_set(&elems[i].input, keys[i])) {
            ok = 0;
            break;
        }
        elems[i].score = score;
    }
    if (count == 1) {
        GboardScoredInput one;
        if (!ok) {
            for (int i = 0; i < count; i++) gboard_string_clear(&elems[i].input);
            free(elems);
            return 0;
        }
        one = elems[0];
        free(elems);
        GboardVector v = { &one, &one + 1, &one + 1 };
        int (*fn)(void *, GboardVector *, int);
        GBOARD_LOAD_FN(engine, 0x38, fn);
        int result = fn(engine, &v, type);
        gboard_string_clear(&one.input);
        return result;
    }
    int result = -1;
    if (ok) {
        GboardVector v = { elems, elems + count, elems + count };
        int (*fn)(void *, GboardVector *, int);
        GBOARD_LOAD_FN(engine, 0x38, fn);
        result = fn(engine, &v, type);
        for (GboardScoredInput *p = v.begin; p < v.end; p++)
            gboard_string_clear(&p->input);
        free(v.begin);
        return result;
    }
    for (int i = 0; i < count; i++) gboard_string_clear(&elems[i].input);
    free(elems);
    return result;
}

static inline int gboard_engine_append(void *engine, const char *const *keys,
                                       int count, int type) {
    return gboard_engine_append_scored(engine, keys, count, type, 1.0f);
}

static inline int gboard_engine_append_one(void *engine, const char *key,
                                           int type) {
    return gboard_engine_append_scored(engine, &key, 1, type, 1.0f);
}

static inline bool gboard_engine_fill(void *engine, GboardRange range) {
    if (!engine) return false;
    bool (*fn)(void *, const GboardRange *);
    GBOARD_LOAD_FN(engine, 0x1c8, fn);
    return fn(engine, &range);
}

static inline int gboard_engine_count(void *engine) {
    if (!engine) return 0;
    int (*fn)(void *);
    GBOARD_LOAD_FN(engine, 0x1d0, fn);
    return fn(engine);
}

static inline GboardRange gboard_engine_range(void *engine, int index) {
    GboardRange out = { -1, -1 };
    if (!engine) return out;
    GboardRange (*fn)(void *, int);
    GBOARD_LOAD_FN(engine, 0x220, fn);
    return fn(engine, index);
}

static inline char *gboard_engine_string_dup(void *engine, int index) {
    if (!engine) return NULL;
    GboardString raw;
    memset(&raw, 0, sizeof(raw));
    GboardString (*fn)(void *, int);
    GBOARD_LOAD_FN(engine, 0x200, fn);
    raw = fn(engine, index);
    char *out = gboard_string_dup(&raw);
    gboard_string_clear(&raw);
    return out;
}

static inline void gboard_engine_reset(void *engine) {
    if (!engine) return;
    void (*fn)(void *);
    GBOARD_LOAD_FN(engine, 0xa0, fn);
    fn(engine);
}

static inline bool gboard_engine_select(void *engine, int index) {
    if (!engine) return false;
    bool (*fn)(void *, int);
    GBOARD_LOAD_FN(engine, 0x1d8, fn);
    return fn(engine, index);
}

static inline GboardRange gboard_engine_decoding_range(void *engine) {
    GboardRange out = { -1, -1 };
    if (!engine) return out;
    GboardRange (*fn)(void *);
    GBOARD_LOAD_FN(engine, 0xb8, fn);
    return fn(engine);
}

static inline bool gboard_engine_select_range(void *engine, GboardRange range) {
    if (!engine) return false;
    bool (*fn)(void *, const GboardRange *);
    GBOARD_LOAD_FN(engine, 0x90, fn);
    return fn(engine, &range);
}

static inline bool gboard_engine_delete(void *engine, GboardRange range) {
    if (!engine) return false;
    bool (*fn)(void *, const GboardRange *);
    GBOARD_LOAD_FN(engine, 0x88, fn);
    return fn(engine, &range);
}

static inline bool gboard_engine_unconvert(void *engine, GboardRange range) {
    if (!engine) return false;
    bool (*fn)(void *, const GboardRange *);
    GBOARD_LOAD_FN(engine, 0x2a8, fn);
    return fn(engine, &range);
}

static inline bool gboard_engine_fill_predictions(void *engine) {
    if (!engine) return false;
    bool (*fn)(void *);
    GBOARD_LOAD_FN(engine, 0x278, fn);
    return fn(engine);
}

static inline int gboard_engine_prediction_count(void *engine) {
    if (!engine) return 0;
    int (*fn)(void *);
    GBOARD_LOAD_FN(engine, 0x280, fn);
    return fn(engine);
}

static inline char *gboard_engine_prediction_string_dup(void *engine, int index) {
    if (!engine) return NULL;
    GboardString raw;
    memset(&raw, 0, sizeof(raw));
    GboardString (*fn)(void *, int);
    GBOARD_LOAD_FN(engine, 0x288, fn);
    raw = fn(engine, index);
    char *out = gboard_string_dup(&raw);
    gboard_string_clear(&raw);
    return out;
}
static inline int gboard_engine_segment_count(void *engine) {
    if (!engine) return 0;
    int (*fn)(void *);
    GBOARD_LOAD_FN(engine, 0xc8, fn);
    return fn(engine);
}

static inline void *gboard_engine_segment(void *engine, int index) {
    if (!engine) return NULL;
    void *(*fn)(void *, int);
    GBOARD_LOAD_FN(engine, 0xd0, fn);
    return fn(engine, index);
}

static inline bool gboard_engine_segment_converted(void *engine, void *segment) {
    if (!engine || !segment) return false;
    bool (*fn)(void *, void *);
    GBOARD_LOAD_FN(engine, 0xd8, fn);
    return fn(engine, segment);
}

static inline GboardRange gboard_engine_segment_range(void *engine, void *segment) {
    GboardRange out = { -1, -1 };
    if (!engine || !segment) return out;
    GboardRange (*fn)(void *, void *);
    GBOARD_LOAD_FN(engine, 0xf8, fn);
    return fn(engine, segment);
}

static inline char *gboard_engine_segment_string_dup(void *engine, void *segment) {
    if (!engine || !segment) return NULL;
    GboardString raw;
    memset(&raw, 0, sizeof(raw));
    GboardString (*fn)(void *, void *);
    GBOARD_LOAD_FN(engine, 0x100, fn);
    raw = fn(engine, segment);
    char *out = gboard_string_dup(&raw);
    gboard_string_clear(&raw);
    return out;
}

static inline int gboard_engine_segment_token_count(void *engine, void *segment) {
    if (!engine || !segment) return 0;
    int (*fn)(void *, void *);
    GBOARD_LOAD_FN(engine, 0x108, fn);
    return fn(engine, segment);
}

static inline void *gboard_engine_segment_token(void *engine, void *segment,
                                                int index) {
    if (!engine || !segment) return NULL;
    void *(*fn)(void *, void *, int);
    GBOARD_LOAD_FN(engine, 0x110, fn);
    return fn(engine, segment, index);
}

static inline GboardRange gboard_engine_token_range(void *engine, void *token) {
    GboardRange out = { -1, -1 };
    if (!engine || !token) return out;
    GboardRange (*fn)(void *, void *);
    GBOARD_LOAD_FN(engine, 0x120, fn);
    return fn(engine, token);
}

static inline char *gboard_engine_token_string_dup(void *engine, void *token) {
    if (!engine || !token) return NULL;
    GboardString raw;
    memset(&raw, 0, sizeof(raw));
    GboardString (*fn)(void *, void *);
    GBOARD_LOAD_FN(engine, 0x128, fn);
    raw = fn(engine, token);
    char *out = gboard_string_dup(&raw);
    gboard_string_clear(&raw);
    return out;
}

static inline char *gboard_engine_token_normalized_string_dup(void *engine,
                                                               void *token) {
    if (!engine || !token) return NULL;
    GboardString raw;
    memset(&raw, 0, sizeof(raw));
    GboardString (*fn)(void *, void *);
    GBOARD_LOAD_FN(engine, 0x148, fn);
    raw = fn(engine, token);
    char *out = gboard_string_dup(&raw);
    gboard_string_clear(&raw);
    return out;
}

static inline int gboard_engine_token_language(void *engine, void *token) {
    if (!engine || !token) return -1;
    int (*fn)(void *, void *);
    GBOARD_LOAD_FN(engine, 0x158, fn);
    return fn(engine, token);
}

static inline bool gboard_engine_is_candidate_corrected(void *engine, int index) {
    if (!engine) return false;
    bool (*fn)(void *, int);
    GBOARD_LOAD_FN(engine, 0x1e8, fn);
    return fn(engine, index);
}

static inline int gboard_engine_candidate_token_count(void *engine, int index) {
    if (!engine) return 0;
    int (*fn)(void *, int);
    GBOARD_LOAD_FN(engine, 0x238, fn);
    return fn(engine, index);
}

static inline void *gboard_engine_candidate_token(void *engine, int index,
                                                  int token_index) {
    if (!engine) return NULL;
    void *(*fn)(void *, int, int);
    GBOARD_LOAD_FN(engine, 0x248, fn);
    return fn(engine, index, token_index);
}
static inline bool gboard_engine_set_separator(void *engine, int vertex,
                                               int type) {
    if (!engine) return false;
    bool (*fn)(void *, int, int);
    GBOARD_LOAD_FN(engine, 0x78, fn);
    return fn(engine, vertex, type);
}

static inline int gboard_engine_get_separator(void *engine, int vertex) {
    if (!engine) return -1;
    int (*fn)(void *, int);
    GBOARD_LOAD_FN(engine, 0x80, fn);
    return fn(engine, vertex);
}
