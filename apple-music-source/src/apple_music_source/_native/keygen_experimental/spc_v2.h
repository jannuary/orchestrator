#ifndef WRAPPER_KG_SPC_V2_H
#define WRAPPER_KG_SPC_V2_H
#include <stddef.h>
#include <stdint.h>
/* Bounded envelope for the observed SPC v2 route. Fields remain opaque until
 * their cryptographic derivation is recovered. Pointers borrow caller memory. */
struct wrapper_kg_spc_v2_view {
    const unsigned char *field16;
    const unsigned char *field256;
    const unsigned char *field20;
    const unsigned char *payload;
    size_t payload_size;
};
/* Strict v2/zero-reserved/exact-length/aligned nonempty payload view.
 * On failure, leave view unchanged. */
int wrapper_kg_spc_v2_parse(const void *packet, size_t size,
                           struct wrapper_kg_spc_v2_view *view);
/* Caller provides field arrays of the named lengths and a bounded payload.
 * Supports output/input overlap. On failure output and written are unchanged.
 * This assembles an envelope; it performs no cryptography or authentication. */
int wrapper_kg_spc_v2_pack(void *output, size_t capacity,
                          const struct wrapper_kg_spc_v2_view *view,
                          size_t *written);
#endif
