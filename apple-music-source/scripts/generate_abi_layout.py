"""Recover source-layout zero globals and symbolic relocation initializers.

Pinned ELFs are development metadata oracles only. No relocated word/image is
emitted. Imports remain symbol-plus-addend expressions over caller bindings;
relative/defined references require translated source or allocated data targets.
Untranslated/encoded destinations remain unsupported, including inside BSS.
"""
import argparse
import json
from pathlib import Path
import re
import sys

from probe_control_data import Classifier
from verify_integrity_codec import HASH
from verify_fill_dispatch import APP_HASH


def describe(root):
    sys.path.insert(0,str(root/'tools/crypto/keygen_experimental'))
    from generate_source_images import module
    classifier=Classifier(root);modules=[];slots={};zeros=[]
    for name,digest,base,identifier in [('libandroidappmusic.so',APP_HASH,0,'APP'),
                                        ('libCoreLSKD.so',HASH,0x10000000,'CORE')]:
        m=module(root/'rootfs/system/lib64'/name,digest,base);m['identifier']=identifier;modules.append(m)
        for section,s in m['sections'].items():
            if s[1]==8 and s[2]&2:zeros.append(dict(module=identifier,section=section,address=base+s[3],size=s[5]))
        def location(value):
            if base+value in classifier.labels:return dict(kind='source code',address=base+value)
            for section,s in m['sections'].items():
                if s[2]&2 and not(s[2]&4) and s[3]<=value<s[3]+s[5]:
                    return dict(kind='source data',section=section,base=base+s[3],offset=value-s[3])
            return None
        for target,info,addend in m['relocs']:
            kind,index=info&0xffffffff,info>>32;address=base+target
            row=dict(address=address,module=identifier,kind='unsupported',reason='unresolved destination')
            if kind==8:
                destination=location(addend)
                if destination:row.update(kind='relative',destination=destination)
            elif kind in (1,6,7):
                symbol,value=m['symbols'][index]
                if symbol and symbol.isascii():
                    if not value:row.update(kind='import',symbol=symbol,addend=addend)
                    else:
                        destination=location(value)
                        # Named source address plus an offset is admitted only
                        # if its final destination also has a source identity.
                        if destination and location(value+addend):
                            row.update(kind='defined',symbol=symbol,destination=destination,addend=addend)
            else:raise ValueError('unsupported ELF relocation kind')
            if row['kind']!='unsupported':row.pop('reason',None)
            slots[address]=row  # Loader order: the last relocation at a slot wins.
    addresses=sorted(slots)
    assert all(a+8<=b for a,b in zip(addresses,addresses[1:])), 'overlapping relocation words need a byte-level model'
    return modules,slots,zeros


def location_expression(destination):
    if destination['kind']=='source code':return f'UINT64_C(0x{destination["address"]:x})'
    return f'(UINT64_C(0x{destination["base"]:x}) + UINT64_C(0x{destination["offset"]:x}))'


