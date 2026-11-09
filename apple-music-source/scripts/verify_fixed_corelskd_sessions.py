"""Verify fixed CoreLSKD parameters against fresh source sessions, no fitting.

Only the public certificate fixture field is read. All source session material,
SPCs, buffers and entropy state remain RAM-only. The source VM is a developer
oracle, never an installed package dependency. No network request is made.
"""
import argparse
import ctypes as C
import json
from pathlib import Path
import random
import subprocess
import sys
import tempfile

from probe_substitution_calls import HELPER,certificate_only


def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('checkout',type=Path)
    parser.add_argument('--public-certificate-fixture',type=Path,required=True)
    parser.add_argument('--output',type=Path,required=True);args=parser.parse_args();root=args.checkout.resolve()
    sys.path.insert(0,str(root/'tools/crypto/keygen_experimental'));sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'src'))
    from source_protocol import SourceSession,Result
    from apple_music_source.crypto._corelskd_ciphers import encrypt,decrypt
    source=root/'crypto/keygen_experimental';build=root/'build/spc-payload';certificate=certificate_only(args.public_certificate_fixture)
    rows=[];rng=random.Random(0x917243)
    with tempfile.TemporaryDirectory(prefix='ams-fixed-core-sessions-') as directory:
        directory=Path(directory);cfile=directory/'probe.c';library=directory/'probe.so'
        cfile.write_text((source/'spc_generate.c').read_text()+HELPER)
        subprocess.run(['cc','-std=c99','-O2','-shared','-fPIC','-I'+str(source),str(cfile),str(source/'ckc_packet.c'),
                        '-L'+str(build),'-lwrapper_spc_native','-Wl,-rpath,'+str(build),'-o',str(library)],check=True,capture_output=True)
        lib=C.CDLL(str(library));probe=lib.ams_kernel_probe
        probe.argtypes=[C.c_void_p,C.c_uint,C.c_uint,C.POINTER(Result),C.POINTER(C.c_uint64),C.POINTER(C.c_uint64),C.POINTER(C.c_ubyte),C.c_void_p,C.c_uint,C.c_uint];probe.restype=C.c_int
        for profile in range(3):
            entropy_rng=random.Random(0x81732+profile*100003);ticks=[0]
            def entropy(_,destination,count):
                for index in range(count):destination[index]=entropy_rng.randrange(256)
                return 0
            def clock(_):
                ticks[0]+=1;return 0x2234567800000000+profile*0x100000000000000+ticks[0]*100003
            def wall(_,seconds,micros):seconds[0]=1700000000+profile*1000000;micros[0]=654321-profile*100003;return 0
            with SourceSession(library,0,certificate,b'fixed-cipher-fresh-profile-'+str(profile).encode(),
                               bytes((profile*31+index)&255 for index in range(16)),entropy=entropy,clock=clock,time=wall) as session:
                checks=[]
                for variant in range(2):
                    for size in (16,32,48,64):
                        data=bytes(rng.randrange(256) for _ in range(size+16));buffer=C.create_string_buffer(data)
                        result=Result();changed=(C.c_uint64*3)();returned=C.c_uint64();output=(C.c_ubyte*192)()
                        code=probe(session.handle,variant,size,C.byref(result),changed,C.byref(returned),output,buffer,len(data),3)
                        destination=2 if variant else 1;actual=bytes(output)[destination*64:destination*64+size]
                        checks.append(dict(variant=variant,bytes=size,source_returned=code==1,
                            fixed_encrypt_equal=encrypt(variant,data[16:],data[:16])==actual,
                            fixed_decrypt_equal=decrypt(variant,actual,data[:16])==data[16:]))
                rows.append(dict(profile=profile,changed_entropy_clock_wall_content_and_device_seed=True,
                                 parameter_refitting=False,cases=checks))
    passed=all(case['source_returned'] and case['fixed_encrypt_equal'] and case['fixed_decrypt_equal'] for row in rows for case in row['cases'])
    report=dict(status='pass' if passed else 'fail',profiles=rows,fresh_sessions=3,messages=24,
                network_requests=0,account_session_content_secrets_written=False,
                scope='fixed package byte transforms against fresh source runtimes with differing synthetic session inputs; no parameter fitting, account state, live license or full SPC/CKC/auth claim')
    args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(dict(status=report['status'],fresh_sessions=3,messages=24)))
    if not passed:raise SystemExit(1)


if __name__=='__main__':main()
