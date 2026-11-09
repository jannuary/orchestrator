"""Trace the setup record registry using invented offline SPC inputs.

Developer oracle probe only. No private session, network, or saved memory bytes.
The original runtime remains an oracle, not a package dependency.
"""
import argparse
import json
import os
from pathlib import Path
import subprocess
import sys
import tempfile
import threading


SHIM = r'''
#define _GNU_SOURCE
#include "spc_native.h"
#include "registry.h"
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static wrapper_kg_native_state *active;
static uint64_t registry, tags_address, records[1024];
static unsigned synthetic_reservations;
static unsigned installed[1024], slots, initialized, stores, folds;
static unsigned current, pointer_matches, record_matches, rekeys, setup_folds;
static uint32_t keys[1024];
static unsigned char plain[1024][336];
static unsigned operation_phase,operation_index;
static uint64_t operation_sites[2048];static unsigned operation_masks[2048],operation_nsites;
void ams_registry_operation_phase(unsigned active){operation_phase=active;if(active)++operation_index;}
static unsigned long pair_calls;
static const uint64_t fold_sites[]={0x1b65fb,0x207b91,0x23915b,0x3ede57,0x3ee66f,0x4b7898,0x4bc9da,0x50cb28,0x50d8b3};
static unsigned long fold_site_calls[9];
static const uint64_t image_starts[]={0x4c9e20,0x5be7c0,0x10000000,0x1066d000};
static const size_t image_sizes[]={545361,313332,850424,170020};
static unsigned char *image_seen[4];static unsigned long image_reads[4],image_unique[4];
static unsigned long reads_before, reads_after, registry_reads, boundaries;
static unsigned long bulk_record_reads,bulk_registry_reads;
static unsigned long changed_boundaries, changed_bytes;
static unsigned char previous[1024][336];
static void(*observer)(unsigned,uint64_t,uint32_t,uint64_t,const unsigned char*,const unsigned char*);
void ams_registry_set_observer(void(*f)(unsigned,uint64_t,uint32_t,uint64_t,const unsigned char*,const unsigned char*)){observer=f;}
typedef struct {uint64_t pc;unsigned long registry,record,bytes;unsigned min,max;} site;
static site sites[1024];static unsigned nsites;
static void *resolve(const char *name){void *h=dlopen(getenv("AMS_NATIVE"),RTLD_NOW|RTLD_NOLOAD);if(!h)abort();void *p=dlsym(h,name);if(!p)abort();return p;}
static const unsigned char *memory(const wrapper_kg_payload_region*r,size_t n,uint64_t a,size_t w){
 for(size_t j=0;j<n;++j)if(a>=r[j].address&&w<=r[j].size&&a-r[j].address<=r[j].size-w)return r[j].data+(a-r[j].address);
 return 0;
}
void ams_registry_bulk_access(uint64_t address,size_t width,unsigned permission){
 if(!(permission&1)||!width||address>UINT64_MAX-width)return;
 if(registry&&address<registry+8192&&registry<address+width)++bulk_registry_reads;
 for(unsigned i=0;i<slots;++i)if(installed[i]&&address<records[i]+336&&records[i]<address+width){++bulk_record_reads;break;}
}
static uint64_t encode_pointer(uint64_t value,uint32_t key){
 uint32_t k=key*UINT32_C(0x678086cb),q[2]={k*k^k,k*(k+1)^k},w[2];unsigned char b[8];
 for(unsigned i=0;i<8;++i)b[i]=(unsigned char)(value>>(i*8));
 for(unsigned i=7;i>1;--i){unsigned j=((k+i)^k)*UINT32_C(0x1000193)%i;unsigned char v=b[i];b[i]=b[j];b[j]=v;}
 {unsigned char v=b[1];b[1]=b[0];b[0]=v;}
 for(unsigned i=0;i<2;++i){w[i]=0;for(unsigned j=0;j<4;++j)w[i]|=(uint32_t)b[i*4+j]<<(j*8);w[i]=(w[i]*UINT32_C(0x1000193)+q[i])^q[i];}
 return ((uint64_t)w[0]|(uint64_t)w[1]<<32)-UINT64_C(0x87a0e6b449599d30);
}
static void transform_record(unsigned char*b,uint64_t address,uint32_t key,int decode){
 uint32_t seed=(uint32_t)address*UINT32_C(0x678086cb)^key;
 if(decode)for(unsigned i=1;i<42;++i){unsigned j=((seed+i)^seed)*UINT32_C(0x1000193)%i;
  for(unsigned k=0;k<8;++k){unsigned char v=b[i*8+k];b[i*8+k]=b[j*8+k];b[j*8+k]=v;}}
 for(unsigned i=0;i<336;++i){unsigned char mask=(unsigned char)(((i-seed)*(i+seed))^seed);
  /* 0x9b is the modular inverse of the low byte of the FNV prime. */
  b[i]=decode?(unsigned char)((unsigned char)(b[i]*155)^mask):(unsigned char)((b[i]^mask)*147);}
 if(!decode)for(unsigned i=41;i>0;--i){unsigned j=((seed+i)^seed)*UINT32_C(0x1000193)%i;
  for(unsigned k=0;k<8;++k){unsigned char v=b[i*8+k];b[i*8+k]=b[j*8+k];b[j*8+k]=v;}}
}
int ams_registry_seed_invented(const wrapper_kg_payload_region*r,size_t n){
 if(stores!=1024||synthetic_reservations||!tags_address)return 0;
 ams_registry canonical;ams_registry_search search;ams_registry_init(&canonical);ams_registry_search_begin(&search,1);
 if(ams_registry_reserve(&canonical,&search,1024)!=AMS_REGISTRY_FOUND||search.slot!=1)return 0;
 unsigned char *p=(unsigned char*)memory(r,n,tags_address+search.slot*4,4);if(!p)return 0;
 uint32_t before=0;for(unsigned i=0;i<4;++i)before|=(uint32_t)p[i]<<(i*8);if(before!=UINT32_C(0x69cad980))return 0;
 uint32_t value=canonical.generation[search.slot]+UINT32_C(0x69cad980);
 for(unsigned i=0;i<4;++i)p[i]=(unsigned char)(value>>(i*8));unsigned char *record=(unsigned char*)memory(r,n,records[search.slot],336);if(!record)abort();
 transform_record(record,records[search.slot],keys[search.slot],1);
 for(unsigned i=0;i<4;++i)record[0xf0+i]=(unsigned char)(search.handle>>(i*8));
 transform_record(record,records[search.slot],keys[search.slot],0);
 memcpy(previous[search.slot],record,336);++synthetic_reservations;return 1;
}
int ams_registry_canonical(const wrapper_kg_payload_region*r,size_t n,unsigned char*out,size_t size){
 if(stores!=1024||!out||size!=1024*(336+4))return 0;
 const unsigned char *t=memory(r,n,tags_address,4096),*slots=memory(r,n,registry,8192);if(!t||!slots)return 0;
 for(unsigned i=0;i<1024;++i){
  uint64_t pointer=0;uint32_t generation=0;
  for(unsigned j=0;j<8;++j)pointer|=(uint64_t)slots[i*8+j]<<(j*8);
  if(pointer!=encode_pointer(records[i],keys[i]))return 0;
  for(unsigned j=0;j<4;++j)generation|=(uint32_t)t[i*4+j]<<(j*8);
  generation-=UINT32_C(0x69cad980);
  for(unsigned j=0;j<4;++j)out[i*340+j]=(unsigned char)(generation>>(j*8));
  const unsigned char *p=memory(r,n,records[i],336);if(!p)return 0;
  memcpy(out+i*340+4,p,336);transform_record(out+i*340+4,records[i],keys[i],1);
 }
 return 1;
}
void ams_registry_event(unsigned event,wrapper_kg_native_state *fs,const wrapper_kg_payload_region*r,size_t n){
 wrapper_kg_payload_state*s=&fs->cpu;
 if(event==0){
 const unsigned char*t=memory(r,n,s->gpr[6]-0x1158,8);if(!t)abort();uint64_t at=0;for(unsigned j=0;j<8;++j)at|=(uint64_t)t[j]<<(j*8);if(tags_address&&at!=tags_address)abort();tags_address=at;
 const unsigned char*p=memory(r,n,records[current],336);if(!p)abort();memcpy(plain[current],p,336);
 }else if(event==1){unsigned i=(unsigned)s->gpr[13];if(i>=1024)abort();current=i;
  if(!registry)registry=s->gpr[3];if(registry!=s->gpr[3])abort();
  if(i&&records[i-1]+336>s->gpr[0])abort();records[i]=s->gpr[0];
  if(i+1>slots)slots=i+1;++initialized;
 }else{unsigned i=(unsigned)s->gpr[3];if(i>=slots||registry!=s->gpr[2]||installed[i])abort();
  installed[i]=1;++stores;
  const unsigned char*p=memory(r,n,records[i],336);if(!p)abort();memcpy(previous[i],p,336);
  unsigned char encoded[336],rekeyed[336];memcpy(encoded,plain[i],336);transform_record(encoded,records[i],keys[i],0);
  if(encode_pointer(records[i],keys[i])!=s->gpr[0])abort();++pointer_matches;
  if(memcmp(encoded,p,336))abort();++record_matches;
  memcpy(rekeyed,plain[i],336);transform_record(rekeyed,records[i],keys[i]^UINT32_C(0xa5a5a5a5),0);
  transform_record(rekeyed,records[i],keys[i]^UINT32_C(0xa5a5a5a5),1);
  if(memcmp(rekeyed,plain[i],336))abort();++rekeys;
  if(observer&&(i<4||i>=1020))observer(i,records[i],keys[i],s->gpr[0],plain[i],p);
 }
}
static void hit(uint64_t pc,int reg,unsigned offset,unsigned width){
 unsigned i;for(i=0;i<nsites&&sites[i].pc!=pc;++i){}
 if(i==nsites){if(nsites==1024)abort();sites[i].pc=pc;sites[i].min=336;++nsites;}
 if(reg)++sites[i].registry;else{++sites[i].record;sites[i].bytes+=width;if(offset<sites[i].min)sites[i].min=offset;if(offset+width>sites[i].max)sites[i].max=offset+width;}
}
int wrapper_kg_native_read(const wrapper_kg_payload_region*r,size_t n,uint64_t a,unsigned w,uint64_t*out){
 static int(*f)(const wrapper_kg_payload_region*,size_t,uint64_t,unsigned,uint64_t*);if(!f)f=resolve("wrapper_kg_native_read");
 int result=f(r,n,a,w,out);
 if(active&&operation_phase){unsigned i;for(i=0;i<operation_nsites&&operation_sites[i]!=active->cpu.pc;++i){}if(i==operation_nsites){if(i==2048)abort();operation_sites[i]=active->cpu.pc;++operation_nsites;}operation_masks[i]|=1u<<(operation_index-1);}
 if(active&&result&&w)for(unsigned j=0;j<4;++j)if(a>=image_starts[j]&&a-image_starts[j]<image_sizes[j]){
  ++image_reads[j];if(!image_seen[j]){image_seen[j]=calloc(image_sizes[j],1);if(!image_seen[j])abort();}
  size_t offset=(size_t)(a-image_starts[j]);for(unsigned k=0;k<w&&offset+k<image_sizes[j];++k)if(!image_seen[j][offset+k]){image_seen[j][offset+k]=1;++image_unique[j];}
 }
 if(active&&result&&w&&registry){uint64_t pc=active->cpu.pc;
  if(a>=registry&&a-registry<8192){++registry_reads;hit(pc,1,0,w);}
  if(slots&&a>=records[0]&&a<records[slots-1]+336){unsigned lo=0,hi=slots;
   while(lo<hi){unsigned mid=lo+(hi-lo)/2;if(records[mid]<=a)lo=mid+1;else hi=mid;}
   if(lo&&a-records[lo-1]<336){unsigned i=lo-1;if(installed[i])++reads_after;else ++reads_before;hit(pc,0,(unsigned)(a-records[i]),w);}
  }
 }
 return result;
}
uint32_t wrapper_kg_integrity_fold(uint64_t b,uint32_t x,int*ok){
 static uint32_t(*f)(uint64_t,uint32_t,int*);if(!f)f=resolve("wrapper_kg_integrity_fold");++folds;
 if(active)for(unsigned j=0;j<9;++j)fold_site_calls[j]+=active->cpu.pc==UINT64_C(0x10000000)+fold_sites[j];
 uint32_t value;if(getenv("AMS_ZERO_FOLD")){*ok=b>=UINT64_C(0x100dc000)&&b<=UINT64_C(0x10664000)&&!((b-UINT64_C(0x100dc000))&4095);value=0;}else value=f(b,x,ok);
 if(active&&active->cpu.pc==UINT64_C(0x101b65fb)){keys[current]=value;++setup_folds;}
 return value;
}
int wrapper_kg_ckc_integrity_pair(uint64_t a,uint64_t b,uint8_t*out){
 static int(*f)(uint64_t,uint64_t,uint8_t*);if(!f)f=resolve("wrapper_kg_ckc_integrity_pair");++pair_calls;
 if(!getenv("AMS_ZERO_PAIR"))return f(a,b,out);
 if(!out||a<UINT64_C(0x100dc000)||a>=UINT64_C(0x1066c008)||b<UINT64_C(0x100dc000)||b>=UINT64_C(0x1066c008))return 0;
 if(b!=a+2&&b!=a-32766)return 0;*out=0;return 1;
}
int wrapper_kg_native_run(uint64_t b,wrapper_kg_native_state*s,const wrapper_kg_payload_region*r,size_t n,size_t budget,const wrapper_kg_payload_imports*imports){
 static int(*f)(uint64_t,wrapper_kg_native_state*,const wrapper_kg_payload_region*,size_t,size_t,const wrapper_kg_payload_imports*);if(!f)f=resolve("wrapper_kg_native_run");
 active=s;int result=f(b,s,r,n,budget,imports);active=0;++boundaries;
 int changed=0;for(unsigned i=0;i<slots;++i)if(installed[i]){const unsigned char*p=memory(r,n,records[i],336);if(!p)abort();
  for(unsigned k=0;k<336;++k)if(previous[i][k]!=p[k]){++changed_bytes;changed=1;}
  memcpy(previous[i],p,336);
 }changed_boundaries+=changed;return result;
}
__attribute__((destructor))static void done(void){
 fprintf(stderr,"REGISTRY_REPORT {\"initialized\":%u,\"installed\":%u,\"folds\":%u,\"setup_folds\":%u,\"pointer_model_matches\":%u,\"record_model_matches\":%u,\"model_rekey_roundtrips\":%u,\"registry_reads\":%lu,\"record_reads_before_install\":%lu,\"record_reads_after_install\":%lu,\"native_boundaries\":%lu,\"record_mutation_boundaries\":%lu,\"record_mutation_bytes\":%lu,\"sites\":[",initialized,stores,folds,setup_folds,pointer_matches,record_matches,rekeys,registry_reads,reads_before,reads_after,boundaries,changed_boundaries,changed_bytes);
 for(unsigned j=0;j<nsites;++j)fprintf(stderr,"%s{\"pc\":\"0x%llx\",\"registry_reads\":%lu,\"record_reads\":%lu,\"record_bytes\":%lu,\"offset_start\":%u,\"offset_end\":%u}",j?",":"",(unsigned long long)sites[j].pc,sites[j].registry,sites[j].record,sites[j].bytes,sites[j].min,sites[j].max);
 fprintf(stderr,"],\"bulk_record_read_permissions\":%lu,\"bulk_registry_read_permissions\":%lu,\"pair_calls\":%lu,\"image_read_coverage\":[",bulk_record_reads,bulk_registry_reads,pair_calls);
 for(unsigned j=0;j<4;++j)fprintf(stderr,"%s{\"base\":\"0x%llx\",\"size\":%zu,\"reads\":%lu,\"distinct_read_addresses\":%lu}",j?",":"",(unsigned long long)image_starts[j],image_sizes[j],image_reads[j],image_unique[j]);
 fprintf(stderr,"],\"synthetic_generation_reservations\":%u,\"operation_read_sites\":[",synthetic_reservations);
 for(unsigned j=0;j<operation_nsites;++j)fprintf(stderr,"%s{\"pc\":\"0x%llx\",\"operation_mask\":%u}",j?",":"",(unsigned long long)operation_sites[j],operation_masks[j]);
 fprintf(stderr,"],\"fold_sites\":[");
 for(unsigned j=0;j<9;++j)fprintf(stderr,"%s{\"pc\":\"0x%llx\",\"calls\":%lu}",j?",":"",(unsigned long long)fold_sites[j],fold_site_calls[j]);
 fprintf(stderr,"]}\n");
}
'''

