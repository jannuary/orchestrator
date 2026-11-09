"""Check three GUID record fold loops against pinned original instructions.

Invented record/state bytes only. Every native output length and every loop
iteration is checked, including exact suffix preservation. No image table data
or native device buffers are serialized.
"""
import argparse
import hashlib
import json
from pathlib import Path
import random
from scan_auth_substitutions import TARGETS
from verify_fill_dispatch import segment_read


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('checkout',type=Path);p.add_argument('--output',type=Path,required=True);args=p.parse_args()
    from unicorn import Uc,UC_ARCH_X86,UC_MODE_64
    from unicorn import x86_const as r
    name,digest=TARGETS['corefp'];image=(args.checkout/'rootfs/system/lib64'/name).read_bytes();assert hashlib.sha256(image).hexdigest()==digest
    mu=Uc(UC_ARCH_X86,UC_MODE_64);mu.mem_map(0x2fb000,4096)
    loops=[(0x2fb4b0,0x2fb502,0x1d0,0x6eb85935,0x150,64),(0x2fb550,0x2fb5b4,0x198,0x4737999b,0xb0,64),(0x2fb600,0x2fb65f,0x1a8,0xda5ce40,0x340,328)]
    for begin,end,*_ in loops:mu.mem_write(begin,segment_read(image,begin,end-begin))
    frame,record,size_pointer=0x90010800,0x90020000,0x90030000
    for address in (frame&~4095,record,size_pointer):mu.mem_map(address,4096)
    rng=random.Random(0x488122);iterations=0
    for length in range(80,201):
        expected=bytearray(rng.randrange(256) for _ in range(length));suffix=bytes(rng.randrange(256) for _ in range(200-length));mu.mem_write(record,bytes(x^0x47 for x in expected)+suffix);mu.mem_write(size_pointer,(length^0x30b1a88a).to_bytes(4,'little'))
        for begin,end,counter_offset,counter_base,state_offset,state_length in loops:
            material=bytes(rng.randrange(256) for _ in range(state_length));mu.mem_write(frame-state_offset,bytes(x^0x54 for x in material))
            for index,value in enumerate(material):
                mu.reg_write(r.UC_X86_REG_RBP,frame);mu.reg_write(r.UC_X86_REG_R13,size_pointer);mu.reg_write(r.UC_X86_REG_R11,(record-0xc18e2b1f7b8a47ec)&0xffffffffffffffff);mu.reg_write(r.UC_X86_REG_R9,1<<32);mu.reg_write(r.UC_X86_REG_R10,0x30b1a88a);mu.reg_write(r.UC_X86_REG_RCX,0xc18e2b1f03155189 if begin==0x2fb4b0 else 0x30b1a88a);mu.reg_write(r.UC_X86_REG_R8,frame-state_offset)
                mu.mem_write(frame-counter_offset,(counter_base+index).to_bytes(8,'little'));mu.emu_start(begin,end,count=128)
                expected[index%length]^=value;actual=bytes(mu.mem_read(record,200));assert actual==bytes(x^0x47 for x in expected)+suffix,(length,hex(begin),index);iterations+=1
    report=dict(status='pass',artifact_sha256=digest,native_lengths_checked=121,original_loops=3,original_iterations=iterations,loop_material_lengths=[64,64,328],every_iteration_and_suffix_compared=True,clear_formula='record[index % length] XOR= material[index]',network_requests=0,private_material_written=False,scope='three post-header fold loops only; state generation and whole first GUID/auth remain incomplete')
    args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))


if __name__=='__main__':main()
