"""Reproduce source provenance and bounded historical coverage metadata.

Usage: python scripts/audit_closure.py SOURCE_CHECKOUT [--output FILE]
This is a developer audit, not a runtime loader. It reads only source and the
named metadata reports, never sessions, captures, ELF files, or the harness.
"""
import argparse
from bisect import bisect_right
import hashlib
import json
from pathlib import Path
import re


def audit(root):
    package = Path(__file__).resolve().parents[1]
    native = package / 'src/apple_music_source/_native'
    copied = []
    for name in ('spc_v2', 'ckc_packet', 'mt19937', 'compare_select', 'field_copy', 'append_bytes'):
        for suffix in ('.c', '.h'):
            source = Path('crypto/keygen_experimental') / (name + suffix)
            target = native / source.name
            original = (root / source).read_bytes()
            if original != target.read_bytes():
                raise ValueError('copied source differs: ' + str(source))
            copied.append({'source': source.as_posix(), 'package': target.relative_to(package).as_posix(),
                           'bytes': len(original), 'sha256': hashlib.sha256(original).hexdigest()})
    for name in ('corelskd_r1.c', 'corelskd_r1.h', 'corelskd_r1_generated.inc'):
        source = Path('crypto') / name
        original = (root / source).read_bytes()
        if original != (native / name).read_bytes():
            raise ValueError('CoreLSKD copy differs: ' + name)
        copied.append({'source': source.as_posix(), 'package': (native / name).relative_to(package).as_posix(),
                       'bytes': len(original), 'sha256': hashlib.sha256(original).hexdigest()})
    for provider in ('coreadi', 'mescal'):
        source_directory = root / 'crypto/auth' / provider
        package_directory = native / 'auth' / provider
        for source in sorted(path for path in source_directory.rglob('*') if path.is_file()):
            relative = source.relative_to(root / 'crypto/auth' / provider)
            target = package_directory / relative
            original = source.read_bytes()
            if original != target.read_bytes():
                raise ValueError('copied auth source differs: ' + str(source.relative_to(root)))
            copied.append({
                'source': source.relative_to(root).as_posix(),
                'package': target.relative_to(package).as_posix(),
                'bytes': len(original),
                'sha256': hashlib.sha256(original).hexdigest(),
            })
    for name in ('spc_machine.h', 'spc_native.h', 'spc_native_internal.h', 'spc_payload.h', 'spc_simd.h'):
        source = Path('crypto/keygen_experimental') / name
        original = (root / source).read_bytes()
        target = native / 'keygen_experimental' / name
        if original != target.read_bytes():
            raise ValueError('copied source differs: ' + str(source))
        copied.append({'source': source.as_posix(), 'package': target.relative_to(package).as_posix(),
                       'bytes': len(original), 'sha256': hashlib.sha256(original).hexdigest()})
    source_tree = root / 'crypto/keygen_experimental'
    package_tree = native / 'keygen_experimental'
    for source in sorted(path for path in source_tree.rglob('*') if path.is_file() and path.suffix in ('.c', '.h', '.inc')):
        relative = source.relative_to(source_tree)
        target = package_tree / relative
        original = source.read_bytes()
        if original != target.read_bytes():
            raise ValueError('copied source differs: ' + str(source.relative_to(root)))
        copied.append({'source': source.relative_to(root).as_posix(),
                       'package': target.relative_to(package).as_posix(),
                       'bytes': len(original), 'sha256': hashlib.sha256(original).hexdigest()})
    coverage_path = 'build/re/keygen-notes/key-target-context-09-20261030-attempt1.json'
    coverage = json.loads((root / coverage_path).read_text())['core_blocks']
    coverage.sort(key=lambda r: r['begin'])
    starts = [r['begin'] for r in coverage]
    def covered(pc):
        j = bisect_right(starts, pc) - 1
        return j >= 0 and pc < coverage[j]['begin'] + coverage[j]['size']
    hooks = {k: {} for k in ('wrapper_kg_integrity_fold', 'wrapper_kg_ckc_integrity_word')}
    for path in sorted((root / 'crypto/keygen_experimental/native_generated').glob('block_*.c')):
        pc = None
        for number, line in enumerate(path.open(), 1):
            match = re.search(r'STEP\(0x([0-9a-f]+)\)', line)
            if match:
                pc = int(match[1], 16)
            for symbol, sites in hooks.items():
                if pc is not None and symbol + '(' in line and 'extern ' not in line:
                    sites.setdefault(pc, {'pc': hex(pc), 'source': path.relative_to(root).as_posix(),
                                          'line': number, 'in_reference_coverage': covered(pc)})
    # Preserve aggregate/small-site metadata only, never arrays from reports.
    hook_summary = {}
    for symbol, sites in hooks.items():
        rows = list(sites.values())
        hook_summary[symbol] = {'distinct_sites': len(rows),
                               'in_reference_coverage': sum(r['in_reference_coverage'] for r in rows),
                               'sites' if len(rows) <= 16 else 'sample_sites': rows if len(rows) <= 16 else rows[:4] + rows[-4:],
                               'scope': 'static call sites inside historical reference basic-block coverage; not source branch telemetry'}
    sources = (
        'crypto/keygen_experimental/CMakeLists.txt', 'crypto/keygen_experimental/spc_generate.c',
        'crypto/keygen_experimental/spc_native.c', 'crypto/keygen_experimental/spc_native_lookup.c',
        'tools/crypto/keygen_experimental/generate_source_images.py',
        'tools/crypto/keygen_experimental/generate_payload_constants.py',
        'tools/crypto/keygen_experimental/generate_integrity.py',
        'tools/crypto/keygen_experimental/identity_builder.c',
        'tools/crypto/keygen_experimental/generate_ckc_pairs.py',
        'tools/auth/coreadi_generate.py', 'tools/auth/mescal_generate.py',
        'tools/auth/mescal_integrity_generate.py', 'tools/auth/coreadi_source.py',
        'crypto/auth/coreadi/coreadi.c', 'crypto/auth/mescal/mescal.c',
        'crypto/auth/coreadi/CMakeLists.txt', 'crypto/auth/mescal/CMakeLists.txt',
        'crypto/auth/coreadi/coreadi.h', 'crypto/auth/mescal/mescal.h',
        'tools/auth/fresh_login.py', 'tools/crypto/keygen_experimental/r1_replay_parity.py',
    )
    manifests = {}
    for name in ('tools/crypto/keygen_experimental/source_image_manifest.json',
                 'tools/crypto/keygen_experimental/payload_constants_manifest.json',
                 'tools/auth/coreadi_manifest.json', 'tools/auth/mescal_manifest.json'):
        m = json.loads((root / name).read_text())
        manifests[name] = {k: m[k] for k in ('app_sha256', 'core_sha256', 'images', 'image_bytes',
                         'non_executable_data_bytes', 'unique_read_bytes', 'covered_bytes') if k in m}
        if 'ranges' in m:
            manifests[name]['ranges'] = len(m['ranges'])
    recovered_models = {
        'fill_dispatch': {
            'scope': 'pristine byte-fill branch destinations only; not a crypto integrity replacement',
            'source_routine': '0x42ced0..0x42cffb',
            'guest_range': ['0x525a00', '0x525a5c'],
            'reconstructed_bytes': 92,
            'finite_destinations': 23,
            'derivation': 'prefix/bulk/suffix store counts and source control-label spacing',
            'sources': {name: hashlib.sha256((package / name).read_bytes()).hexdigest()
                        for name in ('src/apple_music_source/_native/fill_dispatch.c',
                                     'src/apple_music_source/_native/fill_dispatch.h',
                                     'scripts/verify_fill_dispatch.py',
                                     'scripts/probe_fill_reconstruction.py')},
        },
    }
    recovered_models['integrity_codec_simd'] = {
        'scope': 'pristine arithmetic SIMD data; parameterized codec recovered, fold/pair banks unresolved',
        'source_consumers': ['0x3edebc..0x3ee383', '0x3ee6a1..0x3eed16'],
        'core_relative_bases': ['0x580', '0xe20', '0xe30', '0x1170', '0x25b0',
                                '0x25c0', '0x35d0', '0x4690', '0x4c40', '0x4f40'],
        'bytes_per_range': 16,
        'reconstructed_bytes': 160,
        'derivation': 'SIMD lane indices, byte masks, FNV multiplier and modular inverse',
        'sources': {name: hashlib.sha256((package / name).read_bytes()).hexdigest()
                    for name in ('src/apple_music_source/_native/integrity_codec_data.c',
                                 'src/apple_music_source/_native/integrity_codec_data.h',
                                 'scripts/verify_integrity_codec.py',
                                 'scripts/probe_codec_reconstruction.py',
                                 'scripts/probe_fold_boundaries.py')},
    }
    runtime_models = {'registry_generations': {
        'scope': 'canonical generation allocation and pre-codec tag check only; no complete encoded-record registry/session replacement',
        'source_intervals': ['0x1f7300..0x2079d4', '0x3ee473..0x3ee4e5'],
        'representation_relation': 'original tag = canonical generation + 0x69cad980 modulo 2^32',
        'unresolved': ['encoded pointer/record lifetime', 'aliases and native faults',
                       'instruction budgets', 'worker wake/expiry', 'valid CKC/context/decrypt'],
        'sources': {name: hashlib.sha256((package / name).read_bytes()).hexdigest()
                    for name in ('src/apple_music_source/_native/registry.c',
                                 'src/apple_music_source/_native/registry.h',
                                 'scripts/verify_registry_allocator.py',
                                 'scripts/inventory_registry_folds.py',
                                 'scripts/probe_registry_lifetime.py')},
    }}
    runtime_models['copy_codecs'] = {
        'scope': 'two output-byte arithmetic stages and their bounded forward-copy transforms/inverses; no surrounding cipher or packet validation',
        'source_intervals': ['0x527a59..0x527aad', '0x53172e..0x531759'],
        'derivation': 'explicit unsigned arithmetic from original instructions; no image words, lookup tables or fitted cryptographic encoding parameters',
        'stage0_state': 'low BL starts at 0xd0, is saved/restored at frame -0x78, and advances by two while index advances by one; only bits 2 and 3 affect output',
        'stage1_state': 'low R13 byte starts at zero and advances by two while the index advances by one',
        'sources': {name: hashlib.sha256((package / name).read_bytes()).hexdigest()
                    for name in ('src/apple_music_source/_native/copy_codecs.c',
                                 'src/apple_music_source/_native/copy_codecs.h',
                                 'scripts/verify_copy_codecs.py')},
    }
    auth_sources = [row for row in copied if row['source'].startswith('crypto/auth/')]
    package_sources = (
        'build_backend.py',
        'README.md',
        'pyproject.toml',
        'src/apple_music_source/__init__.py',
        'src/apple_music_source/AUDIT.md',
        'src/apple_music_source/auth/__init__.py',
        'src/apple_music_source/auth/coreadi_source.py',
        'src/apple_music_source/auth/device_identity.py',
        'src/apple_music_source/auth/fast_login.py',
        'src/apple_music_source/auth/login_protocol.py',
        'src/apple_music_source/auth/mescal_source.py',
        'src/apple_music_source/auth/source_login.py',
        'src/apple_music_source/crypto/fps.py',
    )
    return {'scope': 'source provenance and historical address coverage; generated vendor-derived auth data is included as C source; no private account/session bytes',
            'copied_sources': copied, 'audited_source_sha256': {
                name: hashlib.sha256((root / name).read_bytes()).hexdigest() for name in sources},
            'package_source_sha256': {
                name: hashlib.sha256((package / name).read_bytes()).hexdigest() for name in package_sources},
            'vendor_derived_auth_data': {
                'coreadi': {'files': sum(row['source'].startswith('crypto/auth/coreadi/') for row in auth_sources),
                            'source_bytes': sum(row['bytes'] for row in auth_sources if row['source'].startswith('crypto/auth/coreadi/')),
                            'runtime': 'anonymous MID/OTP from existing adi.pb and Android ID'},
                'mescal': {'files': sum(row['source'].startswith('crypto/auth/mescal/') for row in auth_sources),
                           'source_bytes': sum(row['bytes'] for row in auth_sources if row['source'].startswith('crypto/auth/mescal/')),
                           'runtime': 'SAP signing and native GUID field derivation'},
                'fresh_provisioning': 'not included',
            },
            'source_fps_pipeline': {
                'files': sum(row['source'].startswith('crypto/keygen_experimental/') for row in copied),
                'source_bytes': sum(row['bytes'] for row in copied if row['source'].startswith('crypto/keygen_experimental/')),
                'runtime': 'source SPC/FPS session and CKC experimentation; online content-key derivation is not verified',
            },
            'reference_coverage_report': coverage_path, 'hooks': hook_summary,
            'data_manifests': manifests, 'recovered_data_models': recovered_models,
            'recovered_runtime_models': runtime_models}


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('source_checkout', type=Path)
    parser.add_argument('--output', type=Path)
    args = parser.parse_args()
    text = json.dumps(audit(args.source_checkout), indent=2) + '\n'
    if args.output:
        args.output.write_text(text)
    else:
        print(text, end='')
