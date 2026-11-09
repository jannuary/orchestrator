"""Source-control reference semantics and read guards; no SDK/oracle input."""
import ctypes as C
from pathlib import Path
import re
import struct
import subprocess
import tempfile
import unittest


class ControlReferenceTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.temporary=tempfile.TemporaryDirectory(prefix='ams-control-test-')
        source=Path(__file__).resolve().parents[1]/'src/apple_music_source/_native/control_refs.c'
        library=Path(cls.temporary.name)/'control.so'
        subprocess.run(['cc','-std=c99','-O2','-Wall','-Wextra','-Werror','-shared','-fPIC',str(source),'-o',str(library)],check=True)
        cls.lib=C.CDLL(str(library));cls.read=cls.lib.ams_control_refs_read
        cls.read.argtypes=[C.c_uint64,C.c_uint,C.POINTER(C.c_uint64)];cls.read.restype=C.c_int
        cls.last_cell=max(int(a,16) for a in re.findall(r'case UINT64_C\((0x[0-9a-f]+)\)',source.read_text()))

    @classmethod
    def tearDownClass(cls):cls.temporary.cleanup()

    def test_dispatch_and_backward_source_destinations(self):
        for address,base,destination in ((0x10013a34,0x101a09eb,0x101a0a0b),
                                         (0x10012f48,0x101b285d,0x101b2510),
                                         # Saved RSI survives independent SIMD
                                         # setup before the jump at 0x1052b456.
                                         (0x10014a18,0x1052952b,0x1052b460)):
            word=C.c_uint64()
            self.assertEqual(self.read(address,4,C.byref(word)),1)
            self.assertEqual(base+C.c_int32(word.value).value,destination)
            # The same source reference must remain valid through unaligned
            # byte/halfword reads; callers do not receive an opaque word object.
            encoded=struct.pack('<I',word.value)
            for offset in range(4):
                for width in range(1,5-offset):
                    self.assertEqual(self.read(address+offset,width,C.byref(word)),1)
                    self.assertEqual(word.value,int.from_bytes(encoded[offset:offset+width],'little'))

    def test_partial_unknown_reads_overflow_and_bad_width_preserve_output(self):
        for address,width in ((0,1),(self.last_cell+3,2),(0x10013a34,0),
                              (0x10013a34,9),(2**64-1,8)):
            output=C.c_uint64(0xdecafbad12345678)
            self.assertEqual(self.read(address,width,C.byref(output)),0)
            self.assertEqual(output.value,0xdecafbad12345678)
        self.assertEqual(self.read(0x10013a34,4,None),0)

    def test_encoded_clock_callback_uses_source_function_and_instruction_offset(self):
        word=C.c_uint64()
        self.assertEqual(self.read(0x10690068,8,C.byref(word)),1)
        # Source producer at 0x101b0c6b, add at 0x101b0c72,
        # frame-local store at 0x101b0c76, call at 0x1024b219.
        immediate=C.c_uint64(-0x78033c36).value
        callback=(word.value+immediate)%(1<<64)
        self.assertEqual(callback,0x101a07d0)

    def test_import_slots_cannot_fall_back_to_fixed_control_tokens(self):
        for address in (0x5f27f0,):
            word=C.c_uint64(0xdecafbad12345678)
            self.assertEqual(self.read(address,8,C.byref(word)),0)
            self.assertEqual(word.value,0xdecafbad12345678)
