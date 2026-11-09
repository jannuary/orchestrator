#ifndef WRAPPER_KG_CKC_PACKET_H
#define WRAPPER_KG_CKC_PACKET_H
#include <stddef.h>
#include <stdint.h>

/* Internal CoreLSKD RPC boundary. Addresses are guest addresses, never host
 * pointers. These helpers serialize arguments; they do not decrypt a CKC. */
#define WRAPPER_KG_CKC_PACKET_SIZE 192
#define WRAPPER_KG_CKC_PERSISTENT_TOKEN UINT32_C(0x13c604d2)
#define WRAPPER_KG_CKC_CONTEXT_TOKEN UINT32_C(0xc84dc4a3)
#define WRAPPER_KG_CONTEXT_FINALIZE_TOKEN UINT32_C(0x68df9ab6)
#define WRAPPER_KG_CONTEXT_DECRYPT_TOKEN UINT32_C(0xdf65877e)

int wrapper_kg_ckc_persistent_packet(unsigned char *output, size_t capacity,
    uint64_t exchange, uint64_t ckc, uint32_t ckc_size,
    uint64_t persistent_output, uint64_t size_output);
int wrapper_kg_ckc_context_packet(unsigned char *output, size_t capacity,
    uint64_t exchange, uint64_t ckc, uint32_t ckc_size,
    uint64_t context_output);
int wrapper_kg_context_finalize_packet(unsigned char *output, size_t capacity,
    uint64_t context);
int wrapper_kg_context_decrypt_packet(unsigned char *output, size_t capacity,
    uint64_t context, uint32_t mode, uint64_t input, uint64_t decrypted_output,
    uint32_t size);
/* Decode the backend's one-element result vector. Failure leaves status alone. */
int wrapper_kg_ckc_packet_status(const unsigned char *packet, size_t size,
    uint32_t *status);
#endif
