// Input append, candidate retrieval, selection, and reset.
#include "hmm_internal.h"
#include "hmm_user_dict.h"
#include "gboard_native_abi.h"

enum {
    INPUT_TYPE_SOURCE_INPUT_UNIT = 0,
    INPUT_TYPE_TARGET_TOKEN = 2,
    SEPARATOR_TOKEN = 1,
    SEPARATOR_SEGMENT = 2,
    END_VERTEX_SENTINEL = 32767,
    CONTEXT_MAX_UTF8_BYTES = 256,
    PREDICTION_MAX_CANDIDATES = 50,
    MAX_CONVERTED_RANGES = 64
};

typedef struct {
    size_t start;
    int utf16_units;
    int language;
} ContextCodepoint;

static char s_context[CONTEXT_MAX_UTF8_BYTES];
static bool s_context_ends_latin;
static bool s_context_injected;
static int s_context_end_vertex;
static bool s_settings_ready = true;

// Ranges of candidates selected in the active composition, like the
// selected-range stack of Gboard's AbstractHmmEngineWrapper.
typedef struct {
    int start;
    int end;
} VertexRange;
static VertexRange s_converted[MAX_CONVERTED_RANGES];
static int s_converted_count;
static uint64_t s_input_generation;

// Candidates cover the input after the last selection, or after the
// injected context when nothing is selected yet.
static int candidate_start_vertex(void) {
    return s_converted_count > 0
        ? s_converted[s_converted_count - 1].end
        : s_context_end_vertex;
}

static size_t utf8_codepoint_length(const unsigned char *s,
                                    size_t remaining) {
    if (remaining == 0) return 0;
    if (s[0] < 0x80) return 1;
    if (remaining >= 2 && (s[0] & 0xe0) == 0xc0 &&
        (s[1] & 0xc0) == 0x80) return 2;
    if (remaining >= 3 && (s[0] & 0xf0) == 0xe0 &&
        (s[1] & 0xc0) == 0x80 && (s[2] & 0xc0) == 0x80) return 3;
    if (remaining >= 4 && (s[0] & 0xf8) == 0xf0 &&
        (s[1] & 0xc0) == 0x80 && (s[2] & 0xc0) == 0x80 &&
        (s[3] & 0xc0) == 0x80) return 4;
    return 1;
}

static uint32_t utf8_decode(const unsigned char *s, size_t len) {
    if (len == 1) return s[0];
    if (len == 2) return ((uint32_t)(s[0] & 0x1f) << 6) |
                         (uint32_t)(s[1] & 0x3f);
    if (len == 3) return ((uint32_t)(s[0] & 0x0f) << 12) |
                         ((uint32_t)(s[1] & 0x3f) << 6) |
                         (uint32_t)(s[2] & 0x3f);
    return ((uint32_t)(s[0] & 0x07) << 18) |
           ((uint32_t)(s[1] & 0x3f) << 12) |
           ((uint32_t)(s[2] & 0x3f) << 6) |
           (uint32_t)(s[3] & 0x3f);
}

static int context_language(uint32_t cp) {
    if ((cp >= 0x3400 && cp <= 0x4dbf) ||
        (cp >= 0x4e00 && cp <= 0x9fff) ||
        (cp >= 0x20000 && cp <= 0x2a6df)) {
        return 2;
    }
    if ((cp >= 'A' && cp <= 'Z') || (cp >= 'a' && cp <= 'z')) {
        return 3;
    }
    return 1;
}

bool hmm_engine_set_context(const char *text_before_cursor) {
    const unsigned char *text =
        (const unsigned char *)(text_before_cursor ? text_before_cursor : "");
    size_t byte_length = strlen((const char *)text);
    ContextCodepoint *points = byte_length > 0
        ? calloc(byte_length, sizeof(*points))
        : NULL;
    if (byte_length > 0 && !points) return false;
    size_t pos = 0;
    size_t count = 0;

    while (pos < byte_length) {
        size_t length =
            utf8_codepoint_length(text + pos, byte_length - pos);
        uint32_t cp = utf8_decode(text + pos, length);
        points[count++] = (ContextCodepoint){
            .start = pos,
            .utf16_units = cp > 0xffff ? 2 : 1,
            .language = context_language(cp)
        };
        pos += length;
    }

    size_t start = byte_length;
    s_context_ends_latin = false;
    if (count > 0) {
        int language = points[count - 1].language;
        if (language != 1) {
            int limit = language == 2 ? 5 : 20;
            int retained_units = 0;
            s_context_ends_latin = language == 3;
            for (size_t i = count; i > 0; i--) {
                ContextCodepoint *point = &points[i - 1];
                if (point->language != language || retained_units >= limit) {
                    break;
                }
                start = point->start;
                retained_units += point->utf16_units;
            }
        }
    }

    size_t kept = byte_length - start;
    if (kept >= sizeof(s_context)) kept = sizeof(s_context) - 1;
    if (kept > 0) memcpy(s_context, text + start, kept);
    s_context[kept] = '\0';
    hmm_engine_set_external_context(s_context[0] != '\0');
    free(points);
    s_context_injected = false;
    s_context_end_vertex = 0;
    LOG("set context: raw='%s' normalized='%s' latin=%d",
        text_before_cursor ? text_before_cursor : "", s_context,
        s_context_ends_latin);
    return true;
}