WORKER_WAKE = r'''
/* Temporary oracle only: enter the REAL saved worker continuation after the
 * original host deadline. Parent APIs retain all their original expiry guards.
 * The reused execute loop also retains its unsupported-early-return guard.
 */
extern void ams_registry_operation_phase(unsigned);
unsigned ams_registry_worker_state(const kg_runtime*r){return r?!!r->worker_pending|((unsigned)!!r->worker_active<<1)|((unsigned)!!r->worker_sleeping<<2):0;}
int ams_registry_worker_wake(kg_runtime*r,wrapper_kg_spc_result*result){
 if(!r||!result||!r->worker_sleeping)return -1;
 memset(result,0,sizeof *result);
 uint64_t now=kg_steady();if(!now||now<r->worker_wake)return -5;
 r->parent_state=r->state;r->state=r->worker_state;r->worker_active=1;r->worker_sleeping=0;r->result=result;
 ams_registry_operation_phase(1);int ok=ams_worker_continue(r);ams_registry_operation_phase(0);
 result->pc=r->state.cpu.pc;result->fault_address=r->state.cpu.fault_address;result->fault_size=r->state.cpu.fault_size;
 if(!ok)return -3;
 return r->worker_sleeping&&!r->worker_active?0:-4;
}
'''

REGISTRY_DISPATCH = r'''
/* Developer-only direct invocation with invented context handles. Retains the
 * existing deadline check; this is not the session API's acquired-context path.
 * No context_handle is installed and no timer/validation guard is disabled. */
extern void ams_registry_operation_phase(unsigned);
extern int ams_registry_seed_invented(const wrapper_kg_payload_region*,size_t);
extern int ams_registry_canonical(const wrapper_kg_payload_region*,size_t,unsigned char*,size_t);
int ams_registry_snapshot(kg_runtime*r,unsigned char*out,size_t size){return r?ams_registry_canonical(r->regions,KG_REGIONS,out,size):0;}
int ams_registry_invented_slot(kg_runtime*r){return r?ams_registry_seed_invented(r->regions,KG_REGIONS):0;}
int ams_registry_dispatch(kg_runtime *r,uint32_t token,uint64_t handle,wrapper_kg_spc_result *result){
 unsigned char *packet;int status;
 if(!r||!result)return -1;
 memset(result,0,sizeof *result);
 if(r->worker_sleeping){uint64_t now=kg_steady();if(!now||now>=r->worker_wake)return -5;}
 r->result=result;packet=kg_memory(r,KG_HEAP+0x7000,WRAPPER_KG_CKC_PACKET_SIZE,3);
 if(!packet)return -3;
 if(token==WRAPPER_KG_CONTEXT_FINALIZE_TOKEN)status=wrapper_kg_context_finalize_packet(packet,WRAPPER_KG_CKC_PACKET_SIZE,handle);
 else if(token==WRAPPER_KG_CONTEXT_DECRYPT_TOKEN){
  unsigned char *p=kg_memory(r,KG_HEAP+0x6000,16,2);if(!p)return -3;memset(p,0,16);
  status=wrapper_kg_context_decrypt_packet(packet,WRAPPER_KG_CKC_PACKET_SIZE,handle,5,KG_HEAP+0x6000,KG_HEAP+0x6100,16);
 }else return -1;
 if(status)return -3;
 ams_registry_operation_phase(1);status=kg_context_dispatch(r,token,packet,result);ams_registry_operation_phase(0);return status;
}
'''

