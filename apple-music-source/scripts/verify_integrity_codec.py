"""Offline ELF differential evidence for the integrity fold's REAL consumers.

Invented pointers, tables and fold parameters only. No account/exchange inputs.
The scalar model derives the pointer and 42-word table encoding, not the fold.
The pristine SIMD replacement is tested at complete consumer boundaries, with
all registers, flags, mapped bytes, faults and budgets. No ELF is shipped.
"""
import argparse
import ctypes
import hashlib
import json
from pathlib import Path
import random
import struct
import subprocess
import tempfile

HASH='1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b'
BASES=(0x580,0xe20,0xe30,0x1170,0x25b0,0x25c0,0x35d0,0x4690,0x4c40,0x4f40)
F=0x1000193
U32=(1<<32)-1
U64=(1<<64)-1
OFFSET=0x87a0e6b449599d30


def positions(key):
    k=key*0x678086cb & U32
    return k,[(i, (((((k+i)&U32)^k)*F)&U32)%i) for i in range(7,1,-1)]+[(1,0)]


def pointer(value,key,decode=False):
    k,swaps=positions(key)
    q=(k*k^k)&U32,((k*((k+1)&U32))^k)&U32
    if decode:
        value=(value+OFFSET)&U64
        words=struct.unpack('<II',struct.pack('<Q',value^(q[0]|q[1]<<32)))
        data=bytearray(struct.pack('<II',*((v-a)*pow(F,-1,1<<32)&U32 for v,a in zip(words,q))))
        for i,j in reversed(swaps):data[i],data[j]=data[j],data[i]
        return int.from_bytes(data,'little')
    data=bytearray(value.to_bytes(8,'little'))
    for i,j in swaps:data[i],data[j]=data[j],data[i]
    words=struct.unpack('<II',data)
    out=[((v*F+a)&U32)^a for v,a in zip(words,q)]
    return ((out[0]|out[1]<<32)-OFFSET)&U64


