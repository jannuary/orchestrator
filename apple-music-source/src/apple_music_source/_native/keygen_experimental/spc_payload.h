#ifndef WRAPPER_KG_SPC_PAYLOAD_H
#define WRAPPER_KG_SPC_PAYLOAD_H
#include <stddef.h>
#include <stdint.h>
/* Experimental bounded semantic reconstructions of five CoreLSKD payload
 * intervals. Guest addresses resolve through bounded caller-owned regions or
 * built-in constant data; captured pointers are never dereferenced. No executable blob is loaded.
 * GPR order: rax,rbx,rcx,rdx,rsi,rdi,rbp,rsp,r8,r9,r10,r11,r12,r13,r14,r15.
 * Fixed lookup data and relative slots are built in. Mutable state setup,
 * framing, CBC orchestration and key derivation remain
 * outside this interface. Paths restart at their fixed entry on every call.
 */
typedef struct wrapper_kg_payload_state {
    uint64_t gpr[16], flags, pc, fault_address;
    size_t steps;
    unsigned fault_size;
} wrapper_kg_payload_state;
typedef struct wrapper_kg_payload_region {
    uint64_t address;
    size_t size;
    unsigned char *data;
    unsigned permissions; /* 1=read, 2=write */
} wrapper_kg_payload_region;
enum { WRAPPER_KG_PAYLOAD_OK=0, WRAPPER_KG_PAYLOAD_INVALID=1,
       WRAPPER_KG_PAYLOAD_READ_FAULT=2, WRAPPER_KG_PAYLOAD_WRITE_FAULT=3,
       WRAPPER_KG_PAYLOAD_LIMIT=4, WRAPPER_KG_PAYLOAD_ARITH_FAULT=5 };
/* Optional standard service addresses in the caller's virtual address space.
 * They are data only: these bounded routines never call these addresses. */
typedef struct wrapper_kg_payload_imports {uint64_t malloc_entry,free_entry;} wrapper_kg_payload_imports;
int wrapper_kg_spc_payload_constant_read_imported(uint64_t module_bias,
    uint64_t address,unsigned width,uint64_t *value,
    const wrapper_kg_payload_imports *bindings);
/* Read only a covered fixed-data range. Returns 1 on success; otherwise 0
 * without changing value. Module bias is applied to relative pointer slots. */
int wrapper_kg_spc_payload_constant_read(uint64_t module_bias,uint64_t address,
    unsigned width,uint64_t *value);
typedef void (*wrapper_kg_payload_read_trace)(uint64_t address, unsigned width, void *user);
/* Offline evidence collection hook; callback receives addresses/sizes only. */
int wrapper_kg_spc_payload_trace(unsigned path, uint64_t module_bias,
    wrapper_kg_payload_state *state, const wrapper_kg_payload_region *regions,
    size_t count, size_t max_steps, wrapper_kg_payload_read_trace trace, void *user);
int wrapper_kg_spc_payload_run(unsigned path, uint64_t module_bias,
    wrapper_kg_payload_state *state, const wrapper_kg_payload_region *regions,
    size_t count, size_t max_steps);
#endif
