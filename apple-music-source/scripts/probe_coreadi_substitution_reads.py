"""Locate candidate AES-family reads on invented CoreADI source executions.

Developer-only: the existing source oracle still maps vendor-derived data.
Only invented provisioning/device inputs are used. No account state, host
provisioning file, network, MID/OTP bytes or substitution values are exposed.
"""
from __future__ import annotations

import argparse
import hashlib
import json
from pathlib import Path
import re
import subprocess
import sys
import tempfile

from probe_auth_substitution_reads import SHIM, group_wrappers
from scan_auth_substitutions import TARGETS

COREADI_LOAD_BIAS: int = 0x10000000

CHILD_PROGRAM = '''
import ctypes,json,random,sys
sys.path.insert(0,sys.argv[1])
from coreadi_source import generate
rows=[]
for case_number,length in enumerate((32,256,1024)):
 generator=random.Random(0x86431+case_number)
 def entropy(_,destination,count):
  for index in range(count):destination[index]=generator.randrange(256)
  return 0
 def clock(_,seconds,microseconds):seconds[0]=1700000000;microseconds[0]=123456;return 0
 provision=bytes(length) if case_number==0 else generator.randbytes(length)
 status,output,result=generate(provision,b'0123456789abcdef',library=sys.argv[2],entropy=entropy,time=clock)
 rows.append(dict(case=case_number,invented_provision_bytes=length,api_status=status,backend_status=result.status,source_PC=hex(result.pc),MID_bytes=result.mid_size,OTP_bytes=result.otp_size))
library=ctypes.CDLL(sys.argv[2]);library.ams_stage_reads.argtypes=[ctypes.c_uint,ctypes.c_uint];library.ams_stage_reads.restype=ctypes.c_uint64
stages=[dict(operation=name,total_reads=library.ams_stage_reads(index,0),classified_candidate_reads=library.ams_stage_reads(index,1)) for index,name in enumerate(('load_library','set_store','set_device','request_OTP'))]
print(json.dumps(dict(cases=rows,operation_read_counts=stages)))
'''


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('checkout', type=Path)
    parser.add_argument('--classification', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    arguments = parser.parse_args()
    root = arguments.checkout.resolve()
    classification = json.loads(arguments.classification.read_text())
    filename, digest = TARGETS['coreadi']
    if classification['target'] != 'coreadi' or classification['artifact_sha256'] != digest:
        raise ValueError('CoreADI classification identity mismatch')
    if hashlib.sha256((root / 'rootfs/system/lib64' / filename).read_bytes()).hexdigest() != digest:
        raise ValueError('CoreADI original artifact identity mismatch')
    candidates = sorted(COREADI_LOAD_BIAS + int(row['elf_virtual_address'],16) for row in classification['rows'] if row.get('affine_equivalent_to_gf256_inversion'))
    bounds = (root / 'crypto/auth/coreadi/generated/bounds.inc').read_text()
    groups = sorted(set(re.findall(r'\badi_(?:ssc|adi)_page_[0-9a-f]+\b', bounds)))
    objects = sorted((root / 'build/auth/coreadi/CMakeFiles/wrapper_coreadi_source.dir').rglob('*.o'))
    if not candidates or not groups or not objects:
        raise ValueError('CoreADI candidate windows or existing source objects unavailable')
    with tempfile.TemporaryDirectory(prefix='ams-coreadi-substitution-use-') as temporary:
        directory = Path(temporary)
        source, library = directory / 'probe.c', directory / 'probe.so'
        shim = SHIM.replace('mescal_native_read', 'adi_native_read')
        shim = shim.replace('static unsigned long total_reads;', 'static unsigned long total_reads;static uint64_t stage_reads[4],stage_candidate_reads[4];static unsigned active_stage;\nuint64_t ams_stage_reads(unsigned stage,unsigned candidate){return stage<4?(candidate?stage_candidate_reads[stage]:stage_reads[stage]):0;}')
        shim = shim.replace('++total_reads;', '++total_reads;++stage_reads[active_stage];')
        shim = shim.replace('++c->reads;', '++c->reads;++stage_candidate_reads[active_stage];')
        wrappers = group_wrappers(groups).replace('current_state=state;int status=', 'current_state=state;if(state->cpu.pc==UINT64_C(0x1de220))active_stage=0;else if(state->cpu.pc==UINT64_C(0x1dbf50))active_stage=1;else if(state->cpu.pc==UINT64_C(0x1ded70))active_stage=2;else if(state->cpu.pc==UINT64_C(0x1d1270))active_stage=3;int status=')
        source.write_text((shim % ',\n'.join('{UINT64_C(0x%x),0,0,{0},{{0}},0}' % address for address in candidates)) + wrappers)
        subprocess.run(['cc','-O2','-shared','-fPIC','-I'+str(root/'crypto/keygen_experimental'),str(source),*map(str,objects),*['-Wl,--wrap='+name for name in groups],'-Wl,--wrap=adi_native_read','-o',str(library)],check=True,capture_output=True)
        completed = subprocess.run([sys.executable,'-S','-c',CHILD_PROGRAM,str(root/'tools/auth'),str(library)],check=True,text=True,capture_output=True,cwd=directory,timeout=60)
    observed = json.loads(completed.stderr)
    if observed['site_overflow'] or any(site['pc']=='0x0' for window in observed['windows'] for site in window['sites']):
        raise ValueError('CoreADI source read-site observation was incomplete')
    report = dict(status='invented CoreADI substitution read coverage',artifact_sha256=digest,classified_windows=len(candidates),**json.loads(completed.stdout),**observed,network_requests=0,private_material_written=False,scope='invented malformed provisioning in existing vendor-data-backed source oracle; source reachability only, no successful OTP/provisioning or standalone primitive claim')
    arguments.output.write_text(json.dumps(report,indent=2)+'\n')
    print(json.dumps({name:value for name,value in report.items() if name!='windows'}))


if __name__ == '__main__':
    main()
