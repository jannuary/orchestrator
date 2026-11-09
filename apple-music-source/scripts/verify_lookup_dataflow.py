"""Exercise symbolic lookup tracking using invented x86 instruction programs."""
import argparse
import json
from pathlib import Path
import random
import subprocess
import tempfile

from trace_lookup_dataflow import LookupTrace


ASSEMBLY='''
.intel_syntax noprefix
.text
mov rbx, 0x3000000
mov ecx, 7
mov eax, DWORD PTR [rbx+rcx*4]
mov edx, eax
mov ah, 0x5c
mov QWORD PTR [rbp-8], rax
mov rax, QWORD PTR [rbp-8]
xor eax, edx
rol eax, 7
ror eax, 7
and eax, 255
lea rsi, [rbx+4096]
mov r8d, DWORD PTR [rsi+rax*4]
mov eax, edx
add eax, -17
adc edx, 0
and edx, 255
mov r9d, DWORD PTR [rsi+rdx*4]
mov r11, 0x10000000
mov eax, r9d
and eax, 255
movzx r12d, BYTE PTR [r11+rax]
cmp edx, 4
sete al
movzx eax, al
mov r10d, DWORD PTR [rsi+rax*4]
mov eax, DWORD PTR [rbx+28]
nop
'''


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--output',type=Path,required=True);args=p.parse_args()
    from unicorn import Uc,UC_ARCH_X86,UC_MODE_64,UC_HOOK_CODE
    from unicorn import x86_const as r
    rng=random.Random(0x733812);cases=[]
    with tempfile.TemporaryDirectory(prefix='ams-symbolic-lookup-controls-') as directory:
        source=Path(directory)/'control.s';object_=Path(directory)/'control.o';binary=Path(directory)/'control.bin'
        source.write_text(ASSEMBLY)
        subprocess.run(['cc','-c',str(source),'-o',str(object_)],check=True,capture_output=True)
        subprocess.run(['objcopy','-O','binary','--only-section=.text',str(object_),str(binary)],check=True,capture_output=True)
        code=binary.read_bytes()
        for case in range(16):
            constrained=case>=8;initial=(0,4,5,17,0x7fffffff,0x80000000,0xfffffff9,0xffffffff)[case%8]
            mu=Uc(UC_ARCH_X86,UC_MODE_64);mu.mem_map(0x1000000,4096);mu.mem_map(0x2000000,8192);mu.mem_map(0x3000000,32768)
            mu.mem_map(0x10000000,4096);mu.mem_write(0x10000000,bytes(range(256)))
            mu.mem_write(0x1000000,code);mu.reg_write(r.UC_X86_REG_RBP,0x2001000);mu.reg_write(r.UC_X86_REG_RSP,0x2001ff0)
            allocated=[];domains=[]
            for ordinal in range(8):
                address=0x3000000+ordinal*4096;allocated.append((address,1028))
                if constrained:
                    columns=[(1<<bit)*0x01010101 for bit in range(8)];offset=(initial^7*0x01010101) if ordinal==0 else rng.getrandbits(32)
                    from analyze_table_algebra import apply
                    data=b''.join((offset^apply(columns,x)).to_bytes(4,'little') for x in range(256))
                else:data=b''.join(rng.getrandbits(32).to_bytes(4,'little') for _ in range(256))
                domains.append(data);mu.mem_write(address,data)
            if not constrained:mu.mem_write(0x3000000+28,initial.to_bytes(4,'little'))
            normalized=case in (6,7,14,15);mask=0xa5c3017b
            transformed={index:b''.join((int.from_bytes(data[j:j+4],'little')^mask).to_bytes(4,'little') for j in range(0,1024,4)) for index,data in enumerate(domains)} if normalized and constrained else domains if constrained else None
            indexed_word=case in (5,13)
            if indexed_word and constrained:
                transformed=[b''.join((int.from_bytes(data[j:j+4],'little')^((j//4)^0x5a)).to_bytes(4,'little') for j in range(0,1024,4)) for data in domains]
            inline_domains=case in (9,13,15)
            trace=LookupTrace(mu,allocated,range(4),range(4,8),transformed,inline_word_domains=inline_domains)
            index_normalized=case in (4,5,12,13)
            if index_normalized:
                trace.index_expression_transform=lambda ordinal,value:value^0x5a
                trace.index_value_transform=lambda ordinal,value:value^0x5a
            if indexed_word:
                trace.indexed_word_value_transform=lambda ordinal,index,value:value^index
                trace.indexed_word_expression_transform=lambda ordinal,index,value:value^trace.z.ZeroExt(24,index)
            if normalized:
                trace.word_value_transform=lambda ordinal,value:value^mask
                trace.word_expression_transform=lambda ordinal,value:value^mask
            mu.hook_add(UC_HOOK_CODE,trace.step)
            mu.emu_start(0x1000000,0x1000000+len(code),count=1000)
            report=trace.summary()
            assert not report['errors'],report
            assert report['lookup_occurrences']==report['symbolic_index_replay_checks']==5
            assert report['distinct_lookup_values']<report['lookup_occurrences']
            assert any(event['dependencies'] for event in trace.events)
            assert len(report['symbolic_readonly_byte_reads'])==1
            assert trace.events[0]['index']==(7^0x5a if index_normalized else 7)
            assert all(trace.concrete(event['expression'])==event['index'] for event in trace.events)
            assert trace.indexed_word_inverse_checks==(5 if indexed_word else 0)
            shared=trace.word_expressions[0];expected=trace.word_values[0]
            for _ in range(64):shared=(shared<<1)^shared;expected=((expected<<1)^expected)&0xffffffff
            assert trace.dependencies(shared)==frozenset((0,))
            assert trace.concrete(shared)==expected
            cases.append(dict(instructions=report['instructions'],lookup_checks=report['symbolic_index_replay_checks'],
                              distinct_values=report['distinct_lookup_values'],word_domains_constrained=constrained,
                              shared_dag_checks=True,normalized_word_hooks=normalized,canonical_index_hooks=index_normalized,indexed_word_hooks=indexed_word,inline_domains=inline_domains,status='pass'))
    report=dict(status='pass',cases=cases,scope='invented lookup arrays and generated instruction program; partial registers, frame memory, rotations, carry and setcc; no target inputs')
    args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))


if __name__=='__main__':main()
