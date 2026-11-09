"""Classify aligned 256-word affine-image windows in pinned readonly data.

No table/encoding/key values are written. Windows are candidates, not proven
object declarations or live uses. The exact inversion-equivalence check keeps
all inferred maps in RAM. This is developer research, never a runtime provider.
"""
import argparse
import ctypes as C
import hashlib
import json
from pathlib import Path
import subprocess
import sys
import tempfile

from probe_substitution_equivalence import SEARCH,investigate
from verify_integrity_codec import HASH
from verify_fill_dispatch import segment_read


SCAN=r'''
#include <stdlib.h>
#include <stddef.h>
static int compare_words(const void *left,const void *right){
 uint32_t a=*(const uint32_t*)left,b=*(const uint32_t*)right;
 return (a>b)-(a<b);
}
int scan_candidates(const uint8_t *data,size_t size,uint32_t *offsets,size_t capacity){
 unsigned found=0;if(size<1024)return 0;
 for(size_t start=0;start<=size-1024;start+=16){
  uint32_t words[256],basis[32]={0};unsigned rank=0,valid=1;
  for(unsigned j=0;j<256;++j){
   size_t p=start+4*j;
   words[j]=(uint32_t)data[p]|(uint32_t)data[p+1]<<8|(uint32_t)data[p+2]<<16|(uint32_t)data[p+3]<<24;
   uint32_t x=words[j]^words[0];
   for(int bit=31;bit>=0;--bit)if(x&(UINT32_C(1)<<bit)){
    if(basis[bit])x^=basis[bit];else{basis[bit]=x;++rank;break;}}
   if(rank>8){valid=0;break;}
  }
  if(!valid||rank!=8)continue;
  qsort(words,256,sizeof *words,compare_words);
  for(unsigned j=1;j<256;++j)if(words[j]==words[j-1]){valid=0;break;}
  if(!valid)continue;
  if(found>=capacity)return -1;offsets[found++]=(uint32_t)start;
 }
 return (int)found;
}
'''


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('checkout',type=Path);p.add_argument('--output',type=Path,required=True)
    p.add_argument('--limit',type=int,default=0,help='Zero attempts all candidate windows')
    args=p.parse_args();assert args.limit>=0;root=args.checkout.resolve()
    raw=(root/'rootfs/system/lib64/libCoreLSKD.so').read_bytes();assert hashlib.sha256(raw).hexdigest()==HASH
    data=segment_read(raw,0,0xcf9f8)
    sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'src'))
    from apple_music_source.crypto.aes import _gpow
    inverse=(C.c_uint8*256)(*(_gpow(x,254) if x else 0 for x in range(256)))
    rows=[]
    with tempfile.TemporaryDirectory(prefix='ams-substitution-scan-') as temp:
        source=Path(temp)/'scan.c';library=Path(temp)/'scan.so';source.write_text(SEARCH+SCAN)
        subprocess.run(['cc','-std=c99','-O3','-shared','-fPIC',str(source),'-o',str(library)],check=True)
        lib=C.CDLL(str(library));scan=lib.scan_candidates
        scan.argtypes=[C.POINTER(C.c_uint8),C.c_size_t,C.POINTER(C.c_uint32),C.c_size_t];scan.restype=C.c_int
        buf=(C.c_uint8*len(data)).from_buffer_copy(data);offsets=(C.c_uint32*(len(data)//16+1))()
        count=scan(buf,len(data),offsets,len(offsets));assert count>=0
        search=lib.equivalent
        search.argtypes=[C.POINTER(C.c_uint8),C.POINTER(C.c_uint8),C.POINTER(C.c_uint64),C.POINTER(C.c_uint8),C.POINTER(C.c_uint8)];search.restype=C.c_int
        selected=list(offsets[:count]);selected=selected[:args.limit] if args.limit else selected
        for offset in selected:
            values=[int.from_bytes(data[offset+4*i:offset+4*i+4],'little') for i in range(256)]
            rows.append(dict(address=hex(0x10000000+offset),**investigate(values,search,inverse)))
    report=dict(status='bounded static inversion-family classification',core_sha256=HASH,readonly_bytes=len(data),
                alignment=16,window_bytes=1024,candidate_windows=count,attempted_windows=len(rows),
                exact_inversion_family_windows=sum(r.get('affine_equivalent_to_gf256_inversion',False) for r in rows),
                rows=rows,
                scope='aligned affine-rank-eight bijective candidate windows only; no reachability, object-layout, full cipher identity, key independence or standalone crypto/auth proof; all words/maps RAM-only')
    args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k!='rows'}))


if __name__=='__main__':main()
