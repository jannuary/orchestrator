"""Locate fully initialized CoreADI runtime word arrays on invented inputs.

The pinned original is an offline developer oracle only. Allocation contents,
CPU values and device data stay in RAM. Reports contain abstract allocation
labels, source PCs, coverage and algebraic shape, never pointers or words.
"""
from __future__ import annotations

import argparse
from collections import Counter
from dataclasses import dataclass, field
import hashlib
import json
from pathlib import Path
import sys
from typing import Any, Final

from classify_runtime_tables import rank
from scan_auth_substitutions import TARGETS

WORD_ARRAY_BYTES: Final[int] = 1024
WORD_BYTES: Final[int] = 4
WORD_ARRAY_VALUES: Final[int] = 256
COREADI_BIAS: Final[int] = 0x10000000
OUTPUT_STORE_PCS: Final[frozenset[int]] = frozenset(COREADI_BIAS+counter for counter in (
    0x9e7a7,0x9e826,0x9e864,0x9ea26,0x9eab3,0x9eaff,0x9ebe9,0x9ec79,
    0x9ecbc,0x9ecf8,0x9ed23,0x9ed64,0x9ed9d,0x9edc3,0x9ee2e,0x9eea9,
))


@dataclass(repr=False)
class Allocation:
    label: int
    address: int
    size: int
    operation: str
    source_store_PC: int | None = None
    source_store_sites: set[int] = field(default_factory=set, repr=False)
    written_offsets: set[int] = field(default_factory=set, repr=False)
    read_sites: Counter[tuple[str, int, int]] = field(default_factory=Counter, repr=False)
    snapshot: bytes | None = field(default=None, repr=False)
    released: bool = False
    initialization_observed: bool = True


def algebraic_shape(data: bytes) -> dict[str, object]:
    words = [int.from_bytes(data[offset:offset+WORD_BYTES], 'little') for offset in range(0, WORD_ARRAY_BYTES, WORD_BYTES)]
    differences = [value ^ words[0] for value in words]
    columns = [differences[1 << bit] for bit in range(8)]
    affine = all(difference == _apply(columns,index) for index,difference in enumerate(differences))
    inversion = True
    for delta in range(1, WORD_ARRAY_VALUES):
        spectrum = Counter(Counter(words[index] ^ words[index ^ delta] for index in range(WORD_ARRAY_VALUES)).values())
        if spectrum != Counter({2:126,4:1}):
            inversion = False
            break
    return dict(distinct_words=len(set(words)),output_affine_rank=rank(differences),affine_index_map=affine,inversion_differential_structure=inversion)


