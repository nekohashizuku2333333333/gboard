// Direct C++ ABI bridge sketch for Gboard's HMM engine.
//
// This file is a migration design artifact, not part of the build. It shows how
// the JNI wrappers in docs/decompiled/jni_wrappers.c map to direct vtable calls.
// Addresses/offsets are specific to the researched Gboard 18.5.9 build.
//
// ABI assumptions to verify before wiring this in:
//   * libc++ std::string / std::vector layout (24 bytes, SSO flag in byte 0)
//   * Itanium C++ vtable layout, offset 0 = vptr
//   * no C++ exceptions cross the bridge
//
// The engine object is the same pointer returned by nativeCreateEngine's jlong.

#include <cstdint>
#include <string>
#include <vector>

namespace gboard {

// The engine's strings use the Android libc++ layout, not the macOS default.
// Verified raw return for "你好": 0c e4 bd a0 e5 a5 bd 00 ... (0x0C marker).
// The layout must be recovered from the engine's own conversion helper; this
// adapter is deliberately explicit instead of pretending std::string matches.
struct AndroidString {
    alignas(8) unsigned char b[24];
};

AndroidString from_utf8(const std::string& s);   // TODO: short/long encoding
std::string to_utf8(const AndroidString& s);     // TODO: Android layout decode

struct ScoredInput {
    AndroidString input;  // 24 bytes, Android layout
    float score;          // + 4 bytes, 0x20 per element
};

struct Range {
    std::int32_t start;
    std::int32_t end;
};

using Factory = void;
using Engine = void;
using DataManager = void;

template <class Fn>
static Fn slot(void* object, std::uintptr_t offset) {
    auto** vptr = *reinterpret_cast<void***>(object);
    return *reinterpret_cast<Fn*>(reinterpret_cast<char*>(vptr) + offset);
}

// nativeCreateEngineFactory: no JNI arguments; returns a C++ factory object.
// Resolve the actual entry from the engine image (file vaddr 0x10c92a0 in the
// researched build) or from the JNINativeMethod table.
Factory* create_factory();

DataManager* get_data_manager(Factory* f) {
    return slot<DataManager* (*)(Factory*)>(f, 0x28)(f);
}

// nativeCreateEngine: the JNI wrapper converts Java strings and calls the
// internal factory path. The direct version must call the same internal
// constructor with std::string data/setting ids. Signature still needs
// confirmation from FUN_011cdfdc / FUN_011ce9e0.
Engine* create_engine(Factory* f, const std::string& data_id,
                      const std::string& setting_id);

void reset(Engine* e) {
    slot<void (*)(Engine*)>(e, 0xa0)(e);
}

int append(Engine* e, const ScoredInput* in, int n, int type) {
    std::vector<ScoredInput> v(in, in + n);
    return slot<int (*)(Engine*, std::vector<ScoredInput>*, int)>(e, 0x38)(e, &v, type);
}

bool fill_candidates(Engine* e, const Range& r) {
    return slot<bool (*)(Engine*, const Range*)>(e, 0x1c8)(e, &r);
}

int candidate_count(Engine* e) {
    return slot<int (*)(Engine*)>(e, 0x1d0)(e);
}

bool select_candidate(Engine* e, int index) {
    return slot<bool (*)(Engine*, int)>(e, 0x1d8)(e, index);
}

std::string candidate_string(Engine* e, int index) {
    // Non-trivial return uses x8 sret; this and index are the explicit args.
    AndroidString raw = slot<AndroidString (*)(Engine*, int)>(e, 0x200)(e, index);
    std::string s = to_utf8(raw);
    // Raw strings carry a 0x0C correction marker; the JNI wrapper strips it.
    if (!s.empty() && s[0] == '\f') s.erase(0, 1);
    return s;
}

Range candidate_range(Engine* e, int index) {
    return slot<Range (*)(Engine*, int)>(e, 0x220)(e, index);
}

Range decoding_range(Engine* e) {
    return slot<Range (*)(Engine*)>(e, 0xb8)(e);
}

bool select_range(Engine* e, const Range& r) {
    return slot<bool (*)(Engine*, const Range*)>(e, 0x90)(e, &r);
}

// Token / prediction / segment methods follow the same pattern; see
// docs/native_abi.tsv for the offset of each native.

}  // namespace gboard