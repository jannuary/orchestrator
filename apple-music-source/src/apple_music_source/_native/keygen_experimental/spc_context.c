#include "spc_machine.h"
#include "spc_context.h"
int wrapper_kg_spc_context_run(unsigned path,uint64_t bias,wrapper_kg_payload_state *s,
    const wrapper_kg_payload_region *regions,size_t count,size_t max_steps) {
    uint64_t a=0,b=0,c=0,x=0,y=0,z=0;
    wrapper_kg_payload_read_trace trace=0;
    void *user=0;
    static const uint64_t ends[5]={0x36b6db,0x343891,0x566816,0x3b5eef,0x38edec};
    if(!s || path>=5 || bias>UINT64_MAX-UINT64_C(0x692c08) || !valid(regions,count))
        return WRAPPER_KG_PAYLOAD_INVALID;
    s->steps=0;s->fault_address=0;s->fault_size=0;
#define STEP(off) do {s->pc=bias+UINT64_C(off); \
    if(s->steps==max_steps)return WRAPPER_KG_PAYLOAD_LIMIT;} while(0)
#define READ(dst,address,width) do {uint64_t addr_=(address);unsigned j_; \
    const unsigned char *p_=translate(regions,count,addr_,width,1); \
    if(p_){(dst)=0;for(j_=0;j_<width;++j_)(dst)|=(uint64_t)p_[j_]<<(j_*8);} \
    else if(!payload_constant_read(bias,addr_,width,&(dst))) { \
        s->fault_address=addr_;s->fault_size=width;return WRAPPER_KG_PAYLOAD_READ_FAULT;} \
    if(trace)trace(addr_,width,user);}while(0)
#define WRITE(address,width,value) do {uint64_t addr_=(address),v_=(value);unsigned j_; \
    unsigned char *p_=translate(regions,count,addr_,width,2); \
    if(!p_){s->fault_address=addr_;s->fault_size=width;return WRAPPER_KG_PAYLOAD_WRITE_FAULT;} \
    for(j_=0;j_<width;++j_)p_[j_]=(unsigned char)(v_>>(j_*8));}while(0)
    switch(path) {
    case 0:
#include "spc_context_a.inc"
        break;
    case 1:
#include "spc_context_b.inc"
        break;
    case 2:
#include "spc_context_c.inc"
        break;
    case 3:
#include "spc_context_d.inc"
        break;
    case 4:
#include "spc_context_e.inc"
        break;
    }
#undef STEP
#undef READ
#undef WRITE
    (void)a;(void)b;(void)c;(void)x;(void)y;(void)z;
    s->pc=bias+ends[path];return WRAPPER_KG_PAYLOAD_OK;
}

int wrapper_kg_spc_context_prepare(uint64_t bias,wrapper_kg_payload_state *s,
    const wrapper_kg_payload_region *regions,size_t count,size_t max_steps) {
    return wrapper_kg_spc_context_run(0,bias,s,regions,count,max_steps);
}
