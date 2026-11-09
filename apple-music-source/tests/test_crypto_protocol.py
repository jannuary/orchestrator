"""Invented buffers, standard MT oracle, and direct native failure contracts."""
import ctypes as C
import os
from pathlib import Path
import random
import struct
import sys
import tempfile
import unittest
from unittest.mock import patch

import _support
sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import build_backend
from apple_music_source.crypto import (
    SPCV2, CryptoPrimitives, decode_dispatch_status, initial_iv,
)


class ProtocolTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.temp = tempfile.TemporaryDirectory(prefix="ams-protocol-")
        cls.library = build_backend.build_native(Path(cls.temp.name))
        cls.environment = patch.dict(os.environ, APPLE_MUSIC_SOURCE_CORELSKD_LIB=str(cls.library))
        cls.environment.start()
        cls.core = CryptoPrimitives()

    @classmethod
    def tearDownClass(cls):
        cls.environment.stop()
        cls.temp.cleanup()

    def test_spc_layout_and_rejections(self):
        e = SPCV2(bytes(range(16)), bytes(range(256)), b"z" * 20, b"p" * 32)
        packet = e.pack()
        self.assertEqual(packet[:8], struct.pack(">II", 2, 0))
        self.assertEqual(packet[8:24], e.field16)
        self.assertEqual(packet[24:280], e.field256)
        self.assertEqual(packet[280:300], e.field20)
        self.assertEqual(packet[300:304], struct.pack(">I", 32))
        self.assertEqual(SPCV2.parse(packet), e)
        for bad in (b"", packet[:-1], packet + b"x", bytes(8) + packet[8:],
                    packet[:7] + b"\x01" + packet[8:], packet[:300] + bytes(4) + packet[304:]):
            with self.subTest(size=len(bad)), self.assertRaises(ValueError):
                SPCV2.parse(bad)
        with self.assertRaises(ValueError):
            SPCV2(bytes(16), bytes(256), bytes(20), b"x")

    def test_all_four_dispatch_adapters(self):
        cases = (
            ("persistent", (1, 2, 3, 4, 5), 0x13c604d2, (6, 0, 1, 1, 2, 3, 4, 5)),
            ("context", (1, 2, 3, 4), 0xc84dc4a3, (5, 0, 1, 1, 2, 3, 4)),
            ("finalize", (9,), 0x68df9ab6, (2, 0, 1, 9)),
            ("decrypt", (1, 5, 2, 3, 64), 0xdf65877e, (6, 0, 1, 1, 5, 2, 3, 64)),
        )
        for name, args, token, words in cases:
            packet = self.core.dispatch(name, *args)
            self.assertEqual(packet.token, token)
            self.assertEqual(packet.arguments, struct.pack(">" + "Q" * 24, *words, *([0] * (24 - len(words)))))
            self.assertEqual(packet.version, 1)
        for name, args in (("missing", ()), ("context", (1, 2, 1 << 32, 4)),
                           ("finalize", (-1,)), ("finalize", (True,)), ("finalize", ())):
            with self.assertRaises(ValueError):
                self.core.dispatch(name, *args)
        self.assertEqual(decode_dispatch_status(struct.pack(">QQQ", 1, 0, 0xffffffff)), 0xffffffff)
        for words in ((0, 0, 0), (1, 1, 0), (1, 0, 1 << 32)):
            with self.assertRaises(ValueError):
                decode_dispatch_status(struct.pack(">QQQ", *words))

    def test_native_failure_does_not_write(self):
        # Validate C contracts as well as Python bounds; no API receives a
        # forged host pointer. Integer packet addresses never get dereferenced.
        lib = self.core._lib
        out = C.create_string_buffer(b"x" * 192, 192)
        f = lib.wrapper_kg_context_finalize_packet
        self.assertEqual(f(out, 191, 1), -1)
        self.assertEqual(out.raw, b"x" * 192)
        append = lib.wrapper_kg_append_bytes
        obj = C.create_string_buffer(struct.pack("<I", 0x7b5ad73e + 299) + b"x" * 300, 304)
        before = obj.raw
        self.assertEqual(append(obj, 304, 0x2167c5a6 + 1, b"a", 1), -42678)
        self.assertEqual(obj.raw, before)
        parse = lib.wrapper_kg_spc_v2_parse
        # The view remains unchanged on a malformed header.
        from apple_music_source.crypto.protocol import _View
        view = _View(1, 2, 3, 4, 5)
        original = bytes(view)
        self.assertEqual(parse(b"x", 1, C.byref(view)), -1)
        self.assertEqual(bytes(view), original)

    def test_mt_against_independent_stdlib(self):
        rng = random.Random(0x20261030)
        for state in ([0] * 624, [0xffffffff] * 624, *([rng.getrandbits(32) for _ in range(624)] for _ in range(6))):
            oracle = random.Random()
            oracle.setstate((3, tuple(state + [624]), None))
            words = self.core.twist(state)
            self.assertEqual([self.core.temper(v) for v in words], [oracle.getrandbits(32) for _ in range(624)])
        for i in range(256):
            v = i * 0x01010101
            self.assertEqual(self.core.encode_word(v), bytes(x ^ 0x47 for x in v.to_bytes(4, "big")))
        for state in ([0] * 623, [0] * 623 + [-1], [0] * 623 + [True]):
            with self.assertRaises(ValueError):
                self.core.twist(state)

    def test_dispatch_controls_and_address_bound_packets(self):
        self.assertEqual(self.core.compare(8, 7, mode=0, selector=16), 185)
        self.assertEqual(self.core.compare(8, 9, mode=0, selector=16), 2815)
        self.assertEqual(self.core.compare(0, (1 << 64) - 1, mode=1, selector=72), 429)
        with self.assertRaises(ValueError):
            self.core.compare(0, 0, mode=0, selector=999)
        address = 0x12345000
        mask = ((address ^ 0xbe2af1b45989a725) * 0x1f6060df) & ((1 << 64) - 1)
        packet = bytearray(48)
        for offset, value, fmt in ((0, 8 - mask, "Q"), (24, 7 - mask, "Q"),
                                    (8, 0x10a1 - mask, "I"), (32, mask, "I"),
                                    (36, 16 + mask, "I"), (44, 3 + mask, "I")):
            struct.pack_into("<" + fmt, packet, offset, value & ((1 << (64 if fmt == "Q" else 32)) - 1))
        self.assertEqual(self.core.compare_packet(address, packet), 185)
        field = struct.pack("<IIQIIQ", 0, (0xdb8 + mask) & 0xffffffff, 123, (10 + mask) & 0xffffffff, 0, 456)
        self.assertEqual(self.core.field_packet(address, field), (0xdb8, 123, 456))
        with self.assertRaises(ValueError):
            self.core.field_packet(address + 1, field)

    def test_field_copy_and_encoded_append(self):
        src, dst = bytes(range(32)), b"x" * 96
        for body, offset, source_offset in ((0xdb8, 0, 16), (0x11c7, 24, 4), (0x1204, 40, 4), (0x1240, 56, 4), (0xdf1, 72, 4)):
            result = self.core.copy_field(body, dst, src)
            self.assertEqual(result[offset:offset + 4], src[source_offset:source_offset + 4])
            self.assertEqual(result[offset + 4:offset + 8], b"x" * 4)
            self.assertEqual(result[offset + 8:offset + 16], src[24:32] if source_offset == 16 else src[8:16])
            if body == 0xdf1:
                self.assertEqual(result[88], 10)
        descriptor = struct.pack("<I", 0x7b5ad73e) + bytes(300)
        result = self.core.append_encoded(descriptor, b"abc")
        self.assertEqual(result[:8], struct.pack("<I", 0x7b5ad73e + 3) + bytes((0xde, 0xdf, 0xe0, 0x7d)))
        self.assertEqual(descriptor[4:], bytes(300))
        with self.assertRaises(ValueError):
            self.core.append_encoded(bytes(304), b"abc")

    def test_initial_iv_permutation_and_faults(self):
        context = bytearray(0x8000)
        context[0x4180:0x4280] = bytes((i * 17 + 11) % 256 for i in range(256))
        context[0x38ed] = 0x73
        state = bytearray(0x2100)
        chain = (0x178, 0x190, 0x118, 0x3e0, 0x160, 0x188, 0xe0, 0x120, 0x100, 0xd0, 0xf8, 0x108, 0xf0, 0xe8, 0x410, 0xc0)
        for base in range(16):
            expected = bytes(range(base * 16, base * 16 + 16))
            for offset, byte in zip(chain, expected):
                state[0x2000 - offset] = context[0x4180 + byte] ^ context[0x38ed]
            self.assertEqual(initial_iv(context, state), expected)
        with self.assertRaises(ValueError):
            initial_iv(bytes(0x8000), state)


if __name__ == "__main__":
    unittest.main()
