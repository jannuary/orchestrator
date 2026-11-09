#ifndef WRAPPER_MESCAL_INTEGRITY_H
#define WRAPPER_MESCAL_INTEGRITY_H
#include <stdint.h>
/* Guest addresses use the source backend's fixed CoreFP base 0x04000000.
 * Returns zero for an unsupported pair, without writing output. */
int mescal_integrity_pair(uint64_t a, uint64_t b, uint8_t *out);
#endif
