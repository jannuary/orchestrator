#ifndef WRAPPER_KG_SPC_INITIAL_H
#define WRAPPER_KG_SPC_INITIAL_H
#include "spc_payload.h"
/* Earlier state-initialization sequences A..E (IDs0..4), not complete context
 * constructors. Incoming arguments/key material and earlier work remain caller
 * prerequisites. Bounds/flags/fault semantics match the other bounded runners.
 * Division errors return ARITH_FAULT before committing the DIV instruction.
 */
int wrapper_kg_spc_initial_run(unsigned path,uint64_t module_bias,
    wrapper_kg_payload_state *state,const wrapper_kg_payload_region *regions,
    size_t count,size_t max_steps);
#endif
