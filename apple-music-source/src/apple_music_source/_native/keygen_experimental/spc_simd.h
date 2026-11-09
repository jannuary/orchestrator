#ifndef WRAPPER_KG_SPC_SIMD_H
#define WRAPPER_KG_SPC_SIMD_H
#include <stdint.h>
/* Portable integer-vector semantics; lanes are numbered from the low byte.
 * No host vector instructions, executable image, alignment or signed-overflow
 * assumptions are required. Legacy SSE arithmetic leaves integer flags alone. */
typedef struct kg_vec {uint64_t lo,hi;} kg_vec;
enum {
 KG_SIMD_PADDB,KG_SIMD_PSUBB,KG_SIMD_PAND,KG_SIMD_PCMPEQD,
 KG_SIMD_PSHUFD,KG_SIMD_PADDQ,KG_SIMD_PSUBQ,KG_SIMD_PSRLQ,
 KG_SIMD_PMULUDQ,KG_SIMD_PSLLQ,KG_SIMD_PACKUSDW,KG_SIMD_PACKUSWB,
 KG_SIMD_PSHUFB,KG_SIMD_PXOR,KG_SIMD_PADDD,KG_SIMD_PSUBD,
 KG_SIMD_PMULLD,KG_SIMD_PMOVZXBW,KG_SIMD_PUNPCKHBW,KG_SIMD_PMULLW,
 KG_SIMD_PMOVZXDQ,KG_SIMD_PUNPCKHDQ,KG_SIMD_PSRLD,KG_SIMD_PANDN,
 KG_SIMD_POR,KG_SIMD_BLENDVPS,KG_SIMD_PSLLD,KG_SIMD_PCMPEQB,
 KG_SIMD_PMOVSXBD,KG_SIMD_PSRAD
};
#define KG_SIMD_ANDPS KG_SIMD_PAND
#define KG_SIMD_XORPS KG_SIMD_PXOR
static inline uint64_t kg_lane_mask(unsigned bits) {
 return bits==64?UINT64_MAX:((UINT64_C(1)<<bits)-1);
}
static inline uint64_t kg_lane(kg_vec v,unsigned bits,unsigned index) {
 unsigned shift=bits*index;
 return ((shift<64?v.lo:v.hi)>>(shift&63))&kg_lane_mask(bits);
}
static inline void kg_lane_put(kg_vec *v,unsigned bits,unsigned index,uint64_t value) {
 unsigned shift=bits*index;
 uint64_t mask=kg_lane_mask(bits);
 uint64_t *word=shift<64?&v->lo:&v->hi;
 shift&=63;
 *word=(*word&~(mask<<shift))|((value&mask)<<shift);
}
static inline kg_vec kg_simd(unsigned op,kg_vec a,kg_vec b,unsigned imm,kg_vec mask) {
 kg_vec out={0,0};
 unsigned i,bits=0;
 uint64_t x,y,z;
 switch(op) {
 case KG_SIMD_PAND:out.lo=a.lo&b.lo;out.hi=a.hi&b.hi;return out;
 case KG_SIMD_PANDN:out.lo=(~a.lo)&b.lo;out.hi=(~a.hi)&b.hi;return out;
 case KG_SIMD_POR:out.lo=a.lo|b.lo;out.hi=a.hi|b.hi;return out;
 case KG_SIMD_PXOR:out.lo=a.lo^b.lo;out.hi=a.hi^b.hi;return out;
 case KG_SIMD_PSHUFD:
  for(i=0;i<4;++i)kg_lane_put(&out,32,i,kg_lane(b,32,(imm>>(i*2))&3));
  return out;
 case KG_SIMD_PSHUFB:
  for(i=0;i<16;++i){x=kg_lane(b,8,i);kg_lane_put(&out,8,i,(x&128)?0:kg_lane(a,8,(unsigned)x&15));}
  return out;
 case KG_SIMD_PMOVZXBW:
  for(i=0;i<8;++i)kg_lane_put(&out,16,i,kg_lane(b,8,i));
  return out;
 case KG_SIMD_PMOVZXDQ:
  for(i=0;i<2;++i)kg_lane_put(&out,64,i,kg_lane(b,32,i));
  return out;
 case KG_SIMD_PMOVSXBD:
  for(i=0;i<4;++i){x=kg_lane(b,8,i);kg_lane_put(&out,32,i,(x^UINT64_C(128))-UINT64_C(128));}
  return out;
 case KG_SIMD_PUNPCKHBW:
  for(i=0;i<8;++i){kg_lane_put(&out,8,2*i,kg_lane(a,8,i+8));kg_lane_put(&out,8,2*i+1,kg_lane(b,8,i+8));}
  return out;
 case KG_SIMD_PUNPCKHDQ:
  for(i=0;i<2;++i){kg_lane_put(&out,32,2*i,kg_lane(a,32,i+2));kg_lane_put(&out,32,2*i+1,kg_lane(b,32,i+2));}
  return out;
 case KG_SIMD_PMULUDQ:
  for(i=0;i<2;++i)kg_lane_put(&out,64,i,kg_lane(a,32,2*i)*kg_lane(b,32,2*i));
  return out;
 case KG_SIMD_PACKUSDW:
  for(i=0;i<8;++i){x=kg_lane(i<4?a:b,32,i&3);z=(x&UINT64_C(0x80000000))?0:(x>65535?65535:x);kg_lane_put(&out,16,i,z);}
  return out;
 case KG_SIMD_PACKUSWB:
  for(i=0;i<16;++i){x=kg_lane(i<8?a:b,16,i&7);z=(x&32768)?0:(x>255?255:x);kg_lane_put(&out,8,i,z);}
  return out;
 case KG_SIMD_BLENDVPS:
  for(i=0;i<4;++i)kg_lane_put(&out,32,i,kg_lane((kg_lane(mask,32,i)&UINT64_C(0x80000000))?b:a,32,i));
  return out;
 case KG_SIMD_PADDB:case KG_SIMD_PSUBB:case KG_SIMD_PCMPEQB:bits=8;break;
 case KG_SIMD_PMULLW:bits=16;break;
 case KG_SIMD_PADDD:case KG_SIMD_PSUBD:case KG_SIMD_PMULLD:
 case KG_SIMD_PCMPEQD:case KG_SIMD_PSRLD:case KG_SIMD_PSLLD:case KG_SIMD_PSRAD:bits=32;break;
 case KG_SIMD_PADDQ:case KG_SIMD_PSUBQ:case KG_SIMD_PSRLQ:case KG_SIMD_PSLLQ:bits=64;break;
 default:return out;
 }
 for(i=0;i<128/bits;++i) {
  x=kg_lane(a,bits,i);y=kg_lane(b,bits,i);z=0;
  switch(op) {
  case KG_SIMD_PADDB:case KG_SIMD_PADDD:case KG_SIMD_PADDQ:z=x+y;break;
  case KG_SIMD_PSUBB:case KG_SIMD_PSUBD:case KG_SIMD_PSUBQ:z=x-y;break;
  case KG_SIMD_PMULLW:case KG_SIMD_PMULLD:z=x*y;break;
  case KG_SIMD_PCMPEQB:case KG_SIMD_PCMPEQD:z=x==y?kg_lane_mask(bits):0;break;
  case KG_SIMD_PSRLD:case KG_SIMD_PSRLQ:z=imm>=bits?0:x>>imm;break;
  case KG_SIMD_PSLLD:case KG_SIMD_PSLLQ:z=imm>=bits?0:x<<imm;break;
  case KG_SIMD_PSRAD:
   z=imm>=bits?0:x>>imm;
   if(x&UINT64_C(0x80000000))z|=imm>=bits?UINT64_C(0xffffffff):(UINT64_C(0xffffffff)^(UINT64_C(0xffffffff)>>imm));
   break;
  default:break;
  }
  kg_lane_put(&out,bits,i,z);
 }
 return out;
}
#endif
