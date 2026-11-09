#include "corelskd_r1.h"
#include <string.h>

static int valid_regions(const corelskd_r1_region *regions, size_t count) {
    size_t i, j;
    if (!regions || !count || count > 1024) return 0;
    for (i = 0; i < count; ++i) {
        const corelskd_r1_region *r = regions + i;
        if (!r->data || !r->size || r->size > UINT64_MAX - r->address ||
            !r->permissions || (r->permissions & ~3u)) return 0;
        for (j = 0; j < i; ++j)
            if (r->address < regions[j].address + regions[j].size &&
                regions[j].address < r->address + r->size) return 0;
    }
    return 1;
}

static uint8_t *translate(const corelskd_r1_region *regions, size_t count,
                          uint64_t address, unsigned width, unsigned access) {
    size_t i;
    for (i = 0; i < count; ++i) {
        const corelskd_r1_region *r = regions + i;
        if (address >= r->address && width <= r->size &&
            address - r->address <= r->size - width &&
            (r->permissions & access))
            return r->data + (size_t)(address - r->address);
    }
    return NULL;
}

static int read_value(const corelskd_r1_region *regions, size_t count,
                      uint64_t address, unsigned width, uint64_t *value) {
    unsigned j;
    const uint8_t *p = translate(regions, count, address, width, CORELSKD_R1_READ);
    if (!p) return 0;
    *value = 0;
    for (j = 0; j < width; ++j) *value |= (uint64_t)p[j] << (8 * j);
    return 1;
}

static int write_value(const corelskd_r1_region *regions, size_t count,
                       uint64_t address, unsigned width, uint64_t value) {
    unsigned j;
    uint8_t *p = translate(regions, count, address, width, CORELSKD_R1_WRITE);
    if (!p) return 0;
    for (j = 0; j < width; ++j) p[j] = (uint8_t)(value >> (8 * j));
    return 1;
}

static int run(corelskd_r1_state *s,
                    const corelskd_r1_region *regions, size_t count,
                    size_t max_steps, uint64_t stop) {
    uint64_t a = 0, b = 0;
    int zf = 0;
    if (!s || !valid_regions(regions, count)) return CORELSKD_R1_INVALID;
    s->steps = 0;
    s->fault_address = 0;
    s->fault_size = 0;
#define STEP(address) do { s->pc = UINT64_C(address); \
    if (s->pc == stop) return CORELSKD_R1_OK; \
    if (s->steps == max_steps) return CORELSKD_R1_STEP_LIMIT; } while (0)
#define READ(dst, address, width) do { uint64_t addr_ = (address); \
    if (!read_value(regions, count, addr_, width, &(dst))) { \
        s->fault_address = addr_; s->fault_size = width; \
        return CORELSKD_R1_READ_FAULT; } } while (0)
#define WRITE(address, width, value) do { uint64_t addr_ = (address); \
    if (!write_value(regions, count, addr_, width, value)) { \
        s->fault_address = addr_; s->fault_size = width; \
        return CORELSKD_R1_WRITE_FAULT; } } while (0)
#include "corelskd_r1_generated.inc"
#undef STEP
#undef READ
#undef WRITE
    (void)a; (void)b;
    s->pc = UINT64_C(0x1d94da);
    return CORELSKD_R1_OK;
}

int corelskd_r1_run(corelskd_r1_state *s,
                    const corelskd_r1_region *regions, size_t count,
                    size_t max_steps) {
    return run(s, regions, count, max_steps, UINT64_C(0x1d94da));
}

int corelskd_r1_transform(corelskd_r1_state *s,
                        const corelskd_r1_region *regions, size_t count,
                        size_t max_steps) {
    return run(s, regions, count, max_steps, UINT64_C(0x1d93d5));
}

static void put64(uint8_t *p, uint64_t value) {
    unsigned i;
    for (i = 0; i < 8; ++i) p[i] = (uint8_t)(value >> (8 * i));
}

