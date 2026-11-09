#include "spc_native_internal.h"
#include "spc_graph.h"
#include "native_generated/bounds.inc"
#include "app_generated/bounds.inc"
int wrapper_kg_native_read(const wrapper_kg_payload_region *regions,size_t count,
    uint64_t address,unsigned width,uint64_t *value) {
    const unsigned char *p=translate(regions,count,address,width,1);
    uint64_t v=0;
    unsigned j;
    if(!p)return wrapper_kg_native_lookup(address,width,value);
    if(!width || width>8)return 0;
    for(j=0;j<width;++j)v|=(uint64_t)p[j]<<(j*8);
    *value=v;return 1;
}
int wrapper_kg_native_run(uint64_t bias,wrapper_kg_native_state *fs,
    const wrapper_kg_payload_region *regions,size_t count,size_t max_steps,
    const wrapper_kg_payload_imports *bindings) {
    wrapper_kg_payload_state *s;
    size_t total=0;
    if(!fs || bias>UINT64_MAX-UINT64_C(0x700000) || !valid(regions,count))return WRAPPER_KG_PAYLOAD_INVALID;
    s=&fs->cpu;s->steps=0;s->fault_address=0;s->fault_size=0;
    for(;;) {
        size_t lo=0,hi=sizeof native_bounds/sizeof native_bounds[0];
        uint64_t before=s->pc,off=s->pc-bias;
        int result;
        if(s->pc>=bias)while(lo<hi){size_t mid=lo+(hi-lo)/2;if(native_bounds[mid].entry<=off)lo=mid+1;else hi=mid;}
        else lo=hi;
        if(lo>0 && s->pc>=bias && off<native_bounds[lo-1].end) {
            --lo;
            const struct native_bound *node=native_bounds+lo;
            result=native_groups[node->group](node->index,bias,fs,regions,count,max_steps-total);
        } else {
            lo=0;hi=sizeof app_bounds/sizeof app_bounds[0];
            while(lo<hi){size_t mid=lo+(hi-lo)/2;if(app_bounds[mid].entry<s->pc)lo=mid+1;else hi=mid;}
            if(lo<sizeof app_bounds/sizeof app_bounds[0] && app_bounds[lo].entry==s->pc) {
                const struct app_bound *node=app_bounds+lo;
                result=app_groups[node->group](node->index,0,fs,regions,count,max_steps-total);
            } else if(kg_shadow_any(fs)) {
                /* The older graph runner has no guarded frame reads. Imports
                 * yield without reading guest memory; all other paths stop. */
                s->steps=0;
                if(s->pc>=UINT64_C(0x800000) && s->pc<UINT64_C(0xa00000))result=WRAPPER_KG_GRAPH_YIELD;
                else {s->fault_address=kg_shadow_fault_address(fs);s->fault_size=fs->ckc_shadow_active?4:1;result=WRAPPER_KG_PAYLOAD_READ_FAULT;}
            } else result=wrapper_kg_spc_graph_run(bias,s,regions,count,max_steps-total,bindings);
        }
        total+=s->steps;
        if(result==WRAPPER_KG_GRAPH_YIELD && s->pc!=before)continue;
        if(result==WRAPPER_KG_PAYLOAD_OK)continue;
        s->steps=total;return result;
    }
}
