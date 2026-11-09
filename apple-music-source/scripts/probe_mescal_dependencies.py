"""Developer audit; run from the source checkout, never part of package runtime.

Only invented inputs and address/count diagnostics. Uses existing build objects
in temporary files; does not access accounts, the retained harness, or network.
"""
import tempfile,subprocess,sys
from pathlib import Path
root=Path.cwd()
shim=r'''
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
static unsigned long pairs,reads,images;static uint64_t first;
int __real_mescal_integrity_pair(uint64_t,uint64_t,uint8_t*);
int __wrap_mescal_integrity_pair(uint64_t a,uint64_t b,uint8_t*out){++pairs;return __real_mescal_integrity_pair(a,b,out);}
int __real_mescal_native_read(const void*,size_t,uint64_t,unsigned,uint64_t*);
int __wrap_mescal_native_read(const void*r,size_t n,uint64_t a,unsigned w,uint64_t*out){++reads;if(a<0x1000000||a>=0x4000000){if(!images)first=a;++images;}return __real_mescal_native_read(r,n,a,w,out);}
__attribute__((destructor))static void done(void){fprintf(stderr,"AUDIT pairs=%lu reads=%lu image_reads=%lu first_image=0x%llx\n",pairs,reads,images,(unsigned long long)first);}
'''
with tempfile.TemporaryDirectory(prefix='ams-auth-audit-')as t:
 p=Path(t);(p/'shim.c').write_text(shim)
 objs=sorted((root/'build/auth/mescal/CMakeFiles/wrapper_mescal_source.dir').rglob('*.o'))
 subprocess.run(['cc','-shared','-fPIC',str(p/'shim.c'),*[str(o)for o in objs],'-Wl,--wrap=mescal_integrity_pair','-Wl,--wrap=mescal_native_read','-o',str(p/'audit.so')],check=True,capture_output=True)
 program="""import sys;sys.path.insert(0,'tools/auth');from device_identity import derive_android_guid_fields
f=derive_android_guid_fields(b'0123456789abcdef',bytes.fromhex('001122334455'),library=sys.argv[1]);print('guid_success',len(f.first)==18,len(f.second)==7)
"""
 r=subprocess.run([sys.executable,'-S','-c',program,str(p/'audit.so')],capture_output=True,text=True,timeout=45)
 print(r.returncode,r.stdout.strip(),r.stderr.strip())
