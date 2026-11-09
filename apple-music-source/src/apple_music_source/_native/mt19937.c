#include "mt19937.h"

/* The in-place recurrence matters: the second span consumes words updated by
 * the first span. Recovered from CoreLSKD virtual offsets 0x1a47c0..0x1a48dd.
 * These are algorithm parameters, not extracted tables or executable bytes. */
void wrapper_kg_mt19937_twist(uint32_t state[624]) {
    unsigned i;
    for (i = 0; i < 624; ++i) {
        uint32_t joined = (state[i] & UINT32_C(0x80000000)) |
                          (state[(i + 1) % 624] & UINT32_C(0x7fffffff));
        state[i] = state[(i + 397) % 624] ^ (joined >> 1) ^
                   ((joined & 1) ? UINT32_C(0x9908b0df) : 0);
    }
}

/* CoreLSKD virtual offsets 0x1a4948..0x1a4967 and 0x1a4010..0x1a4013. */
uint32_t wrapper_kg_mt19937_temper(uint32_t value) {
    value ^= value >> 11;
    value ^= (value << 7) & UINT32_C(0x9d2c5680);
    value ^= (value << 15) & UINT32_C(0xefc60000);
    return value ^ (value >> 18);
}

/* The bytewise expression x - ((2*x)&0x8e) + 0x47 is x XOR 0x47
 * modulo 256. The original stores successive low bytes in reverse order
 * (virtual offsets 0x1a4047..0x1a405d). This is encoding, not encryption. */
void wrapper_kg_mt19937_encode_word(uint32_t value, uint8_t output[4]) {
    unsigned i;
    for (i = 0; i < 4; ++i)
        output[i] = (uint8_t)(value >> (24 - 8*i)) ^ UINT8_C(0x47);
}
