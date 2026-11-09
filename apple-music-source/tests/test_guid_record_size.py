"""Original-instruction answers for Android-ID record-size calculation."""
import json
from pathlib import Path
import unittest

import _support  # noqa: F401
from apple_music_source.auth._guid_record_size import record_size


class GuidRecordSizeTests(unittest.TestCase):
    def test_original_instruction_sizes(self):
        vectors=json.loads((Path(__file__).parent/'vectors/guid_record_size.json').read_text())
        self.assertEqual(len(vectors['cases']),12)
        for case in vectors['cases']:
            with self.subTest(length=len(case['input'])//2):
                self.assertEqual(record_size(bytes.fromhex(case['input'])),case['output_size'])

    def test_raw_byte_shapes_and_native_length_bounds(self):
        value=bytearray(range(16));saved=bytes(value);expected=record_size(saved)
        self.assertEqual(record_size(value),expected)
        self.assertEqual(record_size(memoryview(value).cast('H')),expected)
        self.assertEqual(bytes(value),saved)
        for invalid in (None,16,'0123456789abcdef',b'',bytes(7),bytes(81)):
            with self.subTest(kind=type(invalid).__name__):
                with self.assertRaises(ValueError):record_size(invalid)


if __name__=='__main__':unittest.main()
