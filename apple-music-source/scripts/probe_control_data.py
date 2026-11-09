"""Classify pristine data reads as recoverable source control references.

Developer-only source-runtime oracle. It uses invented SPC inputs, optionally
reading ONLY a public certificate field. Raw data words never enter a report.
Only a reversible load/add chain to an indirect transfer or checked same-frame
stored call and a decoded source destination is accepted. Optional writable
slots must be unresolved local RELATIVE relocations matching pristine linking;
named imports and mutated data cannot be admitted by that extension. This is not
a complete image closure, reachability proof, or installed-package validation.
"""
import argparse
import bisect
import ctypes as C
import hashlib
import json
import os
from pathlib import Path
import random
import re
import struct
import subprocess
import sys
import tempfile

from verify_integrity_codec import HASH
from verify_fill_dispatch import APP_HASH, segment_read


SHIM = r'''
#define _GNU_SOURCE
#include "spc_native.h"
#include <dlfcn.h>
#include <stdint.h>
#include <stdlib.h>
typedef int (*observer_fn)(uint64_t,uint64_t,unsigned,uint64_t,const uint64_t*);
typedef struct {uint64_t pc,address;unsigned width,used,control;uint64_t reads;} entry;
static entry *entries;
static wrapper_kg_native_state *active;
static observer_fn observer;
static uint64_t reads,unique,control_reads,overflow;
enum { CAPACITY=1<<20 };
#ifndef AMS_CONTROL_RW
#define AMS_CONTROL_RW 0
#endif
#ifndef AMS_ENTRY_PACKETS
#define AMS_ENTRY_PACKETS 0
#endif
void ams_control_observer(observer_fn fn){observer=fn;}
void ams_control_counts(uint64_t out[4]){out[0]=reads;out[1]=unique;out[2]=control_reads;out[3]=overflow;}
static void *real(const char *name){
 void *h=dlopen(getenv("AMS_NATIVE"),RTLD_NOW|RTLD_NOLOAD);
 void *p=h?dlsym(h,name):0;if(!p)abort();return p;
}
int wrapper_kg_native_run(uint64_t bias,wrapper_kg_native_state *state,
 const wrapper_kg_payload_region *regions,size_t count,size_t budget,
 const wrapper_kg_payload_imports *bindings){
 static int (*run)(uint64_t,wrapper_kg_native_state*,const wrapper_kg_payload_region*,size_t,size_t,const wrapper_kg_payload_imports*);
 if(!run)run=real("wrapper_kg_native_run");
 wrapper_kg_native_state *previous=active;active=state;
 int status=run(bias,state,regions,count,budget,bindings);active=previous;return status;
}
int wrapper_kg_native_read(const wrapper_kg_payload_region *regions,size_t count,uint64_t address,unsigned width,uint64_t *out){
 static int (*read_word)(const wrapper_kg_payload_region*,size_t,uint64_t,unsigned,uint64_t*);
 if(!read_word)read_word=real("wrapper_kg_native_read");
 int ok=read_word(regions,count,address,width,out);if(!ok||!active||!observer)return ok;
 if(width!=4&&width!=8)return ok;
 int pristine=0;
 for(size_t j=0;j<count;++j)if((regions[j].permissions==1||
  (AMS_CONTROL_RW&&regions[j].permissions==3&&(regions[j].address==UINT64_C(0x5be7c0)||regions[j].address==UINT64_C(0x1066d000))))&&address>=regions[j].address&&
  width<=regions[j].size&&address-regions[j].address<=regions[j].size-width){pristine=1;break;}
 uint64_t pc=active->cpu.pc;
 int is_entry=AMS_ENTRY_PACKETS&&(pc==UINT64_C(0x10526be8)||pc==UINT64_C(0x10530998)||pc==UINT64_C(0x10526e0a)||pc==UINT64_C(0x10530bb9));
 if(AMS_ENTRY_PACKETS&&!is_entry)return ok;
 if(!pristine&&!is_entry)return ok;
 ++reads;if(!entries)entries=calloc(CAPACITY,sizeof *entries);if(!entries)abort();
 size_t k=(size_t)((pc*UINT64_C(0x9e3779b97f4a7c15))^(address*UINT64_C(0x1000193))^width)&(CAPACITY-1),start=k;
 while(entries[k].used&&(entries[k].pc!=pc||entries[k].address!=address||entries[k].width!=width)){
  k=(k+1)&(CAPACITY-1);if(k==start){++overflow;return ok;}}
 entry *e=entries+k;
 if(!e->used){e->used=1;e->pc=pc;e->address=address;e->width=width;++unique;
  e->control=observer(pc,address,width,*out,active->cpu.gpr)!=0;}
 ++e->reads;if(e->control)++control_reads;return ok;
}
'''


