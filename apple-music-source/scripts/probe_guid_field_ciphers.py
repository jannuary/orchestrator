"""Reject bounded GUID field packing/cipher hypotheses using invented inputs.

The source runtime is a developer oracle, freshly linked from existing objects.
No host device ID, saved account/session data, provisioning or network is used.
Raw fields and candidate outputs remain in RAM; only match counts are written.
"""
import argparse
import ctypes as C
import hashlib
import hmac
import json
from pathlib import Path
import subprocess
import sys
import tempfile


def views(value,count):
    result=[]
    for reverse in (False,True):
        data=value[::-1] if reverse else value
        for little in (False,True):
            bits=[(byte>>bit)&1 for byte in data for bit in (range(8) if little else range(7,-1,-1))]
            for offset in range(len(bits)-count*9+1):
                groups=[bits[offset+9*i:offset+9*i+9] for i in range(count)]
                for extra_first in (False,True):
                    groups8=[group[1:] if extra_first else group[:8] for group in groups]
                    raw=bytes(sum(bit<<(i if little else 7-i) for i,bit in enumerate(group)) for group in groups8)
                    extra=[group[0] if extra_first else group[-1] for group in groups]
                    label=(reverse,little,offset,extra_first)
                    result.append((label,raw,extra))
    return result


def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('checkout',type=Path);parser.add_argument('--output',type=Path,required=True);args=parser.parse_args();root=args.checkout.resolve()
    sys.path[:0]=[str(root/'tools/auth'),str(Path(__file__).resolve().parents[1]/'src')]
    from device_identity import derive_android_guid_fields
    from apple_music_source.crypto.aes import AES
    from apple_music_source.auth._guid_cipher import encrypt_blocks as fp_encrypt,decrypt_blocks as fp_decrypt
    from apple_music_source.auth._ssc_guid_cipher import encrypt_blocks as ssc_encrypt,decrypt_blocks as ssc_decrypt
    from apple_music_source.auth._guid_parameters import KEY
    from apple_music_source.crypto._corelskd_ciphers import encrypt as core_encrypt,decrypt as core_decrypt
    profiles=[(b'0123456789abcdef',bytes(range(6))),(b'fedcba9876543210',bytes(range(6,12))),(b'0011223344556677',bytes(range(32,38))),(b'ffeeddccbbaa9988',bytes(range(80,86)))]
    rows=[];consistent=None;packing={}
    with tempfile.TemporaryDirectory(prefix='ams-guid-field-models-') as directory:
        library=Path(directory)/'source.so';objects=sorted((root/'build/auth/mescal/CMakeFiles/wrapper_mescal_source.dir').rglob('*.o'));assert objects
        subprocess.run(['cc','-shared',*map(str,objects),'-o',str(library)],check=True,capture_output=True)
        for profile,(android,mac) in enumerate(profiles):
            fields=derive_android_guid_fields(android,mac,system_serial=b'invented-field-model',library=library);matches=[]
            for field,(data,actual,count) in enumerate(((android,fields.first,16),(mac,fields.second,6))):
                assert len(actual)==(18 if field==0 else 7);decoded=views(actual,count)
                candidates=[]
                inputs=[('raw',data)]
                if field==0:inputs.append(('hex-decoded',bytes.fromhex(data.decode())))
                for name,message in inputs:
                    for padding in ('zeros','PKCS7','repeated'):
                        block=(message+bytes(16))[:16] if padding=='zeros' else message if len(message)==16 else message+bytes([16-len(message)])*(16-len(message)) if padding=='PKCS7' else (message*16)[:16]
                        functions=[('CoreFP-forward',fp_encrypt),('CoreFP-inverse',fp_decrypt),('SSC-forward',ssc_encrypt),('SSC-inverse',ssc_decrypt),('AES-forward',AES(KEY).encrypt_block),('AES-inverse',AES(KEY).decrypt_block)]
                        for variant in (0,1):
                            functions.append(('CoreLSKD-'+str(variant),lambda value,v=variant:core_encrypt(v,value,bytes(16))))
                        for cipher,function in functions:candidates.append((name+'/'+padding+'/'+cipher,function(block)))
                    for digest in ('sha1','sha256','sha512','md5'):
                        candidates.append((name+'/hash/'+digest,hashlib.new(digest,message).digest()))
                        candidates.append((name+'/HMAC/'+digest,hmac.new(KEY,message,digest).digest()))
                for label,value in candidates:
                    if len(value)>=len(actual) and any(value[start:start+len(actual)]==actual for start in range(len(value)-len(actual)+1)):matches.append((field,'digest-or-cipher-substring',label))
                    for layout,raw,extra in decoded:
                        if any(value[start:start+len(raw)]==raw for start in range(len(value)-len(raw)+1)):matches.append((field,'nine-bit-view',label,str(layout)))
                for layout,raw,extra in decoded:packing.setdefault((field,layout),[]).append((raw,extra))
            current=set(matches);consistent=current if consistent is None else consistent&current
            rows.append(dict(profile=profile,candidate_matches=len(matches)))
    parity=[]
    for (field,layout),records in packing.items():
        # A parity/constant tag is a meaningful packing control; no arbitrary
        # table fitting is attempted on these few observed device fields.
        checks=dict(all_zero=all(not bit for _,bits in records for bit in bits),all_one=all(bit for _,bits in records for bit in bits),even_parity=all(bit==(byte.bit_count()&1) for raw,bits in records for byte,bit in zip(raw,bits)),odd_parity=all(bit!=byte.bit_count()&1 for raw,bits in records for byte,bit in zip(raw,bits)))
        if any(checks.values()):parity.append(dict(field=field,layout=layout,checks=checks))
    report=dict(status='bounded hypotheses checked',profiles=rows,consistent_cipher_or_digest_matches=sorted(consistent),nine_bit_packing_controls=parity,network_requests=0,private_bytes_written=False,scope='only listed hash/HMAC, padding, fixed-cipher substring and nine-bit parity layouts on four invented profiles; no full GUID reconstruction claim')
    args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))


if __name__=='__main__':main()
