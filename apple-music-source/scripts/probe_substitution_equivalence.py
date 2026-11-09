"""Offline algebraic investigation of five live substitution tables.

Pinned ELF is a developer oracle only. Table values and recovered maps stay in
RAM. Reports contain structural booleans/counts, never table/encoding/key bytes.
This neither ships an initializer nor claims the surrounding crypto is known.
"""
import argparse
import collections
import ctypes as C
import json
from pathlib import Path
import random
import subprocess
import sys
import tempfile

from probe_control_data import Classifier
from verify_fill_dispatch import segment_read


SEARCH = r'''
#include <stdint.h>
#include <string.h>
typedef struct {uint8_t a[8],b[8];unsigned rank;} map;
static int insert(map *m,unsigned a,unsigned b){
 for(int i=7;i>=0;--i)if(a&(1u<<i)){
  if(m->a[i]){a^=m->a[i];b^=m->b[i];}
  else{m->a[i]=a;m->b[i]=b;++m->rank;return 1;}}
 return !b;
}
static unsigned apply(const map *m,unsigned x){
 unsigned y=0;for(int i=7;i>=0;--i)if(x&(1u<<i)){x^=m->a[i];y^=m->b[i];}return y;
}
static int finish(const map *m,const uint8_t *f,const uint8_t *inverse,uint8_t *input_map,uint8_t *output_map){
 uint8_t back[256],seen[256]={0},b[256];
 if(m->rank!=8)return 0;
 for(unsigned x=0;x<256;++x){unsigned y=apply(m,x);if(seen[y])return 0;seen[y]=1;back[y]=x;}
 for(unsigned x=0;x<256;++x)b[x]=inverse[back[f[x]]];
 for(unsigned x=0;x<256;++x){unsigned y=0;for(unsigned k=0;k<8;++k)if(x&(1u<<k))y^=b[1u<<k];if(y!=b[x])return 0;}
 for(unsigned k=0;k<8;++k){input_map[k]=b[1u<<k];output_map[k]=apply(m,1u<<k);}
 return 1;
}
int equivalent(const uint8_t *f,const uint8_t *inverse,uint64_t *trials,uint8_t *input_map,uint8_t *output_map){
 map first={{0},{0},0};if(f[0]||!insert(&first,1,f[1]))return 0;*trials=0;
 for(unsigned v2=2;v2<256;++v2){
  unsigned span[16]={0,1,v2,1^v2};map second=first;int ok=1;
  for(unsigned x=2;x<4;++x)if(!insert(&second,inverse[span[x]],f[x])){ok=0;break;}if(!ok)continue;
  for(unsigned v3=2;v3<256;++v3){
   int used=0;for(unsigned x=0;x<4;++x)if(span[x]==v3)used=1;if(used)continue;
   for(unsigned x=0;x<4;++x)span[x+4]=span[x]^v3;
   map third=second;ok=1;
   for(unsigned x=4;x<8;++x)if(!insert(&third,inverse[span[x]],f[x])){ok=0;break;}if(!ok)continue;
   for(unsigned v4=2;v4<256;++v4){
    used=0;for(unsigned x=0;x<8;++x)if(span[x]==v4)used=1;if(used)continue;
    ++*trials;map fourth=third;ok=1;
    for(unsigned x=0;x<8;++x)if(!insert(&fourth,inverse[span[x]^v4],f[x+8])){ok=0;break;}
    if(ok&&finish(&fourth,f,inverse,input_map,output_map))return 1;
   }
  }
 }
 return 0;
}
'''


def coordinates(values,with_basis=False):
    basis={}
    for value in values:
        x=value
        for bit in sorted(basis,reverse=True):
            if x&(1<<bit):x^=basis[bit]
        if x:basis[x.bit_length()-1]=x
    if len(basis)!=8:return None
    result=[]
    for x in values:
        y=0
        for i,bit in enumerate(sorted(basis,reverse=True)):
            if x&(1<<bit):x^=basis[bit];y^=1<<i
        assert x==0
        result.append(y)
    return (result,[basis[bit] for bit in sorted(basis,reverse=True)]) if with_basis else result


def investigate(values,search,inverse):
    derivative=[0];spectrum=collections.Counter()
    for delta in range(1,256):
        counts=collections.Counter(values[x]^values[x^delta] for x in range(256))
        spectrum.update(counts.values())
        fourth=[v for v,n in counts.items() if n==4]
        if len(fourth)!=1 or any(n not in (2,4) for n in counts.values()):
            return dict(inversion_differential_structure=False)
        derivative.append(fourth[0])
    shifts=[k for k in range(256) if all(values[x]^values[0]==derivative[x^k]^derivative[k] for x in range(256))]
    compact_data=coordinates(derivative,with_basis=True)
    result=dict(inversion_differential_structure=True,translation_solutions=len(shifts),output_affine_rank=8 if compact_data else None)
    if not compact_data or len(shifts)!=1:return result
    compact,basis=compact_data
    # The fixed first four input coordinates must determine an 8-bit output
    # map. Otherwise this bounded search refuses to make a negative claim.
    if coordinates(derivative[:16]) is None:
        result['search']='unsupported first-four-coordinate rank';return result
    trials=C.c_uint64()
    input_map=(C.c_uint8*8)();output_map=(C.c_uint8*8)()
    result['affine_equivalent_to_gf256_inversion']=bool(search((C.c_uint8*256)(*compact),inverse,C.byref(trials),input_map,output_map))
    result['candidate_maps_checked']=trials.value
    if result['affine_equivalent_to_gf256_inversion']:
        from apple_music_source.crypto.aes import _gpow,_gmul
        def linear(columns,x):
            y=0
            for i,column in enumerate(columns):
                if x&(1<<i):y^=column
            return y
        word_map=[linear(basis,x) for x in output_map]
        rebuilt=[linear(word_map,inverse[linear(input_map,x)]) for x in range(256)]
        assert rebuilt==derivative
        k=shifts[0]
        assert all(rebuilt[x^k]^rebuilt[k]^values[0]==values[x] for x in range(256))
        result['independent_full_table_reconstruction_checks']=256
        result['input_linear_is_field_frobenius']=any(all(linear(input_map,x)==_gpow(x,1<<j) for x in range(256)) for j in range(8))
        at_one=linear(word_map,1)
        result['output_byte_maps_share_field_linear_form']=any(
            all(linear(word_map,x)==sum(_gmul((at_one>>(8*b))&255,_gpow(x,1<<j))<<(8*b) for b in range(4)) for x in range(256))
            for j in range(8))
    return result


