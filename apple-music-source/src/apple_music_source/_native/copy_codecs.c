#include "copy_codecs.h"

uint8_t ams_copy0_byte(uint32_t index, uint8_t state, uint8_t input) {
    uint8_t position = (uint8_t)(index + 6u - (state & 12u));
    uint8_t factor = (uint8_t)(position ^ 6u);
    uint8_t mask = (uint8_t)((uint32_t)factor * 165u -
                            (((uint32_t)factor * 74u) & 44u) + 22u);
    return (uint8_t)(input ^ mask ^ 188u);
}

uint8_t ams_copy1_byte(uint32_t index, uint8_t state, uint8_t input) {
    return (uint8_t)(input + (state & 240u) +
                     ((uint8_t)index ^ 120u) + 116u);
}

static int copy_bytes(void *output, size_t output_size, const void *input,
                      size_t input_size, size_t count, unsigned stage, int inverse) {
    unsigned char *out = output;
    const unsigned char *in = input;
    size_t i;
    if (count > UINT32_MAX || count > output_size || count > input_size ||
        (count && (!out || !in))) return -1;
    for (i = 0; i < count; ++i) {
        /* 0xd0 has no bits in the stage-0 control mask (12). Its saved low
         * byte plus 2*i therefore contributes the same mask as 2*i. */
        uint8_t state = (uint8_t)(2u * i);
        uint8_t offset = stage ? ams_copy1_byte((uint32_t)i, state, 0) :
                                 ams_copy0_byte((uint32_t)i, state, 0);
        uint8_t byte = in[i];
        out[i] = stage ? (uint8_t)(inverse ? byte - offset : byte + offset) :
                         (uint8_t)(byte ^ offset);
    }
    return 0;
}

int ams_copy0_forward(void *output, size_t output_size, const void *input,
                      size_t input_size, size_t count) {
    return copy_bytes(output, output_size, input, input_size, count, 0, 0);
}
int ams_copy0_inverse(void *output, size_t output_size, const void *input,
                      size_t input_size, size_t count) {
    return copy_bytes(output, output_size, input, input_size, count, 0, 1);
}

int ams_copy1_forward(void *output, size_t output_size, const void *input,
                      size_t input_size, size_t count) {
    return copy_bytes(output, output_size, input, input_size, count, 1, 0);
}
int ams_copy1_inverse(void *output, size_t output_size, const void *input,
                      size_t input_size, size_t count) {
    return copy_bytes(output, output_size, input, input_size, count, 1, 1);
}