def emit(root,native):
    modules,slots,zeros=describe(root)
    out=['/* Source-layout linker metadata. No relocated word or image bank.',
         ' * Imported values are resolved by NAME from source-owned bindings.',
         ' * Relative/defined values name translated code or allocated data.',
         ' * Unexplained encoded targets remain unsupported. Zero initialization',
         ' * is C global-storage semantics, overridden by relocation slots.',
         ' * For pristine initialization ONLY; never a mutable-read fallback. */',
         '#include "abi_layout.h"','#include <string.h>','',
         'static const uint64_t relocation_slots[] = {']
    addresses=sorted(slots)
    for i in range(0,len(addresses),5):out.append('    '+','.join(f'UINT64_C(0x{a:x})' for a in addresses[i:i+5])+',')
    out+=['};','',
          'static int binding(const ams_source_binding *bindings,size_t count,const char *name,uint64_t *value) {',
          '    size_t i; int found=0; uint64_t result=0;',
          '    for(i=0;i<count;++i) {',
          '        if(!bindings[i].name)return 0;',
          '        if(!strcmp(bindings[i].name,name)) {',
          '            if(found)return 0;',
          '            found=1; result=bindings[i].address;',
          '        }','    }','    if(!found)return 0;',
          '    *value=result; return 1;','}','',
          'static int relocated(uint64_t address,const ams_source_binding *bindings,size_t count,uint64_t *value) {',
          '    uint64_t symbol;','    switch(address) {']
    for address,row in sorted(slots.items()):
        if row['kind']=='unsupported':continue
        out.append(f'    case UINT64_C(0x{address:x}):')
        if row['kind']=='import':
            out += [f'        if(!binding(bindings,count,{json.dumps(row["symbol"])},&symbol))return 0;',
                    f'        *value=symbol+UINT64_C(0x{row["addend"]&((1<<64)-1):x}); return 1;']
        else:
            destination=row['destination'];comment=row.get('symbol',destination['kind']).replace('*/','* /')
            out.append(f'        /* {row["module"]} {comment} */')
            expression=location_expression(destination)
            if row['kind']=='defined':expression+=f' + UINT64_C(0x{row["addend"]&((1<<64)-1):x})'
            out.append(f'        *value={expression}; return 1;')
    out += ['    default:return 0;','    }','}','',
            'int ams_abi_initial_read(uint64_t address,unsigned width,const ams_source_binding *bindings,size_t count,uint64_t *output) {',
            '    uint64_t result=0,cached_address=UINT64_MAX,cached_word=0;',
            '    unsigned i;',
            '    if(!output||!width||width>8||address>UINT64_MAX-(width-1)||',
            '       count>SIZE_MAX/sizeof *bindings||(count&&!bindings)||',
            '       (count&&(uintptr_t)bindings>UINTPTR_MAX-count*sizeof *bindings))return 0;',
            '    for(i=0;i<width;++i) {',
            '        uint64_t at=address+i;size_t lo=0,hi=sizeof relocation_slots/sizeof *relocation_slots;',
            '        while(lo<hi){size_t mid=lo+(hi-lo)/2;if(relocation_slots[mid]<=at)lo=mid+1;else hi=mid;}',
            '        if(lo&&at-relocation_slots[lo-1]<8) {',
            '            uint64_t slot=relocation_slots[lo-1];',
            '            if(slot!=cached_address){if(!relocated(slot,bindings,count,&cached_word))return 0;cached_address=slot;}',
            '            result|=((cached_word>>(8*(unsigned)(at-slot)))&255)<<(8*i);',
            '        } else {']
    terms=[f'(at>=UINT64_C(0x{z["address"]:x})&&at<UINT64_C(0x{z["address"]+z["size"]:x}))' for z in zeros]
    out += ['            if(!('+'||'.join(terms)+'))return 0;',
            '        }','    }','    *output=result;return 1;','}','']
    native.mkdir(parents=True,exist_ok=True);(native/'abi_layout.c').write_text('\n'.join(out))
    (native/'abi_layout.h').write_text('''#ifndef AMS_ABI_LAYOUT_H
#define AMS_ABI_LAYOUT_H
#include <stddef.h>
#include <stdint.h>
typedef struct ams_source_binding { const char *name; uint64_t address; } ams_source_binding;
/* Pristine initial globals at source-runner virtual addresses. Bindings name
 * source-owned import implementations, never a vendor SDK or crypto provider.
 * This does not call any binding. Names must be readable NUL-terminated strings;
 * missing/ambiguous requested names and unsupported source locations fail closed.
 * Reads are atomic with respect to output. This initializes ordinary memory;
 * it MUST NOT override mutated data, permissions, faults or shadow policy.
 * It is not a complete image loader or crypto/auth/session implementation. */
int ams_abi_initial_read(uint64_t address,unsigned width,const ams_source_binding *bindings,size_t count,uint64_t *output);
#endif
''')
    return dict(relocation_slots=len(slots),modeled_relocations=sum(row['kind']!='unsupported' for row in slots.values()),
                zero_global_bytes=sum(z['size'] for z in zeros),categories={kind:sum(row['kind']==kind for row in slots.values()) for kind in ('relative','defined','import','unsupported')})


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('checkout',type=Path);p.add_argument('--native',type=Path,required=True)
    args=p.parse_args();print(json.dumps(emit(args.checkout.resolve(),args.native)))


if __name__=='__main__':main()
