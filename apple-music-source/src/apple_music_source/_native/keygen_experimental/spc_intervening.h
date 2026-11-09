#ifndef WRAPPER_KG_SPC_INTERVENING_H
#define WRAPPER_KG_SPC_INTERVENING_H
#include "spc_payload.h"
/* Producer fragments identified by the pinned manifest, ordered by entry.
 * Original jump/call instructions are excluded. The caller must provide the
 * incoming state; these are not complete initialization/orchestration.
 * Region, fault and restart semantics match the other bounded runners. */
size_t wrapper_kg_spc_intervening_count(void);
int wrapper_kg_spc_intervening_run_imported(unsigned block,uint64_t module_bias,
    wrapper_kg_payload_state *state,const wrapper_kg_payload_region *regions,
    size_t count,size_t max_steps,const wrapper_kg_payload_imports *bindings);
/* Unbound convenience entry; an import read fails if no binding is provided. */
int wrapper_kg_spc_intervening_run(unsigned block,uint64_t module_bias,
    wrapper_kg_payload_state *state,const wrapper_kg_payload_region *regions,
    size_t count,size_t max_steps);
#endif
