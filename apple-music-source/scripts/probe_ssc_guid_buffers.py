"""Compare complete StoreServices blocks and a prefix-derived AES/CBC model.

Developer oracles only; invented device profiles, no account/session material.
All words, snapshots, encoding maps and candidate cipher parameters stay in RAM.
Later index multisets are observational checks, not a proof of round ordering.
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

from analyze_ssc_guid_column import build
from analyze_guid_prefix_states import analyze
from analyze_round_key_schedule import recover_input
from analyze_table_algebra import apply
from analyze_guid_buffer_cbc import xor
from probe_auth_substitution_reads import group_wrappers
from scan_auth_substitutions import TARGETS
from trace_guid_rounds import Native,Region,SHIM
from clone_guid_span import clone_span
from trace_lookup_dataflow import LookupTrace
from trace_ssc_guid_rounds import BEGIN,BASES

END=0x1fddc2
INVERSE_OUTPUTS=(0x23572d,0x2357b4,0x2357c5,0x2357e9,0x235966,0x235c38,0x235c47,0x235c94,0x235cbb,0x235d95,0x235ea3,0x235f3b,0x235f49,0x235fc6,0x236052,0x23608e)
INPUTS=(0x1f78ca,0x1f7971,0x1f79d7,0x1f7a57,0x1f7b20,0x1f7b74,0x1f7bb4,0x1f7c8d,
        0x1f7d8a,0x1f7e18,0x1f7eac,0x1f7f0b,0x1f7fb9,0x1f8010,0x1f8086,0x1f80ed)


def replay(oracle,expected,normalization,caller_input,source_regions):
    from unicorn import UC_HOOK_CODE,UC_HOOK_MEM_READ,UC_HOOK_MEM_WRITE
    from unicorn import x86_const as r
    from capstone import CS_OP_MEM
    from apple_music_source.crypto.aes import AES
    mu=oracle.mu;observed=[];writes=[]
    trace=LookupTrace(mu,[(base,1024) for base in BASES],range(4),range(4,8),maximum_regular_reads=96 if BEGIN==0x2316f0 else 80)
    z=trace.z;maps=[]
    for mapping in normalization['indices']:
        inverse=[0]*256
        for value,index in enumerate(mapping):inverse[index]=value
        origin=inverse[0];columns=[inverse[1<<bit]^origin for bit in range(8)]
        assert all(inverse[value]==origin^apply(columns,value) for value in range(256))
        maps.append((inverse,origin,columns))
    def canonical(ordinal,value):
        if ordinal>=4:return value
        _,origin,columns=maps[ordinal];result=z.BitVecVal(origin,8)
        for bit,column in enumerate(columns):result^=z.If(z.Extract(bit,bit,value)==1,z.BitVecVal(column,8),z.BitVecVal(0,8))
        return result
    prefix_relations=None
    if BEGIN==0x2316f0:
        incoming_r8=mu.reg_read(r.UC_X86_REG_R8);incoming_rsi=(mu.reg_read(r.UC_X86_REG_RSI)&0xffffffff)^0x1952ce0a
        u1=maps[1][0][incoming_rsi] if 0<=incoming_rsi<256 else None
        u2=mu.reg_read(r.UC_X86_REG_R15)&255
        expected_edx=z.simplify(z.substitute(normalization['prefix_edx'],(normalization['prefix_variables'][1],z.BitVecVal(u1,8)))).as_long() if u1 is not None else None
        expected_low=z.simplify(z.substitute(normalization['prefix_r11_low'],(normalization['prefix_variables'][2],z.BitVecVal(u2,8)))).as_long()
        prefix_relations=dict(r8_is_one_byte=0<=incoming_r8<256,edx_matches_source_index_function=(mu.reg_read(r.UC_X86_REG_RDX)&0xffffffff)==expected_edx,r11_low_matches_r15_source_chain=(mu.reg_read(r.UC_X86_REG_R11)&255)==expected_low,foreign_state_independence=normalization['foreign_state_independence'])
        assert all(value is True or value=='unsat' for value in prefix_relations.values()),prefix_relations
    trace.index_expression_transform=canonical
    trace.index_value_transform=lambda ordinal,value:maps[ordinal][0][value] if ordinal<4 else value
    def code(m,pc,size,user):
        if not BEGIN<=pc<END:m.emu_stop();return
        trace.step(m,pc,size)
    def read(m,kind,address,width,value,ordinal):
        if width==4 and not (address-BASES[ordinal])%4:
            observed.append((m.reg_read(r.UC_X86_REG_RIP),ordinal,(address-BASES[ordinal])//4,int.from_bytes(m.mem_read(address,4),'little')))
    def write(m,kind,address,width,value,user):
        if width!=1:return
        pc=m.reg_read(r.UC_X86_REG_RIP);ins=next(trace.decoder.disasm(bytes(m.mem_read(pc,16)),pc,count=1))
        if pc in INVERSE_OUTPUTS if BEGIN==0x2316f0 else ins.operands and ins.operands[0].type==CS_OP_MEM and ins.reg_name(ins.operands[0].mem.base)=='r11':writes.append(address)
    handles=[mu.hook_add(UC_HOOK_CODE,code),mu.hook_add(UC_HOOK_MEM_WRITE,write)]
    for ordinal,base in enumerate(BASES):handles.append(mu.hook_add(UC_HOOK_MEM_READ,read,ordinal,begin=base,end=base+1023))
    error=None
    try:mu.emu_start(BEGIN,END,count=200000)
    except Exception as exception:error=type(exception).__name__
    finally:
        for handle in handles:mu.hook_del(handle)
    candidates=[];all_events=[dict(ordinal=ordinal,index=maps[ordinal][0][index]) for _,ordinal,index,_ in observed if ordinal<4]
    prefix=analyze(trace,normalization['models'],range(4),lambda key,details:candidates.append((key,details)),all_lookup_events=all_events)
    contiguous=len(set(writes))==16 and max(writes)-min(writes)==15
    source_equal=None;private=None
    if contiguous and len(candidates)==1:
        key,details=candidates[0];logical=recover_input(key,details,range(4));actual=bytes(mu.mem_read(min(writes),16))
        for address,data in source_regions:
            offset=min(writes)-address
            if 0<=offset and offset+16<=len(data):source_equal=actual==data[offset:offset+16];break
        private=(key,logical,xor((AES(key).decrypt_block(logical) if details['cipher_direction']==-1 else AES(key).encrypt_block(logical)),actual),caller_input,actual)
    return dict(original_execution_error=error,original_source_word_reads_equal=observed==expected,original_lookup_reads=len(observed),
                source_lookup_reads=len(expected),source_prefix_relation_checks=prefix_relations,output_store_events=len(writes),contiguous_16_byte_output=contiguous,
                source_original_complete_output_equal=source_equal,lookup_dataflow=trace.summary(),prefix_state_hypothesis=prefix),private


def main():
    global BEGIN,END,BASES,INPUTS
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('checkout',type=Path);parser.add_argument('--output',type=Path,required=True)
    parser.add_argument('--path',choices=('forward','inverse'),default='forward')
    parser.add_argument('--blocks',type=int,choices=(2,8),default=2)
    parser.add_argument('--profile-set',choices=('primary','independent'),default='primary')
    parser.add_argument('--verify-fixed',action='store_true',help='Disable fitting and compare unchanged package constants on independent profiles')
    parser.add_argument('--export-parameters',type=Path,help='Emit named static parameters only after full-stream primary oracle checks')
    args=parser.parse_args();assert not args.verify_fixed or args.export_parameters is None and args.profile_set=='independent';assert args.export_parameters is None or args.blocks==8 and args.profile_set=='primary';root=args.checkout.resolve();sys.path[:0]=[str(root/'tools/auth'),str(root/'tools/crypto/keygen_experimental'),str(Path(__file__).resolve().parents[1]/'src')]
    from device_identity import derive_android_guid_fields
    from apple_music_source.crypto.masked_cbc import MaskedCBC
    filename,digest=TARGETS['storeservices'];image=(root/'rootfs/system/lib64'/filename).read_bytes();assert hashlib.sha256(image).hexdigest()==digest
    if args.path=='inverse':
        BEGIN,END=0x2316f0,0x2360e2
        BASES=(0x9a1a0,0x9c500,0x9a6f0,0x9de30,0x98a60,0x9da20,0x9ed30,0x9ac80)
        from analyze_ssc_second_column import build as build_inverse
        from inventory_guid_word_tables import translated_instructions,root as register_root
        from capstone import Cs,CS_ARCH_X86,CS_MODE_64,CS_OP_MEM,CS_AC_READ,CS_OP_REG
        decoder=Cs(CS_ARCH_X86,CS_MODE_64);decoder.detail=True;pointers={'r14'};pcs=[]
        for ins in translated_instructions(root,image,decoder,'storeservices',0x230ed0,BEGIN):
            if any(op.type==CS_OP_MEM and op.size==1 and op.access&CS_AC_READ and ins.reg_name(op.mem.base) in pointers for op in ins.operands):pcs.append(ins.address)
            propagate=False
            if ins.mnemonic=='mov' and len(ins.operands)==2 and ins.operands[0].type==CS_OP_REG and ins.operands[0].size==8:
                op=ins.operands[1]
                propagate=op.type==CS_OP_REG and ins.reg_name(op.reg) in pointers or op.type==CS_OP_MEM and ins.reg_name(op.mem.base)=='rbp' and not op.mem.index and op.mem.disp==-0x38
            pointers.difference_update(register_root(ins.reg_name(reg)) for reg in ins.regs_access()[1])
            if propagate:pointers.add(ins.reg_name(ins.operands[0].reg))
        assert len(pcs)==16,(len(pcs),[hex(pc) for pc in pcs]);INPUTS=tuple(pcs)
        normalization=None if args.verify_fixed else build_inverse(image)
    else:normalization=None if args.verify_fixed else build(image)
    snapshots={};events={};inputs={};outputs={};final={};current=[-1];errors=[]
    callback_type=C.CFUNCTYPE(None,C.c_uint,C.c_uint,C.POINTER(Native),C.POINTER(Region),C.c_size_t,C.c_uint64,C.c_uint64)
    def observe(kernel,ordinal,fs,regions,count,address,value):
        if kernel:return
        try:
            block=current[0]
            if ordinal==9:
                if block in snapshots:outputs[block]=[(regions[i].address,C.string_at(regions[i].data,regions[i].size)) for i in range(count) if regions[i].permissions&2]
                return
            if ordinal==8:
                if block+1<args.blocks:inputs.setdefault(block+1,[]).append((address,value))
                return
            if fs.contents.cpu.pc==BEGIN:
                current[0]+=1;block=current[0]
                if block<args.blocks:snapshots[block]=clone_span(fs,regions,count,image,BEGIN,END);events[block]=[];final[block]=0
            if block not in snapshots or final[block]>=16:return
            events[block].append((fs.contents.cpu.pc,ordinal,(address-BASES[ordinal])//4,value))
            if ordinal>=4:final[block]+=1
        except BaseException as error:errors.append(type(error).__name__)
    callback=callback_type(observe);rows=[];blocks={};fixed={};starts={}
    with tempfile.TemporaryDirectory(prefix='ams-ssc-buffers-') as directory:
        directory=Path(directory);source,library=directory/'probe.c',directory/'probe.so'
        groups=sorted(set(re.findall(r'\bmescal_(?:ssc|corefp)_page_[0-9a-f]+\b',(root/'crypto/auth/mescal/generated/bounds.inc').read_text())))
        constants=lambda values:','.join('UINT64_C(0x%x)'%value for value in values)
        wrappers=group_wrappers(groups).replace('current_state=old;return status;','ams_guid_after(state,regions,count);current_state=old;return status;')
        source.write_text((SHIM%(constants((BEGIN,0)),constants((END,0)),'{'+constants(BASES)+'},{'+constants((0,)*8)+'}',
                               '{'+constants(INPUTS)+'},{'+constants((0,)*16)+'}'))+wrappers)
        objects=sorted((root/'build/auth/mescal/CMakeFiles/wrapper_mescal_source.dir').rglob('*.o'));assert objects
        subprocess.run(['cc','-std=c99','-O2','-shared','-fPIC','-I'+str(root/'crypto/keygen_experimental'),str(source),*map(str,objects),
                        '-Wl,--wrap=mescal_native_read',*['-Wl,--wrap='+name for name in groups],'-o',str(library)],check=True,capture_output=True)
        native=C.CDLL(str(library));native.ams_guid_observe.argtypes=[callback_type];native.ams_guid_observe(callback)
        profiles=((b'0123456789abcdef',bytes(range(6))),(b'fedcba9876543210',bytes(range(6,12))))
        if args.profile_set=='independent':profiles=((b'0011223344556677',bytes(range(32,38))),(b'ffeeddccbbaa9988',bytes(range(80,86))))
        for profile,(android,mac) in enumerate(profiles):
            snapshots.clear();events.clear();inputs.clear();outputs.clear();final.clear();current[0]=-1
            fields=derive_android_guid_fields(android,mac,system_serial=b'explicit-invented-serial',library=library)
            assert len(fields.first)==18 and len(fields.second)==7 and not errors and len(snapshots)==args.blocks
            for block in range(args.blocks):
                raw=dict(inputs.get(block,[]));contiguous=len(raw)==16 and max(raw)-min(raw)==15
                caller_input=bytes(raw[address] for address in sorted(raw)) if contiguous else None
                if args.verify_fixed:
                    from replay_guid_fixed import replay as replay_fixed
                    row,actual=replay_fixed(0,snapshots[block],events[block],BASES,BEGIN,END,outputs.get(block,[]),output_base='r14' if args.path=='inverse' else 'r11',output_sites=INVERSE_OUTPUTS if args.path=='inverse' else None)
                    row['source_original_complete_output_equal']=row['block_output_checks'][0]['source_original_complete_output_equal']
                    fixed[profile,block]=(caller_input,actual);starts[profile,block]=min(raw) if contiguous else None;private=None
                else:row,private=replay(snapshots[block],events[block],normalization,caller_input,outputs.get(block,[]))
                row.update(profile=profile,block=block,contiguous_16_byte_input=contiguous);rows.append(row)
                print(json.dumps(dict(progress='block checked',path=args.path,profile=profile,block=block,word_reads_equal=row['original_source_word_reads_equal'],output_equal=row['source_original_complete_output_equal'])),file=sys.stderr,flush=True)
                if private is not None:blocks[profile,block]=private
    cbc=[]
    if len(blocks)==2*args.blocks and all(blocks[index][0]==blocks[0,0][0] for index in blocks):
        key,logical,output_mask,raw,actual=blocks[0,0]
        if args.path=='inverse':
            input_mask=xor(logical,raw);output_mask=xor(blocks[0,1][2],raw);iv=xor(blocks[0,0][2],output_mask)
        else:input_mask=xor(blocks[0,1][1],blocks[0,1][3],actual);iv=xor(logical,raw,input_mask)
        ciphertext_mask=input_mask if args.path=='inverse' else output_mask
        cipher=MaskedCBC(key,ciphertext_mask,ciphertext_mask,plaintext_mask=xor(input_mask,output_mask))
        for profile in range(2):
            message=b''.join(blocks[profile,block][3] for block in range(args.blocks));expected=b''.join(blocks[profile,block][4] for block in range(args.blocks))
            cbc.append(dict(profile=profile,heldout=bool(profile),bytes=len(message),complete_stream_equal=(cipher.decrypt(message,iv) if args.path=='inverse' else cipher.encrypt(message,iv))==expected,
                            logical_states_match=all(blocks[profile,block][1]==(xor(blocks[profile,block][3],input_mask) if args.path=='inverse' else xor(blocks[profile,block][3],iv if block==0 else blocks[profile,block-1][4],input_mask)) for block in range(args.blocks))))
    if args.verify_fixed:
        if args.path=='inverse':
            from apple_music_source.auth._ssc_guid_cipher import decrypt_blocks as function
        else:
            from apple_music_source.auth._ssc_guid_cipher import encrypt_blocks as function
        for profile in range(2):
            records=[fixed[profile,block] for block in range(args.blocks)]
            assert all(raw is not None and actual is not None for raw,actual in records)
            assert all(starts[profile,block]==starts[profile,0]+16*block for block in range(args.blocks))
            message=b''.join(raw for raw,_ in records);expected=b''.join(actual for _,actual in records)
            cbc.append(dict(profile=profile,heldout=True,bytes=len(message),complete_stream_equal=function(message)==expected,logical_states_match=None,parameter_refitting=False))
    passed=len(cbc)==2 and all(check['complete_stream_equal'] and (args.verify_fixed or check['logical_states_match']) for check in cbc) and all(row['source_original_complete_output_equal'] and row['original_source_word_reads_equal'] for row in rows)
    exported=None
    if args.export_parameters is not None:
        assert passed and len(rows)==16 and all(row['original_lookup_reads']==160 for row in rows)
        from emit_ssc_guid_parameters import emit
        exported=emit(args.export_parameters,(key,input_mask,output_mask,iv),inverse=args.path=='inverse')
    report=dict(status='pass' if passed else 'incomplete',path=args.path,artifact_sha256=digest,rows=rows,caller_buffer_CBC=cbc,capture_errors=errors,
                network_requests=0,private_bytes_written=False,static_parameter_export=exported,invented_profile_set=args.profile_set,parameter_refitting=not args.verify_fixed,parameter_bytes_exported=64 if exported else 0,
                scope='complete source/original blocks, prefix-derived key hypothesis and heldout CBC buffer behavior; later row-multisets are observed checks, not a proof of round ordering; full GUID/auth not established')
    args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(dict(status=report['status'],blocks=len(rows),CBC_checks=cbc,capture_errors=errors)))
    if not passed:raise SystemExit(1)


if __name__=='__main__':main()
