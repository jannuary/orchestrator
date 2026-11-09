"""Locate classified substitutions on an invented source-native GUID path.

Developer-only source runtime oracle. No account/provisioning input, network,
host device identity, key, GUID bytes or table values are read or reported.
The existing source oracle retains vendor-derived initialization dependencies.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re
import subprocess
import sys
import tempfile

from scan_auth_substitutions import TARGETS,readonly_segments


SHIM = r'''
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include "spc_native.h"
struct read_site { uint64_t pc,reads;unsigned width; };
struct candidate { uint64_t begin,reads;unsigned target;unsigned char seen[128];struct read_site sites[64];unsigned site_count; };
static struct candidate candidates[]={
%s
};
static unsigned long total_reads;
static wrapper_kg_native_state *current_state;
static unsigned site_overflow;
int __real_mescal_native_read(const void*,size_t,uint64_t,unsigned,uint64_t*);
int __wrap_mescal_native_read(const void*r,size_t n,uint64_t address,unsigned width,uint64_t*out){
 size_t count=sizeof candidates/sizeof candidates[0],low=0,high=count;
 ++total_reads;
 while(low<high){size_t mid=low+(high-low)/2;if(candidates[mid].begin<=address)low=mid+1;else high=mid;}
 while(low){struct candidate*c=&candidates[--low];if(address-c->begin>=1024)break;
  if(width<=1024-(address-c->begin)){++c->reads;for(unsigned j=0;j<width;++j){unsigned bit=(unsigned)(address-c->begin)+j;c->seen[bit/8]|=1u<<(bit%%8);}
   uint64_t pc=current_state?current_state->cpu.pc:0;unsigned j;
   for(j=0;j<c->site_count;++j)if(c->sites[j].pc==pc&&c->sites[j].width==width)break;
   if(j==64)site_overflow=1;else {if(j==c->site_count)++c->site_count;c->sites[j].pc=pc;c->sites[j].width=width;++c->sites[j].reads;}}}
 return __real_mescal_native_read(r,n,address,width,out);
}
__attribute__((destructor))static void finish(void){
 size_t count=sizeof candidates/sizeof candidates[0];int comma=0;
 fprintf(stderr,"{\"total_source_reads\":%%lu,\"site_overflow\":%%u,\"windows\":[",total_reads,site_overflow);
 for(size_t i=0;i<count;++i){struct candidate*c=&candidates[i];unsigned bytes=0;
  if(!c->reads)continue;for(unsigned j=0;j<128;++j)bytes+=__builtin_popcount(c->seen[j]);
  fprintf(stderr,"%%s{\"target\":%%u,\"source_window_address\":\"0x%%llx\",\"reads\":%%llu,\"distinct_bytes\":%%u,\"sites\":[",comma?",":"",c->target,(unsigned long long)c->begin,(unsigned long long)c->reads,bytes);comma=1;
  for(unsigned j=0;j<c->site_count;++j)fprintf(stderr,"%%s{\"pc\":\"0x%%llx\",\"width\":%%u,\"reads\":%%llu}",j?",":"",(unsigned long long)c->sites[j].pc,c->sites[j].width,(unsigned long long)c->sites[j].reads);
  fprintf(stderr,"]}");}
 fprintf(stderr,"]}\n");
}
'''


def group_wrappers(names):
    signature = 'unsigned block,uint64_t bias,wrapper_kg_native_state*state,const wrapper_kg_payload_region*regions,size_t count,size_t budget'
    return '\n'.join(
        'int __real_%s(%s);int __wrap_%s(%s){wrapper_kg_native_state*old=current_state;current_state=state;int status=__real_%s(block,bias,state,regions,count,budget);current_state=old;return status;}'
        % (name, signature, name, signature, name) for name in names)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('checkout', type=Path)
    parser.add_argument('--corefp-classification', type=Path, required=True)
    parser.add_argument('--storeservices-classification', type=Path, required=True)
    parser.add_argument('--word-table-inventory',type=Path,help='Also observe statically inventoried bijective word arrays, including encoded arrays missed by raw classification')
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    root = args.checkout.resolve()
    candidates = []
    for target, path, bias, identifier in (
        ('corefp', args.corefp_classification, 0x4000000, 0),
        ('storeservices', args.storeservices_classification, 0, 1),
    ):
        report = json.loads(path.read_text())
        assert report['target'] == target and report['artifact_sha256'] == TARGETS[target][1]
        assert report['alignment'] in (4,16) and report['window_bytes'] == 1024
        candidates.extend((bias + int(row['elf_virtual_address'], 16), identifier)
                          for row in report['rows'] if row.get('affine_equivalent_to_gf256_inversion'))
    if args.word_table_inventory:
        inventory=json.loads(args.word_table_inventory.read_text())
        for module in inventory['rows']:
            target=module['target'];assert target in ('corefp','storeservices')
            filename,digest=TARGETS[target];image=(root/'rootfs/system/lib64'/filename).read_bytes()
            assert hashlib.sha256(image).hexdigest()==module['artifact_sha256']==digest
            ranges=readonly_segments(image,4);bias=0x4000000 if target=='corefp' else 0;identifier=0 if target=='corefp' else 1
            for table in module['candidate_tables']:
                if table['distinct_words']!=256:continue
                base=int(table['elf_virtual_address'],16)
                assert any(begin<=base and base+1024<=begin+len(data) for begin,data in ranges)
                candidates.append((bias+base,identifier))
    candidates=sorted(set(candidates))
    assert candidates and len({address for address, _ in candidates}) == len(candidates)
    with tempfile.TemporaryDirectory(prefix='ams-auth-substitution-use-') as temporary:
        directory = Path(temporary)
        source, library = directory / 'read_probe.c', directory / 'probe.so'
        bounds=(root/'crypto/auth/mescal/generated/bounds.inc').read_text()
        groups=sorted(set(re.findall(r'\bmescal_(?:ssc|corefp)_page_[0-9a-f]+\b',bounds)))
        assert groups
        source.write_text((SHIM % ',\n'.join('{UINT64_C(0x%x),0,%d,{0},{{0}},0}' % row for row in candidates))+group_wrappers(groups))
        objects = sorted((root / 'build/auth/mescal/CMakeFiles/wrapper_mescal_source.dir').rglob('*.o'))
        assert objects, 'existing source Mescal oracle objects unavailable'
        subprocess.run(['cc', '-shared', '-fPIC', '-O2', '-I'+str(root/'crypto/keygen_experimental'),str(source), *map(str, objects),
                        *['-Wl,--wrap='+name for name in groups],
                        '-Wl,--wrap=mescal_native_read', '-o', str(library)], check=True, capture_output=True)
        program = '''import json,sys
sys.path.insert(0,sys.argv[1])
from device_identity import derive_android_guid_fields
fields=derive_android_guid_fields(b'0123456789abcdef',bytes(range(6)),system_serial=b'invented-serial',library=sys.argv[2])
assert len(fields.first)==18 and len(fields.second)==7
print(json.dumps(dict(guid_field_lengths=[len(fields.first),len(fields.second)])))
'''
        completed = subprocess.run([sys.executable, '-S', '-c', program, str(root / 'tools/auth'), str(library)],
                                   check=True, capture_output=True, text=True, cwd=root, timeout=60)
        uses = json.loads(completed.stderr)
        assert not uses['site_overflow']
        assert all(site['pc']!='0x0' for window in uses['windows'] for site in window['sites'])
        result = dict(status='source GUID candidate-window liveness observation',
                      invented_device_inputs=True, network_requests=0, private_bytes_written=False,
                      **json.loads(completed.stdout), classified_windows=len(candidates), **uses,
                      word_inventory_included=args.word_table_inventory is not None,
                      target_names={'0': 'corefp', '1': 'storeservices'},
                      scope='existing source runtime with vendor-derived initialization; executed GUID path only, not signing/OTP or blob-free native-auth closure; no table values, indices or GUID bytes emitted')
        args.output.write_text(json.dumps(result, indent=2) + '\n')
        print(json.dumps({key: value for key, value in result.items() if key != 'windows'}))


if __name__ == '__main__':
    main()
