"""RAM-only native/source/original GUID round tracing on invented device data.

Existing source objects and pinned original instructions are developer oracles,
never package dependencies. No snapshots, words, indices, keys or GUID bytes
are emitted. The report is not a standalone native-auth success claim.
"""
import argparse
import ctypes as C
import hashlib
import json
from pathlib import Path
import re
import subprocess
import sys
import tempfile

from analyze_guid_column import model,COLUMNS
from analyze_round_substitutions import analyze as analyze_substitutions
from analyze_round_key_schedule import analyze as analyze_schedule
from analyze_ordered_aes_rounds import analyze as analyze_ordered
from analyze_frontier_aes_rounds import check as analyze_frontier
from probe_auth_substitution_reads import group_wrappers
from scan_auth_substitutions import TARGETS
from trace_lookup_dataflow import LookupTrace


SPECS=(('corefp_3bd20a',0x43bd20a,0x43c0a7e),('corefp_6523aa',0x46523aa,0x4656595))


SHIM=r'''
#include "spc_native.h"
static wrapper_kg_native_state *current_state;
typedef void(*observer_type)(unsigned,unsigned,const wrapper_kg_native_state*,const wrapper_kg_payload_region*,size_t,uint64_t,uint64_t);
static observer_type observer;
void ams_guid_observe(observer_type f){observer=f;}
static const uint64_t low[2]={%s},high[2]={%s},tables[2][8]={%s};
static const uint64_t inputs[2][16]={%s};
static unsigned final_reads[2],ready[2];
static void ams_guid_after(const wrapper_kg_native_state*s,const wrapper_kg_payload_region*r,size_t n){
 for(unsigned k=0;k<2;++k)if(ready[k]&&(s->cpu.pc<low[k]||s->cpu.pc>=high[k])){
  ready[k]=0;if(observer)observer(k,9,s,r,n,0,0);}}
int __real_mescal_native_read(const void*,size_t,uint64_t,unsigned,uint64_t*);
int __wrap_mescal_native_read(const void*r,size_t n,uint64_t a,unsigned w,uint64_t*out){
 int ok=__real_mescal_native_read(r,n,a,w,out);
 if(ok&&observer&&current_state&&w==1){uint64_t pc=current_state->cpu.pc;
  for(unsigned k=0;k<2;++k)for(unsigned j=0;j<16;++j)if(pc==inputs[k][j]){
   observer(k,8,current_state,r,n,a,*out);return ok;}}
 if(ok&&observer&&current_state&&w==4){uint64_t pc=current_state->cpu.pc;
  for(unsigned k=0;k<2;++k)if(low[k]<=pc&&pc<high[k])
   for(unsigned j=0;j<8;++j)if(tables[k][j]<=a&&a+4<=tables[k][j]+1024&&!((a-tables[k][j])&3)){
    if(pc==low[k]){final_reads[k]=0;ready[k]=0;}
    if(j>=4&&++final_reads[k]==16)ready[k]=1;
    observer(k,j,current_state,r,n,a,*out);return ok;}}
 return ok;
}
'''


class CPU(C.Structure):
    _fields_=[('gpr',C.c_uint64*16),('flags',C.c_uint64),('pc',C.c_uint64),('fault_address',C.c_uint64),('steps',C.c_size_t),('fault_size',C.c_uint)]


class Native(C.Structure):
    _fields_=[('cpu',CPU),('xmm',C.c_uint64*32),('tls',C.c_uint64)]


class Region(C.Structure):
    _fields_=[('address',C.c_uint64),('size',C.c_size_t),('data',C.c_void_p),('permissions',C.c_uint)]


