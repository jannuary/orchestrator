#ifndef WRAPPER_KG_SPC_GENERATE_H
#define WRAPPER_KG_SPC_GENERATE_H
#include <stdint.h>
#include <stddef.h>
/* Callbacks return zero on success. Entropy is required to be cryptographically
 * secure in production. NULL callbacks use the operating system. */
typedef int (*wrapper_kg_entropy)(void *,unsigned char *,size_t);
typedef uint64_t (*wrapper_kg_clock)(void *);
typedef int (*wrapper_kg_time)(void *,int64_t *,int64_t *);
typedef struct wrapper_kg_spc_request {
    /* Legacy raw movie identifier, valid only in the runtime that created it.
     * The FPS-session API derives its own identifier and ignores this field. */
    uint64_t account;
    const unsigned char *certificate;size_t certificate_size;
    const unsigned char *content;size_t content_size;
    const unsigned char *device_seed;size_t device_seed_size;
    wrapper_kg_entropy entropy;wrapper_kg_clock clock;wrapper_kg_time time;
    void *user;
} wrapper_kg_spc_request;
typedef struct wrapper_kg_spc_result {
    uint32_t status;
    uint64_t pc,fault_address,source_steps,clock_calls;
    size_t output_size;
    unsigned fault_size;
} wrapper_kg_spc_result;
/* Builds a complete SPC with source code only. No ELF, SDK, runtime capture,
 * external CPU emulator or executable input is loaded. Fixed algorithm tables are built in.
 * Returns 0 on success, negative on input/runtime failure. Result diagnostics
 * contain virtual locations/counts only, never key material. */
int wrapper_kg_spc_generate(const wrapper_kg_spc_request *request,
    unsigned char *output,size_t capacity,wrapper_kg_spc_result *result);
/* Optional ownership of the source exchange state. Release it after use. */
typedef struct wrapper_kg_spc_session wrapper_kg_spc_session;
int wrapper_kg_spc_generate_session(const wrapper_kg_spc_request *request,
    unsigned char *output,size_t capacity,wrapper_kg_spc_result *result,
    wrapper_kg_spc_session **session);
/* Normal FPS flow: register the certificate/key-format version in this runtime
 * before SPC generation. This is required for a usable matching CKC exchange. */
int wrapper_kg_spc_generate_fps_session(const wrapper_kg_spc_request *request,
    uint32_t format_version,unsigned char *output,size_t capacity,
    wrapper_kg_spc_result *result,wrapper_kg_spc_session **session);
int wrapper_kg_spc_session_exchange(const wrapper_kg_spc_session *session,
    unsigned char output[16]);
/* Process only a CKC matching this session's SPC. No original backend is loaded.
 * Returns negative on input/runtime/backend failure; output changes on success.
 * Context values are opaque virtual handles owned by this source session. */
int wrapper_kg_spc_session_ckc_persistent(wrapper_kg_spc_session *session,
    const unsigned char *ckc,size_t size,unsigned char *output,size_t capacity,
    wrapper_kg_spc_result *result);
int wrapper_kg_spc_session_ckc_context(wrapper_kg_spc_session *session,
    const unsigned char *ckc,size_t size,uint64_t *context,
    wrapper_kg_spc_result *result);
/* Finalize a context returned by this session before decrypting with it.
 * These APIs own no host pointers beyond the duration of the call. */
int wrapper_kg_spc_session_context_finalize(wrapper_kg_spc_session *session,
    uint64_t context,wrapper_kg_spc_result *result);
#define WRAPPER_KG_CONTEXT_DECRYPT_MAX_SIZE 4096
/* The backend determines valid modes/block sizes. Bounded nonempty input is
 * copied into virtual scratch memory; output changes only on complete success.
 * Returns -1 for invalid/foreign/unfinalized contexts, -3 for source failure,
 * -4 for backend rejection, and -5 for the existing lifetime deadline. */
int wrapper_kg_spc_session_context_decrypt(wrapper_kg_spc_session *session,
    uint64_t context,uint32_t mode,const unsigned char *input,size_t size,
    unsigned char *output,size_t capacity,wrapper_kg_spc_result *result);
void wrapper_kg_spc_session_free(wrapper_kg_spc_session *session);
#endif
