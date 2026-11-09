"""Replace 160 codec SIMD bytes and preserve the prior 92-byte fill model.

Uses only original source/build objects and invented rejected requests. No
retained harness, exchanges, provisioning, credentials, network, or ELF reads.
This is NOT package runtime or a full blob-free runtime: other banks remain.
"""
import argparse
import json
import os
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
if(!ams_fill_dispatch_read(UINT64_C(0x525a00)+k,1,&v))goto done;
            r->owned[j][start+k]=(unsigned char)v;
        }
    } else if(image->address==UINT64_C(0x10000000)) {
        const uint64_t bases[]={0x580,0xe20,0xe30,0x1170,0x25b0,0x25c0,0x35d0,0x4690,0x4c40,0x4f40};
        size_t end=0,k;
        for(k=0;k<sizeof bases/sizeof bases[0];++k){size_t at=(size_t)bases[k],v;
            if(at<end||at+16>image->size)goto done;
            memcpy(r->owned[j]+end,image->data+end,at-end);
            for(v=0;v<16;++v){uint64_t word=0;
#if AMS_RECONSTRUCT
                if(!ams_integrity_codec_data_read(at+v,1,&word))goto done;
#endif
                r->owned[j][at+v]=(unsigned char)word;
            }
            end=at+16;
        }
        memcpy(r->owned[j]+end,image->data+end,image->size-end);
    } else memcpy(r->owned[j],image->data,image->size);'''
    program = r'''
import ctypes,hashlib,json,random,struct,sys
sys.path.insert(0,sys.argv[1]+'/tools/crypto/keygen_experimental')
from source_protocol import generate
class Region(ctypes.Structure):
    _fields_=[('address',ctypes.c_uint64),('size',ctypes.c_size_t),('data',ctypes.c_void_p),('permissions',ctypes.c_uint)]
Callback=ctypes.CFUNCTYPE(None,ctypes.c_void_p,ctypes.c_size_t,ctypes.POINTER(Region),ctypes.c_size_t)
observations=[]
def observe(state,size,regions,count):
    digest=hashlib.sha256(ctypes.string_at(state,size))
    for i in range(count):
        region=regions[i]
        digest.update(struct.pack('<QQI',region.address,region.size,region.permissions))
        digest.update(ctypes.string_at(region.data,region.size))
    observations.append(digest.hexdigest())
callback=Callback(observe)
library=ctypes.CDLL(sys.argv[2]);library.ams_audit_set.argtypes=[Callback];library.ams_audit_set(callback)
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
                     source_steps=r.source_steps,clock_calls=r.clock_calls,
                     terminal_full_state_sha256=observations[-1]))
print(json.dumps(rows))
'''
    with tempfile.TemporaryDirectory(prefix='ams-codec-live-') as t:
        temporary = Path(t)
        patched = temporary / 'generate.c'
        audit = r"""
static void (*ams_audit_callback)(const void *,size_t,const wrapper_kg_payload_region *,size_t);
void ams_audit_set(void (*f)(const void *,size_t,const wrapper_kg_payload_region *,size_t)){ams_audit_callback=f;}
"""
        libraries=[]
        for mode in ('baseline','model','zero'):
            body=text if mode=='baseline' else text.replace(old,new)
            body=body.replace('static int kg_generate(',audit+'\nstatic int kg_generate(',1)
            body=body.replace('done:\n    result->pc=', 'done:\n    if(ams_audit_callback)ams_audit_callback(&r->state,sizeof r->state,r->regions,KG_REGIONS);\n    result->pc=',1)
            body=body.replace('#include "spc_generate.h"', '#include "spc_generate.h"\n#include "fill_dispatch.h"\n#include "integrity_codec_data.h"')
            patched.write_text(body)
            lib=temporary/(mode+'.so')
            subprocess.run(['cc','-std=c99','-O2','-shared','-fPIC',
                            '-DAMS_RECONSTRUCT='+str(int(mode!='zero')),
                            '-I'+str(source),'-I'+str(native),str(patched),
                            str(source/'ckc_packet.c'),str(native/'fill_dispatch.c'),
                            str(native/'integrity_codec_data.c'),'-L'+str(build),
                            '-lwrapper_spc_native','-Wl,-rpath,'+str(build),'-o',str(lib)],
                           capture_output=True,text=True,check=True)
            libraries.append(lib)
        trace_source=r'''
#define _GNU_SOURCE
#include "spc_payload.h"
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
static unsigned long hits;
int wrapper_kg_native_read(const wrapper_kg_payload_region *r,size_t n,uint64_t at,unsigned w,uint64_t *out){
 static int(*f)(const wrapper_kg_payload_region*,size_t,uint64_t,unsigned,uint64_t*);
 static const uint64_t bases[]={0x580,0xe20,0xe30,0x1170,0x25b0,0x25c0,0x35d0,0x4690,0x4c40,0x4f40};
 if(!f){void *h=dlopen(getenv("AMS_NATIVE"),RTLD_NOW|RTLD_NOLOAD);if(!h)abort();*(void**)&f=dlsym(h,"wrapper_kg_native_read");if(!f)abort();}
 for(unsigned j=0;j<10;++j)if(at>=0x10000000+bases[j]&&at<0x10000000+bases[j]+16){++hits;break;}
 return f(r,n,at,w,out);
}
__attribute__((destructor))static void done(void){fprintf(stderr,"CODEC_READS %lu\n",hits);}
'''
        (temporary/'reads.c').write_text(trace_source)
        subprocess.run(['cc','-shared','-fPIC','-O2','-I'+str(source),str(temporary/'reads.c'),'-ldl','-o',str(temporary/'reads.so')],check=True)
        environment=dict(os.environ,LD_PRELOAD=str(temporary/'reads.so'),AMS_NATIVE=str(build/'libwrapper_spc_native.so'))
        read_counts=[]
        results = []
        for library in libraries:
            result = subprocess.run([sys.executable, '-S', '-c', program,
                                     str(root), str(library)], capture_output=True,
                                    text=True, check=True, timeout=50,env=environment)
            results.append(json.loads(result.stdout))
            read_counts.append(int(next(line[12:] for line in result.stderr.splitlines() if line.startswith("CODEC_READS "))))
        assert read_counts[0]==read_counts[1] and read_counts[0]>0
        assert results[0] == results[1], 'synthetic source-runtime mismatch'
        assert all(a != b for a, b in zip(results[0], results[2])), 'zero-data negative control did not fail'
        report = {'status': 'pass', 'live_codec_read_counts': read_counts, 'original_fill_bytes_copied': 0,
                  'reconstructed_bytes': 252, 'original_codec_bytes_copied': 0, 'codec_bytes': 160, 'synthetic_cases': results[1],
                  'zero_codec_negative_control': results[2],
                  'negative_control_comparison': 'terminal full native state and all mapped regions hashed; same API rejection is insufficient',
                  'scope': 'rejected invented certificates only; remaining original image/integrity banks retained'}
        args.output.parent.mkdir(parents=True, exist_ok=True)
        args.output.write_text(json.dumps(report, indent=2) + '\n')
        print(json.dumps(report))


if __name__ == '__main__':
    main()