def _apply(columns: list[int], index: int) -> int:
    result = 0
    for bit, column in enumerate(columns):
        if index & (1 << bit):
            result ^= column
    return result


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('checkout', type=Path)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--trace-rounds', action='store_true')
    parser.add_argument('--table-algebra', action='store_true')
    parser.add_argument('--round-substitutions', action='store_true')
    parser.add_argument('--regular-prefix', type=int, default=64)
    parser.add_argument('--normalize-indices', action='store_true')
    parser.add_argument('--word-domains', action='store_true')
    parser.add_argument('--inline-word-domains', action='store_true')
    parser.add_argument('--key-schedule', action='store_true')
    parser.add_argument('--prove-projections', action='store_true')
    parser.add_argument('--split-projection-proofs', action='store_true')
    arguments = parser.parse_args()
    root = arguments.checkout.resolve()
    for target in ('coreadi','storeservices'):
        filename,digest = TARGETS[target]
        if hashlib.sha256((root/'rootfs/system/lib64'/filename).read_bytes()).hexdigest() != digest:
            raise ValueError('original artifact identity mismatch')
    sys.path.insert(0,str(root/'tools/auth'))
    from coreadi_verify_reference import Oracle
    from coreadi_oracle import HEAP, REGS
    from unicorn import UC_HOOK_CODE, UC_HOOK_MEM_READ, UC_HOOK_MEM_WRITE
    from unicorn.x86_const import UC_X86_REG_RAX, UC_X86_REG_RIP
    from trace_lookup_dataflow import LookupTrace
    from unicorn import x86_const
    from capstone import Cs,CS_ARCH_X86,CS_MODE_64,CS_OP_MEM

    class RoundTrace(LookupTrace):
        def __init__(self, machine: Any, arrays: list[Allocation], regular: list[int], final: list[int]) -> None:
            super().__init__(machine,[(entry.address,entry.size) for entry in arrays],regular,final,maximum_regular_reads=arguments.regular_prefix,normalize_round_indices=arguments.normalize_indices,word_domains={index:arrays[index].snapshot for index in regular} if arguments.word_domains or arguments.inline_word_domains or arguments.prove_projections else None,inline_word_domains=arguments.inline_word_domains or arguments.prove_projections)
            self.discovery_reports: list[dict[str,object]] = []
            self.discovered_arrays: list[Allocation] = []
            self.model_arrays=[entry.snapshot for entry in arrays]
            self.projector=None
            self.projection_models=[]
            self.projection_substitutions=None
            self.progress_regular_reads=0
            if arguments.prove_projections:
                sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'src'))
                from analyze_round_substitutions import analyze
                from prove_guid_index_projections import Projector
                self.projection_substitutions=analyze(self.model_arrays,regular,self.projection_models.append)
                position_options={tuple(model['input_positions']) for model in self.projection_models}
                if len(position_options)!=1:
                    raise ValueError('CoreADI physical input-byte positions are not unique')
                positions=[0]*len(arrays)
                for ordinal,position in zip(regular,next(iter(position_options))):
                    positions[ordinal]=position
                self.projector=Projector(tuple(positions),bit_timeout_ms=1500 if arguments.split_projection_proofs else 0)
                self.custom_index_normalizer=lambda trace,index,ordinal:self.projector(trace,index,ordinal) if ordinal in self.regular else index

        def read(self, machine: Any, instruction: Any, operand: Any) -> Any:
            result=self.read_operand(machine,instruction,operand)
            if self.regular_reads and self.regular_reads%16==0 and self.regular_reads!=self.progress_regular_reads:
                self.progress_regular_reads=self.regular_reads
                print(json.dumps(dict(progress='CoreADI regular-word trace',reads=self.regular_reads)),flush=True)
            return result

        def read_operand(self, machine: Any, instruction: Any, operand: Any) -> Any:
            if operand.type!=CS_OP_MEM or operand.size!=WORD_BYTES:
                return super().read(machine,instruction,operand)
            expression=self.address(machine,instruction,operand)
            address=self.concrete(expression)
            if not self.dependencies(expression) or any(base<=address and address+WORD_BYTES<=base+size for base,size in self.allocated):
                return super().read(machine,instruction,operand)
            if not operand.mem.index or operand.mem.scale!=WORD_BYTES:
                return super().read(machine,instruction,operand)
            register_name=instruction.reg_name(operand.mem.index)
            actual_index=machine.reg_read(getattr(x86_const,'UC_X86_REG_'+register_name.upper()))
            base=address-(actual_index & (WORD_ARRAY_VALUES-1))*WORD_BYTES
            solver=self.z.Solver()
            solver.set(timeout=5000)
            solver.add(self.z.Not(self.z.And(self.z.UGE(expression,base),self.z.ULE(expression,base+WORD_ARRAY_BYTES-WORD_BYTES))))
            verdict=str(solver.check())
            if verdict!='unsat':
                self.discovery_reports.append(dict(source_PC=hex(instruction.address),range_proof=verdict,accepted=False))
                return super().read(machine,instruction,operand)
            snapshot=bytes(machine.mem_read(base,WORD_ARRAY_BYTES))
            shape=algebraic_shape(snapshot)
            ordinal=len(self.allocated)
            self.allocated.append((base,WORD_ARRAY_BYTES))
            self.model_arrays.append(snapshot)
            self.regular.add(ordinal)
            self.discovery_reports.append(dict(source_PC=hex(instruction.address),range_proof=verdict,accepted=True,table_ordinal=ordinal,shape=shape))
            allocation=Allocation(ordinal,base,WORD_ARRAY_BYTES,'discovered during round',None,snapshot=snapshot,initialization_observed=False)
            self.discovered_arrays.append(allocation)
            return super().read(machine,instruction,operand)

    class RuntimeOracle(Oracle):
        def __init__(self) -> None:
            self.operation = 'setup'
            self.allocations: list[Allocation] = []
            self.store_decoder=Cs(CS_ARCH_X86,CS_MODE_64)
            self.store_decoder.detail=True
            self.store_cache: dict[int,Any] = {}
            self.pending_snapshots: list[Allocation] = []
            self.unscaled_writes: dict[tuple[str,int],set[int]] = {}
            self.round_trace: Any = None
            self.output_bytes: dict[int,int] = {}
            self.output_store_sites: list[int] = []
            self.write_history: list[tuple[int,int,int]] = []
            self.prefix_read_history: list[tuple[int,int,int]] = []
            super().__init__(None,0x86431,1700000000)
            self.m.hook_add(UC_HOOK_MEM_WRITE,self.observe_write)
            self.m.hook_add(UC_HOOK_MEM_READ,self.observe_read)
            self.m.hook_add(UC_HOOK_CODE,self.finish_write,begin=COREADI_BIAS+0x97600,end=COREADI_BIAS+0x99875)
            if arguments.trace_rounds or arguments.table_algebra or arguments.round_substitutions or arguments.key_schedule:
                self.m.hook_add(UC_HOOK_CODE,self.observe_round,begin=COREADI_BIAS+0x99876,end=COREADI_BIAS+0x9e800)

        def alloc(self, size: int) -> int:
            address = super().alloc(size)
            if size == WORD_ARRAY_BYTES:
                self.allocations.append(Allocation(len(self.allocations),address,size,self.operation))
            return address

        def external(self, machine: Any, counter: int, size: int, user: Any) -> None:
            if self.stubs.get(counter)=='free':
                address=machine.reg_read(REGS[0])
                for allocation in self.allocations:
                    if allocation.address==address:
                        allocation.released=True
            super().external(machine,counter,size,user)

        def observe_write(self, machine: Any, access: int, address: int, width: int, value: int, user: Any) -> None:
            counter=machine.reg_read(UC_X86_REG_RIP)
            if self.round_trace is not None and len(self.output_store_sites)<16 and width==1 and counter in OUTPUT_STORE_PCS:
                self.output_bytes[address]=value & 255
                self.output_store_sites.append(counter)
            if self.round_trace is None and COREADI_BIAS<=counter<COREADI_BIAS+0x180000:
                self.write_history.append((counter,address,width))
            if width!=WORD_BYTES or not COREADI_BIAS+0x97600<=counter<COREADI_BIAS+0x99876:
                return
            instruction=self.store_cache.get(counter)
            if instruction is None:
                instruction=next(self.store_decoder.disasm(bytes(machine.mem_read(counter,15)),counter,count=1))
                self.store_cache[counter]=instruction
            operand=instruction.operands[0]
            if operand.type!=CS_OP_MEM or not operand.mem.index or operand.mem.scale not in (1,WORD_BYTES):
                return
            if operand.mem.scale==1:
                addresses=self.unscaled_writes.setdefault((self.operation,counter),set())
                addresses.add(address)
                if len(addresses)!=WORD_ARRAY_VALUES:
                    return
                base=min(addresses)
                if addresses!=set(range(base,base+WORD_ARRAY_BYTES,WORD_BYTES)):
                    return
                allocation=Allocation(len(self.allocations),base,WORD_ARRAY_BYTES,self.operation,counter)
                allocation.source_store_sites.add(counter)
                allocation.written_offsets.update(range(WORD_ARRAY_BYTES))
                self.allocations.append(allocation)
                self.pending_snapshots.append(allocation)
                return
            index_name=instruction.reg_name(operand.mem.index)
            index=machine.reg_read(getattr(x86_const,'UC_X86_REG_'+index_name.upper()))
            offset = (index * operand.mem.scale) & (WORD_ARRAY_BYTES - 1)
            if offset % WORD_BYTES:
                return
            base=address-offset
            allocation=next((entry for entry in self.allocations if entry.address==base and entry.operation==self.operation),None)
            if allocation is None:
                allocation=Allocation(len(self.allocations),base,WORD_ARRAY_BYTES,self.operation,counter)
                self.allocations.append(allocation)
            allocation.source_store_sites.add(counter)
            allocation.written_offsets.update(range(offset,offset+WORD_BYTES))
            if len(allocation.written_offsets)==allocation.size and allocation.snapshot is None:
                self.pending_snapshots.append(allocation)

        def finish_write(self, machine: Any, counter: int, width: int, user: Any) -> None:
            for allocation in self.pending_snapshots:
                allocation.snapshot=bytes(machine.mem_read(allocation.address,allocation.size))
            self.pending_snapshots=[]

        def observe_round(self, machine: Any, counter: int, width: int, user: Any) -> None:
            if self.round_trace is None:
                if counter!=COREADI_BIAS+0x99876:
                    return
                arrays=[entry for entry in self.allocations if entry.operation==self.operation and entry.snapshot is not None]
                regular=[index for index,entry in enumerate(arrays) if entry.source_store_PC in (COREADI_BIAS+0x976c1,COREADI_BIAS+0x982de,COREADI_BIAS+0x985d0,COREADI_BIAS+0x98a0a)]
                final=[index for index in range(len(arrays)) if index not in regular]
                self.round_trace=RoundTrace(machine,arrays,regular,final)
            self.round_trace.step(machine,counter,width)

        def observe_read(self, machine: Any, access: int, address: int, width: int, value: int, user: Any) -> None:
            if width!=WORD_BYTES:
                return
            counter=machine.reg_read(UC_X86_REG_RIP)
            if self.round_trace is None and COREADI_BIAS+0x98a00<=counter<COREADI_BIAS+0x99876:
                self.prefix_read_history.append((counter,address,width))
            for allocation in self.allocations:
                if allocation.released or allocation.operation!=self.operation or not allocation.address<=address or address+width>allocation.address+allocation.size or (address-allocation.address)%WORD_BYTES:
                    continue
                counter=machine.reg_read(UC_X86_REG_RIP)
                if len(allocation.written_offsets)==allocation.size:
                    if allocation.snapshot is None:
                        allocation.snapshot=bytes(machine.mem_read(allocation.address,allocation.size))
                    allocation.read_sites[(self.operation,counter,width)]+=1

    oracle=RuntimeOracle()
    oracle.files['/data/adi.pb']=bytearray(32)
    operations=[]
    for name,parameters in (
        ('kq56gsgHG6',[oracle.write(b'/system/lib64')]),
        ('nf92ngaK92',[oracle.write(b'/data')]),
        ('Sph98paBcz',[oracle.write(b'0123456789abcdef'),16]),
        ('qi864985u0',[(1<<64)-1,HEAP+0x1000,HEAP+0x1010,HEAP+0x1020,HEAP+0x1030]),
    ):
        oracle.operation=name
        status=oracle.invoke(name,parameters)
        operations.append(dict(operation=name,status=status if status<1<<31 else status-(1<<32)))
        if status:
            break
    rows=[]
    for allocation in oracle.allocations:
        row=dict(allocation_label=allocation.label,source_store_PCs=[hex(counter) for counter in sorted(allocation.source_store_sites)],bytes=allocation.size,operation=allocation.operation,fully_written=len(allocation.written_offsets)==allocation.size,written_bytes=len(allocation.written_offsets),released=allocation.released,word_reads_after_complete_write=sum(allocation.read_sites.values()),read_sites=[dict(operation=operation,source_PC=hex(counter),width=width,reads=count) for (operation,counter,width),count in sorted(allocation.read_sites.items())])
        if allocation.snapshot is not None:
            row['complete_state_shape']=algebraic_shape(allocation.snapshot)
        rows.append(row)
    table_algebra=None
    round_substitutions=None
    key_schedule=None
    ordered_schedule=None
    frontier_schedule=None
    block_output_checks=[]
    if oracle.round_trace is not None:
        for allocation,discovery in zip(oracle.round_trace.discovered_arrays,oracle.round_trace.discovery_reports):
            writes: Counter[int] = Counter()
            covered_bytes: set[int] = set()
            for counter,address,width in oracle.write_history:
                if allocation.address<=address and address+width<=allocation.address+allocation.size:
                    writes[counter]+=1
                    covered_bytes.update(range(address-allocation.address,address-allocation.address+width))
            discovery['prior_initialization_observed_bytes']=len(covered_bytes)
            discovery['prior_initialization_sites']=[dict(source_PC=hex(counter),writes=count) for counter,count in sorted(writes.items())]
            discovery['reads_before_trace']=[dict(source_PC=hex(counter),width=width) for counter,address,width in oracle.prefix_read_history if allocation.address<=address and address+width<=allocation.address+allocation.size]
        trace=oracle.round_trace
        if arguments.table_algebra:
            sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'src'))
            from analyze_table_algebra import analyze
            table_algebra=analyze(trace.model_arrays,sorted(trace.regular),sorted(trace.final))
        if arguments.round_substitutions or arguments.key_schedule:
            sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'src'))
            from analyze_round_substitutions import analyze
            models=[]
            round_substitutions=analyze(trace.model_arrays,sorted(trace.regular),models.append)
            if arguments.key_schedule:
                from analyze_round_key_schedule import analyze as analyze_schedule
                from analyze_ordered_aes_rounds import analyze as analyze_ordered
                from analyze_frontier_aes_rounds import check as analyze_frontier
                key_schedule=analyze_schedule(trace,models,sorted(trace.regular))
                ordered_schedule=analyze_ordered(trace.events,models,sorted(trace.regular))
                candidates=[]
                frontier_schedule=analyze_frontier(trace,models,sorted(trace.regular),lambda master,details:candidates.append((master,details)))
                from analyze_round_key_schedule import recover_input
                from apple_music_source.crypto.aes import AES
                contiguous=len(oracle.output_bytes)==16 and max(oracle.output_bytes)-min(oracle.output_bytes)==15
                actual=bytes(oracle.output_bytes[address] for address in sorted(oracle.output_bytes)) if contiguous else None
                for master,details in candidates:
                    logical_input=recover_input(master,details,sorted(trace.regular))
                    predicted=AES(master).decrypt_block(logical_input) if details['cipher_direction']==-1 else AES(master).encrypt_block(logical_input)
                    block_output_checks.append(dict(contiguous_16_byte_output=contiguous,source_output_store_count=len(oracle.output_store_sites),output_equals_unwhitened_AES=actual==predicted if contiguous else None,parameters_emitted=False))
    report=dict(status='CoreADI runtime word-array trace',table_algebra=table_algebra,round_substitutions=round_substitutions,key_schedule=key_schedule,ordered_schedule=ordered_schedule,frontier_schedule=frontier_schedule,block_output_checks=block_output_checks,round_trace=oracle.round_trace.summary() if oracle.round_trace is not None else None,round_array_discoveries=oracle.round_trace.discovery_reports if oracle.round_trace is not None else [],proved_projection_outcomes=dict(oracle.round_trace.projector.outcomes) if oracle.round_trace is not None and oracle.round_trace.projector is not None else {},artifact_sha256=TARGETS['coreadi'][1],operations=operations,arrays=rows,network_requests=0,host_private_state_read=False,private_material_written=False,scope='invented initialization and malformed provisioning only; complete-write runtime-array shape/read coverage, not a recovered cipher, OTP or provisioning implementation')
    arguments.output.write_text(json.dumps(report,indent=2)+'\n')
    print(json.dumps(dict(status=report['status'],word_arrays=len(rows),completely_initialized_arrays=sum('complete_state_shape' in row for row in rows),inversion_shape_arrays=sum(row.get('complete_state_shape',{}).get('inversion_differential_structure',False) for row in rows))))


if __name__ == '__main__':
    main()
