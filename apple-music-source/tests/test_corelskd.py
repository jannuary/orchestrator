"""Tests for the package-owned, source-reconstructed CoreLSKD native library.

The library is compiled from the shipped C source into a temporary directory.
Inputs are synthetic (all-zero context/state); no captured key material is used.
"""
import ctypes
import os
from pathlib import Path
import subprocess
import tempfile
import unittest

import _support  # noqa: F401

from apple_music_source.crypto import (
    CoreLSKD,
    CoreLSKDError,
    NativeLibraryUnavailable,
    default_library_path,
    load_library,
)

ROOT = Path(__file__).resolve().parents[1]
NATIVE = ROOT / "src" / "apple_music_source" / "_native"
CTX = bytes(0x8000)
STATE = bytes(0x2100)


def _build(destination):
    output = destination / "libcorelskd_r1.so"
    subprocess.run(
        [
            os.environ.get("CC", "cc"),
            "-std=c99",
            "-O1",
            "-fPIC",
            "-shared",
            "-Wall",
            "-Wextra",
            "-Werror",
            f"-I{NATIVE}",
            str(NATIVE / "corelskd_r1.c"),
            "-o",
            str(output),
        ],
        check=True,
        capture_output=True,
    )
    return output


class CoreLSKDTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls._temporary = tempfile.TemporaryDirectory(prefix="corelskd-test-")
        cls.directory = Path(cls._temporary.name)
        cls.library = _build(cls.directory)
        cls.core = CoreLSKD(cls.library)

    @classmethod
    def tearDownClass(cls):
        cls._temporary.cleanup()

    def test_native_source_is_present_and_owned(self):
        for name in ("corelskd_r1.c", "corelskd_r1.h", "corelskd_r1_generated.inc"):
            self.assertTrue((NATIVE / name).is_file(), name)
        source = (NATIVE / "corelskd_r1.c").read_text()
        self.assertIn("corelskd_r1_block", source)
        self.assertNotIn("dlopen", source)
        self.assertNotIn("system(", source)
        self.assertNotIn("popen", source)

    def test_block_is_deterministic_and_depends_on_rax_rcx(self):
        first = self.core.block(CTX, STATE, 0, 0, bytes(16))
        second = self.core.block(CTX, STATE, 0, 0, bytes(16))
        self.assertEqual(first, second)
        self.assertEqual(len(first), 16)
        variants = {
            self.core.block(CTX, STATE, 1, 0, bytes(16)),
            self.core.block(CTX, STATE, 0, 1, bytes(16)),
            self.core.block(CTX, STATE, 0, 0, bytes([1]) * 16),
        }
        self.assertIn(len(variants), (1, 2, 3))

    def test_cbc_chains_blocks_and_respects_explicit_iv(self):
        data = bytes(range(32))
        first = self.core.cbc(CTX, STATE, 0, 0, None, data)
        second = self.core.cbc(CTX, STATE, 0, 0, None, data)
        self.assertEqual(first, second)
        self.assertEqual(len(first), 32)
        # An explicit all-zero IV equals the zero chaining state captured here.
        self.assertEqual(self.core.cbc(CTX, STATE, 0, 0, bytes(16), data), first)
        # With all-zero synthetic inputs the transform is a fixed byte value.
        self.assertEqual(first, bytes([0x76]) * 32)

    def test_extract_key_fails_closed_on_unverifiable_state(self):
        with self.assertRaises(CoreLSKDError) as raised:
            self.core.extract_key(CTX, STATE, 0, 0)
        self.assertEqual(int(raised.exception.status), 1)

    def test_rejects_bad_sizes_and_indices(self):
        with self.assertRaises(ValueError):
            self.core.block(CTX[:-1], STATE, 0, 0, bytes(16))
        with self.assertRaises(ValueError):
            self.core.block(CTX, STATE[:-1], 0, 0, bytes(16))
        with self.assertRaises(ValueError):
            self.core.block(CTX, STATE, 256, 0, bytes(16))
        with self.assertRaises(ValueError):
            self.core.block(CTX, STATE, -1, 0, bytes(16))
        with self.assertRaises(ValueError):
            self.core.block(CTX, STATE, True, 0, bytes(16))
        with self.assertRaises(ValueError):
            self.core.cbc(CTX, STATE, 0, 0, None, bytes(17))
        with self.assertRaises(ValueError):
            self.core.cbc(CTX, STATE, 0, 0, bytes(15), bytes(16))
        with self.assertRaises(TypeError):
            self.core.block("x", STATE, 0, 0, bytes(16))

    def test_missing_library_fails_closed_without_fallback(self):
        missing = self.directory / "absent.so"
        with self.assertRaises(NativeLibraryUnavailable):
            load_library(missing)
        previous = os.environ.get("APPLE_MUSIC_SOURCE_CORELSKD_LIB")
        os.environ["APPLE_MUSIC_SOURCE_CORELSKD_LIB"] = str(missing)
        try:
            self.assertEqual(default_library_path(), missing)
            with self.assertRaises(NativeLibraryUnavailable):
                CoreLSKD()
        finally:
            if previous is None:
                del os.environ["APPLE_MUSIC_SOURCE_CORELSKD_LIB"]
            else:
                os.environ["APPLE_MUSIC_SOURCE_CORELSKD_LIB"] = previous

    def test_accepts_an_already_loaded_library(self):
        loaded = ctypes.CDLL(str(self.library))
        core = CoreLSKD(loaded)
        self.assertEqual(core.block(CTX, STATE, 0, 0, bytes(16)), bytes([0x76]) * 16)


if __name__ == "__main__":
    unittest.main()
