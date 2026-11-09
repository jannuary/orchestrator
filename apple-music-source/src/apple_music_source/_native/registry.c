#include "registry.h"
#include <string.h>

void ams_registry_init(ams_registry *r) {
    if (r) memset(r, 0, sizeof *r);
}

void ams_registry_search_begin(ams_registry_search *s, uint32_t candidate) {
    if (!s) return;
    memset(s, 0, sizeof *s);
    s->candidate = candidate;
    s->status = AMS_REGISTRY_MORE;
}

static int disjoint(const ams_registry *r, const ams_registry_search *s) {
    uintptr_t a = (uintptr_t)r, b = (uintptr_t)s;
    if (a > UINTPTR_MAX - sizeof *r || b > UINTPTR_MAX - sizeof *s) return 0;
    return a + sizeof *r <= b || b + sizeof *s <= a;
}

int ams_registry_reserve(ams_registry *r, ams_registry_search *s,
                         size_t quota) {
    if (!r || !s || !disjoint(r, s) || s->probes > AMS_REGISTRY_SLOTS ||
        s->status > AMS_REGISTRY_FULL) return AMS_REGISTRY_INVALID;
    if (s->status == AMS_REGISTRY_FOUND) {
        if (!s->probes || s->slot != (s->candidate & (AMS_REGISTRY_SLOTS - 1)) ||
            s->handle != (s->candidate ^ UINT32_C(0x51dc9294)) ||
            r->generation[s->slot] != s->candidate) return AMS_REGISTRY_INVALID;
        return AMS_REGISTRY_FOUND;
    }
    if (s->status == AMS_REGISTRY_FULL)
        return s->probes == AMS_REGISTRY_SLOTS ? AMS_REGISTRY_FULL : AMS_REGISTRY_INVALID;
    if (s->probes == AMS_REGISTRY_SLOTS) return AMS_REGISTRY_INVALID;
    while (quota && s->probes < AMS_REGISTRY_SLOTS) {
        uint32_t slot = s->candidate & (AMS_REGISTRY_SLOTS - 1);
        --quota;
        ++s->probes;
        if (!r->generation[slot]) {
            /* 0x207978..0x2079bb simplifies to these two operations.
             * Original tag: candidate + 0x69cad980 (modulo 2^32).
             * The canonical registry stores candidate directly. */
            r->generation[slot] = s->candidate;
            s->slot = slot;
            s->handle = s->candidate ^ UINT32_C(0x51dc9294);
            s->status = AMS_REGISTRY_FOUND;
            return AMS_REGISTRY_FOUND;
        }
        ++s->candidate;
    }
    if (s->probes == AMS_REGISTRY_SLOTS) s->status = AMS_REGISTRY_FULL;
    return (int)s->status;
}

int ams_registry_tag_matches(const ams_registry *r, uint32_t handle) {
    uint32_t slot = (handle & (AMS_REGISTRY_SLOTS - 1)) ^ UINT32_C(0x294);
    return r && r->generation[slot] == (handle ^ UINT32_C(0x51dc9294));
}

int ams_registry_release_unowned(ams_registry *r, size_t slot,
                                const void *record, size_t record_size) {
    uintptr_t a, b;
    const unsigned char *bytes = record;
    if (!r || slot >= AMS_REGISTRY_SLOTS) return AMS_REGISTRY_RELEASE_INVALID;
    if (!r->generation[slot]) return AMS_REGISTRY_ALREADY_FREE;
    if (record) {
        a = (uintptr_t)r; b = (uintptr_t)record;
        if (record_size < AMS_REGISTRY_RECORD_SIZE ||
            a > UINTPTR_MAX - sizeof *r ||
            b > UINTPTR_MAX - AMS_REGISTRY_RECORD_SIZE ||
            (a < b + AMS_REGISTRY_RECORD_SIZE && b < a + sizeof *r))
            return AMS_REGISTRY_RELEASE_INVALID;
        if (bytes[AMS_REGISTRY_RECORD_KIND_OFFSET] == AMS_REGISTRY_OWNED_RECORD_KIND)
            return AMS_REGISTRY_NEEDS_RECORD_CLEANUP;
    }
    r->generation[slot] = 0;
    return AMS_REGISTRY_RELEASED;
}

static void put_le(unsigned char *p, uint64_t value, unsigned width) {
    unsigned i;
    for (i = 0; i < width; ++i) p[i] = (unsigned char)(value >> (8 * i));
}

static int nonzero_pointer(const unsigned char *p) {
    unsigned i;
    for (i = 0; i < 8; ++i) if (p[i]) return 1;
    return 0;
}

static uint64_t get_le(const unsigned char *p, unsigned width) {
    uint64_t value = 0;
    unsigned i;
    for (i = 0; i < width; ++i) value |= (uint64_t)p[i] << (8 * i);
    return value;
}

/* 0x48430b..0x484355 produces the first counter from a scratch address;
 * 0x1b6cf0..0x1b6d60 overwrites in reverse address order. These are unsigned
 * arithmetic operations, including their original 32- and 8-bit truncations.
 * This is the original overwrite pattern, not a secure-erasure guarantee.
 */
