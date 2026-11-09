"""Original-instruction answers for the first GUID record's cyclic mixer."""
import json
from pathlib import Path
import unittest

import _support  # noqa: F401
from apple_music_source.auth._guid_record_mixer import mix_record


class GuidRecordMixerTests(unittest.TestCase):
    def test_original_instruction_known_answers_including_aliasing_taps(self):
        vectors=json.loads((Path(__file__).parent/'vectors/guid_record_mixer.json').read_text())
        self.assertEqual(len(vectors['cases']),7)
        for case in vectors['cases']:
            value=bytes.fromhex(case['input'])
            with self.subTest(length=len(value)):
                self.assertEqual(mix_record(value),bytes.fromhex(case['output']))

    def test_bytes_views_are_normalized_without_mutating_caller(self):
        value=bytearray(range(20));saved=bytes(value);expected=mix_record(saved)
        self.assertEqual(mix_record(value),expected)
        self.assertEqual(mix_record(memoryview(value)),expected)
        self.assertEqual(mix_record(memoryview(value).cast('H')),expected)
        self.assertEqual(bytes(value),saved)
        for invalid in (b'',bytearray(),memoryview(b''),None,20,'x'):
            with self.subTest(kind=type(invalid).__name__):
                with self.assertRaises(ValueError):mix_record(invalid)


if __name__=='__main__':unittest.main()
