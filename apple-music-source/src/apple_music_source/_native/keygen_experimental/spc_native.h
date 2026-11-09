#ifndef WRAPPER_KG_SPC_NATIVE_H
#define WRAPPER_KG_SPC_NATIVE_H
#include "spc_payload.h"
#include "spc_simd.h"
enum {WRAPPER_KG_NATIVE_CLOCK=7};
enum {WRAPPER_KG_BYTE_SHADOW_COUNT=256};
typedef struct wrapper_kg_byte_shadow {
    uint64_t first,second,frame,live;
} wrapper_kg_byte_shadow;
typedef struct wrapper_kg_native_state {
    wrapper_kg_payload_state cpu;
    kg_vec xmm[16];
    uint64_t tls_base;
    /* Private CKC normalization: 1 is an intact frame word, 2 a partial
     * overwrite, 3 a deferred R8 code pair, and >=4 a bounded register
     * lifetime; slot stores its allowed inclusive Core offset interval. */
    uint64_t ckc_shadow_slot,ckc_shadow_frame,ckc_shadow_active;
    /* Each live bit marks one byte whose stored value is normalized. */
    wrapper_kg_byte_shadow ckc_byte_shadows[WRAPPER_KG_BYTE_SHADOW_COUNT];
    /* Odd/even cell reads of normalized word pairs during the CKC fold. */
    uint64_t ckc_pair_parity[4];
} wrapper_kg_native_state;
int wrapper_kg_native_run(uint64_t bias,wrapper_kg_native_state *state,
    const wrapper_kg_payload_region *regions,size_t count,size_t max_steps,
    const wrapper_kg_payload_imports *bindings);
#endif
