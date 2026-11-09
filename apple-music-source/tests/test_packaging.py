"""Build, inspect, install, and smoke-test the package outside the checkout."""
import json
import os
from pathlib import Path
import subprocess
import sys
import tarfile
import tempfile
import unittest
import zipfile

import _support  # noqa: F401

ROOT = Path(__file__).resolve().parents[1]
DIST_INFO = "apple_music_source-0.1.0.dist-info"
WHEEL = "apple_music_source-0.1.0-py3-none-linux_x86_64.whl"
SDIST = "apple-music-source-0.1.0.tar.gz"

sys.path.insert(0, str(ROOT))
import build_backend  # noqa: E402


def _run(command, **kwargs):
    return subprocess.run(command, check=True, capture_output=True, text=True, **kwargs)


class PackagingTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls._temporary = tempfile.TemporaryDirectory(prefix="apple-music-source-dist-")
        cls.directory = Path(cls._temporary.name)
        cls.wheel = cls.directory / build_backend.build_wheel(cls.directory)
        cls.sdist = cls.directory / build_backend.build_sdist(cls.directory)

    @classmethod
    def tearDownClass(cls):
        cls._temporary.cleanup()

    def test_wheel_contents_are_package_owned(self):
        with zipfile.ZipFile(self.wheel) as archive:
            names = archive.namelist()
            records = archive.read(f"{DIST_INFO}/RECORD").decode("ascii").splitlines()
            wheel_meta = archive.read(f"{DIST_INFO}/WHEEL").decode("ascii")
            metadata = archive.read(f"{DIST_INFO}/METADATA").decode("utf-8")
        self.assertIn("apple_music_source/_native/libcorelskd_r1.so", names)
        native_files = [name for name in names if "/_native/" in name]
        self.assertEqual(len(native_files), 4)
        self.assertTrue(all(name.endswith(".so") for name in native_files))
        self.assertIn("apple_music_source/crypto/aes.py", names)
        self.assertIn("apple_music_source/crypto/masked_cbc.py", names)
        self.assertIn("apple_music_source/auth/login_client.py", names)
        self.assertIn("apple_music_source/py.typed", names)
        self.assertFalse([n for n in names if "__pycache__" in n or n.endswith(".pyc")])
        self.assertFalse([n for n in names if "wrapper" in n.lower()])
        self.assertFalse([n for n in names if n.endswith(".o")])
        self.assertIn("Tag: py3-none-linux_x86_64", wheel_meta)
        self.assertIn("Name: apple-music-source", metadata)
        self.assertIn("Requires-Python: >=3.10", metadata)
        self.assertTrue(records[-1].startswith(f"{DIST_INFO}/RECORD,,"))
        for line in records[:-1]:
            self.assertRegex(line, r"^[^,]+,[a-z0-9]+=.*,\d+$")

    def test_sdist_is_source_only(self):
        with tarfile.open(self.sdist) as archive:
            names = archive.getnames()
        self.assertIn(f"apple-music-source-0.1.0/pyproject.toml", names)
        self.assertIn(f"apple-music-source-0.1.0/build_backend.py", names)
        self.assertIn(
            "apple-music-source-0.1.0/src/apple_music_source/_native/corelskd_r1.c",
            names,
        )
        self.assertIn(
            "apple-music-source-0.1.0/src/apple_music_source/crypto/aes.py", names)
        self.assertIn("apple-music-source-0.1.0/tests/test_aes.py", names)
        self.assertFalse([n for n in names if n.endswith((".so", ".o", ".pyc"))])

    def test_install_and_import_outside_the_checkout(self):
        target = self.directory / "installed"
        _run([sys.executable, "-m", "pip", "install", "--no-index", "--no-deps",
              "--target", str(target), str(self.wheel)])
        script = r"""
import ctypes, json, math, sys
from pathlib import Path
import apple_music_source as pkg
from apple_music_source.crypto import AES, MaskedCBC, CoreLSKD, CoreLSKDError, SPCV2, CryptoPrimitives

masked = MaskedCBC(bytes(16), bytes(range(16)), bytes(range(16, 32)))
assert masked.decrypt(masked.encrypt(bytes(48), bytes(16)), bytes(16)) == bytes(48)

assert pkg.__version__ == "0.1.0", pkg.__version__
native = ctypes.CDLL(str(Path(pkg.__file__).parent / "_native/libcorelskd_r1.so"))
auth_word = native.ams_auth_word_decode
auth_word.argtypes = [ctypes.c_uint, ctypes.c_uint32, ctypes.POINTER(ctypes.c_uint32)]
auth_word.restype = ctypes.c_int
auth_output = ctypes.c_uint32(0x12345678)
assert auth_word(5, 0, ctypes.byref(auth_output)) == 0 and auth_output.value == 0x12345678
assert all(auth_word(kind, 0, ctypes.byref(auth_output)) == 1 for kind in range(5))
copy0_byte = native.ams_copy0_byte
copy0_byte.argtypes = [ctypes.c_uint32, ctypes.c_uint8, ctypes.c_uint8]
copy0_byte.restype = ctypes.c_uint8
assert copy0_byte(0, 0, 0) == 0xaa
copy_byte = native.ams_copy1_byte
copy_byte.argtypes = [ctypes.c_uint32, ctypes.c_uint8, ctypes.c_uint8]
copy_byte.restype = ctypes.c_uint8
assert copy_byte(0, 0, 0) == 0xec
read = native.ams_fill_dispatch_read
read.argtypes = [ctypes.c_uint64, ctypes.c_uint, ctypes.POINTER(ctypes.c_uint64)]
word = ctypes.c_uint64()
assert read(0x525a3c, 4, ctypes.byref(word)) == 1
assert 0x525a3c + ctypes.c_int32(word.value).value == 0x42cff9
codec_read = native.ams_integrity_codec_data_read
codec_read.argtypes = [ctypes.c_uint64, ctypes.c_uint, ctypes.POINTER(ctypes.c_uint64)]
assert codec_read(0x25c0, 4, ctypes.byref(word)) == 1
assert word.value * 16777619 % (2**32) == 1
control_read = native.ams_control_refs_read
control_read.argtypes = [ctypes.c_uint64, ctypes.c_uint, ctypes.POINTER(ctypes.c_uint64)]
assert control_read(0x10013a34, 4, ctypes.byref(word)) == 1
assert 0x101a09eb + ctypes.c_int32(word.value).value == 0x101a0a0b
word.value = 0x12345678
assert control_read(0, 1, ctypes.byref(word)) == 0 and word.value == 0x12345678
class SourceBinding(ctypes.Structure):
    _fields_ = [("name", ctypes.c_char_p), ("address", ctypes.c_uint64)]
initial_read = native.ams_abi_initial_read
initial_read.argtypes = [ctypes.c_uint64, ctypes.c_uint, ctypes.POINTER(SourceBinding), ctypes.c_size_t, ctypes.POINTER(ctypes.c_uint64)]
assert initial_read(0x10693000, 8, None, 0, ctypes.byref(word)) == 1 and word.value == 0
bindings = (SourceBinding * 1)(SourceBinding(b"malloc", 0x700010))
assert initial_read(0x5f27f0, 8, bindings, 1, ctypes.byref(word)) == 1 and word.value == 0x700010
word.value = 0x12345678
assert initial_read(0x10690068, 8, None, 0, ctypes.byref(word)) == 0 and word.value == 0x12345678
class Registry(ctypes.Structure):
    _fields_ = [("generation", ctypes.c_uint32 * 1024)]
class Search(ctypes.Structure):
    _fields_ = [(n, ctypes.c_uint32) for n in ("candidate", "probes", "slot", "handle", "status")]
reserve = native.ams_registry_reserve
reserve.argtypes = [ctypes.POINTER(Registry), ctypes.POINTER(Search), ctypes.c_size_t]
native.ams_registry_search_begin.argtypes = [ctypes.POINTER(Search), ctypes.c_uint32]
native.ams_registry_tag_matches.argtypes = [ctypes.POINTER(Registry), ctypes.c_uint32]
registry, search = Registry(), Search()
native.ams_registry_search_begin(ctypes.byref(search), 34)
assert reserve(ctypes.byref(registry), ctypes.byref(search), 1) == 0
assert registry.generation[34] == 34 and search.handle == 34 ^ 0x51dc9294
assert native.ams_registry_tag_matches(ctypes.byref(registry), search.handle) == 1
registry.generation[34] += 1024
assert native.ams_registry_tag_matches(ctypes.byref(registry), search.handle) == 0
release = native.ams_registry_release_inline
release.argtypes = [ctypes.POINTER(Registry), ctypes.c_size_t, ctypes.c_void_p, ctypes.c_size_t, ctypes.c_uint64]
record = ctypes.create_string_buffer(336)
record[244] = 15
assert release(ctypes.byref(registry), 34, record, 336, 0x1005fb8) == 0
assert registry.generation[34] == 0 and record.raw[244] == 14
class Buffer(ctypes.Structure):
    _fields_ = [("address", ctypes.c_uint64), ("data", ctypes.c_void_p), ("size", ctypes.c_size_t)]
Free = ctypes.CFUNCTYPE(None, ctypes.c_void_p, ctypes.c_uint64)
release_buffers = native.ams_registry_release_buffers
release_buffers.argtypes = [ctypes.POINTER(Registry), ctypes.c_size_t, ctypes.c_void_p, ctypes.c_size_t, ctypes.c_uint64, ctypes.POINTER(Buffer), Free, ctypes.c_void_p]
registry.generation[34] = 1058
record[244] = 15
record[300] = 2
external = ctypes.create_string_buffer(bytes([0xa5]) * 64)
views = (Buffer * 4)()
views[2] = Buffer(0x7000, ctypes.cast(external, ctypes.c_void_p), 64)
ctypes.memmove(ctypes.addressof(record) + 0xc8, (0x7000).to_bytes(8, "little"), 8)
ctypes.memmove(ctypes.addressof(record) + 0xd0, (0x193931bf + 17).to_bytes(4, "little"), 4)
calls = []
callback = Free(lambda _opaque, address: calls.append(address))
assert release_buffers(ctypes.byref(registry), 34, record, 336, 0x1005fb8, views, callback, None) == 0
assert calls == [0x7000] and registry.generation[34] == 0
assert external.raw[17:64] == bytes([0xa5]) * 47
class Shared(ctypes.Structure):
    _fields_ = [("references", ctypes.c_uint32), ("timestamp", ctypes.c_uint64), ("baseline", ctypes.c_uint64), ("counter", ctypes.c_uint64)]
release_shared = native.ams_registry_release_shared
release_shared.argtypes = release_buffers.argtypes + [ctypes.POINTER(Shared), ctypes.c_uint64]
state = Shared(1, 10, 100, 100)
registry.generation[34] = 1058
record[244] = 15
record[300] = 3
assert release_shared(ctypes.byref(registry), 34, record, 336, 0, None, Free(), None, ctypes.byref(state), 12) == 0
assert state.references == 0 and state.counter == 102 and record.raw[300] == 2
assert registry.generation[34] == 0
class Worker(ctypes.Structure):
    _fields_ = [("wake_counter", ctypes.c_uint64), ("active", ctypes.c_uint)]
native.ams_registry_worker_begin.argtypes = [ctypes.POINTER(Worker), ctypes.POINTER(Shared)]
native.ams_registry_worker_wake.argtypes = [ctypes.POINTER(Worker), ctypes.POINTER(Shared), ctypes.c_uint64]
worker = Worker(107, 0)
assert native.ams_registry_worker_begin(ctypes.byref(worker), ctypes.byref(state)) == 1
assert native.ams_registry_worker_wake(ctypes.byref(worker), ctypes.byref(state), 13) == 0
assert state.references == 0 and state.counter == 107 and worker.wake_counter == 112 and worker.active == 0
from apple_music_source.auth.mescal_source import SourceMescal
assert len(SourceMescal.guid_descriptor(b"0123456789abcdef", bytes.fromhex("001122334455"))) == 56
key = bytes.fromhex("000102030405060708090a0b0c0d0e0f")
block = bytes.fromhex("00112233445566778899aabbccddeeff")
assert AES(key).encrypt_block(block).hex() == "69c4e0d86a7b0430d8cdb78070b4c55a"
envelope = SPCV2(bytes(16), bytes(256), bytes(20), bytes(16))
assert SPCV2.parse(envelope.pack()) == envelope
assert len(CryptoPrimitives().dispatch("finalize", 1).arguments) == 192
core = CoreLSKD()
assert core.block(bytes(0x8000), bytes(0x2100), 0, 0, bytes(16)) == bytes([0x76]) * 16
try:
    core.extract_key(bytes(0x8000), bytes(0x2100), 0, 0)
except CoreLSKDError:
    pass
else:
    raise AssertionError("synthetic key extraction must fail closed")
import apple_music_source.auth as auth
assert hasattr(auth, "LoginClient") and hasattr(auth, "AdiProvisioning")
assert callable(auth.establish_signer)
print(json.dumps({"file": pkg.__file__, "capabilities": len(pkg.CAPABILITIES)}))
"""
        environment = dict(os.environ)
        environment["PYTHONPATH"] = str(target)
        # Run from a directory that contains neither the package source nor the
        # wrapper checkout, so an accidental relative fallback cannot succeed.
        outside = self.directory / "outside"
        outside.mkdir()
        completed = _run([sys.executable, "-c", script], cwd=outside, env=environment)
        result = json.loads(completed.stdout.strip().splitlines()[-1])
        self.assertTrue(result["file"].startswith(str(target)), result["file"])
        self.assertGreater(result["capabilities"], 5)
        self.assertNotIn(str(ROOT), result["file"])

    def test_build_and_install_from_sdist_outside_checkout(self):
        extracted = self.directory / "sdist-extracted"
        extracted.mkdir()
        with tarfile.open(self.sdist) as archive:
            # All members were produced by this backend, no untrusted archive.
            archive.extractall(extracted, filter="data")
        source = extracted / "apple-music-source-0.1.0"
        target = self.directory / "sdist-installed"
        environment = dict(os.environ)
        environment.pop("APPLE_MUSIC_SOURCE_CORELSKD_LIB", None)
        environment.pop("PYTHONPATH", None)
        _run([sys.executable, "-m", "pip", "install", "--no-index", "--no-deps",
              "--no-build-isolation", "--target", str(target), str(source)],
             cwd=extracted, env=environment)
        environment["PYTHONPATH"] = str(target)
        script = '''
import sys
blocked = sys.argv[1]
def guard(event, args):
    if event.startswith("socket."):
        raise AssertionError("offline test attempted networking")
    if event == "open" and isinstance(args[0], str) and args[0].startswith(blocked):
        raise AssertionError("installed package accessed checkout")
sys.addaudithook(guard)
from apple_music_source.crypto import SPCV2, CryptoPrimitives, AES
from apple_music_source import __file__ as package_file
import ctypes
from pathlib import Path
native = ctypes.CDLL(str(Path(package_file).parent / "_native/libcorelskd_r1.so"))
auth_word = native.ams_auth_word_decode
auth_word.argtypes = [ctypes.c_uint, ctypes.c_uint32, ctypes.POINTER(ctypes.c_uint32)]
auth_word.restype = ctypes.c_int
auth_output = ctypes.c_uint32(0x12345678)
assert auth_word(5, 0, ctypes.byref(auth_output)) == 0 and auth_output.value == 0x12345678
assert all(auth_word(kind, 0, ctypes.byref(auth_output)) == 1 for kind in range(5))
copy0_byte = native.ams_copy0_byte
copy0_byte.argtypes = [ctypes.c_uint32, ctypes.c_uint8, ctypes.c_uint8]
copy0_byte.restype = ctypes.c_uint8
assert copy0_byte(0, 0, 0) == 0xaa
copy_byte = native.ams_copy1_byte
copy_byte.argtypes = [ctypes.c_uint32, ctypes.c_uint8, ctypes.c_uint8]
copy_byte.restype = ctypes.c_uint8
assert copy_byte(0, 0, 0) == 0xec
read = native.ams_fill_dispatch_read
read.argtypes = [ctypes.c_uint64, ctypes.c_uint, ctypes.POINTER(ctypes.c_uint64)]
word = ctypes.c_uint64()
assert read(0x525a00, 4, ctypes.byref(word)) == 1
assert 0x525a00 + ctypes.c_int32(word.value).value == 0x42cf27
codec_read = native.ams_integrity_codec_data_read
codec_read.argtypes = [ctypes.c_uint64, ctypes.c_uint, ctypes.POINTER(ctypes.c_uint64)]
assert codec_read(0x25c0, 4, ctypes.byref(word)) == 1
assert word.value * 16777619 % (2**32) == 1
control_read = native.ams_control_refs_read
control_read.argtypes = [ctypes.c_uint64, ctypes.c_uint, ctypes.POINTER(ctypes.c_uint64)]
assert control_read(0x10013a34, 4, ctypes.byref(word)) == 1
assert 0x101a09eb + ctypes.c_int32(word.value).value == 0x101a0a0b
word.value = 0x12345678
assert control_read(0, 1, ctypes.byref(word)) == 0 and word.value == 0x12345678
class SourceBinding(ctypes.Structure):
    _fields_ = [("name", ctypes.c_char_p), ("address", ctypes.c_uint64)]
initial_read = native.ams_abi_initial_read
initial_read.argtypes = [ctypes.c_uint64, ctypes.c_uint, ctypes.POINTER(SourceBinding), ctypes.c_size_t, ctypes.POINTER(ctypes.c_uint64)]
assert initial_read(0x10693000, 8, None, 0, ctypes.byref(word)) == 1 and word.value == 0
bindings = (SourceBinding * 1)(SourceBinding(b"malloc", 0x700010))
assert initial_read(0x5f27f0, 8, bindings, 1, ctypes.byref(word)) == 1 and word.value == 0x700010
word.value = 0x12345678
assert initial_read(0x10690068, 8, None, 0, ctypes.byref(word)) == 0 and word.value == 0x12345678
class Registry(ctypes.Structure):
    _fields_ = [("generation", ctypes.c_uint32 * 1024)]
class Search(ctypes.Structure):
    _fields_ = [(n, ctypes.c_uint32) for n in ("candidate", "probes", "slot", "handle", "status")]
reserve = native.ams_registry_reserve
reserve.argtypes = [ctypes.POINTER(Registry), ctypes.POINTER(Search), ctypes.c_size_t]
native.ams_registry_search_begin.argtypes = [ctypes.POINTER(Search), ctypes.c_uint32]
native.ams_registry_tag_matches.argtypes = [ctypes.POINTER(Registry), ctypes.c_uint32]
registry, search = Registry(), Search()
native.ams_registry_search_begin(ctypes.byref(search), 34)
assert reserve(ctypes.byref(registry), ctypes.byref(search), 1) == 0
assert registry.generation[34] == 34 and search.handle == 34 ^ 0x51dc9294
assert native.ams_registry_tag_matches(ctypes.byref(registry), search.handle) == 1
registry.generation[34] += 1024
assert native.ams_registry_tag_matches(ctypes.byref(registry), search.handle) == 0
release = native.ams_registry_release_inline
release.argtypes = [ctypes.POINTER(Registry), ctypes.c_size_t, ctypes.c_void_p, ctypes.c_size_t, ctypes.c_uint64]
record = ctypes.create_string_buffer(336)
record[244] = 15
assert release(ctypes.byref(registry), 34, record, 336, 0x1005fb8) == 0
assert registry.generation[34] == 0 and record.raw[244] == 14
class Buffer(ctypes.Structure):
    _fields_ = [("address", ctypes.c_uint64), ("data", ctypes.c_void_p), ("size", ctypes.c_size_t)]
Free = ctypes.CFUNCTYPE(None, ctypes.c_void_p, ctypes.c_uint64)
release_buffers = native.ams_registry_release_buffers
release_buffers.argtypes = [ctypes.POINTER(Registry), ctypes.c_size_t, ctypes.c_void_p, ctypes.c_size_t, ctypes.c_uint64, ctypes.POINTER(Buffer), Free, ctypes.c_void_p]
registry.generation[34] = 1058
record[244] = 15
record[300] = 2
external = ctypes.create_string_buffer(bytes([0xa5]) * 64)
views = (Buffer * 4)()
views[2] = Buffer(0x7000, ctypes.cast(external, ctypes.c_void_p), 64)
ctypes.memmove(ctypes.addressof(record) + 0xc8, (0x7000).to_bytes(8, "little"), 8)
ctypes.memmove(ctypes.addressof(record) + 0xd0, (0x193931bf + 17).to_bytes(4, "little"), 4)
calls = []
callback = Free(lambda _opaque, address: calls.append(address))
assert release_buffers(ctypes.byref(registry), 34, record, 336, 0x1005fb8, views, callback, None) == 0
assert calls == [0x7000] and registry.generation[34] == 0
assert external.raw[17:64] == bytes([0xa5]) * 47
class Shared(ctypes.Structure):
    _fields_ = [("references", ctypes.c_uint32), ("timestamp", ctypes.c_uint64), ("baseline", ctypes.c_uint64), ("counter", ctypes.c_uint64)]
release_shared = native.ams_registry_release_shared
release_shared.argtypes = release_buffers.argtypes + [ctypes.POINTER(Shared), ctypes.c_uint64]
state = Shared(1, 10, 100, 100)
registry.generation[34] = 1058
record[244] = 15
record[300] = 3
assert release_shared(ctypes.byref(registry), 34, record, 336, 0, None, Free(), None, ctypes.byref(state), 12) == 0
assert state.references == 0 and state.counter == 102 and record.raw[300] == 2
assert registry.generation[34] == 0
class Worker(ctypes.Structure):
    _fields_ = [("wake_counter", ctypes.c_uint64), ("active", ctypes.c_uint)]
native.ams_registry_worker_begin.argtypes = [ctypes.POINTER(Worker), ctypes.POINTER(Shared)]
native.ams_registry_worker_wake.argtypes = [ctypes.POINTER(Worker), ctypes.POINTER(Shared), ctypes.c_uint64]
worker = Worker(107, 0)
assert native.ams_registry_worker_begin(ctypes.byref(worker), ctypes.byref(state)) == 1
assert native.ams_registry_worker_wake(ctypes.byref(worker), ctypes.byref(state), 13) == 0
assert state.references == 0 and state.counter == 107 and worker.wake_counter == 112 and worker.active == 0
from apple_music_source.auth import establish_signer
p = CryptoPrimitives()
assert p.temper(0) == 0
assert p.dispatch("decrypt", 1, 5, 2, 3, 64).token == 0xdf65877e
e = SPCV2(bytes(16), bytes(256), bytes(20), bytes(16))
assert SPCV2.parse(e.pack()) == e
assert len(AES(bytes(16)).encrypt_block(bytes(16))) == 16
'''
        _run([sys.executable, "-c", script, str(ROOT.parents[1])], cwd=extracted, env=environment)
        native = target / "apple_music_source/_native/libcorelskd_r1.so"
        dynamic = _run(["readelf", "-d", str(native)]).stdout
        self.assertNotIn("RUNPATH", dynamic)
        self.assertNotIn("RPATH", dynamic)
        self.assertNotIn("libwrapper", dynamic)

    def test_editable_install_is_refused(self):
        with self.assertRaises(build_backend.BuildError):
            build_backend.build_editable(self.directory)
        self.assertEqual(build_backend.get_requires_for_build_wheel(), [])
        self.assertEqual(build_backend.get_requires_for_build_sdist(), [])


if __name__ == "__main__":
    unittest.main()