static bool append_context(void) {
    if (s_context_injected) return true;
    s_context_injected = true;
    s_context_end_vertex = 0;
    if (!s_context[0]) return true;

    const unsigned char *text = (const unsigned char *)s_context;
    size_t length = strlen(s_context);
    size_t pos = 0;
    while (pos < length) {
        size_t char_length =
            utf8_codepoint_length(text + pos, length - pos);
        char token[5] = {0};
        memcpy(token, text + pos, char_length);

        const char *key = token;
        int result = 0;
        CRASH_PROTECT_BEGIN()
        /* Java hip: new ScoredInput(token, 0.0f) for TARGET_TOKEN. */
        result = gboard_engine_append_scored((void *)(uintptr_t)g_engine, &key, 1,
                                             INPUT_TYPE_TARGET_TOKEN, 0.0f);
        CRASH_PROTECT_END("nativeAppend(context)")
        if (result <= 0) {
            LOGERR("context append failed for '%s'; continuing without context",
                   token);
            if (g_engine) {
                CRASH_PROTECT_BEGIN()
                gboard_engine_reset((void *)(uintptr_t)g_engine);
                CRASH_PROTECT_END("nativeReset(context append failure)")
            }
            g_end_vertex = 0;
            return true;
        }
        g_end_vertex = result;
        pos += char_length;
    }

    if (g_engine) {
        CRASH_PROTECT_BEGIN()
        gboard_engine_set_separator((void *)(uintptr_t)g_engine,
                                    END_VERTEX_SENTINEL, SEPARATOR_TOKEN);
        CRASH_PROTECT_END("nativeSetSeparator(context token)")
        if (s_context_ends_latin) {
            CRASH_PROTECT_BEGIN()
            gboard_engine_set_separator((void *)(uintptr_t)g_engine,
                                        END_VERTEX_SENTINEL, SEPARATOR_SEGMENT);
            CRASH_PROTECT_END("nativeSetSeparator(context segment)")
        }
    }

    if (!g_engine) return true;
    GboardRange range = { -1, -1 };
    CRASH_PROTECT_BEGIN()
    range = gboard_engine_decoding_range((void *)(uintptr_t)g_engine);
    CRASH_PROTECT_END("nativeGetDecodingRange(context)")
    if (range.start < 0 || range.end <= range.start) {
        LOGERR("context decoding range unavailable; continuing without context");
        if (g_engine) {
            CRASH_PROTECT_BEGIN()
            gboard_engine_reset((void *)(uintptr_t)g_engine);
            CRASH_PROTECT_END("nativeReset(context range unavailable)")
        }
        g_end_vertex = 0;
        s_context_end_vertex = 0;
        return true;
    }
    int start = range.start, end = range.end;
    bool selected = false;
    CRASH_PROTECT_BEGIN()
    selected = gboard_engine_select_range((void *)(uintptr_t)g_engine, range);
    CRASH_PROTECT_END("nativeSelectRange(context)")
    if (!selected) {
        LOGERR("context range selection failed; continuing without context");
        if (g_engine) {
            CRASH_PROTECT_BEGIN()
            gboard_engine_reset((void *)(uintptr_t)g_engine);
            CRASH_PROTECT_END("nativeReset(context selection failure)")
        }
        g_end_vertex = 0;
        s_context_end_vertex = 0;
        return true;
    }
    s_context_end_vertex = end;
    g_end_vertex = s_context_end_vertex;
    LOG("context selected: range=(%d,%d)", start, end);
    return true;
}

