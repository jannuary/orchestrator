"""Check column rewrite proofs and execution on invented four-read programs."""
import argparse
import json
from pathlib import Path
import struct
import subprocess
import tempfile

from prove_guid_column_rewrites import ColumnRewriter
from trace_lookup_dataflow import LookupTrace
from recover_guid_word_consumers import GPRS


def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--output',type=Path,required=True)
    args=parser.parse_args();results=[]
    from capstone import Cs,CS_ARCH_X86,CS_MODE_64,CS_OP_MEM
    from unicorn import Uc,UC_ARCH_X86,UC_MODE_64,UC_HOOK_CODE
    from unicorn import x86_const as r
    import z3 as z
    with tempfile.TemporaryDirectory(prefix='ams-column-rewrite-controls-') as directory:
        directory=Path(directory)
        for operation in ('xor','add','and'):
            source=directory/(operation+'.s');object_=directory/(operation+'.o');binary=directory/(operation+'.bin')
            source.write_text('.intel_syntax noprefix\n.text\nmov eax,DWORD PTR [rbx+rcx*4]\nmov edx,DWORD PTR [r12+rcx*4]\n'+operation+' eax,edx\nmov esi,DWORD PTR [r13+rcx*4]\n'+operation+' eax,esi\nmov edi,DWORD PTR [r14+rcx*4]\n'+operation+' eax,edi\nxor eax,17\nmov r9d,eax\nmov DWORD PTR [rbp-8],eax\nnop\n')
            subprocess.run(['cc','-c',str(source),'-o',str(object_)],check=True,capture_output=True)
            subprocess.run(['objcopy','-O','binary','--only-section=.text',str(object_),str(binary)],check=True,capture_output=True)
            code=binary.read_bytes();base=0x1000000;bias=0x4000000
            decoder=Cs(CS_ARCH_X86,CS_MODE_64);decoder.detail=True;instructions=list(decoder.disasm(code,base))
            loads=[ins.address for ins in instructions if ins.mnemonic=='mov' and ins.operands[0].type!=CS_OP_MEM and any(operand.type==CS_OP_MEM for operand in ins.operands)]
            assert len(loads)==4
            expected=[(pc+bias,index,0,0) for index,pc in enumerate(loads)]+[(base+bias+len(code),4,0,0)]
            image=bytearray(0x2000);image[:6]=b'\x7fELF\x02\x01';struct.pack_into('<Q',image,32,64);struct.pack_into('<HH',image,54,56,1)
            struct.pack_into('<IIQQQQQQ',image,64,1,5,0x1000,base,0,len(code)+16,4096,4096)
            image[0x1000:0x1000+len(code)+16]=code+bytes([0x90])*16;image=bytes(image)
            words=[z.BitVec('control_word_'+str(j),32) for j in range(4)]
            reference=dict(z=z,words=words,contributions=words)
            tables=[[value<<(8*j) for value in range(256)] for j in range(4)]
            arrays=[b''.join(value.to_bytes(4,'little') for value in table) for table in tables]
            plan=ColumnRewriter(expected,image,reference,tables,arrays)
            if operation=='and':
                assert plan.group_count==0 and not plan.points
                results.append(dict(program=operation,rejected=True));continue
            assert plan.group_count==1 and plan.points
            if operation=='add':assert plan.proofs['word_planes_unsat']
            checks=0
            for index in (0,1,31,127,128,255):
                mu=Uc(UC_ARCH_X86,UC_MODE_64);mu.mem_map(base+bias,4096);mu.mem_write(base+bias,code)
                stack=0x2000000;mu.mem_map(stack,4096);mu.reg_write(r.UC_X86_REG_RBP,stack+0x800)
                allocated=[]
                for ordinal,register in enumerate(('rbx','r12','r13','r14')):
                    address=0x3000000+ordinal*4096;mu.mem_map(address,4096);mu.mem_write(address,arrays[ordinal]);allocated.append((address,1024))
                    mu.reg_write(getattr(r,'UC_X86_REG_'+register.upper()),address)
                mu.reg_write(r.UC_X86_REG_RCX,index)
                trace=LookupTrace(mu,allocated,range(4),range(4,8),{j:data for j,data in enumerate(arrays)})
                plan.contexts.clear();plan.active_group=None;plan.bind(trace,mu)
                def step(m,pc,size,user):plan.step(trace,m,pc);trace.step(m,pc,size)
                mu.hook_add(UC_HOOK_CODE,step);mu.emu_start(base+bias,base+bias+len(code),count=64)
                assert not trace.errors and trace.regular_reads==4
                for name in GPRS:
                    assert trace.concrete(trace.reg(mu,name))==mu.reg_read(getattr(r,'UC_X86_REG_'+name.upper()))
                modeled=z.Concat(*(trace.memory[stack+0x800-8+j] for j in reversed(range(4))))
                assert trace.concrete(modeled)==int.from_bytes(mu.mem_read(stack+0x800-8,4),'little')
                checks+=1
            results.append(dict(program=operation,register_and_memory_execution_cases=checks,proofs=plan.summary()))
    report=dict(status='pass',programs=results,
        scope='invented lookup planes and register programs; unrestricted XOR and valid-plane addition accepted, wrong AND rejected; complete modeled registers and stored word compared with original instruction execution; no target data emitted')
    args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))


if __name__=='__main__':main()