PROGRAM = r'''
import ctypes,json,os,random,struct,sys
sys.path.insert(0,sys.argv[1]+'/tools/crypto/keygen_experimental')
sys.path.insert(0,sys.argv[1]+'/python/apple-music-source/scripts')
from source_protocol import generate,SourceSession,SourceSessionError
from registry_consumer_oracle import RegistryConsumerOracle
oracle=RegistryConsumerOracle(sys.argv[1]+'/rootfs/system/lib64/libCoreLSKD.so')
errors=[]
Callback=ctypes.CFUNCTYPE(None,ctypes.c_uint,ctypes.c_uint64,ctypes.c_uint32,ctypes.c_uint64,ctypes.c_void_p,ctypes.c_void_p)
def observe(index,address,key,encoded_pointer,plain,encoded):
 try:oracle.check(index,address,key,encoded_pointer,ctypes.string_at(plain,336),ctypes.string_at(encoded,336))
 except Exception as e:errors.append(type(e).__name__)
callback=Callback(observe)
shim=ctypes.CDLL(sys.argv[4]);shim.ams_registry_set_observer.argtypes=[Callback];shim.ams_registry_set_observer(callback)
rng=random.Random(0xF01D)
def entropy(_,p,n):
 for j in range(n):p[j]=rng.randrange(256)
 return 0
ticks=[0]
def clock(_):
 ticks[0]+=1
 return 0x1234567800000000+ticks[0]*100003
def wall(_,s,u):
 s[0]=1700000000;u[0]=123456
 return 0
certificate=bytes(int(sys.argv[3]))
if os.environ.get('AMS_CERTIFICATE_FIXTURE'):
 # Read only the public certificate field. Seek over account/content/SPC
 # fields without loading them; no captured exchange/credential input is used.
 with open(os.environ['AMS_CERTIFICATE_FIXTURE'],'rb') as f:
  head=f.read(24)
  assert head[:4]==b'RCP1'
  operation,status,ns,nb=struct.unpack_from('<IqII',head,4)
  assert operation==1 and ns<=32 and nb<=32
  f.seek(ns*12,1);certificate=None
  for _ in range(nb):
   field,size=struct.unpack('<II',f.read(8));assert size<=1024*1024
   if field==1:
    assert certificate is None
    certificate=f.read(size);assert len(certificate)==size
   else:f.seek(size,1)
  assert certificate is not None
context_attempt=None
registry_operations=[]
canonical_snapshots=[]
canonical_deltas=[]
worker_wake=None
if os.environ.get('AMS_CONTEXT_ZERO_SIZE') or os.environ.get('AMS_REGISTRY_OPERATIONS'):
 with SourceSession(sys.argv[2],0,certificate,b'invented-registry-lifetime',bytes(range(16)),entropy=entropy,clock=clock,time=wall,format_version=1) as session:
  o,r=session.spc,session.result;s=0
  if os.environ.get('AMS_REGISTRY_OPERATIONS'):
   from source_protocol import Result
   dispatch=session.lib.ams_registry_dispatch
   dispatch.argtypes=[ctypes.c_void_p,ctypes.c_uint32,ctypes.c_uint64,ctypes.POINTER(Result)]
   dispatch.restype=ctypes.c_int
   snapshot=session.lib.ams_registry_snapshot
   snapshot.argtypes=[ctypes.c_void_p,ctypes.c_void_p,ctypes.c_size_t];snapshot.restype=ctypes.c_int
   def capture():
    output=ctypes.create_string_buffer(1024*340)
    assert snapshot(session.handle,output,len(output))==1,'registry is not in the checked encoded representation'
    current=bytes(output)
    if canonical_snapshots:
     previous=canonical_snapshots[-1];tag_slots=[];record_slots=[];offsets=set();changed=0
     for slot in range(1024):
      at=slot*340
      if current[at:at+4]!=previous[at:at+4]:tag_slots.append(slot)
      differences=[i for i in range(336) if current[at+4+i]!=previous[at+4+i]]
      if differences:record_slots.append(slot);offsets.update(differences);changed+=len(differences)
     canonical_deltas.append(dict(tag_slots=tag_slots,record_slots=record_slots,record_byte_offsets=sorted(offsets),record_bytes_changed=changed))
    canonical_snapshots.append(current)
   capture()
   # Recovered initialized-slot tags. These are invented handles, not CKC
   # acquired contexts. Invoke the original dispatcher; do not override its
   # record validation, lifetime deadline, shadows, faults or budgets.
   for token,handle in ((0x68df9ab6,0),(0x68df9ab6,0x53ea9dad),(0x68df9ab6,0x53ea9dad),(0xdf65877e,0x53ea9dad),(0x68df9ab6,0x51dc9294),(0x68df9ab6,0xffffffff)):
    result=Result();api=dispatch(session.handle,token,handle,ctypes.byref(result))
    capture()
    registry_operations.append(dict(token=hex(token),invented_handle=hex(handle),api=api,status=result.status,pc=hex(result.pc),fault_address=hex(result.fault_address),fault_size=result.fault_size,steps=result.source_steps,clock_calls=result.clock_calls))
   # A SYNTHETIC reserved generation over an otherwise default setup record.
   # This is fixture construction, not valid CKC processing or a context claim.
   reserve=session.lib.ams_registry_invented_slot
   reserve.argtypes=[ctypes.c_void_p];reserve.restype=ctypes.c_int
   assert reserve(session.handle)==1
   capture()
   for token in (0x68df9ab6,0x68df9ab6,0xdf65877e):
    result=Result();api=dispatch(session.handle,token,1,ctypes.byref(result))
    capture()
    registry_operations.append(dict(token=hex(token),synthetic_reserved_generation=True,api=api,status=result.status,pc=hex(result.pc),fault_address=hex(result.fault_address),fault_size=result.fault_size,steps=result.source_steps,clock_calls=result.clock_calls))
   if os.environ.get('AMS_WORKER_WAKE'):
    state=session.lib.ams_registry_worker_state
    state.argtypes=[ctypes.c_void_p];state.restype=ctypes.c_uint
    flags=state(session.handle)
    worker_wake=dict(pending=bool(flags&1),active=bool(flags&2),sleeping=bool(flags&4),attempted=False)
    if flags&4:
     import time
     time.sleep(5.02)
     # Invented TSC input advances with deliberately elapsed host sleep.
     # Parent reuse guards remain unchanged; resume the saved worker only.
     ticks[0]+=50000
     wake=session.lib.ams_registry_worker_wake
     wake.argtypes=[ctypes.c_void_p,ctypes.POINTER(Result)];wake.restype=ctypes.c_int
     result=Result();api=wake(session.handle,ctypes.byref(result))
     worker_wake.update(attempted=True,api=api,status=result.status,pc=hex(result.pc),fault_address=hex(result.fault_address),fault_size=result.fault_size,steps=result.source_steps,clock_calls=result.clock_calls)
    capture()
  elif os.environ.get('AMS_CONTEXT_ZERO_SIZE'):
   try:
    context=session.context(bytes(int(os.environ['AMS_CONTEXT_ZERO_SIZE'])))
    context_attempt=dict(api=0,nonzero_context=bool(context))
   except SourceSessionError as e:
    context_attempt=dict(api=e.status,status=e.result.status,pc=e.result.pc,fault_address=e.result.fault_address,fault_size=e.result.fault_size,source_steps=e.result.source_steps)
else:
 s,o,r=generate(sys.argv[2],0,certificate,b'invented-registry-lifetime',bytes(range(16)),entropy=entropy,clock=clock,time=wall)
if os.environ.get('AMS_OUTPUT_FD'):
 data=memoryview(o+b''.join(canonical_snapshots))
 while data:
  written=os.write(int(os.environ['AMS_OUTPUT_FD']),data);assert written>0;data=data[written:]
assert not errors,errors
assert oracle.records==8 and oracle.executions==24 and oracle.mismatched_seed_controls==8
print(json.dumps(dict(api=dict(api=s,output_size=len(o),status=r.status,pc=r.pc,source_steps=r.source_steps,clock_calls=r.clock_calls,certificate_size=len(certificate)),context_attempt=context_attempt,registry_operations=registry_operations,canonical_deltas=canonical_deltas,worker_wake=worker_wake,canonical_snapshot_count=len(canonical_snapshots),canonical_snapshot_size=1024*340,consumer_oracle=dict(records=oracle.records,executions=oracle.executions,mismatched_seed_controls=oracle.mismatched_seed_controls,scope='actual setup records decoded by original codec; synthetic mutation then original encode/decode under alternate representation; no application mutation-lifetime proof'))))
'''


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('checkout', type=Path)
    p.add_argument('--output', type=Path, required=True)
    p.add_argument('--certificate-size', type=int, default=32, choices=(1, 32, 128))
    p.add_argument('--public-certificate-fixture', type=Path, help='Read only public certificate field from RCP1; skip all other fields')
    p.add_argument('--compare-zero-fold', action='store_true', help='Test a continuous zero-fold representation hypothesis; not a production replacement')
    p.add_argument('--compare-zero-pair', action='store_true', help='Also test zero paired-byte values with original range/relation rejection guards')
    p.add_argument('--worker-wake',action='store_true',help='After invented registry operations, wait for the real deadline and resume only the saved worker in a temporary oracle')
    p.add_argument('--registry-operations', action='store_true', help='Invoke original finalize/decrypt dispatcher on invented handles, without treating them as acquired contexts')
    p.add_argument('--context-zero-size', type=int, choices=(32, 128, 876), help='After FPS-format SPC creation, submit an invented all-zero CKC; rejection is expected')
    a = p.parse_args()
    root = a.checkout.resolve()
    source = root / 'crypto/keygen_experimental'
    build = root / 'build/spc-payload'
    with tempfile.TemporaryDirectory(prefix='ams-registry-') as temporary:
        t = Path(temporary)
        page = (source / 'native_generated/block_page_1b.c').read_text()
        page = page.replace('#include "../spc_native_internal.h"', '#include "spc_native_internal.h"\nextern void ams_registry_event(unsigned,wrapper_kg_native_state*,const wrapper_kg_payload_region*,size_t);', 1)
        for pc, event in (('1b6406', 1), ('1b65fb', 0), ('1b630f', 2)):
            marker = f'kg_pc_{pc}: STEP(0x{pc});'
            assert page.count(marker) == 1
            page = page.replace(marker, marker + f' ams_registry_event({event},fs,regions,count);')
        (t / 'page.c').write_text(page)
        (t / 'shim.c').write_text(SHIM)
        subprocess.run(['cc', '-std=c99', '-O0', '-shared', '-fPIC', '-I'+str(source), str(t/'page.c'), str(t/'shim.c'), str(Path(__file__).resolve().parents[1]/'src/apple_music_source/_native/registry.c'), '-I'+str(Path(__file__).resolve().parents[1]/'src/apple_music_source/_native'), '-ldl', '-o', str(t/'trace.so')], check=True, capture_output=True)
        # Native scalar reads do not cover host memcpy/memmove/service accesses.
        # Observe every successful read-capable kg_memory translation too. This
        # deliberately overcounts read+write translations used only for writes.
        generator=(source/'spc_generate.c').read_text()
        marker='return translate(r->regions,KG_REGIONS,at,size,permission);'
        assert generator.count(marker)==1
        generator=generator.replace(marker,'unsigned char *p=translate(r->regions,KG_REGIONS,at,size,permission);\n    if(p)ams_registry_bulk_access(at,size,permission);return p;')
        generator=generator.replace('#define KG_CORE', 'extern void ams_registry_bulk_access(uint64_t,size_t,unsigned);\n#define KG_CORE',1)
        if a.worker_wake:
            if not a.registry_operations:
                p.error('worker wake requires invented registry operations')
            start=generator.index('    for(;;){\n        int status;',generator.index('static int kg_execute'))
            end=generator.index('\nstatic int kg_generate',start)
            worker='static int ams_worker_continue(kg_runtime*r){wrapper_kg_payload_state*s=&r->state.cpu;\n'+generator[start:end]
            generator+=worker+WORKER_WAKE
        if a.registry_operations:
            generator += REGISTRY_DISPATCH
        (t/'generate.c').write_text(generator)
        subprocess.run(['cc','-std=c99','-O1','-shared','-fPIC','-I'+str(source),str(t/'generate.c'),str(source/'ckc_packet.c'),'-L'+str(build),'-lwrapper_spc_native','-Wl,-rpath,'+str(build),'-o',str(t/'generate.so')],check=True,capture_output=True)
        env = dict(os.environ, LD_PRELOAD=str(t/'trace.so'), AMS_NATIVE=str(build/'libwrapper_spc_native.so'))
        env.pop('AMS_ZERO_FOLD', None)
        env.pop('AMS_ZERO_PAIR', None)
        for name in ('AMS_CONTEXT_ZERO_SIZE','AMS_REGISTRY_OPERATIONS','AMS_CERTIFICATE_FIXTURE','AMS_WORKER_WAKE'):
            env.pop(name,None)
        if a.public_certificate_fixture:
            env['AMS_CERTIFICATE_FIXTURE'] = str(a.public_certificate_fixture.resolve())
        if a.worker_wake:env['AMS_WORKER_WAKE']='1'
        if a.registry_operations:
            if not a.public_certificate_fixture or a.context_zero_size:
                p.error('registry operations require public certificate and no context-zero-size')
            env['AMS_REGISTRY_OPERATIONS']='1'
        if a.context_zero_size:
            if not a.public_certificate_fixture:
                p.error('context probe requires a public certificate fixture')
            env['AMS_CONTEXT_ZERO_SIZE'] = str(a.context_zero_size)
        runs, outputs, canonical_outputs = [], [], []
        modes=['baseline']
        if a.compare_zero_fold:modes.append('zero_fold')
        if a.compare_zero_pair:modes.append('zero_pair')
        if a.compare_zero_fold and a.compare_zero_pair:modes.append('zero_both')
        for mode in modes:
            read_fd, write_fd = os.pipe()
            chunks=[]
            def drain():
                try:
                    while True:
                        chunk=os.read(read_fd,65536)
                        if not chunk:break
                        chunks.append(chunk)
                finally:os.close(read_fd)
            reader=threading.Thread(target=drain)
            reader.start()
            try:
                child_env = dict(env, AMS_OUTPUT_FD=str(write_fd))
                if mode in ('zero_fold','zero_both'):
                    child_env['AMS_ZERO_FOLD'] = '1'
                if mode in ('zero_pair','zero_both'):
                    child_env['AMS_ZERO_PAIR'] = '1'
                result = subprocess.run([sys.executable, '-s', '-c', PROGRAM, str(root), str(t/'generate.so'), str(a.certificate_size), str(t/'trace.so')], capture_output=True, text=True, check=True, timeout=120, env=child_env, pass_fds=(write_fd,))
            finally:
                os.close(write_fd)
                reader.join()
            output=b''.join(chunks)
            lines = [line[len('REGISTRY_REPORT '):] for line in result.stderr.splitlines() if line.startswith('REGISTRY_REPORT ')]
            assert len(lines) == 1
            trace = json.loads(lines[0])
            assert trace['installed'] == trace['initialized'] == trace['setup_folds'] == 1024
            assert trace['pointer_model_matches'] == trace['record_model_matches'] == trace['model_rekey_roundtrips'] == 1024
            checked = json.loads(result.stdout)
            spc_size=checked['api']['output_size']
            assert len(output)==spc_size+checked['canonical_snapshot_count']*checked['canonical_snapshot_size']
            canonical_outputs.append(output[spc_size:]);output=output[:spc_size]
            runs.append(dict(mode=mode, **checked, trace=trace))
            outputs.append(output)
        report = dict(fixture='public certificate field only; otherwise invented inputs' if a.public_certificate_fixture else f'invented {a.certificate_size}-zero-byte certificate; deterministic entropy/time', **{k:v for k,v in runs[0].items() if k!='mode'},
                      scope='offline source-runtime SPC, optional invalid CKC, or invented-handle operations with one explicitly synthetic reserved generation and stored record handle; canonical records compared in RAM only at operation boundaries; no production bank replacement, valid CKC/key acquisition, worker expiry, arbitrary aliases/faults or instruction-budget proof')
        for i in range(1,len(runs)):
            name=runs[i]['mode']+'_hypothesis'
            report[name] = dict(run=runs[i], nonempty_output_equal=bool(outputs[0]) and outputs[0] == outputs[i], status_equal=runs[0]['api']['api'] == runs[i]['api']['api'] and runs[0]['api']['status'] == runs[i]['api']['status'])
            report[name]['registry_operations_equal'] = runs[0]['registry_operations'] == runs[i]['registry_operations']
            report[name]['canonical_snapshots_equal'] = canonical_outputs[0] == canonical_outputs[i]
            report[name]['worker_wake_equal'] = runs[0]['worker_wake'] == runs[i]['worker_wake']
            report[name]['canonical_deltas_equal'] = runs[0]['canonical_deltas'] == runs[i]['canonical_deltas']
            report[name]['canonical_snapshot_count_equal'] = runs[0]['canonical_snapshot_count'] == runs[i]['canonical_snapshot_count']
            report[name]['limitation'] = 'equal rejection does not prove equivalence; encoded representation differs and full record/application consumer closure is unproved'
        a.output.write_text(json.dumps(report, indent=2)+'\n')
        print(json.dumps(dict(api=report['api'], context_attempt=report['context_attempt'], counts={k:v for k,v in report['trace'].items() if k not in ('sites','operation_read_sites')}, sites=len(report['trace']['sites']), hypotheses={k:dict(api=v['run']['api'],context_attempt=v['run']['context_attempt'],nonempty_output_equal=v['nonempty_output_equal']) for k,v in report.items() if k.endswith('_hypothesis')})))


if __name__ == '__main__':
    main()