static void overwrite(unsigned char *p, size_t n, uint64_t scratch) {
    uint64_t index = (UINT64_C(0x6fbf7bfffff563af) ^ scratch) +
        2 * (UINT64_C(0xefbf7bfffff563a8) & scratch) +
        UINT64_C(0x9c57d7ef7eafdce0);
    while (n) {
        uint32_t a = UINT32_C(0x815abf71) + (uint32_t)index++;
        uint32_t b = a ^ UINT32_C(0xba);
        uint32_t c = (2 * b) & UINT32_C(0x6a79980e);
        uint32_t value;
        b = ((b + UINT32_C(0x353ccc07)) - c) ^ UINT32_C(0x353ccc07);
        value = (a + UINT32_C(0x11)) * b;
        value -= 2 * (value & UINT32_C(0x7e));
        p[--n] = (unsigned char)((unsigned char)(value + 0xfe) ^ 0xfe);
    }
}

static void reset_before_buffers(unsigned char *p, uint64_t scratch) {
    overwrite(p, 16, scratch);
    overwrite(p + 0xdc, 16, scratch);
    put_le(p + 0xf0, UINT32_C(0x51dc9294), 4);
    p[0xf4] = 14;
    put_le(p + 0xec, UINT32_C(0x19ab30bc), 4);
    put_le(p + 0xd8, UINT32_C(0x19ab30bc), 4);
    put_le(p + 0x100, UINT64_C(0x2fbd14c0f84e6711), 8);
    put_le(p + 0x120, UINT64_C(0x289739e7b0a5ee06), 8);
    put_le(p + 0x128, UINT32_C(0xb82a9bdf), 4);
}

int ams_registry_release_inline(ams_registry *r, size_t slot,
                               void *record, size_t record_size,
                               uint64_t scratch_address) {
    unsigned char *p = record;
    int status = ams_registry_release_unowned(r, slot, record, record_size);
    if (status != AMS_REGISTRY_NEEDS_RECORD_CLEANUP) return status;
    /* Validate every unsupported ownership branch before mutating anything. */
    if (p[0x12c] == 3 || nonzero_pointer(p + 0xb8) ||
        nonzero_pointer(p + 0xc8) || nonzero_pointer(p + 0x110) ||
        nonzero_pointer(p + 0x130)) return status;
    reset_before_buffers(p, scratch_address);
    overwrite(p + 0x70, 64, scratch_address);
    put_le(p + 0x118, UINT32_C(0x0e1a8a2a), 4);
    put_le(p + 0xb0, UINT32_C(0x6690a63a), 4);
    put_le(p + 0xd4, UINT32_C(0x19ab30bc), 4);
    put_le(p + 0x138, UINT32_C(0x56b7ec5f), 4);
    r->generation[slot] = 0;
    return AMS_REGISTRY_RELEASED;
}

static int regions_overlap(const void *left, size_t left_size,
                           const void *right, size_t right_size) {
    uintptr_t a = (uintptr_t)left, b = (uintptr_t)right;
    /* Include an address even for zero-capacity owned allocations. */
    if (!left_size) left_size = 1;
    if (!right_size) right_size = 1;
    if (a > UINTPTR_MAX - left_size || b > UINTPTR_MAX - right_size) return 1;
    return a < b + right_size && b < a + left_size;
}

static void update_clock(ams_registry_shared *s, uint64_t seconds) {
    uint64_t elapsed;
    if (!s->timestamp) s->timestamp = seconds;
    if (seconds > s->timestamp) {
        elapsed = seconds - s->timestamp;
        if (elapsed > s->counter - s->baseline)
            s->counter = s->baseline + elapsed;
    }
}

int ams_registry_shared_update(ams_registry_shared *s, uint64_t seconds) {
    if (!s || (uintptr_t)s > UINTPTR_MAX - sizeof *s) return AMS_REGISTRY_RELEASE_INVALID;
    if (s->references) --s->references;
    update_clock(s, seconds);
    return AMS_REGISTRY_RELEASED;
}

int ams_registry_worker_begin(ams_registry_worker *w, ams_registry_shared *s) {
    if (!w || !s || regions_overlap(w, sizeof *w, s, sizeof *s) || w->active)
        return AMS_REGISTRY_WORKER_INVALID;
    ++s->references;
    w->active = 1;
    return AMS_REGISTRY_WORKER_SLEEP;
}

int ams_registry_worker_wake(ams_registry_worker *w, ams_registry_shared *s,
                            uint64_t seconds) {
    if (!w || !s || regions_overlap(w, sizeof *w, s, sizeof *s) || w->active != 1)
        return AMS_REGISTRY_WORKER_INVALID;
    if (s->counter < w->wake_counter) s->counter = w->wake_counter;
    update_clock(s, seconds);
    w->wake_counter = s->counter + UINT64_C(5);
    if (s->references <= 1) {
        --s->references;
        w->active = 0;
        return AMS_REGISTRY_WORKER_STOP;
    }
    return AMS_REGISTRY_WORKER_SLEEP;
}

