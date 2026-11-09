#ifndef AMS_INTEGRITY_CODEC_DATA_H
#define AMS_INTEGRITY_CODEC_DATA_H
#include <stdint.h>
/* Pristine SIMD arithmetic data only; CoreLSKD-relative addresses, no bias. */
int ams_integrity_codec_data_read(uint64_t address, unsigned width, uint64_t *out);
#endif
