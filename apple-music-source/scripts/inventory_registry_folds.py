"""Pinned-ELF static inventory of a specific eight-read fold sequence.

This is a bounded pattern inventory, not an exhaustive proof of all bank access
or executable reachability. Reports contain addresses/counts only, never image
bytes. The generated-native label comparison does not audit graph fallbacks.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re
import sys

sys.path.insert(0, str(Path(__file__).resolve().parent))
from verify_integrity_codec import HASH


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('checkout', type=Path)
    p.add_argument('--output', type=Path, required=True)
    a = p.parse_args()
    root = a.checkout.resolve()
    raw = (root / 'rootfs/system/lib64/libCoreLSKD.so').read_bytes()
    assert hashlib.sha256(raw).hexdigest() == HASH
    from capstone import Cs, CS_ARCH_X86, CS_MODE_64, CS_OP_MEM, CS_OP_REG
    decoder = Cs(CS_ARCH_X86, CS_MODE_64)
    decoder.detail = True
    labels = set()
    for page in (root / 'crypto/keygen_experimental/native_generated').glob('block_page_*.c'):
        labels.update(int(m[1], 16) for line in page.open() if
                      (m := re.match(r'kg_pc_([0-9a-f]+): STEP', line)))
    marker = (0x643e71bb8d1a2f56).to_bytes(8, 'little')
    start, candidates, sequences = 0, 0, []
    while (at := raw.find(marker, start)) != -1:
        start = at + 1
        if not 0xdc000 <= at < 0x666000:
            continue
        ins = list(decoder.disasm(raw[at-2:at+180], at-2))
        if not ins or ins[0].mnemonic != 'movabs':
            continue
        candidates += 1
        reads = [i for i in ins if i.mnemonic == 'xor' and len(i.operands) == 2
                 and i.operands[0].type == CS_OP_REG and i.operands[0].size == 4
                 and i.operands[1].type == CS_OP_MEM and i.operands[1].size == 4
                 and i.operands[1].mem.base and i.operands[1].mem.index
                 and i.operands[1].mem.scale == 1 and not i.operands[1].mem.disp]
        if len(reads) != 8:
            continue
        if len({i.operands[1].mem.base for i in reads}) != 1:
            continue
        sequences.append(dict(header=hex(at-2), first_read=hex(reads[0].address),
                              last_read=hex(reads[-1].address), reads=8,
                              accumulator_registers=len({i.operands[0].reg for i in reads}),
                              generated_native_entry_present=reads[0].address in labels))
    known = {0x1b65fb, 0x207b91, 0x23915b, 0x3ede57, 0x3ee66f,
             0x4b7898, 0x4bc9da, 0x50cb28, 0x50d8b3}
    assert known <= {int(row['first_read'], 16) for row in sequences}
    assert len(sequences) == 20
    report = dict(artifact_sha256=HASH, constant_header_candidates=candidates,
                  eight_read_sequences=len(sequences),
                  generated_native_entries=sum(r['generated_native_entry_present'] for r in sequences),
                  sequences=sequences,
                  clear_tag_stores=[dict(pc=hex(pc), generated_native_entry_present=pc in labels)
                                    for pc in (0x1b99ff, 0x3f0cc7)],
                  scope='static specific-pattern matches only; no complete bank-access inventory, CFG reachability, graph-fallback audit, runtime/lifetime or cancellation proof')
    a.output.write_text(json.dumps(report, indent=2)+'\n')
    print(json.dumps({k: v for k, v in report.items() if k not in ('sequences', 'clear_tag_stores')}))


if __name__ == '__main__':
    main()
