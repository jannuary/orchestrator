"""Clone source memory/CPU and execute a pinned original instruction span only.

Developer oracle helper: no external imports, SDK calls or captured user data.
The caller hashes the original artifact and validates all observed reads/output.
The original code bytes replace the span explicitly; source memory supplies
its invented-call data and stack. No emulation is shipped in the package.
"""
import ctypes as C
from types import SimpleNamespace

from verify_fill_dispatch import segment_read


def clone_span(fs,regions,count,image,begin,end):
    from unicorn import Uc,UC_ARCH_X86,UC_MODE_64
    from unicorn import x86_const as r
    mu=Uc(UC_ARCH_X86,UC_MODE_64);spans=[]
    for i in range(count):
        region=regions[i]
        if region.size:spans.append((region.address&~4095,(region.address+region.size+4095)&~4095))
    spans.append((begin&~4095,(end+4095)&~4095));merged=[]
    for low,high in sorted(spans):
        if merged and low<=merged[-1][1]:merged[-1]=(merged[-1][0],max(high,merged[-1][1]))
        else:merged.append((low,high))
    for low,high in merged:mu.mem_map(low,high-low)
    for i in range(count):
        region=regions[i]
        if region.size:mu.mem_write(region.address,C.string_at(region.data,region.size))
    mu.mem_write(begin,segment_read(image,begin,end-begin))
    state=fs.contents;names=('RAX','RBX','RCX','RDX','RSI','RDI','RBP','RSP','R8','R9','R10','R11','R12','R13','R14','R15')
    for name,value in zip(names,state.cpu.gpr):mu.reg_write(getattr(r,'UC_X86_REG_'+name),value)
    mu.reg_write(r.UC_X86_REG_EFLAGS,state.cpu.flags);mu.reg_write(r.UC_X86_REG_RIP,state.cpu.pc);mu.reg_write(r.UC_X86_REG_FS_BASE,state.tls)
    for i in range(16):mu.reg_write(getattr(r,'UC_X86_REG_XMM'+str(i)),state.xmm[2*i]|(state.xmm[2*i+1]<<64))
    return SimpleNamespace(mu=mu,original_instruction_span=(begin,end))
