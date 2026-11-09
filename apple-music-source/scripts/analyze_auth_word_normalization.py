"""Verify one live CoreFP word decoder before classifying its substitution.

The source instructions, word array and fitted algebra are developer oracles
only. No words, encoding maps, keys or decoded values are emitted or shipped.
"""
import argparse
import ctypes as C
import hashlib
import json
from pathlib import Path
import random
import subprocess
import sys
import tempfile

from probe_substitution_equivalence import SEARCH, investigate
from scan_auth_substitutions import TARGETS
from verify_fill_dispatch import segment_read


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('checkout', type=Path)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    name, digest = TARGETS['corefp']
    image = (args.checkout / 'rootfs/system/lib64' / name).read_bytes()
    assert hashlib.sha256(image).hexdigest() == digest
    from capstone import Cs, CS_ARCH_X86, CS_MODE_64, CS_OP_REG, CS_OP_IMM, CS_OP_MEM
    decoder = Cs(CS_ARCH_X86, CS_MODE_64)
    decoder.detail = True
    def instruction(pc):
        return next(decoder.disasm(segment_read(image, pc, 16), pc, count=1))
    def register(ins, operand, name):
        return operand.type == CS_OP_REG and ins.reg_name(operand.reg) == name
    lea = instruction(0x3bd25e)
    assert lea.mnemonic == 'lea' and register(lea, lea.operands[0], 'rcx')
    assert lea.operands[1].type == CS_OP_MEM and lea.reg_name(lea.operands[1].mem.base) == 'rip'
    base = lea.address + lea.size + lea.operands[1].mem.disp
    load = instruction(0x3bd265)
    assert load.mnemonic == 'mov' and register(load, load.operands[0], 'esi')
    mem = load.operands[1]
    assert mem.type == CS_OP_MEM and mem.size == 4 and mem.mem.scale == 4
    assert load.reg_name(mem.mem.base) == 'rcx' and load.reg_name(mem.mem.index) == 'rsi' and not mem.mem.disp
    expected = [(0x3bd26b, 'lea', 'edi'), (0x3bd26e, 'add', 'edi'),
                (0x3bd274, 'and', 'edi'), (0x3bd27a, 'neg', 'edi'),
                (0x3bd27c, 'lea', 'r9d'), (0x3bd280, 'add', 'r9d')]
    instructions = [instruction(pc) for pc, _, _ in expected]
    for ins, (pc, mnemonic, destination) in zip(instructions, expected):
        assert ins.address == pc and ins.mnemonic == mnemonic and register(ins, ins.operands[0], destination)
    for index, registers in ((0, ('rsi', 'rsi')), (4, ('rsi', 'rdi'))):
        ins = instructions[index]
        assert ins.operands[1].type == CS_OP_MEM
        mem = ins.operands[1].mem
        assert (ins.reg_name(mem.base), ins.reg_name(mem.index)) == registers and mem.scale == 1 and not mem.disp
    assert all(instructions[i].operands[1].type == CS_OP_IMM for i in (1, 2, 5))
    add, mask, final = (instructions[i].operands[1].imm & 0xffffffff for i in (1, 2, 5))
    def normalize(word):
        return (word - (((2 * word + add) & 0xffffffff) & mask) + final) & 0xffffffff
    # Independently execute the original six instructions for every table word
    # and 128 invented words, with unrelated registers varied between trials.
    from unicorn import Uc, UC_ARCH_X86, UC_MODE_64
    from unicorn import x86_const as r
    begin, end = 0x3bd26b, 0x3bd287
    mu = Uc(UC_ARCH_X86, UC_MODE_64)
    mu.mem_map(begin & ~4095, 4096)
    mu.mem_write(begin, segment_read(image, begin, end - begin))
    data = segment_read(image, base, 1024)
    words = [int.from_bytes(data[j:j + 4], 'little') for j in range(0, 1024, 4)]
    rng = random.Random(0x734215)
    controls = words + [rng.getrandbits(32) for _ in range(128)]
    for word in controls:
        for register_ in (r.UC_X86_REG_RSI, r.UC_X86_REG_RDI, r.UC_X86_REG_R9):
            mu.reg_write(register_, rng.getrandbits(64))
        mu.reg_write(r.UC_X86_REG_ESI, word)
        mu.emu_start(begin, end, count=16)
        assert mu.reg_read(r.UC_X86_REG_R9D) == normalize(word)
    wrong = sum(normalize(word) != ((word + final) & 0xffffffff) for word in controls)
    assert wrong
    sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'src'))
    from apple_music_source.crypto.aes import _gpow
    from classify_runtime_tables import rank
    inverse = (C.c_uint8 * 256)(*(_gpow(x, 254) if x else 0 for x in range(256)))
    with tempfile.TemporaryDirectory(prefix='ams-auth-word-normalization-') as temporary:
        source, library = Path(temporary) / 'classify.c', Path(temporary) / 'classify.so'
        source.write_text(SEARCH)
        subprocess.run(['cc', '-std=c99', '-O3', '-shared', '-fPIC', str(source), '-o', str(library)], check=True, capture_output=True)
        search = C.CDLL(str(library)).equivalent
        search.argtypes = [C.POINTER(C.c_uint8), C.POINTER(C.c_uint8), C.POINTER(C.c_uint64), C.POINTER(C.c_uint8), C.POINTER(C.c_uint8)]
        search.restype = C.c_int
        normalized = [normalize(word) for word in words]
        report = dict(status='source word decoder verified and classified', target='corefp', artifact_sha256=digest,
            source_table=hex(base), source_load=hex(load.address), source_decoder_begin=hex(begin), source_decoder_end=hex(end),
            original_instruction_comparisons=len(controls), omitted_mask_control_mismatches=wrong,
            raw_affine_rank=rank([word ^ words[0] for word in words]),
            normalized_affine_rank=rank([word ^ normalized[0] for word in normalized]),
            raw_substitution=investigate(words, search, inverse),
            normalized_substitution=investigate(normalized, search, inverse),
            scope='one live word decoder and complete 256-word mathematical relation; no table initializer, key recovery, whole cipher or native-auth implementation; all words/constants/maps RAM-only')
    args.output.write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps(report))


if __name__ == '__main__':
    main()
