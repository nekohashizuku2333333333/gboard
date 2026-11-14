import ghidra.app.decompiler.*;
import ghidra.app.cmd.disassemble.DisassembleCommand;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSpace;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.Memory;
import java.io.*;
import java.util.*;

public class JniDecompile extends GhidraScript {
    private AddressSpace sp;
    private Memory mem;
    private DecompInterface di;
    private PrintWriter w;
    private Set<Long> dumped = new HashSet<>();

    private String cstrAt(long va) {
        StringBuilder sb = new StringBuilder();
        try {
            Address a = sp.getAddress(va);
            for (int i = 0; i < 512; i++) {
                byte b = mem.getByte(a.add(i));
                if (b == 0) break;
                sb.append((char) (b & 0xff));
            }
        } catch (Exception e) { return null; }
        String s = sb.toString();
        return s.isEmpty() ? null : s;
    }
    private String cstr(long va) {
        String s = cstrAt(va);
        if (s == null || s.contains("\uFFFD")) {
            String s2 = cstrAt(va - 0x100000L);
            if (s2 != null && !s2.contains("\uFFFD")) return s2;
        }
        return s;
    }

    private String dec(Function f) {
        DecompileResults r = di.decompileFunction(f, 60, monitor);
        if (r == null || !r.decompileCompleted() || r.getDecompiledFunction() == null)
            return "// decompile failed";
        return r.getDecompiledFunction().getC();
    }

    private void dump(Function f, String why) {
        long k = f.getEntryPoint().getOffset();
        if (dumped.contains(k)) return;
        dumped.add(k);
        w.println("\n/* === " + why + " | " + f.getName() + " @ " + f.getEntryPoint()
                + " size=" + f.getBody().getNumAddresses() + " === */");
        w.println(dec(f));
        for (Function c : f.getCalledFunctions(monitor)) {
            if (!c.isExternal()) w.println("// calls " + c.getName() + " @ " + c.getEntryPoint());
        }
    }

    public void run() throws Exception {
        String[] args = getScriptArgs();
        String out = args.length > 0 ? args[0] : "/tmp/gb/jni_decompiled.c";
        String filter = args.length > 1 ? args[1] : "";
        long table = args.length > 2 ? Long.decode(args[2]) : 0x20fcff8L;
        Set<String> wanted = new HashSet<>();
        if (!filter.isEmpty() && !filter.equals("all")) for (String s : filter.split(",")) wanted.add(s.trim());
        w = new PrintWriter(new BufferedWriter(new FileWriter(out)));
        sp = currentProgram.getAddressFactory().getDefaultAddressSpace();
        mem = currentProgram.getMemory();
        di = new DecompInterface();
        di.toggleCCode(true);
        di.toggleSyntaxTree(true);
        di.openProgram(currentProgram);
        w.println("// table " + Long.toHexString(table));
        int count = 0, dumpedBefore = 0;
        for (int i = 0; i < 400; i++) {
            long ea = table + i * 24L;
            long namep, sigp, fn;
            try {
                namep = mem.getLong(sp.getAddress(ea));
                sigp = mem.getLong(sp.getAddress(ea + 8));
                fn = mem.getLong(sp.getAddress(ea + 16));
            } catch (Exception e) { println("read fail at " + Long.toHexString(ea) + ": " + e); break; }
            if (i < 3) println("entry " + i + " namep=" + Long.toHexString(namep) + " sigp=" + Long.toHexString(sigp) + " fn=" + Long.toHexString(fn));
            String name = namep == 0 ? null : cstr(namep);
            String sig = sigp == 0 ? null : cstr(sigp);
            if (name == null || name.isEmpty() || sig == null || !sig.startsWith("(")) break;
            count++;
            if (!wanted.isEmpty() && !wanted.contains(name)) continue;
            Address fa = sp.getAddress(fn);
            Function f = getFunctionAt(fa);
            if (f != null && !f.getEntryPoint().equals(fa)) f = null;
            if (f != null && f.getBody().getNumAddresses() < 8) {
                currentProgram.getFunctionManager().removeFunction(f.getEntryPoint());
                f = null;
            }
            if (f == null) {
                try {
                    new DisassembleCommand(fa, null, true).applyTo(currentProgram, monitor);
                    f = createFunction(fa, "JNI_" + name);
                } catch (Exception e) { w.println("// cannot create " + name + " @ " + fa + " : " + e); continue; }
            }
            w.println("// " + name + " " + sig + " -> " + fa);
            dump(f, name + " " + sig);
        }
        w.println("// table entries: " + count + ", dumped: " + dumped.size());
        w.close();
        println("JniDecompile: entries=" + count + " dumped=" + dumped.size() + " -> " + out);
    }
}