def clone(fs,regions,count):
    from mescal_oracle import MescalOracle
    from unicorn import x86_const as r
    oracle=MescalOracle(reference_backend=True)
    mu=oracle.mu;mapped=list(mu.mem_regions())
    for index in range(count):
        region=regions[index]
        for page in range(region.address&~4095,(region.address+region.size+4095)&~4095,4096):
            if not any(begin<=page<=end for begin,end,_ in mapped):
                mu.mem_map(page,4096);mapped.append((page,page+4095,7))
        mu.mem_write(region.address,C.string_at(region.data,region.size))
    names=('RAX','RBX','RCX','RDX','RSI','RDI','RBP','RSP','R8','R9','R10','R11','R12','R13','R14','R15')
    state=fs.contents
    for name,value in zip(names,state.cpu.gpr):mu.reg_write(getattr(r,'UC_X86_REG_'+name),value)
    mu.reg_write(r.UC_X86_REG_EFLAGS,state.cpu.flags);mu.reg_write(r.UC_X86_REG_RIP,state.cpu.pc)
    mu.reg_write(r.UC_X86_REG_FS_BASE,state.tls)
    for index in range(16):mu.reg_write(getattr(r,'UC_X86_REG_XMM'+str(index)),state.xmm[2*index]|(state.xmm[2*index+1]<<64))
    return oracle