def source_arithmetic_decode(classifier,values):
    """Evaluate the actual post-load consumer, without fitting another table."""
    from capstone import CS_OP_REG,CS_OP_IMM
    raw=classifier.images[0][1]
    specifications=[(0x1052b84d,'imul','ecx','eax'),(0x1052b853,'imul','eax','eax'),
                    (0x1052b859,'add','eax',None),(0x1052b864,'and','eax',None),
                    (0x1052b872,'add','ecx',None)]
    constants=[]
    for pc,mn,dest,source in specifications:
        ins=next(classifier.decoder.disasm(segment_read(raw,pc-0x10000000,16),pc,count=1))
        ops=ins.operands
        assert ins.mnemonic==mn and ops[0].type==CS_OP_REG and ins.reg_name(ops[0].reg)==dest and ops[0].size==4
        assert ops[-1].type==CS_OP_IMM
        if source:assert ops[1].type==CS_OP_REG and ins.reg_name(ops[1].reg)==source
        constants.append(ops[-1].imm&0xffffffff)
    pc=0x1052b869;ins=next(classifier.decoder.disasm(segment_read(raw,pc-0x10000000,16),pc,count=1))
    assert ins.mnemonic=='sub' and ins.op_str=='ecx, eax'
    a,b,c,mask,d=constants
    return [(x*a-((x*b+c)&mask)+d)&0xffffffff for x in values]


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('checkout',type=Path);parser.add_argument('--output',type=Path,required=True)
    args=parser.parse_args();root=args.checkout.resolve()
    sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'src'))
    from apple_music_source.crypto.aes import _gpow,_SBOX
    inverse=(C.c_uint8*256)(*(_gpow(x,254) if x else 0 for x in range(256)))
    classifier=Classifier(root);rows=[]
    with tempfile.TemporaryDirectory(prefix='ams-substitution-') as temp:
        source=Path(temp)/'search.c';source.write_text(SEARCH);library=Path(temp)/'search.so'
        subprocess.run(['cc','-std=c99','-O3','-shared','-fPIC',str(source),'-o',str(library)],check=True)
        search=C.CDLL(str(library)).equivalent
        search.argtypes=[C.POINTER(C.c_uint8),C.POINTER(C.c_uint8),C.POINTER(C.c_uint64),C.POINTER(C.c_uint8),C.POINTER(C.c_uint8)];search.restype=C.c_int
        control=investigate(list(_SBOX),search,inverse)
        assert control.get('affine_equivalent_to_gf256_inversion'),control
        rng=random.Random(0xa351);synthetic=[]
        def linear(columns,x):
            result=0
            for i,column in enumerate(columns):
                if x&(1<<i):result^=column
            return result
        for _ in range(3):
            # Random elementary row additions/swaps preserve invertibility;
            # this positive fixture is independent of every vendor table.
            left=[1<<i for i in range(8)];right=[1<<i for i in range(8)]
            for columns in (left,right):
                for _ in range(32):
                    a,b=rng.sample(range(8),2);columns[a]^=columns[b]
            shift=rng.randrange(256);offset=rng.randrange(256)
            values=[linear(right,inverse[linear(left,x)^shift])^offset for x in range(256)]
            result=investigate(values,search,inverse)
            assert result.get('affine_equivalent_to_gf256_inversion'),result
            synthetic.append(result)
        random_permutation=list(range(256));rng.shuffle(random_permutation)
        rejected=investigate(random_permutation,search,inverse)
        assert rejected.get('inversion_differential_structure') is False,rejected
        for base in (0x1003f340,0x10063830,0x100aa7f0,0x100a8b50,0x100686e0):
            values=[classifier.pristine_read(base+4*x,4) for x in range(256)]
            rows.append(dict(source_address=hex(base),**investigate(values,search,inverse)))
        base=0x10081ed0
        values=[classifier.pristine_read(base+4*x,4) for x in range(256)]
        decoded=source_arithmetic_decode(classifier,values)
        rows.append(dict(source_address=hex(base),source_consumer='0x1052b84d..0x1052b878',
                         arithmetic_decode_from_checked_instructions=True,
                         **investigate(decoded,search,inverse)))
    report=dict(status='bounded algebraic investigation',computed_aes_control=control,
                synthetic_affine_controls=synthetic,random_permutation_rejected=True,tables=rows,
                scope='all table and recovered map values RAM-only; no shipped initializer, encoding/key bytes or surrounding-crypto equivalence claim')
    args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))


if __name__=='__main__':main()
