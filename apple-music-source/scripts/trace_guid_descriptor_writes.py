"""Observe descriptor changes between selector instructions on invented inputs.

Only temporary source instrumentation is built; existing objects are preserved.
Change locations are reported without byte values. Changes across an untraced
callee are attributed to an observation boundary, not its exact write PC.
"""
import argparse
import ctypes as C
import json
from pathlib import Path
import re
import subprocess
import sys
import tempfile

C_SOURCE=r'''
#include "spc_native.h"
#include <string.h>
static uint64_t destination,previous_pc;
static unsigned char previous[56];
struct event {uint64_t previous_pc,observed_pc;unsigned char changed[56];};
static struct event events[256];static unsigned used,overflow;
void ams_descriptor_reset(void){destination=previous_pc=used=overflow=0;memset(previous,0,56);}
static const unsigned char*locate(const wrapper_kg_payload_region*r,size_t n,uint64_t a,size_t width){
 for(size_t i=0;i<n;++i)if(a>=r[i].address&&a-r[i].address<=r[i].size&&width<=r[i].size-(a-r[i].address))return r[i].data+(a-r[i].address);return 0;}
void ams_descriptor_step(wrapper_kg_native_state*s,const wrapper_kg_payload_region*r,size_t n){
 uint64_t pc=s->cpu.pc;if(pc==UINT64_C(0x203f10)){destination=s->cpu.gpr[5];previous_pc=pc;const unsigned char*p=locate(r,n,destination,56);if(p)memcpy(previous,p,56);return;}
 if(!destination)return;const unsigned char*p=locate(r,n,destination,56);if(!p)return;
 if(memcmp(p,previous,56)){if(used==256)overflow=1;else{struct event*e=events+used++;e->previous_pc=previous_pc;e->observed_pc=pc;for(unsigned i=0;i<56;++i)e->changed[i]=p[i]!=previous[i];}memcpy(previous,p,56);}
 previous_pc=pc;
}
unsigned ams_descriptor_count(void){return used;}
unsigned ams_descriptor_overflow(void){return overflow;}
const struct event*ams_descriptor_events(void){return events;}
'''


# Existing Mescal objects predate the CoreLSKD-only CKC shadow ABI. Restore
# their direct memory/budget macros for this temporary Mescal page; no CKC
# normalization exists on this target. Compare complete results with untouched
# objects below rather than assuming header/object ABI compatibility.
MESCAL_MEMORY_MACROS=r"""
#undef STEP
#define STEP(off) do {s->pc=bias+UINT64_C(off);if(s->steps==max_steps)return WRAPPER_KG_PAYLOAD_LIMIT;}while(0)
#undef READ
#define READ(dst,address,width) do {uint64_t addr_=(address);if(!mescal_native_read(regions,count,addr_,width,&(dst))){s->fault_address=addr_;s->fault_size=width;return WRAPPER_KG_PAYLOAD_READ_FAULT;}}while(0)
#undef WRITE
#define WRITE(address,width,value) do {uint64_t addr_=(address),v_=(value);unsigned j_;unsigned char*p_=translate(regions,count,addr_,width,2);if(!p_){s->fault_address=addr_;s->fault_size=width;return WRAPPER_KG_PAYLOAD_WRITE_FAULT;}for(j_=0;j_<width;++j_)p_[j_]=(unsigned char)(v_>>(j_*8));}while(0)
"""


def main():
 parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('checkout',type=Path);parser.add_argument('--output',type=Path,required=True);args=parser.parse_args();root=args.checkout.resolve();sys.path.insert(0,str(root/'tools/auth'))
 from device_identity import derive_android_guid_fields
 class Event(C.Structure):_fields_=[('previous_pc',C.c_uint64),('observed_pc',C.c_uint64),('changed',C.c_ubyte*56)]
 rows=[]
 with tempfile.TemporaryDirectory(prefix='ams-guid-descriptor-trace-') as directory:
  directory=Path(directory);source,shim,library=directory/'page.c',directory/'probe.c',directory/'probe.so'
  header=root/'crypto/auth/mescal/mescal_internal.h';sources=[]
  for page in (0x20,0x21):
   original=(root/'crypto/auth/mescal/generated'/('mescal_ssc_page_%x.c'%page)).read_text()
   instrument='#include "'+str(header)+'"\n'+MESCAL_MEMORY_MACROS+'\nvoid ams_descriptor_step(wrapper_kg_native_state*,const wrapper_kg_payload_region*,size_t);\n#define AMS_STEP(off) do {STEP(off);if((UINT64_C(off)>=UINT64_C(0x203f10)&&UINT64_C(off)<UINT64_C(0x20518a))||(UINT64_C(off)>=UINT64_C(0x2117c0)&&UINT64_C(off)<UINT64_C(0x211cea)))ams_descriptor_step(fs,regions,count);}while(0)'
   text=original.replace('#include "../mescal_internal.h"',instrument)
   text=re.sub(r': STEP\(',': AMS_STEP(',text);source=directory/('page_%x.c'%page);source.write_text(text);sources.append(source)
  shim.write_text(C_SOURCE)
  oldpages=[root/'build/auth/mescal/CMakeFiles/wrapper_mescal_source.dir/generated'/('mescal_ssc_page_%x.c.o'%page) for page in (0x20,0x21)]
  objects=[path for path in (root/'build/auth/mescal/CMakeFiles/wrapper_mescal_source.dir').rglob('*.o') if path not in oldpages];assert objects
  subprocess.run(['cc','-std=c99','-O0','-shared','-fPIC','-I'+str(root/'crypto/keygen_experimental'),*map(str,sources),str(shim),*map(str,objects),'-o',str(library)],check=True,capture_output=True)
  baseline=directory/'baseline.so'
  subprocess.run(['cc','-shared',*map(str,objects),*map(str,oldpages),'-o',str(baseline)],check=True,capture_output=True)
  lib=C.CDLL(str(library));lib.ams_descriptor_count.restype=C.c_uint;lib.ams_descriptor_events.restype=C.POINTER(Event)
  for profile,(android,mac) in enumerate(((b'0123456789abcdef',bytes(range(6))),(b'fedcba9876543210',bytes(range(6,12))))):
   lib.ams_descriptor_reset();fields=derive_android_guid_fields(android,mac,system_serial=b'invented-descriptor-probe',library=library);assert len(fields.first)==18 and len(fields.second)==7 and not lib.ams_descriptor_overflow()
   untouched=derive_android_guid_fields(android,mac,system_serial=b'invented-descriptor-probe',library=baseline)
   assert fields==untouched
   events=lib.ams_descriptor_events();observed=[]
   for i in range(lib.ams_descriptor_count()):
    e=events[i];observed.append(dict(previous_observed_PC=hex(e.previous_pc),observed_PC=hex(e.observed_pc),changed_descriptor_offsets=[j for j in range(56) if e.changed[j]]))
   rows.append(dict(profile=profile,unchanged_source_output_equal=True,changes=observed))
 report=dict(status='selector descriptor transitions observed',cases=rows,network_requests=0,private_bytes_written=False,scope='source selector instruction boundaries only; untraced callee changes are not exact write-PC attribution; no standalone GUID/auth claim')
 args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(dict(status=report['status'],changes=[len(row['changes']) for row in rows])))


if __name__=='__main__':main()
