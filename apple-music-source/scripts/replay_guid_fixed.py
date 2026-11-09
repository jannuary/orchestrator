"""Replay original GUID blocks for fixed-provider checks, with no parameter fit."""


def replay(kernel,oracle,expected,bases,begin,end,source_regions,output_base=None,output_sites=None):
    from capstone import Cs,CS_ARCH_X86,CS_MODE_64,CS_OP_MEM
    from unicorn import UC_HOOK_CODE,UC_HOOK_MEM_READ,UC_HOOK_MEM_WRITE
    from unicorn import x86_const as r
    mu=oracle.mu;decoder=Cs(CS_ARCH_X86,CS_MODE_64);decoder.detail=True
    observed=[];writes=[];final=[0];started=[False]
    def step(m,pc,size,user):
        if pc==begin:
            if started[0]:m.emu_stop();return
            started[0]=True
        if not begin<=pc<end:m.emu_stop()
    def read(m,kind,address,width,value,ordinal):
        if width!=4 or (address-bases[ordinal])%4:return
        observed.append((m.reg_read(r.UC_X86_REG_RIP),ordinal,(address-bases[ordinal])//4,int.from_bytes(m.mem_read(address,4),'little')))
        if ordinal>=4:final[0]+=1
    def write(m,kind,address,width,value,user):
        if width!=1 or not final[0]:return
        pc=m.reg_read(r.UC_X86_REG_RIP);ins=next(decoder.disasm(bytes(m.mem_read(pc,16)),pc,count=1))
        if pc in output_sites if output_sites is not None else ins.operands and ins.operands[0].type==CS_OP_MEM and ins.reg_name(ins.operands[0].mem.base)==(output_base or ('r13' if kernel==0 else 'r12')):
            writes.append(address)
    handles=[mu.hook_add(UC_HOOK_CODE,step),mu.hook_add(UC_HOOK_MEM_WRITE,write)]
    for ordinal,base in enumerate(bases):handles.append(mu.hook_add(UC_HOOK_MEM_READ,read,ordinal,begin=base,end=base+1023))
    error=None
    try:mu.emu_start(begin,end,count=200000)
    except Exception as exception:error=type(exception).__name__
    finally:
        for handle in handles:mu.hook_del(handle)
    contiguous=len(set(writes))==16 and max(writes)-min(writes)==15
    actual=bytes(mu.mem_read(min(writes),16)) if contiguous else None;source_equal=None
    if actual is not None and source_regions is not None:
        for address,data in source_regions:
            offset=min(writes)-address
            if 0<=offset and offset+16<=len(data):source_equal=data[offset:offset+16]==actual;break
    report=dict(mode='fixed implementation validation; no key, mask, encoding or table-model fitting',
                original_execution_error=error,original_source_word_reads_equal=observed==expected,
                source_lookup_reads=len(expected),original_lookup_reads=len(observed),final_lookup_reads=final[0],
                block_output_checks=[dict(contiguous_16_byte_output=contiguous,source_original_complete_output_equal=source_equal)],
                private_bytes_written=False)
    return report,actual