static int release_buffers(ams_registry *r, size_t slot,
                                void *record, size_t record_size,
                                uint64_t scratch_address,
                                const ams_registry_buffer buffers[4],
                                ams_registry_free_fn release, void *opaque,
                                int allow_shared, ams_registry_shared *shared, uint64_t seconds) {
    static const unsigned offsets[4] = {0x110, 0xb8, 0xc8, 0x130};
    ams_registry_buffer views[4];
    uint64_t addresses[4];
    unsigned char *p = record;
    size_t wipe_size;
    unsigned i, j, present = 0;
    int mode_shared;
    int status = ams_registry_release_unowned(r, slot, record, record_size);
    if (status != AMS_REGISTRY_NEEDS_RECORD_CLEANUP) return status;
    mode_shared = p[0x12c] == 3;
    if (mode_shared && !allow_shared) return status;
    if (mode_shared && shared &&
        (regions_overlap(shared, sizeof *shared, r, sizeof *r) ||
         regions_overlap(shared, sizeof *shared, record, AMS_REGISTRY_RECORD_SIZE)))
        return AMS_REGISTRY_RELEASE_INVALID;
    for (i = 0; i < 4; ++i) {
        addresses[i] = get_le(p + offsets[i], 8);
        if (addresses[i]) ++present;
    }
    if (present && (!buffers || !release ||
        regions_overlap(buffers, sizeof views, r, sizeof *r) ||
        regions_overlap(buffers, sizeof views, record, AMS_REGISTRY_RECORD_SIZE) ||
        (mode_shared && shared && regions_overlap(shared, sizeof *shared, buffers, sizeof views))))
        return AMS_REGISTRY_RELEASE_INVALID;
    memset(views, 0, sizeof views);
    if (present) memcpy(views, buffers, sizeof views);
    wipe_size = (uint32_t)((uint32_t)get_le(p + 0xd0, 4) - UINT32_C(0x193931bf));
    for (i = 0; i < 4; ++i) {
        if (!addresses[i]) continue;
        if (views[i].address != addresses[i] || !views[i].data ||
            (i == 2 && views[i].size < wipe_size) ||
            addresses[i] > UINT64_MAX - views[i].size ||
            regions_overlap(views[i].data, views[i].size, r, sizeof *r) ||
            regions_overlap(views[i].data, views[i].size, record, AMS_REGISTRY_RECORD_SIZE) ||
            regions_overlap(views[i].data, views[i].size, buffers, sizeof views) ||
            (mode_shared && shared && regions_overlap(views[i].data, views[i].size, shared, sizeof *shared)))
            return AMS_REGISTRY_RELEASE_INVALID;
        for (j = 0; j < i; ++j) if (addresses[j] &&
            (addresses[i] == addresses[j] ||
             regions_overlap(views[i].data, views[i].size, views[j].data, views[j].size) ||
             (addresses[i] < addresses[j] + views[j].size &&
              addresses[j] < addresses[i] + views[i].size)))
            return AMS_REGISTRY_RELEASE_INVALID;
    }
    reset_before_buffers(p, scratch_address);
    if (mode_shared) p[0x12c] = 2;
    if (addresses[0]) { release(opaque, addresses[0]); put_le(p + 0x110, 0, 8); }
    put_le(p + 0x118, UINT32_C(0x0e1a8a2a), 4);
    overwrite(p + 0x70, 64, scratch_address);
    if (addresses[1]) { release(opaque, addresses[1]); put_le(p + 0xb8, 0, 8); }
    put_le(p + 0xb0, UINT32_C(0x6690a63a), 4);
    put_le(p + 0xd4, UINT32_C(0x19ab30bc), 4);
    if (addresses[2]) {
        overwrite(views[2].data, wipe_size, scratch_address);
        release(opaque, addresses[2]);
        put_le(p + 0xc8, 0, 8);
        put_le(p + 0xd0, UINT32_C(0x193931bf), 4);
    }
    if (addresses[3]) { release(opaque, addresses[3]); put_le(p + 0x130, 0, 8); }
    put_le(p + 0x138, UINT32_C(0x56b7ec5f), 4);
    if (mode_shared && shared) ams_registry_shared_update(shared, seconds);
    r->generation[slot] = 0;
    return AMS_REGISTRY_RELEASED;
}

int ams_registry_release_buffers(ams_registry *r, size_t slot,
                                void *record, size_t record_size,
                                uint64_t scratch_address,
                                const ams_registry_buffer buffers[4],
                                ams_registry_free_fn release, void *opaque) {
    return release_buffers(r, slot, record, record_size, scratch_address,
                           buffers, release, opaque, 0, NULL, 0);
}

int ams_registry_release_shared(ams_registry *r, size_t slot,
                               void *record, size_t record_size,
                               uint64_t scratch_address,
                               const ams_registry_buffer buffers[4],
                               ams_registry_free_fn release, void *opaque,
                               ams_registry_shared *shared, uint64_t seconds) {
    return release_buffers(r, slot, record, record_size, scratch_address,
                           buffers, release, opaque, 1, shared, seconds);
}
