"""Invented positive/counterexample controls for source XOR separation."""
import argparse
import json
from pathlib import Path
import struct
import subprocess
import tempfile

from recover_guid_xor_components import components,prove,verify_original


def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--output',type=Path,required=True)
    args=parser.parse_args();rows=[]
    from capstone import Cs,CS_ARCH_X86,CS_MODE_64
    decoder=Cs(CS_ARCH_X86,CS_MODE_64)
    with tempfile.TemporaryDirectory(prefix='ams-guid-xor-controls-') as directory:
        directory=Path(directory)
        for operation in ('xor','add','and'):
            assembly=directory/(operation+'.s');object_=directory/(operation+'.o');binary=directory/(operation+'.bin')
            assembly.write_text('.intel_syntax noprefix\n.text\nmov eax,DWORD PTR [rbx+rcx*4]\nxor eax,37\nrol eax,5\nadd eax,17\nmov r8d,eax\n'+operation+' r8d,edi\nret\n')
            subprocess.run(['cc','-c',str(assembly),'-o',str(object_)],check=True,capture_output=True)
            subprocess.run(['objcopy','-O','binary','--only-section=.text',str(object_),str(binary)],check=True,capture_output=True)
            code=binary.read_bytes();base=0x1000000;instructions=list(decoder.disasm(code,base))
            image=bytearray(0x2000);image[:6]=b'\x7fELF\x02\x01'
            struct.pack_into('<Q',image,32,64);struct.pack_into('<HH',image,54,56,1)
            struct.pack_into('<IIQQQQQQ',image,64,1,5,0x1000,base,0,len(code)+16,4096,4096)
            image[0x1000:0x1000+len(code)+16]=code+bytes([0x90])*16;image=bytes(image)
            end=instructions[-2].address+instructions[-2].size
            candidate=next(item for item in components(image,base) if item['end']==end and item['output_register']=='r8')
            verdict=prove(candidate)
            if operation=='xor':
                assert verdict=='unsat';executions=verify_original(image,list(range(256)),candidate);assert executions==768
            else:
                assert verdict=='sat';executions=0
            rows.append(dict(invented_mix=operation,separability_proof=verdict,original_prefix_executions=executions))
    result=dict(status='pass',cases=rows,scope='invented register prefixes only; arbitrary incoming register/carry values; no target data, words or expressions emitted')
    args.output.write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(result))


if __name__=='__main__':main()
