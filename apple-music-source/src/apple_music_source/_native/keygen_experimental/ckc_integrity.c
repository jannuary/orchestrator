#include "ckc_integrity.h"
#include "ckc_integrity_generated.inc"
int wrapper_kg_ckc_integrity_pair(uint64_t a,uint64_t b,uint8_t *out){
 const uint64_t bias=UINT64_C(0x10000000);uint64_t offset;unsigned wrap;
 if(!out||a<bias+CKC_INTEGRITY_START||a>=bias+CKC_INTEGRITY_END||
    b<bias+CKC_INTEGRITY_START||b>=bias+CKC_INTEGRITY_END)return 0;
 if(b==a+2)wrap=0;
 else if(b==a-32766)wrap=1;
 else return 0;
 offset=a-bias-CKC_INTEGRITY_START;
 *out=ckc_integrity_tables[offset/65536](wrap,(unsigned)(offset%65536));return 1;
}

int wrapper_kg_ckc_integrity_word(uint64_t a,uint64_t b,unsigned width,uint64_t *out){
 uint64_t value=0;unsigned i;uint8_t byte;
 if(!out||(width!=1&&width!=2&&width!=4&&width!=8)||a>UINT64_MAX-width||b>UINT64_MAX-width)return 0;
 for(i=0;i<width;i++){
  if(!wrapper_kg_ckc_integrity_pair(a+i,b+i,&byte))return 0;
  value|=(uint64_t)byte<<(i*8);
 }
 *out=value;return 1;
}
