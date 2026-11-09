"""Fail-closed ABI checks; original-prefix differential tests are developer-only."""
import ctypes as C
from pathlib import Path
import subprocess
import tempfile
import unittest


class AuthWordCodecTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.temporary=tempfile.TemporaryDirectory(prefix='ams-auth-word-abi-')
        source=Path(__file__).resolve().parents[1]/'src/apple_music_source/_native/auth_word_codecs.c'
        library=Path(cls.temporary.name)/'word.so'
        subprocess.run(['cc','-std=c99','-O2','-Wall','-Wextra','-Werror','-shared','-fPIC',str(source),'-o',str(library)],check=True)
        cls.library=C.CDLL(str(library));cls.decode=cls.library.ams_auth_word_decode
        cls.decode.argtypes=[C.c_uint,C.c_uint32,C.POINTER(C.c_uint32)];cls.decode.restype=C.c_int

    @classmethod
    def tearDownClass(cls):cls.temporary.cleanup()

    def test_unsupported_decoder_preserves_output(self):
        for decoder in (5,6,255,0xffffffff):
            output=C.c_uint32(0x12345678)
            self.assertEqual(self.decode(decoder,0,C.byref(output)),0)
            self.assertEqual(output.value,0x12345678)

    def test_null_output_is_rejected_for_every_decoder(self):
        for decoder in range(5):self.assertEqual(self.decode(decoder,0,None),0)
