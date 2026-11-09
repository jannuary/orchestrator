"""Verify MAC-word serialization algebra against original byte-store code.

Invented 32-bit words only; no device data, runtime captures or keys are saved.
This is a store/encoding check, not the generation of the two MAC field words.
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
 parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('checkout',type=Path);parser.add_argument('--output',type=Path,required=True);args=parser.parse_args();sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'src'))
 from apple_music_source.auth._guid_field_stages import encode_bytes
 from unicorn import Uc,UC_ARCH_X86,UC_MODE_64
 from unicorn import x86_const as r
 name,digest=TARGETS['corefp'];image=(args.checkout/'rootfs/system/lib64'/name).read_bytes();assert hashlib.sha256(image).hexdigest()==digest
 begin,end=0x60f290,0x60f312;mu=Uc(UC_ARCH_X86,UC_MODE_64);mu.mem_map(begin&~4095,4096);mu.mem_write(begin,segment_read(image,begin,end-begin));buffer=0x90000000;mu.mem_map(buffer,4096)
 rng=random.Random(0x983311);words=[0,1,0x7fffffff,0x80000000,0xffffffff,0x01020304]+[rng.getrandbits(32) for _ in range(512)]
 for word in words:
  mu.reg_write(r.UC_X86_REG_RAX,buffer);mu.reg_write(r.UC_X86_REG_R14,0x7625998a);mu.reg_write(r.UC_X86_REG_RDX,word^0x2f54a7fb)
  mu.emu_start(begin,end,count=128);actual=bytes(mu.mem_read(buffer,4));assert encode_bytes(actual)==(word^0x77143e48).to_bytes(4,'big')
 assert all(((167*((23*value+98)&255)+18)&255)==value for value in range(256))
 report=dict(status='pass',artifact_sha256=digest,source_interval=['0x60f290','0x60f312'],original_word_cases=len(words),exhaustive_byte_codec_inverse_checks=256,network_requests=0,private_bytes_written=False,scope='original word-store bytes followed by the verified field encoder equal big-endian cell XOR 0x77143e48; caller addresses/bounds and word generation remain unresolved')
 args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))


if __name__=='__main__':main()
