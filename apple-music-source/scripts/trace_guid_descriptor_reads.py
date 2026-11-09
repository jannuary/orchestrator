"""Localize GUID output production between native-source memory reads.

All original source objects stay unchanged. The read shim reports only PCs and
changed descriptor offsets; byte values, device fields and pointers stay in RAM.
A change is bounded by reads, not attributed to an exact write instruction.
"""
import argparse
import ctypes as C
import json
from pathlib import Path
import re
import subprocess
import sys
import tempfile

from probe_auth_substitution_reads import group_wrappers

SHIM=r'''
#include "spc_native.h"
#include <string.h>
static wrapper_kg_native_state*current_state;
static unsigned char*destination;static unsigned char previous[56];
static uint64_t previous_pc;
struct event{uint64_t previous_pc,observed_pc;unsigned char changed[56];};
static struct event events[256];static unsigned used,overflow;
void ams_reset(void){destination=0;used=overflow=0;previous_pc=0;memset(previous,0,56);}
static void ams_enter(wrapper_kg_native_state*s,const wrapper_kg_payload_region*r,size_t n){
 if(s->cpu.pc!=UINT64_C(0x203f10))return;uint64_t a=s->cpu.gpr[5];destination=0;
 for(size_t i=0;i<n;++i)if(a>=r[i].address&&a-r[i].address<=r[i].size&&56<=r[i].size-(a-r[i].address)){destination=r[i].data+(a-r[i].address);break;}
 if(destination)memcpy(previous,destination,56);previous_pc=s->cpu.pc;
}
int __real_mescal_native_read(const void*,size_t,uint64_t,unsigned,uint64_t*);
int __wrap_mescal_native_read(const void*r,size_t n,uint64_t a,unsigned w,uint64_t*out){
 if(destination&&current_state){uint64_t pc=current_state->cpu.pc;
  if(memcmp(destination,previous,56)){if(used==256)overflow=1;else{struct event*e=events+used++;e->previous_pc=previous_pc;e->observed_pc=pc;for(unsigned i=0;i<56;++i)e->changed[i]=destination[i]!=previous[i];}memcpy(previous,destination,56);}previous_pc=pc;}
 return __real_mescal_native_read(r,n,a,w,out);
}
unsigned ams_count(void){return used;}unsigned ams_overflow(void){return overflow;}
const struct event*ams_events(void){return events;}
'''


def main():
 parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('checkout',type=Path);parser.add_argument('--output',type=Path,required=True);args=parser.parse_args();root=args.checkout.resolve();sys.path.insert(0,str(root/'tools/auth'))
 from device_identity import derive_android_guid_fields
 class Event(C.Structure):_fields_=[('previous_pc',C.c_uint64),('observed_pc',C.c_uint64),('changed',C.c_ubyte*56)]
 rows=[]
 with tempfile.TemporaryDirectory(prefix='ams-guid-output-reads-') as directory:
  directory=Path(directory);source,library,baseline=directory/'probe.c',directory/'probe.so',directory/'baseline.so'
  groups=sorted(set(re.findall(r'\bmescal_(?:ssc|corefp)_page_[0-9a-f]+\b',(root/'crypto/auth/mescal/generated/bounds.inc').read_text())))
  wrappers=group_wrappers(groups).replace('current_state=state;int status=', 'current_state=state;ams_enter(state,regions,count);int status=')
  source.write_text(SHIM+wrappers);objects=sorted((root/'build/auth/mescal/CMakeFiles/wrapper_mescal_source.dir').rglob('*.o'));assert objects
  subprocess.run(['cc','-std=c99','-O2','-shared','-fPIC','-I'+str(root/'crypto/keygen_experimental'),str(source),*map(str,objects),'-Wl,--wrap=mescal_native_read',*['-Wl,--wrap='+name for name in groups],'-o',str(library)],check=True,capture_output=True)
  subprocess.run(['cc','-shared',*map(str,objects),'-o',str(baseline)],check=True,capture_output=True)
  lib=C.CDLL(str(library));lib.ams_count.restype=C.c_uint;lib.ams_events.restype=C.POINTER(Event)
  for profile,(android,mac) in enumerate(((b'0123456789abcdef',bytes(range(6))),(b'fedcba9876543210',bytes(range(6,12))))):
   lib.ams_reset();fields=derive_android_guid_fields(android,mac,system_serial=b'invented-read-probe',library=library)
   assert not lib.ams_overflow() and fields==derive_android_guid_fields(android,mac,system_serial=b'invented-read-probe',library=baseline)
   events=lib.ams_events();changes=[]
   for i in range(lib.ams_count()):
    event=events[i];changes.append(dict(previous_read_PC=hex(event.previous_pc),observed_read_PC=hex(event.observed_pc),changed_descriptor_offsets=[j for j in range(56) if event.changed[j]]))
   rows.append(dict(profile=profile,unchanged_source_output_equal=True,changes=changes))
 report=dict(status='descriptor production bounded by source reads',cases=rows,network_requests=0,private_bytes_written=False,scope='source read-boundary localization on invented profiles, with untouched-source output control; not exact write-PC attribution or standalone GUID/auth')
 args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(dict(status=report['status'],changes=[len(row['changes']) for row in rows])))


if __name__=='__main__':main()
