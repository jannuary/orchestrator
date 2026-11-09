#ifndef AMS_COPY_CODECS_H
#define AMS_COPY_CODECS_H
#include <stddef.h>
#include <stdint.h>
/* Arithmetic output-byte stages only. state is the original low control byte,
 * not a key. These do not implement either surrounding cipher/packet routine.
 * Stage 0: Core-relative 0x527a59..0x527aad (incoming EBX, R13D).
 * Stage 1: 0x53172e..0x531759 (incoming R13B, R9D). */
uint8_t ams_copy0_byte(uint32_t index, uint8_t state, uint8_t input);
uint8_t ams_copy1_byte(uint32_t index, uint8_t state, uint8_t input);
/* Stage 0 starts BL at 0xd0, saves/restores it at frame -0x78 and advances it
 * by two; its index starts at zero and advances by one. Stage 1 starts both
 * counters at zero and also advances by two/one. The inverses undo the byte
 * transforms. Copies run forward, preserving alias order.
 * Bounds errors leave output untouched. Empty copies permit null pointers. */
int ams_copy0_forward(void *output, size_t output_size, const void *input,
                      size_t input_size, size_t count);
int ams_copy0_inverse(void *output, size_t output_size, const void *input,
                      size_t input_size, size_t count);
int ams_copy1_forward(void *output, size_t output_size, const void *input,
                      size_t input_size, size_t count);
int ams_copy1_inverse(void *output, size_t output_size, const void *input,
                      size_t input_size, size_t count);
#endif
