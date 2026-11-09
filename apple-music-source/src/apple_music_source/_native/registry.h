#ifndef AMS_REGISTRY_H
#define AMS_REGISTRY_H
#include <stddef.h>
#include <stdint.h>

/* Canonical generation-tag registry, recovered from CoreLSKD's allocation
 * loop 0x1f7300..0x2079d4 and pre-codec check 0x3ee473..0x3ee4e5.
 * This owns semantic generations, not the original encoded pointer/record
 * representation. Zero is the original free-tag value after subtracting its
 * additive encoding. Matching a tag does NOT validate a crypto context.
 * Full record/session mutation, synchronization and expiry remain separate
 * unresolved obligations. No public session API uses this yet.
 */
enum { AMS_REGISTRY_SLOTS = 1024 };
enum ams_registry_status {
    AMS_REGISTRY_FOUND = 0, AMS_REGISTRY_MORE = 1,
    AMS_REGISTRY_FULL = 2, AMS_REGISTRY_INVALID = 3
};
typedef struct ams_registry {
    uint32_t generation[AMS_REGISTRY_SLOTS];
} ams_registry;
typedef struct ams_registry_search {
    uint32_t candidate;
    uint32_t probes;
    uint32_t slot;
    uint32_t handle;
    unsigned status;
} ams_registry_search;

/* Both objects are caller-owned and must be disjoint. A probe quota stops at
 * slot boundaries; it is NOT an x86 instruction budget. The original outer
 * entropy/nonzero check remains the caller's responsibility. In particular,
 * candidate arithmetic wraps modulo 2^32, including through zero during a
 * collision chain. The original loop does not skip zero on that path.
 * The caller must hold the registry lock across a search and its resumption.
 */
void ams_registry_init(ams_registry *registry);
void ams_registry_search_begin(ams_registry_search *search, uint32_t candidate);
int ams_registry_reserve(ams_registry *registry, ams_registry_search *search,
                         size_t probe_quota);
/* Returns only the original pre-codec generation comparison. The original
 * default generation zero also matches its corresponding invented handle;
 * this must not be promoted to a valid/acquired-context check.
 */
int ams_registry_tag_matches(const ams_registry *registry, uint32_t handle);

enum {
    AMS_REGISTRY_RECORD_SIZE = 336,
    AMS_REGISTRY_RECORD_KIND_OFFSET = 244,
    AMS_REGISTRY_OWNED_RECORD_KIND = 15
};
enum ams_registry_release_status {
    AMS_REGISTRY_RELEASED = 0, AMS_REGISTRY_ALREADY_FREE = 1,
    AMS_REGISTRY_NEEDS_RECORD_CLEANUP = 2, AMS_REGISTRY_RELEASE_INVALID = 3
};
/* Canonical suboperation of the reset walker 0x3f03df onward. A free slot
 * does not access record. An occupied slot with a null record or a decoded
 * non-owned record clears only its generation. Kind 15 requires the ORIGINAL
 * record cleanup first; it returns NEEDS_RECORD_CLEANUP without clearing.
 * This does not implement that cleanup, the walker's final helper, synchronization,
 * encoding, original instruction budgets or worker expiry. The caller holds
 * the registry lock and supplies a readable decoded record, disjoint from r.
 */
int ams_registry_release_unowned(ams_registry *registry, size_t slot,
                                const void *record, size_t record_size);
/* Extends the bounded reset to kind-15 records which own no external buffers.
 * External pointers at b8/c8/110/130 require the buffer-aware API; mode 3 at
 * 12c requires unrecovered shared-state effects. Both return
 * NEEDS_RECORD_CLEANUP without any writes from this inline-only API.
 * scratch_address is the abstract address of the original walker's remaining-
 * length cell (rbp-3048). The original overwrite pattern depends on this
 * address; it is computed arithmetically, never copied from image data.
 * The caller supplies writable decoded storage, disjoint from the registry.
 * This still excludes the final walker helper, locking and worker expiry.
 */
