"""Validate the variable-length GUID record mixer against pinned instructions.

Only public invented state is used. Optional known answers are invented-state
outputs, never native device buffers, private material or image table bytes.
"""
import argparse
import hashlib
import json
from pathlib import Path
import random
import sys

from scan_auth_substitutions import TARGETS
from verify_fill_dispatch import segment_read


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('checkout',type=Path);parser.add_argument('--output',type=Path,required=True);parser.add_argument('--known-answers',type=Path)
    args=parser.parse_args()
    sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'src'))
    from apple_music_source.auth._guid_record_mixer import mix_record
    from unicorn import Uc,UC_ARCH_X86,UC_MODE_64,UC_HOOK_MEM_READ
    from unicorn import x86_const as r
    name,digest=TARGETS['corefp'];image=(args.checkout/'rootfs/system/lib64'/name).read_bytes();assert hashlib.sha256(image).hexdigest()==digest
    begin,end=0x2fb6b0,0x2fb879
    mu=Uc(UC_ARCH_X86,UC_MODE_64);mu.mem_map(begin&~4095,4096);mu.mem_write(begin,segment_read(image,begin,end-begin))
    stack,buffer,length_pointer=0x90010000,0x90020000,0x90030000
    for address in (stack,buffer,length_pointer):mu.mem_map(address,4096)
    frame=stack+0x800;mu.mem_write(frame-0xd8,buffer.to_bytes(8,'little'));mu.mem_write(frame-0x190,length_pointer.to_bytes(8,'little'));rng=random.Random(0x248093)
    inputs=[bytes((i*43+size)%256 for i in range(size)) for size in (1,6,7,16,20,37,64,112,147,177,256)]
    inputs.extend(bytes(rng.randrange(256) for _ in range(size)) for size in (112,147))
    reads=[]
    def read_hook(uc,access,address,size,value,user):
        if buffer<=address<buffer+4096:reads.append((hex(uc.reg_read(r.UC_X86_REG_RIP)),address-buffer,size))
    mu.hook_add(UC_HOOK_MEM_READ,read_hook)
    vectors=[]
    for value in inputs:
        length=len(value);mu.mem_write(buffer,bytes(x^0x47 for x in value));mu.mem_write(length_pointer,(length^0x30b1a88a).to_bytes(4,'little'))
        expected=bytearray(value)
        for i in range(256):
            mu.reg_write(r.UC_X86_REG_RBP,frame);mu.reg_write(r.UC_X86_REG_R13,length_pointer);mu.reg_write(r.UC_X86_REG_R11,(buffer-0xc18e2b1f7b8a47ec)&0xffffffffffffffff);mu.reg_write(r.UC_X86_REG_R9,1<<32)
            mu.mem_write(frame-0x104,(0x70a1dabc+i).to_bytes(4,'little'));mu.emu_start(begin,end,count=256)
            def rol(x,n):return ((x<<n)|(x>>(8-n)))&255
            at=i%length;expected[at]^=rol(expected[(at-7)%length],1)^rol(expected[(at-37)%length],6)^rol(expected[(at-177)%length],5)
            actual=bytes(x^0x47 for x in mu.mem_read(buffer,length));assert actual==expected,(length,i,reads[-4:])
        assert mix_record(value)==actual
        if length in (1,7,20,112,147):vectors.append(dict(input=value.hex(),output=actual.hex()))
    report=dict(status='pass',artifact_sha256=digest,original_interval=[hex(begin),hex(end)],invented_complete_states=len(inputs),original_iterations=256*len(inputs),lengths=sorted({len(x) for x in inputs}),every_iteration_compared=True,network_requests=0,private_material_written=False,scope='variable-length 256-update record mixer only; no caller initialization, whole first GUID or authentication claim')
    if args.known_answers:args.known_answers.write_text(json.dumps(dict(scope='Public invented-state outputs of pinned original instructions',cases=vectors),indent=2)+'\n')
    args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))


if __name__=='__main__':main()
