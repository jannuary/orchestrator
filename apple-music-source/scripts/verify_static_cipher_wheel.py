"""Verify installed fixed ciphers with checkout, dynamic loading and sockets denied.

Expected outputs use invented messages only. Cipher parameters are not emitted.
Original source/oracle differential evidence is separate from packaging closure.
"""
import argparse
import hashlib
import json
from pathlib import Path
import subprocess
import sys
import tempfile

CHILD=r'''
import ctypes,hashlib,json,sys
from pathlib import Path
payload=json.load(sys.stdin);target=Path(payload['target']).resolve();checkout=Path(payload['checkout']).resolve()
def guard(event,args):
 if event=='open' and isinstance(args[0],(str,bytes)):
  path=Path(args[0]).resolve()
  if path==checkout or checkout in path.parents:raise RuntimeError('checkout access denied')
 if event in ('ctypes.dlopen','socket.__new__','subprocess.Popen'):raise RuntimeError('external runtime denied')
sys.addaudithook(guard);sys.path.insert(0,str(target))
import apple_music_source
from apple_music_source.crypto._corelskd_ciphers import encrypt,decrypt
from apple_music_source.auth._guid_cipher import encrypt_blocks,decrypt_blocks
assert target in Path(apple_music_source.__file__).resolve().parents
from apple_music_source.auth._guid_field_stages import mix20,unmix20
from apple_music_source.auth._guid_input_expansion import expand328
from apple_music_source.auth._guid_record_mixer import mix_record
from apple_music_source.auth._guid_record_size import record_size
from apple_music_source.auth._guid_hash_tail import assemble_hash_tail
from apple_music_source.auth import derive_android_guid_mac_field
for vector in payload.get('hash_tails',[]):assert assemble_hash_tail(bytes.fromhex(vector['scalars']),*(bytes.fromhex(block) for block in vector['folds'])).hex()==vector['output']
for vector in payload.get('record_mixers',[]):assert mix_record(bytes.fromhex(vector['input'])).hex()==vector['output']
for vector in payload.get('record_sizes',[]):assert record_size(bytes.fromhex(vector['input']))==vector['output_size']
for vector in payload.get('MAC_fields',[]):assert derive_android_guid_mac_field(bytes.fromhex(vector['MAC'])).hex()==vector['field']
for vector in payload.get('expansion',[]):assert expand328(bytes.fromhex(vector['input'])).hex()==vector['output']
for vector in payload.get('field_stages',[]):
 original=bytes.fromhex(vector['input']);expected=bytes.fromhex(vector['output']);assert mix20(original)==expected and unmix20(expected)==original
if payload.get('ssc'):
 from apple_music_source.auth._ssc_guid_cipher import encrypt_blocks as ssc_encrypt,decrypt_blocks as ssc_decrypt
 for case in payload['ssc']:assert ssc_encrypt(bytes.fromhex(case['data'])).hex()==case['expected'];assert ssc_decrypt(bytes.fromhex(case['data'])).hex()==case['inverse']
for name,digest in payload['hashes'].items():assert hashlib.sha256((target/name).read_bytes()).hexdigest()==digest
for case in payload['cases']:
 data=bytes.fromhex(case['data']);iv=bytes.fromhex(case['iv']);variant=case['variant']
 output=encrypt(variant,data,iv);assert output.hex()==case['expected'];assert decrypt(variant,output,iv)==data
for case in payload['guid']:
 data=bytes.fromhex(case['data']);assert encrypt_blocks(data).hex()==case['forward'];assert decrypt_blocks(data).hex()==case['inverse']
print(json.dumps(dict(status='pass',hash_tail_cases=len(payload.get('hash_tails',[])),record_mixer_states=len(payload.get('record_mixers',[])),record_size_inputs=len(payload.get('record_sizes',[])),MAC_field_cases=len(payload.get('MAC_fields',[])),corelskd_messages=len(payload['cases']),guid_messages=len(payload['guid']),input_expansion_states=len(payload.get('expansion',[])),field_stage_states=len(payload.get('field_stages',[])),storeservices_messages=len(payload.get('ssc',[])),runtime_files_hashed=len(payload['hashes']),checkout_access=False,dynamic_loading=False,network=False)))
'''


