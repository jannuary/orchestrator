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
static unsigned long reads,images;static uint64_t first,seen[32];static unsigned count;
int __real_adi_native_read(const void*,size_t,uint64_t,unsigned,uint64_t*);
int __wrap_adi_native_read(const void*r,size_t n,uint64_t a,unsigned w,uint64_t*out){++reads;if(a<0x1000000||a>=0x10000000){if(!images)first=a;++images;unsigned i;for(i=0;i<count&&seen[i]!=a;++i);if(i==count&&count<32)seen[count++]=a;}return __real_adi_native_read(r,n,a,w,out);}
__attribute__((destructor))static void done(void){fprintf(stderr,"AUDIT reads=%lu image_reads=%lu first_image=0x%llx addresses=",reads,images,(unsigned long long)first);for(unsigned i=0;i<count;++i)fprintf(stderr,"0x%llx,",(unsigned long long)seen[i]);fprintf(stderr,"\n");}
'''
with tempfile.TemporaryDirectory(prefix='ams-adi-audit-')as t:
 p=Path(t);(p/'shim.c').write_text(shim)
 objs=sorted((root/'build/auth/coreadi/CMakeFiles/wrapper_coreadi_source.dir').rglob('*.o'))
 subprocess.run(['cc','-shared','-fPIC',str(p/'shim.c'),*[str(o)for o in objs],'-Wl,--wrap=adi_native_read','-o',str(p/'audit.so')],check=True,capture_output=True)
 program="""import sys;sys.path.insert(0,'tools/auth');from coreadi_source import generate
s,v,r=generate(b'invented-provisioning',b'0123456789abcdef',library=sys.argv[1]);print('api_status',s,'backend_status',r.status,'pc',hex(r.pc),'mid_size',r.mid_size,'otp_size',r.otp_size)
"""
 r=subprocess.run([sys.executable,'-S','-c',program,str(p/'audit.so')],capture_output=True,text=True,timeout=45)
 print(r.returncode,r.stdout.strip(),r.stderr.strip())
