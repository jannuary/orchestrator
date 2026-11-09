"""Verify source ABI initializers against independently applied ELF relocations.

The linked images are development-only RAM oracles, never emitted or imported
by package code. Alternate bindings prove that imports are symbolic expressions
instead of captured relocated values. Reports contain counts and booleans only.
"""
import argparse
import ctypes as C
import json
from pathlib import Path
import struct
import subprocess
import tempfile

from generate_abi_layout import describe


class Binding(C.Structure):
    _fields_=[('name',C.c_char_p),('address',C.c_uint64)]


def binding_array(names,addresses):
    return (Binding*len(names))(*(Binding(name.encode('ascii'),addresses[name]) for name in names))


def relocated_images(modules,bindings):
    result=[]
    for module in modules:
        data=bytearray(module['rw'])
        for target,info,addend in module['relocs']:
            kind,index=info&0xffffffff,info>>32
            if kind==8:value=module['base']+addend
            else:
                name,value=module['symbols'][index]
                value=(module['base']+value if value else bindings[name])+addend
            struct.pack_into('<Q',data,target-module['rw_lo'],value&((1<<64)-1))
        result.append((module['base']+module['rw_lo'],data))
    return result


def oracle_read(images,address,width):
    for start,data in images:
        if start<=address and address+width<=start+len(data):return int.from_bytes(data[address-start:address-start+width],'little')
    raise AssertionError('oracle range missing')


def known_addresses(slots,zeros):
    known={z['address']+i for z in zeros for i in range(z['size'])}
    for address,row in slots.items():
        if row['kind']=='unsupported':known.difference_update(range(address,address+8))
        else:known.update(range(address,address+8))
    return known


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('checkout',type=Path);p.add_argument('--output',type=Path,required=True)
    args=p.parse_args();root=args.checkout.resolve();modules,slots,zeros=describe(root)
    names=json.loads((root/'tools/crypto/keygen_experimental/source_image_manifest.json').read_text())['services']
    addresses={name:0x800000+i*16 for i,name in enumerate(names)};bindings=binding_array(names,addresses)
    images=relocated_images(modules,addresses);known=known_addresses(slots,zeros)
    native=Path(__file__).resolve().parents[1]/'src/apple_music_source/_native'
    compared=rejected=alternative_cases=0
    with tempfile.TemporaryDirectory(prefix='ams-abi-verify-') as temp:
        library=Path(temp)/'abi.so'
        subprocess.run(['cc','-std=c99','-O2','-Wall','-Wextra','-Werror','-shared','-fPIC',str(native/'abi_layout.c'),'-o',str(library)],check=True)
        read=C.CDLL(str(library)).ams_abi_initial_read
        read.argtypes=[C.c_uint64,C.c_uint,C.POINTER(Binding),C.c_size_t,C.POINTER(C.c_uint64)];read.restype=C.c_int
        for address in sorted(known):
            for width in range(1,9):
                out=C.c_uint64(0xdecafbad12345678)
                if all(address+i in known for i in range(width)):
                    assert read(address,width,bindings,len(bindings),C.byref(out))==1
                    assert out.value==oracle_read(images,address,width),(hex(address),width)
                    compared+=1
                else:
                    assert read(address,width,bindings,len(bindings),C.byref(out))==0 and out.value==0xdecafbad12345678
                    rejected+=1
        import_rows=[row for row in slots.values() if row['kind']=='import']
        for alternative in ({name:0 for name in names},
                            {name:(0xfffffffffffffff0+i*32)&((1<<64)-1) for i,name in enumerate(names)}):
            other=binding_array(names,alternative);oracle=relocated_images(modules,alternative)
            for row in import_rows:
                out=C.c_uint64()
                assert read(row['address'],8,other,len(other),C.byref(out))==1
                assert out.value==oracle_read(oracle,row['address'],8)
                alternative_cases+=1
        row=import_rows[0];symbol=row['symbol'];partial=[name for name in names if name!=symbol]
        variants=[(None,0),(binding_array(partial,addresses),len(partial)),
                  ((Binding*2)(Binding(symbol.encode(),1),Binding(symbol.encode(),2)),2),
                  ((Binding*1)(Binding(None,1)),1)]
        for other,count in variants:
            out=C.c_uint64(0xdecafbad12345678)
            assert read(row['address'],8,other,count,C.byref(out))==0 and out.value==0xdecafbad12345678
            rejected+=1
        for address,row in slots.items():
            if row['kind']!='unsupported':continue
            out=C.c_uint64(0xdecafbad12345678)
            assert read(address,8,bindings,len(bindings),C.byref(out))==0 and out.value==0xdecafbad12345678
            rejected+=1
        for address,width,count,other in ((0,1,0,None),(2**64-1,8,0,None),(min(known),0,0,None),
                                          (min(known),9,0,None),(min(known),1,1,None)):
            out=C.c_uint64(0xdecafbad12345678)
            assert read(address,width,other,count,C.byref(out))==0 and out.value==0xdecafbad12345678
            rejected+=1
        assert read(min(known),1,bindings,len(bindings),None)==0;rejected+=1
    report=dict(status='pass',modeled_bytes=len(known),relocation_slots=len(slots),
                modeled_relocations=sum(r['kind']!='unsupported' for r in slots.values()),
                zero_global_bytes=sum(z['size'] for z in zeros),read_comparisons=compared,
                alternate_binding_comparisons=alternative_cases,rejection_preservation_checks=rejected,
                relation='all admitted 1..8-byte initializer reads equal independently linked source-layout oracles; alternate/zero binding addresses and wrap; missing/ambiguous names, gaps and unsupported destinations reject',
                scope='pristine layout only; not a runtime mutable-memory fallback or full source image/crypto/auth closure')
    args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))


if __name__=='__main__':main()
