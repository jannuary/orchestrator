"""Source global-storage/linking semantics, without an ELF or wrapper checkout."""
import ctypes as C
from pathlib import Path
import subprocess
import tempfile
import unittest


class Binding(C.Structure):
    _fields_=[('name',C.c_char_p),('address',C.c_uint64)]


class AbiLayoutTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.temporary=tempfile.TemporaryDirectory(prefix='ams-abi-test-')
        source=Path(__file__).resolve().parents[1]/'src/apple_music_source/_native/abi_layout.c'
        library=Path(cls.temporary.name)/'abi.so'
        subprocess.run(['cc','-std=c99','-O2','-Wall','-Wextra','-Werror','-shared','-fPIC',str(source),'-o',str(library)],check=True)
        cls.lib=C.CDLL(str(library));cls.read=cls.lib.ams_abi_initial_read
        cls.read.argtypes=[C.c_uint64,C.c_uint,C.POINTER(Binding),C.c_size_t,C.POINTER(C.c_uint64)];cls.read.restype=C.c_int

    @classmethod
    def tearDownClass(cls):cls.temporary.cleanup()

    def test_zero_globals_and_relative_source_address_need_no_import_provider(self):
        for address in (0x5fc970,0x10693000):
            value=C.c_uint64(0xdecafbad12345678)
            self.assertEqual(self.read(address,8,None,0,C.byref(value)),1)
            self.assertEqual(value.value,0)
        value=C.c_uint64()
        self.assertEqual(self.read(0x1068f068,8,None,0,C.byref(value)),1)
        self.assertEqual(value.value,0x10152760)

    def test_named_binding_is_resolved_for_each_call_instead_of_captured(self):
        bindings=(Binding*1)(Binding(b'malloc',0))
        for address in (0,0x700010,2**64-1):
            bindings[0].address=address;value=C.c_uint64()
            self.assertEqual(self.read(0x5f27f0,8,bindings,1,C.byref(value)),1)
            self.assertEqual(value.value,address)

    def test_missing_ambiguous_and_unsupported_initializers_preserve_output(self):
        duplicates=(Binding*2)(Binding(b'malloc',1),Binding(b'malloc',2))
        malformed=(Binding*1)(Binding(None,1))
        wrong_name=(Binding*1)(Binding(b'calloc',1))
        requests=[(0x5f27f0,8,None,0),(0x5f27f0,8,wrong_name,1),
                  (0x5f27f0,8,duplicates,2),(0x5f27f0,8,malformed,1),
                  # This encoded callback belongs to the separately verified
                  # control-reference component. Normal relocation arithmetic
                  # alone must not admit the unexplained addend here.
                  (0x10690068,8,None,0),(0,1,None,0),
                  (0x10693000,0,None,0),(0x10693000,9,None,0),
                  (2**64-1,8,None,0),(0x10693000,1,None,1),
                  (0x10693000,1,wrong_name,C.c_size_t(-1).value)]
        for address,width,bindings,count in requests:
            value=C.c_uint64(0xdecafbad12345678)
            self.assertEqual(self.read(address,width,bindings,count,C.byref(value)),0)
            self.assertEqual(value.value,0xdecafbad12345678)
        self.assertEqual(self.read(0x10693000,8,None,0,None),0)
