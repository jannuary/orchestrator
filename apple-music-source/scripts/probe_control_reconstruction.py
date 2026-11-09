"""Remove modeled bytes from a temporary initializer and compare live SPC.

Only development oracles retain other original banks. The model initializer
never sees the removed bytes, even transiently. Positive/model/zero-control
outputs are compared in RAM; state digests and SPC bytes are not reported.
"""
import argparse
import json
import os
from pathlib import Path
import re
import subprocess
import sys
import tempfile
import threading

from generate_control_refs import cells


PROGRAM=r'''
import ctypes as C,hashlib,json,os,random,struct,sys
from pathlib import Path
sys.path.insert(0,sys.argv[1]+'/tools/crypto/keygen_experimental')
from source_protocol import generate
class Region(C.Structure):
 _fields_=[('address',C.c_uint64),('size',C.c_size_t),('data',C.c_void_p),('permissions',C.c_uint)]
Callback=C.CFUNCTYPE(None,C.c_void_p,C.c_size_t,C.POINTER(Region),C.c_size_t)
digests=[]
def capture(state,size,regions,count):
 h=hashlib.sha256(C.string_at(state,size))
 for i in range(count):
  r=regions[i];h.update(struct.pack('<QQI',r.address,r.size,r.permissions));h.update(C.string_at(r.data,r.size))
 digests.append(h.hexdigest())
callback=Callback(capture);lib=C.CDLL(sys.argv[2]);lib.ams_capture_set.argtypes=[Callback];lib.ams_capture_set(callback)
certificates=[bytes(1),bytes(32)]
with open(sys.argv[3],'rb') as f:
 head=f.read(24);assert head[:4]==b'RCP1'
 operation,status,ns,nb=struct.unpack_from('<IqII',head,4);assert operation==1 and ns<=32 and nb<=32
 f.seek(ns*12,1);cert=None
 for _ in range(nb):
  field,size=struct.unpack('<II',f.read(8));assert size<=1024*1024
  if field==1:
   assert cert is None;cert=f.read(size);assert len(cert)==size
  else:f.seek(size,1)
 assert cert is not None;certificates.append(cert)
rows=[]
for index,cert in enumerate(certificates):
 rng=random.Random(0xc017+index);ticks=[0]
 def entropy(_,p,n):
  for i in range(n):p[i]=rng.randrange(256)
  return 0
 def clock(_):ticks[0]+=1;return 0x1234567800000000+ticks[0]*100003
 def wall(_,sec,micro):sec[0]=1700000000;micro[0]=123456;return 0
 status,output,r=generate(sys.argv[2],0,cert,b'invented-control-data',bytes(range(16)),entropy=entropy,clock=clock,time=wall)
 data=struct.pack('<I',len(output))+output
 while data:
  count=os.write(int(os.environ['AMS_OUTPUT_FD']),data);data=data[count:]
 rows.append(dict(certificate_size=len(cert),api=status,status=r.status,pc=hex(r.pc),
                  fault_address=hex(r.fault_address),fault_size=r.fault_size,
                  source_steps=r.source_steps,clock_calls=r.clock_calls,output_size=len(output),terminal_digest=digests[-1]))
print(json.dumps(rows))
'''


