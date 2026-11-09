"""Inventory references and storage provenance of unresolved GUID parameters.

Only source PCs, ranges and operand roles are reported. Artifact contents,
lookup indices, parameter values and device buffers stay in RAM. Instruction
starts come from the existing translation and are checked against the ELF.
This is a bounded reference inventory, not proof that no indirect writer exists.
"""
from __future__ import annotations

import argparse
from dataclasses import dataclass
import hashlib
import json
from pathlib import Path
import re
import struct
from typing import Final

from replay_guid_record_middle import GuidMiddleOracle, FORWARD_LAYOUT, HASH_LAYOUT
from emit_guid_middle_source import readonly_seed_locations
from scan_auth_substitutions import TARGETS
from verify_fill_dispatch import segment_read

ELF_LOAD_SEGMENT: Final[int] = 1
ELF_WRITE_PERMISSION: Final[int] = 2
ELF_RELOCATION_SECTION: Final[frozenset[int]] = frozenset((4, 9))
TRANSLATED_RIP_INSTRUCTION: Final[re.Pattern[str]] = re.compile(r'STEP\(0x([0-9a-f]+)\); /\* [^\n]*\brip\b')


@dataclass(frozen=True)
class ParameterRegion:
    role: str
    address: int
    size: int


def load_segments(image: bytes) -> list[tuple[int, int, int]]:
    offset = struct.unpack_from('<Q', image, 32)[0]
    stride, count = struct.unpack_from('<HH', image, 54)
    segments: list[tuple[int, int, int]] = []
    for index in range(count):
        kind, flags, _, address, _, size, _, _ = struct.unpack_from('<IIQQQQQQ', image, offset + index * stride)
        if kind == ELF_LOAD_SEGMENT:
            segments.append((address, size, flags))
    return segments


def relocated_addresses(image: bytes) -> set[int]:
    offset = struct.unpack_from('<Q', image, 40)[0]
    stride, count = struct.unpack_from('<HH', image, 58)
    addresses: set[int] = set()
    for index in range(count):
        _, kind, _, _, file_offset, size, _, _, _, entry_size = struct.unpack_from('<IIQQQQIIQQ', image, offset + index * stride)
        if kind not in ELF_RELOCATION_SECTION:
            continue
        for position in range(file_offset, file_offset + size, entry_size):
            addresses.add(struct.unpack_from('<Q', image, position)[0])
    return addresses


def main() -> None:
    from capstone import Cs, CS_ARCH_X86, CS_MODE_64, CS_OP_MEM, CS_AC_WRITE

    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('checkout', type=Path)
    parser.add_argument('--output', type=Path, required=True)
    arguments = parser.parse_args()
    root = arguments.checkout.resolve()
    filename, digest = TARGETS['corefp']
    image = (root / 'rootfs/system/lib64' / filename).read_bytes()
    if hashlib.sha256(image).hexdigest() != digest:
        raise ValueError('CoreFP artifact identity mismatch')
    regions: list[ParameterRegion] = []
    for layout in (FORWARD_LAYOUT, HASH_LAYOUT):
        with GuidMiddleOracle(root, layout) as oracle:
            regions.extend((ParameterRegion(layout.name + '_initial_state', layout.initial_state_address, 64), ParameterRegion(layout.name + '_lookup', layout.lookup_address, 64)))
            regions.extend(ParameterRegion(layout.name + '_readonly_seed_' + str(index), address, size) for index, (address, size) in enumerate(readonly_seed_locations(oracle)))
    candidates: set[int] = set()
    files = sorted((root / 'crypto/auth/mescal/generated').glob('mescal_corefp_page_*.c'))
    for source in files:
        candidates.update(int(match, 16) for match in TRANSLATED_RIP_INSTRUCTION.findall(source.read_text()))
    decoder = Cs(CS_ARCH_X86, CS_MODE_64)
    decoder.detail = True
    references: dict[str, list[dict[str, object]]] = {region.role: [] for region in regions}
    overlap_references: list[dict[str, object]] = []
    for address in sorted(candidates):
        instruction = next(decoder.disasm(segment_read(image, address, 15), address))
        for operand in instruction.operands:
            if operand.type != CS_OP_MEM or instruction.reg_name(operand.mem.base) != 'rip':
                continue
            target = instruction.address + instruction.size + operand.mem.disp
            for region in regions:
                if target >= region.address + region.size or target + operand.size <= region.address:
                    continue
                role = 'address_materialization' if instruction.mnemonic == 'lea' else 'direct_write' if operand.access & CS_AC_WRITE else 'direct_read'
                item = dict(source_PC=hex(address),operation=instruction.mnemonic,role=role,region_offset=target-region.address,operand_bytes=operand.size)
                if region.address <= target and target + operand.size <= region.address + region.size:
                    references[region.role].append(item)
                else:
                    overlap_references.append(dict(region=region.role,**item))
    segments = load_segments(image)
    relocations = relocated_addresses(image)
    rows: list[dict[str, object]] = []
    for region in regions:
        matching = [entry for entry in segments if entry[0] <= region.address and region.address + region.size <= entry[0] + entry[1]]
        if len(matching) != 1:
            raise ValueError('parameter range is not in one file-backed load segment')
        rows.append(dict(role=region.role,source_range=[hex(region.address),hex(region.address+region.size)],bytes=region.size,writable_segment=bool(matching[0][2] & ELF_WRITE_PERMISSION),relocation_sites=sum(region.address<=address<region.address+region.size for address in relocations),references=references[region.role]))
    report = dict(status='bounded GUID parameter origin inventory',artifact_sha256=digest,translated_source_files=len(files),translated_RIP_instruction_starts=len(candidates),parameter_bytes=sum(region.size for region in regions),regions=rows,overlapping_references=overlap_references,network_requests=0,parameter_values_emitted=False,private_material_written=False,scope='direct RIP-relative references at translated instruction starts and ELF storage/relocation metadata; indirect references, ungenerated code and semantic parameter generation remain unresolved')
    arguments.output.write_text(json.dumps(report,indent=2)+'\n')
    print(json.dumps(dict(status=report['status'],parameter_regions=len(rows),parameter_bytes=report['parameter_bytes'],direct_references=sum(len(row['references']) for row in rows),writable_regions=sum(row['writable_segment'] for row in rows),relocation_sites=sum(row['relocation_sites'] for row in rows))))


if __name__ == '__main__':
    main()
