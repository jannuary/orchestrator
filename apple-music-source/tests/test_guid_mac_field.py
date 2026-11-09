"""Complete native-path known answers for invented MAC fields."""
import json
from pathlib import Path
import unittest

import _support  # noqa: F401
from apple_music_source.auth import derive_android_guid_mac_field


class GuidMACFieldTests(unittest.TestCase):
    def test_native_source_known_answers(self):
        vectors = json.loads((Path(__file__).parent/'vectors/guid_mac_field.json').read_text())
        self.assertEqual(len(vectors['cases']), 4)
        for case in vectors['cases']:
            with self.subTest(MAC=case['MAC']):
                self.assertEqual(derive_android_guid_mac_field(bytes.fromhex(case['MAC'])), bytes.fromhex(case['field']))

    def test_rejects_text_and_wrong_raw_shapes(self):
        for invalid in (None, '00:01:02:03:04:05', bytes(5), bytes(7), bytearray(6), memoryview(bytes(6))):
            with self.subTest(kind=type(invalid).__name__):
                with self.assertRaises(ValueError):
                    derive_android_guid_mac_field(invalid)


if __name__ == '__main__':
    unittest.main()
