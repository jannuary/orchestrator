"""Emit a parametric source model from the middle-span arithmetic DAG.

All image-data reads become explicit byte-array parameters. Emitted code has
no instruction decoder, native addresses, vendor loader or captured state.
"""
from __future__ import annotations

import importlib.util
from pathlib import Path
from typing import Any, Final

from guid_record_tail_model import SCALAR_FRAME_OFFSETS
from replay_guid_record_middle import (
    MIDDLE_START_ADDRESS, MIDDLE_END_ADDRESS, MAXIMUM_INSTRUCTIONS,
    EXPANDED_STATE_FRAME_OFFSET, EXPANDED_STATE_BYTE_COUNT,
    FIRST_FOLD_FRAME_OFFSET, SECOND_FOLD_FRAME_OFFSET, FOLD_BYTE_COUNT,
    LOOKUP_START_ADDRESS, LOOKUP_BYTE_COUNT, INVENTED_ANDROID_IDENTIFIERS,
)

INPUT_SHAPES: Final[tuple[int, ...]] = (328, 64, 48, 64)
MAXIMUM_UNARY_SEARCH_NODES: Final[int] = 256
MAXIMUM_UNARY_CANDIDATES: Final[int] = 4


class ArithmeticEmitter:
    def __init__(self, trace: Any) -> None:
        self.trace = trace
        self.layout = trace.oracle.layout
        self.input_shapes = (328, 64, trace.input_counts['seed_input'], 64)
        self.bindings = dict(trace.input_bindings)
        self.nodes: dict[int, tuple[Any, str]] = {}
        self.lines: list[str] = []
        self.mask_widths: set[int] = set()
        self.snapshots: dict[tuple[int, ...], str] = {}
        self.lookup_number = 0
        self.memory_updates = 0
        self.unary_rewrites = 0
        self.composite_byte_rewrites = 0
        self.unary_cache: dict[int, tuple[Any, str | None]] = {}

    def mask_name(self, width: int) -> str:
        self.mask_widths.add(width)
        return f'MASK_{width}'

    def unary_subject(self, expression: Any) -> tuple[Any, Any] | None:
        dependencies = self.trace.dependencies(expression)
        if len(dependencies) == 1:
            variable = self.trace.variables[next(iter(dependencies))]
            if variable.size() == 8 and str(variable) in self.bindings:
                return variable, expression
            return None
        if len(dependencies) < 2:
            return None
        references: dict[int, int] = {}
        nodes: dict[int, Any] = {}
        pending = [expression]
        visited: set[int] = set()
        for node in pending:
            identifier = node.get_id()
            if identifier in visited:
                continue
            visited.add(identifier)
            if len(visited) > MAXIMUM_UNARY_SEARCH_NODES:
                return None
            for child in node.children():
                child_id = child.get_id()
                references[child_id] = references.get(child_id, 0) + 1
                nodes[child_id] = child
                pending.append(child)
        attempted_candidates = 0
        for identifier, subject in nodes.items():
            if references[identifier] < 2 or not self.trace.z.is_bv(subject) or subject.size() != 8:
                continue
            if self.trace.dependencies(subject) != dependencies:
                continue
            attempted_candidates += 1
            if attempted_candidates > MAXIMUM_UNARY_CANDIDATES:
                return None
            unexplored = [expression]
            checked: set[int] = set()
            dominates = True
            while unexplored:
                node = unexplored.pop()
                node_id = node.get_id()
                if node_id == identifier or node_id in checked or not self.trace.dependencies(node):
                    continue
                checked.add(node_id)
                if not node.children():
                    dominates = False
                    break
                unexplored.extend(node.children())
            if dominates:
                variable = self.trace.z.BitVec('unary_subject_' + str(expression.get_id()), 8)
                return subject, self.trace.z.substitute(expression, (subject, variable))
        return None

    def compact_unary(self, expression: Any) -> str | None:
        identifier = expression.get_id()
        if identifier in self.unary_cache:
            return self.unary_cache[identifier][1]
        subject_result = self.unary_subject(expression)
        if subject_result is None:
            self.unary_cache[identifier] = (expression, None)
            return None
        subject, evaluated_expression = subject_result
        composite_subject = not self.trace.z.is_const(subject)
        variable = self.trace.z.BitVec('unary_subject_' + str(identifier), 8) if composite_subject else subject
        width = expression.size()
        output_mask = (1 << width) - 1
        outputs: list[int] = []
        for value in range(256):
            evaluated = self.trace.z.simplify(self.trace.z.substitute(evaluated_expression, (variable, self.trace.literal(value, 8))))
            if not self.trace.z.is_bv_value(evaluated):
                self.unary_cache[identifier] = (expression, None)
                return None
            outputs.append(evaluated.as_long())
        binding = '(' + (self.render(subject) if composite_subject else self.bindings[str(variable)]) + ')'
        base = outputs[0]
        multiplier = (outputs[1] - base) & output_mask
        result: str | None = None
        if all(output == (base + multiplier * value) & output_mask for value, output in enumerate(outputs)):
            if not multiplier:
                result = hex(base)
            else:
                term = binding if multiplier == 1 else f'({binding} * {hex(multiplier)})'
                term = term if not base else f'({term} + {hex(base)})'
                result = f'({term}) & {self.mask_name(width)}'
        elif all(output == value ^ base for value, output in enumerate(outputs)):
            result = f'({binding} ^ {hex(base)})'
        else:
            columns = [outputs[1 << bit] ^ base for bit in range(8)]
            predicted: list[int] = []
            for value in range(256):
                transformed = base
                for bit, column in enumerate(columns):
                    if value & (1 << bit):
                        transformed ^= column
                predicted.append(transformed)
            if predicted == outputs and all(not column or column & (column - 1) == 0 for column in columns):
                placements = [(bit, column.bit_length() - 1) for bit, column in enumerate(columns) if column]
                shifts = {output_bit - input_bit for input_bit, output_bit in placements}
                output_bits = sum(column for column in set(columns))
                if len(shifts) == 1:
                    shift = next(iter(shifts))
                    term = binding if not shift else f'({binding} {"<<" if shift > 0 else ">>"} {abs(shift)})'
                    result = f'(({term}) & {hex(output_bits)}) ^ {hex(base)}'
                elif placements and max(output_bit for _, output_bit in placements) < 8:
                    rotations = {(output_bit - input_bit) % 8 for input_bit, output_bit in placements}
                    if len(rotations) == 1:
                        rotation = next(iter(rotations))
                        term = binding if not rotation else f'(({binding} << {rotation}) | ({binding} >> {8-rotation}))'
                        result = f'(({term}) & {hex(output_bits)}) ^ {hex(base)}'
        self.unary_cache[identifier] = (expression, result)
        if result is not None:
            self.unary_rewrites += 1
            if composite_subject:
                self.composite_byte_rewrites += 1
        return result

    def render(self, expression: Any) -> str:
        symbolic = self.trace.z
        if symbolic.is_bv_value(expression):
            return hex(expression.as_long())
        if symbolic.is_const(expression):
            name = str(expression)
            if name not in self.bindings:
                raise ValueError('source emission encountered an unbound symbolic value')
            return self.bindings[name]
        identifier = expression.get_id()
        if identifier in self.nodes:
            return self.nodes[identifier][1]
        compact = self.compact_unary(expression)
        if compact is not None:
            self.nodes[identifier] = (expression, compact)
            return compact
        operands = expression.children()
        values = [self.render(operand) for operand in operands]
        operation = str(expression.decl().name())
        width = expression.size()
        operators = {'bvadd':'+','bvsub':'-','bvmul':'*','bvand':'&','bvor':'|','bvxor':'^','bvshl':'<<','bvlshr':'>>'}
        if operation in operators:
            body = (' ' + operators[operation] + ' ').join(f'({value})' for value in values)
            body = f'({body}) & {self.mask_name(width)}'
        elif operation in ('bvnot','bvneg'):
            operator = '~' if operation == 'bvnot' else '-'
            body = f'({operator}({values[0]})) & {self.mask_name(width)}'
        elif operation == 'extract':
            high_bit, low_bit = expression.decl().params()
            body = f'(({values[0]}) >> {low_bit}) & {self.mask_name(high_bit-low_bit+1)}'
        elif operation == 'concat':
            shift_width = sum(operand.size() for operand in operands)
            pieces: list[str] = []
            for operand, value in zip(operands, values):
                shift_width -= operand.size()
                pieces.append(f'(({value}) << {shift_width})' if shift_width else f'({value})')
            body = ' | '.join(pieces)
        elif operation == 'zero_extend':
            return values[0]
        elif operation == 'sign_extend':
            sign_mask = 1 << (operands[0].size() - 1)
            body = f'((({values[0]}) ^ {sign_mask}) - {sign_mask}) & {self.mask_name(width)}'
        else:
            raise ValueError('unsupported source arithmetic operation: ' + operation)
        name = f'intermediate_{len(self.nodes):04d}'
        self.lines.append(f'    {name} = {body}')
        self.nodes[identifier] = (expression, name)
        return name

    def emit_lookup(self, event: dict[str, Any]) -> None:
        index_expression = self.render(event['index_expression'])
        if event['role'] == 'external':
            source_name = 'substitution_bytes'
        else:
            source_name = event['role'] + '_state'
        result_name = f'lookup_result_{self.lookup_number:02d}'
        self.lookup_number += 1
        self.lines.append(f'    {result_name} = {source_name}[{index_expression}]')
        variable = self.trace.variables[event['variable_number']]
        self.bindings[str(variable)] = result_name

    def emit_memory_update(self, event: dict[str, Any], oracle: Any) -> None:
        scalar_positions = {oracle.frame_address-offset:index for index,offset in enumerate(self.layout.scalar_offsets)}
        windows = (
            (oracle.frame_address-FIRST_FOLD_FRAME_OFFSET,FOLD_BYTE_COUNT,'first_fold_state'),
            (oracle.frame_address-SECOND_FOLD_FRAME_OFFSET,FOLD_BYTE_COUNT,'second_fold_state'),
            (oracle.frame_address-EXPANDED_STATE_FRAME_OFFSET,EXPANDED_STATE_BYTE_COUNT,'expanded_fold_state'),
        )
        for byte_offset in range(event['width']):
            address = event['address'] + byte_offset
            target = None
            if address in scalar_positions:
                target = f'scalar_state[{scalar_positions[address]}]'
            else:
                for start, length, name in windows:
                    if start <= address < start+length:
                        target = f'{name}[{address-start}]'
                        break
            if target is None:
                continue
            expression = self.trace.z.simplify(self.trace.z.Extract(8*byte_offset+7,8*byte_offset,event['value']))
            rendered = self.render(expression)
            self.lines.append(f'    {target} = {rendered}')
            self.memory_updates += 1

    def render_output(self, expressions: list[Any], output_name: str) -> None:
        values = [self.render(expression) for expression in expressions]
        self.lines.append(f'    {output_name} = bytes((')
        self.lines.extend('        ' + value + ',' for value in values)
        self.lines.append('    ))')

    def module_source(self) -> str:
        header = [
            '"""Generated middle-state arithmetic with explicit protocol parameters.',
            '',
            'No image data or instruction execution is included. MASK_n is 2**n-1.',
            'The supplied readonly/substitution parameters remain unreconstructed;',
            'this developer model is not a complete standalone GUID provider.',
            '"""', '',
        ]
        header.extend(f'MASK_{width}: int = (1 << {width}) - 1' for width in sorted(self.mask_widths))
        header.extend([
            '', '', 'def generate_middle_state(',
            '    expanded_state: bytes,', '    initial_fold_state: bytes,',
            '    readonly_seed: bytes,', '    substitution_bytes: bytes,',
            ') -> tuple[bytes, bytes, bytes, bytes]:',
            '    parameter_lengths = tuple(map(len, (expanded_state, initial_fold_state, readonly_seed, substitution_bytes)))',
            f'    if parameter_lengths != {self.input_shapes!r}:',
            "        raise ValueError('middle-state parameters have incorrect byte lengths')",
            f'    scalar_state = bytearray({len(self.layout.scalar_offsets)})',
            f'    first_fold_state = bytearray({FOLD_BYTE_COUNT})',
            '    second_fold_state = bytearray(initial_fold_state)',
            '    expanded_fold_state = bytearray(expanded_state)',
        ])
        return '\n'.join(header + self.lines + ['    return bytes(scalar_state), bytes(first_fold_state), bytes(second_fold_state), bytes(expanded_fold_state)', ''])