def scrub_images(text,images,known,poison=0):
    replaced=[0]
    pattern=r'(static const unsigned char kg_image_(\d+)\[(\d+)\] = \{\n)(.*?)(\n\};)'
    def replace(match):
        index=int(match[2]);data=bytearray(int(v,16) for v in re.findall(r'0x([0-9a-fA-F]{2})',match[4]))
        assert len(data)==int(match[3])==images[index]['size']
        start=images[index]['address']
        for address in known:
            if start<=address<start+len(data):data[address-start]=poison;replaced[0]+=1
        body='\n'.join('    '+','.join(f'0x{v:02x}' for v in data[i:i+16])+',' for i in range(0,len(data),16))
        return match[1]+body+match[5]
    result,count=re.subn(pattern,replace,text,flags=re.S)
    assert count==len(images) and replaced[0]==len(known)
    return result


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('checkout',type=Path);p.add_argument('inventory',type=Path)
    p.add_argument('--public-certificate-fixture',type=Path,required=True);p.add_argument('--output',type=Path,required=True)
    p.add_argument('--abi-layout',action='store_true',help='Also reconstruct named relocations and zero globals; poison every removed source byte')
    p.add_argument('--zero-local-functions',action='store_true',help='Negative control zeros only the recovered encoded local-function slots')
    args=p.parse_args();root=args.checkout.resolve();source=root/'crypto/keygen_experimental';build=root/'build/spc-payload'
    native=Path(__file__).resolve().parents[1]/'src/apple_music_source/_native'
    entries=cells(root,json.loads(args.inventory.read_text()));control={address+i for address in entries for i in range(4)}
    local_cells=sorted(address for address,row in entries.items() if row.get('memory_kind')=='pristine relative function slot')
    assert not args.zero_local_functions or local_cells,'local-function inventory required'
    local_test=' || '.join(f'(address >= UINT64_C(0x{a:x}) && address < UINT64_C(0x{a+4:x}))' for a in local_cells) or '0'
    local_helper='static int ams_local_function_byte(uint64_t address){return '+local_test+';}\n'
    known=set(control);known.update(range(0x525a00,0x525a5c))
    for at in (0x580,0xe20,0xe30,0x1170,0x25b0,0x25c0,0x35d0,0x4690,0x4c40,0x4f40):known.update(range(0x10000000+at,0x10000000+at+16))
    abi_counts={}
    if args.abi_layout:
        from generate_abi_layout import describe
        from verify_abi_layout import known_addresses
        _,slots,zeros=describe(root);known.update(known_addresses(slots,zeros))
        abi_counts=dict(abi_modeled_relocations=sum(r['kind']!='unsupported' for r in slots.values()),
                        zero_global_bytes=sum(z['size'] for z in zeros))
    images=json.loads((root/'tools/crypto/keygen_experimental/source_image_manifest.json').read_text())['images']
    poison=0xa5 if args.abi_layout else 0
    scrubbed=scrub_images((source/'native_generated/images.inc').read_text(),images,known,poison)
    original=(source/'spc_generate.c').read_text();needle='memcpy(r->owned[j],image->data,image->size);';assert original.count(needle)==1
    initializer=r'''
#if AMS_ABI_LAYOUT
        ams_source_binding abi_bindings[sizeof kg_source_service_names/sizeof *kg_source_service_names];
        size_t abi_count=sizeof abi_bindings/sizeof *abi_bindings;
        for(size_t b=0;b<abi_count;++b){abi_bindings[b].name=kg_source_service_names[b];abi_bindings[b].address=UINT64_C(0x800000)+b*16;}
#endif
        for(size_t k=0;k<image->size;++k){
            uint64_t value=0,address=image->address+k;
#if AMS_ABI_LAYOUT
            if(ams_abi_initial_read(address,1,abi_bindings,abi_count,&value)) {
#if !AMS_ABI_MODEL
                value=0;
#endif
                r->owned[j][k]=(unsigned char)value;
            } else
#endif
            if(ams_control_refs_read(address,1,&value)) {
#if !AMS_CONTROL_MODEL
                value=0;
#endif
#if !AMS_LOCAL_FUNCTION_MODEL
                if(ams_local_function_byte(address))value=0;
#endif
                r->owned[j][k]=(unsigned char)value;
            } else if(ams_fill_dispatch_read(address,1,&value))r->owned[j][k]=(unsigned char)value;
            else if(address>=UINT64_C(0x10000000)&&ams_integrity_codec_data_read(address-UINT64_C(0x10000000),1,&value))r->owned[j][k]=(unsigned char)value;
            else r->owned[j][k]=image->data[k];
        }
'''
    capture=r'''
static void (*ams_capture)(const void*,size_t,const wrapper_kg_payload_region*,size_t);
void ams_capture_set(void (*f)(const void*,size_t,const wrapper_kg_payload_region*,size_t)){ams_capture=f;}
'''
    results=[];outputs=[]
    with tempfile.TemporaryDirectory(prefix='ams-control-live-') as temp:
        temporary=Path(temp)
        for mode in ('baseline','model','zero'):
            directory=temporary/mode;directory.mkdir()
            body=original
            if mode!='baseline':
                image_dir=directory/'native_generated';image_dir.mkdir();(image_dir/'images.inc').write_text(scrubbed)
                body=body.replace(needle,initializer)
            body=body.replace('static int kg_generate(',local_helper+capture+'\nstatic int kg_generate(',1)
            marker='done:\n    result->pc=';assert body.count(marker)==1
            body=body.replace(marker,'done:\n    if(ams_capture)ams_capture(&r->state,sizeof r->state,r->regions,KG_REGIONS);\n    result->pc=',1)
            body=body.replace('#include "spc_generate.h"','#include "spc_generate.h"\n#include "control_refs.h"\n#include "abi_layout.h"\n#include "fill_dispatch.h"\n#include "integrity_codec_data.h"',1)
            file=directory/'generate.c';file.write_text(body);library=directory/'generate.so'
            subprocess.run(['cc','-std=c99','-O2','-shared','-fPIC',
                            '-DAMS_CONTROL_MODEL='+str(int(mode!='zero' or args.abi_layout or args.zero_local_functions)),
                            '-DAMS_LOCAL_FUNCTION_MODEL='+str(int(mode!='zero' or not args.zero_local_functions)),
                            '-DAMS_ABI_LAYOUT='+str(int(args.abi_layout)),'-DAMS_ABI_MODEL='+str(int(mode!='zero' or args.zero_local_functions)),
                            '-I'+str(source),'-I'+str(native),str(file),str(source/'ckc_packet.c'),
                            str(native/'control_refs.c'),str(native/'fill_dispatch.c'),str(native/'integrity_codec_data.c'),
                            *([str(native/'abi_layout.c')] if args.abi_layout else []),
                            '-L'+str(build),'-lwrapper_spc_native','-Wl,-rpath,'+str(build),'-o',str(library)],
                           check=True,capture_output=True,text=True)
            read_fd,write_fd=os.pipe();chunks=[]
            def drain():
                try:
                    while True:
                        chunk=os.read(read_fd,65536)
                        if not chunk:break
                        chunks.append(chunk)
                finally:os.close(read_fd)
            reader=threading.Thread(target=drain);reader.start()
            try:
                env=dict(os.environ,AMS_OUTPUT_FD=str(write_fd))
                result=subprocess.run([sys.executable,'-s','-c',PROGRAM,str(root),str(library),str(args.public_certificate_fixture.resolve())],
                                      env=env,check=True,capture_output=True,text=True,timeout=180,pass_fds=(write_fd,))
            finally:os.close(write_fd);reader.join()
            results.append(json.loads(result.stdout));outputs.append(b''.join(chunks))
    assert results[0]==results[1] and outputs[0]==outputs[1],'source reconstruction mismatch'
    assert results[1][-1]['api']==0 and results[1][-1]['output_size']>0,'positive SPC boundary not reached'
    def behavior(row):return tuple(row[k] for k in ('api','status','pc','fault_address','fault_size','source_steps','output_size'))
    assert all(behavior(a)!=behavior(b) for a,b in zip(results[0],results[2])),'zero-control changes only unused data'
    rows=[{k:v for k,v in row.items() if k!='terminal_digest'} for row in results[1]]
    report=dict(status='pass',control_bytes=len(control),total_source_model_bytes=len(known),modeled_source_values_removed_from_temporary_initializer=True,
                temporary_initializer_poison=poison,**abi_counts,
                cases=rows,spc_outputs_equal_in_ram=True,terminal_native_state_and_all_regions_equal=True,
                zero_control_changes_executed_behavior=True,
                negative_control='local function slots only' if args.zero_local_functions else ('ABI initializers only' if args.abi_layout else 'source control references'),
                scope='temporary offline source oracle; invented inputs/public certificate only; remaining image/integrity banks retained; no valid CKC/auth or installed package SPC closure proof')
    args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))


if __name__=='__main__':main()
