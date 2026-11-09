#ifndef AMS_FILL_DISPATCH_H
#define AMS_FILL_DISPATCH_H
#include <stdint.h>

/* Read the recovered byte-fill routine's finite control structure. The guest
 * addresses describe the pinned source layout, not an ELF loader. No caller
 * memory is read. Unknown addresses/widths leave *output unchanged. */
int ams_fill_dispatch_read(uint64_t address, unsigned width, uint64_t *output);
#endif
