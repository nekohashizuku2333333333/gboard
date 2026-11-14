#!/usr/bin/env python3
"""Extract the JNINativeMethod tables from an Android AArch64 ELF.

Outputs a tab-separated table of:

    name<TAB>signature<TAB>file_vaddr<TAB>table_vaddr

The function addresses are original ELF virtual addresses.  To decompile them
with Ghidra, add the imported image base (see docs/native-abi-migration.md).

Only reads the file; never loads or executes the target.
"""

import argparse
import hashlib
import struct
import sys


def align(value, page=0x4000):
    return (value + page - 1) & ~(page - 1)


class Elf:
    def __init__(self, path):
        self.data = open(path, "rb").read()
        d = self.data
        if d[:4] != b"\x7fELF" or d[4] != 2 or d[5] != 1:
            raise SystemExit("expected a little-endian ELF64 file")
        self.e_phoff = struct.unpack_from("<Q", d, 32)[0]
        self.e_phnum = struct.unpack_from("<H", d, 56)[0]
        e_shoff = struct.unpack_from("<Q", d, 40)[0]
        e_shnum = struct.unpack_from("<H", d, 60)[0]
        e_shstrndx = struct.unpack_from("<H", d, 62)[0]

        self.ph = []
        for i in range(self.e_phnum):
            t, fl, off, va, pa, fs, ms, al = struct.unpack_from(
                "<IIQQQQQQ", d, self.e_phoff + i * 56)
            self.ph.append(dict(type=t, flags=fl, off=off, vaddr=va,
                                filesz=fs, memsz=ms, align=al))

        self.sections = []
        for i in range(e_shnum):
            name, typ, flags, addr, off, size, link, info, a, ent = \
                struct.unpack_from("<IIQQQQIIQQ", d, e_shoff + i * 64)
            self.sections.append(dict(name_off=name, type=typ, flags=flags,
                                      addr=addr, off=off, size=size))
        if e_shstrndx < len(self.sections):
            base = self.sections[e_shstrndx]["off"]
            for s in self.sections:
                end = d.index(b"\0", base + s["name_off"])
                s["name"] = d[base + s["name_off"]:end].decode("latin1")
        else:
            for s in self.sections:
                s["name"] = ""

        self.dyn = {}
        for p in self.ph:
            if p["type"] != 2:
                continue
            o = p["off"]
            while True:
                tag, val = struct.unpack_from("<QQ", d, o)
                if tag == 0:
                    break
                self.dyn[tag] = val
                o += 16
        self._relocs()

    def v2o(self, va):
        for p in self.ph:
            if p["type"] == 1 and p["vaddr"] <= va < p["vaddr"] + p["filesz"]:
                return p["off"] + (va - p["vaddr"])
        return None

    def read(self, va, size):
        o = self.v2o(va)
        if o is None or o + size > len(self.data):
            return None
        return self.data[o:o + size]

    def u64(self, va):
        b = self.read(va, 8)
        return struct.unpack("<Q", b)[0] if b else 0

    def cstr(self, va, limit=512):
        o = self.v2o(va)
        if o is None:
            return None
        end = self.data.find(b"\0", o, min(len(self.data), o + limit))
        if end < 0:
            return None
        b = self.data[o:end]
        if not b or any(c < 9 or c > 126 for c in b):
            return None
        return b.decode("latin1")

    @staticmethod
    def _sleb(b, o):
        r = 0
        s = 0
        while True:
            x = b[o]
            o += 1
            r |= (x & 0x7F) << s
            s += 7
            if not (x & 0x80):
                if s < 64 and (x & 0x40):
                    r |= ~0 << s
                return r, o

    def _relocs(self):
        """Map RELATIVE relocation vaddr -> addend; needed for table pointers."""
        self.relmap = {}
        d = self.data
        if 0x60000011 in self.dyn and 0x60000012 in self.dyn:
            start = self.v2o(self.dyn[0x60000011])
            size = self.dyn[0x60000012]
            if start is None:
                return
            b = d[start:start + size]
            if b[:4] != b"APS2":
                return
            count, o = self._sleb(b, 4)
            off, o = self._sleb(b, o)
            applied = 0
            addend = 0
            while applied < count and o < len(b):
                group, o = self._sleb(b, o)
                flags, o = self._sleb(b, o)
                go = 0
                gr = 0
                if flags & 2:
                    go, o = self._sleb(b, o)
                if flags & 1:
                    gr, o = self._sleb(b, o)
                if (flags & 4) and (flags & 8):
                    addend, o = self._sleb(b, o)
                elif not (flags & 8):
                    addend = 0
                for _ in range(group):
                    if flags & 2:
                        off += go
                    else:
                        delta, o = self._sleb(b, o)
                        off += delta
                    if flags & 1:
                        info = gr
                    else:
                        info, o = self._sleb(b, o)
                    if flags & 8:
                        if not (flags & 4):
                            delta, o = self._sleb(b, o)
                            addend += delta
                    else:
                        addend = 0
                    if info & 0xFFFFFFFF == 1027:  # R_AARCH64_RELATIVE
                        self.relmap[off] = addend
                    applied += 1

        jmprel = self.dyn.get(23)
        pltrelsz = self.dyn.get(2)
        if jmprel and pltrelsz:
            for k in range(pltrelsz // 24):
                ro, ri, add = struct.unpack_from(
                    "<QQq", d, self.v2o(jmprel) + k * 24)
                if ri & 0xFFFFFFFF == 1027:
                    self.relmap[ro] = add

    def value(self, va):
        if va in self.relmap:
            return self.relmap[va]
        return self.u64(va)

    def is_exec(self, va):
        return any(p["type"] == 1 and (p["flags"] & 1)
                   and p["vaddr"] <= va < p["vaddr"] + p["memsz"]
                   for p in self.ph)


def find_tables(elf):
    data_sections = [s for s in elf.sections
                     if s["type"] != 8 and s["name"] in
                     (".data.rel.ro", ".data", ".rodata")]
    tables = []
    for sec in data_sections:
        addr = sec["addr"]
        end = addr + sec["size"]
        while addr + 24 <= end:
            name = elf.cstr(elf.value(addr))
            sig = elf.cstr(elf.value(addr + 8))
            fn = elf.value(addr + 16)
            if name and sig and sig.startswith("(") and elf.is_exec(fn):
                entries = []
                cur = addr
                while cur + 24 <= end:
                    n = elf.cstr(elf.value(cur))
                    s = elf.cstr(elf.value(cur + 8))
                    f = elf.value(cur + 16)
                    if not n or not s or not s.startswith("(") or not elf.is_exec(f):
                        break
                    entries.append((n, s, f))
                    cur += 24
                if len(entries) >= 4:
                    tables.append((sec["name"], addr, entries))
                    addr = cur
                    continue
            addr += 8
    return tables


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("elf", help="libintegrated_shared_object.so")
    ap.add_argument("-o", "--output", help="write TSV here instead of stdout")
    ap.add_argument("--table-address", type=lambda x: int(x, 0),
                    help="only inspect this table address (file vaddr)")
    args = ap.parse_args()

    elf = Elf(args.elf)
    digest = hashlib.sha256(elf.data).hexdigest()
    tables = find_tables(elf)
    if args.table_address is not None:
        tables = [t for t in tables if t[1] == args.table_address]
        if not tables:
            raise SystemExit("no JNINativeMethod table at 0x%x" % args.table_address)

    rows = []
    for sec, addr, entries in tables:
        print("/* table %s @ 0x%x: %d entries */" % (sec, addr, len(entries)),
              file=sys.stderr)
        for name, sig, fn in entries:
            rows.append((name, sig, fn, addr))

    out = sys.stdout if not args.output else open(args.output, "w")
    out.write("name\tsignature\tfile_vaddr\ttable_vaddr\n")
    for name, sig, fn, table in rows:
        out.write("%s\t%s\t0x%x\t0x%x\n" % (name, sig, fn, table))
    if out is not sys.stdout:
        out.close()
    print("/* sha256 %s; %d natives */" % (digest, len(rows)), file=sys.stderr)


if __name__ == "__main__":
    main()