def readonly_seed_locations(oracle: Any) -> list[tuple[int, int]]:
    from capstone import CS_OP_MEM
    locations: list[tuple[int, int]] = []
    for instruction in oracle.instructions.values():
        if instruction.mnemonic != 'movaps':
            continue
        for operand in instruction.operands:
            if operand.type == CS_OP_MEM and instruction.reg_name(operand.mem.base) == 'rip':
                locations.append((instruction.address + instruction.size + operand.mem.disp, operand.size))
    return locations


def emit_middle_source(trace: Any, oracle: Any, destination: Path) -> dict[str, Any]:
    from apple_music_source.auth._guid_input_expansion import expand328
    from replay_guid_record_middle import HASH_WIRE_XOR, FORWARD_WIRE_XOR

    emitter = ArithmeticEmitter(trace)
    for event in trace.program_events:
        if event['kind'] == 'lookup':
            emitter.emit_lookup(event)
        else:
            emitter.emit_memory_update(event, oracle)
    source = emitter.module_source()
    destination.write_text(source)
    specification = importlib.util.spec_from_file_location('generated_guid_middle', destination)
    if specification is None or specification.loader is None:
        raise RuntimeError('generated middle source cannot be loaded')
    module = importlib.util.module_from_spec(specification)
    specification.loader.exec_module(module)
    seed_locations = readonly_seed_locations(oracle)
    seed = b''.join(bytes(oracle.unicorn.mem_read(address, length)) for address, length in seed_locations)
    substitution = bytes(oracle.unicorn.mem_read(oracle.layout.lookup_address, LOOKUP_BYTE_COUNT))
    comparisons = 0
    invented_inputs = INVENTED_ANDROID_IDENTIFIERS if oracle.layout.name == 'forward' else tuple(bytes((index * 13 + length) & 255 for index in range(length)) for length in (80, 112, 147, 200))
    for android_identifier in invented_inputs:
        expected = oracle.derive_state(android_identifier)
        expanded = bytes(value ^ HASH_WIRE_XOR ^ oracle.layout.wire_xor for value in expand328(bytes(value ^ HASH_WIRE_XOR ^ oracle.layout.input_wire_xor for value in android_identifier)))
        observed = module.generate_middle_state(expanded, oracle.initial_second_fold, seed, substitution)
        assert observed == (expected.scalar_bytes, expected.first_fold_bytes, expected.second_fold_bytes, expected.expanded_fold_bytes)
        comparisons += 1
    return dict(source=str(destination),source_bytes=len(source.encode()),arithmetic_nodes=len(emitter.nodes),exhaustive_unary_rewrites=emitter.unary_rewrites,composite_byte_rewrites=emitter.composite_byte_rewrites,lookup_operations=emitter.lookup_number,array_snapshots=len(emitter.snapshots),source_memory_updates=emitter.memory_updates,original_complete_state_comparisons=comparisons,unreconstructed_parameter_lengths=list(emitter.input_shapes[1:]),copied_image_bank_bytes=0,instruction_decoder=False,scope='parameterized arithmetic model; readonly parameters and full GUID/auth remain unfinished')
