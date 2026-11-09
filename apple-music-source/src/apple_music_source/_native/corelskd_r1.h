#ifndef WRAPPER_CORELSKD_R1_H
#define WRAPPER_CORELSKD_R1_H
#include <stddef.h>
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif
enum corelskd_r1_register {
    CORELSKD_RAX, CORELSKD_RBX, CORELSKD_RCX, CORELSKD_RDX,
    CORELSKD_RSI, CORELSKD_RDI, CORELSKD_RBP, CORELSKD_RSP,
    CORELSKD_R8, CORELSKD_R9, CORELSKD_R10, CORELSKD_R11,
    CORELSKD_R12, CORELSKD_R13, CORELSKD_R14, CORELSKD_R15
};
enum { CORELSKD_R1_READ = 1, CORELSKD_R1_WRITE = 2,
       CORELSKD_R1_INSTRUCTIONS = 3598 };
enum corelskd_r1_result {
    CORELSKD_R1_OK = 0, CORELSKD_R1_INVALID = 1,
    CORELSKD_R1_READ_FAULT = 2, CORELSKD_R1_WRITE_FAULT = 3,
    CORELSKD_R1_STEP_LIMIT = 4
};
typedef struct corelskd_r1_state {
    uint64_t gpr[16];
    uint64_t pc;
    uint64_t fault_address;
    size_t steps;
    unsigned fault_size;
} corelskd_r1_state;
typedef struct corelskd_r1_region {
    uint64_t address;
    size_t size;
    uint8_t *data;
    unsigned permissions;
} corelskd_r1_region;
/* Executes the fixed interval [0x1d5709, 0x1d94da). No target code executes.
 * Guest addresses are integers, translated only through the supplied regions.
 * Regions must be nonempty, disjoint, nonwrapping and backed by valid buffers.
 * A memory operand must fit wholly in one region. Buffers may alias; accesses
 * occur in original order and unaligned little-endian operations are supported.
 * On a fault/limit, completed instructions remain committed; pc identifies the
 * next/faulting instruction. This is not a resumable interface: every call starts
 * at the fixed entry. flags are not input/output; all consumed conditions are
 * derived within this interval. The terminal indirect jump is not executed.
 * No key generation, snapshot acquisition or full sample decryption is provided.
 */
int corelskd_r1_run(corelskd_r1_state *state,
                    const corelskd_r1_region *regions, size_t count,
                    size_t max_steps);
/* Same entry, stopping immediately after the 16 output writes, before the
 * original dispatch-table lookup. No original binary/table mapping is needed.
 */
int corelskd_r1_transform(corelskd_r1_state *state,
                        const corelskd_r1_region *regions, size_t count,
                        size_t max_steps);
/* Transform one block using a first-block /key capture. State is the byte
 * window beginning at captured RBP-0x2000 (at least 0x2100 bytes). Addresses
 * are relocated into bounded private regions; no captured pointer is followed.
 * This reproduces the captured block operation, including its captured chaining
 * state. It does not acquire keys, establish a cipher mode, or parse media.
 */
int corelskd_r1_block(const uint8_t ctx[0x8000], const uint8_t *state,
                     size_t state_size, uint64_t rax, uint64_t rcx,
                     const uint8_t input[16], uint8_t output[16]);
/* Decrypt complete CBC blocks. A NULL iv uses the IV encoded in the capture.
 * No padding is added/removed. input/output must be disjoint or identical. The captured
 * key state is read-only; earlier blocks remain written if a later block fails.
 */
int corelskd_r1_cbc(const uint8_t ctx[0x8000], const uint8_t *state,
                   size_t state_size, uint64_t rax, uint64_t rcx,
                   const uint8_t iv[16], const uint8_t *input,
                   uint8_t *output, size_t size);
/* Recover the ordinary 16-byte AES-128 content key from this capture layout.
 * Uses the affine output encoding and final-round tables; no original library
 * or emulator is required. Writes key only after all 16 positions agree.
 */
int corelskd_r1_extract_key(const uint8_t ctx[0x8000], const uint8_t *state,
                           size_t state_size, uint64_t rax, uint64_t rcx,
                           uint8_t key[16]);
#ifdef __cplusplus
}
#endif
#endif
