"""Check fixed AES kernels in pristine runtimes without SPC/session setup.

Developer source objects provide the oracle. No certificate, account, session,
device configuration, original capture or network is used. No key is fitted.
"""
import argparse
import ctypes as C
import json
from pathlib import Path
import random
import subprocess
import sys
import tempfile

from probe_substitution_calls import HELPER


PRISTINE=r'''
kg_runtime *ams_pristine_new(const wrapper_kg_spc_request*request,wrapper_kg_spc_result*result){
 kg_runtime*r=calloc(1,sizeof *r);size_t j;if(!r)return NULL;
 r->request_copy=*request;r->request=&r->request_copy;r->result=result;r->allocated=0x10000;r->state.cpu.flags=2;
 for(j=0;j<KG_IMAGES;++j){const struct kg_image*image=kg_images+j;
  r->owned[j]=malloc(image->size);if(!r->owned[j])goto fail;
  memcpy(r->owned[j],image->data,image->size);
  r->regions[j]=(wrapper_kg_payload_region){image->address,image->size,r->owned[j],image->permissions};}
 for(j=KG_IMAGES;j<KG_REGIONS;++j){r->owned[j]=calloc(1,KG_ARENA);if(!r->owned[j])goto fail;
  r->regions[j]=(wrapper_kg_payload_region){j==KG_IMAGES?KG_STACK:KG_HEAP,KG_ARENA,r->owned[j],3};}
 for(j=0;j<sizeof kg_source_service_names/sizeof kg_source_service_names[0];++j){
  if(!strcmp(kg_source_service_names[j],"malloc"))r->bindings.malloc_entry=UINT64_C(0x800000)+j*16;
  if(!strcmp(kg_source_service_names[j],"free"))r->bindings.free_entry=UINT64_C(0x800000)+j*16;}
 return r;
fail:wrapper_kg_spc_session_free(r);return NULL;
}
'''


def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('checkout',type=Path);parser.add_argument('--output',type=Path,required=True)
    parser.add_argument('--emit-known-answers',type=Path,help='Write four public invented-message KATs, never runtime images or secrets')
    args=parser.parse_args();root=args.checkout.resolve();sys.path.insert(0,str(root/'tools/crypto/keygen_experimental'))
    sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'src'))
    from source_protocol import Request,Result,Entropy,Clock,Time
    from apple_music_source.crypto._corelskd_ciphers import encrypt,decrypt
    source=root/'crypto/keygen_experimental';build=root/'build/spc-payload';rows=[];known=[];data_rng=random.Random(0x817349)
    with tempfile.TemporaryDirectory(prefix='ams-pristine-fixed-core-') as directory:
        directory=Path(directory);cfile=directory/'probe.c';library=directory/'probe.so'
        cfile.write_text((source/'spc_generate.c').read_text()+HELPER+PRISTINE)
        subprocess.run(['cc','-std=c99','-O2','-shared','-fPIC','-I'+str(source),str(cfile),str(source/'ckc_packet.c'),
                        '-L'+str(build),'-lwrapper_spc_native','-Wl,-rpath,'+str(build),'-o',str(library)],check=True,capture_output=True)
        lib=C.CDLL(str(library));lib.ams_pristine_new.argtypes=[C.POINTER(Request),C.POINTER(Result)];lib.ams_pristine_new.restype=C.c_void_p
        lib.wrapper_kg_spc_session_free.argtypes=[C.c_void_p]
        probe=lib.ams_kernel_probe;probe.argtypes=[C.c_void_p,C.c_uint,C.c_uint,C.POINTER(Result),C.POINTER(C.c_uint64),C.POINTER(C.c_uint64),C.POINTER(C.c_ubyte),C.c_void_p,C.c_uint,C.c_uint];probe.restype=C.c_int
        for profile in range(3):
            rng=random.Random(0x451732+profile*91733);ticks=[0]
            def entropy(_,destination,count):
                for index in range(count):destination[index]=rng.randrange(256)
                return 0
            def clock(_):ticks[0]+=1;return 0x3234567800000000+profile*0x10000000000000+ticks[0]*100003
            def wall(_,seconds,micros):seconds[0]=1702000000+profile*1000000;micros[0]=123456+profile*100003;return 0
            callbacks=(Entropy(entropy),Clock(clock),Time(wall));request=Request(0,None,0,None,0,None,0,*callbacks,None);result=Result()
            handle=lib.ams_pristine_new(C.byref(request),C.byref(result));assert handle
            checks=[]
            try:
                for variant in range(2):
                    for size in (16,32,48,64):
                        data=bytes(data_rng.randrange(256) for _ in range(size+16));buffer=C.create_string_buffer(data)
                        result=Result();changed=(C.c_uint64*3)();returned=C.c_uint64();output=(C.c_ubyte*192)()
                        code=probe(handle,variant,size,C.byref(result),changed,C.byref(returned),output,buffer,len(data),3)
                        destination=2 if variant else 1;actual=bytes(output)[destination*64:destination*64+size]
                        if profile==0 and size in (16,32):known.append(dict(variant=variant,iv=data[:16].hex(),plaintext=data[16:].hex(),ciphertext=actual.hex()))
                        checks.append(dict(variant=variant,bytes=size,source_returned=code==1,
                            fixed_encrypt_equal=encrypt(variant,data[16:],data[:16])==actual,
                            fixed_decrypt_equal=decrypt(variant,actual,data[:16])==data[16:]))
            finally:lib.wrapper_kg_spc_session_free(handle)
            rows.append(dict(profile=profile,SPC_or_session_setup=False,certificate_or_device_input=False,parameter_refitting=False,cases=checks))
    passed=all(check['source_returned'] and check['fixed_encrypt_equal'] and check['fixed_decrypt_equal'] for row in rows for check in row['cases'])
    report=dict(status='pass' if passed else 'fail',pristine_runtimes=3,messages=24,profiles=rows,network_requests=0,
                account_session_content_material_used=False,scope='fixed package byte ciphers against pristine mapped-source runtimes; no SPC generation, device/certificate/session input or fitting; source image data is a developer oracle only')
    if args.emit_known_answers is not None:
        assert passed and len(known)==4
        args.emit_known_answers.parent.mkdir(parents=True,exist_ok=True)
        args.emit_known_answers.write_text(json.dumps(dict(scope='Public invented-message known-answer vectors from pristine source-runtime execution; no account/session/content input, no key or original table bytes',artifact_sha256='1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b',cases=known),indent=2)+'\n')
    args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(dict(status=report['status'],pristine_runtimes=3,messages=24)))
    if not passed:raise SystemExit(1)


if __name__=='__main__':main()
