"""Owned arithmetic copy stages; no ELF, SDK, keys or account inputs."""
import ctypes as C
from pathlib import Path
import subprocess
import tempfile
import unittest


class CopyCodecTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.temporary=tempfile.TemporaryDirectory(prefix='ams-copy-test-')
        source=Path(__file__).resolve().parents[1]/'src/apple_music_source/_native/copy_codecs.c'
        library=Path(cls.temporary.name)/'copy.so'
        subprocess.run(['cc','-std=c99','-O2','-Wall','-Wextra','-Werror','-shared','-fPIC',str(source),'-o',str(library)],check=True)
        cls.lib=C.CDLL(str(library))
        for name in ('ams_copy0_byte','ams_copy1_byte'):
            f=getattr(cls.lib,name);f.argtypes=[C.c_uint32,C.c_uint8,C.c_uint8];f.restype=C.c_uint8
        for name in ('ams_copy0_forward','ams_copy0_inverse','ams_copy1_forward','ams_copy1_inverse'):
            f=getattr(cls.lib,name);f.argtypes=[C.c_void_p,C.c_size_t,C.c_void_p,C.c_size_t,C.c_size_t];f.restype=C.c_int

    @classmethod
    def tearDownClass(cls):cls.temporary.cleanup()

    def test_original_byte_vectors_and_control_masks(self):
        # Covered by the original-instruction development oracle as well.
        self.assertEqual(self.lib.ams_copy0_byte(0,0,0),0xaa)
        self.assertEqual(self.lib.ams_copy0_byte(0,4,0),0x3e)
        self.assertEqual(self.lib.ams_copy1_byte(0,0,0),0xec)
        out=C.create_string_buffer(16);inp=C.create_string_buffer(bytes(range(16)),16)
        self.assertEqual(self.lib.ams_copy1_forward(out,16,inp,16,16),0)
        self.assertEqual(bytes(out),bytes.fromhex('eceef0f2f4f6f8fafcfe00020406080a'))
        self.assertEqual(self.lib.ams_copy0_forward(out,16,inp,16,16),0)
        self.assertEqual(bytes(out),bytes.fromhex('aa0ee2463a96722e8a6ed2b61ac6a20e'))
        for state in range(256):
            self.assertEqual(self.lib.ams_copy0_byte(127,state,0x9a),self.lib.ams_copy0_byte(127,state&12,0x9a))
            self.assertEqual(self.lib.ams_copy1_byte(127,state,0x9a),self.lib.ams_copy1_byte(127,state&240,0x9a))

    def test_forward_inverse_and_exact_alias_across_counter_wrap(self):
        initial=bytes(range(256))*2+b'counter-boundary'
        for stage in (0,1):
            forward=getattr(self.lib,'ams_copy'+str(stage)+'_forward');inverse=getattr(self.lib,'ams_copy'+str(stage)+'_inverse')
            for count in (0,1,8,15,16,17,255,256,257,len(initial)):
                buf=C.create_string_buffer(initial,len(initial))
                self.assertEqual(forward(buf,len(buf),buf,len(buf),count),0)
                self.assertEqual(bytes(buf)[count:],initial[count:])
                self.assertEqual(inverse(buf,len(buf),buf,len(buf),count),0)
                self.assertEqual(bytes(buf),initial)

    def test_forward_overlap_reads_each_byte_after_prior_store(self):
        buf=C.create_string_buffer(bytes(range(8)),8)
        self.assertEqual(self.lib.ams_copy1_forward(C.byref(buf,1),7,buf,8,7),0)
        self.assertEqual(bytes(buf),bytes.fromhex('00ecd9c7b6a69789'))
        buf=C.create_string_buffer(bytes(range(8)),8)
        self.assertEqual(self.lib.ams_copy0_forward(C.byref(buf,1),7,buf,8,7),0)
        self.assertEqual(bytes(buf),bytes.fromhex('00aaa545003eadd9'))

    def test_invalid_bounds_preserve_output_and_empty_null_copy(self):
        for name in ('ams_copy0_forward','ams_copy0_inverse','ams_copy1_forward','ams_copy1_inverse'):
            f=getattr(self.lib,name);buf=C.create_string_buffer(b'untouched',9)
            for output_size,input_size,count in ((0,9,1),(9,0,1),(8,9,9),(9,8,9)):
                self.assertEqual(f(buf,output_size,buf,input_size,count),-1)
                self.assertEqual(bytes(buf),b'untouched')
            self.assertEqual(f(buf,9,None,9,1),-1)
            self.assertEqual(f(None,9,buf,9,1),-1)
            if C.sizeof(C.c_size_t)>4:self.assertEqual(f(buf,2**32,buf,2**32,2**32),-1)
            self.assertEqual(bytes(buf),b'untouched')
            self.assertEqual(f(None,0,None,0,0),0)
