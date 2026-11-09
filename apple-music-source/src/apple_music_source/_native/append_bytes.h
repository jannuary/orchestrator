#ifndef WRAPPER_KG_APPEND_BYTES_H
#define WRAPPER_KG_APPEND_BYTES_H
#include <stddef.h>
#include <stdint.h>
/* CoreLSKD 0x1a4b40 body 0x1389, dispatch 10, for stable source descriptors.
 * Object: little-endian encoded length followed by 300 payload bytes.
 * Count: source descriptor's encoded count (0x2167c5a6 + count).
 * Returns 0, original capacity error -42678, or -1 for unsupported/bad buffers.
 * Failures leave the object unchanged. Caller owns all buffers; no guest or
 * captured host pointer is dereferenced. Aliasing payload/data uses forward
 * byte-by-byte semantics. Count and data pointer must stay stable in the call.
 */
int wrapper_kg_append_bytes(void *object, size_t object_size,
                            uint32_t encoded_count,
                            const void *data, size_t data_size);
#endif
