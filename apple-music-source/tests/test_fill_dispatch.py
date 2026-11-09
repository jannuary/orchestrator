"""Finite byte-fill control structure; invented inputs, no original artifacts."""
import ctypes
import os
from pathlib import Path
import struct
import subprocess
import tempfile
import unittest


NATIVE = Path(__file__).resolve().parents[1] / 'src/apple_music_source/_native'


class FillDispatchTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.temporary = tempfile.TemporaryDirectory(prefix='ams-fill-model-')
        path = Path(cls.temporary.name) / 'model.so'
        subprocess.run([os.environ.get('CC', 'cc'), '-std=c99', '-Wall', '-Wextra',
                        '-Werror', '-shared', '-fPIC', str(NATIVE / 'fill_dispatch.c'),
                        '-o', str(path)], check=True)
        cls.lib = ctypes.CDLL(str(path))
        cls.read = cls.lib.ams_fill_dispatch_read
        cls.read.argtypes = [ctypes.c_uint64, ctypes.c_uint,
                             ctypes.POINTER(ctypes.c_uint64)]
        cls.read.restype = ctypes.c_int

    @classmethod
    def tearDownClass(cls):
        cls.temporary.cleanup()

    def test_control_destinations(self):
        # Enumerated entry labels for 1..7 leading stores, 0..7 whole-word
        # residues, and 0..7 trailing stores. These are control-flow labels.
        groups = (
            (0x525a00, (0x42cf27, 0x42cf20, 0x42cf19, 0x42cf12,
                        0x42cf0b, 0x42cf04, 0x42cefd)),
            (0x525a1c, (0x42cf7b, 0x42cfac, 0x42cfa5, 0x42cf9e,
                        0x42cf97, 0x42cf90, 0x42cf89, 0x42cf82)),
            (0x525a3c, (0x42cff9, 0x42cff6, 0x42cfef, 0x42cfe8,
                        0x42cfe1, 0x42cfda, 0x42cfd3, 0x42cfcc)),
        )
        expected = b''.join(struct.pack('<i', target - base)
                            for base, targets in groups for target in targets)
        for start in range(len(expected)):
            for width in range(1, min(8, len(expected) - start) + 1):
                out = ctypes.c_uint64(0x123456789abcdef0)
                self.assertEqual(self.read(0x525a00 + start, width,
                                          ctypes.byref(out)), 1)
                self.assertEqual(out.value, int.from_bytes(
                    expected[start:start + width], 'little'))

    def test_rejections_preserve_output(self):
        for address, width in ((0, 4), (0x5259ff, 1), (0x525a5c, 1),
                               (0x525a5b, 2), (0x525a00, 0), (0x525a00, 9),
                               (2**64 - 1, 8), (0x525a00, 2**32 - 1)):
            out = ctypes.c_uint64(0x123456789abcdef0)
            self.assertEqual(self.read(address, width, ctypes.byref(out)), 0)
            self.assertEqual(out.value, 0x123456789abcdef0)
        self.assertEqual(self.read(0x525a00, 4, None), 0)


if __name__ == '__main__':
    unittest.main()
