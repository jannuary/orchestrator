#ifndef WRAPPER_KG_SPC_CONTINUATION_H
#define WRAPPER_KG_SPC_CONTINUATION_H
#include "spc_payload.h"
/* Arithmetic tails following the recovered intervals, ordered by entry.
 * run stops before the transfer. transfer then performs the register jump or
 * virtual call, including the checked return-address stack write. No host call
 * occurs. The caller still supplies incoming state and dispatches the next PC.
 * Region, fault and restart semantics match the other bounded runners. */
size_t wrapper_kg_spc_continuation_count(void);
int wrapper_kg_spc_continuation_run_imported(unsigned block,uint64_t module_bias,
    wrapper_kg_payload_state *state,const wrapper_kg_payload_region *regions,
    size_t count,size_t max_steps,const wrapper_kg_payload_imports *bindings);
/* Unbound convenience entry; an import read fails if no binding is provided. */
int wrapper_kg_spc_continuation_run(unsigned block,uint64_t module_bias,
    wrapper_kg_payload_state *state,const wrapper_kg_payload_region *regions,
    size_t count,size_t max_steps);
/* Apply exactly one transfer at the matching run endpoint. Target addresses
 * remain integer guest addresses; no host pointer is invoked. On a failed call
 * stack write, GPRs, PC, steps and caller memory remain unchanged. */
int wrapper_kg_spc_continuation_transfer(unsigned block,uint64_t module_bias,
    wrapper_kg_payload_state *state,const wrapper_kg_payload_region *regions,size_t count);
#endif
