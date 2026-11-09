"""Locate changes to native GUID field buffers before their descriptor copy.

Two-pass developer tracing with invented profiles. Guest/host pointers, buffer
bytes and identifiers remain in RAM; only PC boundaries and offsets are saved.
A repeat verifies identical results and identical guest buffer allocation before
using the first run's watch ranges. No source object is modified.
"""
import argparse
import ctypes as C
import json
import hashlib
from pathlib import Path
import re
import random
import subprocess
import sys
import tempfile

from probe_auth_substitution_reads import group_wrappers

SHIM=r'''
#include "spc_native.h"
#include <string.h>
static wrapper_kg_native_state*current_state;
static uint64_t requested[2],discovered[2],last_pc,descriptor,mac_source;
static unsigned char*watch[2],previous[2][18];
static unsigned stage_length,initial_size,mac_size,stop_initial,initial_captures;static unsigned char initial[64],mac_input[32];
static unsigned seed_ready,hash_input_size,expansion_stage_ready,lookup_ready;static unsigned char lookup[64];static unsigned char expansion_stage[328];static unsigned char fold_seed[20],fold_inputs[456],hash_input[256];
struct event{uint64_t previous_pc,observed_pc;unsigned field;unsigned char changed[18];};
static struct event events[2][128];static unsigned used[2],finished[2];
void ams_stop_initial(unsigned enabled){stop_initial=enabled;}
void ams_reset(uint64_t first,uint64_t second){requested[0]=first;requested[1]=second;watch[0]=watch[1]=0;discovered[0]=discovered[1]=last_pc=descriptor=mac_source=0;used[0]=used[1]=finished[0]=finished[1]=0;memset(previous,0,sizeof previous);stage_length=initial_size=mac_size=initial_captures=seed_ready=hash_input_size=expansion_stage_ready=lookup_ready=0;memset(initial,0,sizeof initial);memset(mac_input,0,sizeof mac_input);}
static unsigned char*locate(const wrapper_kg_payload_region*r,size_t n,uint64_t a,size_t width){
 for(size_t i=0;i<n;++i)if(a>=r[i].address&&a-r[i].address<=r[i].size&&width<=r[i].size-(a-r[i].address))return r[i].data+(a-r[i].address);return 0;}
static void ams_enter(wrapper_kg_native_state*s,const wrapper_kg_payload_region*r,size_t n){
 if(s->cpu.pc==UINT64_C(0x203f10))descriptor=s->cpu.gpr[5];
 if(s->cpu.pc!=UINT64_C(0x205190))return;
 for(unsigned k=0;k<2;++k)if(requested[k]){watch[k]=locate(r,n,requested[k],k?7:18);if(watch[k])memcpy(previous[k],watch[k],k?7:18);}
 last_pc=s->cpu.pc;
}
int __real_mescal_native_read(const void*,size_t,uint64_t,unsigned,uint64_t*);
int __wrap_mescal_native_read(const void*r,size_t n,uint64_t a,unsigned w,uint64_t*out){
 if(current_state){uint64_t pc=current_state->cpu.pc;
  if(descriptor&&(pc==UINT64_C(0x4668919)||pc==UINT64_C(0x4668986))){uint64_t index=current_state->cpu.gpr[pc==UINT64_C(0x4668919)?4:2],dest=current_state->cpu.gpr[13]+index;if(dest>=descriptor+1&&dest<descriptor+19)discovered[0]=a-(dest-descriptor-1);}
  if(descriptor&&(pc==UINT64_C(0x4680a6b)||pc==UINT64_C(0x467933e))){uint64_t index=current_state->cpu.gpr[pc==UINT64_C(0x4680a6b)?2:0],dest=current_state->cpu.gpr[15]+index+29;if(dest>=descriptor+29&&dest<descriptor+36)discovered[1]=a-(dest-descriptor-29);}
  for(unsigned k=0;k<2;++k){unsigned width=k?7:18;if(watch[k]&&!finished[k]&&memcmp(watch[k],previous[k],width)){
   {struct event*e=events[k]+(used[k]++%128);e->previous_pc=last_pc;e->observed_pc=pc;e->field=k;memset(e->changed,0,18);for(unsigned i=0;i<width;++i)e->changed[i]=watch[k][i]!=previous[k][i];}memcpy(previous[k],watch[k],width);}}
  for(unsigned k=0;k<2;++k)if(discovered[k]&&requested[k])finished[k]=1;
  last_pc=pc;}
 int ok=__real_mescal_native_read(r,n,a,w,out);
 if(ok&&current_state&&requested[0]&&!lookup_ready&&current_state->cpu.pc==UINT64_C(0x42f67e3)){
  uint64_t frame=current_state->cpu.gpr[6],target=0;unsigned char*p=locate(r,n,frame-0x158,8);if(p){memcpy(&target,p,8);if(target==requested[0]){p=locate(r,n,current_state->cpu.gpr[8],64);if(p){memcpy(lookup,p,64);lookup_ready=1;}}}}

 if(ok&&current_state&&requested[0]&&!expansion_stage_ready&&current_state->cpu.pc==UINT64_C(0x42f6772)&&current_state->cpu.gpr[9]==UINT64_C(0x94d2607)){
  uint64_t frame=current_state->cpu.gpr[6],target=0;unsigned char*p=locate(r,n,frame-0x158,8);if(p){memcpy(&target,p,8);if(target==requested[0]){p=locate(r,n,frame-0x340,328);if(p){memcpy(expansion_stage,p,328);expansion_stage[current_state->cpu.gpr[8]%328]=(unsigned char)current_state->cpu.gpr[5];expansion_stage_ready=1;}}}}

 if(ok&&current_state&&requested[0]&&!hash_input_size&&current_state->cpu.pc==UINT64_C(0x42f65f8)&&current_state->cpu.gpr[1]==UINT64_C(0xb8d3569)){
  uint64_t frame=current_state->cpu.gpr[6],target=0;unsigned length=0;unsigned char*p=locate(r,n,frame-0x158,8),*q=locate(r,n,frame-0xb8,4);
  if(p&&q){memcpy(&target,p,8);memcpy(&length,q,4);if(target==requested[0]&&length&&length<=256){p=locate(r,n,a,length);if(p){memcpy(hash_input,p,length);hash_input_size=length;}}}}

 if(ok&&current_state&&requested[0]&&!seed_ready&&current_state->cpu.pc==UINT64_C(0x42f83c7)&&current_state->cpu.gpr[13]==requested[0]&&current_state->cpu.gpr[2]==UINT64_C(0x77049158)){
  uint64_t pointers[4]={requested[0],current_state->cpu.gpr[9],current_state->cpu.gpr[4],current_state->cpu.gpr[10]};unsigned widths[4]={20,64,64,328};unsigned char*destinations[4]={fold_seed,fold_inputs,fold_inputs+64,fold_inputs+128};unsigned valid=1;
  for(unsigned i=0;i<4;++i){unsigned char*p=locate(r,n,pointers[i],widths[i]);if(!p){valid=0;break;}memcpy(destinations[i],p,widths[i]);}seed_ready=valid;}

 if(ok&&current_state&&requested[0]&&current_state->cpu.pc==UINT64_C(0x42f8520)&&current_state->cpu.gpr[13]==requested[0]){
  stage_length=(unsigned)*out^0x3005ed45u;
  if(current_state->cpu.gpr[9]==UINT64_C(0x4b4ae83)&&stage_length&&stage_length<=64){unsigned char*p=locate(r,n,requested[0],stage_length);if(p){++initial_captures;if(!stop_initial||!initial_size){memcpy(initial,p,stage_length);initial_size=stage_length;}if(stop_initial)finished[0]=1;}}}
 if(ok&&current_state&&requested[1]&&!mac_size&&(current_state->cpu.pc==UINT64_C(0x45e2151)||current_state->cpu.pc==UINT64_C(0x45e216b))&&current_state->cpu.gpr[8]==requested[1]){
  unsigned char*p=locate(r,n,current_state->cpu.gpr[9],20);if(p){memcpy(mac_input,p,20);mac_size=20;mac_source=current_state->cpu.gpr[9];}}
 return ok;
}
uint64_t ams_discovered(unsigned field){return field<2?discovered[field]:0;}
uint64_t ams_mac_source(void){return mac_source;}
unsigned ams_lookup_ready(void){return lookup_ready;}
const unsigned char*ams_lookup(void){return lookup;}
unsigned ams_expansion_stage_ready(void){return expansion_stage_ready;}
const unsigned char*ams_expansion_stage(void){return expansion_stage;}
unsigned ams_hash_input_size(void){return hash_input_size;}
const unsigned char*ams_hash_input(void){return hash_input;}
unsigned ams_seed_ready(void){return seed_ready;}
const unsigned char*ams_fold_seed(void){return fold_seed;}
const unsigned char*ams_fold_inputs(void){return fold_inputs;}
unsigned ams_initial_captures(void){return initial_captures;}
unsigned ams_stage_length(void){return stage_length;}
unsigned ams_initial_size(unsigned field){return field?mac_size:initial_size;}
const unsigned char*ams_initial(unsigned field){return field?mac_input:initial;}
unsigned ams_total(unsigned field){return field<2?used[field]:0;}
const struct event*ams_events(unsigned field){return field<2?events[field]:0;}
'''


