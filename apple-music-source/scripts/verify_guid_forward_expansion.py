"""Validate reuse of the recovered ARX expansion on the Android-ID transform.

The two native paths use different wire XOR encodings. This checks actual
forward-copy/update instructions, with every invented-state update compared.
"""
import argparse
import hashlib
import json
from pathlib import Path
import sys

from scan_auth_substitutions import TARGETS
from verify_fill_dispatch import segment_read


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('checkout',type=Path);p.add_argument('--output',type=Path,required=True);args=p.parse_args()
    sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'src'))
    from apple_music_source.auth._guid_input_expansion import expand328
    from unicorn import Uc,UC_ARCH_X86,UC_MODE_64
    from unicorn import x86_const as r
    name,digest=TARGETS['corefp'];image=(args.checkout/'rootfs/system/lib64'/name).read_bytes();assert hashlib.sha256(image).hexdigest()==digest
    mu=Uc(UC_ARCH_X86,UC_MODE_64);mu.mem_map(0x2f8000,4096)
    for begin,end in ((0x2f8bc0,0x2f8bef),(0x2f8c30,0x2f8d61)):mu.mem_write(begin,segment_read(image,begin,end-begin))
    stack,source=0x90010000,0x90020000
    for address in (stack,source):mu.mem_map(address,4096)
    frame=stack+0x800;buffer=frame-0x340;inputs=[bytes(range(8)),bytes(range(16)),bytes(range(80)),b'0123456789abcdef'];copies=updates=0
    for value in inputs:
        mu.mem_write(source,value);mu.mem_write(frame-0x30,len(value).to_bytes(4,'little'));mu.reg_write(r.UC_X86_REG_RBP,frame);mu.reg_write(r.UC_X86_REG_R12,source)
        for i in range(328):
            mu.mem_write(frame-0x1c8,(0xe9cfa62+i).to_bytes(8,'little'));mu.emu_start(0x2f8bc0,0x2f8bef,count=64);copies+=1
        expected=bytearray(value[i%len(value)] for i in range(328));assert bytes(mu.mem_read(buffer,328))==bytes(x^0x54 for x in expected)
        def rol(x,n):return ((x<<n)|(x>>(8-n)))&255
        for i in range(1312):
            mu.mem_write(frame-0xfc,(0x4b983553+i).to_bytes(4,'little'));mu.emu_start(0x2f8c30,0x2f8d61,count=256);updates+=1
            at=i%328;expected[at]=((expected[at]^rol(expected[(i-13)%328],3))+rol(expected[(i-57)%328],5)-rol(expected[(i-155)%328],7))&255
            assert bytes(mu.mem_read(buffer,328))==bytes(x^0x54 for x in expected),(len(value),i)
        shared=bytes(x^0x47 for x in expand328(bytes(x^0x47 for x in value)))
        assert shared==bytes(expected)
    report=dict(status='pass',artifact_sha256=digest,original_copy_iterations=copies,original_mixer_iterations=updates,every_update_compared=True,recovered_expander_reused=True,clear_input_lengths=[len(x) for x in inputs],network_requests=0,private_material_written=False,scope='Android-ID transform initial ARX expansion only; subsequent transforms and complete first GUID/auth remain unresolved')
    args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))


if __name__=='__main__':main()
