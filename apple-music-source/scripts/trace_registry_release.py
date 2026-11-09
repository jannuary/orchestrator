"""Bounded original-ELF teardown trace on a synthetic canonical record.

Developer oracle only; no production session, network, or saved record bytes.
Stops at the first unmodeled helper rather than inventing its effects.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct

from verify_integrity_codec import HASH, OFFSET, U32, U64, pointer, table


def trace(image, slot, occupied, kind=14, null_record=False, payload=None, seed=0x12345678,
          stop_owned=True, cleanup_return_state=0, observe_record=None, frame_address=0x1009000,
          execute_helpers=False, heap_blocks=None, observe_heap=None,
          shared_state=None, model_shared_lock=False, observe_shared=None, clock_sample=None,
          observe_pc=None, selector_value=0, seed_words=None, clock_status=0):
    from unicorn import Uc, UcError, UC_ARCH_X86, UC_MODE_64
    from unicorn import UC_HOOK_CODE, UC_HOOK_MEM_INVALID, UC_HOOK_MEM_WRITE, UC_HOOK_MEM_READ
    from unicorn import x86_const as r
    mu=Uc(UC_ARCH_X86,UC_MODE_64)
    stubs={}
    mu.mem_map(0x900000,0x10000)
    if execute_helpers:
        import sys
        sys.path.insert(0,str(Path(__file__).resolve().parents[3]/'tools/crypto/keygen_experimental'))
        from elf_loader import load
        elf=Path(__file__).resolve().parents[3]/'rootfs/system/lib64/libCoreLSKD.so'
        assert hashlib.sha256(elf.read_bytes()).hexdigest()==HASH
        load(mu,elf,0,stubs,{},0x900000)
    else:
        mu.mem_map(0,0x700000);mu.mem_write(0,image)
    mu.mem_map(0x1000000,0x10000)
    mu.mem_map(0x3000000,0x20000)
    frame,tags,record,registry=frame_address,0x3000000,0x3002000,0x3006000
    registry_cell,seed_cell,seed_table,selector=0x3009000,0x3009010,0x300a000,0x3009020
    registers=[getattr(r,'UC_X86_REG_'+n) for n in 'RAX RBX RCX RDX RSI RDI RBP RSP R8 R9 R10 R11 R12 R13 R14 R15'.split()]
    def put(at,fmt,*values):mu.mem_write(at,struct.pack(fmt,*values))
    for address,data in (heap_blocks or {}).items():mu.mem_write(address,data)
    if shared_state is not None:
        put(0x301f000,'<Q',0x301d000 if shared_state else 0)
        put(frame-0xbb0,'<Q',0x301f000)
        if shared_state:mu.mem_write(0x301d000,bytes(shared_state))
    put(registry_cell,'<Q',registry);put(seed_cell,'<Q',seed_table)
    put(frame-0xf88,'<Q',registry_cell)
    put(frame-0x1e8,'<Q',record)
    # Execute the real default-field producer instead of embedding its output.
    mu.reg_write(r.UC_X86_REG_RBP,frame)
    mu.reg_write(r.UC_X86_REG_R13,0x40f8740d+slot)
    mu.emu_start(0x1b63d9,0x1b64f0,count=100)
    assert mu.reg_read(r.UC_X86_REG_RIP)==0x1b64f0
    if execute_helpers:
        # Saved selector producer with the caller's recovered control state 8.
        # Without this initialized slot the c8 release creates an invalid packet.
        mu.reg_write(r.UC_X86_REG_RBX,8)
        mu.emu_start(0x1b0a39,0x1b0a75,count=32)
        assert int.from_bytes(mu.mem_read(frame-0x9dc,4),'little')==1
        mu.emu_start(0x1b0a82,0x1b0a89,count=1)
        mu.emu_start(0x1b0c62,0x1b0c7d,count=16)
    plain=bytearray(mu.mem_read(record,336) if payload is None else payload)
    assert len(plain)==336
    plain[0xf4]=kind;plain=bytes(plain)
    seed_offset=selector_value&0x678086c8
    put(seed_table+seed_offset,'<I',seed^0x678086cb)
    for offset,word in (seed_words or {}).items():put(seed_table+offset,'<Q',word)
    value=int.from_bytes(mu.mem_read(seed_table+seed_offset,4),'little')^0x678086cb
    for _ in range(8):value^=struct.unpack_from('<I',image,0xdc000+(value&32767))[0]
    key=value&U32
    mu.mem_write(record,table(plain,record,key))
    put(registry+slot*8,'<Q',pointer(0 if null_record else record,key))
    put(tags,'<1024I',*[0x69cad980]*1024)
    if occupied:put(tags+slot*4,'<I',(slot+1024+0x69cad980)&U32)
    put(selector,'<I',selector_value)
    put(0x695290,'<I',0x8d1a2f56^32767)
    put(0x695d80,'<Q',0xdc000^0x573e4d09ce0dc7b1)
    put(frame-0x1158,'<Q',tags)
    put(frame-0x110,'<Q',seed_cell)
    put(frame-0x128,'<Q',selector)
    put(frame-0x458,'<Q',0x1a09c0 if execute_helpers else 0x900100)
    put(frame-0xb8,'<Q',cleanup_return_state)
    for reg in registers:mu.reg_write(reg,0)
    mu.reg_write(r.UC_X86_REG_RBP,frame)
    mu.reg_write(r.UC_X86_REG_RSP,frame-0x6000)
    mu.reg_write(r.UC_X86_REG_RFLAGS,0x202)
    mu.reg_write(r.UC_X86_REG_RCX,(slot+0x307751a0)&U32)
    # Bounded control-state derivation: table[7350] reaches the slot check,
    # table[7363] reaches the occupied branch, table[7376] reaches its codec.
    mu.reg_write(r.UC_X86_REG_R12,7349)
    mu.reg_write(r.UC_X86_REG_R11,0x7350)
    mu.reg_write(r.UC_X86_REG_R14,selector)
    plain_writes=[]
    steps=[0];recent=[];events=[];faults=[];dirty=[False];decoded=[False];boundaries={};representation=['encoded'];wipe_entries=[];frees=[];locks=[]
    def write(_mu,_access,at,width,_value,_user):
        if at == frame-0x40:
            events.append(dict(event="wipe_index_producer",pc=hex(mu.reg_read(r.UC_X86_REG_RIP))))
        if at<record+336 and record<at+width:
            dirty[0]=True
            if representation[0]=='plain':
                plain_writes.append(dict(pc=hex(mu.reg_read(r.UC_X86_REG_RIP)),offset=at-record,width=width))
    def low_data(_mu,access,at,width,_value,_user):
        # ELF is relocated to zero for developer execution. Its mapped header
        # must not turn a null application pointer into an admissible object.
        if execute_helpers and at < 0x40:
            faults.append(dict(pc=hex(mu.reg_read(r.UC_X86_REG_RIP)),access=access,
                               address=hex(at),width=width,reason='null/low application data pointer'))
            mu.emu_stop()
    def invalid(_mu,access,at,width,_value,_user):
        faults.append(dict(pc=hex(mu.reg_read(r.UC_X86_REG_RIP)),access=access,address=hex(at),width=width))
        return False
    def code(_mu,at,_size,_user):
        steps[0]+=1;recent.append(hex(at));del recent[:-12]
        if observe_pc is not None:observe_pc(mu,at)
        if execute_helpers and at in stubs:
            name=stubs[at];arg=mu.reg_read(r.UC_X86_REG_RDI)
            if name=='gettimeofday' and clock_sample is not None and 0x1000000<=arg<=0x100fff0 and mu.reg_read(r.UC_X86_REG_RSI)==0:
                # Explicit deterministic test clock, not a runtime replacement.
                if not clock_status:put(arg,'<qq',*clock_sample)
                stack=mu.reg_read(r.UC_X86_REG_RSP)
                mu.reg_write(r.UC_X86_REG_RAX,clock_status&U64)
                mu.reg_write(r.UC_X86_REG_RIP,int.from_bytes(mu.mem_read(stack,8),'little'))
                mu.reg_write(r.UC_X86_REG_RSP,stack+8)
                events.append(dict(event='test_clock_sample'))
                return
            if model_shared_lock and name in ('pthread_rwlock_wrlock','pthread_rwlock_unlock','pthread_rwlock_destroy') and arg==0x301d000:
                locks.append(name)
                stack=mu.reg_read(r.UC_X86_REG_RSP)
                mu.reg_write(r.UC_X86_REG_RAX,0)
                mu.reg_write(r.UC_X86_REG_RIP,int.from_bytes(mu.mem_read(stack,8),'little'))
                mu.reg_write(r.UC_X86_REG_RSP,stack+8)
                return
            if name=='free' and (arg==0 or arg in (heap_blocks or {})) and arg not in frees:
                # Explicit test allocator: track release, retain mapped bytes for
                # comparison. Run the original dispatcher around this void import.
                frees.append(arg)
                stack=mu.reg_read(r.UC_X86_REG_RSP)
                mu.reg_write(r.UC_X86_REG_RIP,int.from_bytes(mu.mem_read(stack,8),'little'))
                mu.reg_write(r.UC_X86_REG_RSP,stack+8)
                return
            events.append(dict(event='unmodeled_import',name=name,argument=hex(arg)))
            mu.emu_stop();return
        if execute_helpers and at==0x3f0cb7:
            events.append(dict(event='final_helper_returned',pc=hex(at)))
            mu.emu_stop();return
        if dirty[0]:
            dirty[0]=False
            if not decoded[0] and bytes(mu.mem_read(record,336))==plain:
                decoded[0]=True;representation[0]='plain';events.append(dict(event='record_matches_original_plain',pc=hex(at)))
        if at==0x3f0520:representation[0]='decoding'
        if at==0x3f0d6f:representation[0]='encoding'
        if at==0x3f03df and representation[0]=='encoding':representation[0]='encoded'
        if at==0x1b6d31 and (not wipe_entries or mu.reg_read(r.UC_X86_REG_R10)-record != wipe_entries[-1]["offset"]):
            wipe_entries.append(dict(offset=mu.reg_read(r.UC_X86_REG_R10)-record,
                                     length=mu.reg_read(r.UC_X86_REG_RCX),
                                     index=mu.reg_read(r.UC_X86_REG_RAX),
                                     control_a=hex(mu.reg_read(r.UC_X86_REG_R12)&U32),
                                     control_b=hex(mu.reg_read(r.UC_X86_REG_R15)&U32)))
        if at==0x234747 and stop_owned:
            events.append(dict(event='owned_record_cleanup_required',pc=hex(at)))
            mu.emu_stop()
        if at in (0x3f042e,0x3f047b,0x3f0520,0x3f0cc7,0x3f0d6f):
            pc=hex(at);boundaries[pc]=boundaries.get(pc,0)+1
            if boundaries[pc]==1:events.append(dict(event='code_boundary',pc=pc))
        if at==(0x1a09c0 if execute_helpers else 0x900100):
            packet=mu.reg_read(r.UC_X86_REG_RDI)
            mask=((packet^0x26532472)*0x20bd8b7f)&U32
            data=bytes(mu.mem_read(packet,20))
            events.append(dict(event='original_helper' if execute_helpers else 'unmodeled_helper',return_pc=hex(int.from_bytes(mu.mem_read(mu.reg_read(r.UC_X86_REG_RSP),8),'little')),
                               argument_address=hex(packet),
                               selector=struct.unpack_from('<I',data,16)[0]^mask,
                               body_token=hex((struct.unpack_from('<I',data,0)[0]+mask)&U32),
                               null_argument=struct.unpack_from('<Q',data,8)[0]==0,
                               helper_argument=hex(struct.unpack_from('<Q',data,8)[0])))
            if not execute_helpers:mu.emu_stop()
        if at not in range(0xdc000,0x66c008) and at!=0x900100:
            events.append(dict(event='left_bounded_span',pc=hex(at)))
            mu.emu_stop()
    mu.hook_add(UC_HOOK_CODE,code)
    mu.hook_add(UC_HOOK_MEM_WRITE,write)
    mu.hook_add(UC_HOOK_MEM_READ|UC_HOOK_MEM_WRITE,low_data)
    mu.hook_add(UC_HOOK_MEM_INVALID,invalid)
    error=None
    try:mu.emu_start(0x3f03df,0x3f1800,count=100000)
    except UcError as e:error=e.errno
    data=bytes(mu.mem_read(record,336))
    logical=data if representation[0]=='plain' else table(data,record,key,True) if representation[0]=='encoded' else None
    if observe_record is not None: observe_record(logical)
    if observe_heap is not None:
        observe_heap({address:bytes(mu.mem_read(address,len(data))) for address,data in (heap_blocks or {}).items()})
    if observe_shared is not None and shared_state:
        observe_shared(bytes(mu.mem_read(0x301d000,len(shared_state))))
    return dict(slot=slot,occupied=occupied,kind=kind,null_record=null_record,cleanup_return_state=cleanup_return_state,steps=steps[0],pc=hex(mu.reg_read(r.UC_X86_REG_RIP)),
                decoded_record_observed=decoded[0],events=events,faults=faults,error=error,
                tag_cleared=int.from_bytes(mu.mem_read(tags+slot*4,4),'little')==0x69cad980,
                reencoded_pointer_consistent=int.from_bytes(mu.mem_read(registry+slot*8,8),'little')==pointer(0 if null_record else record,key),
                record_representation=representation[0],
                decoded_changed_offsets=[i for i,(old,new) in enumerate(zip(plain,logical)) if old!=new] if logical is not None else None,
                wipe_entries=wipe_entries,plain_writes=plain_writes,allocator_frees=frees,shared_locks=locks,
                boundary_counts=boundaries,recent_pcs=recent)


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('core_elf',type=Path)
    p.add_argument('--output',type=Path,required=True)
    a=p.parse_args();image=a.core_elf.read_bytes()
    assert hashlib.sha256(image).hexdigest()==HASH
    rows=[trace(image,slot,occupied) for slot in (0,1,1023) for occupied in (False,True)]
    rows.extend(trace(image,slot,True,kind=15) for slot in (0,1023))
    rows.append(trace(image,1023,True,null_record=True))
    report=dict(oracle_sha256=HASH,cases=rows,scope='synthetic default records; bounded release trace only; helper effects and completed teardown not modeled')
    a.output.write_text(json.dumps(report,indent=2)+'\n')
    print(json.dumps(dict(cases=[{k:v for k,v in row.items() if k!='recent_pcs'} for row in rows],scope=report['scope'])))


if __name__=='__main__':main()
