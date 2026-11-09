"""Prove which lookup-result bits can affect middle-span observations.

Dynamic byte reads are independent symbolic values. Every byte-read address
and every memory write is observed, so discarded bits cannot hide effects in
later memory lookups. Actual inputs and symbolic expressions stay in RAM.
"""
from __future__ import annotations

import argparse
import json
from pathlib import Path
from typing import Any, Final

from replay_guid_record_middle import (
    GuidMiddleOracle, FORWARD_LAYOUT, HASH_LAYOUT, MIDDLE_START_ADDRESS, MIDDLE_END_ADDRESS, MAXIMUM_INSTRUCTIONS,
    LOOKUP_START_ADDRESS, LOOKUP_BYTE_COUNT, FIRST_FOLD_FRAME_OFFSET,
    SECOND_FOLD_FRAME_OFFSET, EXPANDED_STATE_FRAME_OFFSET, FOLD_BYTE_COUNT,
    EXPANDED_STATE_BYTE_COUNT, INVENTED_ANDROID_IDENTIFIERS, GPR_NAMES,
)
from trace_lookup_dataflow import LookupTrace

BYTE_BIT_COUNT: Final[int] = 8
BYTE_VALUE_MASK: Final[int] = 255
ADDRESS_BIT_COUNT: Final[int] = 64
PROOF_TIMEOUT_MILLISECONDS: Final[int] = 5000


class MiddleDataflow(LookupTrace):
    def __init__(self, oracle: GuidMiddleOracle) -> None:
        super().__init__(oracle.unicorn, [], [], [])
        self.oracle = oracle
        self.lookup_events: list[dict[str, Any]] = []
        self.program_events: list[dict[str, Any]] = []
        self.observations: list[Any] = []
        self.range_proofs: list[str] = []
        self.extra_instruction_count = 0
        self.observed_memory_writes = 0
        self.input_bindings: dict[str, str] = {}
        self.input_counts: dict[str, int] = {}
        self.byte_windows = (
            (oracle.layout.lookup_address, LOOKUP_BYTE_COUNT, 'external'),
            (oracle.frame_address - FIRST_FOLD_FRAME_OFFSET, FOLD_BYTE_COUNT, 'first_fold'),
            (oracle.frame_address - SECOND_FOLD_FRAME_OFFSET, FOLD_BYTE_COUNT, 'second_fold'),
        )

    def add_symbolic_byte(self, address: int, role: str) -> None:
        variable_number = len(self.variables)
        variable = self.z.BitVec(f'{role}_{variable_number}', BYTE_BIT_COUNT)
        self.variables.append(variable)
        self.values.append(self.oracle.unicorn.mem_read(address, 1)[0])
        self.variable_names[str(variable)] = variable_number
        self.memory[address] = variable
        input_names = {'expanded_input':'expanded_state', 'second_fold_input':'initial_fold_state', 'seed_input':'readonly_seed'}
        input_number = self.input_counts.get(role, 0)
        self.input_counts[role] = input_number + 1
        self.input_bindings[str(variable)] = f'{input_names[role]}[{input_number}]' 

    def read(self, machine: Any, instruction: Any, operand: Any) -> Any:
        from capstone import CS_OP_MEM
        if operand.type != CS_OP_MEM or operand.size != 1:
            return super().read(machine, instruction, operand)
        address_expression = self.address(machine, instruction, operand)
        concrete_address = self.concrete(address_expression)
        external = self.oracle.layout.lookup_address <= concrete_address < self.oracle.layout.lookup_address + LOOKUP_BYTE_COUNT
        if not external and not self.dependencies(address_expression):
            return super().read(machine, instruction, operand)
        matching_window = next((window for window in self.byte_windows if window[0] <= concrete_address < window[0] + window[1]), None)
        if matching_window is None:
            raise ValueError('symbolic byte read left the three bounded lookup windows')
        window_start, window_size, role = matching_window
        solver = self.z.Solver()
        solver.set(timeout=PROOF_TIMEOUT_MILLISECONDS)
        inside_window = self.z.And(self.z.UGE(address_expression, window_start), self.z.ULT(address_expression, window_start + window_size))
        solver.add(self.z.Not(inside_window))
        verdict = solver.check()
        self.range_proofs.append(str(verdict))
        if verdict != self.z.unsat:
            raise ValueError('byte-read address bound was not proved')
        self.observations.append(address_expression)
        variable_number = len(self.variables)
        variable = self.z.BitVec(f'read_result_{variable_number}', BYTE_BIT_COUNT)
        self.variables.append(variable)
        self.values.append(machine.mem_read(concrete_address, 1)[0])
        self.variable_names[str(variable)] = variable_number
        window_values = None if role == 'external' else tuple(self.memory[window_start + index] for index in range(window_size))
        event = dict(kind='lookup',source_PC=instruction.address,role=role,variable_number=variable_number,index_expression=self.z.simplify(address_expression-window_start),window_values=window_values)
        self.lookup_events.append(event)
        self.program_events.append(event)
        return variable

    def write(self, machine: Any, instruction: Any, operand: Any, value: Any) -> None:
        from capstone import CS_OP_MEM
        if operand.type == CS_OP_MEM:
            self.observations.append(value)
            self.observed_memory_writes += 1
            address = self.concrete(self.address(machine, instruction, operand))
            self.program_events.append(dict(kind='write',address=address,width=operand.size,value=self.resize(value,operand.size*8)))
        super().write(machine, instruction, operand, value)

    def step_middle(self, machine: Any, program_counter: int, instruction_size: int, user_data: Any) -> None:
        instruction = self.oracle.instructions[program_counter]
        if instruction.mnemonic == 'movaps':
            self.extra_instruction_count += 1
            value = self.read(machine, instruction, instruction.operands[1])
            self.write(machine, instruction, instruction.operands[0], value)
            return
        if instruction.mnemonic == 'mul':
            self.extra_instruction_count += 1
            left = self.reg(machine, 'al')
            right = self.resize(self.read(machine, instruction, instruction.operands[0]), BYTE_BIT_COUNT)
            product = self.z.ZeroExt(BYTE_BIT_COUNT, left) * self.z.ZeroExt(BYTE_BIT_COUNT, right)
            self.put_reg(machine, 'ax', product)
            high_product = self.z.Extract(2 * BYTE_BIT_COUNT - 1, BYTE_BIT_COUNT, product)
            self.flags['cf'] = self.flags['of'] = high_product != 0
            return
        super().step(machine, program_counter, instruction_size)

    def prove_unused_bits(self, event: dict[str, Any]) -> dict[str, Any]:
        variable_number = event['variable_number']
        variable = self.variables[variable_number]
        dependent_observations = [observation for observation in self.observations if variable_number in self.dependencies(observation)]
        outcomes: dict[str, list[int]] = {'unsat': [], 'sat': [], 'unknown': []}
        for bit_number in range(BYTE_BIT_COUNT):
            flipped_value = variable ^ (1 << bit_number)
            differences = [observation != self.z.substitute(observation, (variable, flipped_value)) for observation in dependent_observations]
            solver = self.z.Solver()
            solver.set(timeout=PROOF_TIMEOUT_MILLISECONDS)
            solver.add(self.z.Or(*differences))
            verdict = str(solver.check())
            outcomes[verdict].append(bit_number)
        return dict(source_PC=hex(event['source_PC']),role=event['role'],observations_checked=len(dependent_observations),proven_ignored_bits=outcomes['unsat'],not_proven_ignored_bits=outcomes['sat'],unknown_bits=outcomes['unknown'])


