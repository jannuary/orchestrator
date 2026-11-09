#ifndef WRAPPER_KG_SPC_NATIVE_INTERNAL_H
#define WRAPPER_KG_SPC_NATIVE_INTERNAL_H
#define WRAPPER_KG_NO_CONSTANTS
#include "spc_machine.h"
#include "spc_native.h"
int wrapper_kg_native_lookup(uint64_t address,unsigned width,uint64_t *value);
int wrapper_kg_native_read(const wrapper_kg_payload_region *regions,size_t count,
    uint64_t address,unsigned width,uint64_t *value);
static inline int kg_shadow_overlap(const wrapper_kg_native_state *fs,uint64_t address,size_t size) {    if(!fs->ckc_shadow_active || fs->ckc_shadow_active>=3 || !size)return 0;
    return address<=fs->ckc_shadow_slot ? fs->ckc_shadow_slot-address<size : address-fs->ckc_shadow_slot<4;
}
static inline int kg_shadow_cell_overlap(uint64_t address,size_t size,uint64_t cell,size_t width) {
    if(!size)return 0;
    return address<=cell ? cell-address<size : address-cell<width;
}
static inline int kg_shadow_read_allowed(const wrapper_kg_native_state *fs,uint64_t address,size_t size) {
    size_t j;
    for(j=0;j<WRAPPER_KG_BYTE_SHADOW_COUNT;++j){
        const wrapper_kg_byte_shadow *p=&fs->ckc_byte_shadows[j];
        size_t width=(p->live&UINT64_C(0x100))?4:1;
        if((p->live&1) && kg_shadow_cell_overlap(address,size,p->first,width))return 0;
        if((p->live&2) && kg_shadow_cell_overlap(address,size,p->second,width))return 0;
    }
    if(!kg_shadow_overlap(fs,address,size))return 1;
    return fs->ckc_shadow_active==1 && fs->cpu.pc==UINT64_C(0x100e84e6) &&
        fs->cpu.gpr[6]==fs->ckc_shadow_frame && address==fs->ckc_shadow_slot && size==4;
}
/* The phase-30/31 CKC fold reads normalized code-word pairs one cell at a
 * time and XORs them into frame accumulators. A pair stores (0,A^B) where the
 * original frame held (A,B); XOR-linear use of both cells restores A^B, so a
 * whole-cell read is admitted while the fold is active and the per-record
 * balance is tracked for the phase-end check. */