def main():
 parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('wheel',type=Path);parser.add_argument('--output',type=Path,required=True);args=parser.parse_args()
 package=Path(__file__).resolve().parents[1];sys.path.insert(0,str(package/'src'))
 from apple_music_source.crypto._corelskd_ciphers import encrypt
 from apple_music_source.auth._guid_cipher import encrypt_blocks,decrypt_blocks
 paths=['auth/_guid_hash_tail.py','auth/_guid_record_mixer.py','auth/_guid_record_size.py','auth/device_identity.py','auth/_guid_mac_parameters.py','auth/_guid_input_expansion.py','auth/_guid_field_stages.py','crypto/_corelskd_ciphers.py','crypto/_corelskd_parameters.py','crypto/masked_cbc.py','crypto/aes.py','auth/_guid_cipher.py','auth/_guid_parameters.py']
 if (package/'src/apple_music_source/auth/_ssc_guid_parameters.py').exists():paths.extend(['auth/_ssc_guid_cipher.py','auth/_ssc_guid_parameters.py','auth/_ssc_guid_inverse_parameters.py'])
 hashes={'apple_music_source/'+name:hashlib.sha256((package/'src/apple_music_source'/name).read_bytes()).hexdigest() for name in paths}
 cases=[];guid=[];ssc=[]
 if 'auth/_ssc_guid_parameters.py' in paths:
  from apple_music_source.auth._ssc_guid_cipher import encrypt_blocks as ssc_encrypt,decrypt_blocks as ssc_decrypt
 for size in (0,16,32,48,64,128):
  data=bytes((index*43+size*7)%256 for index in range(size));iv=bytes((index*11+size)%256 for index in range(16))
  for variant in (0,1):cases.append(dict(variant=variant,data=data.hex(),iv=iv.hex(),expected=encrypt(variant,data,iv).hex()))
  guid.append(dict(data=data.hex(),forward=encrypt_blocks(data).hex(),inverse=decrypt_blocks(data).hex()))
  if 'auth/_ssc_guid_parameters.py' in paths:ssc.append(dict(data=data.hex(),expected=ssc_encrypt(data).hex(),inverse=ssc_decrypt(data).hex()))
 with tempfile.TemporaryDirectory(prefix='ams-fixed-installed-') as directory:
  target=Path(directory)/'installed'
  subprocess.run([sys.executable,'-m','pip','install','--no-index','--no-deps','--target',str(target),str(args.wheel.resolve())],check=True,capture_output=True)
  result=subprocess.run([sys.executable,'-I','-c',CHILD],input=json.dumps(dict(target=str(target),checkout=str(package.parents[1]),hashes=hashes,hash_tails=json.loads((package/'tests/vectors/guid_hash_tail.json').read_text())['cases'],record_mixers=json.loads((package/'tests/vectors/guid_record_mixer.json').read_text())['cases'],record_sizes=json.loads((package/'tests/vectors/guid_record_size.json').read_text())['cases'],MAC_fields=json.loads((package/'tests/vectors/guid_mac_field.json').read_text())['cases'],cases=cases,guid=guid,ssc=ssc,field_stages=json.loads((package/'tests/vectors/guid_field_mixer.json').read_text())['cases'],expansion=json.loads((package/'tests/vectors/guid_input_expansion.json').read_text())['cases'])),text=True,capture_output=True,cwd=directory,check=False)
  if result.returncode:raise RuntimeError(result.stderr)
 report=json.loads(result.stdout);report.update(wheel_sha256=hashlib.sha256(args.wheel.read_bytes()).hexdigest(),scope='installed artifact closure and invented-message equality with audited source modules; native differential reports establish cipher behavior separately')
 args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))


if __name__=='__main__':main()