bool hmm_engine_append(const char *pinyin_input) {
    LOG("append: input='%s' g_engine=%lld", pinyin_input, (long long)g_engine);
    if (!g_engine) { LOG("append: SKIP (null)"); return false; }
    if (!s_settings_ready) {
        LOGERR("Cannot append: decoder settings failed to refresh");
        return false;
    }
    if (!append_context()) return false;

    size_t len = strlen(pinyin_input);
    for (size_t i = 0; i < len; i++) {
        char ch[2] = { pinyin_input[i], '\0' };

        int result = 0;
        CRASH_PROTECT_BEGIN()
        result = gboard_engine_append_one((void *)(uintptr_t)g_engine, ch,
                                          INPUT_TYPE_SOURCE_INPUT_UNIT);
        LOGERR("nativeAppend('%c') → %d", pinyin_input[i], result);
        CRASH_PROTECT_END("nativeAppend")
        if (result > 0) {
            g_end_vertex = result;
        } else {
            return i > 0;
        }
    }
    return true;
}

int hmm_engine_get_candidates_page(char **candidates, int offset, int max_count) {
    if (!g_engine || !candidates || offset < 0 || max_count < 1) return 0;

    int count = 0;
    bool ok = false;
    GboardRange range = { candidate_start_vertex(), g_end_vertex };
    CRASH_PROTECT_BEGIN()
    ok = gboard_engine_fill((void *)(uintptr_t)g_engine, range);
    LOGERR("fillCandidateList → %d", ok);
    CRASH_PROTECT_END("nativeFillCandidateList")
    if (!ok) return 0;
    CRASH_PROTECT_BEGIN()
    count = gboard_engine_count((void *)(uintptr_t)g_engine);
    LOGERR("getCandidateCount → %d", count);
    CRASH_PROTECT_END("nativeGetCandidateCount")

    if (offset >= count) return 0;
    int end = count;
    if (max_count < count - offset) end = offset + max_count;

    int filled = 0;
    for (int i = offset; i < end; i++) {
        char *s = NULL;
        CRASH_PROTECT_BEGIN()
        s = gboard_engine_string_dup((void *)(uintptr_t)g_engine, i);
        CRASH_PROTECT_END("nativeGetCandidateString")
        if (s && *s) {
            candidates[filled++] = s;
        } else {
            free(s);
        }
    }
    return filled;
}

int hmm_engine_get_candidates(char **candidates, int max_count) {
    return hmm_engine_get_candidates_page(candidates, 0, max_count);
}

int hmm_engine_get_predictions(char **candidates, int max_count) {
    if (!candidates || max_count < 1 || !g_engine) {
        hmm_engine_reset();
        return 0;
    }
    // Mirrors Gboard hbe.g(): inject context as TARGET_TOKEN input, fill
    // predictions, then reset so the next composition starts clean.
    hmm_engine_prepare_input("");
    hmm_engine_reset();
    if (!s_context[0] || !g_engine || !s_settings_ready) return 0;
    append_context();

    int filled = 0;
    if (s_context_end_vertex > 0) {
        bool ok = false;
        CRASH_PROTECT_BEGIN()
        ok = gboard_engine_fill_predictions((void *)(uintptr_t)g_engine);
        CRASH_PROTECT_END("nativeFillPredictionCandidateList")

        int count = 0;
        if (ok) {
            CRASH_PROTECT_BEGIN()
            count = gboard_engine_prediction_count((void *)(uintptr_t)g_engine);
            CRASH_PROTECT_END("nativeGetPredictionCandidateCount")
        }
        if (count > PREDICTION_MAX_CANDIDATES) {
            count = PREDICTION_MAX_CANDIDATES;
        }
        for (int i = 0; i < count && filled < max_count; i++) {
            char *s = NULL;
            CRASH_PROTECT_BEGIN()
            s = gboard_engine_prediction_string_dup((void *)(uintptr_t)g_engine, i);
            CRASH_PROTECT_END("nativeGetPredictionCandidateString")
            if (!s || !*s) { free(s); continue; }
            bool duplicate = false;
            for (int j = 0; j < filled && !duplicate; j++) {
                duplicate = strcmp(candidates[j], s) == 0;
            }
            if (!duplicate) candidates[filled++] = s;
            else free(s);
        }
        LOG("predictions for '%s' → %d", s_context, filled);
    }

    hmm_engine_reset();
    return filled;
}

