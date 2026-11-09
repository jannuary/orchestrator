#ifndef WRAPPER_AUTH_ADI_SIMD_H
#define WRAPPER_AUTH_ADI_SIMD_H
#include "../../keygen_experimental/spc_simd.h"
enum {ADI_SIMD_BLENDVPD,ADI_SIMD_PCMPGTD,ADI_SIMD_PMINUD,ADI_SIMD_PMOVSXDQ,
 ADI_SIMD_PMOVZXBD,ADI_SIMD_PMOVZXWD,ADI_SIMD_PUNPCKLQDQ,ADI_SIMD_SHUFPS};
static inline kg_vec adi_simd(unsigned op,kg_vec a,kg_vec b,unsigned imm,kg_vec implicit) {
 kg_vec out={0,0};unsigned j;uint64_t x,y,v;
 if(op==ADI_SIMD_PUNPCKLQDQ)return (kg_vec){a.lo,b.lo};
 for(j=0;j<(op==ADI_SIMD_BLENDVPD||op==ADI_SIMD_PMOVSXDQ?2:4);++j){
  unsigned width=(op==ADI_SIMD_BLENDVPD||op==ADI_SIMD_PMOVSXDQ)?64:32;
  x=kg_lane(a,width,j);y=kg_lane(b,width,j);v=0;
  switch(op){
   case ADI_SIMD_BLENDVPD:v=(kg_lane(implicit,64,j)>>63)?y:x;break;
   case ADI_SIMD_PCMPGTD:v=((x^UINT64_C(0x80000000))>(y^UINT64_C(0x80000000)))?UINT64_C(0xffffffff):0;break;
   case ADI_SIMD_PMINUD:v=x<y?x:y;break;
   case ADI_SIMD_PMOVSXDQ:x=kg_lane(b,32,j);v=(x^UINT64_C(0x80000000))-UINT64_C(0x80000000);break;
   case ADI_SIMD_PMOVZXBD:v=kg_lane(b,8,j);break;
   case ADI_SIMD_PMOVZXWD:v=kg_lane(b,16,j);break;
   case ADI_SIMD_SHUFPS:v=kg_lane(j<2?a:b,32,(imm>>(j*2))&3);break;
  }
  kg_lane_put(&out,width,j,v);
 }
 return out;
}
#endif
