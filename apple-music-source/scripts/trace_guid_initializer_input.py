"""Follow the first GUID initializer's variable-length input record backwards.

Invented profiles and replayed OS inputs only. Buffers/pointers stay in RAM;
reports contain producer PC boundaries, offsets and encoding equality flags.
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

ADDON=r'''
struct call_event{uint64_t target,input,output,length;uint32_t r14;unsigned char candidates[2][16];unsigned valid[2];};
static struct call_event call_events[128];static unsigned call_used;
unsigned ams_call_count(void){return call_used;}
const struct call_event*ams_call_events(void){return call_events;}
static unsigned char hash_tail_scalars[12],hash_tail_blocks[456];static unsigned hash_tail_ready;
static unsigned char tail_scalars[26],tail_blocks[456];static unsigned tail_ready,tail_fill_ok;
static unsigned char forward_expansion[328];static unsigned forward_ready;
static unsigned char input_before[256];static unsigned input_before_count;
static uint64_t input_requested,input_last_pc;static unsigned input_width,input_finished,input_used;
static const void*input_regions;static size_t input_region_count;
static unsigned char*input_watch;static unsigned char input_previous[256];
struct input_event{uint64_t previous_pc,observed_pc;unsigned char changed[256];};static struct input_event input_events[2048];
void ams_input_config(uint64_t address,unsigned width){hash_tail_ready=0;tail_ready=tail_fill_ok=0;forward_ready=0;call_used=0;input_before_count=0;input_requested=address;input_width=width;input_watch=0;input_finished=input_used=0;input_last_pc=0;}
static void ams_input_enter(wrapper_kg_native_state*s,const wrapper_kg_payload_region*r,size_t n){
 input_regions=r;input_region_count=n;
 if(s->cpu.pc==UINT64_C(0x42f6380)){unsigned char*p=locate(r,n,s->cpu.gpr[5],36);if(p&&call_used<128){uint64_t args[3];uint32_t d[3];memcpy(args,p,24);memcpy(d,p+24,12);uint64_t h=(UINT64_C(0xa2f384a639655707)^s->cpu.gpr[5])*UINT64_C(0x54f99365);struct call_event*e=call_events+call_used++;memset(e,0,sizeof *e);e->target=UINT64_C(0x42f63b7)+(int32_t)(((uint32_t)h^d[0])-UINT32_C(0x3bc));e->input=args[0];e->output=args[1];e->length=args[2];e->r14=d[1]+(uint32_t)h;for(unsigned k=0;k<2;++k){p=locate(r,n,args[0]+(k?UINT64_C(0xc18e2b1f7b8a47ec):0),16);if(p){memcpy(e->candidates[k],p,16);e->valid[k]=1;}}}}

 if(s->cpu.pc==UINT64_C(0x205190)&&input_requested&&input_width<=256){input_watch=locate(r,n,input_requested,input_width);if(input_watch)memcpy(input_previous,input_watch,input_width);input_last_pc=s->cpu.pc;}}
static void ams_input_read(uint64_t address){
 if(current_state&&current_state->cpu.pc==UINT64_C(0x42f807a)){
  static const unsigned offsets[12]={0x3e,0x3d,0x3c,0x3b,0x3a,0x39,0x38,0x37,0x36,0x35,0x34,0x2a};unsigned valid=1;uint64_t frame=current_state->cpu.gpr[6];
  for(unsigned i=0;i<12;++i){unsigned char*q=locate((const wrapper_kg_payload_region*)input_regions,input_region_count,frame-offsets[i],1);if(!q){valid=0;break;}hash_tail_scalars[i]=*q;}
  unsigned widths[3]={64,64,328},starts[3]={0x150,0xb0,0x340},at=0;
  for(unsigned i=0;i<3;++i){unsigned char*q=locate((const wrapper_kg_payload_region*)input_regions,input_region_count,frame-starts[i],widths[i]);if(!q){valid=0;break;}memcpy(hash_tail_blocks+at,q,widths[i]);at+=widths[i];}hash_tail_ready=valid;
 }
 if(!current_state||!input_watch||input_finished)return;uint64_t pc=current_state->cpu.pc;
 if(pc==UINT64_C(0x42fb6b0)&&current_state->cpu.gpr[11]+UINT64_C(0xc18e2b1f7b8a47ec)==input_requested){unsigned char*q=locate((const wrapper_kg_payload_region*)input_regions,input_region_count,current_state->cpu.gpr[6]-0x104,4);uint32_t count=0;if(q){memcpy(&count,q,4);if(count==UINT32_C(0x70a1dabc)){memcpy(input_before,input_watch,input_width);++input_before_count;}}}
 if(pc==UINT64_C(0x42fa8e9)&&address==input_requested){
  static const unsigned offsets[26]={0xcf,0xce,0xcd,0xcc,0xcb,0xca,0xc9,0xc8,0xc7,0xb8,0x4c,0x48,0x47,0x3f,0x3e,0x3d,0x3c,0x3b,0x3a,0x39,0x38,0x37,0x36,0x35,0x34,0x2a};unsigned valid=1;uint64_t frame=current_state->cpu.gpr[6];
  for(unsigned i=0;i<26;++i){unsigned char*q=locate((const wrapper_kg_payload_region*)input_regions,input_region_count,frame-offsets[i],1);if(!q){valid=0;break;}tail_scalars[i]=*q;}
  unsigned widths[3]={64,64,328},starts[3]={0x150,0xb0,0x340},at=0;
  for(unsigned i=0;i<3;++i){unsigned char*q=locate((const wrapper_kg_payload_region*)input_regions,input_region_count,frame-starts[i],widths[i]);if(!q){valid=0;break;}memcpy(tail_blocks+at,q,widths[i]);at+=widths[i];}
  tail_fill_ok=1;for(unsigned i=0;i<input_width;++i)if(input_watch[i]!=0x72)tail_fill_ok=0;tail_ready=valid;
 }
 if(pc==UINT64_C(0x42f8d61)&&current_state->cpu.gpr[9]==UINT64_C(0x4b983a73)){unsigned char*q=locate((const wrapper_kg_payload_region*)input_regions,input_region_count,current_state->cpu.gpr[6]-0x340,328);if(q){memcpy(forward_expansion,q,328);forward_ready=1;}}
 if(memcmp(input_watch,input_previous,input_width)){struct input_event*e=input_events+(input_used++%2048);e->previous_pc=input_last_pc;e->observed_pc=pc;memset(e->changed,0,256);for(unsigned i=0;i<input_width;++i)e->changed[i]=input_watch[i]!=input_previous[i];memcpy(input_previous,input_watch,input_width);}
 input_last_pc=pc;if(pc==UINT64_C(0x42f65f8)&&address==input_requested&&current_state->cpu.gpr[1]==UINT64_C(0xb8d3569))input_finished=1;
}
unsigned ams_hash_tail_ready(void){return hash_tail_ready;}
const unsigned char*ams_hash_tail_scalars(void){return hash_tail_scalars;}
const unsigned char*ams_hash_tail_blocks(void){return hash_tail_blocks;}
unsigned ams_tail_ready(void){return tail_ready&&tail_fill_ok;}
const unsigned char*ams_tail_scalars(void){return tail_scalars;}
const unsigned char*ams_tail_blocks(void){return tail_blocks;}
unsigned ams_forward_ready(void){return forward_ready;}
const unsigned char*ams_forward_expansion(void){return forward_expansion;}
const unsigned char*ams_input_before(void){return input_before;}
unsigned ams_input_before_count(void){return input_before_count;}
unsigned ams_input_count(void){return input_used;}
unsigned ams_input_finished(void){return input_finished;}
const struct input_event*ams_input_events(void){return input_events;}
uint64_t ams_hash_input_address(void){return hash_input_address;}
'''


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('checkout',type=Path)
    parser.add_argument('--output',type=Path,required=True)
    args=parser.parse_args();root=args.checkout.resolve()
    sys.path.insert(0,str(root/'tools/auth'))
    sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'src'))
    from apple_music_source.auth._guid_record_mixer import mix_record
    from apple_music_source.auth._guid_record_size import record_size
    from apple_music_source.auth._guid_input_expansion import expand328
    from guid_record_tail_model import assemble_record_tail
    from replay_guid_record_middle import GuidMiddleOracle, HASH_LAYOUT, LOOKUP_START_ADDRESS, LOOKUP_BYTE_COUNT
    from emit_guid_middle_source import readonly_seed_locations
    from guid_middle_source_model import generate_middle_state
    from guid_hash_middle_source_model import generate_middle_state as generate_hash_middle_state
    from apple_music_source.auth._guid_hash_tail import assemble_hash_tail
    from guid_field_source_model import MiddleParameters, derive_first_guid_field
    from device_identity import decode_android_guid_fields
    from mescal_source import Options,Result,Entropy,Clock,Time
    class Event(C.Structure):
        _fields_=[('previous_pc',C.c_uint64),('observed_pc',C.c_uint64),('changed',C.c_ubyte*256)]
    class CallEvent(C.Structure):
        _fields_=[('target',C.c_uint64),('input',C.c_uint64),('output',C.c_uint64),('length',C.c_uint64),('r14',C.c_uint32),('candidates',(C.c_ubyte*16)*2),('valid',C.c_uint*2)]
    def derive(android,mac,profile):
        rng=random.Random(0x654991+profile*131);ticks=[0]
        def entropy(_,destination,count):
            for i in range(count):destination[i]=rng.randrange(256)
            return 0
        def clock(_):ticks[0]+=1;return 0x3234567800000000+ticks[0]*100003
        def wall(_,seconds,micros):seconds[0]=1702000000;micros[0]=123456;return 0
        callbacks=(Entropy(entropy),Clock(clock),Time(wall));options=Options(*callbacks,None)
        call=lib.wrapper_mescal_guid_fields
        call.argtypes=[C.c_void_p,C.c_size_t,C.c_void_p,C.c_size_t,C.c_void_p,C.c_void_p,C.c_size_t,C.POINTER(Options),C.POINTER(Result)];call.restype=C.c_int
        serial=b'invented-initializer-record';a=C.create_string_buffer(android);m=C.create_string_buffer(mac);s=C.create_string_buffer(serial);out=C.create_string_buffer(56);result=Result()
        assert call(a,len(android),s,len(serial),m,out,56,C.byref(options),C.byref(result))==0
        return decode_android_guid_fields(out.raw)
    rows=[]
    with tempfile.TemporaryDirectory(prefix='ams-GUID-record-') as directory, GuidMiddleOracle(root) as middle_oracle, GuidMiddleOracle(root,HASH_LAYOUT) as hash_oracle:
        directory=Path(directory);source,library=directory/'probe.c',directory/'probe.so'
        groups=sorted(set(re.findall(r'\bmescal_(?:ssc|corefp)_page_[0-9a-f]+\b',(root/'crypto/auth/mescal/generated/bounds.inc').read_text())))
        shim=SHIM.replace('static wrapper_kg_native_state*current_state;', 'static wrapper_kg_native_state*current_state;static uint64_t hash_input_address;')
        shim=shim.replace('void ams_reset(uint64_t first,uint64_t second){','void ams_reset(uint64_t first,uint64_t second){hash_input_address=0;')
        shim=shim.replace('memcpy(hash_input,p,length);hash_input_size=length;','memcpy(hash_input,p,length);hash_input_size=length;hash_input_address=a;')
        shim=shim.replace('int __real_mescal_native_read(', 'static void ams_input_read(uint64_t);\nint __real_mescal_native_read(',1)
        shim=shim.replace('int ok=__real_mescal_native_read(r,n,a,w,out);','ams_input_read(a);int ok=__real_mescal_native_read(r,n,a,w,out);',1)
        wrappers=group_wrappers(groups).replace('current_state=state;int status=', 'current_state=state;ams_enter(state,regions,count);ams_input_enter(state,regions,count);int status=')
        source.write_text(shim+ADDON+wrappers)
        objects=sorted((root/'build/auth/mescal/CMakeFiles/wrapper_mescal_source.dir').rglob('*.o'));assert objects
        subprocess.run(['cc','-std=c99','-O2','-shared','-fPIC','-I'+str(root/'crypto/keygen_experimental'),str(source),*map(str,objects),'-Wl,--wrap=mescal_native_read',*['-Wl,--wrap='+name for name in groups],'-o',str(library)],check=True,capture_output=True)
        lib=C.CDLL(str(library));lib.ams_hash_tail_scalars.restype=C.c_void_p;lib.ams_hash_tail_blocks.restype=C.c_void_p;lib.ams_tail_scalars.restype=C.c_void_p;lib.ams_tail_blocks.restype=C.c_void_p;lib.ams_forward_expansion.restype=C.c_void_p;lib.ams_call_events.restype=C.POINTER(CallEvent);lib.ams_input_before.restype=C.c_void_p;lib.ams_reset.argtypes=[C.c_uint64,C.c_uint64];lib.ams_input_config.argtypes=[C.c_uint64,C.c_uint];lib.ams_discovered.argtypes=[C.c_uint];lib.ams_discovered.restype=C.c_uint64;lib.ams_hash_input_address.restype=C.c_uint64;lib.ams_hash_input.restype=C.c_void_p;lib.ams_input_events.restype=C.POINTER(Event)
        middle_readonly_seed=b''.join(bytes(middle_oracle.unicorn.mem_read(address,length)) for address,length in readonly_seed_locations(middle_oracle))
        middle_substitution=bytes(middle_oracle.unicorn.mem_read(LOOKUP_START_ADDRESS,LOOKUP_BYTE_COUNT))
        hash_readonly_seed=b''.join(bytes(hash_oracle.unicorn.mem_read(address,length)) for address,length in readonly_seed_locations(hash_oracle))
        hash_substitution=bytes(hash_oracle.unicorn.mem_read(HASH_LAYOUT.lookup_address,LOOKUP_BYTE_COUNT))
        for profile,(android,mac) in enumerate(((b'0123456789abcdef',bytes(range(6))),(b'fedcba9876543210',bytes(range(6,12))),(b'0011223344556677',bytes(range(12,18))),(b'ffeeddccbbaa9988',bytes(range(18,24))))):
            lib.ams_reset(0,0);lib.ams_input_config(0,0);first=derive(android,mac,profile);target=lib.ams_discovered(0);assert target
            lib.ams_reset(target,0);second=derive(android,mac,profile);assert first==second
            address=lib.ams_hash_input_address();width=lib.ams_hash_input_size();assert address and 0<width<=256
            original=C.string_at(lib.ams_hash_input(),width)
            lib.ams_reset(target,0);lib.ams_input_config(address,width);third=derive(android,mac,profile)
            assert third==first and address==lib.ams_hash_input_address() and original==C.string_at(lib.ams_hash_input(),width) and lib.ams_input_finished()
            events=lib.ams_input_events();count=lib.ams_input_count();changes=[]
            for number in range(max(0,count-2048),count):
                event=events[number%2048];changes.append(dict(previous_read_PC=hex(event.previous_pc),observed_read_PC=hex(event.observed_pc),changed_record_offsets=[i for i in range(width) if event.changed[i]]))
            assert lib.ams_input_before_count()==1
            before=C.string_at(lib.ams_input_before(),width)
            assert bytes(x^0x47 for x in mix_record(bytes(x^0x47 for x in before)))==original
            assert lib.ams_tail_ready()
            scalars=C.string_at(lib.ams_tail_scalars(),26);material=C.string_at(lib.ams_tail_blocks(),456);clear_material=bytes(x^0x54 for x in material)
            original_middle_state=middle_oracle.derive_state(android)
            original_middle_checks=dict(scalars_equal=original_middle_state.scalar_bytes==scalars,first_fold_equal=original_middle_state.first_fold_bytes==material[:64],second_fold_equal=original_middle_state.second_fold_bytes==material[64:128],expanded_fold_equal=original_middle_state.expanded_fold_bytes==material[128:])
            assert all(original_middle_checks.values()),original_middle_checks
            tail=assemble_record_tail(width,scalars,clear_material[:64],clear_material[64:128],clear_material[128:])
            assert bytes(x^0x47 for x in tail)==original
            assert record_size(android)==width and lib.ams_forward_ready()
            native_forward=C.string_at(lib.ams_forward_expansion(),328)
            expected_forward=bytes(x^0x47^0x54 for x in expand328(bytes(x^0x47 for x in android)))
            assert native_forward==expected_forward
            source_middle=generate_middle_state(expected_forward,middle_oracle.initial_second_fold,middle_readonly_seed,middle_substitution)
            assert source_middle==(scalars,material[:64],material[64:128],material[128:])
            source_clear_blocks=tuple(bytes(value^0x54 for value in block) for block in source_middle[1:])
            source_record=assemble_record_tail(width,source_middle[0],*source_clear_blocks)
            assert bytes(value^0x47 for value in source_record)==original
            assert lib.ams_hash_tail_ready()
            hash_scalars=C.string_at(lib.ams_hash_tail_scalars(),12);hash_material=C.string_at(lib.ams_hash_tail_blocks(),456)
            native_hash_state=(hash_scalars,hash_material[:64],hash_material[64:128],hash_material[128:])
            original_hash_middle=hash_oracle.derive_state(original)
            assert native_hash_state==(original_hash_middle.scalar_bytes,original_hash_middle.first_fold_bytes,original_hash_middle.second_fold_bytes,original_hash_middle.expanded_fold_bytes)
            source_hash_middle=generate_hash_middle_state(expand328(original),hash_oracle.initial_second_fold,hash_readonly_seed,hash_substitution)
            assert source_hash_middle==native_hash_state
            source_hash=assemble_hash_tail(source_hash_middle[0],*(bytes(value^0x47 for value in block) for block in source_hash_middle[1:]))
            assert source_hash[:18]==first.first
            assert derive_first_guid_field(android,MiddleParameters(middle_oracle.initial_second_fold,middle_readonly_seed,middle_substitution),MiddleParameters(hash_oracle.initial_second_fold,hash_readonly_seed,hash_substitution))==first.first
            groups={}
            for number,event in enumerate(changes):
                key=(event['previous_read_PC'],event['observed_read_PC'])
                if key not in groups:groups[key]=dict(previous_read_PC=key[0],observed_read_PC=key[1],count=0,changed_record_offsets=set(),first_retained_event=number,last_retained_event=number)
                group=groups[key];group['count']+=1;group['changed_record_offsets'].update(event['changed_record_offsets']);group['last_retained_event']=number
            producer_groups=list(groups.values())
            for group in producer_groups:group['changed_record_offsets']=sorted(group['changed_record_offsets'])
            forms={'before_raw':before,'before_xor47':bytes(x^0x47 for x in before),'raw':original,'xor47':bytes(x^0x47 for x in original),'encode167':bytes((167*x+18)&255 for x in original),'decode23':bytes((23*x+98)&255 for x in original)}
            metadata={name:dict(printable_ASCII_bytes=sum(32<=x<127 for x in value),AndroidID_occurs=android in value,MAC_occurs=mac in value) for name,value in forms.items()}
            calls=[];labels={}
            def label(address):
                if address not in labels:labels[address]=len(labels)
                return labels[address]
            for i in range(lib.ams_call_count()):
                event=lib.ams_call_events()[i];matches=[]
                for k in range(2):
                    if event.valid[k]:
                        value=bytes(event.candidates[k])
                        for codec,decoded in [('raw',value),('xor47',bytes(x^0x47 for x in value)),('encode167',bytes((167*x+18)&255 for x in value)),('decode23',bytes((23*x+98)&255 for x in value))]:
                            if decoded==android:matches.append(dict(pointer_form=k,codec=codec))
                calls.append(dict(target_PC=hex(event.target),input_label=label(event.input),decoded_input_label=label((event.input+0xc18e2b1f7b8a47ec)&0xffffffffffffffff),output_label=label(event.output),decoded_output_label=label((event.output+0xc18e2b1f7b8a47ec)&0xffffffffffffffff),hash_input_length=((event.r14-0x69eb7d15)&0xffffffff) if event.target==0x42f6493 else None,AndroidID_matches=matches))
            rows.append(dict(calls=calls,profile=profile,record_bytes=width,repeated_fields_and_records_equal=True,cyclic_mixer_prediction_equal=True,record_size_prediction_equal=True,complete_record_tail_prediction_equal=True,original_middle_state_equal=True,generated_middle_state_equal=True,source_record_from_android_id_equal=True,original_hash_middle_state_equal=True,generated_hash_middle_state_equal=True,source_first_GUID_field_equal=True,complete_source_pipeline_equal=True,forward_ARX_prediction_equal=True,encoding_metadata=metadata,total_changes=count,earlier_changes_omitted=max(0,count-2048),producer_groups=producer_groups,earlier_event_detail_omitted=max(0,count-256),changes=changes[-256:]))
    report=dict(status='GUID input record producer traced',cases=rows,network_requests=0,private_material_written=False,scope='complete first GUID arithmetic from Android ID with unresolved readonly/substitution parameters supplied only in RAM; no standalone first GUID/auth claim')
    args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(dict(status=report['status'],record_bytes=[r['record_bytes'] for r in rows],changes=[r['total_changes'] for r in rows])))


if __name__=='__main__':main()