int corelskd_r1_block(const uint8_t ctx[0x8000], const uint8_t *state,
                     size_t state_size, uint64_t rax, uint64_t rcx,
                     const uint8_t input[16], uint8_t output[16]) {
    uint8_t stack[0x2100], in[16], out[16] = {0};
    corelskd_r1_state s;
    /* Virtual addresses have no relationship to host buffer addresses. */
    corelskd_r1_region regions[4];
    int result;
    if (!ctx || !state || state_size < sizeof(stack) || !input || !output ||
        rcx > 255 || rax > 255) return CORELSKD_R1_INVALID;
    memcpy(stack, state, sizeof(stack));
    memcpy(in, input, sizeof(in));
    put64(stack + 0x1fc0, UINT64_C(0x100000));
    put64(stack + 0x1888, UINT64_C(0x300000));
    put64(stack + 0x1898, UINT64_C(0x400000));
    put64(stack + 0x1de0, 8);
    memset(&s, 0, sizeof(s));
    s.gpr[CORELSKD_RAX] = rax;
    s.gpr[CORELSKD_RCX] = rcx;
    s.gpr[CORELSKD_R9] = UINT64_C(0x100000);
    s.gpr[CORELSKD_RBP] = UINT64_C(0x202000);
    s.gpr[CORELSKD_RDI] = UINT64_C(0x1eb2c6b4);
    s.gpr[CORELSKD_RSI] = 8;
    regions[0] = (corelskd_r1_region){UINT64_C(0x100000), 0x8000,
                                   (uint8_t *)ctx, CORELSKD_R1_READ};
    regions[1] = (corelskd_r1_region){UINT64_C(0x200000), sizeof(stack), stack, 3};
    regions[2] = (corelskd_r1_region){UINT64_C(0x300000), sizeof(in), in, CORELSKD_R1_READ};
    regions[3] = (corelskd_r1_region){UINT64_C(0x400000), sizeof(out), out, CORELSKD_R1_WRITE};
    result = corelskd_r1_transform(&s, regions, 4, CORELSKD_R1_INSTRUCTIONS);
    if (result == CORELSKD_R1_OK) memcpy(output, out, sizeof(out));
    return result;
}

int corelskd_r1_cbc(const uint8_t ctx[0x8000], const uint8_t *state,
                   size_t state_size, uint64_t rax, uint64_t rcx,
                   const uint8_t iv[16], const uint8_t *input,
                   uint8_t *output, size_t size) {
    /* Offsets from RBP, ordered by ciphertext byte. The original block tail
       saves encoded ciphertext here for the next block's chaining operation. */
    static const unsigned chain[16] = {
        0x178, 0x190, 0x118, 0x3e0, 0x160, 0x188, 0xe0, 0x120,
        0x100, 0xd0, 0xf8, 0x108, 0xf0, 0xe8, 0x410, 0xc0
    };
    uint8_t scratch[0x2100], previous[16], cipher[16], block[16];
    size_t offset;
    unsigned j;
    int result;
    if (!ctx || !state || state_size < sizeof(scratch) || size % 16 ||
        (size && (!input || !output)) || rax > 255 || rcx > 255)
        return CORELSKD_R1_INVALID;
    memcpy(scratch, state, sizeof(scratch));
    if (iv) memcpy(previous, iv, sizeof(previous));
    for (offset = 0; offset < size; offset += 16) {
        memcpy(cipher, input + offset, sizeof(cipher));
        if (iv || offset) {
            for (j = 0; j < 16; ++j)
                scratch[0x2000 - chain[j]] = ctx[0x4180 + previous[j]] ^ ctx[0x38ed];
        }
        result = corelskd_r1_block(ctx, scratch, sizeof(scratch), rax, rcx, cipher, block);
        if (result != CORELSKD_R1_OK) return result;
        memcpy(output + offset, block, sizeof(block));
        memcpy(previous, cipher, sizeof(previous));
    }
    return CORELSKD_R1_OK;
}

static uint8_t gf_multiply(uint8_t a, uint8_t b) {
    unsigned i;
    uint8_t result = 0;
    for (i = 0; i < 8; ++i) {
        if (b & 1) result ^= a;
        a = (uint8_t)((a << 1) ^ ((a & 0x80) ? 0x1b : 0));
        b >>= 1;
    }
    return result;
}

