"""Exhaust original copy-byte arithmetic with invented byte/index/control inputs.

Only code is read from the pinned development ELF. No session, table, encoding
matrix, account field or cryptographic output enters the report or package.
These checks prove the output-byte expressions, not whole cipher equivalence.
"""
import argparse
import ctypes as C
import hashlib
import json
from pathlib import Path
import subprocess
import sys
import tempfile

from verify_integrity_codec import HASH
from verify_fill_dispatch import segment_read


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('checkout',type=Path);p.add_argument('--output',type=Path,required=True)
    args=p.parse_args();root=args.checkout.resolve();raw=(root/'rootfs/system/lib64/libCoreLSKD.so').read_bytes()
    assert hashlib.sha256(raw).hexdigest()==HASH
    from unicorn import Uc,UC_ARCH_X86,UC_MODE_64
    from unicorn import x86_const as r
    native=Path(__file__).resolve().parents[1]/'src/apple_music_source/_native'
    checks=[0,0];high_index_checks=0
    with tempfile.TemporaryDirectory(prefix='ams-copy-codecs-') as temp:
        library=Path(temp)/'copy.so'
        subprocess.run(['cc','-std=c99','-O2','-Wall','-Wextra','-Werror','-shared','-fPIC',str(native/'copy_codecs.c'),'-o',str(library)],check=True)
        lib=C.CDLL(str(library))
        for which,(begin,end) in enumerate(((0x527a59,0x527aad),(0x53172e,0x531759))):
            function=getattr(lib,'ams_copy'+str(which)+'_byte');function.argtypes=[C.c_uint32,C.c_uint8,C.c_uint8];function.restype=C.c_uint8
            mu=Uc(UC_ARCH_X86,UC_MODE_64);mu.mem_map(begin&~4095,8192);mu.mem_write(begin,segment_read(raw,begin,end-begin))
            frame=0x2001000;source=0x3000000;destination=0x3001000
            mu.mem_map(0x2000000,8192);mu.mem_map(source,8192);mu.reg_write(r.UC_X86_REG_RBP,frame)
            def original(index,state,byte):
                # Rebase the pointers so even high unsigned indices address a
                # deliberately mapped single invented byte. No private input.
                base_in=(source-index)%(1<<64);base_out=(destination-index)%(1<<64)
                if which==0:
                    mu.reg_write(r.UC_X86_REG_R13,index);mu.reg_write(r.UC_X86_REG_RBX,state)
                    mu.mem_write(frame-0xc8,base_in.to_bytes(8,'little'));mu.mem_write(frame-0x160,base_out.to_bytes(8,'little'))
                else:
                    mu.reg_write(r.UC_X86_REG_R9,index);mu.reg_write(r.UC_X86_REG_R13,state)
                    mu.mem_write(frame-0xe0,base_in.to_bytes(8,'little'));mu.mem_write(frame-0x1d8,base_out.to_bytes(8,'little'))
                mu.mem_write(source,bytes([byte]));mu.mem_write(destination,b'\xa5');mu.reg_write(r.UC_X86_REG_EFLAGS,0x202)
                mu.emu_start(begin,end,count=100)
                assert mu.reg_read(r.UC_X86_REG_RIP)==end
                return mu.mem_read(destination,1)[0]
            for index in range(256):
                states=(0,4,8,12) if which==0 else ((2*index)&255,)
                for state in states:
                    for byte in range(256):
                        assert function(index,state,byte)==original(index,state,byte),(which,index,state,byte)
                        checks[which]+=1
            if which==1:
                for index in (0,1,7,8,15,16,127,128,255):
                    for state in range(0,256,16):
                        for byte in range(256):
                            assert function(index,state,byte)==original(index,state,byte),(which,index,state,byte)
                            checks[which]+=1
            for index in (256,511,65535,0x7fffffff,0x80000000,0xfffffffe,0xffffffff):
                for state in (0,4,12,16,128,255):
                    for byte in (0,1,7,15,63,127,128,254,255):
                        assert function(index,state,byte)==original(index,state,byte),(which,index,state,byte)
                        high_index_checks+=1
    report=dict(status='pass',stage0_original_byte_comparisons=checks[0],stage1_original_byte_comparisons=checks[1],
                high_index_comparisons=high_index_checks,
                scope='source-derived copy-stage output arithmetic only; no complete buffer-state, packet, cipher, SPC or auth proof')
    args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))


if __name__=='__main__':main()
