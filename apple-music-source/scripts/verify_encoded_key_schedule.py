"""Invented positive/negative controls for encoded round-key arithmetic."""
import argparse
import json
from pathlib import Path
import random
import sys
from types import SimpleNamespace
from functools import reduce

from analyze_encoded_key_schedule import analyze
from analyze_table_algebra import Basis, apply


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    import z3 as z
    sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'src'))
    from apple_music_source.crypto import AES
    rng = random.Random(0x125447)
    cipher = AES(bytes(rng.randrange(256) for _ in range(16)))
    columns = []
    for row in range(4):
        matrix = [1 << j for j in range(8)]
        for _ in range(40):
            a, b = rng.sample(range(8), 2)
            matrix[a] ^= matrix[b]
        columns.append(matrix)
    offsets = [rng.randrange(256) for _ in range(4)]
    encoded = [bytes(Basis(columns[j % 4]).coordinates(value) ^ offsets[j % 4]
                     for j, value in enumerate(key)) for key in cipher._round_keys[1:8]]
    physical = (2, 0, 3, 1)

    def construct(wrong_projection=False, wrong_recurrence=False):
        layers, groups, variables = [], [None], []
        for level in range(8):
            layer = []
            for column in range(4):
                for row in range(4):
                    variable = len(variables)
                    variables.append(z.BitVec('lookup_' + str(variable), 32))
                    dependencies = tuple(sorted(layers[-1][4 * ((column + r) % 4) + r]['variable'] for r in range(4))) if level else ()
                    expression = z.BitVecVal(0, 8)
                    if level:
                        word = reduce(lambda a, b: a ^ b, (variables[j] for j in dependencies))
                        projection = z.Extract(8 * physical[row] + 7, 8 * physical[row], word)
                        constant = encoded[level - 1][4 * column + row]
                        if wrong_recurrence and level == 2 and column == 1 and row == 0:
                            constant ^= 1
                        expression = projection ^ constant
                        if wrong_projection and level == 1 and column == 0 and row == 0:
                            expression += 1
                    layer.append(dict(variable=variable, ordinal=row, expression=expression, dependencies=dependencies))
            layers.append(layer)
            if level:
                groups.append(sorted({tuple(event['dependencies']) for event in layer}))
        labels = {tuple(layers[1][4 * column]['dependencies']): column for column in range(4)}
        trace = SimpleNamespace(z=z, word_expressions=dict(enumerate(variables)),
            literal=lambda value, width: z.BitVecVal(value, width))
        details = dict(layers=layers, groups=groups, first_group_labels=labels,
                       model=dict(input_rows=(0, 1, 2, 3), input_positions=physical))
        return trace, details

    trace, details = construct()
    checked = []
    def check(keys, found_offsets):
        assert keys == encoded and found_offsets == offsets
        checked.append(True)
    positive = analyze(trace, details, range(4), check)
    assert checked == [True] and positive['bitvector_proof_outcomes'] == {'unsat': 112}
    trace, details = construct(wrong_projection=True)
    negative_projection = analyze(trace, details, range(4))
    assert negative_projection['status'] == 'source XOR projection not proved'
    trace, details = construct(wrong_recurrence=True)
    negative_recurrence = analyze(trace, details, range(4))
    assert negative_recurrence['status'] == 'no common affine row offset'
    report = dict(status='pass', positive=positive,
                  nonlinear_projection_rejected=True, wrong_key_recurrence_rejected=True,
                  scope='invented keys, encodings and words only; no crypto bytes emitted')
    args.output.write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps(report))


if __name__ == '__main__':
    main()
