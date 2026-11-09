"""Prove normalization controls, including a sampling-resistant false identity."""
import argparse
from functools import reduce
import json
from pathlib import Path

from trace_lookup_dataflow import LookupTrace


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    trace = LookupTrace(None, [], [], [])
    z = trace.z
    variables = [z.BitVec('lookup_' + str(j), 32) for j in range(4)]
    trace.word_expressions = dict(enumerate(variables))
    trace.variable_names = {str(variable): j for j, variable in enumerate(variables)}
    word = reduce(lambda a, b: a ^ b, variables)
    disguised = ((variables[0] | variables[1]) - (variables[0] & variables[1])) ^ variables[2] ^ variables[3]
    for byte in range(4):
        candidate = z.Extract(8 * byte + 7, 8 * byte, word) ^ 37
        original = z.Extract(8 * byte + 7, 8 * byte, disguised) ^ 37
        normalized = trace.normalize_index(original)
        assert z.eq(normalized, z.simplify(candidate))
    assert trace.index_normalizations['unsat'] == 4
    # It agrees at zero and at both filter assignments. A solver must still
    # find its counterexample; the filters may never license normalization.
    false_identity = z.Extract(7, 0, word) ^ z.If(word == 0x10203040, z.BitVecVal(1, 8), z.BitVecVal(0, 8))
    assert z.eq(trace.normalize_index(false_identity), false_identity)
    assert trace.index_normalizations['sat'] == 1
    three_words = z.Extract(7, 0, variables[0] ^ variables[1] ^ variables[2])
    assert z.eq(trace.normalize_index(three_words), three_words)
    report = dict(status='pass', proved_byte_projections=4,
                  sampling_resistant_counterexample_rejected=True,
                  unsupported_dependency_count_preserved=True,
                  proof_outcomes=dict(trace.index_normalizations),
                  scope='invented symbolic words only; no target parameters or data')
    args.output.write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps(report))


if __name__ == '__main__':
    main()
