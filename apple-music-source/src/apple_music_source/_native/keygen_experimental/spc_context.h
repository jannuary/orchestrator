#ifndef WRAPPER_KG_SPC_CONTEXT_H
#define WRAPPER_KG_SPC_CONTEXT_H
#include "spc_payload.h"
/* Final context-preparation sequences for payload paths A..E (IDs 0..4).
 * Earlier key/input preparation remains a caller prerequisite. These are
 * bounded substages, not complete constructors. Region/fault semantics match
 * payload_run. Each call restarts at its fixed entry.
 */
int wrapper_kg_spc_context_run(unsigned path,uint64_t module_bias,
    wrapper_kg_payload_state *state,const wrapper_kg_payload_region *regions,
    size_t count,size_t max_steps);
/* Compatibility entry point for path A.
 * [CoreLSKD 0x36490e,0x36b6db), before the original dispatch jump.
 * Earlier key/input preparation remains a caller prerequisite. This is not
 * a complete context constructor. Region/fault semantics match payload_run.
 */
int wrapper_kg_spc_context_prepare(uint64_t module_bias,
    wrapper_kg_payload_state *state,const wrapper_kg_payload_region *regions,
    size_t count,size_t max_steps);
#endif