def replay(kernel,oracle,expected,bases,image,prefix,normalize_inverse=False,rewrite_columns=False,source_projections=False,caller_input=None,reconstruction=None,source_final_regions=None):
    from unicorn import UC_HOOK_CODE,UC_HOOK_MEM_READ,UC_HOOK_MEM_WRITE
    from unicorn import x86_const as r
    name,begin,end=SPECS[kernel];mu=oracle.mu;observed=[];final=[0];first=[True];output_writes=[]
    if reconstruction is None:reconstruction={}
    raw_tables=[bytes(mu.mem_read(base,1024)) for base in bases[:4]]
    if reconstruction:
        assert raw_tables==reconstruction['raw_tables'],'regular word arrays changed'
        analysis=reconstruction['analysis'];arrays=reconstruction['arrays']
    else:
        analysis=model(image,name);arrays=[];z=analysis['z']
        for index,raw in enumerate(raw_tables):
            words=[int.from_bytes(raw[j:j+4],'little') for j in range(0,1024,4)]
            values=[z.simplify(z.substitute(analysis['contributions'][index],(analysis['words'][index],z.BitVecVal(word,32)))).as_long() for word in words]
            arrays.append(b''.join(value.to_bytes(4,'little') for value in values))
        reconstruction.update(raw_tables=raw_tables,analysis=analysis,arrays=arrays)
    z=analysis['z']
    domains={index:data for index,data in enumerate(arrays)} if normalize_inverse and kernel==0 else None
    trace=LookupTrace(mu,[(base,1024) for base in bases],range(4),range(4,8),word_domains=domains,maximum_regular_reads=prefix)
    normalization=None;inverse_report=None;rewriter=None
    if domains is not None:
        from invert_guid_word_encodings import recover
        from normalize_guid_indices import IndexNormalizer
        inverses={}
        inverse_report=recover(analysis,image,lambda index,encoded,inverse:inverses.update({index:(encoded,inverse)}))
        assert len(inverses)==4,'word inverse proof incomplete'
        def normalize(ordinal,value):
            if ordinal>=4:return value
            return z.simplify(z.substitute(analysis['contributions'][ordinal],(analysis['words'][ordinal],z.BitVecVal(value,32)))).as_long()
        def denormalize(ordinal,expression):
            if ordinal>=4:return expression
            variable,inverse=inverses[ordinal]
            return z.simplify(z.substitute(inverse,(variable,expression)))
        trace.word_value_transform=normalize;trace.word_expression_transform=denormalize
        if not rewrite_columns:
            normalization=IndexNormalizer();trace.custom_index_normalizer=normalization
        else:
            from prove_guid_column_rewrites import ColumnRewriter
            raw_tables=[]
            for base in bases[:4]:
                data=bytes(mu.mem_read(base,1024));raw_tables.append([int.from_bytes(data[j:j+4],'little') for j in range(0,1024,4)])
            rewriter=ColumnRewriter(expected,image,analysis,raw_tables,arrays);rewriter.bind(trace,mu)
    def code(m,pc,size,user):
        if pc==begin:
            if not first[0]:m.emu_stop();return
            first[0]=False
        if not begin<=pc<end:m.emu_stop();return
        if rewriter is not None and trace.active:rewriter.step(trace,m,pc)
        trace.step(m,pc,size)
    def read(m,kind,address,width,value,ordinal):
        if width!=4 or (address-bases[ordinal])%4:return
        pc=m.reg_read(r.UC_X86_REG_RIP)
        observed.append((pc,ordinal,(address-bases[ordinal])//4,int.from_bytes(m.mem_read(address,4),'little')))
        if ordinal>=4:
            final[0]+=1
    def write(m,kind,address,width,value,user):
        if not final[0] or width!=1:return
        from capstone import CS_OP_MEM
        pc=m.reg_read(r.UC_X86_REG_RIP)
        ins=next(trace.decoder.disasm(bytes(m.mem_read(pc,16)),pc,count=1))
        if ins.operands and ins.operands[0].type==CS_OP_MEM and ins.reg_name(ins.operands[0].mem.base)==('r13' if kernel==0 else 'r12'):
            output_writes.append(address)
    mu.hook_add(UC_HOOK_CODE,code)
    mu.hook_add(UC_HOOK_MEM_WRITE,write)
    for ordinal,base in enumerate(bases):mu.hook_add(UC_HOOK_MEM_READ,read,ordinal,begin=base,end=base+1023)
    error=None
    try:mu.emu_start(begin,end,count=200000)
    except Exception as exception:error=type(exception).__name__
    if 'models' in reconstruction:models=reconstruction['models'];substitutions=reconstruction['substitutions']
    else:
        models=[];substitutions=analyze_substitutions(arrays,range(4),models.append)
        reconstruction.update(models=models,substitutions=substitutions)
    masters=[];schedule=analyze_schedule(trace,models,range(4),lambda master,details:masters.append(master))
    ordered_masters=[];ordered=analyze_ordered(trace.events,models,range(4),lambda master,details:ordered_masters.append(master))
    frontier_masters=[];frontier_details=[]
    def accept_frontier(master,details):
        frontier_masters.append(master);frontier_details.append(details)
    frontier=analyze_frontier(trace,models,range(4),accept_frontier)
    agreement=set(masters)==set(ordered_masters) if masters and ordered_masters else None
    frontier_agreement=set(masters)==set(frontier_masters) if masters and frontier_masters else None
    if not masters:masters=ordered_masters
    if not masters:masters=frontier_masters
    final_inputs=[]
    block_outputs=[];private_blocks=[];source_key_projections=[]
    for master,details in zip(frontier_masters,frontier_details):
        if source_projections:
            from analyze_guid_key_arithmetic import analyze as prove_source_projections
            source_key_projections.append(prove_source_projections(trace,details,analysis,all_rounds=source_projections=='all'))
        from analyze_guid_final_inputs import check as check_final_inputs
        final_inputs.append(check_final_inputs(master,details,observed))
        from analyze_round_key_schedule import recover_input
        from apple_music_source.crypto.aes import AES
        contiguous=len(set(output_writes))==16 and max(output_writes)-min(output_writes)==15
        equal=source_equal=None
        if contiguous:
            original=recover_input(master,details,range(4));cipher=AES(master)
            predicted=cipher.decrypt_block(original) if details['cipher_direction']==-1 else cipher.encrypt_block(original)
            actual=bytes(mu.mem_read(min(output_writes),16));equal=actual==predicted
            if source_final_regions is not None:
                for address,data in source_final_regions:
                    offset=min(output_writes)-address
                    if 0<=offset and offset+16<=len(data):
                        source_equal=data[offset:offset+16]==actual;break
            private_blocks.append((master,original,bytes(a^b for a,b in zip(predicted,actual)),caller_input,actual))
        block_outputs.append(dict(output_byte_store_events=len(output_writes),contiguous_16_byte_output=contiguous,
                                  original_output_equals_unwhitened_AES=equal,source_original_complete_output_equal=source_equal,
                                  private_bytes_written=False))
    result=dict(column=name,original_execution_error=error,original_source_word_reads_equal=observed==expected,
        source_lookup_reads=len(expected),original_lookup_reads=len(observed),final_lookup_reads=final[0],
        original_stop_pc=hex(mu.reg_read(r.UC_X86_REG_RIP)),lookup_dataflow=trace.summary(),
        coherent_substitutions=substitutions,round_key_schedule=schedule,
        execution_order_schedule=ordered,dataflow_execution_order_keys_agree=agreement,
        frontier_schedule=frontier,dataflow_frontier_keys_agree=frontier_agreement,
        final_input_checks=final_inputs,
        block_output_checks=block_outputs,
        source_key_projections=source_key_projections,
        source_word_inverse_proofs=inverse_report,index_projection_proofs=dict(normalization.outcomes) if normalization else None,
        column_rewrites=rewriter.summary() if rewriter else None,
        scope='one captured invented GUID block; original/source words compared in RAM; only observed regular lookup rounds and schedule checked, not final key/output encoding, chaining or auth; keys/models stay RAM-only')
    return result,masters,private_blocks


def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('checkout',type=Path)
    parser.add_argument('--read-sites',type=Path,required=True);parser.add_argument('--output',type=Path,required=True)
    parser.add_argument('--trace-prefix',type=int,default=96,help='Regular reads to track symbolically; zero includes final reads')
    parser.add_argument('--normalize-inverse-words',action='store_true',help='Use proved source-word inverses and validated affine output planes on the inverse kernel')
    parser.add_argument('--rewrite-columns',action='store_true',help='Prove and reuse column register identities rather than full per-index normalization')
    parser.add_argument('--blocks',type=int,default=1,choices=(1,2,8),help='Capture up to eight cipher blocks per path, keeping states in RAM')
    parser.add_argument('--profiles',type=int,default=1,choices=(1,2),help='Use one or two explicit invented device profiles')
    parser.add_argument('--source-projections',action='store_true',help='Attempt unconstrained first-transition word projection proofs')
    parser.add_argument('--all-source-projections',action='store_true',help='Attempt every observed transition rather than only the first')
    parser.add_argument('--export-guid-parameters',type=Path,help='Explicitly emit 112 named static GUID protocol parameter bytes after full eight-block source/original validation')
    parser.add_argument('--verify-fixed-guid',action='store_true',help='Validate the fixed package GUID cipher paths without fitting keys, masks or encodings')
    parser.add_argument('--profile-set',choices=('primary','independent'),default='primary',help='Select explicit invented device profiles; independent profiles are excluded from parameter fitting')
    args=parser.parse_args();root=args.checkout.resolve();assert 0<=args.trace_prefix<=160
    assert not args.rewrite_columns or args.normalize_inverse_words
    assert not (args.source_projections or args.all_source_projections) or not args.normalize_inverse_words
    assert args.export_guid_parameters is None or args.blocks==args.profiles==2
    assert not args.verify_fixed_guid or args.export_guid_parameters is None and not args.normalize_inverse_words
    sys.path.insert(0,str(root/'tools/auth'));sys.path.insert(0,str(root/'tools/crypto/keygen_experimental'))
    sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'src'))
    from device_identity import derive_android_guid_fields
    filename,digest=TARGETS['corefp'];image=(root/'rootfs/system/lib64'/filename).read_bytes();assert hashlib.sha256(image).hexdigest()==digest
    sites=json.loads(args.read_sites.read_text());bases=[]
    for name,begin,end in SPECS:
        found={int(window['source_window_address'],16) for window in sites['windows'] if window['target']==0
               and any(begin<=int(site['pc'],16)<end for site in window['sites'])}
        regular=[base+0x4000000 for _,base in COLUMNS[name][2]]
        assert len(found)==8 and set(regular)<=found
        bases.append(regular+sorted(found-set(regular)))
    snapshots={};events={};current=[-1,-1];final={};errors=[];input_reads={};source_outputs={}
    callback_type=C.CFUNCTYPE(None,C.c_uint,C.c_uint,C.POINTER(Native),C.POINTER(Region),C.c_size_t,C.c_uint64,C.c_uint64)
    def observe(kernel,ordinal,fs,regions,count,address,value):
        try:
            pc=fs.contents.cpu.pc
            if ordinal==9:
                key=(kernel,current[kernel])
                if key in snapshots:
                    source_outputs[key]=[(regions[index].address,C.string_at(regions[index].data,regions[index].size))
                                         for index in range(count) if regions[index].permissions&2]
                return
            if ordinal==8:
                key=(kernel,current[kernel]+1)
                if key[1]<args.blocks:input_reads.setdefault(key,[]).append((address,value))
                return
            if pc==SPECS[kernel][1]:
                current[kernel]+=1
                if current[kernel]<args.blocks:
                    key=(kernel,current[kernel]);snapshots[key]=clone(fs,regions,count);events[key]=[];final[key]=0
            key=(kernel,current[kernel])
            if key not in events or final[key]>=16:return
            events[key].append((pc,ordinal,(address-bases[kernel][ordinal])//4,value))
            if ordinal>=4:
                final[key]+=1
        except BaseException as exception:
            errors.append(type(exception).__name__)
    callback=callback_type(observe)
    with tempfile.TemporaryDirectory(prefix='ams-guid-rounds-') as directory:
        directory=Path(directory);source,library=directory/'capture.c',directory/'capture.so'
        groups=sorted(set(re.findall(r'\bmescal_(?:ssc|corefp)_page_[0-9a-f]+\b',(root/'crypto/auth/mescal/generated/bounds.inc').read_text())))
        constants=lambda values:','.join('UINT64_C(0x%x)'%value for value in values)
        from capstone import Cs,CS_ARCH_X86,CS_MODE_64,CS_OP_MEM,CS_AC_READ
        from inventory_guid_word_tables import translated_instructions
        decoder=Cs(CS_ARCH_X86,CS_MODE_64);decoder.detail=True;input_sites=[]
        for begin,end in ((0x3bca00,0x3bd20a),(0x651a10,0x6523aa)):
            pcs=[ins.address+0x4000000 for ins in translated_instructions(root,image,decoder,'corefp',begin,end)
                 if any(operand.type==CS_OP_MEM and operand.size==1 and operand.access&CS_AC_READ
                        and ins.reg_name(operand.mem.base)=='r13' for operand in ins.operands)]
            assert len(pcs)==16;input_sites.append(pcs)
        wrappers=group_wrappers(groups)
        assert wrappers.count('current_state=old;return status;')==len(groups)
        wrappers=wrappers.replace('current_state=old;return status;','ams_guid_after(state,regions,count);current_state=old;return status;')
        source.write_text((SHIM%(constants(spec[1] for spec in SPECS),constants(spec[2] for spec in SPECS),
            ','.join('{'+constants(row)+'}' for row in bases),','.join('{'+constants(row)+'}' for row in input_sites)))+wrappers)
        objects=sorted((root/'build/auth/mescal/CMakeFiles/wrapper_mescal_source.dir').rglob('*.o'));assert objects
        subprocess.run(['cc','-std=c99','-O2','-shared','-fPIC','-I'+str(root/'crypto/keygen_experimental'),str(source),*map(str,objects),
            '-Wl,--wrap=mescal_native_read',*['-Wl,--wrap='+name for name in groups],'-o',str(library)],check=True,capture_output=True)
        native=C.CDLL(str(library));native.ams_guid_observe.argtypes=[callback_type];native.ams_guid_observe(callback)
        rows=[];masters={};baseline={};chain_baseline={};input_chain_baseline={};previous_blocks={};key_sets={0:set(),1:set()}
        reconstruction={0:{},1:{}};private_blocks={};fixed_blocks={};fixed_starts={}
        profiles=((b'0123456789abcdef',bytes(range(6)),b'invented-serial'),
                  (b'fedcba9876543210',bytes(range(6,12)),b'another-invented-serial'))
        if args.profile_set=='independent':
            profiles=((b'0011223344556677',bytes(range(32,38)),b'independent-third-serial'),
                      (b'ffeeddccbbaa9988',bytes(range(80,86)),b'independent-fourth-serial'))
        for profile,(android,mac,serial) in enumerate(profiles[:args.profiles]):
            snapshots.clear();events.clear();final.clear();input_reads.clear();source_outputs.clear();current[:]=[-1,-1]
            fields=derive_android_guid_fields(android,mac,system_serial=serial,library=library)
            assert len(fields.first)==18 and len(fields.second)==7
            for kernel,block in sorted(snapshots):
                captured=input_reads.get((kernel,block),[]);input_bytes=dict(captured)
                input_contiguous=len(input_bytes)==16 and max(input_bytes)-min(input_bytes)==15
                caller_input=bytes(input_bytes[address] for address in sorted(input_bytes)) if input_contiguous else None
                if args.verify_fixed_guid:
                    from replay_guid_fixed import replay as replay_fixed
                    row,actual=replay_fixed(kernel,snapshots[kernel,block],events[kernel,block],bases[kernel],
                                            SPECS[kernel][1],SPECS[kernel][2],source_outputs.get((kernel,block)))
                    row.update(column=SPECS[kernel][0],invented_profile=profile,cipher_block=block,
                               caller_input_capture=dict(byte_reads=len(captured),contiguous_16_byte_input=input_contiguous))
                    rows.append(row);fixed_blocks[kernel,profile,block]=(caller_input,actual)
                    fixed_starts[kernel,profile,block]=min(input_bytes) if input_contiguous else None
                    continue
                projection_mode='all' if args.all_source_projections else args.source_projections
                row,keys,parameters=replay(kernel,snapshots[kernel,block],events[kernel,block],bases[kernel],image,args.trace_prefix,args.normalize_inverse_words,args.rewrite_columns,projection_mode,caller_input,reconstruction[kernel],source_outputs.get((kernel,block)))
                row.update(invented_profile=profile,cipher_block=block)
                row['caller_input_capture']=dict(byte_reads=len(captured),contiguous_16_byte_input=input_contiguous,private_bytes_written=False)
                if len(parameters)==1:
                    private_blocks[kernel,profile,block]=parameters[0]
                    key,original,mask=parameters[0][:3]
                    if kernel in baseline:
                        before_key,before_input,before_mask=baseline[kernel][:3]
                        row['heldout_output_mask_check']=dict(same_master_key=key==before_key,
                            logical_input_changed=original!=before_input,constant_output_XOR_mask=mask==before_mask,
                            private_bytes_written=False)
                        before_raw=baseline[kernel][3]
                        if caller_input is not None and before_raw is not None:
                            row['heldout_input_mask_check']=dict(
                                caller_input_changed=caller_input!=before_raw,
                                constant_input_XOR_mask=bytes(a^b for a,b in zip(original,caller_input))==bytes(a^b for a,b in zip(before_input,before_raw)),
                                private_bytes_written=False)
                    else:baseline[kernel]=parameters[0]
                    if block and (profile,kernel) in previous_blocks:
                        _,previous_input,_,previous_raw,previous_output=previous_blocks[profile,kernel]
                        chain_mask=bytes(a^b for a,b in zip(mask,previous_input))
                        if kernel in chain_baseline:
                            row['heldout_CBC_feedback_check']=dict(previous_logical_input_XOR_relation=chain_mask==chain_baseline[kernel],
                                private_bytes_written=False,
                                scope='held-out second block of another invented profile, using the first profile second-block residual without refitting; not source input/output encoding or initialization proof')
                        else:chain_baseline[kernel]=chain_mask
                        if caller_input is not None:
                            residual=bytes(a^b^c for a,b,c in zip(original,caller_input,previous_output))
                            if kernel in input_chain_baseline:
                                row['heldout_input_CBC_check']=dict(previous_caller_output_XOR_relation=residual==input_chain_baseline[kernel],private_bytes_written=False)
                            else:input_chain_baseline[kernel]=residual
                    previous_blocks[profile,kernel]=parameters[0]
                rows.append(row);masters[kernel]=keys;key_sets[kernel].update(keys)
        from analyze_guid_buffer_cbc import analyze as analyze_buffer_cbc
        parameters_to_export={}
        buffer_report=analyze_buffer_cbc(private_blocks,lambda values:parameters_to_export.update(values))
        fixed_report=None
        if args.verify_fixed_guid:
            from apple_music_source.auth._guid_cipher import encrypt_blocks,decrypt_blocks
            fixed_report=[]
            for kernel,function in ((0,decrypt_blocks),(1,encrypt_blocks)):
                for profile in range(args.profiles):
                    streams=[];previous=None
                    for block in range(args.blocks):
                        start=fixed_starts[kernel,profile,block]
                        if previous is None or start!=previous+16:streams.append([])
                        streams[-1].append(fixed_blocks[kernel,profile,block]);previous=start
                    for stream,records in enumerate(streams):
                        assert all(raw is not None and actual is not None for raw,actual in records)
                        actual=function(b''.join(raw for raw,_ in records))
                        fixed_report.append(dict(kernel=kernel,profile=profile,stream=stream,blocks=len(records),
                            complete_message_equal=actual==b''.join(expected for _,expected in records),
                            parameter_refitting=False,private_bytes_written=False))
        exported=None
        if args.export_guid_parameters is not None:
            assert len(rows)==8 and not errors and len(parameters_to_export)==2
            assert all(row['original_source_word_reads_equal'] and row['original_lookup_reads']==160
                       and len(row['block_output_checks'])==1
                       and row['block_output_checks'][0]['source_original_complete_output_equal'] for row in rows)
            from emit_guid_parameters import emit
            exported=emit(args.export_guid_parameters,parameters_to_export)
        report=dict(status='incomplete native GUID round investigation',offline=True,network_requests=0,private_bytes_written=False,
            synthetic_source_GUID_succeeded=True,capture_errors=errors,rows=rows,
            requested_invented_profiles=args.profiles,requested_blocks_per_path=args.blocks,
            unique_master_keys_per_path=[len(key_sets[kernel]) for kernel in range(2)],
            caller_buffer_CBC=None if args.verify_fixed_guid else buffer_report,static_guid_parameter_export=exported,
            fixed_guid_validation=fixed_report,invented_profile_set=args.profile_set,
            matching_master_keys=masters[0][0]==masters[1][0] if len(masters.get(0,[]))==len(masters.get(1,[]))==1 else None,
            scope='developer oracles only; snapshots, lookup words/indices and encoding maps stay RAM-only; only an explicit export writes named static vendor GUID parameters after validation; no account/session/content material or runtime oracle fallback')
        args.output.write_text(json.dumps(report,indent=2)+'\n')
        print(json.dumps(dict(status=report['status'],capture_errors=errors,kernels=len(rows),
            original_source_matches=sum(row['original_source_word_reads_equal'] for row in rows),
            symbolic_statuses=[row.get('lookup_dataflow',{}).get('status',row.get('mode')) for row in rows])))


if __name__=='__main__':main()
