#include "append_bytes.h"

static uint32_t le32(const unsigned char *p)
{
    return (uint32_t)p[0] | (uint32_t)p[1] << 8 |
           (uint32_t)p[2] << 16 | (uint32_t)p[3] << 24;
}
static void put32(unsigned char *p, uint32_t value)
{
    p[0] = (unsigned char)value;
    p[1] = (unsigned char)(value >> 8);
    p[2] = (unsigned char)(value >> 16);
    p[3] = (unsigned char)(value >> 24);
}
int wrapper_kg_append_bytes(void *object, size_t object_size,
                            uint32_t encoded_count,
                            const void *data, size_t data_size)
{
    unsigned char *out = object;
    const unsigned char *in = data;
    uint32_t length, count, i;
    if (!out || object_size < 304) return -1;
    length = le32(out) - UINT32_C(0x7b5ad73e);
    count = encoded_count - UINT32_C(0x2167c5a6);
    /* Do not admit wrapped or negative logical lengths. These malformed cases
     * are outside the recovered bounded interface. */
    if (length > 299 || count > 299) return -1;
    if (length + count > 299) return -42678;
    if (data_size < count || (count && !in)) return -1;
    for (i = 0; i < count; ++i)
        out[4 + length + i] = (unsigned char)(in[i] + 0x7d);
    out[4 + length + count] = 0x7d;
    put32(out, UINT32_C(0x7b5ad73e) + length + count);
    return 0;
}
