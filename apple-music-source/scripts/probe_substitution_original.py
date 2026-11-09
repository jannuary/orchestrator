"""Compare invented kernel calls with original instructions, RAM-only.

Developer oracle only. Reads the public certificate field and pinned ELF, not
private session fields. Runtime snapshots, buffers, RNG states and crypto values
stay in memory. Reports contain parity booleans and instruction addresses only.
"""
import argparse
from bisect import bisect_right
from collections import Counter
from functools import reduce
import ctypes as C
import hashlib
import json
from pathlib import Path
import random
import struct
import subprocess
import sys
import tempfile

from probe_substitution_calls import HELPER,certificate_only
from verify_integrity_codec import HASH
from verify_fill_dispatch import APP_HASH


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('checkout',type=Path);p.add_argument('--public-certificate-fixture',type=Path,required=True)
    p.add_argument('--output',type=Path,required=True)
    p.add_argument('--buffer-accesses',action='store_true',help='Record operand buffer offsets/PCs only, never values')
    p.add_argument('--copy-stage-checks',action='store_true',help='Check copy arithmetic and loop counters in the original full call; values remain RAM-only')
    p.add_argument('--substitution-windows',type=Path,help='Trace candidate windows from the bounded static classification; report locations/counts only')
    p.add_argument('--runtime-tables',action='store_true',help='Classify temporary lookup arrays at the first data block; all values remain RAM-only')
    p.add_argument('--initializer-read-map',action='store_true',help='Count original Core segment reads before the first block; no bytes or lookup indices are emitted')
    p.add_argument('--freeze-trial-inputs',action='store_true',help='Restore invented host RNG/clock state before each isolated call')
    p.add_argument('--repeat-fixed-case',action='store_true',help='Repeat the fixed IV/data case after the additional random cases')
    p.add_argument('--input-controls',action='store_true',help='With frozen host state, vary data, IV, and their equal-XOR cancellation separately')
    p.add_argument('--kernel',type=int,choices=(0,1),help='Limit the developer experiment to one kernel')
    p.add_argument('--prove-index',action='store_true',help='Prove the first kernel table-index identity with symbolic byte inputs')
    p.add_argument('--table-algebra',action='store_true',help='Analyze decoded regular/final word-space mixing; no inferred bases are emitted')
    p.add_argument('--round-substitutions',action='store_true',help='Check one shared byte encoding for source substitutions and MixColumns')
    p.add_argument('--trace-rounds',action='store_true',help='Track symbolic lookup dependencies on the observed first-block path')
    p.add_argument('--normalize-round-indices',action='store_true',help='Simplify only solver-proved byte projections of four symbolic lookup words')
    p.add_argument('--normalization-timeout-ms',type=int,default=1500,help='Bound each byte-projection proof; timeout leaves the expression unchanged')
    p.add_argument('--key-schedule',action='store_true',help='Validate an observed round prefix against AES-128 key expansion entirely in RAM')
    p.add_argument('--encoded-key-arithmetic',action='store_true',help='Prove encoded round-key XOR arithmetic independently of word table domains; no parameters emitted')
    p.add_argument('--native-prediction-cases',type=int,default=0,help='Additional source-runtime message checks using unchanged RAM-only baseline parameters; no original-instruction trace for these cases')
    p.add_argument('--cross-session-predictions',type=int,default=0,help='Validate unchanged candidates in a fresh source session with a different entropy seed, content and device seed')
    p.add_argument('--export-static-parameters',type=Path,help='Emit only named static cipher parameters after original parity and fresh-session prediction checks')
    p.add_argument('--trace-prefix',type=int,default=0,help='Stop symbolic tracking after this many regular lookup reads; zero tracks through the final word lookups')
    p.add_argument('--trace-blocks',type=int,default=1,help='Number of consecutive first-block-shaped round paths to inspect')
    p.add_argument('--length',type=int,action='append',help='Positive 16-byte multiple up to 64; repeatable')
    p.add_argument('--random-cases',type=int,default=0,help='Additional invented IV/data cases per length, kept entirely in RAM')
    args=p.parse_args();root=args.checkout.resolve();source=root/'crypto/keygen_experimental';build=root/'build/spc-payload'
    assert not args.input_controls or args.freeze_trial_inputs
    assert not args.prove_index or (args.runtime_tables and args.kernel!=1)
    assert not args.table_algebra or args.runtime_tables
    assert not args.initializer_read_map or args.runtime_tables
    assert not args.round_substitutions or args.table_algebra
    assert not args.trace_rounds or args.table_algebra
    assert not args.normalize_round_indices or args.trace_rounds
    assert 1<=args.normalization_timeout_ms<=30000
    assert not args.key_schedule or (args.trace_rounds and args.round_substitutions)
    assert not args.encoded_key_arithmetic or args.key_schedule
    assert 0<=args.native_prediction_cases<=256 and (not args.native_prediction_cases or args.key_schedule)
    assert 0<=args.cross_session_predictions<=64 and (not args.cross_session_predictions or args.key_schedule)
    assert args.export_static_parameters is None or args.kernel is None and args.native_prediction_cases>=8 and args.cross_session_predictions>=8
    assert 0<=args.trace_prefix<=512 and (not args.trace_prefix or args.trace_rounds)
    assert 1<=args.trace_blocks<=4 and (args.trace_blocks==1 or args.trace_rounds)
    sys.path.insert(0,str(root/'tools/crypto/keygen_experimental'))
    from source_protocol import SourceSession,Result
    from payload_protocol import State,Region,REGISTERS
    from elf_loader import load
    from unicorn import Uc,UcError,UC_ARCH_X86,UC_MODE_64,UC_HOOK_CODE,UC_HOOK_BLOCK,UC_HOOK_MEM_READ,UC_HOOK_MEM_WRITE,UC_MEM_WRITE
    from unicorn import x86_const as x86
    if args.runtime_tables:
        sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'src'))
        from classify_runtime_tables import allocations as classify_allocations
        from classify_runtime_tables import xor_relation
        if args.table_algebra:from analyze_table_algebra import analyze as analyze_algebra
        if args.round_substitutions:from analyze_round_substitutions import analyze as analyze_round
        if args.trace_rounds:from trace_lookup_dataflow import LookupTrace
        if args.key_schedule:
            from analyze_round_key_schedule import analyze as analyze_schedule,recover_input
            from apple_music_source.crypto.aes import AES
            from apple_music_source.crypto.masked_cbc import MaskedCBC
            if args.encoded_key_arithmetic:from analyze_encoded_key_schedule import analyze as analyze_encoded_schedule
    class Native(C.Structure):
        _fields_=[('cpu',State),('xmm',C.c_uint64*32),('tls',C.c_uint64)]
    callback_type=C.CFUNCTYPE(None,C.POINTER(Native),C.POINTER(Region),C.c_size_t,C.c_uint64)
    app=root/'rootfs/system/lib64/libandroidappmusic.so';core=root/'rootfs/system/lib64/libCoreLSKD.so'
    assert hashlib.sha256(app.read_bytes()).hexdigest()==APP_HASH
    assert hashlib.sha256(core.read_bytes()).hexdigest()==HASH
    if args.prove_index:
        from prove_lookup_index import IndexProof
        index_proof=IndexProof(core.read_bytes())
    windows=[]
    if args.substitution_windows:
        classification=json.loads(args.substitution_windows.read_text())
        assert classification['core_sha256']==HASH and classification['window_bytes']==1024
        windows=sorted((int(row['address'],16),bool(row.get('affine_equivalent_to_gf256_inversion')))
                       for row in classification['rows'])
        assert len({address for address,_ in windows})==len(windows)
        assert all(0x10000000<=address<=0x100cf9f8-1024 and address%16==0 for address,_ in windows)
    window_starts=[address for address,_ in windows]
    names=json.loads((root/'tools/crypto/keygen_experimental/source_image_manifest.json').read_text())['services']
    captures=[];errors=[];all_blocks={};rows=[];rng=random.Random(0xc017);ticks=[0];codecs=[];streams=[];runtime_reference={};mask_reference={};index_reference={};input_seed_reference={};schedule_key_reference={};schedule_io_reference={};schedule_chain_reference={};masked_kernel_reference={};static_parameters={};cross_session_rows=[]
    def entropy(_,p,n):
        for i in range(n):p[i]=rng.randrange(256)
        return 0
    def clock(_):ticks[0]+=1;return 0x1234567800000000+ticks[0]*100003
    def wall(_,seconds,micros):seconds[0]=1700000000;micros[0]=123456;return 0
    capture_enabled=[True];prediction_rows=[];initializer_models=[];schedule_encoding_reference={}
    def capture(fs,regions,count,cursor):
        if not capture_enabled[0]:return
        saved_rng=rng.getstate();saved_tick=ticks[0]
        try:
            mu=Uc(UC_ARCH_X86,UC_MODE_64);mu.mem_map(0x800000,0x100000);mu.mem_map(0x900000,4096)
            stubs={0x800000+i*16:name for i,name in enumerate(names)};symbols={name:a for a,name in stubs.items()}
            load(mu,app,0,stubs,symbols,0x800000);load(mu,core,0x10000000,stubs,symbols,0x800000)
            for i in range(count):
                region=regions[i];start=region.address&~4095;end=(region.address+region.size+4095)&~4095
                for page in range(start,end,4096):
                    if not any(a<=page<=b for a,b,perm in mu.mem_regions()):mu.mem_map(page,4096)
                mu.mem_write(region.address,C.string_at(region.data,region.size))
            s=fs.contents
            for reg,value in zip(REGISTERS,list(s.cpu.gpr)+[s.cpu.flags]):mu.reg_write(reg,value)
            for j in range(16):mu.reg_write(getattr(x86,'UC_X86_REG_XMM'+str(j)),s.xmm[2*j]|(s.xmm[2*j+1]<<64))
            mu.reg_write(x86.UC_X86_REG_FS_BASE,s.tls)
            packet=s.cpu.gpr[5];which=int(s.cpu.pc==0x10530970);raw=bytes(mu.mem_read(packet,40));mask=((packet^(0xbe2af1b45989a725 if which else 0xe49b8bbe838d1770))*(0x1f6060df if which else 0x741a8ab1))&0xffffffff
            size=(struct.unpack_from('<I',raw,16 if which else 32)[0]-mask-(0x60ba2e72 if which else 0x2a47a758))&0xffffffff
            destination=(struct.unpack_from('<Q',raw,24 if which else 8)[0]+(0xe40c57b7a130b973 if which else 0xc43e05c519b61228))&((1<<64)-1)
            assert size<=64
            allocation=[cursor];imports=[];faults=[];buffer_events=[]
            allocated=[];runtime_tables=[];runtime_uses={};runtime_table_arrays=[];runtime_word_reads=Counter();round_traces=[]
            initializer_reads={};initializer_segments=[];initializer_model_cache={};initializer_model_bytes={};initializer_model_mismatches=set();initializer_unknown_bytes=set()
            if args.initializer_read_map:
                image=core.read_bytes();phoff=struct.unpack_from('<Q',image,32)[0];pe,pn=struct.unpack_from('<HH',image,54)
                for j in range(pn):
                    kind,flags,off,va,_,length,memory_size,_=struct.unpack_from('<IIQQQQQQ',image,phoff+j*pe)
                    if kind!=1:continue
                    role='executable' if flags&1 else 'mutable' if flags&2 else 'readonly'
                    initializer_segments.append((0x10000000+va,0x10000000+va+memory_size,role,set()))
                def initializer_read(m,kind,address,width,value,user):
                    if runtime_tables:return
                    segment=next((entry for entry in initializer_segments if entry[0]<=address and address+width<=entry[1]),None)
                    if segment is None:return
                    pc=m.reg_read(x86.UC_X86_REG_RIP);key=(pc,width,segment[2])
                    entry=initializer_reads.setdefault(key,[0,set()]);entry[0]+=1
                    entry[1].update(range(address,address+width));segment[3].update(range(address,address+width))
                    if segment[2]=='readonly':
                        for at in range(address,address+width):
                            if at in initializer_model_cache:continue
                            explained=False
                            for name,reader,bias in initializer_models:
                                result=C.c_uint64()
                                if reader(at-bias,1,C.byref(result)):
                                    explained=True
                                    if result.value==m.mem_read(at,1)[0]:initializer_model_bytes.setdefault(name,set()).add(at)
                                    else:initializer_model_mismatches.add(at)
                                    break
                            if not explained:initializer_unknown_bytes.add(at)
                            initializer_model_cache[at]=True
                mu.hook_add(UC_HOOK_MEM_READ,initializer_read,begin=0x10000000,end=0x106fffff)
            if args.runtime_tables:
                source_word_mask=[]
                source_input_seed=[]
                source_raw_bias=[];source_store_bias=[]
                source_index_observations=[]
                source_index_map={};source_raw_indices=[]
                if not which:
                    load_sites={0x1052c0e4,0x1052c0f3,0x1052c106,0x1052c112}
                    store_sites={0x1052c1c8,0x1052c1ce,0x1052c1d6,0x1052c1de}
                    def construction_read(m,kind,address,width,value,user):
                        if m.reg_read(x86.UC_X86_REG_RIP) in load_sites:
                            assert width==4 and not (address-0x1003f340)%4
                            source_raw_indices.append((address-0x1003f340)//4)
                            if args.prove_index:
                                pc=m.reg_read(x86.UC_X86_REG_RIP)
                                lane=(0x1052c0e4,0x1052c0f3,0x1052c106,0x1052c112).index(pc)
                                source_index_observations.append(((address-0x1003f340)//4,
                                    (m.reg_read(x86.UC_X86_REG_XMM12)>>(32*lane))&255,
                                    m.reg_read(x86.UC_X86_REG_XMM4)&255,m.reg_read(x86.UC_X86_REG_XMM8)&255,lane))
                            if not source_raw_bias:
                                bias=(m.reg_read(x86.UC_X86_REG_RSI)-0x286834aa-0x1003f340)&((1<<64)-1)
                                assert not bias%4;source_raw_bias.append((bias//4)&255)
                    def construction_write(m,kind,address,width,value,user):
                        if m.reg_read(x86.UC_X86_REG_RIP) not in store_sites:return
                        assert width==4 and source_raw_indices and source_word_mask
                        ordinal,_=source_word_mask[0];base=allocated[ordinal][0]
                        assert base<=address<base+1024 and not (address-base)%4
                        raw_index=source_raw_indices.pop(0);index=(address-base)//4
                        assert raw_index not in source_index_map
                        source_index_map[raw_index]=index
                    mu.hook_add(UC_HOOK_MEM_READ,construction_read,begin=0x1003f340,end=0x1003f73f)
                    mu.hook_add(UC_HOOK_MEM_WRITE,construction_write,begin=cursor,end=0x20fffff)
                    def construction_mask(m,address,ins_size,user):
                        if not source_word_mask:
                            at=(m.reg_read(x86.UC_X86_REG_R11)+4*m.reg_read(x86.UC_X86_REG_RAX))&((1<<64)-1)
                            ordinal=next((j for j,(base,size_) in enumerate(allocated) if base<=at<base+1024),None)
                            assert ordinal is not None,'source store does not address a declared table'
                            bias=(m.reg_read(x86.UC_X86_REG_R11)-allocated[ordinal][0])&((1<<64)-1)
                            assert not bias%4;source_store_bias.append((bias//4)&255)
                            # 52c11e..52c12c broadcasts (R9D XOR low XMM5)
                            # before XORing the raw lookup. The rest of this
                            # output expression uses fixed raw-word arithmetic.
                            source_word_mask.append((ordinal,(m.reg_read(x86.UC_X86_REG_R9D)^m.reg_read(x86.UC_X86_REG_XMM5))&0xffffffff))
                            source_input_seed.append((m.reg_read(x86.UC_X86_REG_XMM4)^m.reg_read(x86.UC_X86_REG_XMM8))&255)
                    mu.hook_add(UC_HOOK_CODE,construction_mask,begin=0x1052c1c8,end=0x1052c1c8)
                def ready(m,address,ins_size,user):
                    if runtime_tables:return
                    runtime_tables.append(classify_allocations(m,allocated))
                    arrays=[bytes(m.mem_read(at,1024)) for at,size_ in allocated if size_ in (1028,1032)]
                    runtime_table_arrays.extend(arrays)
                    if args.trace_rounds:
                        from analyze_table_algebra import independent
                        regular=[];final=[]
                        for ordinal,data in enumerate(arrays):
                            words=[int.from_bytes(data[j:j+4],'little') for j in range(0,1024,4)]
                            ranks=[len(independent([((word^words[0])>>(8*k))&255 for word in words])) for k in range(4)]
                            if ranks==[8]*4:regular.append(ordinal)
                            elif sorted(ranks)==[0,0,0,8]:final.append(ordinal)
                        assert len(regular)==len(final)==4
                        first_lookup=0x10538508 if which else 0x1052e475
                        def trace_step(mm,pc,ins_size,user):
                            if pc==first_lookup:
                                if len(round_traces)>=args.trace_blocks:return
                                trace=LookupTrace(mm,allocated,regular,final,arrays,args.trace_prefix,args.normalize_round_indices,args.normalization_timeout_ms);round_traces.append(trace)
                            if round_traces:round_traces[-1].step(mm,pc,ins_size)
                        m.hook_add(UC_HOOK_CODE,trace_step,begin=first_lookup,
                                   end=0x1053a674 if which else 0x10530963)
                    reference=runtime_reference.setdefault(which,arrays)
                    assert len(reference)==len(arrays)
                    relations=[]
                    for ordinal,(base,current) in enumerate(zip(reference,arrays)):
                        deltas=[int.from_bytes(base[j:j+4],'little')^int.from_bytes(current[j:j+4],'little') for j in range(0,1024,4)]
                        relations.append(dict(table_ordinal=ordinal,equal_to_first_case=base==current,
                                              wordwise_xor_delta_constant=len(set(deltas))==1,
                                              exact_input_output_xor_translation_solutions=xor_relation(base,current)))
                    runtime_tables[0]['relations_to_first_case']=relations
                    if not which:
                        assert len(source_word_mask)==1
                        ordinal,mask=source_word_mask[0];base_mask=mask_reference.setdefault((which,ordinal),mask)
                        runtime_tables[0]['source_word_mask_table_ordinal']=ordinal
                        runtime_tables[0]['source_word_mask_predicts_output_translation']=(
                            xor_relation(reference[ordinal],arrays[ordinal],base_mask^mask)==1)
                        assert len(source_index_map)==256 and not source_raw_indices
                        assert set(source_index_map)==set(source_index_map.values())==set(range(256))
                        base_indices=index_reference.setdefault(which,source_index_map.copy())
                        input_shift=base_indices[0]^source_index_map[0]
                        runtime_tables[0]['raw_index_xor_store_index_constant']=len({j^i for j,i in source_index_map.items()})==1
                        columns=[source_index_map[1<<j]^source_index_map[0] for j in range(8)]
                        runtime_tables[0]['source_index_mapping_affine']=all(
                            source_index_map[x]==(source_index_map[0]^reduce(int.__xor__,
                              (columns[j] for j in range(8) if x&(1<<j)),0)) for x in range(256))
                        assert len(source_input_seed)==1
                        input_seed=source_input_seed[0];base_input_seed=input_seed_reference.setdefault(which,input_seed)
                        runtime_tables[0]['low_xmm4_xor_xmm8_predicts_input_translation']=(input_shift==(input_seed^base_input_seed))
                        runtime_tables[0]['source_construction_indices_checked']=len(source_index_map)
                        runtime_tables[0]['source_index_mapping_deltas_constant']=all(
                            (base_indices[j]^source_index_map[j])==input_shift for j in range(256))
                        runtime_tables[0]['source_input_output_masks_predict_complete_table']=(
                            xor_relation(reference[ordinal],arrays[ordinal],base_mask^mask,input_shift)==1)
                        if args.prove_index:
                            assert len(source_raw_bias)==len(source_store_bias)==1
                            runtime_tables[0]['source_index_proof']=index_proof.prove(source_raw_bias[0],source_store_bias[0])
                            verification=index_proof.verify_observations(source_raw_bias[0],source_store_bias[0],
                                                                       source_index_observations,source_index_map)
                            assert verification['observed_indices']==verification['raw_index_matches']==verification['store_index_matches']==256
                            runtime_tables[0]['symbolic_model_original_checks']=verification
                    def heap_read(mm,kind,at,width,value,ordinal):
                        pc=mm.reg_read(x86.UC_X86_REG_RIP);key=(ordinal,pc,width)
                        entry=runtime_uses.setdefault(key,[0,set()]);entry[0]+=1
                        entry[1].add(at-allocated[ordinal][0])
                        offset=at-allocated[ordinal][0]
                        if width==4 and 0<=offset<=1020 and not offset%4:runtime_word_reads[ordinal]+=1
                    for ordinal,(at,size_) in enumerate(allocated):
                        m.hook_add(UC_HOOK_MEM_READ,heap_read,ordinal,begin=at,end=at+size_-1)
                boundary=0x105374b5 if which else 0x1052d5d5
                mu.hook_add(UC_HOOK_CODE,ready,begin=boundary,end=boundary)
            table_reads=Counter();table_indices={};table_order=[];ambiguous_table_reads=[0]
            if windows:
                def table_access(m,kind,address,width,value,user):
                    # Overlapping candidate windows remain ambiguous. Do not
                    # turn a static window into an asserted object boundary.
                    at=bisect_right(window_starts,address)-1;matches=[]
                    while at>=0 and address<window_starts[at]+1024:
                        start,exact=windows[at]
                        if width==4 and not (address-start)%4 and address+width<=start+1024:
                            matches.append((start,exact))
                        at-=1
                    if len(matches)>1:ambiguous_table_reads[0]+=1
                    pc=m.reg_read(x86.UC_X86_REG_RIP)
                    for start,exact in matches:
                        key=(start,pc,exact)
                        if start not in table_indices:table_order.append(start);table_indices[start]=set()
                        table_indices[start].add((address-start)//4);table_reads[key]+=1
                mu.hook_add(UC_HOOK_MEM_READ,table_access,begin=0x10000000,end=0x100cf9f7)
            copy_checks=dict(byte_comparisons=0,byte_mismatches=0,index_mismatches=0,stage0_counter_mismatches=0,stage1_counter_mismatches=0);copy_states=[]
            copy_output=bytearray(size);copy_input=None
            raw_key_inputs=None
            if args.buffer_accesses or args.copy_stage_checks or args.key_schedule:
                fields=((24,0xf24d0dd1b2cce148),(8,0xc43e05c519b61228),(16,0xe0d7cdbb906643cd)) if not which else ((0,0xbf6e2aefd239cb18),(8,0xdf7dabda77790d68),(24,0xe40c57b7a130b973))
                buffers=[(struct.unpack_from('<Q',raw,offset)[0]+addend)&((1<<64)-1) for offset,addend in fields]
                copy_input=bytes(mu.mem_read(buffers[1 if which else 2],size))
                if args.key_schedule:raw_key_inputs=(bytes(mu.mem_read(buffers[0],16)),copy_input)
                def buffer_access(m,kind,address,width,value,index):
                    pc=m.reg_read(x86.UC_X86_REG_RIP);offset=address-buffers[index]
                    if args.buffer_accesses:buffer_events.append(dict(buffer=index,offset=offset,width=width,
                                                                      access='write' if kind==UC_MEM_WRITE else 'read',pc=hex(pc)))
                    if args.copy_stage_checks and kind==UC_MEM_WRITE and pc==(0x10531756 if which else 0x10527aaa):
                        assert width==1
                        input_byte=m.mem_read(buffers[1 if which else 2]+offset,1)[0]
                        state=m.reg_read(x86.UC_X86_REG_R13)&255 if which else m.mem_read(m.reg_read(x86.UC_X86_REG_RBP)-0x78,1)[0]
                        copy_output[offset]=value&255
                        copy_checks['byte_comparisons']+=1;copy_checks['byte_mismatches']+=codecs[which](offset,state,input_byte)!=(value&255)
                        copy_checks['index_mismatches']+=(m.reg_read(x86.UC_X86_REG_R9D if which else x86.UC_X86_REG_R13D)!=offset)
                        if which:copy_checks['stage1_counter_mismatches']+=state!=((2*offset)&255)
                        else:
                            copy_states.append((offset,state&12,input_byte&12))
                            copy_checks['stage0_counter_mismatches']+=state!=((0xd0+2*offset)&255)
                for j,address in enumerate(buffers):mu.hook_add(UC_HOOK_MEM_READ|UC_HOOK_MEM_WRITE,buffer_access,j,begin=address,end=address+4095)
            def external(m,address,ins_size,user):
                if address==0x900000:m.emu_stop();return
                if address not in stubs:return
                name=stubs[address];imports.append(name)
                a,b,c=[m.reg_read(reg) for reg in (x86.UC_X86_REG_RDI,x86.UC_X86_REG_RSI,x86.UC_X86_REG_RDX)];value=0
                if name in ('malloc','calloc'):
                    n=a if name=='malloc' else a*b;value=allocation[0];allocation[0]=(value+n+15)&~15
                    assert n<=0x100000 and allocation[0]<=0x2100000
                    allocated.append((value,n))
                elif name=='free':pass
                elif name in ('memcpy','memmove'):m.mem_write(a,bytes(m.mem_read(b,c)));value=a
                elif name=='memset':m.mem_write(a,bytes([b&255])*c);value=a
                elif name=='arc4random':value=int.from_bytes(bytes(rng.randrange(256) for _ in range(4)),'little')
                elif name=='arc4random_buf':m.mem_write(a,bytes(rng.randrange(256) for _ in range(b)))
                elif name=='gettimeofday':m.mem_write(a,struct.pack('<qq',1700000000,123456))
                else:faults.append('unsupported import '+name);m.emu_stop();return
                sp=m.reg_read(x86.UC_X86_REG_RSP);ret=int.from_bytes(m.mem_read(sp,8),'little')
                m.reg_write(x86.UC_X86_REG_RAX,value);m.reg_write(x86.UC_X86_REG_RSP,sp+8);m.reg_write(x86.UC_X86_REG_RIP,ret)
            def block(m,address,size,user):
                if 0x100d0000<=address<0x1066d000:all_blocks[address-0x10000000]=size
            def rdtsc(m,address,size,user):
                if size not in (2,3) or bytes(m.mem_read(address,size)) not in (b'\x0f\x31',b'\x0f\x01\xf9'):return
                value=clock(None);m.reg_write(x86.UC_X86_REG_RAX,value&0xffffffff);m.reg_write(x86.UC_X86_REG_RDX,value>>32)
                if size==3:m.reg_write(x86.UC_X86_REG_RCX,0)
                m.reg_write(x86.UC_X86_REG_RIP,address+size)
            mu.hook_add(UC_HOOK_CODE,external,begin=0x800000,end=0x900000)
            mu.hook_add(UC_HOOK_BLOCK,block)
            # Only executed exact opcode boundaries are intercepted.
            for path,bias in ((app,0),(core,0x10000000)):
                image=path.read_bytes();phoff=struct.unpack_from('<Q',image,32)[0];pe,pn=struct.unpack_from('<HH',image,54)
                for j in range(pn):
                    kind,flags,off,va,_,length,_,_=struct.unpack_from('<IIQQQQQQ',image,phoff+j*pe)
                    if kind!=1 or not flags&1:continue
                    for opcode in (b'\x0f\x31',b'\x0f\x01\xf9'):
                        start=0;segment=image[off:off+length]
                        while True:
                            at=segment.find(opcode,start)
                            if at<0:break
                            mu.hook_add(UC_HOOK_CODE,rdtsc,begin=bias+va+at,end=bias+va+at);start=at+1
            try:mu.emu_start(s.cpu.pc,0x900000,count=2000000)
            except UcError as error:faults.append(type(error).__name__)
            pc=mu.reg_read(x86.UC_X86_REG_RIP)
            state_models=set()
            if copy_states:
                state_models={(a,b) for a in range(16) for b in range(16) if all(((a*i+b)&12)==state for i,state,byte in copy_states)}
                copy_checks['stage0_index_only_model_count']=len(state_models)
                copy_checks['stage0_previous_raw_byte_relation']=all(state==copy_states[j-1][2] for j,(i,state,byte) in enumerate(copy_states) if j)
            if args.copy_stage_checks and copy_checks['byte_comparisons']==size:
                inp=C.create_string_buffer(copy_input,size);out=C.create_string_buffer(size)
                assert streams[which](out,size,inp,size,size)==0
                copy_checks['complete_copy_helper_equal']=bytes(out)==copy_output
            captures.append(dict(which=which,size=size,output=bytes(mu.mem_read(destination,size)),
                                 returned=pc==0x900000,pc=pc,imports=sorted(set(imports)),faults=faults,
                                 buffer_events=buffer_events,copy_checks=copy_checks,state_models=state_models))
            if args.runtime_tables:
                assert len(runtime_tables)==1,'data block boundary not reached'
                runtime_tables[0]['uses_after_first_block_boundary']=[
                    dict(allocation_ordinal=ordinal,pc=hex(pc),width=width,reads=count,
                         distinct_offsets=len(offsets),minimum_offset=min(offsets),maximum_offset=max(offsets))
                    for (ordinal,pc,width),(count,offsets) in sorted(runtime_uses.items())]
                if args.table_algebra:
                    assert len(runtime_table_arrays)==len(allocated)==8
                    ordering=sorted(range(8),key=lambda j:runtime_word_reads[j]);final=sorted(ordering[:4]);regular=sorted(ordering[4:])
                    assert max(runtime_word_reads[j] for j in final)<min(runtime_word_reads[j] for j in regular)
                    runtime_tables[0]['word_table_read_counts']=[runtime_word_reads[j] for j in range(8)]
                    runtime_tables[0]['word_mixing_algebra']=analyze_algebra(runtime_table_arrays,regular,final)
                    round_models=[]
                    if args.round_substitutions:
                        runtime_tables[0]['round_substitutions']=analyze_round(runtime_table_arrays,regular,
                                                                             round_models.append if args.key_schedule else None)
                    if args.trace_rounds:
                        assert len(round_traces)==min(args.trace_blocks,size//16)
                        runtime_tables[0]['lookup_dataflow']=round_traces[0].summary()
                        runtime_tables[0]['lookup_dataflows']=[trace.summary() for trace in round_traces]
                        if args.key_schedule:
                            schedules=[];logical_outputs=[];baseline_reused=which in masked_kernel_reference
                            for block_number,trace in enumerate(round_traces):
                                key_matches=[];io_relations=[];encoded_proofs=[];encoding_relations=[];encoding_profiles=[]
                                def remember_key(master,details):
                                    reference=schedule_key_reference.setdefault(which,master);key_matches.append(master==reference)
                                    if args.encoded_key_arithmetic:
                                        encoded_proofs.append(analyze_encoded_schedule(trace,details,regular))
                                    decoders=details['model']['decoders']
                                    from apple_music_source.crypto.aes import _gmul,_gpow
                                    public_families={tuple(_gmul(scale,_gpow(1<<bit,1<<power)) for bit in range(8))
                                                     for power in range(8) for scale in range(1,256)}
                                    encoding_profiles.append(dict(
                                        distinct_byte_maps=len({tuple(decoder) for decoder in decoders}),
                                        bit_permutation_maps=sum(len(set(decoder))==8 and all(value and not value&(value-1) for value in decoder) for decoder in decoders),
                                        field_scalar_Frobenius_maps=sum(tuple(decoder) in public_families for decoder in decoders),
                                        scope='RAM-only structural classification; no matrix, scalar or permutation values emitted'))
                                    schedule_encoding_reference.setdefault(which,decoders)
                                    if 0 in schedule_encoding_reference and which==1:
                                        before=schedule_encoding_reference[0]
                                        encoding_relations.append(dict(
                                            equal_byte_maps_in_physical_order=sum(a==b for a,b in zip(before,decoders)),
                                            byte_maps_matching_any_first_kernel_map=sum(any(a==b for a in before) for b in decoders),
                                            scope='RAM-only comparison of the selected encoding models; no map bytes emitted'))
                                    logical=recover_input(master,details,regular);ciphertext=AES(master).encrypt_block(logical)
                                    raw_iv,raw_data=raw_key_inputs;data=raw_data[16*block_number:16*(block_number+1)]
                                    chain=raw_iv if block_number==0 else logical_outputs[-1]
                                    raw_input=bytes(a^b for a,b in zip(chain,data));raw_output=bytes(mu.mem_read(destination+16*block_number,16))
                                    input_delta=bytes(a^b for a,b in zip(logical,raw_input));output_delta=bytes(a^b for a,b in zip(ciphertext,raw_output))
                                    before=schedule_io_reference.setdefault(which,(input_delta,output_delta))
                                    if block_number==0 and which not in masked_kernel_reference:
                                        masked_kernel_reference[which]=MaskedCBC(master,input_delta,output_delta)
                                        static_parameters[which]=(master,input_delta,output_delta)
                                    relation=dict(logical_input_equals_raw_iv_xor_data=logical==raw_input,
                                                  logical_ciphertext_equals_raw_output=ciphertext==raw_output,
                                                  input_xor_delta_equals_first_case=input_delta==before[0],
                                                  output_xor_delta_equals_first_case=output_delta==before[1])
                                    if block_number:
                                        previous=schedule_chain_reference.setdefault(which,input_delta)
                                        relation['following_block_input_delta_equals_first_following_block']=input_delta==previous
                                    io_relations.append(relation);logical_outputs.append(ciphertext)
                                schedule=analyze_schedule(trace,round_models,regular,remember_key)
                                schedule['block']=block_number;schedule['matching_keys_equal_first_case']=key_matches
                                schedule['logical_buffer_relations']=io_relations;schedules.append(schedule)
                                if encoded_proofs:schedule['encoded_key_arithmetic']=encoded_proofs
                                if encoding_relations:schedule['encoding_relations_to_first_kernel']=encoding_relations
                                if encoding_profiles:schedule['encoding_model_structure']=encoding_profiles
                            runtime_tables[0]['round_key_schedule']=schedules[0];runtime_tables[0]['round_key_schedules']=schedules
                            if which in masked_kernel_reference:
                                raw_iv,raw_data=raw_key_inputs
                                reference=masked_kernel_reference[which]
                                original_output=bytes(mu.mem_read(destination,size))
                                predicted=reference.encrypt(raw_data,raw_iv)
                                runtime_tables[0]['table_free_message']=dict(
                                    bytes=size,baseline_parameters_reused=baseline_reused,
                                    encrypt_equal_original=predicted==original_output,
                                    decrypt_original_equal_input=reference.decrypt(original_output,raw_iv)==raw_data)
                captures[-1]['runtime_tables']=runtime_tables[0]
                if args.initializer_read_map:
                    runtime_tables[0]['initializer_reads']=dict(
                        segments=[dict(role=role,distinct_bytes=len(addresses)) for begin,end,role,addresses in initializer_segments],
                        sites=[dict(pc=hex(pc),width=width,segment_role=role,reads=entry[0],distinct_bytes=len(entry[1]))
                               for (pc,width,role),entry in sorted(initializer_reads.items())],
                        readonly_model_matching_bytes={name:len(addresses) for name,addresses in initializer_model_bytes.items()},
                        readonly_model_mismatching_bytes=len(initializer_model_mismatches),
                        readonly_bytes_without_existing_source_model=len(initializer_unknown_bytes),
                        scope='observed reads before first-block boundary only; no values, lookup indices or data-dependent addresses emitted')
            if windows:
                captures[-1]['substitution_reads']=dict(
                    candidate_windows_read=len(table_indices),ambiguous_reads=ambiguous_table_reads[0],
                    first_use_order=[hex(address) for address in table_order],
                    windows=[dict(address=hex(start),distinct_indices=len(indices))
                             for start,indices in sorted(table_indices.items())],
                    sites=[dict(address=hex(start),pc=hex(pc),exact_inversion_family=exact,reads=count)
                           for (start,pc,exact),count in sorted(table_reads.items())])
        except Exception as error:errors.append(type(error).__name__)
        finally:rng.setstate(saved_rng);ticks[0]=saved_tick
    callback=callback_type(capture)
    declaration='\nstatic int ams_probe_running;\nstatic void (*ams_capture)(const wrapper_kg_native_state*,const wrapper_kg_payload_region*,size_t,uint64_t);\n'
    with tempfile.TemporaryDirectory(prefix='ams-kernel-original-') as temp:
        body=(source/'spc_generate.c').read_text().replace('} kg_runtime;','} kg_runtime;'+declaration,1)
        needle='status=wrapper_kg_native_run('
        assert body.count(needle)==1
        body=body.replace(needle,'if(ams_probe_running&&ams_capture){ams_probe_running=0;ams_capture(&r->state,r->regions,KG_REGIONS,KG_HEAP+r->allocated);}\n        '+needle,1)
        helper=HELPER.replace('int ok=kg_execute(','ams_probe_running=1;\n int ok=kg_execute(',1).replace('result->pc=r->state.cpu.pc;','ams_probe_running=0;\n result->pc=r->state.cpu.pc;',1)
        body+='\n'+helper+'\nvoid ams_capture_set(void (*f)(const wrapper_kg_native_state*,const wrapper_kg_payload_region*,size_t,uint64_t)){ams_capture=f;}\n'
        cfile=Path(temp)/'generate.c';library=Path(temp)/'generate.so';cfile.write_text(body)
        codec_source=Path(__file__).resolve().parents[1]/'src/apple_music_source/_native/copy_codecs.c'
        model_sources=[str(codec_source.parent/name) for name in ('control_refs.c','integrity_codec_data.c')] if args.initializer_read_map else []
        subprocess.run(['cc','-std=c99','-O2','-shared','-fPIC','-I'+str(source),str(cfile),str(source/'ckc_packet.c'),str(codec_source),*model_sources,'-L'+str(build),'-lwrapper_spc_native','-Wl,-rpath,'+str(build),'-o',str(library)],check=True,capture_output=True)
        lib=C.CDLL(str(library));lib.ams_capture_set.argtypes=[callback_type];lib.ams_capture_set(callback)
        if args.initializer_read_map:
            for name,bias in (('control_refs',0),('integrity_codec_data',0x10000000)):
                reader=getattr(lib,'ams_'+name+'_read');reader.argtypes=[C.c_uint64,C.c_uint,C.POINTER(C.c_uint64)];reader.restype=C.c_int
                initializer_models.append((name,reader,bias))
        for name in ('ams_copy0_byte','ams_copy1_byte'):
            function=getattr(lib,name);function.argtypes=[C.c_uint32,C.c_uint8,C.c_uint8];function.restype=C.c_uint8;codecs.append(function)
        for name in ('ams_copy0_forward','ams_copy1_forward'):
            function=getattr(lib,name);function.argtypes=[C.c_void_p,C.c_size_t,C.c_void_p,C.c_size_t,C.c_size_t];function.restype=C.c_int;streams.append(function)
        probe=lib.ams_kernel_probe;probe.argtypes=[C.c_void_p,C.c_uint,C.c_uint,C.POINTER(Result),C.POINTER(C.c_uint64),C.POINTER(C.c_uint64),C.POINTER(C.c_ubyte),C.c_void_p,C.c_uint,C.c_uint];probe.restype=C.c_int
        certificate=certificate_only(args.public_certificate_fixture)
        assert 0<=args.random_cases<=32
        sample_rng=random.Random(0x1a3e25e);common_state_models=None
        for which in ((args.kernel,) if args.kernel is not None else (0,1)):
            rng.seed(0xc017);ticks[0]=0
            with SourceSession(library,0,certificate,b'invented-original-kernel',bytes(range(16)),entropy=entropy,clock=clock,time=wall) as session:
                trial_rng=rng.getstate();trial_tick=ticks[0]
                for size in (args.length or (16,32,48,64)):
                    assert 0<size<=64 and size%16==0
                    trials=[('fixed IV/data',None)]
                    trials.extend(('random IV/data',bytes(sample_rng.randrange(256) for _ in range(16+size))) for _ in range(args.random_cases))
                    if args.input_controls:
                        initial=bytes((i*17)&255 for i in range(16))+bytes((i*17+(31 if which else 62))&255 for i in range(size))
                        for kind,flip_iv,flip_data in (('data-only bit flip',False,True),('IV-only bit flip',True,False),('equal IV/data bit flip',True,True)):
                            trial=bytearray(initial)
                            if flip_iv:trial[0]^=1
                            if flip_data:trial[16]^=1
                            trials.append((kind,bytes(trial)))
                    if args.repeat_fixed_case:trials.append(('fixed IV/data',None))
                    first_output=None
                    for sample,(input_kind,context) in enumerate(trials):
                        ctx=C.create_string_buffer(context) if context else None
                        result=Result();changed=(C.c_uint64*3)();returned=C.c_uint64();output=(C.c_ubyte*192)();before=len(captures)
                        if args.freeze_trial_inputs:rng.setstate(trial_rng);ticks[0]=trial_tick
                        code=probe(session.handle,which,size,C.byref(result),changed,C.byref(returned),output,ctx,len(context) if context else 0,3 if context else 0)
                        assert not errors and len(captures)==before+1,(errors,len(captures),before)
                        original=captures[-1];destination=2 if which else 1
                        observed=bytes(output)[destination*64:destination*64+size]
                        if first_output is None:first_output=observed
                        rows.append(dict(function=hex(0x10530970 if which else 0x10526bc0),size=size,sample=sample,
                                         invented_input_kind=input_kind,output_equal_to_first_case=observed==first_output,
                                         source_returned=code==1,source_pc=hex(result.pc),source_fault_size=result.fault_size,
                                         original_returned=original['returned'],original_pc=hex(original['pc']),
                                         original_imports=original['imports'],original_faults=original['faults'],
                                         output_equal=bytes(output)[destination*64:destination*64+size]==original['output']))
                        if args.buffer_accesses:rows[-1]['original_buffer_accesses']=original['buffer_events']
                        if windows:rows[-1]['substitution_reads']=original['substitution_reads']
                        if args.runtime_tables:rows[-1]['runtime_tables']=original['runtime_tables']
                        if args.copy_stage_checks:
                            rows[-1]['original_copy_stage_checks']=original['copy_checks']
                            if which==0:common_state_models=original['state_models'] if common_state_models is None else common_state_models&original['state_models']
                if args.native_prediction_cases:
                    assert which in masked_kernel_reference,'no baseline parameter candidate'
                    reference=masked_kernel_reference[which];checks=[]
                    capture_enabled[0]=False
                    try:
                        for trial in range(args.native_prediction_cases):
                            size=16*(1+trial%4)
                            context=bytes(sample_rng.randrange(256) for _ in range(16+size));ctx=C.create_string_buffer(context)
                            result=Result();changed=(C.c_uint64*3)();returned=C.c_uint64();output=(C.c_ubyte*192)()
                            code=probe(session.handle,which,size,C.byref(result),changed,C.byref(returned),output,ctx,len(context),3)
                            destination=2 if which else 1
                            observed=bytes(output)[destination*64:destination*64+size]
                            checks.append(dict(bytes=size,source_returned=code==1,
                                encrypt_equal_source=reference.encrypt(context[16:],context[:16])==observed,
                                decrypt_source_equal_input=reference.decrypt(observed,context[:16])==context[16:]))
                    finally:capture_enabled[0]=True
                    prediction_rows.append(dict(kernel=which,parameters_reused_without_refitting=True,
                        frozen_host_rng_and_clock=False,cases=checks,
                        scope='held-out invented inputs against source runtime only; baseline derived from original instructions'))
                if args.cross_session_predictions:
                    assert which in masked_kernel_reference
                    capture_enabled[0]=False
                    try:
                        rng.seed(0xa67193+which);ticks[0]=0
                        with SourceSession(library,0,certificate,b'independent-invented-content',bytes(range(32,48)),entropy=entropy,clock=clock,time=wall) as fresh:
                            reference=masked_kernel_reference[which];checks=[]
                            for trial in range(args.cross_session_predictions):
                                size=16*(1+trial%4);context=bytes(sample_rng.randrange(256) for _ in range(16+size));ctx=C.create_string_buffer(context)
                                result=Result();changed=(C.c_uint64*3)();returned=C.c_uint64();output=(C.c_ubyte*192)()
                                code=probe(fresh.handle,which,size,C.byref(result),changed,C.byref(returned),output,ctx,len(context),3)
                                destination=2 if which else 1;observed=bytes(output)[destination*64:destination*64+size]
                                checks.append(dict(bytes=size,source_returned=code==1,
                                    encrypt_equal_source=reference.encrypt(context[16:],context[:16])==observed,
                                    decrypt_source_equal_input=reference.decrypt(observed,context[:16])==context[16:]))
                    finally:capture_enabled[0]=True
                    cross_session_rows.append(dict(kernel=which,fresh_session=True,changed_entropy_content_and_device_seed=True,
                        parameters_reused_without_refitting=True,cases=checks))
    exported=None
    if args.export_static_parameters is not None:
        assert set(static_parameters)=={0,1} and len(cross_session_rows)==2 and len(prediction_rows)==2
        assert rows and all(row['source_returned'] and row['original_returned'] and row['output_equal'] for row in rows)
        assert all(check['source_returned'] and check['encrypt_equal_source'] and check['decrypt_source_equal_input']
                   for group in cross_session_rows+prediction_rows for check in group['cases'])
        from emit_corelskd_parameters import emit
        exported=emit(args.export_static_parameters,static_parameters)
    report=dict(status='original/source kernel differential investigation',core_sha256=HASH,cases=rows,
                native_table_free_predictions=prediction_rows,
                cross_session_predictions=cross_session_rows,static_parameter_export=exported,
                frozen_host_rng_and_clock=args.freeze_trial_inputs,
                stage0_common_index_only_models=len(common_state_models) if common_state_models is not None else None,
                core_blocks=[dict(begin=a,size=n) for a,n in sorted(all_blocks.items())],
                scope='invented source-runtime snapshots; originals are developer oracles only; snapshots, buffers and maps stay RAM-only; optional export writes only named vendor parameters after fresh-session checks, never account/session/content secrets; no full standalone closure claim')
    args.output.write_text(json.dumps(report,indent=2)+'\n')
    print(json.dumps(dict(status=report['status'],cases=len(rows),
                          source_returns=sum(row['source_returned'] for row in rows),
                          original_returns=sum(row['original_returned'] for row in rows),
                          output_matches=sum(row['output_equal'] for row in rows),
                          candidate_window_counts=[row['substitution_reads']['candidate_windows_read'] for row in rows] if windows else None,
                          scope=report['scope'])))


if __name__=='__main__':main()
