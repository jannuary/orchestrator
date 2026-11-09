"""Emit decoded source control-flow references, not an image/word dump.

Only the evidence produced by probe_control_data is admitted. Every destination
must already exist in generated source or be a named import; every base term
must be a source address; the original source instruction recipe is rechecked.
The pinned ELF is a development oracle only. Package builds never run this.
"""
import argparse
import json
from pathlib import Path

from probe_control_data import Classifier
from verify_fill_dispatch import segment_read


def cells(root,report):
    classifier=Classifier(root,include_pristine_rw=True);result={}
    for row in report['rows']:
        pc=int(row['read_pc'],16);address=int(row['address'],16);width=row['width']
        target=int(row['target'],16);addend=int(row['addend'],16)
        assert row['effective_address_checked'] is True and width in (4,8) and address%4==0
        assert target in classifier.labels or target in classifier.imports
        recipe=classifier.recipe(pc,width);assert recipe is not None
        assert recipe['transfer_pc']==int(row['transfer_pc'],16) and recipe['signed']==row['signed']
        assert row.get('required_constant')==recipe['required_constant']
        assert row['transfer']==recipe['transfer']
        if 'store_pc' in recipe:
            assert int(row['store_pc'],16)==recipe['store_pc']
            assert row['frame_displacement']==recipe['frame_displacement']
            assert classifier.function_scope(target)==target
        expression=row['base_expression'];constant=int(expression['constant'],16)
        assert constant==recipe['addend']
        terms={t['register']:t['coefficient'] for t in expression['terms']}
        assert terms==recipe['base_terms']
        derived=constant
        for term in expression['terms']:
            base=int(term['source_address'],16)
            assert not base or base in classifier.labels or any(a<=base<b for a,b in classifier.readonly)
            derived+=term['coefficient']*base
        assert derived&((1<<64)-1)==addend
        readonly=any(a<=address and address+width<=b for a,b in classifier.readonly)
        assert readonly or width==8 and address in classifier.relative_candidates and target in classifier.labels
        expected=classifier.pristine_read(address,width);assert expected is not None
        reconstructed=(target-addend)&((1<<(width*8))-1)
        assert reconstructed==expected
        for offset in range(0,width,4):
            cell=address+offset;entry=dict(row,shift=offset*8)
            if cell in result:
                old=result[cell]
                old_word=((int(old['target'],16)-int(old['addend'],16))>>old['shift'])&0xffffffff
                assert old_word==(reconstructed>>(offset*8))&0xffffffff
                # Prefer a source-PC constant over a register-resolved base.
                if len(old['base_expression']['terms'])<=len(expression['terms']):continue
            result[cell]=entry
    return result


def emit(root,report,native):
    entries=cells(root,report)
    targets=sorted({int(row['target'],16) for row in entries.values()})
    bases=sorted({int(t['source_address'],16) for row in entries.values() for t in row['base_expression']['terms']})
    lines=['/* Recovered SOURCE CONTROL-FLOW GRAPH REFERENCES. No original image',
           ' * bytes, instruction words, cryptographic tables or integrity results.',
           ' * Each word is an explicit source destination relative to a base',
           ' * derived by the original load-to-transfer instruction sequence.',
           ' * Observed coverage only: unsupported addresses fail closed.',
           ' * Regenerate/verify with the developer scripts; no ELF is used by',
           ' * the build, installed library, or these functions. */',
           '#include "control_refs.h"','']
    lines += [f'#define AMS_CONTROL_LABEL_{a:x} UINT64_C(0x{a:x})' for a in targets]
    lines += [f'#define AMS_CONTROL_BASE_{a:x} UINT64_C(0x{a:x})' for a in bases]
    lines += ['','static int word_at(uint64_t address, uint32_t *value) {','    switch (address) {']
    for address,row in sorted(entries.items()):
        expression=row['base_expression'];terms=[f'UINT64_C({expression["constant"]})']
        for term in expression['terms']:
            base=int(term['source_address'],16);coefficient=term['coefficient']
            terms.append((' + ' if coefficient>0 else ' - ')+f'UINT64_C({abs(coefficient)}) * AMS_CONTROL_BASE_{base:x}')
        base=''.join(terms);target=int(row['target'],16)
        lines += [f'    /* {row["read_pc"]} -> {row["transfer"]} at {row["transfer_pc"]}: source destination {row["target"]}. */',
                  f'    case UINT64_C(0x{address:x}):',
                  f'        *value = (uint32_t)((AMS_CONTROL_LABEL_{target:x} - ({base})) >> {row["shift"]}); return 1;']
    lines += ['    default: return 0;','    }','}','',
              'int ams_control_refs_read(uint64_t address, unsigned width, uint64_t *output) {',
              '    uint64_t result = 0;', '    unsigned i;',
              '    if (!output || !width || width > 8 || address > UINT64_MAX - (width - 1)) return 0;',
              '    for (i = 0; i < width; ++i) {',
              '        uint64_t at = address + i; uint32_t word;',
              '        if (!word_at(at & ~UINT64_C(3), &word)) return 0;',
              '        result |= (uint64_t)((word >> (8 * (unsigned)(at & 3))) & 255) << (8 * i);',
              '    }','    *output = result; return 1;','}','']
    native.mkdir(parents=True,exist_ok=True)
    (native/'control_refs.c').write_text('\n'.join(lines))
    (native/'control_refs.h').write_text('''#ifndef AMS_CONTROL_REFS_H
#define AMS_CONTROL_REFS_H
#include <stdint.h>
/* Pristine source-control references at source-runner virtual addresses.
 * Unknown/cross-gap/overflow reads leave output unchanged. This initializes
 * ordinary memory; it must not replace mutable reads or permission checks.
 * This is not a complete image initializer or SPC/auth implementation. */
int ams_control_refs_read(uint64_t address, unsigned width, uint64_t *output);
#endif
''')
    return len(entries)


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('checkout',type=Path);p.add_argument('report',type=Path);p.add_argument('--native',type=Path,required=True)
    args=p.parse_args();report=json.loads(args.report.read_text())
    print(json.dumps(dict(control_cells=emit(args.checkout.resolve(),report,args.native),scope='decoded source control-reference model; remaining image/data dependencies unchanged')))


if __name__=='__main__':main()