int hmm_engine_get_candidate_consumed(int index) {
    if (!g_engine) return -1;
    GboardRange range = { -1, -1 };
    CRASH_PROTECT_BEGIN()
    range = gboard_engine_range((void *)(uintptr_t)g_engine, index);
    CRASH_PROTECT_END("nativeGetCandidateRange")
    if (range.start < 0 || range.end <= range.start) return -1;
    int start_v = range.start, end_v = range.end;
    LOG("getCandidateRange(%d) → start=%d end=%d (g_end_vertex=%d)", index, start_v, end_v, g_end_vertex);
    int consumed = end_v - s_context_end_vertex;
    return consumed >= 0 ? consumed : -1;
}

int hmm_engine_get_separator(int vertex_index) {
    if (!g_engine) return -1;
    int result = -1;
    CRASH_PROTECT_BEGIN()
    result = gboard_engine_get_separator((void *)(uintptr_t)g_engine,
                                         s_context_end_vertex + vertex_index);
    CRASH_PROTECT_END("nativeGetSeparator")
    return result;
}

bool hmm_engine_set_separator(int vertex_index, int separator_type) {
    if (!g_engine) return false;
    bool result = false;
    CRASH_PROTECT_BEGIN()
    result = gboard_engine_set_separator((void *)(uintptr_t)g_engine,
                                         s_context_end_vertex + vertex_index,
                                         separator_type);
    CRASH_PROTECT_END("nativeSetSeparator")
    return result;
}

int hmm_engine_get_segmented_pinyin(char *text, int max_bytes) {
    if (!text || max_bytes < 1 || !g_engine) return 0;
    text[0] = '\0';
    void *engine = (void *)(uintptr_t)g_engine;

    int segCount = 0;
    CRASH_PROTECT_BEGIN()
    segCount = gboard_engine_segment_count(engine);
    CRASH_PROTECT_END("getSegmentCount")

    int written = 0;
    bool has_token = false;
    int prev_language = -1;
    for (int s = 0; s < segCount && written < max_bytes - 1; s++) {
        void *seg = NULL;
        CRASH_PROTECT_BEGIN()
        seg = gboard_engine_segment(engine, s);
        CRASH_PROTECT_END("getSegment")
        if (!seg) continue;

        GboardRange range = { -1, -1 };
        CRASH_PROTECT_BEGIN()
        range = gboard_engine_segment_range(engine, seg);
        CRASH_PROTECT_END("getSegmentRange")
        if (range.start < 0 || range.end <= range.start) continue;
        int start_v = range.start, end_v = range.end;
        if (start_v < s_context_end_vertex) continue;
        if (start_v < candidate_start_vertex()) continue;
        bool converted = false;
        CRASH_PROTECT_BEGIN()
        converted = gboard_engine_segment_converted(engine, seg);
        CRASH_PROTECT_END("nativeIsSegmentConverted")
        if (converted) continue;

        int tokenCount = 0;
        CRASH_PROTECT_BEGIN()
        tokenCount = gboard_engine_segment_token_count(engine, seg);
        CRASH_PROTECT_END("getSegmentTokenCount")

        for (int t = 0; t < tokenCount && written < max_bytes - 1; t++) {
            void *token = NULL;
            CRASH_PROTECT_BEGIN()
            token = gboard_engine_segment_token(engine, seg, t);
            CRASH_PROTECT_END("getSegmentToken")
            if (!token) continue;

            char *token_text = NULL;
            CRASH_PROTECT_BEGIN()
            token_text = gboard_engine_token_string_dup(engine, token);
            CRASH_PROTECT_END("nativeGetTokenString")
            if (!token_text || !token_text[0]) {
                free(token_text);
                continue;
            }

            int language = -1;
            CRASH_PROTECT_BEGIN()
            language = gboard_engine_token_language(engine, token);
            CRASH_PROTECT_END("nativeGetTokenLanguage")
            bool join = has_token && language == 0 && prev_language == 0;
            prev_language = language;

            if (has_token && !join && written < max_bytes - 1) {
                text[written++] = '\'';
                text[written] = '\0';
            }
            int available = max_bytes - 1 - written;
            int length = (int)strlen(token_text);
            if (length > available) length = available;
            memcpy(text + written, token_text, (size_t)length);
            free(token_text);
            written += length;
            text[written] = '\0';
            has_token = true;
        }
    }
    return written;
}

static void copy_token_text(char *dst, size_t max, const char *src) {
    if (!src) src = "";
    size_t length = strlen(src);
    if (length >= max) length = max - 1;
    memcpy(dst, src, length);
    dst[length] = '\0';
}

