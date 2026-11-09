#ifndef WRAPPER_KG_SPC_GRAPH_H
#define WRAPPER_KG_SPC_GRAPH_H
#include "spc_payload.h"
/* The source graph stops at an uncovered guest PC with YIELD. It neither loads
 * executable data nor invokes guest addresses as host pointers. Caller-owned
 * stack/heap state and explicit standard import tokens remain inputs. */
enum { WRAPPER_KG_GRAPH_YIELD=6 };
size_t wrapper_kg_spc_graph_count(void);
int wrapper_kg_spc_graph_run(uint64_t module_bias,wrapper_kg_payload_state *state,
    const wrapper_kg_payload_region *regions,size_t count,size_t max_steps,
    const wrapper_kg_payload_imports *bindings);
/* Steps count all executed source instructions in this invocation. A budget
 * limit stops before a whole graph node, so that node can be retried. Other
 * instruction faults retain the bounded runner's partial-execution semantics. */
#endif
