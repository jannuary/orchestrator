"""Invented controls for constant-base discovery and source word decoders."""
import argparse
import ctypes as C
import json
from pathlib import Path
import random
import struct
import subprocess
import tempfile

from analyze_guid_word_tables import OFFSET_SEARCH
from inventory_guid_word_tables import constant_before
from recover_guid_word_consumers import candidates,verify_original


ASSEMBLY='''
.intel_syntax noprefix
.text
lea rcx,[rip+64]
mov r12,rcx
mov eax,DWORD PTR [r12+rdx*4]
xor eax,37
movzx edx,al
rol eax,5
add eax,17
mov r8d,eax
xor r8d,edi
ret
'''


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output',type=Path,required=True)
    args=parser.parse_args()
    rng=random.Random(0x431527)
    with tempfile.TemporaryDirectory(prefix='ams-auth-word-controls-') as temporary:
        directory=Path(temporary);assembly=directory/'test.s';object_=directory/'test.o';binary=directory/'test.bin'
        assembly.write_text(ASSEMBLY)
        subprocess.run(['cc','-c',str(assembly),'-o',str(object_)],check=True,capture_output=True)
        subprocess.run(['objcopy','-O','binary','--only-section=.text',str(object_),str(binary)],check=True,capture_output=True)
        from capstone import Cs,CS_ARCH_X86,CS_MODE_64
        decoder=Cs(CS_ARCH_X86,CS_MODE_64);decoder.detail=True
        code=binary.read_bytes();base=0x1000000;instructions=list(decoder.disasm(code,base))
        assert constant_before(instructions,2,'r12')==base+instructions[0].size+64
        # A missing instruction must not be crossed as if definitions were
        # adjacent. A partial register write must not preserve a full pointer.
        assert constant_before([instructions[0],instructions[2]],1,'r12') is None
        partial=list(decoder.disasm(bytes.fromhex('488d0d4000000088d18b0491'),base))
        assert constant_before(partial,2,'rcx') is None
        image=bytearray(0x2000);image[:6]=b'\x7fELF\x02\x01'
        struct.pack_into('<Q',image,32,64);struct.pack_into('<HH',image,54,56,1)
        struct.pack_into('<IIQQQQQQ',image,64,1,5,0x1000,base,0,len(code)+16,4096,4096)
        image[0x1000:0x1000+len(code)+16]=code+bytes([0x90])*16;image=bytes(image)
        discovered=list(candidates(image,instructions[2].address));assert discovered
        bijective=lossy=0;comparisons=0
        for candidate in discovered:
            z=candidate['z'];word=candidate['word'];expression=candidate['expression'];other=z.BitVec('other_word',32)
            solver=z.Solver();solver.add(word!=other,expression==z.substitute(expression,(word,other)))
            verdict=solver.check()
            if verdict==z.unsat:
                bijective+=1;comparisons+=verify_original(image,list(range(256)),candidate)
            else:
                assert verdict==z.sat
                values=[z.simplify(z.substitute(expression,(word,z.BitVecVal(value,32)))).as_long() for value in range(256)]
                assert len(set(values))==256
                lossy+=1
        assert bijective>=3 and lossy>=1
        end_mix=instructions[-2].address+instructions[-2].size
        assert not any(candidate['end']==end_mix and candidate['output_register']=='r8' for candidate in discovered)
        cfile,library=directory/'offsets.c',directory/'offsets.so';cfile.write_text(OFFSET_SEARCH)
        subprocess.run(['cc','-std=c99','-O2','-shared','-fPIC',str(cfile),'-o',str(library)],check=True,capture_output=True)
        find=C.CDLL(str(library)).additive_offsets
        find.argtypes=[C.POINTER(C.c_uint32),C.POINTER(C.c_uint32),C.c_size_t,C.POINTER(C.c_uint32),C.c_size_t];find.restype=C.c_size_t
        from analyze_table_algebra import apply,independent
        columns=[]
        while len(columns)<8:
            trial=rng.getrandbits(32)
            if len(independent(columns+[trial]))>len(columns):columns.append(trial)
        offset=rng.getrandbits(32)
        words=(C.c_uint32*256)(*((apply(columns,x)-offset)&0xffffffff for x in range(256)))
        offsets=(C.c_uint32*3)(offset,offset^0x80000000,0);indices=(C.c_uint32*3)()
        count=find(words,offsets,3,indices,3)
        assert {0,1}<=set(indices[:count])
        wrong=(C.c_uint32*256)(*(rng.getrandbits(32) for _ in range(256)))
        assert find(wrong,offsets,3,indices,3)==0
    report=dict(status='pass',constant_base_alias_recovered=True,cross_gap_definition_rejected=True,
        partial_register_clobber_rejected=True,bijective_word_prefixes=bijective,
        lossy_prefixes_rejected_despite_256_distinct_samples=lossy,
        foreign_register_mix_excluded=True,original_instruction_comparisons=comparisons,
        additive_offset_positive_and_negative_controls=True,
        scope='invented instruction program, word arrays and offsets only; no target bytes or parameters emitted')
    args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))


if __name__=='__main__':main()
