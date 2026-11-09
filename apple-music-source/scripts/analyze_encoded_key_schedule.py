"""Analyze AES round-key arithmetic without retaining target table encodings.

Developer only. Raw round keys, matrices, masks and all intermediate values stay
in RAM. Public results contain proof counts and structural relations only.
"""
from functools import reduce


def analyze(trace, details, regular, encoded_callback=None):
    z = trace.z
    model = details['model']
    ordinals = {ordinal: i for i, ordinal in enumerate(regular)}
    labels = details['first_group_labels'].copy()
    layers, groups = details['layers'], details['groups']
    keys = []
    verdicts = {}
    for level in range(1, len(layers)):
        previous = {event['variable']: event for event in layers[level - 1]}
        if level > 1:
            next_labels = {}
            for group in groups[level]:
                columns = {
                    (labels[tuple(sorted(previous[variable]['dependencies']))]
                     - model['input_rows'][ordinals[previous[variable]['ordinal']]]) % 4
                    for variable in group
                }
                if len(columns) != 1:
                    return dict(status='inconsistent ShiftRows labels', target_parameters_emitted=False)
                next_labels[group] = columns.pop()
            if set(next_labels.values()) != set(range(4)):
                return dict(status='inconsistent column labels', target_parameters_emitted=False)
            labels = next_labels
        key = [None] * 16
        for event in layers[level]:
            group = tuple(sorted(event['dependencies']))
            i = ordinals[event['ordinal']]
            physical_row = model['input_positions'][i]
            word = reduce(lambda a, b: a ^ b,
                          (trace.word_expressions[variable] for variable in group))
            projected = z.Extract(8 * physical_row + 7, 8 * physical_row, word)
            delta = z.simplify(event['expression'] ^ projected)
            origin = z.simplify(z.substitute(delta, *[
                (trace.word_expressions[variable], trace.literal(0, 32)) for variable in group]))
            if not z.is_bv_value(origin):
                return dict(status='nonconstant zero-word projection', target_parameters_emitted=False)
            constant = origin.as_long()
            solver = z.Solver()
            solver.set(timeout=1500)
            solver.add(delta != trace.literal(constant, 8))
            verdict = str(solver.check())
            verdicts[verdict] = verdicts.get(verdict, 0) + 1
            if verdict != 'unsat':
                return dict(status='source XOR projection not proved',
                            bitvector_proof_outcomes=verdicts,
                            target_parameters_emitted=False)
            row = model['input_rows'][i]
            position = 4 * labels[group] + row
            assert key[position] is None
            key[position] = constant
        assert all(value is not None for value in key)
        keys.append(bytes(key))
    offsets = []
    for row in range(4):
        deltas = {
            keys[level][4 * column + row]
            ^ keys[level - 1][4 * column + row]
            ^ keys[level][4 * (column - 1) + row]
            for level in range(1, len(keys)) for column in range(1, 4)
        }
        if len(deltas) != 1:
            return dict(status='no common affine row offset',
                        bitvector_proof_outcomes=verdicts,
                        target_parameters_emitted=False)
        offsets.append(deltas.pop())
    if encoded_callback is not None:
        encoded_callback(keys, offsets)
    return dict(status='source XOR projection and affine key-recurrence relation proved',
                observed_round_keys=len(keys),
                bitvector_proof_outcomes=verdicts,
                common_affine_offset_per_row=True,
                target_parameters_emitted=False,
                scope='unconstrained word32 projection proofs on observed source path; row/column labels still supplied by developer table analysis; no independent key recovery or parameter factory')