def main() -> None:
    from unicorn import UC_HOOK_CODE
    from capstone import CS_OP_MEM

    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('checkout', type=Path)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--emit-source', type=Path)
    parser.add_argument('--kind', choices=('forward', 'hash'), default='forward')
    arguments = parser.parse_args()
    layout = HASH_LAYOUT if arguments.kind == 'hash' else FORWARD_LAYOUT
    with GuidMiddleOracle(arguments.checkout.resolve(), layout) as oracle:
        invented_input = INVENTED_ANDROID_IDENTIFIERS[0] if arguments.kind == 'forward' else bytes(index ^ 0x47 for index in range(80))
        oracle.prepare_state(invented_input)
        trace = MiddleDataflow(oracle)
        for role, frame_offset, length in (
            ('expanded_input', EXPANDED_STATE_FRAME_OFFSET, EXPANDED_STATE_BYTE_COUNT),
            ('second_fold_input', SECOND_FOLD_FRAME_OFFSET, FOLD_BYTE_COUNT),
        ):
            for byte_offset in range(length):
                trace.add_symbolic_byte(oracle.frame_address - frame_offset + byte_offset, role)
        for instruction in oracle.instructions.values():
            if instruction.mnemonic != 'movaps':
                continue
            for operand in instruction.operands:
                if operand.type == CS_OP_MEM and instruction.reg_name(operand.mem.base) == 'rip':
                    source_address = instruction.address + instruction.size + operand.mem.disp
                    for byte_offset in range(operand.size):
                        trace.add_symbolic_byte(source_address + byte_offset, 'seed_input')
        hook = oracle.unicorn.hook_add(UC_HOOK_CODE, trace.step_middle)
        oracle.unicorn.emu_start(layout.start_address, layout.end_address, count=MAXIMUM_INSTRUCTIONS)
        oracle.unicorn.hook_del(hook)
        if not trace.active or trace.errors:
            raise RuntimeError(json.dumps(trace.summary()))
        register_checks = 0
        for register_name in GPR_NAMES:
            expected = oracle.unicorn.reg_read(getattr(oracle.register_ids, 'UC_X86_REG_' + register_name.upper()))
            if trace.concrete(trace.reg(oracle.unicorn, register_name)) != expected:
                raise ValueError('symbolic register replay differs from original execution')
            register_checks += 1
        for address, expression in trace.memory.items():
            if trace.concrete(expression) != oracle.unicorn.mem_read(address, 1)[0]:
                raise ValueError('symbolic byte replay differs from original execution')
        generated_model = None
        if arguments.emit_source is not None:
            from emit_guid_middle_source import emit_middle_source
            generated_model = emit_middle_source(trace, oracle, arguments.emit_source)
        results: list[dict[str, Any]] = []
        for event in trace.lookup_events:
            if event['role'] != 'external':
                continue
            result = trace.prove_unused_bits(event)
            results.append(result)
            print(json.dumps(dict(progress='external lookup projection',source_PC=result['source_PC'],proven_ignored_bits=result['proven_ignored_bits'])), flush=True)
        report = dict(status='middle abstract dataflow checked',kind=layout.name,instructions=trace.instructions + trace.extra_instruction_count,register_replay_checks=register_checks,symbolic_memory_bytes=len(trace.memory),bounded_byte_reads=len(trace.lookup_events),address_range_proofs=trace.range_proofs,observed_memory_writes=trace.observed_memory_writes,external_lookup_bit_proofs=results,network_requests=0,private_material_written=False,generated_model=generated_model,scope='independent dynamic reads with every memory write/address observed; unused-bit proofs preserve those observations, not a complete source middle implementation')
    arguments.output.write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps({key:value for key,value in report.items() if key not in ('external_lookup_bit_proofs','address_range_proofs')}))


if __name__ == '__main__':
    main()
