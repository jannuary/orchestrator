"""Compare source-owned GUID stages with pinned original instructions.

Only invented input states/bytes are used. Optional KAT output contains public
invented messages, not keys, identifiers, image data or captured exchanges.
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
 from apple_music_source.auth._guid_field_stages import mix20,unmix20,encode_bytes
 from unicorn import Uc,UC_ARCH_X86,UC_MODE_64
 from unicorn import x86_const as r
 filename,digest=TARGETS['corefp'];image=(args.checkout/'rootfs/system/lib64'/filename).read_bytes();assert hashlib.sha256(image).hexdigest()==digest
 mu=Uc(UC_ARCH_X86,UC_MODE_64);mu.mem_map(0x2f8000,4096);mu.mem_write(0x2f8510,segment_read(image,0x2f8510,0x2f8593-0x2f8510))
 mu.mem_map(0x5e2000,4096);mu.mem_write(0x5e2156,segment_read(image,0x5e2156,0x5e215c-0x5e2156))
 stack,buffer,length=0x90010000,0x90020000,0x90030000
 for pointer in (stack,buffer,length):mu.mem_map(pointer,4096)
 frame=stack+0x800;mu.mem_write(length,(20^0x3005ed45).to_bytes(4,'little'));rng=random.Random(0x731995)
 inputs=[bytes(20),bytes(range(20)),bytes([255])*20,bytes(rng.randrange(256) for _ in range(20))];vectors=[];iterations=0
 for data in inputs:
  mu.mem_write(buffer,data)
  for index in range(256):
   mu.reg_write(r.UC_X86_REG_RBP,frame);mu.reg_write(r.UC_X86_REG_R12,length);mu.reg_write(r.UC_X86_REG_R13,buffer)
   mu.mem_write(frame-0x70,(0x4b4ae83+index).to_bytes(4,'little'));mu.emu_start(0x2f8510,0x2f8593,count=128);iterations+=1
   at=index%20;assert all(((20+index-offset)&0xffffffff)%20!=at for offset in (7,37,177))
  actual=bytes(mu.mem_read(buffer,20));assert mix20(data)==actual and unmix20(actual)==data
  vectors.append(dict(input=data.hex(),output=actual.hex()))
 byte_checks=0
 for value in range(256):
  mu.reg_write(r.UC_X86_REG_RCX,value);mu.emu_start(0x5e2156,0x5e215c,count=4)
  assert mu.reg_read(r.UC_X86_REG_RCX)&255==encode_bytes(bytes([value]))[0];byte_checks+=1
 report=dict(status='pass',artifact_sha256=digest,complete_mixer_states=len(inputs),original_mixer_iterations=iterations,original_byte_checks=byte_checks,tap_alias_exclusion_checks=256*3,network_requests=0,private_bytes_written=False,scope='exact original straight-line mixer body iterated 256 times with valid invented state and length, plus all byte-transform values; not initialization, whole GUID or authentication')
 if args.known_answers:
  args.known_answers.parent.mkdir(parents=True,exist_ok=True);args.known_answers.write_text(json.dumps(dict(scope='Public invented-state known answers from pinned original mixer instructions',artifact_sha256=digest,cases=vectors),indent=2)+'\n')
 args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))


if __name__=='__main__':main()
