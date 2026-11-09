"""Probe identified source packet functions using invented ordinary buffers.

Development runtime retains its existing image/integrity dependencies. No live
license, private fixture fields, buffer values, keys or SPC bytes are emitted.
This is ABI research, not a standalone implementation or AES parity claim.
"""
import argparse
import ctypes as C
import json
from pathlib import Path
import random
import struct
import subprocess
import sys
import tempfile


HELPER=r'''
static int ams_kernel_probe_inner(kg_runtime *r,unsigned which,unsigned size,
 wrapper_kg_spc_result *result,uint64_t changed[3],uint64_t *returned,unsigned char output[192],
 const unsigned char *context,unsigned context_size,unsigned key_buffer){
 uint64_t p=(KG_HEAP+r->allocated+15)&~UINT64_C(15),a[3],mask;
 unsigned char before[3][4096];wrapper_kg_spc_result *old=r->result;
 if(which>1||size>4096||context_size>4096||key_buffer>3||p>KG_HEAP+KG_ARENA-0x4000)return -1;
 r->allocated=(size_t)(p+0x4000-KG_HEAP);
 for(unsigned j=0;j<3;++j){a[j]=p+0x1000*(j+1);changed[j]=0;
  for(unsigned i=0;i<4096;++i){before[j][i]=(unsigned char)(i*17+j*31);if(!kg_write(r,a[j]+i,1,before[j][i]))return -2;}}
 if(context&&key_buffer<3)for(unsigned i=0;i<context_size;++i){before[key_buffer][i]=context[i];if(!kg_write(r,a[key_buffer]+i,1,context[i]))return -2;}
 if(key_buffer==3){
  if(!context)return -1;
  if(context_size==1){
   for(unsigned j=0;j<3;++j)if(j==0||j==(which?1:2)){
    before[j][0]^=context[0];if(!kg_write(r,a[j],1,before[j][0]))return -2;}
  }else{
   if(context_size<32||context_size>16+size)return -1;
   for(unsigned i=0;i<context_size;++i){unsigned j=i<16?0:(which?1:2),offset=i<16?i:i-16;
    before[j][offset]=context[i];if(!kg_write(r,a[j]+offset,1,context[i]))return -2;}
  }
 }
 for(unsigned i=0;i<64;++i)if(!kg_write(r,p+i,1,0))return -2;
 if(!which){
  mask=(p^UINT64_C(0xe49b8bbe838d1770))*UINT64_C(0x741a8ab1);
  if(!kg_write(r,p,4,9-mask)||!kg_write(r,p+8,8,a[1]-UINT64_C(0xc43e05c519b61228))||
     !kg_write(r,p+16,8,a[2]-UINT64_C(0xe0d7cdbb906643cd))||!kg_write(r,p+24,8,a[0]-UINT64_C(0xf24d0dd1b2cce148))||
     !kg_write(r,p+32,4,mask+UINT64_C(0x2a47a758)+size))return -2;
 }else{
  mask=(p^UINT64_C(0xbe2af1b45989a725))*UINT64_C(0x1f6060df);
  if(!kg_write(r,p,8,a[0]-UINT64_C(0xbf6e2aefd239cb18))||!kg_write(r,p+8,8,a[1]-UINT64_C(0xdf7dabda77790d68))||
     !kg_write(r,p+16,4,mask+UINT64_C(0x60ba2e72)+size)||!kg_write(r,p+24,8,a[2]-UINT64_C(0xe40c57b7a130b973))||
     !kg_write(r,p+32,4,4^mask))return -2;
 }
 memset(result,0,sizeof *result);r->result=result;
 int ok=kg_execute(r,KG_CORE+(which?UINT64_C(0x530970):UINT64_C(0x526bc0)),&p,1,0,0);
 result->pc=r->state.cpu.pc;result->fault_address=r->state.cpu.fault_address;result->fault_size=r->state.cpu.fault_size;
 *returned=r->state.cpu.gpr[0];
 for(unsigned j=0;j<3;++j){const unsigned char *data=kg_memory(r,a[j],4096,1);if(data){
  for(unsigned i=0;i<4096;++i)changed[j]+=data[i]!=before[j][i];memcpy(output+j*64,data,64);}}
 r->result=old;return ok;
}
int ams_kernel_probe(kg_runtime *r,unsigned which,unsigned size,
 wrapper_kg_spc_result *result,uint64_t changed[3],uint64_t *returned,unsigned char output[192],
 const unsigned char *context,unsigned context_size,unsigned key_buffer){
 kg_runtime *saved=malloc(sizeof *saved);unsigned char *copies[KG_REGIONS]={0};int status=-99;
 if(!saved)return -99;memcpy(saved,r,sizeof *saved);
 for(unsigned j=0;j<KG_REGIONS;++j)if(r->regions[j].permissions&2){
  copies[j]=malloc(r->regions[j].size);if(!copies[j])goto done;
  memcpy(copies[j],r->owned[j],r->regions[j].size);
 }
 status=ams_kernel_probe_inner(r,which,size,result,changed,returned,output,context,context_size,key_buffer);
done:
 for(unsigned j=0;j<KG_REGIONS;++j)if(copies[j]){
  memcpy(saved->owned[j],copies[j],saved->regions[j].size);kg_clear(copies[j],saved->regions[j].size);free(copies[j]);}
 memcpy(r,saved,sizeof *r);kg_clear(saved,sizeof *saved);free(saved);return status;
}
'''


