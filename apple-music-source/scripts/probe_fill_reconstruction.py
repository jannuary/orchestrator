"""Replace live SPC fill control data in a temporary OFFLINE oracle build.

Uses only original source/build objects and invented rejected requests. No
retained harness, exchanges, provisioning, credentials, network, or ELF reads.
This is NOT package runtime or a full blob-free runtime: other banks remain.
"""
import argparse
import json
from pathlib import Path
import subprocess
import sys
import tempfile


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('source_checkout', type=Path)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    root = args.source_checkout.resolve()
    native = Path(__file__).resolve().parents[1] / 'src/apple_music_source/_native'
    source = root / 'crypto/keygen_experimental'
    build = root / 'build/spc-payload'
    text = (source / 'spc_generate.c').read_text()
    old = 'memcpy(r->owned[j],image->data,image->size);'
    assert text.count(old) == 1
    # Never copy the original 92 bytes, including transient initialization.
    new = '''if(image->address==UINT64_C(0x4c9e20)) {
        size_t start=(size_t)(UINT64_C(0x525a00)-image->address), k;
        if(image->size<start+92)goto done;
        memcpy(r->owned[j],image->data,start);
        memcpy(r->owned[j]+start+92,image->data+start+92,image->size-start-92);
        for(k=0;k<92;++k){uint64_t v=0;
#if AMS_RECONSTRUCT
            if(!ams_fill_dispatch_read(UINT64_C(0x525a00)+k,1,&v))goto done;
#endif
            r->owned[j][start+k]=(unsigned char)v;
        }
    } else memcpy(r->owned[j],image->data,image->size);'''
    program = r'''
import ctypes,json,random,sys
sys.path.insert(0,sys.argv[1]+'/tools/crypto/keygen_experimental')
from source_protocol import generate
rows=[]
for n in (1,32,128):
    rng=random.Random(0xA551+n)
    def entropy(_,p,n):
        for j in range(n):p[j]=rng.randrange(256)
        return 0
    ticks=[0]
    def clock(_):
        ticks[0]+=1
        return 0x1234567800000000+ticks[0]*100003
    def wall(_,seconds,micros):
        seconds[0]=1700000000;micros[0]=123456
        return 0
    s,o,r=generate(sys.argv[2],0,bytes(n),b'invented-fill-model',bytes(range(16)),
                   entropy=entropy,clock=clock,time=wall)
    rows.append(dict(certificate_size=n,api=s,output_size=len(o),status=r.status,
                     pc=r.pc,fault_address=r.fault_address,fault_size=r.fault_size,
                     source_steps=r.source_steps,clock_calls=r.clock_calls))
print(json.dumps(rows))
'''
    with tempfile.TemporaryDirectory(prefix='ams-fill-live-') as t:
        temporary = Path(t)
        patched = temporary / 'generate.c'
        patched.write_text(text.replace('#include "spc_generate.h"',
            '#include "spc_generate.h"\n#include "fill_dispatch.h"').replace(old, new))
        libraries = [build / 'libwrapper_spc_generate.so']
        for enabled in (1, 0):
            lib = temporary / ('model.so' if enabled else 'zero.so')
            subprocess.run(['cc', '-std=c99', '-O2', '-shared', '-fPIC',
                        '-DAMS_RECONSTRUCT=' + str(enabled),
                        '-I' + str(source), '-I' + str(native), str(patched),
                        str(source / 'ckc_packet.c'), str(native / 'fill_dispatch.c'),
                        '-L' + str(build), '-lwrapper_spc_native',
                        '-Wl,-rpath,' + str(build), '-o', str(lib)],
                           capture_output=True, text=True, check=True)
            libraries.append(lib)
        results = []
        for library in libraries:
            result = subprocess.run([sys.executable, '-S', '-c', program,
                                     str(root), str(library)], capture_output=True,
                                    text=True, check=True, timeout=50)
            results.append(json.loads(result.stdout))
        assert results[0] == results[1], 'synthetic source-runtime mismatch'
        assert all(a != b for a, b in zip(results[0], results[2])), 'zero-data negative control did not fail'
        report = {'status': 'pass', 'original_fill_bytes_copied': 0,
                  'reconstructed_bytes': 92, 'synthetic_cases': results[1],
                  'zero_model_negative_control': results[2],
                  'scope': 'rejected invented certificates only; remaining original image/integrity banks retained'}
        args.output.parent.mkdir(parents=True, exist_ok=True)
        args.output.write_text(json.dumps(report, indent=2) + '\n')
        print(json.dumps(report))


if __name__ == '__main__':
    main()
