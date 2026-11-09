"""Canonical allocator state, generation reuse and bounded search; no oracle."""
import ctypes as C
from pathlib import Path
import subprocess
import tempfile
import unittest
import struct


class Registry(C.Structure):
    _fields_ = [('generation', C.c_uint32 * 1024)]


class Search(C.Structure):
    _fields_ = [(n, C.c_uint32) for n in ('candidate', 'probes', 'slot', 'handle', 'status')]


class Buffer(C.Structure):
    _fields_ = [('address', C.c_uint64), ('data', C.c_void_p), ('size', C.c_size_t)]


Free = C.CFUNCTYPE(None, C.c_void_p, C.c_uint64)


class Shared(C.Structure):
    _fields_ = [('references', C.c_uint32), ('timestamp', C.c_uint64),
                ('baseline', C.c_uint64), ('counter', C.c_uint64)]


class Worker(C.Structure):
    _fields_ = [('wake_counter', C.c_uint64), ('active', C.c_uint)]


class RegistryTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.tmp = tempfile.TemporaryDirectory(prefix='ams-registry-test-')
        path = Path(cls.tmp.name) / 'registry.so'
        source = Path(__file__).resolve().parents[1] / 'src/apple_music_source/_native/registry.c'
        subprocess.run(['cc', '-std=c99', '-Wall', '-Wextra', '-Werror', '-shared',
                        '-fPIC', str(source), '-o', str(path)], check=True)
        cls.lib = C.CDLL(str(path))
        cls.lib.ams_registry_init.argtypes = [C.POINTER(Registry)]
        cls.lib.ams_registry_search_begin.argtypes = [C.POINTER(Search), C.c_uint32]
        cls.lib.ams_registry_reserve.argtypes = [C.POINTER(Registry), C.POINTER(Search), C.c_size_t]
        cls.lib.ams_registry_tag_matches.argtypes = [C.POINTER(Registry), C.c_uint32]
        cls.lib.ams_registry_release_unowned.argtypes = [C.POINTER(Registry), C.c_size_t, C.c_void_p, C.c_size_t]
        cls.lib.ams_registry_release_inline.argtypes = cls.lib.ams_registry_release_unowned.argtypes + [C.c_uint64]
        cls.lib.ams_registry_release_buffers.argtypes = cls.lib.ams_registry_release_inline.argtypes + [C.POINTER(Buffer), Free, C.c_void_p]
        cls.lib.ams_registry_shared_update.argtypes = [C.POINTER(Shared), C.c_uint64]
        cls.lib.ams_registry_release_shared.argtypes = cls.lib.ams_registry_release_buffers.argtypes + [C.POINTER(Shared), C.c_uint64]
        cls.lib.ams_registry_worker_begin.argtypes = [C.POINTER(Worker), C.POINTER(Shared)]
        cls.lib.ams_registry_worker_wake.argtypes = [C.POINTER(Worker), C.POINTER(Shared), C.c_uint64]

    @classmethod
    def tearDownClass(cls):
        cls.tmp.cleanup()

    def test_collision_chain_resumes_and_commits_once(self):
        registry, search = Registry(), Search()
        registry.generation[17:24] = range(1, 8)
        self.lib.ams_registry_search_begin(C.byref(search), 1041)
        before = bytes(registry)
        self.assertEqual(self.lib.ams_registry_reserve(C.byref(registry), C.byref(search), 0), 1)
        self.assertEqual(search.probes, 0)
        self.assertEqual(self.lib.ams_registry_reserve(C.byref(registry), C.byref(search), 7), 1)
        self.assertEqual((search.candidate, search.probes), (1048, 7))
        self.assertEqual(bytes(registry), before)
        self.assertEqual(self.lib.ams_registry_reserve(C.byref(registry), C.byref(search), 1), 0)
        self.assertEqual((search.candidate, search.probes, search.slot), (1048, 8, 24))
        self.assertEqual(registry.generation[24], 1048)
        terminal = bytes(registry), bytes(search)
        self.assertEqual(self.lib.ams_registry_reserve(C.byref(registry), C.byref(search), 1024), 0)
        self.assertEqual((bytes(registry), bytes(search)), terminal)

    def test_full_table_is_bounded_without_writes(self):
        registry, search = Registry(), Search()
        registry.generation[:] = [1] * 1024
        self.lib.ams_registry_search_begin(C.byref(search), 0xfffffffe)
        before = bytes(registry)
        self.assertEqual(self.lib.ams_registry_reserve(C.byref(registry), C.byref(search), 1023), 1)
        self.assertEqual(self.lib.ams_registry_reserve(C.byref(registry), C.byref(search), 1024), 2)
        self.assertEqual((search.candidate, search.probes), (1022, 1024))
        self.assertEqual(bytes(registry), before)

    def test_wrap_does_not_invent_a_zero_skip(self):
        registry, search = Registry(), Search()
        registry.generation[1023] = 1
        self.lib.ams_registry_search_begin(C.byref(search), 0xffffffff)
        self.assertEqual(self.lib.ams_registry_reserve(C.byref(registry), C.byref(search), 2), 0)
        self.assertEqual((search.candidate, search.slot, search.handle), (0, 0, 0x51dc9294))
        # The pre-codec check alone admits this default tag. It is not a valid
        # crypto-context test and must never be used as one by a session API.
        self.assertTrue(self.lib.ams_registry_tag_matches(C.byref(registry), search.handle))

    def test_generation_reuse_rejects_stale_handle(self):
        registry, search = Registry(), Search()
        self.lib.ams_registry_search_begin(C.byref(search), 7)
        self.assertEqual(self.lib.ams_registry_reserve(C.byref(registry), C.byref(search), 1), 0)
        old = search.handle
        self.assertTrue(self.lib.ams_registry_tag_matches(C.byref(registry), old))
        registry.generation[7] = 7 + 1024
        self.assertFalse(self.lib.ams_registry_tag_matches(C.byref(registry), old))
        self.assertTrue(self.lib.ams_registry_tag_matches(C.byref(registry), (7 + 1024) ^ 0x51dc9294))

    def test_invalid_or_overlapping_control_preserves_storage(self):
        registry, search = Registry(), Search()
        self.lib.ams_registry_search_begin(C.byref(search), 123)
        original = bytes(registry), bytes(search)
        self.assertEqual(self.lib.ams_registry_reserve(None, C.byref(search), 1), 3)
        self.assertEqual(self.lib.ams_registry_reserve(C.byref(registry), None, 1), 3)
        alias = C.cast(C.byref(registry), C.POINTER(Search))
        self.assertEqual(self.lib.ams_registry_reserve(C.byref(registry), alias, 1), 3)
        self.assertEqual((bytes(registry), bytes(search)), original)
        for probes, status in ((1025, 1), (1024, 1), (0, 4), (0, 0), (0, 2)):
            search.probes, search.status = probes, status
            before = bytes(registry), bytes(search)
            self.assertEqual(self.lib.ams_registry_reserve(C.byref(registry), C.byref(search), 1), 3)
            self.assertEqual((bytes(registry), bytes(search)), before)
        self.assertFalse(self.lib.ams_registry_tag_matches(None, 0))

    def test_explicit_initialization_clears_generations(self):
        registry = Registry()
        registry.generation[:] = [0xffffffff] * 1024
        self.lib.ams_registry_init(C.byref(registry))
        self.assertEqual(list(registry.generation), [0] * 1024)

    def test_release_rejects_old_generation_after_slot_reuse(self):
        registry, search = Registry(), Search()
        record = C.create_string_buffer(336)
        record[244] = 14
        self.lib.ams_registry_search_begin(C.byref(search), 7)
        self.assertEqual(self.lib.ams_registry_reserve(C.byref(registry), C.byref(search), 1), 0)
        old_handle = search.handle
        self.assertEqual(self.lib.ams_registry_release_unowned(C.byref(registry), 7, record, 336), 0)
        self.assertFalse(self.lib.ams_registry_tag_matches(C.byref(registry), old_handle))
        self.lib.ams_registry_search_begin(C.byref(search), 7 + 1024)
        self.assertEqual(self.lib.ams_registry_reserve(C.byref(registry), C.byref(search), 1), 0)
        self.assertFalse(self.lib.ams_registry_tag_matches(C.byref(registry), old_handle))
        self.assertTrue(self.lib.ams_registry_tag_matches(C.byref(registry), search.handle))

    def test_owned_record_requires_cleanup_before_tag_clear(self):
        registry = Registry(); registry.generation[10] = 1034
        record = C.create_string_buffer(336); record[244] = 15
        before = bytes(registry), record.raw
        self.assertEqual(self.lib.ams_registry_release_unowned(C.byref(registry), 10, record, 336), 2)
        self.assertEqual((bytes(registry), record.raw), before)

    def test_inline_cleanup_preserves_unrelated_fields_and_releases_once(self):
        registry = Registry(); registry.generation[10] = 1034
        payload = bytearray([0xa5] * 336); payload[244] = 15
        for offset in (0xb8, 0xc8, 0x110, 0x130):
            payload[offset:offset+8] = bytes(8)
        payload[0x12c] = 2
        record = C.create_string_buffer(bytes(payload))
        self.assertEqual(self.lib.ams_registry_release_inline(C.byref(registry), 10, record, 336, 0x1005fb8), 0)
        self.assertEqual(registry.generation[10], 0)
        self.assertEqual(record.raw[244], 14)
        self.assertEqual(record.raw[16:112], bytes(payload[16:112]))
        self.assertEqual(record.raw[176+4:184], bytes(payload[176+4:184]))
        self.assertEqual(record.raw[320:336], bytes(payload[320:336]))
        before = record.raw
        self.assertEqual(self.lib.ams_registry_release_inline(C.byref(registry), 10, C.c_void_p(1), 0, 0), 1)
        self.assertEqual(record.raw, before)

    def test_inline_cleanup_refuses_each_external_ownership_branch_atomically(self):
        for offset in (0xb8, 0xc8, 0x110, 0x130, 0x12c):
            registry = Registry(); registry.generation[10] = 1034
            payload = bytearray(336); payload[244] = 15
            payload[offset] = 3 if offset == 0x12c else 1
            record = C.create_string_buffer(bytes(payload))
            before = bytes(registry), record.raw
            self.assertEqual(self.lib.ams_registry_release_inline(C.byref(registry), 10, record, 336, 0), 2)
            self.assertEqual((bytes(registry), record.raw), before)

    def test_free_slot_does_not_read_record_and_null_release_is_idempotent(self):
        registry = Registry(); registry.generation[0] = 1024
        self.assertEqual(self.lib.ams_registry_release_unowned(C.byref(registry), 0, None, 0), 0)
        self.assertEqual(self.lib.ams_registry_release_unowned(C.byref(registry), 0, C.c_void_p(1), 0), 1)
        self.assertFalse(any(registry.generation))

    def test_release_bad_storage_and_aliases_preserve_registry(self):
        registry = Registry(); registry.generation[0] = 1024
        record = C.create_string_buffer(336)
        before = bytes(registry)
        for slot, pointer, size in ((1024, None, 0), (0, record, 335), (0, C.byref(registry), 336)):
            self.assertEqual(self.lib.ams_registry_release_unowned(C.byref(registry), slot, pointer, size), 3)
            self.assertEqual(bytes(registry), before)
        self.assertEqual(self.lib.ams_registry_release_unowned(None, 0, None, 0), 3)

    def owned_fixture(self):
        registry = Registry(); registry.generation[10] = 1034
        payload = bytearray(336); payload[244] = 15; payload[300] = 2
        blocks = [C.create_string_buffer(bytes([0xa5]) * 64) for _ in range(4)]
        views = (Buffer * 4)()
        for i, offset in enumerate((0x110, 0xb8, 0xc8, 0x130)):
            address = 0x5000 + 0x100 * i
            struct.pack_into('<Q', payload, offset, address)
            views[i] = Buffer(address, C.cast(blocks[i], C.c_void_p), 64)
        struct.pack_into('<I', payload, 0xd0, 0x193931bf + 17)
        record = C.create_string_buffer(bytes(payload))
        calls = []
        callback = Free(lambda _opaque, address: calls.append(address))
        return registry, record, blocks, views, calls, callback

    def test_buffer_cleanup_releases_once_in_order_and_bounds_the_overwrite(self):
        registry, record, blocks, views, calls, callback = self.owned_fixture()
        self.assertEqual(self.lib.ams_registry_release_buffers(C.byref(registry), 10, record, 336, 0x1005fb8, views, callback, None), 0)
        self.assertEqual(calls, [v.address for v in views])
        for i in (0, 1, 3): self.assertEqual(blocks[i].raw[:64], bytes([0xa5]) * 64)
        self.assertNotEqual(blocks[2].raw[:17], bytes([0xa5]) * 17)
        self.assertEqual(blocks[2].raw[17:64], bytes([0xa5]) * 47)
        for offset in (0x110, 0xb8, 0xc8, 0x130):
            self.assertEqual(record.raw[offset:offset+8], bytes(8))
        self.assertEqual(self.lib.ams_registry_release_buffers(C.byref(registry), 10, C.c_void_p(1), 0, 0, None, Free(), None), 1)
        self.assertEqual(len(calls), 4)

    def test_buffer_cleanup_preflights_lengths_and_allocator_without_mutation(self):
        for failure in ('short', 'wrapped_length', 'allocator', 'missing'):
            registry, record, blocks, views, calls, callback = self.owned_fixture()
            if failure == 'short': views[2].size = 16
            if failure == 'wrapped_length':
                C.memmove(C.addressof(record) + 0xd0, struct.pack('<I', 0x193931be), 4)
            before = bytes(registry), record.raw, [b.raw for b in blocks]
            self.assertEqual(self.lib.ams_registry_release_buffers(C.byref(registry), 10, record, 336, 0,
                None if failure == 'missing' else views, Free() if failure == 'allocator' else callback, None), 3)
            self.assertEqual((bytes(registry), record.raw, [b.raw for b in blocks]), before)
            self.assertEqual(calls, [])

    def test_buffer_cleanup_rejects_duplicate_or_overlapping_ownership(self):
        for failure in ('record', 'registry', 'views', 'duplicate_data', 'virtual_overlap', 'address_overflow'):
            registry, record, blocks, views, calls, callback = self.owned_fixture()
            if failure == 'record': views[2].data = C.addressof(record)
            if failure == 'registry': views[2].data = C.addressof(registry)
            if failure == 'views': views[2].data = C.addressof(views)
            if failure == 'duplicate_data': views[2].data = views[0].data
            if failure == 'virtual_overlap':
                views[2].address = views[0].address + 1
                C.memmove(C.addressof(record) + 0xc8, struct.pack('<Q', views[2].address), 8)
            if failure == 'address_overflow':
                views[2].address = 2**64 - 1
                C.memmove(C.addressof(record) + 0xc8, struct.pack('<Q', views[2].address), 8)
            before = bytes(registry), record.raw, [b.raw for b in blocks]
            self.assertEqual(self.lib.ams_registry_release_buffers(C.byref(registry), 10, record, 336, 0, views, callback, None), 3)
            self.assertEqual((bytes(registry), record.raw, [b.raw for b in blocks]), before)
            self.assertEqual(calls, [])

    def test_shared_mode_refuses_before_releasing_external_buffers(self):
        registry, record, blocks, views, calls, callback = self.owned_fixture()
        record[300] = 3
        before = bytes(registry), record.raw, [b.raw for b in blocks]
        self.assertEqual(self.lib.ams_registry_release_buffers(C.byref(registry), 10, record, 336, 0, views, callback, None), 2)
        self.assertEqual((bytes(registry), record.raw, [b.raw for b in blocks]), before)
        self.assertEqual(calls, [])

    def test_shared_clock_initial_backward_equal_and_reference_floor(self):
        state = Shared(1, 0, 100, 104)
        self.assertEqual(self.lib.ams_registry_shared_update(C.byref(state), 10), 0)
        self.assertEqual((state.references, state.timestamp, state.counter), (0, 10, 104))
        for now in (9, 10, 13, 14):
            self.assertEqual(self.lib.ams_registry_shared_update(C.byref(state), now), 0)
            self.assertEqual((state.references, state.timestamp, state.counter), (0, 10, 104))
        self.assertEqual(self.lib.ams_registry_shared_update(C.byref(state), 15), 0)
        self.assertEqual((state.timestamp, state.baseline, state.counter), (10, 100, 105))
        self.assertEqual(self.lib.ams_registry_shared_update(None, 0), 3)

    def test_shared_counter_preserves_unsigned_wrap_semantics(self):
        state = Shared(0xffffffff, 1, 2**64 - 2, 2**64 - 1)
        self.assertEqual(self.lib.ams_registry_shared_update(C.byref(state), 4), 0)
        self.assertEqual((state.references, state.counter), (0xfffffffe, 1))
        # A wrapped current-minus-baseline is a large unsigned interval; it
        # must not be treated as a negative value and overwritten.
        state = Shared(0, 1, 100, 99)
        self.lib.ams_registry_shared_update(C.byref(state), 2)
        self.assertEqual(state.counter, 99)

    def test_shared_release_updates_after_buffer_callbacks_and_accepts_absent_object(self):
        for present in (True, False):
            registry, record, blocks, views, calls, _callback = self.owned_fixture()
            record[300] = 3
            state = Shared(2, 10, 100, 100); observations = []
            @Free
            def callback(_opaque, address):
                calls.append(address)
                observations.append((record.raw[300], state.references, registry.generation[10]))
            self.assertEqual(self.lib.ams_registry_release_shared(C.byref(registry), 10, record, 336, 0,
                views, callback, None, C.byref(state) if present else None, 12), 0)
            self.assertEqual(observations, [(2, 2, 1034)] * 4)
            self.assertEqual((state.references, state.counter), (1, 102) if present else (2, 100))
            self.assertEqual(registry.generation[10], 0)

    def test_shared_state_aliases_refuse_before_any_cleanup(self):
        for target in ('record', 'registry', 'buffer', 'mappings'):
            registry, record, blocks, views, calls, callback = self.owned_fixture()
            record[300] = 3
            address = {'record': C.addressof(record), 'registry': C.addressof(registry),
                       'buffer': C.addressof(blocks[2]), 'mappings': C.addressof(views)}[target]
            state = C.cast(address, C.POINTER(Shared))
            before = bytes(registry), record.raw, [b.raw for b in blocks], bytes(views)
            self.assertEqual(self.lib.ams_registry_release_shared(C.byref(registry), 10, record, 336, 0,
                views, callback, None, state, 12), 3)
            self.assertEqual((bytes(registry), record.raw, [b.raw for b in blocks], bytes(views)), before)
            self.assertEqual(calls, [])

    def test_worker_takes_reference_clamps_wake_counter_and_stops_once(self):
        state, worker = Shared(0, 10, 100, 100), Worker(105, 0)
        self.assertEqual(self.lib.ams_registry_worker_begin(C.byref(worker), C.byref(state)), 1)
        self.assertEqual((state.references, worker.active), (1, 1))
        before = bytes(state), bytes(worker)
        self.assertEqual(self.lib.ams_registry_worker_begin(C.byref(worker), C.byref(state)), 3)
        self.assertEqual((bytes(state), bytes(worker)), before)
        self.assertEqual(self.lib.ams_registry_worker_wake(C.byref(worker), C.byref(state), 11), 0)
        self.assertEqual((state.references, state.counter, worker.wake_counter, worker.active), (0, 105, 110, 0))
        before = bytes(state), bytes(worker)
        self.assertEqual(self.lib.ams_registry_worker_wake(C.byref(worker), C.byref(state), 20), 3)
        self.assertEqual((bytes(state), bytes(worker)), before)

    def test_worker_remains_while_other_owner_exists_then_releases(self):
        state, worker = Shared(1, 10, 100, 100), Worker(105, 0)
        self.lib.ams_registry_worker_begin(C.byref(worker), C.byref(state))
        self.assertEqual(self.lib.ams_registry_worker_wake(C.byref(worker), C.byref(state), 15), 1)
        self.assertEqual((state.references, worker.active), (2, 1))
        self.lib.ams_registry_shared_update(C.byref(state), 16)
        self.assertEqual(state.references, 1)
        self.assertEqual(self.lib.ams_registry_worker_wake(C.byref(worker), C.byref(state), 20), 0)
        self.assertEqual((state.references, state.counter, worker.wake_counter), (0, 110, 115))

    def test_worker_preserves_original_reference_wrap_and_alias_guards(self):
        state, worker = Shared(0xffffffff, 10, 100, 100), Worker(105, 0)
        self.lib.ams_registry_worker_begin(C.byref(worker), C.byref(state))
        self.assertEqual(state.references, 0)
        self.assertEqual(self.lib.ams_registry_worker_wake(C.byref(worker), C.byref(state), 15), 0)
        self.assertEqual(state.references, 0xffffffff)
        alias = C.cast(C.byref(state), C.POINTER(Worker)); before = bytes(state)
        self.assertEqual(self.lib.ams_registry_worker_begin(alias, C.byref(state)), 3)
        self.assertEqual(self.lib.ams_registry_worker_wake(alias, C.byref(state), 15), 3)
        self.assertEqual(bytes(state), before)
