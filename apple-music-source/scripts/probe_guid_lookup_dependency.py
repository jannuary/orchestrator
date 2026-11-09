"""Measure whether a selected GUID lookup changes complete native outputs.

The temporary developer oracle uses invented device profiles. Only status,
read counts and equality flags are saved; native buffers remain in RAM.
"""
import argparse
import ctypes
import json
from pathlib import Path
import re
import subprocess
import sys
import tempfile
from typing import Any, Final

from probe_auth_substitution_reads import group_wrappers

DEFAULT_LOOKUP_ADDRESS: Final[int] = 0x26d800
LOOKUP_WINDOW_BYTES: Final[int] = 64
COREFP_IMAGE_BIAS: Final[int] = 0x4000000
INVENTED_PROFILES: Final[tuple[tuple[bytes, bytes], ...]] = (
    (b'0123456789abcdef', bytes(range(6))),
    (b'fedcba9876543210', bytes(range(6, 12))),
)
REPLACEMENTS: Final[tuple[tuple[int, str], ...]] = (
    (1, 'zero bytes'),
    (2, 'flip low bit'),
    (3, 'invented arithmetic sequence'),
)
SHIM: Final[str] = r'''
#include "spc_native.h"

static wrapper_kg_native_state *current_state;
static unsigned replacement_mode;
static uint64_t overridden_read_count;
static uint64_t lookup_first_address;
static uint64_t lookup_last_address;

enum {
    REPLACE_WITH_ZERO = 1,
    REPLACE_WITH_LOW_BIT_FLIP = 2,
    INVENTED_SEQUENCE_MULTIPLIER = 37,
    INVENTED_SEQUENCE_OFFSET = 19,
    BYTE_VALUE_MASK = 255
};

void ams_lookup_config(uint64_t lookup_address, uint64_t lookup_size) {
    lookup_first_address = lookup_address;
    lookup_last_address = lookup_address + lookup_size;
}

void ams_mode(unsigned selected_mode) {
    replacement_mode = selected_mode;
    overridden_read_count = 0;
}

uint64_t ams_changed(void) {
    return overridden_read_count;
}

int __real_mescal_native_read(const void *, size_t, uint64_t, unsigned, uint64_t *);

int __wrap_mescal_native_read(
    const void *regions,
    size_t region_count,
    uint64_t address,
    unsigned width,
    uint64_t *output
) {
    int read_succeeded = __real_mescal_native_read(regions, region_count, address, width, output);
    if (!read_succeeded || !replacement_mode || !current_state || width != 1) return read_succeeded;
    if (address < lookup_first_address || address >= lookup_last_address) return read_succeeded;
    ++overridden_read_count;
    if (replacement_mode == REPLACE_WITH_ZERO) {
        *output = 0;
        return read_succeeded;
    }
    if (replacement_mode == REPLACE_WITH_LOW_BIT_FLIP) {
        *output ^= 1;
        return read_succeeded;
    }
    *output = ((address - lookup_first_address) * INVENTED_SEQUENCE_MULTIPLIER + INVENTED_SEQUENCE_OFFSET) & BYTE_VALUE_MASK;
    return read_succeeded;
}
'''


def parse_native_address(value: str) -> int:
    return int(value, 0)


def create_native_probe(checkout: Path, destination: Path, lookup_address: int) -> ctypes.CDLL:
    generated_bounds = checkout / 'crypto/auth/mescal/generated/bounds.inc'
    native_groups = sorted(set(re.findall(r'\bmescal_(?:ssc|corefp)_page_[0-9a-f]+\b', generated_bounds.read_text())))
    source_path = destination / 'probe.c'
    library_path = destination / 'probe.so'
    source_path.write_text(SHIM + group_wrappers(native_groups))
    native_objects = sorted((checkout / 'build/auth/mescal/CMakeFiles/wrapper_mescal_source.dir').rglob('*.o'))
    if not native_objects:
        raise RuntimeError('native developer oracle objects are unavailable')
    command = [
        'cc', '-std=c99', '-O2', '-shared', '-fPIC',
        '-I' + str(checkout / 'crypto/keygen_experimental'), str(source_path),
        *map(str, native_objects), '-Wl,--wrap=mescal_native_read',
        *['-Wl,--wrap=' + group for group in native_groups], '-o', str(library_path),
    ]
    subprocess.run(command, check=True, capture_output=True)
    native_library = ctypes.CDLL(str(library_path))
    native_library.ams_lookup_config.argtypes = [ctypes.c_uint64, ctypes.c_uint64]
    native_library.ams_lookup_config(COREFP_IMAGE_BIAS + lookup_address, LOOKUP_WINDOW_BYTES)
    native_library.ams_mode.argtypes = [ctypes.c_uint]
    native_library.ams_changed.restype = ctypes.c_uint64
    return native_library


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('checkout', type=Path)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--lookup-address', type=parse_native_address, default=DEFAULT_LOOKUP_ADDRESS)
    arguments = parser.parse_args()
    if arguments.lookup_address < 0:
        parser.error('lookup address must be nonnegative')
    checkout = arguments.checkout.resolve()
    sys.path.insert(0, str(checkout / 'tools/auth'))
    from device_identity import derive_android_guid_fields
    from mescal_source import SourceMescalError

    profile_results: list[dict[str, Any]] = []
    with tempfile.TemporaryDirectory(prefix='ams-guid-lookup-control-') as directory:
        temporary_directory = Path(directory)
        native_library = create_native_probe(checkout, temporary_directory, arguments.lookup_address)
        library_path = temporary_directory / 'probe.so'
        for profile_number, (android_identifier, mac_address) in enumerate(INVENTED_PROFILES):
            native_library.ams_mode(0)
            baseline = derive_android_guid_fields(
                android_identifier, mac_address,
                system_serial=b'invented-lookup-control', library=library_path,
            )
            replacement_results: list[dict[str, Any]] = []
            for replacement_mode, replacement_label in REPLACEMENTS:
                native_library.ams_mode(replacement_mode)
                try:
                    observed = derive_android_guid_fields(
                        android_identifier, mac_address,
                        system_serial=b'invented-lookup-control', library=library_path,
                    )
                    replacement_results.append(dict(
                        replacement=replacement_label, source_returned=True,
                        first_field_equal=observed.first == baseline.first,
                        second_field_equal=observed.second == baseline.second,
                        overridden_reads=native_library.ams_changed(),
                    ))
                except SourceMescalError as error:
                    replacement_results.append(dict(
                        replacement=replacement_label, source_returned=False,
                        error_type=type(error).__name__, overridden_reads=native_library.ams_changed(),
                    ))
            profile_results.append(dict(profile=profile_number, controls=replacement_results))
    report = dict(
        status='bounded positive-output lookup dependency controls',
        source_lookup=f'CoreFP {arguments.lookup_address:#x}..{arguments.lookup_address + LOOKUP_WINDOW_BYTES:#x}',
        cases=profile_results, network_requests=0, private_bytes_written=False,
        scope='temporary source-oracle byte substitutions; no package lookup replacement or full auth claim',
    )
    arguments.output.write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps(report))


if __name__ == '__main__':
    main()