def certificate_only(path):
    with path.open('rb') as f:
        head=f.read(24);assert head[:4]==b'RCP1'
        operation,status,ns,nb=struct.unpack_from('<IqII',head,4);assert operation==1 and ns<=32 and nb<=32
        f.seek(ns*12,1);certificate=None
        for _ in range(nb):
            field,size=struct.unpack('<II',f.read(8));assert size<=1024*1024
            if field==1:
                assert certificate is None;certificate=f.read(size);assert len(certificate)==size
            else:f.seek(size,1)
        assert certificate is not None
        return certificate


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('checkout',type=Path);parser.add_argument('--public-certificate-fixture',type=Path,required=True)
    parser.add_argument('--output',type=Path,required=True)
    parser.add_argument('--expanded-key-hypotheses',action='store_true',help='Try specification-generated AES-128 round-key layouts on invented buffers')
    parser.add_argument('--sensitivity',action='store_true',help='Measure output changes from single-bit changes at invented buffer offsets; never emit output values')
    parser.add_argument('--xor-cancellation',action='store_true',help='Test whether equal IV/data bit changes cancel; structural relation only')
    parser.add_argument('--cross-kernels',action='store_true',help='Compare both kernels on identical invented IV/data; no cipher bytes emitted')
    parser.add_argument('--mode-relations',action='store_true',help='Test same-kernel block chaining and arbitrary IV/data XOR cancellation in RAM')
    parser.add_argument('--inverse-relations',action='store_true',help='Test whether the two zero-IV block operations invert one another on invented inputs')
    parser.add_argument('--feedback-hypotheses',action='store_true',help='With mode-relations, test standard byte orders and a uniform XOR feedback family; inferred mask values never leave RAM')
    parser.add_argument('--encoded-feedback',action='store_true',help='With mode-relations, test the recovered copy transforms as input/output/IV representations')
    args=parser.parse_args();root=args.checkout.resolve();source=root/'crypto/keygen_experimental';build=root/'build/spc-payload'
    sys.path.insert(0,str(root/'tools/crypto/keygen_experimental'))
    from source_protocol import SourceSession,Result
    sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'src'))
    from apple_music_source.crypto.aes import AES,aes_cbc_encrypt,aes_cbc_decrypt
    certificate=certificate_only(args.public_certificate_fixture);rows=[];first_kernel_output=None
    with tempfile.TemporaryDirectory(prefix='ams-kernel-call-') as temp:
        cfile=Path(temp)/'generate.c';library=Path(temp)/'generate.so'
        cfile.write_text((source/'spc_generate.c').read_text()+'\n'+HELPER)
        codec_source=Path(__file__).resolve().parents[1]/'src/apple_music_source/_native/copy_codecs.c'
        subprocess.run(['cc','-std=c99','-O2','-shared','-fPIC','-I'+str(source),str(cfile),str(source/'ckc_packet.c'),str(codec_source),
                        '-L'+str(build),'-lwrapper_spc_native','-Wl,-rpath,'+str(build),'-o',str(library)],check=True,capture_output=True)
        lib=C.CDLL(str(library));probe=lib.ams_kernel_probe
        probe.argtypes=[C.c_void_p,C.c_uint,C.c_uint,C.POINTER(Result),C.POINTER(C.c_uint64),C.POINTER(C.c_uint64),C.POINTER(C.c_ubyte),C.c_void_p,C.c_uint,C.c_uint];probe.restype=C.c_int
        byte_codecs=[lib.ams_copy0_byte,lib.ams_copy1_byte]
        for function in byte_codecs:function.argtypes=[C.c_uint32,C.c_uint8,C.c_uint8];function.restype=C.c_uint8
        def normalized(name,value,start=0):
            if name=='identity':return value
            result=[]
            for i,byte in enumerate(value,start):
                if name=='copy0':result.append(byte_codecs[0](i,2*i,byte))
                elif name=='copy1-add':result.append(byte_codecs[1](i,2*i,byte))
                else:result.append((byte-byte_codecs[1](i,2*i,0))&255)
            return bytes(result)
        inverse_name={'identity':'identity','copy0':'copy0','copy1-add':'copy1-subtract','copy1-subtract':'copy1-add'}
        for which,size in ((0,48),(1,16)):
            rng=random.Random(0xc017);ticks=[0]
            def entropy(_,p,n):
                for i in range(n):p[i]=rng.randrange(256)
                return 0
            def clock(_):ticks[0]+=1;return 0x1234567800000000+ticks[0]*100003
            def wall(_,seconds,micros):seconds[0]=1700000000;micros[0]=123456;return 0
            with SourceSession(library,0,certificate,b'invented-kernel-probe',bytes(range(16)),entropy=entropy,clock=clock,time=wall) as session:
                result=Result();changed=(C.c_uint64*3)();returned=C.c_uint64();output=(C.c_ubyte*192)()
                ok=probe(session.handle,which,size,C.byref(result),changed,C.byref(returned),output,None,0,0)
                initial=[bytes((i*17+j*31)&255 for i in range(64)) for j in range(3)]
                destination=1 if not which else 2;observed=bytes(output)[destination*64:destination*64+size];matches=[];checks=0
                if ok==1:
                    for key_buffer in range(3):
                        if key_buffer==destination:continue
                        input_buffer=3-destination-key_buffer;data=initial[input_buffer][:size]
                        for key_size in (16,24,32):
                            key=initial[key_buffer][:key_size];aes=AES(key)
                            for direction in ('encrypt','decrypt'):
                                block=getattr(aes,direction+'_block')
                                candidates=[('ECB',b''.join(block(data[i:i+16]) for i in range(0,size,16)))]
                                for iv_name,iv in (('zero',bytes(16)),('key-buffer-tail',initial[key_buffer][32:48])):
                                    value=aes_cbc_encrypt(key,iv,data,pad=False) if direction=='encrypt' else aes_cbc_decrypt(key,iv,data,unpad=False)
                                    candidates.append(('CBC-'+iv_name,value))
                                for mode,value in candidates:
                                    checks+=1
                                    if value==observed:matches.append(dict(direction=direction,mode=mode,key_size=key_size,key_buffer=key_buffer,input_buffer=input_buffer))
                rows.append(dict(function=hex(0x10526bc0 if not which else 0x10530970),size=size,
                                 execution_reached_return=ok==1,raw_return_is_zero=not returned.value if ok==1 else None,pc=hex(result.pc),
                                 fault_address=hex(result.fault_address),fault_size=result.fault_size,steps=result.source_steps,
                                 invented_buffer_changed_byte_counts=list(changed),
                                 direct_raw_key_AES_hypotheses_checked=checks,direct_raw_key_AES_matches=matches))
                baseline=bytes(output)[destination*64:destination*64+size]
                if which==0:first_kernel_output=baseline
                if args.inverse_relations and which==0:
                    def block_kernel(algorithm,data):
                        context=bytes(16)+data;ctx=C.create_string_buffer(context);out=(C.c_ubyte*192)();rr=Result();cc=(C.c_uint64*3)();ret=C.c_uint64()
                        code=probe(session.handle,algorithm,16,C.byref(rr),cc,C.byref(ret),out,ctx,len(context),3)
                        assert code==1,('inverse probe source gap',hex(rr.pc))
                        dest=2 if algorithm else 1
                        return bytes(out)[dest*64:dest*64+16]
                    relation_rng=random.Random(0x1a3e25e);left=right=0;left_delta=right_delta=None;left_fixed=right_fixed=True
                    for _ in range(32):
                        data=bytes(relation_rng.randrange(256) for _ in range(16))
                        a=block_kernel(1,block_kernel(0,data));b=block_kernel(0,block_kernel(1,data))
                        left+=a==data;right+=b==data
                        da=bytes(x^y for x,y in zip(a,data));db=bytes(x^y for x,y in zip(b,data))
                        if left_delta is None:left_delta,right_delta=da,db
                        else:left_fixed&=da==left_delta;right_fixed&=db==right_delta
                    rows[-1]['cross_inverse_relations']=dict(invented_inputs=32,forward_then_reverse_equal=left,
                                                            reverse_then_forward_equal=right,
                                                            forward_reverse_fixed_xor=left_fixed,reverse_forward_fixed_xor=right_fixed)
                if args.mode_relations:
                    data_index=2 if not which else 1;iv=initial[0][:16];data=initial[data_index][:48]
                    def invoke_iv_data(iv,data):
                        context=iv+data;ctx=C.create_string_buffer(context);out=(C.c_ubyte*192)();rr=Result();cc=(C.c_uint64*3)();ret=C.c_uint64()
                        code=probe(session.handle,which,len(data),C.byref(rr),cc,C.byref(ret),out,ctx,len(context),3)
                        return code,bytes(out)[destination*64:destination*64+len(data)],rr
                    code,multi,rr=invoke_iv_data(iv,data)
                    mode_result=dict(multiblock_reached_return=code==1,multiblock_pc=hex(rr.pc))
                    mode_result['multiblock_fault_size']=rr.fault_size
                    if code==1:
                        chain=iv;blocks=[];returned_all=True
                        for start in range(0,48,16):
                            code,block,rr=invoke_iv_data(chain,data[start:start+16]);returned_all&=code==1;blocks.append(block);chain=block
                        mode_result['three_single_blocks_returned']=returned_all
                        mode_result['same_kernel_chaining_equal']=b''.join(blocks)==multi if returned_all else None
                        mode_result['same_kernel_chaining_equal_by_block']=[a==multi[i*16:i*16+16] for i,a in enumerate(blocks)] if returned_all else None
                        relation_rng=random.Random(0xc8c001);cancellation=[]
                        for _ in range(32):
                            new_iv=bytes(relation_rng.randrange(256) for _ in range(16))
                            new_data=bytes(a^b^c for a,b,c in zip(data[:16],iv,new_iv))+data[16:]
                            code,changed_output,rr=invoke_iv_data(new_iv,new_data)
                            cancellation.append(code==1 and changed_output==multi)
                        mode_result['arbitrary_iv_xor_cancellation_checks']=len(cancellation)
                        mode_result['arbitrary_iv_xor_cancellation_passes']=sum(cancellation)
                        if args.encoded_feedback:
                            checked=0;matches=[]
                            for input_name in inverse_name:
                                for output_name in inverse_name:
                                    for iv_name in inverse_name:
                                        checked+=1
                                        raw_zero_iv=normalized(inverse_name[iv_name],bytes(16))
                                        chain=normalized(iv_name,iv);equal=True
                                        for start in range(0,48,16):
                                            plain=normalized(input_name,data[start:start+16],start)
                                            core_input=bytes(a^b for a,b in zip(chain,plain))
                                            raw_input=normalized(inverse_name[input_name],core_input)
                                            status,raw_output,rr=invoke_iv_data(raw_zero_iv,raw_input)
                                            expected=normalized(output_name,multi[start:start+16],start)
                                            actual=normalized(output_name,raw_output)
                                            if status!=1 or actual!=expected:equal=False;break
                                            chain=expected
                                        if equal:matches.append(dict(input=input_name,output=output_name,iv=iv_name))
                            mode_result['source_codec_feedback_combinations_checked']=checked
                            mode_result['source_codec_feedback_matches']=matches
                        if args.feedback_hypotheses:
                            def xor_bytes(a,b):return bytes(x^y for x,y in zip(a,b))
                            def zero_iv_block(block):
                                code,value,rr=invoke_iv_data(bytes(16),block)
                                assert code==1,('feedback block source gap',hex(rr.pc))
                                return value
                            zero_first=zero_iv_block(xor_bytes(iv,data[:16]))
                            mode_result['zero_iv_combined_first_block_equal']=zero_first==multi[:16]
                            prefix=iv;prefix_outputs=[]
                            for start in range(0,48,16):
                                prefix=xor_bytes(prefix,data[start:start+16]);prefix_outputs.append(zero_iv_block(prefix))
                            mode_result['plain_prefix_xor_equal_by_block']=[v==multi[i*16:i*16+16] for i,v in enumerate(prefix_outputs)]
                            post=[multi[:16]];stream=[multi[:16]]
                            for start in range(16,48,16):
                                block=data[start:start+16]
                                post.append(xor_bytes(zero_iv_block(block),post[-1]))
                                stream.append(xor_bytes(zero_iv_block(stream[-1]),block))
                            mode_result['post_cipher_xor_feedback_equal_by_block']=[v==multi[i*16:i*16+16] for i,v in enumerate(post)]
                            mode_result['stream_feedback_equal_by_block']=[v==multi[i*16:i*16+16] for i,v in enumerate(stream)]
                            orders={'identity':list(range(16)),'reverse':list(reversed(range(16))),
                                    'transpose-4x4':[4*(i%4)+i//4 for i in range(16)]}
                            for width in (2,4,8):
                                orders['reverse-within-'+str(width)]=[i//width*width+width-1-i%width for i in range(16)]
                                orders['reverse-'+str(width)+'-byte-units']=[(16//width-1-i//width)*width+i%width for i in range(16)]
                            for shift in (1,2,3):
                                orders['rotate-byte-in-word-'+str(shift)]=[i//4*4+(i+shift)%4 for i in range(16)]
                                orders['rotate-word-'+str(shift)]=[(i+4*shift)%16 for i in range(16)]
                                orders['shift-rows-'+str(shift)]=[4*((i//4+shift*(i%4))%4)+i%4 for i in range(16)]
                            byte_order_matches=[];order_checks=0;xor_matches=0;xor_checks=0
                            for name,order in orders.items():
                                candidate=bytes(multi[i] for i in order);code,value,rr=invoke_iv_data(candidate,data[16:32]);order_checks+=1
                                if code==1 and value==multi[16:32]:
                                    candidate=bytes(multi[16+i] for i in order);code,value,rr=invoke_iv_data(candidate,data[32:48])
                                    if code==1 and value==multi[32:48]:byte_order_matches.append(name)
                            for mask in range(256):
                                candidate=bytes(x^mask for x in multi[:16]);code,value,rr=invoke_iv_data(candidate,data[16:32]);xor_checks+=1
                                if code==1 and value==multi[16:32]:
                                    candidate=bytes(x^mask for x in multi[16:32]);code,value,rr=invoke_iv_data(candidate,data[32:48])
                                    xor_matches+=code==1 and value==multi[32:48]
                            mode_result['standard_byte_orders_checked']=order_checks;mode_result['standard_byte_order_matches']=byte_order_matches
                            mode_result['uniform_xor_feedback_candidates_checked']=xor_checks;mode_result['uniform_xor_feedback_matches']=xor_matches
                    rows[-1]['mode_relations']=mode_result
                if args.cross_kernels and which==1:
                    iv=initial[0][:16];data=initial[2][:48];comparison=[]
                    for block in range(3):
                        context=iv+data[block*16:block*16+16];ctx=C.create_string_buffer(context)
                        changed=(C.c_uint64*3)();output=(C.c_ubyte*192)();result=Result()
                        ok=probe(session.handle,which,size,C.byref(result),changed,C.byref(returned),output,ctx,len(context),3)
                        observed=bytes(output)[destination*64:destination*64+16]
                        comparison.append(dict(block=block,source_reached_return=ok==1,
                                               equal_to_first_kernel_block=observed==first_kernel_output[block*16:block*16+16] if ok==1 else None))
                        iv=observed
                    rows[-1]['iterated_cross_kernel_comparison']=comparison
                if args.xor_cancellation:
                    cancellations=[]
                    for mask in (1,2,4,8,16,32,64,128):
                        ctx=C.create_string_buffer(bytes([mask]));changed=(C.c_uint64*3)();output=(C.c_ubyte*192)();result=Result()
                        ok=probe(session.handle,which,size,C.byref(result),changed,C.byref(returned),output,ctx,1,3)
                        observed=bytes(output)[destination*64:destination*64+size]
                        cancellations.append(dict(bit_mask=mask,source_reached_return=ok==1,
                                                  equal_output=observed==baseline if ok==1 else None))
                    rows[-1]['equal_input_bit_cancellation']=cancellations
                if args.sensitivity:
                    sensitivity=[]
                    for buffer in range(3):
                        for offset in (0,16,32,64,128,176):
                            context=bytearray((i*17+buffer*31)&255 for i in range(offset+1));context[offset]^=1
                            ctx=C.create_string_buffer(bytes(context));changed=(C.c_uint64*3)();output=(C.c_ubyte*192)();result=Result()
                            ok=probe(session.handle,which,size,C.byref(result),changed,C.byref(returned),output,ctx,len(context),buffer)
                            output_bytes=bytes(output)[destination*64:destination*64+size]
                            sensitivity.append(dict(buffer=buffer,offset=offset,probe_status=ok,source_reached_return=ok==1,
                                                    pc=hex(result.pc),fault_address=hex(result.fault_address),fault_size=result.fault_size,
                                                    changed_output_bytes_by_block=[sum(a!=b for a,b in zip(baseline[i:i+16],output_bytes[i:i+16])) for i in range(0,size,16)] if ok==1 else None))
                    rows[-1]['single_bit_sensitivity']=sensitivity
                if args.expanded_key_hypotheses:
                    context_rows=[]
                    for key_buffer in range(3):
                        if key_buffer==destination:continue
                        key=initial[key_buffer][:16];aes=AES(key);input_buffer=3-destination-key_buffer;data=initial[input_buffer][:size]
                        contexts=[('forward',aes._round_keys),('reverse',list(reversed(aes._round_keys)))]
                        inverse_rounds=[list(aes._round_keys[-1])]
                        for rk in reversed(aes._round_keys[1:-1]):
                            rk=list(rk);aes._inv_mix_columns(rk);inverse_rounds.append(rk)
                        inverse_rounds.append(list(aes._round_keys[0]));contexts.append(('inverse-mixed',inverse_rounds))
                        for layout,rounds in contexts:
                            expanded=bytes(x for rk in rounds for x in rk)
                            for endian in ('bytes','word-reversed'):
                                context=expanded if endian=='bytes' else b''.join(expanded[i:i+4][::-1] for i in range(0,len(expanded),4))
                                ctx=C.create_string_buffer(context);changed=(C.c_uint64*3)();output=(C.c_ubyte*192)();result=Result()
                                ok=probe(session.handle,which,size,C.byref(result),changed,C.byref(returned),output,ctx,len(context),key_buffer)
                                candidates=[]
                                if ok==1:
                                    observed=bytes(output)[destination*64:destination*64+size]
                                    for direction in ('encrypt','decrypt'):
                                        block=getattr(aes,direction+'_block');value=b''.join(block(data[i:i+16]) for i in range(0,size,16))
                                        if value==observed:candidates.append(direction+' ECB')
                                        value=aes_cbc_encrypt(key,bytes(16),data,pad=False) if direction=='encrypt' else aes_cbc_decrypt(key,bytes(16),data,unpad=False)
                                        if value==observed:candidates.append(direction+' CBC-zero')
                                context_rows.append(dict(key_buffer=key_buffer,layout=layout,byte_order=endian,
                                                         source_reached_return=ok==1,probe_status=ok,pc=hex(result.pc),
                                                         matches=candidates))
                    rows[-1]['expanded_aes128_context_hypotheses']=context_rows
    report=dict(status='source ABI investigation',isolated_runtime_snapshots=True,cases=rows,
                scope='invented ordinary buffers; no acquired CKC or valid crypto-context claim; original developer image/integrity banks remain')
    args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))


if __name__=='__main__':main()