def register(name):
    aliases={'eax':'rax','ax':'rax','al':'rax','ebx':'rbx','bx':'rbx','bl':'rbx',
             'ecx':'rcx','cx':'rcx','cl':'rcx','edx':'rdx','dx':'rdx','dl':'rdx',
             'edi':'rdi','esi':'rsi','ebp':'rbp','esp':'rsp'}
    if name in aliases:return aliases[name]
    if re.fullmatch(r'r\d+[dwb]',name):return name[:-1]
    return name


class Classifier:
    def __init__(self,root,include_pristine_rw=False):
        from capstone import Cs, CS_ARCH_X86, CS_MODE_64
        self.decoder=Cs(CS_ARCH_X86,CS_MODE_64);self.decoder.detail=True
        self.images=[];self.labels=set();self.cache={};self.rows=[];self.errors=[]
        self.root=root;self.include_pristine_rw=include_pristine_rw
        self.rw_images=[];self.relative_candidates=set();self.frame_call_pcs=[]
        self.function_ranges=[];self.frame_calls={};self.flow_ready=False
        for name,digest,bias,directory in [('libCoreLSKD.so',HASH,0x10000000,'native_generated'),
                                         ('libandroidappmusic.so',APP_HASH,0,'app_generated')]:
            raw=(root/'rootfs/system/lib64'/name).read_bytes()
            assert hashlib.sha256(raw).hexdigest()==digest
            self.images.append((bias,raw))
            for page in (root/'crypto/keygen_experimental'/directory).glob('block_*.c'):
                # App translations use STEP PCs without the Core runner's
                # kg_pc_ labels. Both are explicit source instruction identities.
                text=page.read_text()
                for pc in re.findall(r'STEP\(0x([0-9a-f]+)\)',text):
                    self.labels.add(bias+int(pc,16))
                self.frame_call_pcs += [bias+int(pc,16) for pc in re.findall(r'STEP\(0x([0-9a-f]+)\); /\* call qword ptr \[rbp[^\]]*\]',text)]
        manifest=json.loads((root/'tools/crypto/keygen_experimental/source_image_manifest.json').read_text())
        self.imports={0x800000+i*16:name for i,name in enumerate(manifest['services'])}
        self.readonly=[(m['address'],m['address']+m['size']) for m in manifest['images'] if m['permissions']==1]
        self.sorted_labels=sorted(self.labels)
        if include_pristine_rw:
            sys.path.insert(0,str(root/'tools/crypto/keygen_experimental'))
            from generate_source_images import module
            bindings={name:address for address,name in self.imports.items()}
            for name,digest,base in [('libandroidappmusic.so',APP_HASH,0),('libCoreLSKD.so',HASH,0x10000000)]:
                m=module(root/'rootfs/system/lib64'/name,digest,base);data=bytearray(m['rw'])
                for target,info,addend in m['relocs']:
                    kind,index=info&0xffffffff,info>>32
                    if kind==8:
                        value=base+addend
                        data_target=any(s[2]&2 and not(s[2]&4) and s[3]<=addend<s[3]+s[5] for s in m['sections'].values())
                        if value not in self.labels and not data_target:self.relative_candidates.add(base+target)
                    else:
                        symbol,value=m['symbols'][index]
                        value=(base+value if value else bindings[symbol])+addend
                    struct.pack_into('<Q',data,target-m['rw_lo'],value&((1<<64)-1))
                self.rw_images.append((base+m['rw_lo'],data))

    def pristine_read(self,address,width):
        for begin,end in self.readonly:
            if begin<=address and address+width<=end:
                bias,raw=self.images[0 if address>=0x10000000 else 1]
                return int.from_bytes(segment_read(raw,address-bias,width),'little')
        for begin,data in self.rw_images:
            if begin<=address and address+width<=begin+len(data):return int.from_bytes(data[address-begin:address-begin+width],'little')
        return None

    def prepare_flow_metadata(self):
        if self.flow_ready:return
        from capstone import CS_OP_MEM
        for name,bias in [('libCoreLSKD.so',0x10000000),('libandroidappmusic.so',0)]:
            text=subprocess.run(['readelf','--debug-dump=frames','-W',str(self.root/'rootfs/system/lib64'/name)],
                                check=True,capture_output=True,text=True).stdout
            self.function_ranges.extend((bias+int(a,16),bias+int(b,16)) for a,b in re.findall(r'pc=([0-9a-f]+)\.\.([0-9a-f]+)',text))
        self.function_ranges.sort();self.function_starts=[a for a,b in self.function_ranges]
        for pc in self.frame_call_pcs:
            bias,raw=self.images[0 if pc>=0x10000000 else 1]
            ins=next(self.decoder.disasm(segment_read(raw,pc-bias,16),pc,count=1))
            if ins.mnemonic!='call' or len(ins.operands)!=1 or ins.operands[0].type!=CS_OP_MEM:continue
            mem=ins.operands[0].mem
            if ins.reg_name(mem.base)!='rbp' or mem.index or mem.segment or ins.operands[0].size!=8:continue
            scope=self.function_scope(pc)
            if scope is not None:self.frame_calls.setdefault((scope,mem.disp),[]).append(pc)
        self.flow_ready=True

    def function_scope(self,pc):
        i=bisect.bisect_right(self.function_starts,pc)-1
        return self.function_ranges[i][0] if i>=0 and pc<self.function_ranges[i][1] else None

    def preceding_constant(self,pc,destination):
        from capstone import CS_OP_REG,CS_OP_IMM
        index=bisect.bisect_left(self.sorted_labels,pc);expected=pc
        bias,raw=self.images[0 if pc>=0x10000000 else 1]
        for before in reversed(self.sorted_labels[max(0,index-10):index]):
            if before<bias:return None
            ins=next(self.decoder.disasm(segment_read(raw,before-bias,16),before,count=1))
            if ins.address+ins.size!=expected or ins.mnemonic.startswith('j') or ins.mnemonic in ('call','ret','retf'):return None
            expected=before
            if destination not in {register(ins.reg_name(r)) for r in ins.regs_access()[1]}:continue
            ops=ins.operands
            if ins.mnemonic not in ('mov','movabs') or len(ops)!=2 or ops[0].type!=CS_OP_REG or ops[1].type!=CS_OP_IMM or ops[0].size not in (4,8):return None
            return dict(register=destination,value=ops[1].imm&((1<<(ops[0].size*8))-1),producer_pc=before)
        return None

    def recipe(self,pc,width):
        from capstone import CS_OP_REG, CS_OP_IMM, CS_OP_MEM
        key=(pc,width)
        if key in self.cache:return self.cache[key]
        self.cache[key]=None
        bias,raw=self.images[0 if pc>=0x10000000 else 1]
        try:code=segment_read(raw,pc-bias,16)
        except ValueError:return None
        first=next(self.decoder.disasm(code,pc,count=1),None)
        if first is None:return None
        ops=first.operands
        if first.mnemonic not in ('mov','movsxd','add') or len(ops)!=2 or ops[0].type!=CS_OP_REG or ops[1].type!=CS_OP_MEM or ops[1].size!=width:return None
        # SIMD/independent state setup can separate the resolved destination
        # from its jump by more than the old 24-instruction/192-byte window.
        # Keep the same conservative control-transfer and provenance barriers.
        try:code=segment_read(raw,pc-bias,512)
        except ValueError:code=segment_read(raw,pc-bias,192)
        instructions=list(self.decoder.disasm(code,pc))[:96]
        required=None;initial=0
        if first.mnemonic=='add':
            if width!=8 or ops[0].size!=8:return None
            required=self.preceding_constant(pc,register(first.reg_name(ops[0].reg)))
            if required is None:return None
            initial=required['value']
        signed=first.mnemonic=='movsxd'
        # Affine expressions retain initial-register symbols. Their concrete
        # values may later be admitted ONLY as source-label/readonly addresses,
        # never as arbitrary fixture integers or captured cryptographic words.
        names='rax rbx rcx rdx rsi rdi rbp rsp r8 r9 r10 r11 r12 r13 r14 r15'.split()
        expressions={name:(0,0,{name:1}) for name in names}
        expressions[register(first.reg_name(ops[0].reg))]=(1,initial,{})
        def combine(left,right,factor=1):
            if left is None or right is None:return None
            terms=dict(left[2])
            for name,coefficient in right[2].items():terms[name]=terms.get(name,0)+factor*coefficient
            return (left[0]+factor*right[0],left[1]+factor*right[1],{k:v for k,v in terms.items() if v})
        def value(op):
            if op.type==CS_OP_IMM:return (0,op.imm,{})
            if op.type==CS_OP_REG:return expressions.get(register(first.reg_name(op.reg)))
            return None
        for instruction in instructions[1:]:
            ops=instruction.operands;mn=instruction.mnemonic
            if mn in ('jmp','call'):
                if len(ops)==1 and ops[0].type==CS_OP_REG:
                    result=value(ops[0])
                    if result and result[0]==1:
                        recipe=dict(addend=result[1]&((1<<64)-1),signed=signed,
                                    base_terms=result[2],
                                    instruction=first,
                                    transfer_pc=instruction.address,transfer=mn,required_constant=required)
                        self.cache[key]=recipe;return recipe
                return None
            if mn.startswith('j') or mn in ('ret','retf','int3','syscall'):return None
            if mn=='mov' and len(ops)==2 and ops[0].type==CS_OP_MEM and ops[0].size==8:
                mem=ops[0].mem;result=value(ops[1])
                if result and result[0]==1 and instruction.reg_name(mem.base)=='rbp' and not mem.index and not mem.segment:
                    self.prepare_flow_metadata()
                    calls=self.frame_calls.get((self.function_scope(pc),mem.disp),[])
                    if calls:
                        recipe=dict(addend=result[1]&((1<<64)-1),signed=signed,
                                    base_terms=result[2],instruction=first,transfer_pc=calls[0],
                                    transfer='stored frame call',store_pc=instruction.address,
                                    frame_displacement=mem.disp,required_constant=required)
                        self.cache[key]=recipe;return recipe
            if mn=='cdqe':
                if expressions.get('rax')==(1,0,{}) and width==4: signed=True
                else: expressions['rax']=None
                continue
            if len(ops)<1 or ops[0].type!=CS_OP_REG:
                for reg in instruction.regs_access()[1]:expressions[register(instruction.reg_name(reg))]=None
                continue
            destination=register(instruction.reg_name(ops[0].reg))
            if mn=='lea' and len(ops)==2 and ops[1].type==CS_OP_MEM:
                mem=ops[1].mem;result=(0,mem.disp,{})
                for reg,scale in ((mem.base,1),(mem.index,mem.scale)):
                    if not reg:continue
                    name=instruction.reg_name(reg)
                    term=(0,instruction.address+instruction.size,{}) if name=='rip' else expressions.get(register(name))
                    result=combine(result,term,scale)
                expressions[destination]=result
            elif mn=='mov' and len(ops)==2:
                expressions[destination]=value(ops[1])
            elif mn=='movsxd' and len(ops)==2 and width==4 and value(ops[1])==(1,0,{}):
                expressions[destination]=(1,0,{});signed=True
            elif mn in ('add','sub') and len(ops)==2:
                left=expressions.get(destination);right=value(ops[1]);sign=1 if mn=='add' else -1
                expressions[destination]=combine(left,right,sign)
            else:
                for reg in instruction.regs_access()[1]:expressions[register(instruction.reg_name(reg))]=None
            # Unsupported truncations destroy provenance instead of guessing
            # that a 32-bit register retains a reversible 64-bit expression.
            if ops[0].size!=8:
                result=expressions.get(destination)
                if mn=='mov' and ops[0].size==4 and result==(1,0,{}) and width==4:pass
                elif ops[0].size==4 and result and not result[0] and not result[2]:expressions[destination]=(0,result[1]&0xffffffff,{})
                else:expressions[destination]=None
        return None

    def observe(self,pc,address,width,word,gpr):
        readonly=any(a<=address and address+width<=b for a,b in self.readonly)
        if not readonly and (not self.include_pristine_rw or width!=8 or address not in self.relative_candidates):return 0
        if self.pristine_read(address,width)!=word:return 0
        recipe=self.recipe(pc,width)
        if recipe is None:return 0
        first=recipe['instruction'];mem=first.operands[1].mem
        if mem.segment:return 0
        indices={name:i for i,name in enumerate('rax rbx rcx rdx rsi rdi rbp rsp r8 r9 r10 r11 r12 r13 r14 r15'.split())}
        required=recipe['required_constant']
        if required and gpr[indices[required['register']]]!=required['value']:return 0
        effective=mem.disp
        for reg,scale in ((mem.base,1),(mem.index,mem.scale)):
            if not reg:continue
            name=first.reg_name(reg)
            if name=='rip':effective+=(first.address+first.size)*scale
            elif register(name) in indices:effective+=gpr[indices[register(name)]]*scale
            else:return 0
        if effective&((1<<64)-1)!=address:return 0
        value=word
        if recipe['signed'] and word&(1<<31):value-=1<<32
        addend=recipe['addend']
        for name,coefficient in recipe['base_terms'].items():
            base=gpr[indices[name]]
            if base and base not in self.labels and not any(begin<=base<end for begin,end in self.readonly):return 0
            addend+=coefficient*base
        addend&=(1<<64)-1
        target=(value+addend)&((1<<64)-1)
        if (target-addend)&((1<<(width*8))-1)!=word:return 0
        if target not in self.labels and target not in self.imports:return 0
        if recipe['transfer']=='stored frame call' and self.function_scope(target)!=target:return 0
        # Emit decoded source-control identities only, never a raw data word.
        self.rows.append(dict(read_pc=hex(pc),address=hex(address),width=width,
                              target=hex(target),addend=hex(addend),
                              base_registers=sorted(recipe['base_terms']),effective_address_checked=True,
                              base_expression=dict(constant=hex(recipe['addend']),
                                terms=[dict(register=n,coefficient=c,source_address=hex(gpr[indices[n]]))
                                       for n,c in sorted(recipe['base_terms'].items())]),
                              signed=recipe['signed'],transfer=recipe['transfer'],
                              transfer_pc=hex(recipe['transfer_pc']),
                              target_kind='import' if target in self.imports else 'source label',
                              import_name=self.imports.get(target)))
        self.rows[-1].update(memory_kind='readonly' if readonly else 'pristine relative function slot',
                             required_constant=required)
        if 'store_pc' in recipe:self.rows[-1].update(store_pc=hex(recipe['store_pc']),frame_displacement=recipe['frame_displacement'])
        return 1


