"""Verify repeated-input and four-pass GUID expansion against original code.

Only invented byte strings are supplied. The arithmetic body and final store
are executed as separate original spans; skipped branch scheduling changes
neither the store byte nor its address. No caller-validation/auth claim.
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
 parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('checkout',type=Path);parser.add_argument('--output',type=Path,required=True);parser.add_argument('--known-answers',type=Path);args=parser.parse_args();sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'src'))
 from apple_music_source.auth._guid_input_expansion import expand328
 from unicorn import Uc,UC_ARCH_X86,UC_MODE_64
 from unicorn import x86_const as r
 filename,digest=TARGETS['corefp'];image=(args.checkout/'rootfs/system/lib64'/filename).read_bytes();assert hashlib.sha256(image).hexdigest()==digest
 mu=Uc(UC_ARCH_X86,UC_MODE_64);mu.mem_map(0x2f6000,4096)
 for begin,end in ((0x2f65b0,0x2f6608),(0x2f6650,0x2f6753),(0x2f6780,0x2f6788)):mu.mem_write(begin,segment_read(image,begin,end-begin))
 stack,input_pointer=0x90010000,0x90020000;mu.mem_map(stack,4096);mu.mem_map(input_pointer,4096);frame=stack+0x800;buffer=frame-0x340
 rng=random.Random(0x785232);inputs=[bytes([0]),bytes(range(6)),bytes(range(16)),bytes(rng.randrange(256) for _ in range(140))];vectors=[];copy_checks=mix_checks=0
 for data in inputs:
  mu.mem_write(input_pointer,data);mu.mem_write(frame-0xb8,len(data).to_bytes(4,'little'));mu.mem_write(frame-0xd8,input_pointer.to_bytes(8,'little'))
  for index in range(328):
   mu.reg_write(r.UC_X86_REG_RBP,frame);mu.reg_write(r.UC_X86_REG_R8,buffer);mu.reg_write(r.UC_X86_REG_RCX,1<<32);mu.mem_write(frame-0x1c8,(0xb8d3569+index).to_bytes(8,'little'))
   mu.emu_start(0x2f65b0,0x2f6608,count=128);copy_checks+=1
  assert bytes(mu.mem_read(buffer,328))==bytes(data[i%len(data)] for i in range(328))
  for index in range(4*328):
   mu.reg_write(r.UC_X86_REG_RBP,frame);mu.mem_write(frame-0x30,(0x94d20e7+index).to_bytes(4,'little'))
   mu.emu_start(0x2f6650,0x2f6753,count=256)
   assert mu.reg_read(r.UC_X86_REG_R8)==index%328
   mu.emu_start(0x2f6780,0x2f6788,count=1);mix_checks+=1
  actual=bytes(mu.mem_read(buffer,328));assert expand328(data)==actual
  vectors.append(dict(input=data.hex(),output=actual.hex()))
 report=dict(status='pass',artifact_sha256=digest,input_cases=len(inputs),original_input_copy_iterations=copy_checks,original_mixer_iterations=mix_checks,network_requests=0,private_bytes_written=False,scope='bounded repeated-input copy and four-pass byte arithmetic/store against original instructions; native branch scheduling and caller validation are not reconstructed')
 if args.known_answers:
  args.known_answers.parent.mkdir(parents=True,exist_ok=True);args.known_answers.write_text(json.dumps(dict(scope='Public invented-input original-instruction known answers; no key, image or lookup bytes',artifact_sha256=digest,cases=vectors),indent=2)+'\n')
 args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))


if __name__=='__main__':main()
