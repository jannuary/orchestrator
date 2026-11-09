#ifndef WRAPPER_KEYGEN_EXPERIMENTAL_COMPARE_SELECT_H
#define WRAPPER_KEYGEN_EXPERIMENTAL_COMPARE_SELECT_H
#include <stdint.h>
#include <stddef.h>
/* All functions return -1 on unsupported inputs or null output, without writing.
 * Only the recovered 16 mode/selector pairs and dispatch 3 are supported.
 * Body tokens are decoded u32(packet+8)+u32(address-derived mask):
 * 0xf24 / 0x1023: mode 0 b==a, mode 1 unsigned b>a;
 * 0xfa4: mode 0 b!=a, mode 1 unsigned b>=a;
 * 0x10a1: mode 0 unsigned b<a, mode 1 signed two's-complement b<a.
 * Results are finite control indices, not boolean values. */
int wrapper_kg_compare_select(uint64_t a, uint64_t b, unsigned mode,
                              uint32_t selector, uint32_t body,
                              uint32_t dispatch, uint32_t *output);
/* The original packet address is explicit so offline emulated addresses need
 * not coincide with the host buffer address. Reads 48 little-endian bytes;
 * ignores trailing bytes; writes only *output on success. */
int wrapper_kg_compare_packet(uint64_t address, const void *packet,
                              size_t size, uint32_t *output);
/* Compatibility entry point for the previously verified less-than subset. */
int wrapper_kg_compare_less(uint64_t a, uint64_t b, unsigned mode,
                            uint32_t selector, uint32_t *output);
#endif
