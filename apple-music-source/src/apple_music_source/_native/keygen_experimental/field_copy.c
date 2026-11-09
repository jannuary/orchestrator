#include "field_copy.h"
#include <string.h>

static int layout(uint32_t body, size_t *d, size_t *s)
{
    switch (body) {
    case 0xdb8: *d = 0; *s = 0x10; return 0;
    case 0x11c7: *d = 0x18; *s = 4; return 0;
    case 0x1204: *d = 0x28; *s = 4; return 0;
    case 0x1240: *d = 0x38; *s = 4; return 0;
    case 0xdf1: *d = 0x48; *s = 4; return 0;
    default: return -1;
    }
}

int wrapper_kg_field_copy(uint32_t dispatch, uint32_t body,
                          void *dst, size_t dst_size,
                          const void *src, size_t src_size)
{
    size_t d, s;
    unsigned char *out = dst;
    const unsigned char *in = src;
    uint32_t word;
    uint64_t quad;
    if (dispatch != 10 || layout(body, &d, &s) || !dst || !src ||
        dst_size < d + 16 || src_size < (s == 4 ? 16 : 32) ||
        (body == 0xdf1 && dst_size < 0x59)) return -1;
    /* Preserve the original load/store order, including aliases between
     * buffers: the tag precedes both loads; the qword load follows the dword
     * store. Padding bytes at d+4..d+7 are deliberately untouched. */
    if (body == 0xdf1) out[0x58] = 10;
    memcpy(&word, in + s, 4);
    memcpy(out + d, &word, 4);
    memcpy(&quad, in + (s == 4 ? 8 : 24), 8);
    memcpy(out + d + 8, &quad, 8);
    return 0;
}

static uint32_t le32(const unsigned char *p)
{
    return (uint32_t)p[0] | (uint32_t)p[1] << 8 |
           (uint32_t)p[2] << 16 | (uint32_t)p[3] << 24;
}
static uint64_t le64(const unsigned char *p)
{
    return (uint64_t)le32(p) | (uint64_t)le32(p + 4) << 32;
}
int wrapper_kg_field_packet(uint64_t address, const void *packet, size_t size,
                            uint32_t *body, uint64_t *dst, uint64_t *src)
{
    const unsigned char *p = packet;
    uint64_t mask = (address ^ UINT64_C(0xbe2af1b45989a725)) *
                    UINT64_C(0x1f6060df);
    uint32_t token;
    size_t d, s;
    if (!p || size < 32 || !body || !dst || !src) return -1;
    token = le32(p + 4) - (uint32_t)mask;
    if (le32(p + 16) - (uint32_t)mask != 10 || layout(token, &d, &s)) return -1;
    *body = token;
    *dst = le64(p + 8);
    *src = le64(p + 24);
    return 0;
}
