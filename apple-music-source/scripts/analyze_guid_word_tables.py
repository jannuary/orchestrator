"""Test source-immediate additive normalizations of indexed GUID word arrays.

Hypotheses are bounded by nearby source constants and verified over all 256
words. They do not prove the actual consumer implements that normalization.
All constants, words, offsets and affine maps remain only in RAM.
"""
import argparse
import ctypes as C
import hashlib
import json
from pathlib import Path
import subprocess
import sys
import tempfile

from inventory_guid_word_tables import translated_instructions
from probe_substitution_equivalence import SEARCH,investigate
from scan_auth_substitutions import TARGETS
from verify_fill_dispatch import segment_read


OFFSET_SEARCH=r'''
#include <stdint.h>
#include <stddef.h>
size_t additive_offsets(const uint32_t *words,const uint32_t *offsets,size_t count,uint32_t *indices,size_t capacity){
 size_t found=0;
 for(size_t i=0;i<count;++i){uint32_t basis[32]={0},first=words[0]+offsets[i];unsigned rank=0;
  for(unsigned j=1;j<256;++j){uint32_t x=(words[j]+offsets[i])^first;
   for(int bit=31;bit>=0;--bit)if(x&(UINT32_C(1)<<bit)){
    if(basis[bit])x^=basis[bit];else {basis[bit]=x;if(++rank>8)goto rejected;break;}}
  }
  if(rank==8){if(found<capacity)indices[found]=(uint32_t)i;++found;}
rejected:;
 }
 return found;
}
'''


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('checkout',type=Path)
    parser.add_argument('--inventory',type=Path,required=True)
    parser.add_argument('--output',type=Path,required=True)
    args=parser.parse_args()
    from capstone import Cs,CS_ARCH_X86,CS_MODE_64,CS_OP_IMM,CS_OP_MEM
    decoder=Cs(CS_ARCH_X86,CS_MODE_64);decoder.detail=True
    sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'src'))
    from apple_music_source.crypto.aes import _gpow
    inverse=(C.c_uint8*256)(*(_gpow(x,254) if x else 0 for x in range(256)))
    inventory=json.loads(args.inventory.read_text());rows=[]
    with tempfile.TemporaryDirectory(prefix='ams-guid-word-normalization-') as directory:
        source,library=Path(directory)/'normalize.c',Path(directory)/'normalize.so'
        source.write_text(SEARCH+OFFSET_SEARCH)
        subprocess.run(['cc','-std=c99','-O3','-shared','-fPIC',str(source),'-o',str(library)],check=True,capture_output=True)
        native=C.CDLL(str(library));find=native.additive_offsets;search=native.equivalent
        find.argtypes=[C.POINTER(C.c_uint32),C.POINTER(C.c_uint32),C.c_size_t,C.POINTER(C.c_uint32),C.c_size_t];find.restype=C.c_size_t
        search.argtypes=[C.POINTER(C.c_uint8),C.POINTER(C.c_uint8),C.POINTER(C.c_uint64),C.POINTER(C.c_uint8),C.POINTER(C.c_uint8)];search.restype=C.c_int
        for module in inventory['rows']:
            filename,digest=TARGETS[module['target']]
            image=(args.checkout/'rootfs/system/lib64'/filename).read_bytes()
            assert module['artifact_sha256']==hashlib.sha256(image).hexdigest()==digest
            constants={0}
            for region in module['scanned_ranges']:
                begin,end=(int(region[name],16) for name in ('begin','end'))
                for ins in translated_instructions(args.checkout,image,decoder,module['target'],begin,end):
                    for operand in ins.operands:
                        if operand.type==CS_OP_IMM:value=operand.imm
                        elif operand.type==CS_OP_MEM:value=operand.mem.disp
                        else:continue
                        value&=0xffffffff
                        for candidate in (value,-value,value>>1,-(value>>1),value^0x80000000,(value>>1)^0x80000000):constants.add(candidate&0xffffffff)
            offsets=sorted(constants);offset_array=(C.c_uint32*len(offsets))(*offsets);tables=[]
            for table in module['candidate_tables']:
                result=dict(elf_virtual_address=table['elf_virtual_address'],source_load_sites=table['source_load_sites'],raw_affine_rank=table['raw_affine_rank'])
                if table['distinct_words']!=256:
                    result['status']='not a bijective 256-word candidate';tables.append(result);continue
                base=int(table['elf_virtual_address'],16);data=segment_read(image,base,1024)
                words=[int.from_bytes(data[j:j+4],'little') for j in range(0,1024,4)]
                indices=(C.c_uint32*64)()
                count=find((C.c_uint32*256)(*words),offset_array,len(offsets),indices,len(indices)) if table['raw_affine_rank']!=8 else 1
                selected=[offsets[index] for index in indices[:min(count,len(indices))]] if table['raw_affine_rank']!=8 else [0]
                result['rank_eight_offset_hypotheses']=count
                result['tested_offset_hypotheses']=0;result['inversion_family_match']=False
                for offset in selected:
                    normalized=[(word+offset)&0xffffffff for word in words]
                    classified=investigate(normalized,search,inverse);result['tested_offset_hypotheses']+=1
                    if classified.get('affine_equivalent_to_gf256_inversion'):
                        result.update(inversion_family_match=True,additive_normalization_needed=table['raw_affine_rank']!=8,
                                      independently_reconstructed_words=classified['independent_full_table_reconstruction_checks']);break
                result['status']='bounded source-constant hypothesis search';tables.append(result)
            rows.append(dict(target=module['target'],artifact_sha256=digest,source_offset_candidate_count=len(offsets),tables=tables))
    report=dict(status='bounded additive word-array normalization hypotheses',rows=rows,
        scope='complete 256-word checks for tested source-immediate offsets only; inferred offsets/maps stay RAM-only; no actual-consumer proof except separate verified decoder, no table initializer or native-auth closure')
    args.output.write_text(json.dumps(report,indent=2)+'\n')
    print(json.dumps(dict(status=report['status'],modules=[dict(target=row['target'],tables=len(row['tables']),
        inversion_matches=sum(table.get('inversion_family_match',False) for table in row['tables']),
        additive_matches=sum(table.get('inversion_family_match',False) and table.get('additive_normalization_needed',False) for table in row['tables'])) for row in rows])))


if __name__=='__main__':main()
