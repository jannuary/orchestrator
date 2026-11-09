"""Compare the source-only MAC field with a freshly linked native source oracle.

Invented hardware inputs only. No source-library/key/session capture is shipped
or serialized. The native oracle is developer-only, outside package runtime.
"""
import argparse
import hashlib
import json
from pathlib import Path
import random
import subprocess
import sys
import tempfile


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('checkout', type=Path)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    root = args.checkout.resolve()
    package = Path(__file__).resolve().parents[1]
    sys.path.insert(0, str(root / 'tools/auth'))
    from device_identity import derive_android_guid_fields
    sys.path.insert(0, str(package / 'src'))
    from apple_music_source.auth import derive_android_guid_mac_field
    from apple_music_source.auth._guid_mac_parameters import SHA1_SUFFIX
    from scan_auth_substitutions import TARGETS
    name, digest = TARGETS['corefp']
    image = (root / 'rootfs/system/lib64' / name).read_bytes()
    assert hashlib.sha256(image).hexdigest() == digest
    assert bytes((167*x+18)&255 for x in image[0x23954c:0x23956c]) == SHA1_SUFFIX
    rng = random.Random(0x68475)
    macs = [bytes(6), bytes([255])*6, bytes(range(6)), bytes(range(250,256))]
    macs += [bytes(rng.randrange(256) for _ in range(6)) for _ in range(12)]
    with tempfile.TemporaryDirectory(prefix='ams-MAC-comparison-') as directory:
        library = Path(directory) / 'fresh.so'
        objects = sorted((root/'build/auth/mescal/CMakeFiles/wrapper_mescal_source.dir').rglob('*.o'))
        assert objects
        subprocess.run(['cc', '-shared', *map(str, objects), '-o', str(library)], check=True, capture_output=True)
        for index, mac in enumerate(macs):
            android = hashlib.sha256(f'invented-android-{index}'.encode()).hexdigest()[:16].encode()
            native = derive_android_guid_fields(android, mac, system_serial=f'invented-serial-{index}'.encode(), library=library)
            assert native.second == derive_android_guid_mac_field(mac), index
            assert len(native.second) == 7
    report = dict(status='pass', invented_MAC_cases=len(macs), changed_android_and_serial_inputs=True,
                  fresh_native_source_link=True, fixed_suffix_bytes=32, fixed_suffix_source='CoreFP 0x23954c..0x23956c, decoded byte codec',
                  artifact_sha256=digest, network_requests=0, private_material_written=False,
                  scope='complete second GUID field only; first GUID field, signing, CoreADI and full crypto/auth remain incomplete')
    args.output.write_text(json.dumps(report, indent=2)+'\n')
    print(json.dumps(report))


if __name__ == '__main__':
    main()
