#define _POSIX_C_SOURCE 200809L
#include "spc_native_internal.h"
#include "spc_graph.h"
#include "spc_generate.h"
#include "ckc_packet.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <sys/time.h>
#include <time.h>
#include "native_generated/images.inc"
#define KG_CORE UINT64_C(0x10000000)
#define KG_STACK UINT64_C(0x1000000)
#define KG_HEAP UINT64_C(0x2000000)
#define KG_STOP UINT64_C(0x900000)
#define KG_ONCE (KG_STOP+16)
#define KG_ARENA ((size_t)0x100000)
#define KG_IMAGES (sizeof kg_images/sizeof kg_images[0])
#define KG_REGIONS (KG_IMAGES+2)
typedef struct wrapper_kg_spc_session {
    wrapper_kg_native_state state;
    wrapper_kg_payload_region regions[KG_REGIONS];
    unsigned char *owned[KG_REGIONS];
    size_t allocated;
    uint64_t once_ret[32],once_sp[32];size_t once_count;
    wrapper_kg_spc_request request_copy;
    const wrapper_kg_spc_request *request;
    wrapper_kg_spc_result *result;
    wrapper_kg_payload_imports bindings;
    wrapper_kg_native_state parent_state,worker_state;
    uint64_t worker_entry,worker_wake;
    int worker_pending,worker_active,worker_sleeping;
    uint64_t context_handle;
    int context_finalized;
} kg_runtime;
static uint64_t kg_steady(void) {
    struct timespec t;
    if(clock_gettime(CLOCK_MONOTONIC,&t))return 0;
    return (uint64_t)t.tv_sec*UINT64_C(1000000000)+(uint64_t)t.tv_nsec;
}
static unsigned char *kg_memory(kg_runtime *r,uint64_t at,size_t size,unsigned permission) {
    if((permission&1) && !kg_shadow_read_allowed(&r->state,at,size))return 0;
    return translate(r->regions,KG_REGIONS,at,size,permission);
}
static int kg_read(kg_runtime *r,uint64_t at,unsigned width,uint64_t *out) {
    return wrapper_kg_native_read_guarded(&r->state,r->regions,KG_REGIONS,at,width,out);
}
static int kg_write(kg_runtime *r,uint64_t at,unsigned width,uint64_t value) {
    unsigned char *p=kg_memory(r,at,width,2);unsigned j;
    if(!p)return 0;
    for(j=0;j<width;++j)p[j]=(unsigned char)(value>>(j*8));
    kg_shadow_written(&r->state,at,width);
    return 1;
}
static int kg_return(kg_runtime *r,uint64_t value) {
    wrapper_kg_payload_state *s=&r->state.cpu;
    uint64_t ret;
    if(!kg_read(r,s->gpr[7],8,&ret))return 0;
    kg_shadow_return(&r->state,s->gpr[7]);
    s->gpr[0]=value;s->gpr[7]+=8;s->pc=ret;return 1;
}
static int kg_entropy(kg_runtime *r,unsigned char *p,size_t n) {
    FILE *f;size_t done;
    if(r->request->entropy)return r->request->entropy(r->request->user,p,n)==0;
    f=fopen("/dev/urandom","rb");if(!f)return 0;
    done=fread(p,1,n,f);fclose(f);return done==n;
}
static uint64_t kg_clock(kg_runtime *r) {
    struct timespec t;
    ++r->result->clock_calls;
    if(r->request->clock)return r->request->clock(r->request->user);
    if(clock_gettime(CLOCK_MONOTONIC,&t))return 0;
    return (uint64_t)t.tv_sec*UINT64_C(1000000000)+(uint64_t)t.tv_nsec;
}
static int kg_time(kg_runtime *r,int64_t *seconds,int64_t *micros) {
    struct timeval t;
    if(r->request->time)return r->request->time(r->request->user,seconds,micros)==0;
    if(gettimeofday(&t,0))return 0;
    *seconds=t.tv_sec;*micros=t.tv_usec;return 1;
}
static int kg_string(kg_runtime *r,uint64_t at,char *out,size_t capacity) {
    size_t j;
    for(j=0;j<capacity;++j){uint64_t v;if(!kg_read(r,at+j,1,&v))return 0;out[j]=(char)v;if(!v)return 1;}
    return 0;
}
static int kg_service(kg_runtime *r,const char *name) {
    wrapper_kg_payload_state *s=&r->state.cpu;
    uint64_t a=s->gpr[5],b=s->gpr[4],c=s->gpr[3],value=0;
    unsigned char *p,*q;
    size_t n;
    if(!strcmp(name,"pthread_once")) {
        uint64_t once,ret;
        if(!kg_read(r,a,4,&once))return 0;
        if(!once){
            if(r->once_count==32 || !kg_read(r,s->gpr[7],8,&ret) || !kg_write(r,a,4,1) || !kg_write(r,s->gpr[7],8,KG_ONCE))return 0;
            r->once_ret[r->once_count]=ret;r->once_sp[r->once_count++]=s->gpr[7];s->pc=b;return 1;
        }
    } else if(!strcmp(name,"malloc") || !strcmp(name,"calloc")) {
        if(!strcmp(name,"calloc")){if(b && a>UINT64_MAX/b)return 0;a*=b;}
        if(a>KG_ARENA || r->allocated>KG_ARENA-a || r->allocated+a>KG_ARENA-15)return 0;
        value=KG_HEAP+r->allocated;r->allocated=(r->allocated+(size_t)a+15)&~(size_t)15;
    } else if(!strcmp(name,"pthread_create")) {
        /* Only the observed null-argument lifetime worker is admitted. Queue it
         * until the parent API returns and releases the shared registry lock. */
        if(b || c!=KG_CORE+0xdc000 || s->gpr[2] || r->worker_pending || r->worker_active || r->worker_sleeping)return 0;
        if(!kg_write(r,a,8,1))return 0;
        r->worker_entry=c;r->worker_pending=1;
    } else if(!strcmp(name,"pthread_kill")) {
        if(a!=1 || b || !(r->worker_pending || r->worker_sleeping))return 0;
        if(r->worker_sleeping){uint64_t now=kg_steady();if(!now || now>=r->worker_wake)return 0;}
    } else if(!strcmp(name,"sleep")) {
        if(!r->worker_active || a!=5 || !kg_return(r,0))return 0;
        r->worker_wake=kg_steady();if(!r->worker_wake)return 0;
        r->worker_state=r->state;r->worker_wake+=UINT64_C(5000000000);
        r->worker_sleeping=1;r->worker_active=0;r->state=r->parent_state;return 1;
    } else if(!strcmp(name,"free") || !strncmp(name,"pthread_rwlock_",15) || !strncmp(name,"pthread_mutex_",14)) {
        /* Each generator owns independent state; no shared guest lock exists. */
    } else if(!strcmp(name,"memcpy") || !strcmp(name,"memmove")) {
        if(c>KG_ARENA)return 0;
        p=kg_memory(r,a,(size_t)c,2);q=kg_memory(r,b,(size_t)c,1);
        if(!p || !q)return 0;
        memmove(p,q,(size_t)c);kg_shadow_written(&r->state,a,(size_t)c);value=a;
    } else if(!strcmp(name,"memset")) {
        if(c>KG_ARENA)return 0;
        p=kg_memory(r,a,(size_t)c,2);if(!p)return 0;
        memset(p,(unsigned char)b,(size_t)c);kg_shadow_written(&r->state,a,(size_t)c);value=a;
    } else if(!strcmp(name,"strlen")) {
        for(n=0;n<KG_ARENA;++n){uint64_t v;if(!kg_read(r,a+n,1,&v))return 0;if(!v)break;}
        if(n==KG_ARENA)return 0;
        value=n;
    } else if(!strcmp(name,"__system_property_get")) {
        if(!kg_write(r,b,1,0))return 0;
    } else if(!strcmp(name,"gettimeofday")) {
        int64_t sec,usec;
        if(!kg_time(r,&sec,&usec) || !kg_write(r,a,8,(uint64_t)sec) || !kg_write(r,a+8,8,(uint64_t)usec))return 0;
    } else if(!strcmp(name,"arc4random")) {
        unsigned char bytes[4];unsigned j;
        if(!kg_entropy(r,bytes,4))return 0;
        for(j=0;j<4;++j)value|=(uint64_t)bytes[j]<<(8*j);
    } else if(!strcmp(name,"arc4random_buf")) {
        if(b>KG_ARENA)return 0;
        p=kg_memory(r,a,(size_t)b,2);if(!p || !kg_entropy(r,p,(size_t)b))return 0;
        kg_shadow_written(&r->state,a,(size_t)b);
    } else if(!strcmp(name,"dlopen"))value=0x1234;
    else if(!strcmp(name,"dlsym")) {
        char symbol[512];size_t j;
        if(!kg_string(r,b,symbol,sizeof symbol))return 0;
        for(j=0;j<sizeof kg_source_exports/sizeof kg_source_exports[0];++j)
            if(!strcmp(symbol,kg_source_exports[j].name)){value=kg_source_exports[j].address;break;}
        if(!value)return 0;
    } else return 0;
    return kg_return(r,value);
}
static int kg_execute(kg_runtime *r,uint64_t entry,const uint64_t *args,size_t count,const uint64_t *stack_args,size_t stack_count) {
    static const unsigned regs[]={5,4,3,2,8,9};
    wrapper_kg_payload_state *s=&r->state.cpu;
    size_t j;
    s->gpr[7]=KG_STACK+0x80000;s->pc=entry;
    if(!kg_write(r,s->gpr[7],8,KG_STOP))return 0;
    for(j=0;j<count && j<6;++j)s->gpr[regs[j]]=args[j];
    for(j=0;j<stack_count;++j)if(!kg_write(r,s->gpr[7]+8*(j+1),8,stack_args[j]))return 0;
    for(;;){
        int status;
        if(s->pc==KG_STOP){
            if(r->worker_active)return 0; /* Unobserved early worker return. */
            if(r->worker_pending){
                r->parent_state=r->state;r->worker_pending=0;r->worker_active=1;
                s->pc=r->worker_entry;s->gpr[7]=KG_STACK+0xf0000;s->gpr[5]=0;
                if(!kg_write(r,s->gpr[7],8,KG_STOP))return 0;
                continue;
            }
            return 1;
        }
        if(s->pc==KG_ONCE){
            if(!r->once_count)return 0;
            --r->once_count;s->gpr[7]=r->once_sp[r->once_count]+8;s->gpr[0]=0;s->pc=r->once_ret[r->once_count];continue;
        }
        if(s->pc>=UINT64_C(0x800000) && !(s->pc&15)) {
            uint64_t id=(s->pc-UINT64_C(0x800000))/16;
            if(id<sizeof kg_source_service_names/sizeof kg_source_service_names[0]) {
                if(!kg_service(r,kg_source_service_names[id]))return 0;
                continue;
            }
        }
        if(r->result->source_steps>=UINT64_C(400000000))return 0;
        status=wrapper_kg_native_run(KG_CORE,&r->state,r->regions,KG_REGIONS,400000000-(size_t)r->result->source_steps,&r->bindings);
        r->result->source_steps+=s->steps;
        if(status==WRAPPER_KG_NATIVE_CLOCK){
            uint64_t clock=kg_clock(r);
            s->gpr[0]=(uint32_t)clock;s->gpr[3]=clock>>32;s->pc+=2;++r->result->source_steps;continue;
        }
        if(status!=WRAPPER_KG_GRAPH_YIELD)return 0;
        if(s->pc==KG_STOP || s->pc==KG_ONCE || (s->pc>=UINT64_C(0x800000) && s->pc<UINT64_C(0x900000)))continue;
        return 0;
    }
}
static int kg_generate(const wrapper_kg_spc_request *request,unsigned char *output,size_t capacity,wrapper_kg_spc_result *result,kg_runtime **retained,const uint32_t *format_version) {
    kg_runtime *r;size_t j;int success=0;uint64_t setup_args[2],args[6],stack_args[2],length,pointer;
    if(!result)return -1;
    memset(result,0,sizeof *result);
    if(!request || !output || !request->certificate || !request->content || !request->device_seed ||
       !request->certificate_size || request->certificate_size>4096 || !request->content_size || request->content_size>4096 ||
       !request->device_seed_size || request->device_seed_size>4096)return -1;
    r=(kg_runtime *)calloc(1,sizeof *r);if(!r)return -2;
    r->request_copy=*request;r->request=&r->request_copy;r->result=result;r->allocated=0x10000;r->state.cpu.flags=2;
    for(j=0;j<KG_IMAGES;++j){
        const struct kg_image *image=kg_images+j;
        r->owned[j]=(unsigned char *)malloc(image->size);if(!r->owned[j])goto done;
        memcpy(r->owned[j],image->data,image->size);
        r->regions[j]=(wrapper_kg_payload_region){image->address,image->size,r->owned[j],image->permissions};
    }
    for(j=KG_IMAGES;j<KG_REGIONS;++j){
        r->owned[j]=(unsigned char *)calloc(1,KG_ARENA);if(!r->owned[j])goto done;
        r->regions[j]=(wrapper_kg_payload_region){j==KG_IMAGES?KG_STACK:KG_HEAP,KG_ARENA,r->owned[j],3};
    }
    for(j=0;j<sizeof kg_source_service_names/sizeof kg_source_service_names[0];++j){
        if(!strcmp(kg_source_service_names[j],"malloc"))r->bindings.malloc_entry=UINT64_C(0x800000)+j*16;
        if(!strcmp(kg_source_service_names[j],"free"))r->bindings.free_entry=UINT64_C(0x800000)+j*16;
    }
    memcpy(kg_memory(r,KG_HEAP,request->certificate_size,2),request->certificate,request->certificate_size);
    memcpy(kg_memory(r,KG_HEAP+0x1000,request->content_size,2),request->content,request->content_size);
    memcpy(kg_memory(r,KG_HEAP+0x4000,request->device_seed_size,2),request->device_seed,request->device_seed_size);
    setup_args[0]=KG_HEAP+0x4000;setup_args[1]=request->device_seed_size;
    if(!kg_execute(r,0x3dcb80,setup_args,2,0,0) || (uint32_t)r->state.cpu.gpr[0])goto done;
    args[0]=request->account;
    if(format_version){
        uint64_t movie_args[5]={KG_HEAP,request->certificate_size,KG_HEAP+0x5000,1,KG_HEAP+0x5010};
        if(!kg_write(r,KG_HEAP+0x5000,4,*format_version) || !kg_execute(r,0x3ded50,movie_args,5,0,0))goto done;
        result->status=(uint32_t)r->state.cpu.gpr[0];
        if(result->status || !kg_read(r,KG_HEAP+0x5010,8,args) || !args[0])goto done;
    }
    args[1]=KG_HEAP;args[2]=request->certificate_size;
    args[3]=KG_HEAP+0x1000;args[4]=request->content_size;args[5]=KG_HEAP+0x2020;
    stack_args[0]=KG_HEAP+0x2000;stack_args[1]=KG_HEAP+0x2010;
    if(!kg_execute(r,0x3d3b90,args,6,stack_args,2))goto done;
    result->status=(uint32_t)r->state.cpu.gpr[0];
    if(result->status || !kg_read(r,KG_HEAP+0x2000,4,&length) || !kg_read(r,KG_HEAP+0x2020,8,&pointer) || !length || length>capacity)goto done;
    if(format_version){
        if(!kg_read(r,KG_HEAP+0x2010,8,args) || !args[0] || !kg_execute(r,0x3e2490,args,1,0,0))goto done;
        result->status=(uint32_t)r->state.cpu.gpr[0];if(result->status)goto done;
    }
    {unsigned char *p=kg_memory(r,pointer,(size_t)length,1);if(!p)goto done;memcpy(output,p,(size_t)length);result->output_size=(size_t)length;}
    success=1;
done:
    result->pc=r->state.cpu.pc;result->fault_address=r->state.cpu.fault_address;result->fault_size=r->state.cpu.fault_size;
    if(success && retained){*retained=r;return 0;}
    wrapper_kg_spc_session_free(r);return success?0:-3;
}
static void kg_clear(void *memory,size_t size) {
    volatile unsigned char *p=(volatile unsigned char *)memory;
    while(size--)*p++=0;
}
void wrapper_kg_spc_session_free(wrapper_kg_spc_session *r) {
    size_t j;
    if(!r)return;
    for(j=0;j<KG_REGIONS;++j)if(r->owned[j]){kg_clear(r->owned[j],r->regions[j].size);free(r->owned[j]);}
    kg_clear(r,sizeof *r);free(r);
}
int wrapper_kg_spc_generate(const wrapper_kg_spc_request *request,unsigned char *output,size_t capacity,wrapper_kg_spc_result *result) {
    return kg_generate(request,output,capacity,result,0,0);
}
int wrapper_kg_spc_generate_session(const wrapper_kg_spc_request *request,unsigned char *output,size_t capacity,wrapper_kg_spc_result *result,wrapper_kg_spc_session **session) {
    if(!session)return -1;
    *session=0;return kg_generate(request,output,capacity,result,session,0);
}
int wrapper_kg_spc_generate_fps_session(const wrapper_kg_spc_request *request,uint32_t format_version,unsigned char *output,size_t capacity,wrapper_kg_spc_result *result,wrapper_kg_spc_session **session) {
    if(!session)return -1;
    *session=0;return kg_generate(request,output,capacity,result,session,&format_version);
}
int wrapper_kg_spc_session_exchange(const wrapper_kg_spc_session *r,unsigned char output[16]) {
    const unsigned char *p;
    if(!r || !output)return -1;
    p=translate(r->regions,KG_REGIONS,KG_HEAP+0x2010,16,1);
    if(!p)return -1;
    memcpy(output,p,16);return 0;
}
static int kg_process_ckc(kg_runtime *r,const unsigned char *ckc,size_t size,int context,wrapper_kg_spc_result *result) {
    uint64_t handle,args[3]={1,context?WRAPPER_KG_CKC_CONTEXT_TOKEN:WRAPPER_KG_CKC_PERSISTENT_TOKEN,KG_HEAP+0x7000};
    unsigned char *packet;
    int ok;
    if(!result)return -1;
    memset(result,0,sizeof *result);
    if(!r || !ckc || !size || size>4096)return -1;
    /* Wake/expiry handling beyond the first observed five-second sleep is not
     * reconstructed yet. Refuse reuse once that deadline is reached. */
    if(r->worker_sleeping){uint64_t now=kg_steady();if(!now || now>=r->worker_wake)return -5;}
    r->result=result;
    if(!kg_read(r,KG_HEAP+0x2010,8,&handle) || !handle)return -1;
    memcpy(kg_memory(r,KG_HEAP+0x6000,size,2),ckc,size);
    if(!kg_write(r,KG_HEAP+0x3000,8,0) || !kg_write(r,KG_HEAP+0x3010,4,0))return -3;
    packet=kg_memory(r,KG_HEAP+0x7000,WRAPPER_KG_CKC_PACKET_SIZE,3);
    if(!packet)return -3;
    ok=context?wrapper_kg_ckc_context_packet(packet,WRAPPER_KG_CKC_PACKET_SIZE,handle,KG_HEAP+0x6000,(uint32_t)size,KG_HEAP+0x3000):
        wrapper_kg_ckc_persistent_packet(packet,WRAPPER_KG_CKC_PACKET_SIZE,handle,KG_HEAP+0x6000,(uint32_t)size,KG_HEAP+0x3000,KG_HEAP+0x3010);
    if(ok)return -3;
    ok=kg_execute(r,KG_CORE+0x526ac0,args,3,0,0);
    result->pc=r->state.cpu.pc;result->fault_address=r->state.cpu.fault_address;result->fault_size=r->state.cpu.fault_size;
    if(r->worker_sleeping){uint64_t now=kg_steady();if(!now || now>=r->worker_wake)return -5;}
    if(!ok || (uint32_t)r->state.cpu.gpr[0] || wrapper_kg_ckc_packet_status(packet,WRAPPER_KG_CKC_PACKET_SIZE,&result->status))return -3;
    return result->status?-4:0;
}
int wrapper_kg_spc_session_ckc_persistent(wrapper_kg_spc_session *r,const unsigned char *ckc,size_t size,unsigned char *output,size_t capacity,wrapper_kg_spc_result *result) {
    uint64_t pointer,length;unsigned char *p;int status;
    if(!output || !capacity)return -1;
    status=kg_process_ckc(r,ckc,size,0,result);if(status)return status;
    if(!kg_read(r,KG_HEAP+0x3000,8,&pointer) || !kg_read(r,KG_HEAP+0x3010,4,&length) || !length || length>capacity)return -3;
    p=kg_memory(r,pointer,(size_t)length,1);if(!p)return -3;
    memcpy(output,p,(size_t)length);result->output_size=(size_t)length;return 0;
}
int wrapper_kg_spc_session_ckc_context(wrapper_kg_spc_session *r,const unsigned char *ckc,size_t size,uint64_t *context,wrapper_kg_spc_result *result) {
    uint64_t value;int status;
    if(!context)return -1;
    status=kg_process_ckc(r,ckc,size,1,result);if(status)return status;
    if(!kg_read(r,KG_HEAP+0x3000,8,&value) || !value)return -3;
    r->context_handle=value;r->context_finalized=0;
    *context=value;return 0;
}
static int kg_context_ready(kg_runtime *r,uint64_t context,wrapper_kg_spc_result *result) {
    if(!result)return -1;
    memset(result,0,sizeof *result);
    if(!r || !context || context!=r->context_handle)return -1;
    if(r->worker_sleeping){uint64_t now=kg_steady();if(!now || now>=r->worker_wake)return -5;}
    r->result=result;
    return 0;
}
static int kg_context_dispatch(kg_runtime *r,uint32_t token,unsigned char *packet,wrapper_kg_spc_result *result) {
    uint64_t args[3]={1,token,KG_HEAP+0x7000};
    int ok=kg_execute(r,KG_CORE+0x526ac0,args,3,0,0);
    result->pc=r->state.cpu.pc;result->fault_address=r->state.cpu.fault_address;result->fault_size=r->state.cpu.fault_size;
    if(r->worker_sleeping){uint64_t now=kg_steady();if(!now || now>=r->worker_wake)return -5;}
    if(!ok || (uint32_t)r->state.cpu.gpr[0] || wrapper_kg_ckc_packet_status(packet,WRAPPER_KG_CKC_PACKET_SIZE,&result->status))return -3;
    return result->status?-4:0;
}
int wrapper_kg_spc_session_context_finalize(wrapper_kg_spc_session *r,uint64_t context,wrapper_kg_spc_result *result) {
    unsigned char *packet;
    int status=kg_context_ready(r,context,result);
    if(status)return status;
    packet=kg_memory(r,KG_HEAP+0x7000,WRAPPER_KG_CKC_PACKET_SIZE,3);
    if(!packet)return -3;
    if(wrapper_kg_context_finalize_packet(packet,WRAPPER_KG_CKC_PACKET_SIZE,context))return -3;
    r->context_finalized=0;
    status=kg_context_dispatch(r,WRAPPER_KG_CONTEXT_FINALIZE_TOKEN,packet,result);
    if(!status)r->context_finalized=1;
    return status;
}
int wrapper_kg_spc_session_context_decrypt(wrapper_kg_spc_session *r,uint64_t context,uint32_t mode,
    const unsigned char *input,size_t size,unsigned char *output,size_t capacity,wrapper_kg_spc_result *result) {
    unsigned char *packet,*in,*out;
    int status;
    if(!result)return -1;
    memset(result,0,sizeof *result);
    if(!input || !output || !size || size>WRAPPER_KG_CONTEXT_DECRYPT_MAX_SIZE || capacity<size)return -1;
    status=kg_context_ready(r,context,result);
    if(status)return status;
    if(!r->context_finalized)return -1;
    packet=kg_memory(r,KG_HEAP+0x7000,WRAPPER_KG_CKC_PACKET_SIZE,3);
    in=kg_memory(r,KG_HEAP+0x8000,size,3);out=kg_memory(r,KG_HEAP+0x9000,size,3);
    if(!packet || !in || !out)return -3;
    if(wrapper_kg_context_decrypt_packet(packet,WRAPPER_KG_CKC_PACKET_SIZE,context,mode,KG_HEAP+0x8000,KG_HEAP+0x9000,(uint32_t)size))return -3;
    memcpy(in,input,size);memset(out,0,size);
    status=kg_context_dispatch(r,WRAPPER_KG_CONTEXT_DECRYPT_TOKEN,packet,result);
    if(!status){memcpy(output,out,size);result->output_size=size;}
    kg_clear(in,size);kg_clear(out,size);
    return status;
}
