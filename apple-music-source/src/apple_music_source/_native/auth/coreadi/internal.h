#ifndef WRAPPER_AUTH_COREADI_INTERNAL_H
#define WRAPPER_AUTH_COREADI_INTERNAL_H
#define WRAPPER_KG_NO_CONSTANTS
#include "../../keygen_experimental/spc_machine.h"
#include "../../keygen_experimental/spc_native.h"
#include "simd.h"
static inline void adi_signed_multiply(wrapper_kg_payload_state *s,uint64_t b,unsigned bits){
 uint64_t m=mask(bits),sign=UINT64_C(1)<<(bits-1),a=s->gpr[0]&m,hi,lo;int overflow;
 b&=m;multiply(s,b,bits);lo=s->gpr[0]&m;hi=(bits==8?s->gpr[0]>>8:s->gpr[3])&m;
 hi=(hi-((a&sign)?b:0)-((b&sign)?a:0))&m;
 if(bits==8)s->gpr[0]=(s->gpr[0]&~UINT64_C(65535))|lo|(hi<<8);else s->gpr[3]=hi;
 overflow=hi!=((lo&sign)?m:0);s->flags=(s->flags&~(CF|OF))|(overflow?(CF|OF):0);
}
int adi_native_read(const wrapper_kg_payload_region *,size_t,uint64_t,unsigned,uint64_t *);
#define NATIVE_LOCALS wrapper_kg_payload_state *s=&fs->cpu;uint64_t a=0,b=0,c=0,x=0,y=0,z=0,next_pc=0;kg_vec v0={0,0},v1={0,0};s->steps=0
#define STEP(off) do {s->pc=bias+UINT64_C(off);if(s->steps==max_steps)return WRAPPER_KG_PAYLOAD_LIMIT;}while(0)
#define READ(dst,address,width) do {uint64_t addr_=(address);if(!adi_native_read(regions,count,addr_,width,&(dst))){s->fault_address=addr_;s->fault_size=width;return WRAPPER_KG_PAYLOAD_READ_FAULT;}}while(0)
#define WRITE(address,width,value) do {uint64_t addr_=(address),v_=(value);unsigned j_;unsigned char *p_=translate(regions,count,addr_,width,2);if(!p_){s->fault_address=addr_;s->fault_size=width;return WRAPPER_KG_PAYLOAD_WRITE_FAULT;}for(j_=0;j_<width;++j_)p_[j_]=(unsigned char)(v_>>(j_*8));}while(0)
#define NATIVE_DONE (void)a;(void)b;(void)c;(void)x;(void)y;(void)z;(void)v0;(void)v1;s->pc=next_pc;return WRAPPER_KG_PAYLOAD_OK
#endif