static inline int kg_pair_cell_read(uint64_t address,size_t size,uint64_t cell) {
    return address<=cell && cell<=UINT64_MAX-4 && cell+4-address<=size;
}
static inline int kg_pair_parity_clear(const wrapper_kg_native_state *fs) {
    size_t j;for(j=0;j<4;++j)if(fs->ckc_pair_parity[j])return 0;
    return 1;
}
static inline void kg_pair_parity_reset(wrapper_kg_native_state *fs) {
    size_t j;for(j=0;j<4;++j)fs->ckc_pair_parity[j]=0;
}
static inline int kg_pair_read_admit(wrapper_kg_native_state *fs,uint64_t address,size_t size) {
    size_t j,slots[WRAPPER_KG_BYTE_SHADOW_COUNT],count=0;
    if((fs->ckc_shadow_active!=30 && fs->ckc_shadow_active!=31) || !size)return 0;
    for(j=0;j<WRAPPER_KG_BYTE_SHADOW_COUNT;++j){
        const wrapper_kg_byte_shadow *p=&fs->ckc_byte_shadows[j];
        size_t width=(p->live&UINT64_C(0x100))?4:1;
        int first=(p->live&1)&&kg_shadow_cell_overlap(address,size,p->first,width);
        int second=(p->live&2)&&kg_shadow_cell_overlap(address,size,p->second,width);
        if(!first && !second)continue;
        if(p->live!=UINT64_C(0x103) || p->frame!=fs->cpu.gpr[6])return 0;
        if(first && second)return 0; /* One access cannot consume both cells. */
        if((first && !kg_pair_cell_read(address,size,p->first)) ||
           (second && !kg_pair_cell_read(address,size,p->second)))return 0;
        slots[count++]=j;
    }
    if(!count)return 0;
    for(j=0;j<count;++j)fs->ckc_pair_parity[slots[j]/64]^=UINT64_C(1)<<(slots[j]%64);
    return 1;
}
static inline void kg_shadow_written(wrapper_kg_native_state *fs,uint64_t address,size_t size) {
    size_t j;
    for(j=0;j<WRAPPER_KG_BYTE_SHADOW_COUNT;++j){
        wrapper_kg_byte_shadow *p=&fs->ckc_byte_shadows[j];
        size_t width=(p->live&UINT64_C(0x100))?4:1;
        if((p->live&1) && kg_shadow_cell_overlap(address,size,p->first,width)){
            if(address<=p->first && size>=width && p->first-address<=size-width)p->live&=~UINT64_C(1);
            else p->live|=UINT64_C(0x200);
        }
        if((p->live&2) && kg_shadow_cell_overlap(address,size,p->second,width)){
            if(address<=p->second && size>=width && p->second-address<=size-width)p->live&=~UINT64_C(2);
            else p->live|=UINT64_C(0x200);
        }
        if((p->live&UINT64_C(0x100)) && !(p->live&3))p->live=0;
    }
    if(!kg_shadow_overlap(fs,address,size))return;
    if(address<=fs->ckc_shadow_slot && size>=4 && fs->ckc_shadow_slot-address<=size-4)fs->ckc_shadow_active=0;
    else fs->ckc_shadow_active=2;
}
static inline int kg_shadow_any(const wrapper_kg_native_state *fs) {
    size_t j;if(fs->ckc_shadow_active)return 1;
    for(j=0;j<WRAPPER_KG_BYTE_SHADOW_COUNT;++j)if(fs->ckc_byte_shadows[j].live)return 1;
    return 0;
}
static inline uint64_t kg_shadow_fault_address(const wrapper_kg_native_state *fs) {
    size_t j;if(fs->ckc_shadow_active)return fs->ckc_shadow_slot;
    for(j=0;j<WRAPPER_KG_BYTE_SHADOW_COUNT;++j){
        const wrapper_kg_byte_shadow *p=&fs->ckc_byte_shadows[j];
        if(p->live&1)return p->first;
        if(p->live&2)return p->second;
    }
    return 0;
}
static inline void kg_shadow_return(wrapper_kg_native_state *fs,uint64_t stack) {
    size_t j;
    if(fs->ckc_shadow_active && fs->ckc_shadow_frame<=UINT64_MAX-8 && stack==fs->ckc_shadow_frame+8)fs->ckc_shadow_active=0;
    for(j=0;j<WRAPPER_KG_BYTE_SHADOW_COUNT;++j){
        wrapper_kg_byte_shadow *p=&fs->ckc_byte_shadows[j];
        if(p->live && p->frame<=UINT64_MAX-8 && stack==p->frame+8)p->live=0;
    }
}
static inline int wrapper_kg_native_read_guarded(wrapper_kg_native_state *fs,
    const wrapper_kg_payload_region *regions,size_t count,uint64_t address,unsigned width,uint64_t *value) {
    if(!kg_shadow_read_allowed(fs,address,width) && !kg_pair_read_admit(fs,address,width))return 0;
    return wrapper_kg_native_read(regions,count,address,width,value);
}
/* Consume a pair only when both cells are live, belong to this frame, and
 * have no competing shadow. The normalized bytes may be read only together. */
static inline int kg_byte_shadow_pair(wrapper_kg_native_state *fs,
    const wrapper_kg_payload_region *regions,size_t count,uint64_t first,uint64_t second,uint64_t *out) {
    size_t j;int found=0;uint64_t a,b;
    if(first==second || kg_shadow_overlap(fs,first,1) || kg_shadow_overlap(fs,second,1))return 0;
    for(j=0;j<WRAPPER_KG_BYTE_SHADOW_COUNT;++j){
        const wrapper_kg_byte_shadow *p=&fs->ckc_byte_shadows[j];
        size_t width=(p->live&UINT64_C(0x100))?4:1;
        int overlaps=((p->live&1) && (kg_shadow_cell_overlap(first,1,p->first,width) || kg_shadow_cell_overlap(second,1,p->first,width))) ||
                     ((p->live&2) && (kg_shadow_cell_overlap(first,1,p->second,width) || kg_shadow_cell_overlap(second,1,p->second,width)));
        if(!overlaps)continue;
        if(found || p->live!=3 || p->frame!=fs->cpu.gpr[6] ||
           !((p->first==first&&p->second==second)||(p->first==second&&p->second==first)))return 0;
        found=1;
    }
    if(!found || !translate(regions,count,first,1,1) || !translate(regions,count,second,1,1) ||
       !wrapper_kg_native_read(regions,count,first,1,&a) ||
       !wrapper_kg_native_read(regions,count,second,1,&b))return 0;
    *out=a^b;return 1;
}
static inline int kg_word_shadow_pair(wrapper_kg_native_state *fs,
    const wrapper_kg_payload_region *regions,size_t count,uint64_t first,uint64_t second,uint64_t *out) {
    size_t j;int found=0;uint64_t a,b;
    if(kg_shadow_cell_overlap(first,4,second,4)||kg_shadow_overlap(fs,first,4)||kg_shadow_overlap(fs,second,4))return 0;
    for(j=0;j<WRAPPER_KG_BYTE_SHADOW_COUNT;++j){
        const wrapper_kg_byte_shadow *p=&fs->ckc_byte_shadows[j];size_t width=(p->live&UINT64_C(0x100))?4:1;
        int overlaps=((p->live&1)&&(kg_shadow_cell_overlap(first,4,p->first,width)||kg_shadow_cell_overlap(second,4,p->first,width)))||
                     ((p->live&2)&&(kg_shadow_cell_overlap(first,4,p->second,width)||kg_shadow_cell_overlap(second,4,p->second,width)));
        if(!overlaps)continue;
        if(found||p->live!=UINT64_C(0x103)||p->frame!=fs->cpu.gpr[6]||
           !((p->first==first&&p->second==second)||(p->first==second&&p->second==first)))return 0;
        found=1;
    }
    if(!found||!translate(regions,count,first,4,1)||!translate(regions,count,second,4,1)||
       !wrapper_kg_native_read(regions,count,first,4,&a)||!wrapper_kg_native_read(regions,count,second,4,&b))return 0;
    *out=a^b;return 1;
}
/* Read a normalized whole word only into an XOR accumulator that tracks the
 * returned pair identity. Direct reads remain blocked by the ordinary guard. */
