#include <stdint.h>
int wrapper_kg_native_lookup(uint64_t address,unsigned width,uint64_t *value) {
 (void)address;(void)width;(void)value;
 /* Original instruction data is never supplied by the source runtime. */
 return 0;
}
