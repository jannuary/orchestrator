"""Trace the MAC field's upstream seven-byte producer using replayed inputs.

All source objects remain untouched. Three passes discover the final buffer,
its pre-affine source, and that source's write boundaries. Only PCs/offsets are
reported. No pointer, identifier, key or buffer value is serialized.
"""
import argparse
import ctypes as C
import json
from pathlib import Path
import random
import re
import subprocess
import sys
import tempfile

from probe_auth_substitution_reads import group_wrappers
from trace_guid_field_producers import SHIM


def main():
 parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('checkout',type=Path);parser.add_argument('--output',type=Path,required=True);args=parser.parse_args();root=args.checkout.resolve();sys.path.insert(0,str(root/'tools/auth'))
 from device_identity import decode_android_guid_fields
 from mescal_source import Options,Result,Entropy,Clock,Time
 class Event(C.Structure):_fields_=[('previous_pc',C.c_uint64),('observed_pc',C.c_uint64),('field',C.c_uint),('changed',C.c_ubyte*18)]
 def derive(android,mac,profile):
  rng=random.Random(0x654991+profile*131);ticks=[0]
  def entropy(_,destination,count):
   for i in range(count):destination[i]=rng.randrange(256)
   return 0
  def clock(_):ticks[0]+=1;return 0x3234567800000000+ticks[0]*100003
  def wall(_,seconds,micros):seconds[0]=1702000000;micros[0]=123456;return 0
  callbacks=(Entropy(entropy),Clock(clock),Time(wall));options=Options(*callbacks,None)
  call=lib.wrapper_mescal_guid_fields;call.argtypes=[C.c_void_p,C.c_size_t,C.c_void_p,C.c_size_t,C.c_void_p,C.c_void_p,C.c_size_t,C.POINTER(Options),C.POINTER(Result)];call.restype=C.c_int
  serial=b'invented-MAC-trace';a=C.create_string_buffer(android);m=C.create_string_buffer(mac);s=C.create_string_buffer(serial);out=C.create_string_buffer(56);result=Result()
  assert call(a,len(android),s,len(serial),m,out,56,C.byref(options),C.byref(result))==0
  return decode_android_guid_fields(out.raw)
 rows=[]
 with tempfile.TemporaryDirectory(prefix='ams-MAC-field-producer-') as directory:
  directory=Path(directory);source,library=directory/'probe.c',directory/'probe.so'
  groups=sorted(set(re.findall(r'\bmescal_(?:ssc|corefp)_page_[0-9a-f]+\b',(root/'crypto/auth/mescal/generated/bounds.inc').read_text())))
  wrappers=group_wrappers(groups).replace('current_state=state;int status=','current_state=state;ams_enter(state,regions,count);int status=')
  source.write_text(SHIM+wrappers);objects=sorted((root/'build/auth/mescal/CMakeFiles/wrapper_mescal_source.dir').rglob('*.o'));assert objects
  subprocess.run(['cc','-std=c99','-O2','-shared','-fPIC','-I'+str(root/'crypto/keygen_experimental'),str(source),*map(str,objects),'-Wl,--wrap=mescal_native_read',*['-Wl,--wrap='+name for name in groups],'-o',str(library)],check=True,capture_output=True)
  lib=C.CDLL(str(library));lib.ams_reset.argtypes=[C.c_uint64,C.c_uint64];lib.ams_discovered.argtypes=[C.c_uint];lib.ams_discovered.restype=C.c_uint64;lib.ams_mac_source.restype=C.c_uint64;lib.ams_total.argtypes=[C.c_uint];lib.ams_total.restype=C.c_uint;lib.ams_events.argtypes=[C.c_uint];lib.ams_events.restype=C.POINTER(Event)
  for profile,(android,mac) in enumerate(((b'0123456789abcdef',bytes(range(6))),(b'fedcba9876543210',bytes(range(6,12))))):
   lib.ams_reset(0,0);first=derive(android,mac,profile);final=lib.ams_discovered(1);assert final
   lib.ams_reset(0,final);second=derive(android,mac,profile);upstream=lib.ams_mac_source();assert upstream and first==second and final==lib.ams_discovered(1)
   lib.ams_reset(0,upstream);third=derive(android,mac,profile);assert third==first and final==lib.ams_discovered(1)
   total=lib.ams_total(1);assert total;events=lib.ams_events(1);changes=[]
   for number in range(max(0,total-128),total):
    event=events[number%128];changes.append(dict(previous_read_PC=hex(event.previous_pc),observed_read_PC=hex(event.observed_pc),changed_source_offsets=[i for i in range(7) if event.changed[i]]))
   rows.append(dict(profile=profile,repeated_outputs_equal=True,guest_allocations_equal=True,total_changes=total,earlier_changes_omitted=max(0,total-128),changes=changes))
 report=dict(status='MAC pre-affine producer localized',cases=rows,network_requests=0,private_bytes_written=False,scope='last 128 source-buffer changes bounded by reads on two invented replayed profiles; caller derivation and whole GUID/auth remain unresolved')
 args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(dict(status=report['status'],changes=[row['total_changes'] for row in rows])))


if __name__=='__main__':main()