int ams_registry_release_inline(ams_registry *registry, size_t slot,
                               void *record, size_t record_size,
                               uint64_t scratch_address);

typedef struct ams_registry_buffer {
    uint64_t address; /* canonical record pointer, separate from mapped bytes */
    void *data;
    size_t size;
} ams_registry_buffer;
typedef void (*ams_registry_free_fn)(void *opaque, uint64_t address);
/* Extends reset to the four external buffers, in original release order:
 * record offsets 110, b8, c8, 130. Supply four corresponding bounded mappings.
 * Only c8 is overwritten, for (record[d0] - 0x193931bf) modulo 2^32 bytes.
 * Missing/short/overlapping mappings, duplicate pointers, or a missing allocator
 * callback fail before any mutation. Callback is the caller's void allocator
 * release; it must return normally and not reenter or modify the registry,
 * record, mappings, or other allocations. Its address argument is never assumed
 * to be a host pointer. A callback may deallocate its own mapping after release.
 * Mode 3 still requires shared-state cleanup and refuses without writes.
 * The caller holds the registry lock. This does not unlock it or implement expiry.
 */
int ams_registry_release_buffers(ams_registry *registry, size_t slot,
                                void *record, size_t record_size,
                                uint64_t scratch_address,
                                const ams_registry_buffer buffers[4],
                                ams_registry_free_fn release, void *opaque);

/* Canonical shared mode-3 state. The original stores references with an additive
 * tag, and the three 64-bit values under seed-dependent XOR representations.
 * These fields are decoded values; no image-derived keys/banks are required.
 */
typedef struct ams_registry_shared {
    uint32_t references;
    uint64_t timestamp;
    uint64_t baseline;
    uint64_t counter;
} ams_registry_shared;
/* Caller holds the shared-state lock. Decrement references unless zero,
 * initialize a zero timestamp, and update the cumulative counter using unsigned
 * modulo-2^64 arithmetic. Seconds are the successful original gettimeofday
 * result, or zero for its failure path. This does not implement a worker wake
 * or expiry decision. */
int ams_registry_shared_update(ams_registry_shared *shared, uint64_t seconds);
/* Buffer-aware reset including mode 3. In that mode the caller also holds the
 * shared-state lock; shared may be null, matching the original absent-object
 * path. Validate all mappings and state aliases before any writes/releases.
 * Other record modes ignore shared and seconds. This remains an internal
 * decoded-storage operation, not a session validity or key acquisition API. */
int ams_registry_release_shared(ams_registry *registry, size_t slot,
                               void *record, size_t record_size,
                               uint64_t scratch_address,
                               const ams_registry_buffer buffers[4],
                               ams_registry_free_fn release, void *opaque,
                               ams_registry_shared *shared, uint64_t seconds);

typedef struct ams_registry_worker {
    uint64_t wake_counter;
    unsigned active;
} ams_registry_worker;
enum ams_registry_worker_status {
    AMS_REGISTRY_WORKER_STOP = 0, AMS_REGISTRY_WORKER_SLEEP = 1,
    AMS_REGISTRY_WORKER_INVALID = 3
};
/* Logical worker entry/wake boundaries from 0xdc000..0xdc7c9. Caller holds
 * the shared-object locks and supplies disjoint initialized objects. Begin
 * takes the worker's reference (with original uint32 wrap). Wake first clamps
 * the cumulative counter against the saved wake counter, then maintains time and advances the
 * wake counter by five.
 * References zero or one take the original stop branch, which decrements
 * modulo 2^32 (including zero underflow); otherwise wait five seconds.
 * These do not spawn a thread, advance a host deadline, rotate encoded storage,
 * implement record expiry, or establish concurrency/session validity. */
int ams_registry_worker_begin(ams_registry_worker *worker, ams_registry_shared *shared);
int ams_registry_worker_wake(ams_registry_worker *worker, ams_registry_shared *shared,
                            uint64_t seconds);
#endif
