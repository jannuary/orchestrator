"""Trace the first StoreServices GUID AES path using source index coordinates.

Original artifacts and source objects are developer oracles only. All lookup
words/indices, normalization maps and candidate keys remain in RAM. There is
no static parameter export or native-auth success claim in this experiment.
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
from analyze_frontier_aes_rounds import check as frontier_check
from analyze_round_key_schedule import analyze as schedule_check
from analyze_table_algebra import apply
from probe_auth_substitution_reads import group_wrappers
from scan_auth_substitutions import TARGETS
from trace_guid_rounds import Native,Region,clone,SHIM
from trace_lookup_dataflow import LookupTrace


BEGIN,END=0x1f8249,0x1fda00
BASES=(0x9d1d0,0xa0370,0x9ff40,0x9fa10,0x97f40,0x9cb20,0x9e230,0xa0880)


def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('checkout',type=Path)
    parser.add_argument('--output',type=Path,required=True)
    parser.add_argument('--normalize-words',action='store_true',help='Use proved word inverses and source input-index corrections in symbolic word values')
    parser.add_argument('--inline-domains',action='store_true',help='Represent normalized words directly by their exact eight-bit affine coordinates')
    parser.add_argument('--prove-index-projections',action='store_true',help='Replace canonical indices only after exact domain-coordinate projection proofs')
    args=parser.parse_args();root=args.checkout.resolve()
    sys.path.insert(0,str(root/'tools/auth'));sys.path.insert(0,str(root/'tools/crypto/keygen_experimental'))
    sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'src'))
    from device_identity import derive_android_guid_fields
    from unicorn import UC_HOOK_CODE,UC_HOOK_MEM_READ
    from unicorn import x86_const as r
    filename,digest=TARGETS['storeservices'];image=(root/'rootfs/system/lib64'/filename).read_bytes()
    assert hashlib.sha256(image).hexdigest()==digest
    normalization=build(image);inverse_maps=[];affine=[]
    for mapping in normalization['indices']:
        inverse=[0]*256
        for value,index in enumerate(mapping):inverse[index]=value
        offset=inverse[0];columns=[inverse[1<<bit]^offset for bit in range(8)]
        linear=all(inverse[value]==offset^apply(columns,value) for value in range(256))
        inverse_maps.append((inverse,offset,columns));affine.append(linear)
    captured=[];expected=[];done=[False];errors=[];final=[0]
    callback_type=C.CFUNCTYPE(None,C.c_uint,C.c_uint,C.POINTER(Native),C.POINTER(Region),C.c_size_t,C.c_uint64,C.c_uint64)
    def observe(kernel,ordinal,fs,regions,count,address,value):
        if kernel or ordinal>=8 or done[0]:return
        try:
            if not captured:
                if fs.contents.cpu.pc!=BEGIN:return
                captured.append(clone(fs,regions,count))
            expected.append((fs.contents.cpu.pc,ordinal,(address-BASES[ordinal])//4,value))
            if ordinal>=4:
                final[0]+=1
                if final[0]==16:done[0]=True
        except BaseException as error:errors.append(type(error).__name__);done[0]=True
    callback=callback_type(observe)
    with tempfile.TemporaryDirectory(prefix='ams-ssc-guid-rounds-') as directory:
        directory=Path(directory);source,library=directory/'capture.c',directory/'capture.so'
        groups=sorted(set(re.findall(r'\bmescal_(?:ssc|corefp)_page_[0-9a-f]+\b',(root/'crypto/auth/mescal/generated/bounds.inc').read_text())))
        constants=lambda values:','.join('UINT64_C(0x%x)'%value for value in values)
        wrappers=group_wrappers(groups).replace('current_state=old;return status;','ams_guid_after(state,regions,count);current_state=old;return status;')
        source.write_text((SHIM%(constants((BEGIN,0)),constants((END,0)),
            '{'+constants(BASES)+'},{'+constants((0,)*8)+'}',
            '{'+constants((0,)*16)+'},{'+constants((0,)*16)+'}'))+wrappers)
        objects=sorted((root/'build/auth/mescal/CMakeFiles/wrapper_mescal_source.dir').rglob('*.o'));assert objects
        subprocess.run(['cc','-std=c99','-O2','-shared','-fPIC','-I'+str(root/'crypto/keygen_experimental'),str(source),*map(str,objects),
                        '-Wl,--wrap=mescal_native_read',*['-Wl,--wrap='+name for name in groups],'-o',str(library)],check=True,capture_output=True)
        native=C.CDLL(str(library));native.ams_guid_observe.argtypes=[callback_type];native.ams_guid_observe(callback)
        fields=derive_android_guid_fields(b'0123456789abcdef',bytes(range(6)),system_serial=b'invented-serial',library=library)
        assert len(fields.first)==18 and len(fields.second)==7 and captured and done[0] and not errors
        domains={index:data for index,data in enumerate(normalization['arrays'])} if args.normalize_words else None
        assert not args.inline_domains or args.normalize_words
        mu=captured[0].mu;trace=LookupTrace(mu,[(base,1024) for base in BASES],range(4),range(4,8),word_domains=domains,maximum_regular_reads=144,inline_word_domains=args.inline_domains)
        z=trace.z
        def index_expression(ordinal,value):
            if ordinal>=4:return value
            inverse,offset,columns=inverse_maps[ordinal]
            if affine[ordinal]:
                expression=z.BitVecVal(offset,8)
                for bit,column in enumerate(columns):expression^=z.If(z.Extract(bit,bit,value)==1,z.BitVecVal(column,8),z.BitVecVal(0,8))
                return expression
            array=z.K(z.BitVecSort(8),z.BitVecVal(0,8))
            for index,decoded in enumerate(inverse):array=z.Store(array,z.BitVecVal(index,8),z.BitVecVal(decoded,8))
            return z.Select(array,value)
        trace.index_expression_transform=index_expression
        trace.index_value_transform=lambda ordinal,value:inverse_maps[ordinal][0][value] if ordinal<4 else value
        projector=None
        if args.prove_index_projections:
            assert args.inline_domains
            from prove_guid_index_projections import Projector
            assert len({tuple(item['input_positions']) for item in normalization['models']})==1
            projector=Projector(normalization['models'][0]['input_positions']);trace.custom_index_normalizer=projector
        inverse_report=None
        if args.normalize_words:
            from invert_guid_word_encodings import recover
            inverses={};analysis=normalization['analysis']
            inverse_report=recover(analysis,image,lambda index,encoded,inverse:inverses.update({index:(encoded,inverse)}),allow_multiplication=True)
            assert len(inverses)==4
            def h(ordinal,index):
                if ordinal==2:return z.substitute(normalization['h2'],(normalization['u2'],index))
                if ordinal==3:return z.substitute(normalization['h3'],(normalization['u3'],index))
                return z.BitVecVal(0,32)
            def word_value(ordinal,index,value):
                if ordinal>=4:return value
                result=z.substitute(analysis['contributions'][ordinal],(analysis['words'][ordinal],z.BitVecVal(value,32)))^h(ordinal,z.BitVecVal(index,8))
                result=z.simplify(result).as_long()
                assert result==int.from_bytes(normalization['arrays'][ordinal][index*4:index*4+4],'little')
                return result
            def word_expression(ordinal,index,value):
                if ordinal>=4:return value
                encoded,inverse=inverses[ordinal]
                return z.simplify(z.substitute(inverse,(encoded,value^h(ordinal,index))))
            trace.indexed_word_value_transform=word_value;trace.indexed_word_expression_transform=word_expression
        observed=[];final=[0];stop=[False];started=[False]
        def step(m,pc,size,user):
            if stop[0]:m.emu_stop();return
            if pc==BEGIN:
                if started[0]:m.emu_stop();return
                started[0]=True
            if not BEGIN<=pc<END:m.emu_stop();return
            trace.step(m,pc,size)
        def read(m,kind,address,width,value,ordinal):
            if width!=4 or (address-BASES[ordinal])%4:return
            observed.append((m.reg_read(r.UC_X86_REG_RIP),ordinal,(address-BASES[ordinal])//4,int.from_bytes(m.mem_read(address,4),'little')))
            if ordinal>=4:
                final[0]+=1
                if final[0]==16:stop[0]=True
        mu.hook_add(UC_HOOK_CODE,step)
        for ordinal,base in enumerate(BASES):mu.hook_add(UC_HOOK_MEM_READ,read,ordinal,begin=base,end=base+1023)
        execution_error=None
        try:mu.emu_start(BEGIN,END,count=100000)
        except Exception as error:execution_error=type(error).__name__
        keys=[];strict=schedule_check(trace,normalization['models'],range(4))
        frontier=frontier_check(trace,normalization['models'],range(4),lambda key,details:keys.append(key))
        from analyze_guid_prefix_states import analyze as analyze_prefix_states
        prefix_states=analyze_prefix_states(trace,normalization['models'],range(4))
        report=dict(status='incomplete StoreServices GUID round investigation',artifact_sha256=digest,
                    original_execution_error=execution_error,original_source_word_reads_equal=observed==expected,
                    original_lookup_reads=len(observed),source_lookup_reads=len(expected),final_lookup_reads=final[0],
                    source_index_inverse_maps_affine=affine,lookup_dataflow=trace.summary(),
                    word_inverse_proofs=inverse_report,indexed_word_inverse_replay_checks=trace.indexed_word_inverse_checks,
                    inline_word_domains=trace.inlined_word_domains,
                    index_projection_proofs=dict(projector.outcomes) if projector else None,
                    coherent_substitutions=normalization['result'],strict_round_schedule=strict,frontier_round_schedule=frontier,
                    key_candidates=len(keys),key_bytes_written=0,network_requests=0,private_bytes_written=False,
                    prefix_state_hypothesis=prefix_states,
                    scope='one invented source block, canonical source-byte indices, original read equality and observed schedule only; no final output, initializer, exported key, full GUID or auth claim')
        args.output.write_text(json.dumps(report,indent=2)+'\n')
        print(json.dumps({key:report[key] for key in ('status','original_source_word_reads_equal','original_lookup_reads','source_lookup_reads','key_candidates')}))


if __name__=='__main__':main()