def table(data,address,key,decode=False):
    seed=((address&U32)*0x678086cb)^key
    seed &= U32
    data=bytearray(data)
    def shuffle(indices):
        for i in indices:
            j=((((seed+i)&U32)^seed)*F&U32)%i
            data[i*8:i*8+8],data[j*8:j*8+8]=data[j*8:j*8+8],data[i*8:i*8+8]
    if decode:shuffle(range(1,42))
    for i,b in enumerate(data):
        mask=(((i-seed)*(i+seed))^seed)&255
        data[i]=((b*pow(F,-1,256))^mask)&255 if decode else ((b^mask)*F)&255
    if not decode:shuffle(range(41,0,-1))
    return bytes(data)


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('core_elf',type=Path);p.add_argument('--output',type=Path,required=True);a=p.parse_args()
    raw=a.core_elf.read_bytes();assert hashlib.sha256(raw).hexdigest()==HASH
    native=Path(__file__).resolve().parents[1]/'src/apple_music_source/_native'
    reconstructed=bytearray(raw);reads=0
    with tempfile.TemporaryDirectory(prefix='ams-codec-') as t:
        lib=Path(t)/'data.so'
        subprocess.run(['cc','-std=c99','-O2','-shared','-fPIC','-Wall','-Wextra','-Werror',str(native/'integrity_codec_data.c'),'-o',str(lib)],check=True)
        read=ctypes.CDLL(str(lib)).ams_integrity_codec_data_read
        read.argtypes=[ctypes.c_uint64,ctypes.c_uint,ctypes.POINTER(ctypes.c_uint64)]
        for base in BASES:
            for i in range(16):
                v=ctypes.c_uint64();assert read(base+i,1,ctypes.byref(v))==1
                reconstructed[base+i]=v.value
            for i in range(16):
                for width in range(1,min(8,16-i)+1):
                    v=ctypes.c_uint64();assert read(base+i,width,ctypes.byref(v))==1
                    assert v.value==int.from_bytes(raw[base+i:base+i+width],'little');reads+=1
    assert reconstructed==raw
    from unicorn import Uc,UcError,UC_ARCH_X86,UC_MODE_64,UC_HOOK_MEM_INVALID,UC_HOOK_CODE
    from unicorn import x86_const as reg
    names='RAX RBX RCX RDX RSI RDI RBP RSP R8 R9 R10 R11 R12 R13 R14 R15 RFLAGS RIP'.split()
    regs=[getattr(reg,'UC_X86_REG_'+n) for n in names]+[getattr(reg,'UC_X86_REG_XMM'+str(i)) for i in range(16)]
    rng=random.Random(0xC0DEC)
    def execute(image,key,plain,address,decode=False,budget=100000,readonly=False):
        mu=Uc(UC_ARCH_X86,UC_MODE_64)
        mu.mem_map(0,0x700000);mu.mem_write(0,image)
        mu.mem_map(0x1000000,0x10000);mu.mem_map(0x3000000,0x4000)
        frame=0x1009000
        for i,r in enumerate(regs[:16]):mu.reg_write(r,(0x102030405060708*(i+1))&U64)
        for i,r in enumerate(regs[18:]):mu.reg_write(r,(i+1)*0x9876543210123456789)
        mu.reg_write(reg.UC_X86_REG_RBP,frame);mu.reg_write(reg.UC_X86_REG_RSP,frame-0x5000)
        mu.reg_write(reg.UC_X86_REG_RFLAGS,0x202)
        mu.mem_write(frame-0x48,struct.pack('<Q',0x3003000))
        if decode:
            entry,end=0x3ee6a1,0x3eed16
            mu.reg_write(reg.UC_X86_REG_R8,0x3003000)
            mu.reg_write(reg.UC_X86_REG_RAX,key)
            mu.reg_write(reg.UC_X86_REG_R14,pointer(address,key))
            mu.reg_write(reg.UC_X86_REG_R9,8)
        else:
            entry,end=0x3edebc,0x3ee383
            mu.reg_write(reg.UC_X86_REG_RBX,key)
            mu.mem_write(frame-0x90,struct.pack('<I',key))
            mu.mem_write(frame-0x3128,struct.pack('<Q',address))
            mu.mem_write(frame-0x4128,bytes(8))
        if address+len(plain)<=0x700000 or 0x3000000<=address and address+len(plain)<=0x3004000:
            mu.mem_write(address,plain)
        if readonly:mu.mem_protect(0,0xdc000,1)
        faults=[];steps=[0]
        def fault(_m,access,at,width,_v,_u):faults.append((access,at,width));return False
        def step(*_):steps[0]+=1
        mu.hook_add(UC_HOOK_MEM_INVALID,fault);mu.hook_add(UC_HOOK_CODE,step)
        error=None
        try:mu.emu_start(entry,end,count=budget)
        except UcError as e:error=e.errno
        state=tuple(mu.reg_read(r) for r in regs)
        memory=tuple(bytes(mu.mem_read(at,n)) for at,n in ((0,0x700000),(0x1000000,0x10000),(0x3000000,0x4000)))
        out=int.from_bytes(mu.mem_read(0x3003000,8),'little')
        return state,memory,tuple(faults),error,steps[0],out
    cases=[]
    for key in (0,1,2,0x7fffffff,0x80000000,U32,*[rng.getrandbits(32) for _ in range(26)]):
        plain=rng.randbytes(336);address=0x3001000
        for decode in (False,True):cases.append((key,plain,address,decode,100000,False))
    # Bad addresses, partial writes, read-only and writable aliasing to pristine
    # modeled data; budgets stop throughout scalar/SIMD/shuffle operations.
    for address in (0x800000,0x3003f00,0x580,0x25b0):
        for ro in (False,True):cases.append((0x12345678,bytes(336),address,False,100000,ro))
    for budget in (1,2,7,25,70,150,300,700,1500):
        for decode in (False,True):cases.append((0x87654321,bytes(336),0x3001000,decode,budget,False))
    for i,case in enumerate(cases):
        original=execute(raw,*case);model=execute(bytes(reconstructed),*case)
        assert original==model,('full-state mismatch',i)
        key,plain,address,decode,budget,ro=case
        if i<64:
            assert original[0][17]==(0x3eed16 if decode else 0x3ee383) and original[3] is None
            assert original[-1]==((address-OFFSET)&U64 if decode else pointer(address,key)),('pointer algorithm',i)
            assert original[1][2][0x1000:0x1150]==table(plain,address,key,decode),('table algorithm',i)
    roundtrips=0
    for _ in range(4096):
        key=rng.getrandbits(32);address=rng.getrandbits(64);plain=rng.randbytes(336)
        assert pointer(pointer(address,key),key,True)==address
        assert table(table(plain,address,key),address,key,True)==plain
        roundtrips+=1
    # Changing the key consistently preserves the abstract roundtrip, but
    # changes the encoded producer state. This is NOT full-state cancellation.
    witnesses=sum(pointer(0x3001000,k)!=pointer(0x3001000,k^1) for k in range(256))
    assert witnesses
    report=dict(status='pass',oracle_sha256=HASH,reconstructed_simd_bytes=160,differential_reads=reads,consumer_execution_pairs=len(cases),ordinary_pairs=64,alias_fault_permission_pairs=8,budget_pairs=18,scalar_roundtrips=roundtrips,key_change_encoding_witnesses=witnesses,full_state_fields='16 GPR, RIP, flags, 16 XMM, all mapped memory, faults, executed instruction budget',eliminated='160 pristine image bytes; no fold/pair bank removed',scope='parameterized pointer/table codec, not a bank-free SPC/CKC implementation')
    a.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))
if __name__=='__main__':main()
