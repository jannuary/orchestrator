#include "spc_machine.h"
#include "spc_continuation.h"
#include "spc_continuation_bounds.inc"
int wrapper_kg_spc_continuation_run_imported(unsigned path,uint64_t bias,wrapper_kg_payload_state *s,
    const wrapper_kg_payload_region *regions,size_t count,size_t max_steps,const wrapper_kg_payload_imports *bindings) {
    uint64_t a=0,b=0,c=0,x=0,y=0,z=0;
    wrapper_kg_payload_read_trace trace=0;
    void *user=0;
    if(!s || path>=sizeof continuation_bounds/sizeof continuation_bounds[0] || bias>UINT64_MAX-UINT64_C(0x692c08) || !valid(regions,count))
        return WRAPPER_KG_PAYLOAD_INVALID;
    s->steps=0;s->fault_address=0;s->fault_size=0;
#define STEP(off) do {s->pc=bias+UINT64_C(off); \
    if(s->steps==max_steps)return WRAPPER_KG_PAYLOAD_LIMIT;} while(0)
#define READ(dst,address,width) do {uint64_t addr_=(address);unsigned j_; \
    const unsigned char *p_=translate(regions,count,addr_,width,1); \
    if(p_){(dst)=0;for(j_=0;j_<width;++j_)(dst)|=(uint64_t)p_[j_]<<(j_*8);} \
    else if(!payload_constant_read_imported(bias,addr_,width,&(dst),bindings)) { \
        s->fault_address=addr_;s->fault_size=width;return WRAPPER_KG_PAYLOAD_READ_FAULT;} \
    if(trace)trace(addr_,width,user);}while(0)
#define WRITE(address,width,value) do {uint64_t addr_=(address),v_=(value);unsigned j_; \
    unsigned char *p_=translate(regions,count,addr_,width,2); \
    if(!p_){s->fault_address=addr_;s->fault_size=width;return WRAPPER_KG_PAYLOAD_WRITE_FAULT;} \
    for(j_=0;j_<width;++j_)p_[j_]=(unsigned char)(v_>>(j_*8));}while(0)
    switch(path) {
#include "spc_continuation_cases.inc"
    }
#undef STEP
#undef READ
#undef WRITE
    (void)a;(void)b;(void)c;(void)x;(void)y;(void)z;
    s->pc=bias+continuation_bounds[path].end;return WRAPPER_KG_PAYLOAD_OK;
}

size_t wrapper_kg_spc_continuation_count(void) {
    return sizeof continuation_bounds/sizeof continuation_bounds[0];
}

int wrapper_kg_spc_continuation_run(unsigned block,uint64_t bias,
    wrapper_kg_payload_state *s,const wrapper_kg_payload_region *regions,
    size_t count,size_t max_steps) {
    return wrapper_kg_spc_continuation_run_imported(block,bias,s,regions,count,max_steps,0);
}

int wrapper_kg_spc_continuation_transfer(unsigned block,uint64_t bias,
    wrapper_kg_payload_state *s,const wrapper_kg_payload_region *regions,size_t count) {
    const struct continuation_bound *bound;
    uint64_t target,sp,ret;
    unsigned char *p;
    unsigned j;
    if(!s || block>=sizeof continuation_bounds/sizeof continuation_bounds[0] ||
       bias>UINT64_MAX-UINT64_C(0x692c08) || !valid(regions,count))return WRAPPER_KG_PAYLOAD_INVALID;
    bound=continuation_bounds+block;
    if(s->pc!=bias+bound->end || s->steps==SIZE_MAX)return WRAPPER_KG_PAYLOAD_INVALID;
    s->fault_address=0;s->fault_size=0;
    target=s->gpr[bound->reg];
    if(bound->call) {
        sp=s->gpr[7]-UINT64_C(8);
        p=translate(regions,count,sp,8,2);
        if(!p){s->fault_address=sp;s->fault_size=8;return WRAPPER_KG_PAYLOAD_WRITE_FAULT;}
        ret=bias+bound->end+bound->size;
        for(j=0;j<8;++j)p[j]=(unsigned char)(ret>>(j*8));
        s->gpr[7]=sp;
    }
    s->pc=target;++s->steps;
    return WRAPPER_KG_PAYLOAD_OK;
}
