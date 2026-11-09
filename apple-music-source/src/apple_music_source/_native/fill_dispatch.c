#include "fill_dispatch.h"

/* libandroidappmusic, source routine 0x42ced0..0x42cffb.
 *
 * This is a Duff-style byte fill: align the destination, write eight-byte
 * words in groups of eight, then write trailing bytes. Each branch selects
 * how many stores remain. The seven prefix stores and eight bulk stores
 * occupy seven source-layout bytes each; the last byte store occupies three.
 * These formulas enumerate recovered control destinations, not instruction
 * words, integrity substitutions, oracle results, or a compressed image.
 *
 * Prefix index = prefix length - 1 (0..6), bulk index = word count % 8,
 * suffix index = suffix length (0..7). Signed relative destinations are
 * serialized as LE32 because the existing source runner reads that model.
 * See scripts/verify_fill_dispatch.py for offline ELF and execution checks.
 */
static uint32_t destination_word(uint64_t address) {
    uint64_t base, target;
    unsigned index;
    if (address < UINT64_C(0x525a1c)) {
        base = UINT64_C(0x525a00);
        index = (unsigned)((address - base) / 4);
        target = UINT64_C(0x42cf27) - 7 * index;
    } else if (address < UINT64_C(0x525a3c)) {
        base = UINT64_C(0x525a1c);
        index = (unsigned)((address - base) / 4);
        target = index ? UINT64_C(0x42cfb3) - 7 * index
                       : UINT64_C(0x42cf7b);
    } else {
        base = UINT64_C(0x525a3c);
        index = (unsigned)((address - base) / 4);
        target = index ? UINT64_C(0x42cffd) - 7 * index
                       : UINT64_C(0x42cff9);
    }
    return (uint32_t)(target - base);
}

int ams_fill_dispatch_read(uint64_t address, unsigned width, uint64_t *output) {
    uint64_t result = 0;
    unsigned i;
    if (!output || !width || width > 8 || address < UINT64_C(0x525a00) ||
        address >= UINT64_C(0x525a5c) ||
        width > UINT64_C(0x525a5c) - address) return 0;
    for (i = 0; i < width; ++i) {
        uint64_t at = address + i;
        uint32_t word = destination_word(at);
        result |= (uint64_t)((word >> (8 * (unsigned)(at & 3))) & 255) << (8 * i);
    }
    *output = result;
    return 1;
}