int hmm_engine_get_corrected_candidate_reading(int index,
                                               HmmTokenReading *tokens,
                                               int max_tokens) {
    if (!tokens || max_tokens < 1 || !g_engine) return 0;
    void *engine = (void *)(uintptr_t)g_engine;

    int filled = 0;
    int count = 0;
    CRASH_PROTECT_BEGIN()
    if (gboard_engine_is_candidate_corrected(engine, index)) {
        count = gboard_engine_candidate_token_count(engine, index);
    }
    CRASH_PROTECT_END("corrected candidate reading")
    if (count > 0 && count <= max_tokens) {
        volatile int i = 0;
        CRASH_PROTECT_BEGIN()
        for (; i < count; i++) {
            void *token = gboard_engine_candidate_token(engine, index, i);
            if (!token) break;
            HmmTokenReading *reading = &tokens[i];
            char *raw = gboard_engine_token_string_dup(engine, token);
            copy_token_text(reading->raw, sizeof(reading->raw), raw);
            free(raw);
            if (!reading->raw[0]) break;
            char *normalized = gboard_engine_token_normalized_string_dup(engine, token);
            copy_token_text(reading->normalized, sizeof(reading->normalized),
                            normalized);
            free(normalized);
            if (!reading->normalized[0]) {
                memcpy(reading->normalized, reading->raw,
                       sizeof(reading->normalized));
            }
            reading->language = gboard_engine_token_language(engine, token);
        }
        CRASH_PROTECT_END("corrected candidate reading")
        if (i == count) filled = count;
    }
    return filled;
}

bool hmm_engine_select(int index) {
    if (!g_engine) return false;
    if (s_converted_count >= MAX_CONVERTED_RANGES) return false;
    int start = 0, end = 0;
    bool has_range = false;
    GboardRange range = { -1, -1 };
    CRASH_PROTECT_BEGIN()
    range = gboard_engine_range((void *)(uintptr_t)g_engine, index);
    CRASH_PROTECT_END("nativeGetCandidateRange(select)")
    start = range.start;
    end = range.end;
    has_range = start >= 0 && end > start;
    bool result = false;
    CRASH_PROTECT_BEGIN()
    result = gboard_engine_select((void *)(uintptr_t)g_engine, index);
    CRASH_PROTECT_END("nativeSelectCandidate")
    if (result && has_range) {
        s_converted[s_converted_count++] = (VertexRange){ start, end };
    }
    return (bool)result;
}

bool hmm_engine_delete_last_input(void) {
    if (!g_engine) return false;
    if (g_end_vertex <= candidate_start_vertex()) return false;
    GboardRange range = { g_end_vertex - 1, g_end_vertex };
    bool result = false;
    CRASH_PROTECT_BEGIN()
    result = gboard_engine_delete((void *)(uintptr_t)g_engine, range);
    CRASH_PROTECT_END("nativeDelete")
    if (!result) return false;
    g_end_vertex--;
    return true;
}

uint64_t hmm_engine_input_generation(void) {
    return s_input_generation;
}

bool hmm_engine_can_edit_in_place(uint64_t generation, int letters,
                                  int next_letters) {
    return g_engine && generation == s_input_generation &&
           s_settings_ready && s_converted_count == 0 &&
           s_context_injected && letters >= 0 && next_letters >= 0 &&
           g_end_vertex - s_context_end_vertex == letters &&
           hmm_engine_decoder_for_input_length((size_t)next_letters) ==
               g_engine;
}

int hmm_engine_get_converted_count(void) {
    return s_converted_count;
}

bool hmm_engine_unconvert_last(void) {
    if (s_converted_count == 0 || !g_engine) return false;
    VertexRange last = s_converted[s_converted_count - 1];
    GboardRange range = { last.start, last.end };
    bool result = false;
    CRASH_PROTECT_BEGIN()
    result = gboard_engine_unconvert((void *)(uintptr_t)g_engine, range);
    CRASH_PROTECT_END("nativeUnconvertSegments")
    if (!result) return false;
    s_converted_count--;
    return true;
}

void hmm_engine_reset(void) {
    s_input_generation++;
    g_end_vertex = 0;
    s_converted_count = 0;
    s_context_injected = false;
    s_context_end_vertex = 0;
    volatile bool reset_ok = false;
    if (g_engine) {
        CRASH_PROTECT_BEGIN()
        gboard_engine_reset((void *)(uintptr_t)g_engine);
        reset_ok = true;
        CRASH_PROTECT_END("nativeReset")
    }
    s_settings_ready = reset_ok && hmm_engine_refresh_settings_after_reset();
    hmm_user_dict_refresh_decoder_if_needed();
}
