#include <stdint.h>
#include "integrity_generated/bounds.inc"
uint32_t wrapper_kg_integrity_fold(uint64_t base,uint32_t input,int *ok) {
 uint64_t first=UINT64_C(0x100dc000),last=UINT64_C(0x10664000),index;
 if(base<first || base>last || ((base-first)&4095)){*ok=0;return 0;}
 index=(base-first)>>12;*ok=1;
 return kg_integrity_groups[index/16]((unsigned)(index%16),input);
}
