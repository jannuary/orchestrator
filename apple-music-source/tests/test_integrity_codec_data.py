"""Arithmetic data closure for the fold consumers; no oracle or vendor input."""
import ctypes
from pathlib import Path
import struct
import subprocess
import tempfile
import unittest

NATIVE=Path(__file__).resolve().parents[1]/'src/apple_music_source/_native'


class IntegrityCodecDataTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.tmp=tempfile.TemporaryDirectory(prefix='ams-codec-data-')
        lib=Path(cls.tmp.name)/'model.so'
        subprocess.run(['cc','-std=c99','-Wall','-Wextra','-Werror','-shared','-fPIC',str(NATIVE/'integrity_codec_data.c'),'-o',str(lib)],check=True)
        cls.lib=ctypes.CDLL(str(lib));cls.read=cls.lib.ams_integrity_codec_data_read
        cls.read.argtypes=[ctypes.c_uint64,ctypes.c_uint,ctypes.POINTER(ctypes.c_uint64)]

    @classmethod
    def tearDownClass(cls):cls.tmp.cleanup()

    def test_arithmetic_data(self):
        prime=16777619
        vectors={0x580:[(prime%256)*65537]*4,0xe20:[255]*4,
                 0xe30:[16]*4,0x1170:list(range(4,8)),
                 0x25b0:list(range(8,12)),0x25c0:[pow(prime,-1,2**32)]*4,
                 0x35d0:[255*65537]*4,0x4690:list(range(12,16)),
                 0x4c40:list(range(4)),0x4f40:[32]*4}
        expected={}
        for base,vector in vectors.items():
            expected.update({base+i:b for i,b in enumerate(struct.pack('<4I',*vector))})
        for address in expected:
            for width in range(1,9):
                out=ctypes.c_uint64(0xabcdef)
                covered=all(address+i in expected for i in range(width))
                self.assertEqual(self.read(address,width,ctypes.byref(out)),int(covered))
                self.assertEqual(out.value,sum(expected[address+i]<<(8*i) for i in range(width)) if covered else 0xabcdef)

    def test_guards_preserve_output(self):
        for address,width in ((0,1),(0x590,1),(0xe20,0),(0xe20,9),
                              (0xe20,2**32-1),(2**64-4,8),(0x57f,2)):
            out=ctypes.c_uint64(0x123456789abcdef0)
            self.assertEqual(self.read(address,width,ctypes.byref(out)),0)
            self.assertEqual(out.value,0x123456789abcdef0)
        self.assertEqual(self.read(0xe20,4,None),0)
