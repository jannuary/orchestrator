#include "spc_v2.h"
#include <string.h>

static uint32_t be32(const unsigned char *p)
{
    return (uint32_t)p[0] << 24 | (uint32_t)p[1] << 16 |
           (uint32_t)p[2] << 8 | (uint32_t)p[3];
}
static int valid_length(size_t n)
{
    return n && n <= UINT32_MAX && n <= SIZE_MAX - 304 && !(n & 15);
}
int wrapper_kg_spc_v2_parse(const void *packet, size_t size,
                           struct wrapper_kg_spc_v2_view *view)
{
    const unsigned char *p = packet;
    struct wrapper_kg_spc_v2_view v;
    uint32_t n;
    if (!p || !view || size < 304 || be32(p) != 2 || be32(p + 4) != 0)
        return -1;
    n = be32(p + 300);
    if (!valid_length(n) || size - 304 != n) return -1;
    v.field16 = p + 8;
    v.field256 = p + 24;
    v.field20 = p + 280;
    v.payload = p + 304;
    v.payload_size = n;
    *view = v;
    return 0;
}
int wrapper_kg_spc_v2_pack(void *output, size_t capacity,
                          const struct wrapper_kg_spc_v2_view *view,
                          size_t *written)
{
    unsigned char header[304] = {0};
    unsigned char *out = output;
    struct wrapper_kg_spc_v2_view v;
    uint32_t n;
    if (!out || !view || !written) return -1;
    v = *view;
    if (!v.field16 || !v.field256 || !v.field20 || !v.payload ||
        !valid_length(v.payload_size) || capacity < 304 + v.payload_size)
        return -1;
    n = (uint32_t)v.payload_size;
    header[3] = 2;
    memcpy(header + 8, v.field16, 16);
    memcpy(header + 24, v.field256, 256);
    memcpy(header + 280, v.field20, 20);
    header[300] = (unsigned char)(n >> 24);
    header[301] = (unsigned char)(n >> 16);
    header[302] = (unsigned char)(n >> 8);
    header[303] = (unsigned char)n;
    /* Snapshot fields before moving payload; write header last to support
     * repacking a parsed packet in place or shifting an overlapping packet. */
    memmove(out + 304, v.payload, v.payload_size);
    memcpy(out, header, sizeof header);
    *written = 304 + v.payload_size;
    return 0;
}
