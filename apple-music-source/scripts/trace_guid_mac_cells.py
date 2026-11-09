"""Follow the two backing words consumed by the native MAC field serializer.

Four passes on invented inputs discover buffers/cells and trace cell changes
before each consumption. Addresses, word values and identifiers stay in RAM.
Only source PCs, relative offsets and verified equality flags are reported.
"""
import argparse
import ctypes as C
import hashlib
import struct
import json
from pathlib import Path
import random
import re
import subprocess
import sys
import tempfile

from probe_auth_substitution_reads import group_wrappers
from trace_guid_field_producers import SHIM

ADDON=r'''
static uint64_t cell_target,cell_requested,cell_discovered,cell_last_pc;
static unsigned char*cell_watch;static unsigned char cell_previous[8];
static uint64_t suffix_read_pcs[64];static unsigned suffix_reads;
unsigned ams_suffix_reads(void){return suffix_reads;}
uint64_t ams_suffix_read_pc(unsigned i){return i<64?suffix_read_pcs[i]:0;}
static unsigned char sha_schedule[320],sha_initial[20];static unsigned sha_captures;
static uint32_t cell_values[2];static unsigned cell_seen,cell_bad,cell_used;
struct cell_event{uint64_t previous_pc,observed_pc;unsigned char changed[8];};
static struct cell_event cell_events[128];
void ams_cells_config(uint64_t target,uint64_t watch){suffix_reads=0;sha_captures=0;cell_target=target;cell_requested=watch;cell_discovered=cell_last_pc=0;cell_watch=0;cell_seen=cell_bad=cell_used=0;memset(cell_previous,0,8);memset(cell_values,0,sizeof cell_values);}
static void ams_cells_enter(wrapper_kg_native_state*s,const wrapper_kg_payload_region*r,size_t n){
 if(s->cpu.pc==UINT64_C(0x205190)&&cell_requested){cell_watch=locate(r,n,cell_requested,8);if(cell_watch)memcpy(cell_previous,cell_watch,8);cell_last_pc=s->cpu.pc;}}
static void ams_cells_read(const wrapper_kg_payload_region*r,size_t n,uint64_t address,unsigned width,uint64_t value){
 (void)r;(void)n;if(!current_state)return;uint64_t pc=current_state->cpu.pc;
 if(address<UINT64_C(0x423956c)&&address+width>UINT64_C(0x423954c)){if(suffix_reads<64)suffix_read_pcs[suffix_reads]=pc;++suffix_reads;}
 if(cell_requested&&pc==UINT64_C(0x4670363)&&address==cell_requested+16){
  uint64_t ptr=0;unsigned char*q=locate(r,n,current_state->cpu.gpr[6]-0x30,8);
  if(q){memcpy(&ptr,q,8);q=locate(r,n,ptr,320);unsigned char*h=locate(r,n,cell_requested,20);if(q&&h){memcpy(sha_schedule,q,320);memcpy(sha_initial,h,20);++sha_captures;}}}
 if(cell_watch&&cell_seen!=3){unsigned changed=0;unsigned char mask[8];
  for(unsigned i=0;i<8;++i){mask[i]=!(cell_seen&(1u<<(i/4)))&&cell_watch[i]!=cell_previous[i];changed|=mask[i];}
  if(changed){struct cell_event*e=cell_events+(cell_used++%128);e->previous_pc=cell_last_pc;e->observed_pc=pc;memcpy(e->changed,mask,8);}memcpy(cell_previous,cell_watch,8);}
 if(cell_target&&pc==UINT64_C(0x46706b7)&&width==4){
  unsigned source_offset=(unsigned)(current_state->cpu.gpr[14]-UINT64_C(0x7625998a));
  uint64_t destination=current_state->cpu.gpr[0]+source_offset;
  unsigned offset=(unsigned)(destination-cell_target);
  if(offset==0||offset==4){uint64_t base=address-offset;if(cell_discovered&&cell_discovered!=base)cell_bad=1;cell_discovered=base;
   cell_values[offset/4]=(uint32_t)value;cell_seen|=1u<<(offset/4);if(cell_requested&&cell_requested!=base)cell_bad=1;}}
 cell_last_pc=pc;
}
unsigned ams_sha_count(void){return sha_captures;}
const unsigned char*ams_sha_schedule(void){return sha_schedule;}
const unsigned char*ams_sha_initial(void){return sha_initial;}
uint64_t ams_cells_base(void){return cell_discovered;}
unsigned ams_cells_seen(void){return cell_seen;}
unsigned ams_cells_bad(void){return cell_bad;}
uint32_t ams_cells_value(unsigned index){return index<2?cell_values[index]:0;}
unsigned ams_cells_count(void){return cell_used;}
const struct cell_event*ams_cells_events(void){return cell_events;}
'''


