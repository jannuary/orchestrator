"""Developer audit; run from the source checkout, never part of package runtime.

Only invented inputs and address/count diagnostics. Uses existing build objects
in temporary files; does not access accounts, the retained harness, or network.
"""
import tempfile,subprocess,os,sys,json
from pathlib import Path
root=Path.cwd()
shim=r'''
#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
static unsigned long folds,pairs,mespairs,reads,image_reads;
static uint64_t first_image;
static void *sym(const char *lib,const char *name){void*h=dlopen(lib,RTLD_NOW|RTLD_NOLOAD);if(!h)abort();void*p=dlsym(h,name);if(!p)abort();return p;}
uint32_t wrapper_kg_integrity_fold(uint64_t b,uint32_t x,int*ok){static uint32_t(*f)(uint64_t,uint32_t,int*);if(!f)f=sym(getenv("AUDIT_NATIVE"),"wrapper_kg_integrity_fold");++folds;return f(b,x,ok);}
int wrapper_kg_ckc_integrity_word(uint64_t a,uint64_t b,unsigned w,uint64_t*out){static int(*f)(uint64_t,uint64_t,unsigned,uint64_t*);if(!f)f=sym(getenv("AUDIT_NATIVE"),"wrapper_kg_ckc_integrity_word");++pairs;return f(a,b,w,out);}
int mescal_integrity_pair(uint64_t a,uint64_t b,uint8_t*out){static int(*f)(uint64_t,uint64_t,uint8_t*);if(!f)f=sym(getenv("AUDIT_MESCAL"),"mescal_integrity_pair");++mespairs;return f(a,b,out);}
int wrapper_kg_native_read(const void*r,size_t n,uint64_t a,unsigned w,uint64_t*out){static int(*f)(const void*,size_t,uint64_t,unsigned,uint64_t*);if(!f)f=sym(getenv("AUDIT_NATIVE"),"wrapper_kg_native_read");++reads;if((a>=0x4c9e20&&a<0x54f071)||(a>=0x5be7c0&&a<0x60afb4)||(a>=0x10000000&&a<0x100cf9f8)||(a>=0x1066d000&&a<0x10696824)){if(!image_reads)first_image=a;++image_reads;}return f(r,n,a,w,out);}
__attribute__((destructor))static void done(void){fprintf(stderr,"AUDIT {\"fold_calls\":%lu,\"ckc_word_calls\":%lu,\"mescal_pair_calls\":%lu,\"native_reads\":%lu,\"image_reads\":%lu,\"first_image_address\":%llu}\n",folds,pairs,mespairs,reads,image_reads,(unsigned long long)first_image);}
'''
with tempfile.TemporaryDirectory(prefix='ams-audit-')as t:
 p=Path(t);(p/'shim.c').write_text(shim);subprocess.run(['cc','-shared','-fPIC','-O2',str(p/'shim.c'),'-ldl','-o',str(p/'shim.so')],check=True)
 env=dict(os.environ,LD_PRELOAD=str(p/'shim.so'),AUDIT_NATIVE=str(root/'build/spc-payload/libwrapper_spc_native.so'),AUDIT_MESCAL=str(root/'build/auth/mescal/libwrapper_mescal_source.so'))
 programs={
 'synthetic_spc':"""import sys;sys.path.insert(0,'tools/crypto/keygen_experimental');from source_protocol import generate
s,o,r=generate('build/spc-payload/libwrapper_spc_generate.so',0,bytes(32),b'synthetic',bytes(range(16)));print('api_status',s,'pc',hex(r.pc),'output_size',r.output_size)
""",
}
 for name,program in programs.items():
  r=subprocess.run([sys.executable,'-S','-c',program],env=env,capture_output=True,text=True,timeout=45)
  print(name,r.returncode,r.stdout.strip(),r.stderr.strip())
