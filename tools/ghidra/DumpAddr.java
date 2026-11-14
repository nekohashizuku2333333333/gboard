import ghidra.app.decompiler.*;
import ghidra.app.cmd.disassemble.DisassembleCommand;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import java.io.*;

public class DumpAddr extends GhidraScript {
    public void run() throws Exception {
        String[] a = getScriptArgs();
        String out = a[0];
        PrintWriter w = new PrintWriter(new BufferedWriter(new FileWriter(out)));
        AddressSpace sp = currentProgram.getAddressFactory().getDefaultAddressSpace();
        DecompInterface di = new DecompInterface(); di.openProgram(currentProgram);
        java.util.List<String> vals = new java.util.ArrayList<>();
        for (int i = 1; i < a.length; i++) for (String t : a[i].split(",")) if (!t.isEmpty()) vals.add(t);
        for (String sv : vals) {
            long v = Long.decode(sv);
            Address ad = sp.getAddress(v);
            Function f = getFunctionAt(ad);
            if (f == null || !f.getEntryPoint().equals(ad)) {
                if (f != null) currentProgram.getFunctionManager().removeFunction(f.getEntryPoint());
                new DisassembleCommand(ad, null, true).applyTo(currentProgram, monitor);
                f = createFunction(ad, "FUN_" + Long.toHexString(v));
            }
            w.println("\n/* ==== " + sv + " " + (f == null ? "NOFUNC" : f.getName()) + " @ " + ad
                      + " size=" + (f == null ? 0 : f.getBody().getNumAddresses()) + " ==== */");
            if (f != null) {
                DecompileResults r = di.decompileFunction(f, 60, monitor);
                w.println(r != null && r.decompileCompleted() && r.getDecompiledFunction() != null
                          ? r.getDecompiledFunction().getC() : "// decompile failed");
                for (Function c : f.getCalledFunctions(monitor))
                    if (!c.isExternal()) w.println("// calls " + c.getName() + " @ " + c.getEntryPoint());
            }
        }
        w.close();
        println("DumpAddr -> " + out);
    }
}