def main():
 parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('checkout',type=Path);parser.add_argument('--output',type=Path,required=True);args=parser.parse_args();root=args.checkout.resolve();sys.path.insert(0,str(root/'tools/auth'))
 from device_identity import decode_android_guid_fields
 from mescal_source import Options,Result,Entropy,Clock,Time
 class Event(C.Structure):_fields_=[('previous_pc',C.c_uint64),('observed_pc',C.c_uint64),('changed',C.c_ubyte*8)]
 def derive(android,mac,profile):
  rng=random.Random(0x654991+profile*131);ticks=[0]
  def entropy(_,destination,count):
   for i in range(count):destination[i]=rng.randrange(256)
   return 0
  def clock(_):ticks[0]+=1;return 0x3234567800000000+ticks[0]*100003
  def wall(_,seconds,micros):seconds[0]=1702000000;micros[0]=123456;return 0
  callbacks=(Entropy(entropy),Clock(clock),Time(wall));options=Options(*callbacks,None)
  call=lib.wrapper_mescal_guid_fields;call.argtypes=[C.c_void_p,C.c_size_t,C.c_void_p,C.c_size_t,C.c_void_p,C.c_void_p,C.c_size_t,C.POINTER(Options),C.POINTER(Result)];call.restype=C.c_int
  serial=b'invented-MAC-cell-trace';a=C.create_string_buffer(android);m=C.create_string_buffer(mac);s=C.create_string_buffer(serial);out=C.create_string_buffer(56);result=Result()
  assert call(a,len(android),s,len(serial),m,out,56,C.byref(options),C.byref(result))==0
  return decode_android_guid_fields(out.raw)
 def serialization(fields):
  assert lib.ams_cells_seen()==3 and not lib.ams_cells_bad()
  clear=b''.join((lib.ams_cells_value(i)^0x77143e48).to_bytes(4,'big') for i in range(2))[:7]
  return clear==fields.second
 rows=[];messages=[]
 with tempfile.TemporaryDirectory(prefix='ams-MAC-cell-trace-') as directory:
  directory=Path(directory);source,library=directory/'probe.c',directory/'probe.so'
  groups=sorted(set(re.findall(r'\bmescal_(?:ssc|corefp)_page_[0-9a-f]+\b',(root/'crypto/auth/mescal/generated/bounds.inc').read_text())))
  prototype='static void ams_cells_read(const wrapper_kg_payload_region*,size_t,uint64_t,unsigned,uint64_t);\n'
  shim=SHIM.replace('int __real_mescal_native_read(',prototype+'int __real_mescal_native_read(',1).replace('int ok=__real_mescal_native_read(r,n,a,w,out);','int ok=__real_mescal_native_read(r,n,a,w,out);if(ok)ams_cells_read(r,n,a,w,*out);',1)
  wrappers=group_wrappers(groups).replace('current_state=state;int status=','current_state=state;ams_enter(state,regions,count);ams_cells_enter(state,regions,count);int status=')
  source.write_text(shim+ADDON+wrappers);objects=sorted((root/'build/auth/mescal/CMakeFiles/wrapper_mescal_source.dir').rglob('*.o'));assert objects
  subprocess.run(['cc','-std=c99','-O2','-shared','-fPIC','-I'+str(root/'crypto/keygen_experimental'),str(source),*map(str,objects),'-Wl,--wrap=mescal_native_read',*['-Wl,--wrap='+name for name in groups],'-o',str(library)],check=True,capture_output=True)
  lib=C.CDLL(str(library));lib.ams_suffix_read_pc.argtypes=[C.c_uint];lib.ams_suffix_read_pc.restype=C.c_uint64;lib.ams_sha_schedule.restype=C.POINTER(C.c_ubyte);lib.ams_sha_initial.restype=C.POINTER(C.c_ubyte);lib.ams_reset.argtypes=[C.c_uint64,C.c_uint64];lib.ams_cells_config.argtypes=[C.c_uint64,C.c_uint64];lib.ams_discovered.argtypes=[C.c_uint];lib.ams_discovered.restype=C.c_uint64;lib.ams_mac_source.restype=C.c_uint64;lib.ams_cells_base.restype=C.c_uint64;lib.ams_cells_value.argtypes=[C.c_uint];lib.ams_cells_value.restype=C.c_uint32;lib.ams_cells_events.restype=C.POINTER(Event)
  for profile,(android,mac) in enumerate(((b'0123456789abcdef',bytes(range(6))),(b'fedcba9876543210',bytes(range(6,12))))):
   lib.ams_reset(0,0);lib.ams_cells_config(0,0);first=derive(android,mac,profile);final=lib.ams_discovered(1);assert final
   lib.ams_reset(0,final);lib.ams_cells_config(0,0);second=derive(android,mac,profile);upstream=lib.ams_mac_source();assert upstream and first==second
   lib.ams_reset(0,upstream);lib.ams_cells_config(upstream,0);third=derive(android,mac,profile);cells=lib.ams_cells_base();assert cells and third==first and serialization(third),dict(cells_discovered=bool(cells),seen=lib.ams_cells_seen(),bad=bool(lib.ams_cells_bad()),repeated_output_equal=third==first)
   lib.ams_reset(0,upstream);lib.ams_cells_config(upstream,cells);fourth=derive(android,mac,profile);assert fourth==first and cells==lib.ams_cells_base() and serialization(fourth)
   assert lib.ams_sha_count()==1
   words=[x^0x544b0786 for x in struct.unpack('<80I',C.string_at(lib.ams_sha_schedule(),320))]
   initial=[x^0x77143e48 for x in struct.unpack('<5I',C.string_at(lib.ams_sha_initial(),20))]
   assert initial==[0x67452301,0xefcdab89,0x98badcfe,0x10325476,0xc3d2e1f0]
   def rol(x,n):return ((x<<n)|(x>>(32-n)))&0xffffffff
   assert all(words[i]==rol(words[i-3]^words[i-8]^words[i-14]^words[i-16],1) for i in range(16,80))
   block=struct.pack('>16I',*words[:16]);bits=int.from_bytes(block[-8:],'big');assert bits%8==0 and bits//8<56
   message=block[:bits//8];assert block[len(message):]==b'\x80'+bytes(55-len(message))+bits.to_bytes(8,'big')
   assert hashlib.sha1(message).digest()[:7]==fourth.second
   candidates={'raw_MAC':mac,'hex_MAC':mac.hex().encode(),'colon_MAC':b':'.join(f'{x:02x}'.encode() for x in mac),'encoded_MAC':bytes((167*x+18)&255 for x in mac),'decoded_MAC':bytes((23*x+98)&255 for x in mac)}
   messages.append(message)
   sha=dict(MAC_offset=message.find(mac),schedule_recurrence_equal=True,initial_state_equal=True,padding_valid=True,hashlib_field_equal=True,message_bytes=len(message),candidate_equal={name:value==message for name,value in candidates.items()},MAC_occurs=mac in message)
   suffix_pcs=[hex(lib.ams_suffix_read_pc(i)) for i in range(min(64,lib.ams_suffix_reads()))]
   count=lib.ams_cells_count();assert count;events=lib.ams_cells_events();changes=[]
   for number in range(max(0,count-128),count):
    event=events[number%128];changes.append(dict(previous_read_PC=hex(event.previous_pc),observed_read_PC=hex(event.observed_pc),changed_cell_offsets=[i for i in range(8) if event.changed[i]]))
   rows.append(dict(profile=profile,SHA1=sha,static_suffix_read_PCs=suffix_pcs,repeated_outputs_equal=True,backing_cell_allocations_equal=True,two_word_serialization_equal=True,total_changes=count,earlier_changes_omitted=max(0,count-128),changes=changes))
 offsets=[row['SHA1']['MAC_offset'] for row in rows];assert len(set(offsets))==1 and offsets[0]>=0
 suffixes=[message[:offsets[0]]+message[offsets[0]+6:] for message in messages]
 from scan_auth_substitutions import TARGETS
 name,digest=TARGETS['corefp'];image=(root/'rootfs/system/lib64'/name).read_bytes();assert hashlib.sha256(image).hexdigest()==digest
 positions=[]
 for part in (messages[0][:offsets[0]],messages[0][offsets[0]+6:]):
  positions.append({name:image.find(value) for name,value in {'clear':part,'wire':bytes((23*x+98)&255 for x in part),'xor47':bytes(x^47 for x in part)}.items()} if part else None)
 report=dict(non_MAC_bytes_equal_across_profiles=len(set(suffixes))==1,non_MAC_part_file_offsets=positions,status='MAC SHA1 schedule and message verified',cases=rows,network_requests=0,private_bytes_written=False,scope='source read-boundary tracing, complete SHA1 schedule/message/field checks and static suffix read provenance; no pointer/value output or complete GUID/auth claim')
 args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(dict(status=report['status'],changes=[row['total_changes'] for row in rows])))


if __name__=='__main__':main()
