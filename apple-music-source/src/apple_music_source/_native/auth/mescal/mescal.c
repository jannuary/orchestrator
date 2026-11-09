#define _POSIX_C_SOURCE 200809L
#include "mescal.h"
#include "mescal_internal.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <fcntl.h>
#include <unistd.h>
#include "generated/bounds.inc"
#include "generated/images.inc"
#define STACK UINT64_C(0x1000000)
#define HEAP UINT64_C(0x2000000)
#define RETURN UINT64_C(0x900000)
#define HEAP_BYTES ((size_t)0x2000000)
#define ARRAY_SIZE(a) (sizeof(a)/sizeof((a)[0]))
typedef void (*mescal_trace)(uint64_t,const uint64_t*,uint64_t,const void*,void*);
struct mescal_session {
    mescal_trace trace;void *trace_user;
    wrapper_kg_native_state state;
    wrapper_kg_payload_region regions[16];size_t region_count;
    uint64_t heap,context,once_pc[32],once_sp[32];size_t once_count;
    uint64_t device;
    mescal_options options;
    mescal_result diagnostic;
    int hardware_mode;
    unsigned char hardware_serial[92],hardware_mac[6];
};
int mescal_native_lookup(uint64_t a,unsigned n,uint64_t *v){(void)a;(void)n;(void)v;return 0;}
int mescal_native_read(const wrapper_kg_payload_region *r,size_t n,uint64_t a,unsigned width,uint64_t *out){
 const unsigned char *p=translate(r,n,a,width,1);uint64_t v=0;unsigned i;if(!p||!width||width>8)return 0;
 for(i=0;i<width;++i)v|=(uint64_t)p[i]<<(i*8);*out=v;return 1;
}
static unsigned char *memory(mescal_session *s,uint64_t a,size_t n,unsigned p){return translate(s->regions,s->region_count,a,n,p);}
static int put(mescal_session *s,uint64_t a,unsigned n,uint64_t v){unsigned char*p=memory(s,a,n,2);unsigned i;if(!p)return 0;for(i=0;i<n;++i)p[i]=(unsigned char)(v>>(8*i));return 1;}
static uint64_t get(mescal_session*s,uint64_t a,unsigned n){uint64_t v=0;if(!mescal_native_read(s->regions,s->region_count,a,n,&v)){s->state.cpu.fault_address=a;s->state.cpu.fault_size=n;}return v;}
static uint64_t allocate(mescal_session*s,size_t n){uint64_t p=s->heap;if(n>HEAP_BYTES||p<HEAP||p>HEAP+HEAP_BYTES-n)return 0;s->heap=(p+n+15)&~UINT64_C(15);return p;}
static const char*cstring(mescal_session*s,uint64_t a){const char*p=(const char*)memory(s,a,1,1);size_t i;if(!p)return NULL;for(i=0;i<4096;++i){const unsigned char*q=memory(s,a+i,1,1);if(!q)return NULL;if(!*q)return p;}return NULL;}
static int entropy(mescal_session*s,unsigned char*p,size_t n){
 int fd;size_t done=0;if(s->options.entropy)return s->options.entropy(s->options.user,p,n);
 fd=open("/dev/urandom",O_RDONLY);if(fd<0)return -1;while(done<n){ssize_t got=read(fd,p+done,n-done);if(got<=0){close(fd);return -1;}done+=(size_t)got;}close(fd);return 0;
}
static uint64_t clock_value(mescal_session*s){struct timespec t;if(s->options.clock)return s->options.clock(s->options.user);if(clock_gettime(CLOCK_MONOTONIC,&t))return 0;return (uint64_t)t.tv_sec*UINT64_C(1000000000)+(uint64_t)t.tv_nsec;}
static int wall_time(mescal_session*s,int64_t *sec,int64_t *usec){struct timeval t;if(s->options.time)return s->options.time(s->options.user,sec,usec);if(gettimeofday(&t,NULL))return -1;*sec=t.tv_sec;*usec=t.tv_usec;return 0;}
static int external(mescal_session*s,size_t index){
 wrapper_kg_payload_state*c=&s->state.cpu;uint64_t a[6]={c->gpr[5],c->gpr[4],c->gpr[3],c->gpr[2],c->gpr[8],c->gpr[9]},value=0;const char *name=mescal_imports[index];size_t i;unsigned char*p,*q;
 if(!strcmp(name,"malloc")||!strcmp(name,"calloc")){
  size_t n=(size_t)a[0];if(!strcmp(name,"calloc")){if(a[1]&&a[0]>HEAP_BYTES/a[1])return 0;n=(size_t)(a[0]*a[1]);}value=allocate(s,n);if(!value)return 0;
 }else if(!strcmp(name,"free")||!strncmp(name,"pthread_mutex_",14)||!strncmp(name,"pthread_rwlock_",15)){
 }else if(!strcmp(name,"memcpy")||!strcmp(name,"memmove")){
  p=memory(s,a[0],(size_t)a[2],2);q=memory(s,a[1],(size_t)a[2],1);if(!p||!q)return 0;memmove(p,q,(size_t)a[2]);value=a[0];
 }else if(!strcmp(name,"memset")){
  p=memory(s,a[0],(size_t)a[2],2);if(!p)return 0;memset(p,(unsigned char)a[1],(size_t)a[2]);value=a[0];
 }else if(!strcmp(name,"strlen")){
  const char*text=cstring(s,a[0]);if(!text)return 0;value=strlen(text);
 }else if(!strcmp(name,"arc4random")){
  uint32_t v;if(entropy(s,(unsigned char*)&v,4))return 0;value=v;
 }else if(!strcmp(name,"arc4random_buf")){
  p=memory(s,a[0],(size_t)a[1],2);if(!p||entropy(s,p,(size_t)a[1]))return 0;
 }else if(!strcmp(name,"gettimeofday")||!strcmp(name,"clock_gettime")){
  int64_t sec,usec;if(wall_time(s,&sec,&usec))return 0;uint64_t ptr=!strcmp(name,"gettimeofday")?a[0]:a[1];if(!put(s,ptr,8,(uint64_t)sec)||!put(s,ptr+8,8,(uint64_t)(!strcmp(name,"gettimeofday")?usec:usec*1000)))return 0;
 }else if(!strcmp(name,"__system_property_get")){
  const char *key=cstring(s,a[0]);size_t n=0;
  if(s->hardware_mode&&key&&(!strcmp(key,"ril.serialnumber")||!strcmp(key,"ro.serialno")||!strcmp(key,"ro.boot.serialno")))n=strlen((const char*)s->hardware_serial);
  p=memory(s,a[1],n+1,2);if(!p)return 0;
  if(n)memcpy(p,s->hardware_serial,n);p[n]=0;value=n;
 }else if(s->hardware_mode&&!strcmp(name,"socket")){
  if(a[0]!=2||a[1]!=2||a[2]!=0)return 0;value=10;
 }else if(s->hardware_mode&&!strcmp(name,"ioctl")){
  if(a[0]!=10)return 0;
  if((uint32_t)a[1]==0x8912){
   uint64_t capacity=get(s,a[2],4),destination=get(s,a[2]+8,8);size_t n=capacity<80?(size_t)capacity:80;
   unsigned char records[80]={0};memcpy(records,"lo",2);memcpy(records+40,"eth0",4);records[16]=2;records[56]=2;
   if(destination&&n){p=memory(s,destination,n,2);if(!p)return 0;memcpy(p,records,n);}
   if(!put(s,a[2],4,n))return 0;
  }else if((uint32_t)a[1]==0x8913||(uint32_t)a[1]==0x8927){
   const unsigned char *name=memory(s,a[2],16,1);int loopback;
   if(!name||(!memchr(name,0,16)))return 0;
   loopback=!strcmp((const char*)name,"lo");
   if(!loopback&&strcmp((const char*)name,"eth0"))return 0;
   if((uint32_t)a[1]==0x8913){if(!put(s,a[2]+16,2,loopback?0x49:0x1043))return 0;}
   else{p=memory(s,a[2]+16,16,2);if(!p)return 0;memset(p,0,16);p[0]=1;if(!loopback)memcpy(p+2,s->hardware_mac,6);}
  }else return 0;
 }else if(s->hardware_mode&&!strcmp(name,"close")){
  if(a[0]!=10)return 0;
 }else if(!strcmp(name,"dlopen")){
  const char*path=cstring(s,a[0]);if(!path||strcmp(path,"libCoreFP.so"))return 0;value=0x1234;
 }else if(!strcmp(name,"dlsym")){
  const char*symbol=cstring(s,a[1]);if(!symbol)return 0;
  for(i=0;i<ARRAY_SIZE(mescal_exports);++i)if(!strcmp(symbol,mescal_exports[i].name)){value=mescal_exports[i].address;break;}
  if(!value)return 0;
 }else if(!strcmp(name,"pthread_once")){
  for(i=0;i<s->once_count;++i)if(s->once_pc[i]==c->pc&&s->once_sp[i]==c->gpr[7]){s->once_pc[i]=s->once_pc[--s->once_count];s->once_sp[i]=s->once_sp[s->once_count];goto complete;}
  if(get(s,a[0],4)==0){
   if(s->once_count>=ARRAY_SIZE(s->once_pc)||!put(s,a[0],4,1))return 0;
   s->once_pc[s->once_count]=c->pc;s->once_sp[s->once_count++]=c->gpr[7];c->gpr[7]-=8;if(!put(s,c->gpr[7],8,c->pc))return 0;c->pc=a[1];return 1;
  }
 }else {s->diagnostic.status=UINT32_C(0xffff0000)+(uint32_t)index;return 0;}
complete:
 c->gpr[0]=value;c->pc=get(s,c->gpr[7],8);c->gpr[7]+=8;return !c->fault_size;
}
static int execute(mescal_session*s,uint64_t entry,const uint64_t *args,size_t argc,mescal_result*out){
 wrapper_kg_payload_state*c=&s->state.cpu;static const unsigned regs[]={5,4,3,2,8,9};uint64_t total=0;size_t i;int result=0;
 memset(&s->diagnostic,0,sizeof(s->diagnostic));c->fault_size=0;c->fault_address=0;c->gpr[7]=STACK+0x80000;c->pc=entry;
 if(!put(s,c->gpr[7],8,RETURN))return 0;
 for(i=0;i<argc;++i)if(i<6)c->gpr[regs[i]]=args[i];else if(!put(s,c->gpr[7]+8*(i-5),8,args[i]))return 0;
 while(total<UINT64_C(500000000)){
  size_t lo=0,hi=ARRAY_SIZE(mescal_bounds);uint64_t pc=c->pc;
  if(pc==RETURN){result=1;break;}
  if(s->trace)s->trace(pc,c->gpr,c->flags,s->state.xmm,s->trace_user);
  if(pc>=0x800000&&pc<0x800000+ARRAY_SIZE(mescal_imports)*16&&(pc&15)==0){if(!external(s,(size_t)((pc-0x800000)/16)))break;++total;continue;}
  while(lo<hi){size_t mid=lo+(hi-lo)/2;if(mescal_bounds[mid].begin<=pc)lo=mid+1;else hi=mid;}
  if(!lo||pc>=mescal_bounds[lo-1].end){s->diagnostic.status=UINT32_C(0xfffe0000);break;}
  const struct mescal_bound*b=mescal_bounds+lo-1;int rc=mescal_groups[b->group](b->index,b->bias,&s->state,s->regions,s->region_count,500000000-total);total+=c->steps;
  if(rc==WRAPPER_KG_NATIVE_CLOCK){uint64_t v=clock_value(s);c->gpr[0]=(uint32_t)v;c->gpr[3]=(uint32_t)(v>>32);c->pc+=2;++total;continue;}
  if(rc!=WRAPPER_KG_PAYLOAD_OK){s->diagnostic.status=(uint32_t)rc;break;}
 }
 s->diagnostic.pc=c->pc;s->diagnostic.fault_address=c->fault_address;s->diagnostic.fault_size=c->fault_size;s->diagnostic.steps=total;
 if(result)s->diagnostic.status=(uint32_t)c->gpr[0];if(out)*out=s->diagnostic;return result;
}
static int region(mescal_session*s,uint64_t address,size_t size,unsigned perms,const unsigned char*initial){
 if(s->region_count>=ARRAY_SIZE(s->regions))return 0;unsigned char*p=calloc(size?size:1,1);if(!p)return 0;if(initial)memcpy(p,initial,size);s->regions[s->region_count++]=(wrapper_kg_payload_region){address,size,p,perms};return 1;
}
static void wipe(void*p,size_t n){volatile unsigned char*q=p;while(n--)*q++=0;}
void wrapper_mescal_free(mescal_session*s){size_t i;if(!s)return;for(i=0;i<s->region_count;++i){if(s->regions[i].permissions&2)wipe(s->regions[i].data,s->regions[i].size);free(s->regions[i].data);}wipe(s,sizeof(*s));free(s);}
static mescal_session *new_runtime(const mescal_options*options,mescal_trace trace,void*user){
 size_t i;mescal_session*s=calloc(1,sizeof(*s));if(!s)return NULL;s->trace=trace;s->trace_user=user;if(options)s->options=*options;s->heap=HEAP+0x100000;s->device=HEAP+0x20000;
 for(i=0;i<ARRAY_SIZE(mescal_images);++i){const struct mescal_image*im=mescal_images+i;if(!region(s,im->address,im->size,im->permissions,im->data))goto fail;}
 if(!region(s,STACK,0x200000,3,NULL)||!region(s,HEAP,HEAP_BYTES,3,NULL))goto fail;
 return s;
fail:wrapper_mescal_free(s);return NULL;
}
static int create_with_trace(const unsigned char*device,size_t n,const mescal_options*options,mescal_session**out,mescal_result*result,mescal_trace trace,void*user){
 uint64_t args[2];if(result)memset(result,0,sizeof(*result));if(!device||!n||n>20||!out)return -1;*out=NULL;
 mescal_session*s=new_runtime(options,trace,user);if(!s)return -2;
 if(!put(s,s->device,4,n))goto fail;memcpy(memory(s,s->device+4,n,2),device,n);args[0]=HEAP+0x30000;args[1]=s->device;
 if(!execute(s,0x1eb0f0,args,2,result)||s->diagnostic.status)goto fail;s->context=get(s,args[0],8);if(!s->context)goto fail;*out=s;return 0;
fail:wrapper_mescal_free(s);return -2;
}
int wrapper_mescal_guid_fields(const unsigned char*android,size_t android_n,const unsigned char*serial,size_t n,const unsigned char*mac,
    unsigned char*out,size_t capacity,const mescal_options*options,mescal_result*result){
 mescal_session*s;int status=-2;unsigned char*p;uint64_t args[2]={HEAP+0x70000,2};
 if(result)memset(result,0,sizeof(*result));
 if(!android||!android_n||android_n>4096||(n&&!serial)||n>91||!mac||!out||capacity<56||(n&&memchr(serial,0,n)))return -1;
 s=new_runtime(options,NULL,NULL);if(!s)return -2;s->hardware_mode=1;
 if(n)memcpy(s->hardware_serial,serial,n);memcpy(s->hardware_mac,mac,6);
 p=memory(s,HEAP+0x72000,android_n,2);if(!p)goto done;memcpy(p,android,android_n);
 {uint64_t config[2]={HEAP+0x72000,android_n};if(!execute(s,0x205190,config,2,result)||s->diagnostic.status)goto done;}
 if(!put(s,args[0]+48,4,1))goto done;
 if(!execute(s,0x203f10,args,2,result)||s->diagnostic.status)goto done;
 p=memory(s,args[0],56,1);if(!p||get(s,args[0]+24,4)>23||get(s,args[0]+52,4)>23)goto done;
 memcpy(out,p,56);status=0;
done:wrapper_mescal_free(s);return status;
}
int wrapper_mescal_create(const unsigned char*d,size_t n,const mescal_options*o,mescal_session**s,mescal_result*r){return create_with_trace(d,n,o,s,r,NULL,NULL);}
/* Explicit offline verifier hook; never enabled by the normal entry point. */
MESCAL_API int wrapper_mescal_create_trace(const unsigned char*d,size_t n,const mescal_options*o,mescal_session**s,mescal_result*r,mescal_trace t,void*u){return create_with_trace(d,n,o,s,r,t,u);}
static int operation_call(mescal_session*s,unsigned mode,int exchange,const unsigned char*data,size_t n,unsigned char*out,size_t capacity,size_t*size,unsigned*phase,mescal_result*result){
 uint64_t args[8],input=HEAP+0x50000,pointer,length;size_t count;if(size)*size=0;if(result)memset(result,0,sizeof(*result));if(!s||!data||!n||n>0x80000||!out||!size||(exchange&&!phase))return -1;
 memcpy(memory(s,input,n,2),data,n);put(s,HEAP+0x30000,8,0);put(s,HEAP+0x30010,4,0);put(s,HEAP+0x30020,1,255);
 if(exchange){uint64_t a[]={mode,s->device,s->context,input,n,HEAP+0x30000,HEAP+0x30010,HEAP+0x30020};memcpy(args,a,sizeof(a));count=8;}
 else {uint64_t a[]={s->context,input,n,HEAP+0x30000,HEAP+0x30010};memcpy(args,a,sizeof(a));count=5;}
 if(!execute(s,exchange?0x1e28e0:0x1eed30,args,count,result)||s->diagnostic.status)return -2;
 pointer=get(s,HEAP+0x30000,8);length=get(s,HEAP+0x30010,4);if(length>capacity||(!pointer&&length)||!memory(s,pointer,(size_t)length,1))return -3;
 if(length)memcpy(out,memory(s,pointer,(size_t)length,1),(size_t)length);*size=(size_t)length;if(exchange)*phase=(unsigned)get(s,HEAP+0x30020,1);return 0;
}
int wrapper_mescal_exchange(mescal_session*s,unsigned mode,const unsigned char*data,size_t n,unsigned char*out,size_t capacity,size_t*size,unsigned*phase,mescal_result*result){return operation_call(s,mode,1,data,n,out,capacity,size,phase,result);}
int wrapper_mescal_sign(mescal_session*s,const unsigned char*data,size_t n,unsigned char*out,size_t capacity,size_t*size,mescal_result*result){return operation_call(s,0,0,data,n,out,capacity,size,NULL,result);}
