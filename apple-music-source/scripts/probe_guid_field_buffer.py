"""Locate GUID field data at the selector's post-dispatch frame boundary.

Four invented profiles only; buffers and fields stay in RAM. The report has
source addresses, sizes and match booleans, never device or crypto values.
"""
import argparse
import ctypes as C
import hashlib
import json
from pathlib import Path
import re
import subprocess
import sys
import tempfile

from probe_auth_substitution_reads import group_wrappers
from trace_guid_rounds import Native,Region

SHIM=r'''
#include "spc_native.h"
static wrapper_kg_native_state *current_state;
typedef void(*observe_type)(const wrapper_kg_native_state*,const wrapper_kg_payload_region*,size_t);
static observe_type observer;
void ams_observe(observe_type f){observer=f;}
'''


def main():
 parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('checkout',type=Path);parser.add_argument('--output',type=Path,required=True);args=parser.parse_args();root=args.checkout.resolve();sys.path[:0]=[str(root/'tools/auth'),str(root/'tools/crypto/keygen_experimental')]
 from device_identity import derive_android_guid_fields
 captured=[];errors=[];callback_type=C.CFUNCTYPE(None,C.POINTER(Native),C.POINTER(Region),C.c_size_t)
 def observe(fs,regions,count):
  try:
   pointer=fs.contents.cpu.gpr[6]-0x100
   for i in range(count):
    region=regions[i]
    if region.address<=pointer and pointer+128<=region.address+region.size:
     captured.append(C.string_at(region.data+pointer-region.address,128));return
   raise ValueError('frame range unavailable')
  except Exception as error:errors.append(type(error).__name__)
 callback=callback_type(observe);rows=[]
 with tempfile.TemporaryDirectory(prefix='ams-guid-field-boundary-') as directory:
  directory=Path(directory);source,library=directory/'probe.c',directory/'probe.so'
  groups=sorted(set(re.findall(r'\bmescal_(?:ssc|corefp)_page_[0-9a-f]+\b',(root/'crypto/auth/mescal/generated/bounds.inc').read_text())))
  wrappers=group_wrappers(groups).replace('current_state=state;int status=', 'current_state=state;if(observer&&state->cpu.pc==UINT64_C(0x20421e))observer(state,regions,count);int status=')
  source.write_text(SHIM+wrappers);objects=sorted((root/'build/auth/mescal/CMakeFiles/wrapper_mescal_source.dir').rglob('*.o'));assert objects
  subprocess.run(['cc','-std=c99','-O2','-shared','-fPIC','-I'+str(root/'crypto/keygen_experimental'),str(source),*map(str,objects),*['-Wl,--wrap='+name for name in groups],'-o',str(library)],check=True,capture_output=True)
  lib=C.CDLL(str(library));lib.ams_observe.argtypes=[callback_type];lib.ams_observe(callback)
  profiles=((b'0123456789abcdef',bytes(range(6))),(b'fedcba9876543210',bytes(range(6,12))),(b'0011223344556677',bytes(range(32,38))),(b'ffeeddccbbaa9988',bytes(range(80,86))))
  for profile,(android,mac) in enumerate(profiles):
   captured.clear();fields=derive_android_guid_fields(android,mac,system_serial=b'invented-frame-probe',library=library)
   assert not errors and len(captured)==1
   frame=captured[0];parts=(fields.first,fields.second)
   rows.append(dict(profile=profile,frame_bytes=128,field_bytes=[len(value) for value in parts],field_substring_offsets=[frame.find(value) for value in parts],android_literal_present=android in frame,mac_literal_present=mac in frame,hex_decoded_android_present=bytes.fromhex(android.decode()) in frame,frame_nonzero_offsets=[index for index,byte in enumerate(frame) if byte],field_printable=[all(32<=byte<127 for byte in value) for value in parts],field_hex_ascii=[all(byte in b'0123456789abcdefABCDEF' for byte in value) for value in parts],frame_zero_bytes=frame.count(0)))
 report=dict(status='post-dispatch boundary observed',source_PC='0x20421e',selector_frame_offset='-0x100',cases=rows,errors=errors,network_requests=0,private_bytes_written=False,scope='one post-dispatch buffer per invented source call; substring findings do not establish field generation or standalone closure')
 args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))


if __name__=='__main__':main()