static inline int kg_word_shadow_read(wrapper_kg_native_state *fs,
    const wrapper_kg_payload_region *regions,size_t count,uint64_t address,uint64_t *out,size_t *tag) {
    size_t j;*tag=0;
    if(kg_shadow_overlap(fs,address,4))return 0;
    for(j=0;j<WRAPPER_KG_BYTE_SHADOW_COUNT;++j){
        const wrapper_kg_byte_shadow *p=&fs->ckc_byte_shadows[j];size_t width=(p->live&UINT64_C(0x100))?4:1;
        int overlaps=((p->live&1)&&kg_shadow_cell_overlap(address,4,p->first,width))||
                     ((p->live&2)&&kg_shadow_cell_overlap(address,4,p->second,width));
        if(!overlaps)continue;
        if(*tag||p->live!=UINT64_C(0x103)||p->frame!=fs->cpu.gpr[6]||kg_shadow_cell_overlap(p->first,4,p->second,4)||
           (address!=p->first&&address!=p->second))return 0;
        *tag=j+1;
    }
    if(*tag && !translate(regions,count,address,4,1))return 0;
    return *tag?wrapper_kg_native_read(regions,count,address,4,out):
                wrapper_kg_native_read_guarded(fs,regions,count,address,4,out);
}
#define NATIVE_LOCALS \
    wrapper_kg_payload_state *s=&fs->cpu; \
    uint64_t a=0,b=0,c=0,x=0,y=0,z=0,next_pc=0; \
    kg_vec v0={0,0},v1={0,0}; \
    s->steps=0
#define STEP(off) do {s->pc=bias+UINT64_C(off); \
    if(fs->ckc_shadow_active>=4 && ((uint64_t)(off)<(fs->ckc_shadow_slot>>32) || (uint64_t)(off)>(uint32_t)fs->ckc_shadow_slot || s->gpr[6]!=fs->ckc_shadow_frame)){ \
        s->fault_address=fs->ckc_shadow_slot;s->fault_size=1;return WRAPPER_KG_PAYLOAD_READ_FAULT;} \
    if(s->steps==max_steps)return WRAPPER_KG_PAYLOAD_LIMIT;}while(0)
#define READ(dst,address,width) do {uint64_t addr_=(address); \
    if(!wrapper_kg_native_read_guarded(fs,regions,count,addr_,width,&(dst))){ \
        s->fault_address=addr_;s->fault_size=width;return WRAPPER_KG_PAYLOAD_READ_FAULT;}}while(0)
#define WRITE(address,width,value) do {uint64_t addr_=(address),v_=(value);unsigned j_; \
    unsigned char *p_=translate(regions,count,addr_,width,2); \
    if(!p_){s->fault_address=addr_;s->fault_size=width;return WRAPPER_KG_PAYLOAD_WRITE_FAULT;} \
    for(j_=0;j_<width;++j_)p_[j_]=(unsigned char)(v_>>(j_*8)); \
    kg_shadow_written(fs,addr_,width);}while(0)
#define NATIVE_DONE \
    (void)a;(void)b;(void)c;(void)x;(void)y;(void)z;(void)v0;(void)v1; \
    s->pc=next_pc;return WRAPPER_KG_PAYLOAD_OK
#endif
