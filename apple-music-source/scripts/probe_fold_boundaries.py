"""Offline, invented-input full-state test of fold cancellation at import yields.

No oracle bytes or state snapshots are retained. The original source runtime is
an offline oracle only; candidate runs use cloned regions and complete native
state. This deliberately tests a hypothesis, not a shipping replacement.
"""
import argparse
import json
import os
from pathlib import Path
import subprocess
import sys
import tempfile

SHIM = r'''
#define _GNU_SOURCE
#include "spc_native.h"
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static wrapper_kg_native_state *active;
static int candidate;
static unsigned long calls, affected, equal, regdiff, flagdiff, shadowdiff, simddiff, memdiff, flowdiff, folds, identities;
static unsigned long site_calls[9];
static const uint64_t sites[9]={0x1b65fb,0x207b91,0x23915b,0x3ede57,0x3ee66f,0x4b7898,0x4bc9da,0x50cb28,0x50d8b3};
static void *resolve(const char *name){void *h=dlopen(getenv("AMS_NATIVE"),RTLD_NOW|RTLD_NOLOAD);if(!h)abort();void *p=dlsym(h,name);if(!p)abort();return p;}
uint32_t wrapper_kg_integrity_fold(uint64_t b,uint32_t x,int *ok){
 static uint32_t(*f)(uint64_t,uint32_t,int*);if(!f)f=resolve("wrapper_kg_integrity_fold");
 uint32_t y=f(b,x,ok);
 if(!candidate){++folds;identities+=x==y;if(active)for(unsigned j=0;j<9;++j)site_calls[j]+=active->cpu.pc==0x10000000+sites[j];}
 return candidate&&*ok?x:y;
}
int wrapper_kg_native_run(uint64_t bias,wrapper_kg_native_state *s,const wrapper_kg_payload_region *r,size_t n,size_t budget,const wrapper_kg_payload_imports *imports){
 static int(*f)(uint64_t,wrapper_kg_native_state*,const wrapper_kg_payload_region*,size_t,size_t,const wrapper_kg_payload_imports*);
 if(!f)f=resolve("wrapper_kg_native_run");
 wrapper_kg_native_state copy=*s;
 wrapper_kg_payload_region *rr=calloc(n,sizeof *rr);if(!rr)abort();
 /* Preserve host aliases, not just virtual addresses. All overlapping host
  * spans must share a single clone. Current generator regions are disjoint;
  * reject overlap rather than accidentally changing alias semantics. */
 for(size_t j=0;j<n;++j){for(size_t k=0;k<j;++k)if(r[j].size&&r[k].size&&(uintptr_t)r[j].data<(uintptr_t)r[k].data+r[k].size&&(uintptr_t)r[k].data<(uintptr_t)r[j].data+r[j].size)abort();rr[j]=r[j];rr[j].data=malloc(r[j].size?r[j].size:1);if(!rr[j].data)abort();memcpy(rr[j].data,r[j].data,r[j].size);}
 unsigned long before=folds;
 active=s;int status=f(bias,s,r,n,budget,imports);active=0;++calls;
 if(folds!=before){
  ++affected;candidate=1;active=&copy;int other=f(bias,&copy,rr,n,budget,imports);active=0;candidate=0;
  int rd=memcmp(s->cpu.gpr,copy.cpu.gpr,sizeof copy.cpu.gpr)!=0;
  int fd=s->cpu.flags!=copy.cpu.flags;
  int sd=memcmp(&s->ckc_shadow_slot,&copy.ckc_shadow_slot,sizeof copy-(size_t)((char*)&copy.ckc_shadow_slot-(char*)&copy))!=0;
  int xd=memcmp(s->xmm,copy.xmm,sizeof copy.xmm)!=0||s->tls_base!=copy.tls_base;
  int md=0;size_t changed=0;for(size_t j=0;j<n;++j)for(size_t k=0;k<r[j].size;++k)if(r[j].data[k]!=rr[j].data[k]){md=1;++changed;}
  int flow=status!=other||s->cpu.pc!=copy.cpu.pc||s->cpu.steps!=copy.cpu.steps||s->cpu.fault_address!=copy.cpu.fault_address||s->cpu.fault_size!=copy.cpu.fault_size;
  regdiff+=rd;flagdiff+=fd;shadowdiff+=sd;simddiff+=xd;memdiff+=md;flowdiff+=flow;equal+=!(rd||fd||sd||xd||md||flow);
  if(affected<=8)fprintf(stderr,"BOUNDARY {\"entry_fold_calls\":%lu,\"baseline_pc\":%llu,\"candidate_pc\":%llu,\"changed_memory_bytes\":%zu,\"gpr_equal\":%d,\"flags_equal\":%d,\"shadow_equal\":%d,\"simd_tls_equal\":%d,\"flow_fault_budget_equal\":%d}\n",folds-before,(unsigned long long)s->cpu.pc,(unsigned long long)copy.cpu.pc,changed,!rd,!fd,!sd,!xd,!flow);
 }
 for(size_t j=0;j<n;++j)free(rr[j].data);free(rr);return status;
}
__attribute__((destructor))static void done(void){fprintf(stderr,"FOLD_REPORT {\"native_boundaries\":%lu,\"affected_boundaries\":%lu,\"full_state_equal\":%lu,\"gpr_differences\":%lu,\"flags_differences\":%lu,\"shadow_differences\":%lu,\"simd_tls_differences\":%lu,\"memory_differences\":%lu,\"flow_fault_budget_differences\":%lu,\"fold_calls\":%lu,\"identity_outputs\":%lu,\"sites\":[",calls,affected,equal,regdiff,flagdiff,shadowdiff,simddiff,memdiff,flowdiff,folds,identities);for(unsigned j=0;j<9;++j)fprintf(stderr,"%s{\"pc\":%llu,\"calls\":%lu}",j?",":"",(unsigned long long)sites[j],site_calls[j]);fprintf(stderr,"]}\n");}
'''
PROGRAM = r'''
import json,random,sys
sys.path.insert(0,sys.argv[1]+'/tools/crypto/keygen_experimental')
from source_protocol import generate
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
s,o,r=generate(sys.argv[2],0,bytes(32),b'invented-fold-boundary',bytes(range(16)),entropy=entropy,clock=clock,time=wall)
print(json.dumps(dict(api=s,output_size=len(o),status=r.status,pc=r.pc,source_steps=r.source_steps,clock_calls=r.clock_calls)))
'''

