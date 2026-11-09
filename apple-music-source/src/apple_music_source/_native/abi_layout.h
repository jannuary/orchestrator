#ifndef AMS_ABI_LAYOUT_H
#define AMS_ABI_LAYOUT_H
#include <stddef.h>
#include <stdint.h>
typedef struct ams_source_binding { const char *name; uint64_t address; } ams_source_binding;
/* Pristine initial globals at source-runner virtual addresses. Bindings name
 * source-owned import implementations, never a vendor SDK or crypto provider.
 * This does not call any binding. Names must be readable NUL-terminated strings;
 * missing/ambiguous requested names and unsupported source locations fail closed.
 * Reads are atomic with respect to output. This initializes ordinary memory;
 * it MUST NOT override mutated data, permissions, faults or shadow policy.
 * It is not a complete image loader or crypto/auth/session implementation. */
int ams_abi_initial_read(uint64_t address,unsigned width,const ams_source_binding *bindings,size_t count,uint64_t *output);
#endif
