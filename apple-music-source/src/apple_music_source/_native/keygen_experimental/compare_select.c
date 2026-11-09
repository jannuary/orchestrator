#include "compare_select.h"
#include <stddef.h>

/* Finite control destinations recovered from the supplied SPC path's selector
 * table, not keys or instructions. Only the 16 observed mode/selector pairs
 * are admitted. The four recovered body tokens and dispatch variant 3 are
 * explicit; all other combinations fail without modifying the output. */
struct selection { uint32_t mode, selector, when_false, when_true; };
static const struct selection selections[] = {
    {0,16,2815,185}, {0,46,726,593}, {0,49,2584,185},
    {0,61,268,215}, {0,78,529,192}, {0,83,2432,206},
    {0,87,24029,186}, {0,88,331,278}, {0,94,1731,261},
    {0,101,186,141}, {0,114,3014,303},
    {1,17,364,UINT32_C(4294963667)},
    {1,52,166,UINT32_C(4294964936)}, {1,72,397,429},
    {1,95,390,431}, {1,103,411,UINT32_C(4294963660)}
};

int wrapper_kg_compare_select(uint64_t a, uint64_t b, unsigned mode,
                              uint32_t selector, uint32_t body,
                              uint32_t dispatch, uint32_t *output) {
    size_t i;
    int condition;
    if (!output || dispatch != 3 || mode > 1) return -1;
    switch (body) {
    case 0x0f24: /* body 0x1a0dad */
    case 0x1023: /* body 0x1a0eac */
        condition = mode ? b > a : b == a;
        break;
    case 0x0fa4: /* body 0x1a0e2d */
        condition = mode ? b >= a : b != a;
        break;
    case 0x10a1: { /* body 0x1a0f2a */
        uint64_t sign = mode ? UINT64_C(0x8000000000000000) : 0;
        condition = (b ^ sign) < (a ^ sign);
        break;
    }
    default:
        return -1;
    }
    for (i = 0; i < sizeof(selections)/sizeof(selections[0]); ++i) {
        const struct selection *s = &selections[i];
        if (s->mode == mode && s->selector == selector) {
            *output = condition ? s->when_true : s->when_false;
            return 0;
        }
    }
    return -1;
}

int wrapper_kg_compare_less(uint64_t a, uint64_t b, unsigned mode,
                            uint32_t selector, uint32_t *output) {
    return wrapper_kg_compare_select(a, b, mode, selector, 0x10a1, 3, output);
}

static uint32_t read32(const uint8_t *p) {
    return (uint32_t)p[0] | (uint32_t)p[1] << 8 |
           (uint32_t)p[2] << 16 | (uint32_t)p[3] << 24;
}

static uint64_t read64(const uint8_t *p) {
    return (uint64_t)read32(p) | (uint64_t)read32(p + 4) << 32;
}

int wrapper_kg_compare_packet(uint64_t address, const void *packet,
                              size_t size, uint32_t *output) {
    const uint8_t *p = packet;
    uint64_t mask;
    if (!p || size < 48 || !output) return -1;
    mask = (address ^ UINT64_C(0xbe2af1b45989a725)) * UINT64_C(0x1f6060df);
    return wrapper_kg_compare_select(read64(p) + mask, read64(p + 24) + mask,
        read32(p + 32) - (uint32_t)mask,
        read32(p + 36) - (uint32_t)mask,
        read32(p + 8) + (uint32_t)mask,
        read32(p + 44) - (uint32_t)mask, output);
}
