#include "mescal_integrity.h"
#include "mescal_integrity_generated.inc"
int mescal_integrity_pair(uint64_t a,uint64_t b,uint8_t *out){
 const uint64_t bias=UINT64_C(0x04000000);uint64_t offset;unsigned wrap;
 if(!out||a<bias+MES_INTEGRITY_START||a>=bias+MES_INTEGRITY_END)return 0;
 if(b==a+2)wrap=0;
 else if(a>=32766 && b==a-32766)wrap=1;
 else return 0;
 offset=a-bias-MES_INTEGRITY_START;
 *out=mes_integrity_tables[offset/65536](wrap,(unsigned)(offset%65536));return 1;
}
