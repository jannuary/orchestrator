"""Validate GUID record-size arithmetic using original instructions.

Only invented inputs and arithmetic states. No native/private buffer values
are written; optional answers contain public invented byte strings only.
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
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('checkout',type=Path);p.add_argument('--output',type=Path,required=True);p.add_argument('--known-answers',type=Path);args=p.parse_args()
    sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'src'))
    from apple_music_source.auth._guid_record_size import record_size
    from unicorn import Uc,UC_ARCH_X86,UC_MODE_64
    from unicorn import x86_const as r
    name,digest=TARGETS['corefp'];image=(args.checkout/'rootfs/system/lib64'/name).read_bytes();assert hashlib.sha256(image).hexdigest()==digest
    mu=Uc(UC_ARCH_X86,UC_MODE_64);mu.mem_map(0x2f8000,4096);mu.mem_write(0x2f86e0,segment_read(image,0x2f86e0,0x2f87b5-0x2f86e0));mu.mem_write(0x2f8b89,segment_read(image,0x2f8b89,0x2f8ba8-0x2f8b89))
    stack,buffer,length=0x90010000,0x90020000,0x90030000
    for a in (stack,buffer,length):mu.mem_map(a,4096)
    frame=stack+0x800;mu.reg_write(r.UC_X86_REG_RBP,frame);mu.reg_write(r.UC_X86_REG_R12,buffer);mu.reg_write(r.UC_X86_REG_R13,length)
    def reset(value,residue=5):
        mu.mem_write(buffer,value);mu.mem_write(frame-0x30,len(value).to_bytes(4,'little'));mu.mem_write(frame-0x6c,(len(value)+0x3f57c963).to_bytes(4,'little'));mu.mem_write(frame-0xf8,(residue+0x37b43d81).to_bytes(4,'little'));mu.mem_write(frame-0xf4,(0x705e351).to_bytes(4,'little'))
    rng=random.Random(0x480115)
    inputs=[b'0123456789abcdef',b'fedcba9876543210',b'0011223344556677',b'ffeeddccbbaa9988']
    inputs.extend(bytes(rng.randrange(256) for _ in range(n)) for n in (8,9,15,17,32,64,79,80))
    vectors=[];iterations=0
    for value in inputs:
        reset(value);residue=5;count=len(value)+355
        for i in range(count):
            mu.emu_start(0x2f86e0,0x2f87b5,count=128);iterations+=1;residue=(residue-value[i%len(value)])%121
            actual=int.from_bytes(mu.mem_read(frame-0xf8,4),'little')-0x37b43d81;assert actual==residue,(len(value),i)
            assert mu.reg_read(r.UC_X86_REG_RCX)&255==(0 if i<count-1 else 5)
        mu.emu_start(0x2f8b89,0x2f8ba8,count=32);size=int.from_bytes(mu.mem_read(length,4),'little')^0x30b1a88a
        assert size==record_size(value)
        vectors.append(dict(input=value.hex(),output_size=size))
    pairs=0
    for byte in range(256):
        for previous in range(121):
            reset(bytes([byte])*8,previous);mu.emu_start(0x2f86e0,0x2f87b5,count=128)
            actual=int.from_bytes(mu.mem_read(frame-0xf8,4),'little')-0x37b43d81;assert actual==(previous-byte)%121;pairs+=1
    report=dict(status='pass',artifact_sha256=digest,complete_invented_inputs=len(inputs),original_full_loop_iterations=iterations,exhaustive_byte_residue_pairs=pairs,original_stop_condition_checked_each_iteration=True,network_requests=0,private_material_written=False,scope='record length derivation only; record contents, first GUID and authentication remain incomplete')
    if args.known_answers:args.known_answers.write_text(json.dumps(dict(scope='Public invented inputs and original-instruction sizes',cases=vectors),indent=2)+'\n')
    args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))


if __name__=='__main__':main()