static void aes_sbox(uint8_t box[256]) {
    unsigned i, j;
    for (i = 0; i < 256; ++i) {
        uint8_t inverse = 1, power = (uint8_t)i, transformed;
        unsigned exponent = 254;
        /* Inversion in GF(2^8), followed by the standard AES affine map. */
        while (exponent) {
            if (exponent & 1) inverse = gf_multiply(inverse, power);
            power = gf_multiply(power, power);
            exponent >>= 1;
        }
        transformed = inverse;
        for (j = 1; j <= 4; ++j)
            transformed ^= (uint8_t)((inverse << j) | (inverse >> (8 - j)));
        box[i] = transformed ^ 0x63;
    }
}

static int is_affine(const uint8_t values[256]) {
    uint8_t basis[8];
    unsigned i, bit;
    for (bit = 0; bit < 8; ++bit) basis[bit] = values[1u << bit] ^ values[0];
    for (i = 0; i < 256; ++i) {
        uint8_t expected = values[0];
        for (bit = 0; bit < 8; ++bit) if (i & (1u << bit)) expected ^= basis[bit];
        if (values[i] != expected) return 0;
    }
    return 1;
}

int corelskd_r1_extract_key(const uint8_t ctx[0x8000], const uint8_t *state,
                           size_t state_size, uint64_t rax, uint64_t rcx,
                           uint8_t key[16]) {
    /* These four final-round tables each have one varying output byte. */
    static const unsigned tables[4] = {0x3410, 0x3d70, 0x4290, 0x4ef0};
    static const unsigned active_byte[4] = {3, 2, 0, 1};
    uint8_t scratch[0x8000], sbox[256], values[256], normalize[4];
    uint8_t input[16] = {0}, zero_iv[16] = {0}, baseline[16], changed[16], recovered[16] = {0};
    unsigned table, candidate, i, j, found = 0;
    int result;
    if (!ctx || !state || state_size < 0x2100 || !key || rax > 255 || rcx > 255)
        return CORELSKD_R1_INVALID;
    aes_sbox(sbox);
    for (table = 0; table < 4; ++table) {
        unsigned matches = 0;
        for (candidate = 0; candidate < 256; ++candidate) {
            for (i = 0; i < 256; ++i) {
                uint8_t encoded = ctx[tables[table] + 4 * i + active_byte[table]];
                uint8_t decoded = ctx[0x5300 + encoded] ^ 0x76;
                values[i] = sbox[decoded ^ candidate];
            }
            if (is_affine(values)) { normalize[table] = (uint8_t)candidate; ++matches; }
        }
        if (matches != 1) return CORELSKD_R1_INVALID;
    }
    result = corelskd_r1_cbc(ctx, state, state_size, rax, rcx, zero_iv, input, baseline, 16);
    if (result) return result;
    memcpy(scratch, ctx, sizeof(scratch));
    /* Fault only the source's private data copy. A varying final-table entry
       influences precisely the plaintext positions which use that entry.
       This identifies the key whitening bytes without decoding hidden pointers. */
    for (table = 0; table < 4; ++table) {
        for (i = 0; i < 256; ++i) {
            unsigned offset = tables[table] + 4 * i + active_byte[table];
            uint8_t decoded = ctx[0x5300 + ctx[offset]] ^ 0x76;
            scratch[offset] ^= 1;
            result = corelskd_r1_cbc(scratch, state, state_size, rax, rcx, zero_iv, input, changed, 16);
            scratch[offset] ^= 1;
            if (result) return result;
            for (j = 0; j < 16; ++j) {
                if (baseline[j] != changed[j]) {
                    uint8_t value = baseline[j] ^ decoded ^ normalize[table];
                    if ((found & (1u << j)) && recovered[j] != value) return CORELSKD_R1_INVALID;
                    recovered[j] = value;
                    found |= 1u << j;
                }
            }
        }
    }
    if (found != 0xffff) return CORELSKD_R1_INVALID;
    memcpy(key, recovered, sizeof(recovered));
    return CORELSKD_R1_OK;
}