def child(root,shim,certificate_file,pristine_rw=False,entry_packets=False):
    sys.path.insert(0,str(root/'tools/crypto/keygen_experimental'))
    from source_protocol import generate
    classifier=Classifier(root,pristine_rw);unclassified=[];entries=[]
    callback_type=C.CFUNCTYPE(C.c_int,C.c_uint64,C.c_uint64,C.c_uint,C.c_uint64,C.POINTER(C.c_uint64))
    def observe(*args):
        try:
            pc,address,width,word,gpr=args
            if entry_packets and pc in (0x10526be8,0x10530998):
                selector=(word+gpr[0] if pc==0x10526be8 else word^gpr[0])&0xffffffff
                entries.append(dict(function=hex(0x10526bc0 if pc==0x10526be8 else 0x10530970),
                                    read_pc=hex(pc),source_dispatch_selector=hex(selector)))
                return 0
            if entry_packets and pc in (0x10526e0a,0x10530bb9):
                first=pc==0x10526e0a
                mask=((gpr[8]^(0xe49b8bbe838d1770 if first else 0xbe2af1b45989a725))*(0x741a8ab1 if first else 0x1f6060df))&0xffffffff
                origin=0x2a47a758 if first else 0x60ba2e72
                entries.append(dict(function=hex(0x10526bc0 if first else 0x10530970),read_pc=hex(pc),
                                    field_delta_from_validation_origin=(word-gpr[0]-origin)&0xffffffff,
                                    source_mask_adjustment=hex((gpr[0]-mask)&0xffffffff)))
                return 0
            result=classifier.observe(*args)
            if not result:unclassified.append(dict(read_pc=hex(args[0]),address=hex(args[1]),width=args[2]))
            return result
        except Exception as error:classifier.errors.append(type(error).__name__);return 0
    callback=callback_type(observe);library=C.CDLL(str(shim));library.ams_control_observer.argtypes=[callback_type]
    library.ams_control_observer(callback)
    certificate=bytes(32)
    if certificate_file:
        with open(certificate_file,'rb') as f:
            head=f.read(24);assert head[:4]==b'RCP1'
            operation,status,ns,nb=struct.unpack_from('<IqII',head,4);assert operation==1 and ns<=32 and nb<=32
            f.seek(ns*12,1);certificate=None
            for _ in range(nb):
                field,size=struct.unpack('<II',f.read(8));assert size<=1024*1024
                if field==1:
                    assert certificate is None;certificate=f.read(size);assert len(certificate)==size
                else:f.seek(size,1)
            assert certificate is not None
    rng=random.Random(0xc017);ticks=[0]
    def entropy(_,p,n):
        for i in range(n):p[i]=rng.randrange(256)
        return 0
    def clock(_):ticks[0]+=1;return 0x1234567800000000+ticks[0]*100003
    def wall(_,seconds,micros):seconds[0]=1700000000;micros[0]=123456;return 0
    status,output,result=generate(root/'build/spc-payload/libwrapper_spc_generate.so',0,certificate,
                                  b'invented-control-data',bytes(range(16)),entropy=entropy,clock=clock,time=wall)
    counts=(C.c_uint64*4)();library.ams_control_counts.argtypes=[C.POINTER(C.c_uint64)];library.ams_control_counts(counts)
    assert not classifier.errors and not counts[3],(classifier.errors,counts[3])
    byte_addresses={a+i for row in classifier.rows for a in (int(row['address'],16),) for i in range(row['width'])}
    print(json.dumps(dict(status='live dependency inventory',api=status,core_status=result.status,pc=hex(result.pc),
                          output_size=len(output),certificate_size=len(certificate),steps=result.source_steps,
                          observed_reads=counts[0],includes_pristine_writable_slots=pristine_rw,entry_packets_only=entry_packets,
                          unique_reads=counts[1],recognized_control_reads=counts[2],
                          recognized_control_cells=len(classifier.rows),recognized_control_bytes=len(byte_addresses),
                          rows=classifier.rows,unclassified_reads=unclassified,entry_dispatches=entries,
                          scope=('source control/validation selectors only; no pointer, operand, key or session bytes; no crypto parity claim' if entry_packets else
                                 'observed readonly references and optional pristine local-function relocations; initializer only; no mutable-read replacement, full image closure, input completeness or standalone crypto/auth proof'))))


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('checkout',type=Path);p.add_argument('--output',type=Path,required=True)
    p.add_argument('--public-certificate-fixture',type=Path)
    p.add_argument('--pristine-rw',action='store_true',help='admit checked encoded local function relocations in pristine writable storage')
    p.add_argument('--entry-packets',action='store_true',help='observe only source dispatch selectors at two identified substitution consumers; no pointer/key bytes')
    p.add_argument('--child',type=Path,help=argparse.SUPPRESS)
    args=p.parse_args();root=args.checkout.resolve()
    if args.child:child(root,args.child,args.public_certificate_fixture,args.pristine_rw,args.entry_packets);return
    with tempfile.TemporaryDirectory(prefix='ams-control-data-') as temp:
        directory=Path(temp);source=directory/'shim.c';shim=directory/'shim.so';source.write_text(SHIM)
        subprocess.run(['cc','-std=c99','-O2','-shared','-fPIC','-DAMS_CONTROL_RW='+str(int(args.pristine_rw)),
                        '-DAMS_ENTRY_PACKETS='+str(int(args.entry_packets)),'-I'+str(root/'crypto/keygen_experimental'),
                        str(source),'-ldl','-o',str(shim)],check=True,capture_output=True)
        env=dict(os.environ,LD_PRELOAD=str(shim),AMS_NATIVE=str(root/'build/spc-payload/libwrapper_spc_native.so'))
        command=[sys.executable,str(Path(__file__).resolve()),str(root),'--output',str(args.output),'--child',str(shim)]
        if args.public_certificate_fixture:command+=['--public-certificate-fixture',str(args.public_certificate_fixture.resolve())]
        if args.pristine_rw:command+=['--pristine-rw']
        if args.entry_packets:command+=['--entry-packets']
        result=subprocess.run(command,env=env,check=True,capture_output=True,text=True,timeout=180)
        report=json.loads(result.stdout);args.output.write_text(json.dumps(report,indent=2)+'\n')
        print(json.dumps({k:v for k,v in report.items() if k not in ('rows','unclassified_reads')}))


if __name__=='__main__':main()