def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('checkout',type=Path)
    p.add_argument('--output',type=Path,required=True)
    a=p.parse_args();root=a.checkout.resolve();build=root/'build/spc-payload'
    with tempfile.TemporaryDirectory(prefix='ams-fold-boundaries-') as t:
        t=Path(t);(t/'shim.c').write_text(SHIM)
        subprocess.run(['cc','-std=c99','-O2','-shared','-fPIC','-I'+str(root/'crypto/keygen_experimental'),str(t/'shim.c'),'-ldl','-o',str(t/'shim.so')],check=True)
        env=dict(os.environ,LD_PRELOAD=str(t/'shim.so'),AMS_NATIVE=str(build/'libwrapper_spc_native.so'))
        r=subprocess.run([sys.executable,'-S','-c',PROGRAM,str(root),str(build/'libwrapper_spc_generate.so')],env=env,capture_output=True,text=True,check=True,timeout=120)
        boundaries=[];summary=None
        for line in r.stderr.splitlines():
            if line.startswith('BOUNDARY '):boundaries.append(json.loads(line[9:]))
            if line.startswith('FOLD_REPORT '):summary=json.loads(line[12:])
        assert summary and summary['fold_calls'] and summary['affected_boundaries']
        report=dict(hypothesis='replace folded value with input across complete native-run import/fault/limit boundaries',result='rejected' if summary['full_state_equal']!=summary['affected_boundaries'] else 'equal_on_fixture_only',fixture='invented 32 zero certificate; deterministic entropy/time',api=json.loads(r.stdout),summary=summary,boundaries=boundaries,scope='offline source runtime oracle; no production substitution; other banks retained')
        a.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))
if __name__=='__main__':main()
