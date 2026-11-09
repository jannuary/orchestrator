#ifndef AMS_CONTROL_REFS_H
#define AMS_CONTROL_REFS_H
#include <stdint.h>
/* Pristine source-control references at source-runner virtual addresses.
 * Unknown/cross-gap/overflow reads leave output unchanged. This initializes
 * ordinary memory; it must not replace mutable reads or permission checks.
 * This is not a complete image initializer or SPC/auth implementation. */
int ams_control_refs_read(uint64_t address, unsigned width, uint64_t *output);
#endif