def main():
 parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('checkout',type=Path);parser.add_argument('--output',type=Path,required=True);parser.add_argument('--initial-only',action='store_true');parser.add_argument('--entropy-controls',action='store_true');args=parser.parse_args();root=args.checkout.resolve();sys.path.insert(0,str(root/'tools/auth'))
 sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'src'))
 from apple_music_source.auth._guid_input_expansion import expand328
 from device_identity import decode_android_guid_fields
 from mescal_source import Options,Result,Entropy,Clock,Time
 def derive(android,mac,profile):
  rng=random.Random(0x654991+profile*131);ticks=[0]
  def entropy(_,destination,count):
   for i in range(count):destination[i]=rng.randrange(256)
   return 0
  def clock(_):ticks[0]+=1;return 0x3234567800000000+ticks[0]*100003
  def wall(_,seconds,micros):seconds[0]=1702000000;micros[0]=123456;return 0
  callbacks=(Entropy(entropy),Clock(clock),Time(wall));options=Options(*callbacks,None)
  call=lib.wrapper_mescal_guid_fields;call.argtypes=[C.c_void_p,C.c_size_t,C.c_void_p,C.c_size_t,C.c_void_p,C.c_void_p,C.c_size_t,C.POINTER(Options),C.POINTER(Result)];call.restype=C.c_int
  serial=b'invented-producer-trace';a=C.create_string_buffer(android);m=C.create_string_buffer(mac);s=C.create_string_buffer(serial);out=C.create_string_buffer(56);result=Result()
  status=call(a,len(android),s,len(serial),m,out,56,C.byref(options),C.byref(result));assert status==0
  return decode_android_guid_fields(out.raw)
 class Event(C.Structure):_fields_=[('previous_pc',C.c_uint64),('observed_pc',C.c_uint64),('field',C.c_uint),('changed',C.c_ubyte*18)]
 rows=[];stage_samples=[];fold_samples=[];field_samples=[]
 with tempfile.TemporaryDirectory(prefix='ams-guid-field-producers-') as directory:
  directory=Path(directory);source,library=directory/'probe.c',directory/'probe.so'
  groups=sorted(set(re.findall(r'\bmescal_(?:ssc|corefp)_page_[0-9a-f]+\b',(root/'crypto/auth/mescal/generated/bounds.inc').read_text())))
  wrappers=group_wrappers(groups).replace('current_state=state;int status=', 'current_state=state;ams_enter(state,regions,count);int status=')
  source.write_text(SHIM+wrappers);objects=sorted((root/'build/auth/mescal/CMakeFiles/wrapper_mescal_source.dir').rglob('*.o'));assert objects
  subprocess.run(['cc','-std=c99','-O2','-shared','-fPIC','-I'+str(root/'crypto/keygen_experimental'),str(source),*map(str,objects),'-Wl,--wrap=mescal_native_read',*['-Wl,--wrap='+name for name in groups],'-o',str(library)],check=True,capture_output=True)
  lib=C.CDLL(str(library));lib.ams_stop_initial.argtypes=[C.c_uint];lib.ams_stop_initial(int(args.initial_only));lib.ams_initial_captures.restype=C.c_uint;lib.ams_reset.argtypes=[C.c_uint64,C.c_uint64];lib.ams_discovered.argtypes=[C.c_uint];lib.ams_discovered.restype=C.c_uint64;lib.ams_lookup_ready.restype=C.c_uint;lib.ams_lookup.restype=C.c_void_p;lib.ams_expansion_stage_ready.restype=C.c_uint;lib.ams_expansion_stage.restype=C.c_void_p;lib.ams_hash_input_size.restype=C.c_uint;lib.ams_hash_input.restype=C.c_void_p;lib.ams_seed_ready.restype=C.c_uint;lib.ams_fold_seed.restype=C.c_void_p;lib.ams_fold_inputs.restype=C.c_void_p;lib.ams_initial_size.argtypes=[C.c_uint];lib.ams_initial_size.restype=C.c_uint;lib.ams_initial.argtypes=[C.c_uint];lib.ams_initial.restype=C.c_void_p;lib.ams_stage_length.restype=C.c_uint;lib.ams_total.argtypes=[C.c_uint];lib.ams_total.restype=C.c_uint;lib.ams_events.argtypes=[C.c_uint];lib.ams_events.restype=C.POINTER(Event)
  profiles=((b'0123456789abcdef',bytes(range(6))),(b'fedcba9876543210',bytes(range(6,12))),(b'0011223344556677',bytes(range(32,38))),(b'ffeeddccbbaa9988',bytes(range(80,86))))
  if args.entropy_controls:profiles=(profiles[0],profiles[0],profiles[2],profiles[2])
  for profile,(android,mac) in enumerate(profiles):
   lib.ams_reset(0,0);first=derive(android,mac,profile);buffers=[lib.ams_discovered(i) for i in range(2)];assert all(buffers)
   lib.ams_reset(*buffers);second=derive(android,mac,profile)
   checks=dict(repeated_fields_equal=first==second,source_buffers_equal=buffers==[lib.ams_discovered(i) for i in range(2)])
   assert checks['repeated_fields_equal'] and checks['source_buffers_equal'],checks
   changes=[];totals=[lib.ams_total(field) for field in range(2)]
   for field,total in enumerate(totals):
    events=lib.ams_events(field)
    for number in range(max(0,total-128),total):
     event=events[number%128];changes.append(dict(field=event.field,previous_read_PC=hex(event.previous_pc),observed_read_PC=hex(event.observed_pc),changed_field_offsets=[j for j in range(18) if event.changed[j]]))
   assert all(any(change['field']==field for change in changes) for field in range(2))
   def mix(data):
    data=bytearray(data);length=len(data)
    rol=lambda value,n:((value<<n)|(value>>(8-n)))&255
    for index in range(256):
     at=index%length
     data[at]^=rol(data[((length+index-7)&0xffffffff)%length],1)^rol(data[((length+index-37)&0xffffffff)%length],6)^rol(data[((length+index-177)&0xffffffff)%length],5)
    return bytes(data)
   captured=[C.string_at(lib.ams_initial(field),lib.ams_initial_size(field)) for field in range(2)]
   inputs={'AndroidID':android,'AndroidID-hex-decoded':bytes.fromhex(android.decode()),'MAC':mac}
   matches=[]
   for name,message in inputs.items():
    for algorithm in ('sha1','sha256','md5'):
     digest=hashlib.new(algorithm,message).digest()
     for field,observed in enumerate(captured):
      if observed and observed==digest:matches.append(dict(field=field,input=name,algorithm=algorithm,transform='raw digest'))
      if observed and observed==mix(digest):matches.append(dict(field=field,input=name,algorithm=algorithm,transform='256-round cyclic mixer'))
   assert lib.ams_seed_ready()
   source_input=C.string_at(lib.ams_hash_input(),lib.ams_hash_input_size());assert source_input
   lookup_info=dict(site_observed=bool(lib.ams_lookup_ready()))
   if lib.ams_lookup_ready():
    from scan_auth_substitutions import TARGETS
    from verify_fill_dispatch import segment_read
    image=(root/'rootfs/system/lib64'/TARGETS['corefp'][0]).read_bytes()
    actual_lookup=C.string_at(lib.ams_lookup(),64);decoded_lookup=[byte^0x47 for byte in actual_lookup]
    lookup_info.update(runtime_equals_pristine=actual_lookup==segment_read(image,0x26d800,64),distinct=len(set(decoded_lookup)),all_power_of_two=all(value and not value&(value-1) for value in decoded_lookup),permutation_0_63=set(decoded_lookup)==set(range(64)))
   source_input_matches=[]
   for name,message in [('AndroidID',android),('AndroidID-hex-decoded',bytes.fromhex(android.decode())),('MAC',mac)]:
    candidates=[('raw',message),('xor47',bytes(byte^0x47 for byte in message)),('encode167',bytes((167*byte+18)&255 for byte in message)),('decode23',bytes((23*byte+98)&255 for byte in message))]
    for codec,value in candidates:
     if source_input==value:source_input_matches.append(dict(input=name,codec=codec))
   seed=C.string_at(lib.ams_fold_seed(),20);material=C.string_at(lib.ams_fold_inputs(),456);parts=(material[:64],material[64:128],material[128:]);folded=bytearray(seed)
   for part in parts:
    for index,byte in enumerate(part):folded[index%20]^=byte^0x47
   assert bytes(folded)==captured[0]
   assert lib.ams_expansion_stage_ready()
   native_expansion=C.string_at(lib.ams_expansion_stage(),328)
   assert expand328(source_input)==native_expansion
   fold_samples.append((android,mac,seed,parts))
   stage_samples.append((android,mac,captured));field_samples.append(second)
   first_prediction=mix(captured[0])[:18]==second.first if captured[0] else None
   mac_prediction=bytes((167*value+18)&255 for value in captured[1][:7])==second.second if captured[1] else None
   rows.append(dict(profile=profile,source_lookup_runtime=lookup_info,source_expansion_input_bytes=len(source_input),source_expansion_input_matches=source_input_matches,AndroidID_literal_in_source_input=source_input.find(android),initial_mixer_snapshots=lib.ams_initial_captures(),watch_stops_at_initial_mixer=args.initial_only,mixer_buffer_length=lib.ams_stage_length(),captured_stage_lengths=[len(value) for value in captured],stage_input_hypotheses=matches,source_input_expansion_prediction_equal=True,after_ARX_equals_pre_fold_buffer=native_expansion==parts[2],pre_mixer_fold_prediction_equal=True,first_field_mixer_prediction_equal=first_prediction,second_field_affine_prediction_equal=mac_prediction,repeated_output_equal=True,guest_buffer_allocations_equal=True,total_buffer_changes=totals,earlier_changes_omitted=[max(0,total-128) for total in totals],changes=changes))
 # Test only named arithmetic/hash families. A first-profile XOR delta is
 # accepted as a hypothesis only when it predicts all three later profiles;
 # no delta or fitted byte map is exported here.
 hypotheses=[]
 for field in range(2):
  for input_form in ('raw','hex','hex-colons'):
   for input_codec in ('raw','encode167','decode23'):
    for terminator in (False,True):
     for algorithm in ('sha1','sha256'):
      for order in ('raw','word-reversed','reversed'):
       for output_codec in ('raw','encode167','decode23'):
        for mixed in (False,True):
         deltas=[]
         for android,mac,captured in stage_samples:
          data=android if field==0 else mac
          if input_form=='hex':data=bytes.fromhex(android.decode()) if field==0 else mac.hex().encode()
          if input_form=='hex-colons':data=android.hex().encode() if field==0 else b':'.join(('%02x'%byte).encode() for byte in mac)
          transform=lambda value,codec:bytes((167*byte+18)&255 for byte in value) if codec=='encode167' else bytes((23*byte+98)&255 for byte in value) if codec=='decode23' else value
          data=transform(data,input_codec)+(b'\0' if terminator else b'');digest=hashlib.new(algorithm,data).digest()[:20]
          if order=='word-reversed':digest=b''.join(digest[i:i+4][::-1] for i in range(0,len(digest),4))
          elif order=='reversed':digest=digest[::-1]
          digest=transform(digest,output_codec)
          if mixed:digest=mix(digest)
          width=20 if field==0 else 7
          deltas.append(bytes(a^b for a,b in zip(digest[:width],captured[field][:width])))
         if len(deltas)==4 and len(set(deltas))==1:hypotheses.append(dict(field=field,input_form=input_form,input_codec=input_codec,NUL_terminated=terminator,algorithm=algorithm,word_order=order,output_codec=output_codec,cyclic_mixer=mixed,constant_XOR_delta_predicts_three_heldout=True,parameter_bytes_written=0))
 fold_layout=[]
 for part in range(3):
  values=[sample[3][part] for sample in fold_samples];width=len(values[0])
  fold_layout.append(dict(part=part,bytes=width,variable_offsets_across_profiles=[i for i in range(width) if len({value[i] for value in values})>1],AndroidID_literal_offsets=[data.find(android) for android,mac,seed,parts in fold_samples for data in [parts[part]]],MAC_literal_offsets=[data.find(mac) for android,mac,seed,parts in fold_samples for data in [parts[part]]]))
 seed_variable=[i for i in range(20) if len({sample[2][i] for sample in fold_samples})>1]
 entropy_controls=[]
 if args.entropy_controls:
  for first,second in ((0,1),(2,3)):
   entropy_controls.append(dict(profiles=[first,second],hardware_input_equal=True,entropy_seeds_differ=True,first_field_equal=field_samples[first].first==field_samples[second].first,second_field_equal=field_samples[first].second==field_samples[second].second,pre_mixer_state_equal=stage_samples[first][2][0]==stage_samples[second][2][0],second_field_input_prefix_equal=stage_samples[first][2][1][:7]==stage_samples[second][2][1][:7],fold_seed_equal=fold_samples[first][2]==fold_samples[second][2],fold_parts_equal=[fold_samples[first][3][part]==fold_samples[second][3][part] for part in range(3)]))
 report=dict(status='native field producer ranges observed',cases=rows,cross_entropy_controls=entropy_controls,pre_mixer_fold_layout=fold_layout,pre_mixer_seed_variable_offsets=seed_variable,heldout_initial_state_hypotheses=hypotheses,network_requests=0,private_bytes_written=False,OS_inputs='deterministic invented entropy, monotonic clock and wall time, reset for each repeat',scope='two-pass source read-boundary localization, retaining the last 128 buffer changes per field before its final copy, with repeated output/allocation checks on invented profiles; not exact write-PC attribution or complete GUID/auth')
 args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(dict(status=report['status'],changes=[len(row['changes']) for row in rows])))


if __name__=='__main__':main()
