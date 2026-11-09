#ifndef WRAPPER_KG_FIELD_COPY_H
#define WRAPPER_KG_FIELD_COPY_H
#include <stddef.h>
#include <stdint.h>
/* Five bounded field-copy bodies from CoreLSKD 0x1a4b40. Unknown control
 * inputs and short buffers fail before writing. No host pointers are decoded. */
int wrapper_kg_field_copy(uint32_t dispatch, uint32_t body,
                          void *dst, size_t dst_size,
                          const void *src, size_t src_size);
/* Decode the address-bound packet into integer addresses only. Outputs are
 * unchanged on failure; the caller must resolve addresses into owned memory. */
int wrapper_kg_field_packet(uint64_t address, const void *packet, size_t size,
                            uint32_t *body, uint64_t *dst, uint64_t *src);
#endif
