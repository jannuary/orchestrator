#include "spc_machine.h"
#include "spc_context.h"
#include "spc_initial.h"
#include "spc_intervening.h"
#include "spc_continuation.h"
#include "spc_graph.h"
#include "spc_graph_bounds.inc"
size_t wrapper_kg_spc_graph_count(void) {
    return sizeof graph_bounds/sizeof graph_bounds[0];
}
int wrapper_kg_spc_graph_run(uint64_t bias,wrapper_kg_payload_state *s,
    const wrapper_kg_payload_region *regions,size_t count,size_t max_steps,
    const wrapper_kg_payload_imports *bindings) {
    size_t total=0;
    if(!s || bias>UINT64_MAX-UINT64_C(0x692c08) || !valid(regions,count))return WRAPPER_KG_PAYLOAD_INVALID;
    s->steps=0;s->fault_address=0;s->fault_size=0;
    for(;;) {
        size_t lo=0,hi=sizeof graph_bounds/sizeof graph_bounds[0];
        const struct graph_bound *node;
        uint64_t off;
        int result;
        if(s->pc<bias){s->steps=total;return WRAPPER_KG_GRAPH_YIELD;}
        off=s->pc-bias;
        while(lo<hi){size_t mid=lo+(hi-lo)/2;if(graph_bounds[mid].entry<off)lo=mid+1;else hi=mid;}
        if(lo==sizeof graph_bounds/sizeof graph_bounds[0] || graph_bounds[lo].entry!=off){s->steps=total;return WRAPPER_KG_GRAPH_YIELD;}
        node=graph_bounds+lo;
        if(node->steps>max_steps-total){s->steps=total;return WRAPPER_KG_PAYLOAD_LIMIT;}
        switch(node->family) {
        case 0:result=wrapper_kg_spc_payload_run(node->index,bias,s,regions,count,node->steps);break;
        case 1:result=wrapper_kg_spc_context_run(node->index,bias,s,regions,count,node->steps);break;
        case 2:result=wrapper_kg_spc_initial_run(node->index,bias,s,regions,count,node->steps);break;
        case 3:result=wrapper_kg_spc_intervening_run_imported(node->index,bias,s,regions,count,node->steps,bindings);break;
        default:
            result=wrapper_kg_spc_continuation_run_imported(node->index,bias,s,regions,count,node->steps,bindings);
            if(result==WRAPPER_KG_PAYLOAD_OK)result=wrapper_kg_spc_continuation_transfer(node->index,bias,s,regions,count);
            break;
        }
        total+=s->steps;
        if(result!=WRAPPER_KG_PAYLOAD_OK){s->steps=total;return result;}
    }
}
