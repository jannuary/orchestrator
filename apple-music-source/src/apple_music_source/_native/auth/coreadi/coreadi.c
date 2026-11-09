#include "coreadi.h"
#include "internal.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <sys/time.h>
#include "generated/bounds.inc"
#include "generated/images.inc"
#include "generated/adi_substitutions.inc"
#define STACK UINT64_C(0x1000000)
#define HEAP UINT64_C(0x2000000)
#define RETURN UINT64_C(0x900000)
#define HEAP_SIZE 0x2000000
#define PROVISION_SIZE_LIMIT 0x100000
#define ANDROID_ID_SIZE_LIMIT 4096
#define SPIM_SIZE_LIMIT 0x100000
#define CPIM_POINTER_SLOT (HEAP+0x1000)
#define CPIM_SIZE_SLOT (HEAP+0x1010)
#define SESSION_SLOT (HEAP+0x1020)
#define RUNTIME_REGION_CAPACITY 64
#define ADI_SUBSTITUTION_BYTES 1024
#define ADI_SUBSTITUTION_WORD_BYTES 4
#define GF256_REDUCTION 0x1b
#define GF256_INVERSE_EXPONENT 254
struct runtime {
 wrapper_kg_native_state state;wrapper_kg_payload_region regions[RUNTIME_REGION_CAPACITY];size_t count;
 const wrapper_adi_request *request;uint64_t heap,steps,ticks;
 size_t position;int fd;int failure;
 void (*trace)(uint64_t,const uint64_t *,uint64_t,const kg_vec *,void *);void *trace_user;
};
static uint8_t adi_linear_byte(const uint8_t columns[8],uint8_t value){uint8_t result=0;unsigned bit;for(bit=0;bit<8;++bit)if(value&(1u<<bit))result^=columns[bit];return result;}
static uint32_t adi_linear_word(const uint32_t columns[8],uint8_t value){uint32_t result=0;unsigned bit;for(bit=0;bit<8;++bit)if(value&(1u<<bit))result^=columns[bit];return result;}
static uint8_t adi_gf256_multiply(uint8_t left,uint8_t right){uint8_t result=0;while(right){if(right&1)result^=left;if(left&0x80)left=(uint8_t)((left<<1)^GF256_REDUCTION);else left=(uint8_t)(left<<1);right>>=1;}return result;}
static uint8_t adi_gf256_inverse(uint8_t value){uint8_t result=1,factor=value;unsigned exponent=GF256_INVERSE_EXPONENT;if(!value)return 0;while(exponent){if(exponent&1)result=adi_gf256_multiply(result,factor);factor=adi_gf256_multiply(factor,factor);exponent>>=1;}return result;}
static uint32_t adi_substitution_word(const struct adi_substitution *table,uint8_t index){uint8_t input=adi_linear_byte(table->input_columns,(uint8_t)(index^table->input_shift));return adi_linear_word(table->output_columns,adi_gf256_inverse(input))^table->output_xor;}
static int adi_substitution_byte(uint64_t address,uint8_t *value){size_t table_index;for(table_index=0;table_index<sizeof adi_substitutions/sizeof adi_substitutions[0];++table_index){const struct adi_substitution *table=adi_substitutions+table_index;uint64_t offset;if(address<table->address)continue;offset=address-table->address;if(offset>=ADI_SUBSTITUTION_BYTES)continue;*value=(uint8_t)(adi_substitution_word(table,(uint8_t)(offset/ADI_SUBSTITUTION_WORD_BYTES))>>((offset%ADI_SUBSTITUTION_WORD_BYTES)*8));return 1;}return 0;}
int adi_native_read(const wrapper_kg_payload_region *regions,size_t count,uint64_t address,unsigned width,uint64_t *value){
 uint64_t result=0;unsigned byte_index;if(!value||!width||width>8||address>UINT64_MAX-(width-1))return 0;
 for(byte_index=0;byte_index<width;++byte_index){uint8_t byte;const unsigned char *source;if(!adi_substitution_byte(address+byte_index,&byte)){source=translate(regions,count,address+byte_index,1,1);if(!source)return 0;byte=*source;}result|=(uint64_t)byte<<(byte_index*8);}
 *value=result;return 1;
}
static unsigned char *memory(struct runtime *r,uint64_t p,size_t n,unsigned perm){if(n>UINT_MAX)return 0;return translate(r->regions,r->count,p,(unsigned)n,perm);}
static int put(struct runtime *r,uint64_t p,uint64_t v,unsigned n){unsigned char *b=memory(r,p,n,2);unsigned j;if(!b)return 0;for(j=0;j<n;++j)b[j]=(unsigned char)(v>>(8*j));return 1;}
static int get(struct runtime *r,uint64_t p,uint64_t *v,unsigned n){return adi_native_read(r->regions,r->count,p,n,v);}
static int string(struct runtime *r,uint64_t p,char *out,size_t n){size_t j;for(j=0;j<n;++j){unsigned char *b=memory(r,p+j,1,1);if(!b)return 0;out[j]=(char)*b;if(!*b)return 1;}return 0;}
static int entropy(struct runtime *r,unsigned char *p,size_t n){
 FILE *f;int ok;if(r->request->entropy)return r->request->entropy(r->request->user,p,n)==0;
 f=fopen("/dev/urandom","rb");if(!f)return 0;ok=fread(p,1,n,f)==n;fclose(f);return ok;
}
static uint64_t allocate(struct runtime *r,size_t n){uint64_t p=r->heap;if(n>0x1000000||p>HEAP+HEAP_SIZE-n-16)return 0;r->heap=(p+n+15)&~UINT64_C(15);return p;}
static int external(struct runtime *r,const char *name){
 wrapper_kg_payload_state *s=&r->state.cpu;uint64_t *g=s->gpr;
 uint64_t a[6]={g[5],g[4],g[3],g[2],g[8],g[9]},ret=0,n,p;unsigned char *dst,*src;char text[4096];size_t j;
 if(!strcmp(name,"malloc")||!strcmp(name,"calloc")||!strcmp(name,"_Znwm")){
  if(!strcmp(name,"calloc")&&a[0]&&a[1]>SIZE_MAX/a[0])return 0;
  n=!strcmp(name,"calloc")?a[0]*a[1]:a[0];ret=allocate(r,n);if(!ret)return 0;
 }else if(!strcmp(name,"free")||!strncmp(name,"pthread_rwlock_",15)||!strncmp(name,"pthread_mutex_",14)){}
 else if(!strcmp(name,"memcpy")||!strcmp(name,"memmove")){
  dst=memory(r,a[0],a[2],2);src=memory(r,a[1],a[2],1);if(!dst||!src)return 0;memmove(dst,src,a[2]);ret=a[0];
 }else if(!strcmp(name,"memset")){dst=memory(r,a[0],a[2],2);if(!dst)return 0;memset(dst,(int)a[1],a[2]);ret=a[0];}
 else if(!strcmp(name,"strlen")){if(!string(r,a[0],text,sizeof text))return 0;ret=strlen(text);}
 else if(!strcmp(name,"strncpy")){
  if(!string(r,a[1],text,sizeof text))return 0;dst=memory(r,a[0],a[2],2);if(!dst)return 0;
  n=strlen(text);if(n>a[2])n=a[2];memcpy(dst,text,n);memset(dst+n,0,a[2]-n);ret=a[0];
 }else if(!strcmp(name,"dlopen")){
  if(!string(r,a[0],text,sizeof text)||!strstr(text,"libCoreADI.so"))return 0;ret=0x1234;
 }else if(!strcmp(name,"dlsym")){
  if(!string(r,a[1],text,sizeof text))return 0;
  for(j=0;j<sizeof symbols/sizeof symbols[0];++j)if(!strcmp(text,symbols[j].name)){ret=symbols[j].address;break;}
  if(!ret)return 0;
 }else if(!strcmp(name,"__errno")||!strcmp(name,"__errno_location")){ret=HEAP+0x100;if(!put(r,ret,2,4))return 0;}
 else if(!strcmp(name,"__system_property_get")){if(!put(r,a[1],0,1))return 0;}
 else if(!strcmp(name,"gettimeofday")){
  int64_t sec,usec;struct timeval tv;
  if(r->request->time){if(r->request->time(r->request->user,&sec,&usec))return 0;}
  else{if(gettimeofday(&tv,0))return 0;sec=tv.tv_sec;usec=tv.tv_usec;}
  if(!put(r,a[0],(uint64_t)sec,8)||!put(r,a[0]+8,(uint64_t)usec,8))return 0;
 }else if(!strcmp(name,"arc4random")){
  unsigned char b[4];if(!entropy(r,b,4))return 0;for(j=0;j<4;++j)ret|=(uint64_t)b[j]<<(8*j);
 }else if(!strcmp(name,"arc4random_buf")){dst=memory(r,a[0],a[1],2);if(!dst||!entropy(r,dst,a[1]))return 0;}
 else if(!strcmp(name,"open")||!strcmp(name,"open64")){
  if(!string(r,a[0],text,sizeof text))return 0;
  if(strcmp(text,"/data/adi.pb")||a[1]&3||!r->request->provision_size)ret=UINT64_MAX;
  else{r->position=0;r->fd=10;ret=10;}
 }else if(!strcmp(name,"read")){
  if(a[0]!=(uint64_t)r->fd||!r->fd)ret=UINT64_MAX;
  else{n=r->request->provision_size-r->position;if(n>a[2])n=a[2];dst=memory(r,a[1],n,2);if(!dst)return 0;memcpy(dst,r->request->provision+r->position,n);r->position+=n;ret=n;}
 }else if(!strcmp(name,"close")){r->fd=0;}
 else if(!strcmp(name,"lstat")||!strcmp(name,"stat")||!strcmp(name,"fstat")){
  int found=0,isfile=0;
  if(!strcmp(name,"fstat")){found=(a[0]==(uint64_t)r->fd&&r->fd);isfile=found;}
  else{if(!string(r,a[0],text,sizeof text))return 0;isfile=r->request->provision_size&&!strcmp(text,"/data/adi.pb");found=isfile||!strcmp(text,"/data")||!strcmp(text,"/data/");}
  if(!found)ret=UINT64_MAX;
  else{
   dst=memory(r,a[1],144,2);if(!dst)return 0;memset(dst,0,144);
   if(!put(r,a[1]+16,1,8)||!put(r,a[1]+24,isfile?0100600:040700,4)||!put(r,a[1]+48,isfile?r->request->provision_size:0,8)||!put(r,a[1]+56,4096,8)||!put(r,a[1]+88,1700000000,8)||!put(r,a[1]+104,1700000000,8))return 0;
  }
 }else return 0;
 g[0]=ret;if(!get(r,g[7],&p,8))return 0;g[7]+=8;s->pc=p;return 1;
}
static int run(struct runtime *r){
 wrapper_kg_payload_state *s=&r->state.cpu;size_t lo,hi,j;int status;
 while(r->steps<UINT64_C(100000000)){
  if(s->pc==RETURN)return 1;
  if(r->trace)r->trace(s->pc,s->gpr,s->flags,r->state.xmm,r->trace_user);
  for(j=0;j<sizeof stubs/sizeof stubs[0];++j)if(stubs[j].address==s->pc)break;
  if(j<sizeof stubs/sizeof stubs[0]){if(!external(r,stubs[j].name))return 0;++r->steps;continue;}
  lo=0;hi=sizeof bounds/sizeof bounds[0];while(lo<hi){size_t mid=lo+(hi-lo)/2;if(bounds[mid].begin<=s->pc)lo=mid+1;else hi=mid;}
  if(!lo||s->pc>=bounds[lo-1].end)return 0;--lo;
  status=groups[bounds[lo].group](bounds[lo].index,s->pc>=UINT64_C(0x10000000)?UINT64_C(0x10000000):0,&r->state,r->regions,r->count,100000000-r->steps);
  r->steps+=s->steps;
  if(status==WRAPPER_KG_NATIVE_CLOCK){uint64_t t=UINT64_C(0x1234567800000000)+(r->ticks++)*100003;s->gpr[0]=(uint32_t)t;s->gpr[3]=(uint32_t)(t>>32);s->pc+=2;++r->steps;}
  else if(status!=WRAPPER_KG_PAYLOAD_OK)return 0;
 }
 return 0;
}
static int invoke(struct runtime *r,uint64_t entry,const uint64_t *args,size_t count){
 static const unsigned indices[6]={5,4,3,2,8,9};size_t j;r->state.cpu.gpr[7]=STACK+0x80000;
 if(!put(r,STACK+0x80000,RETURN,8))return 0;
 for(j=0;j<count;++j)r->state.cpu.gpr[indices[j]]=args[j];r->state.cpu.pc=entry;return run(r);
}
static uint64_t bytes(struct runtime *r,const unsigned char *data,size_t n){uint64_t p=allocate(r,n+1);unsigned char *dst=memory(r,p,n+1,2);if(!dst)return 0;memcpy(dst,data,n);dst[n]=0;return p;}
static void clear(unsigned char *p,size_t n){volatile unsigned char *q=p;while(n--)*q++=0;}
static int generate(const wrapper_adi_request *request,unsigned char *mid,size_t mid_cap,unsigned char *otp,size_t otp_cap,wrapper_adi_result *result,void (*trace)(uint64_t,const uint64_t *,uint64_t,const kg_vec *,void *),void *trace_user){
 struct runtime r;size_t j;int status=-1;uint64_t args[6],p,n,midp,otpp,midn,otpn;
 if(!result)return -1;memset(result,0,sizeof *result);
 if(!request||!request->provision||!request->provision_size||request->provision_size>PROVISION_SIZE_LIMIT||!request->android_id||!request->android_id_size||request->android_id_size>ANDROID_ID_SIZE_LIMIT||!mid||!otp)return -1;
 memset(&r,0,sizeof r);r.request=request;r.heap=HEAP+0x10000;r.trace=trace;r.trace_user=trace_user;
 for(j=0;j<sizeof images/sizeof images[0];++j){const struct image *im=images+j;unsigned char *data;
  if(im->flags&2){data=malloc(im->size);if(!data)goto done;memcpy(data,im->data,im->size);}
  else data=(unsigned char *)im->data;
  r.regions[r.count++]=(wrapper_kg_payload_region){im->address,im->size,data,1|((im->flags&2)?2:0)};
 }
 for(j=0;j<2;++j){size_t size=j?HEAP_SIZE:0x200000;unsigned char *data=calloc(1,size);if(!data)goto done;r.regions[r.count++]=(wrapper_kg_payload_region){j?HEAP:STACK,size,data,3};}
 status=-2;
 p=bytes(&r,(const unsigned char *)"/system/lib64",13);
 n=bytes(&r,(const unsigned char *)"/data",5);
 midp=bytes(&r,request->android_id,request->android_id_size);
 if(!p||!n||!midp)goto done;
 args[0]=p;if(!invoke(&r,ENTRY_kq56gsgHG6,args,1)||(uint32_t)r.state.cpu.gpr[0])goto done;
 args[0]=n;if(!invoke(&r,ENTRY_nf92ngaK92,args,1)||(uint32_t)r.state.cpu.gpr[0])goto done;
 args[0]=midp;args[1]=request->android_id_size;if(!invoke(&r,ENTRY_Sph98paBcz,args,2)||(uint32_t)r.state.cpu.gpr[0])goto done;
 args[0]=UINT64_MAX;args[1]=HEAP+0x1000;args[2]=HEAP+0x1010;args[3]=HEAP+0x1020;args[4]=HEAP+0x1030;
 if(!invoke(&r,ENTRY_qi864985u0,args,5))goto done;
 status=-3;result->status=(int32_t)r.state.cpu.gpr[0];if(result->status)goto done;
 if(!get(&r,HEAP+0x1000,&midp,8)||!get(&r,HEAP+0x1010,&midn,4)||!get(&r,HEAP+0x1020,&otpp,8)||!get(&r,HEAP+0x1030,&otpn,4))goto done;
 if(!midn||!otpn||midn>mid_cap||otpn>otp_cap||!memory(&r,midp,midn,1)||!memory(&r,otpp,otpn,1))goto done;
 memcpy(mid,memory(&r,midp,midn,1),midn);memcpy(otp,memory(&r,otpp,otpn,1),otpn);result->mid_size=midn;result->otp_size=otpn;status=0;
 done:result->pc=r.state.cpu.pc;result->fault_address=r.state.cpu.fault_address;result->fault_size=r.state.cpu.fault_size;result->steps=r.steps;
 for(j=0;j<r.count;++j)if(r.regions[j].permissions&2){clear(r.regions[j].data,r.regions[j].size);free(r.regions[j].data);}
 (void)p;(void)n;return status;
}

static int start_provisioning(const wrapper_adi_request *request,uint64_t ds_id,const unsigned char *spim,size_t spim_size,unsigned char *cpim,size_t cpim_cap,wrapper_adi_provision_result *result){
 struct runtime r;wrapper_adi_request fresh_request;size_t j;int status=-1;uint64_t args[6],library_path,data_path,android_id,spim_pointer,cpim_pointer,cpim_size_value,session_value;
 if(!result)return -1;memset(result,0,sizeof *result);
 if(!request||!request->android_id||!request->android_id_size||request->android_id_size>ANDROID_ID_SIZE_LIMIT||!spim||!spim_size||spim_size>SPIM_SIZE_LIMIT||!cpim||!cpim_cap)return -1;
 memset(&r,0,sizeof r);fresh_request=*request;fresh_request.provision=0;fresh_request.provision_size=0;r.request=&fresh_request;r.heap=HEAP+0x10000;
 for(j=0;j<sizeof images/sizeof images[0];++j){const struct image *im=images+j;unsigned char *data;
  if(im->flags&2){data=malloc(im->size);if(!data)goto done;memcpy(data,im->data,im->size);}
  else data=(unsigned char *)im->data;
  r.regions[r.count++]=(wrapper_kg_payload_region){im->address,im->size,data,1|((im->flags&2)?2:0)};
 }
 for(j=0;j<2;++j){size_t size=j?HEAP_SIZE:0x200000;unsigned char *data=calloc(1,size);if(!data)goto done;r.regions[r.count++]=(wrapper_kg_payload_region){j?HEAP:STACK,size,data,3};}
 status=-2;
 library_path=bytes(&r,(const unsigned char *)"/system/lib64",13);
 data_path=bytes(&r,(const unsigned char *)"/data",5);
 android_id=bytes(&r,request->android_id,request->android_id_size);
 spim_pointer=bytes(&r,spim,spim_size);
 if(!library_path||!data_path||!android_id||!spim_pointer)goto done;
 args[0]=library_path;if(!invoke(&r,ENTRY_kq56gsgHG6,args,1)||(uint32_t)r.state.cpu.gpr[0])goto done;
 args[0]=data_path;if(!invoke(&r,ENTRY_nf92ngaK92,args,1)||(uint32_t)r.state.cpu.gpr[0])goto done;
 args[0]=android_id;args[1]=request->android_id_size;if(!invoke(&r,ENTRY_Sph98paBcz,args,2)||(uint32_t)r.state.cpu.gpr[0])goto done;
 args[0]=ds_id;args[1]=spim_pointer;args[2]=spim_size;args[3]=CPIM_POINTER_SLOT;args[4]=CPIM_SIZE_SLOT;args[5]=SESSION_SLOT;
 if(!invoke(&r,ENTRY_rsegvyrt87,args,6))goto done;
 status=-3;result->status=(int32_t)r.state.cpu.gpr[0];if(result->status){status=0;goto done;}
 if(!get(&r,CPIM_POINTER_SLOT,&cpim_pointer,8)||!get(&r,CPIM_SIZE_SLOT,&cpim_size_value,4)||!get(&r,SESSION_SLOT,&session_value,4))goto done;
 if(!cpim_size_value||cpim_size_value>cpim_cap||session_value>UINT32_MAX||!memory(&r,cpim_pointer,cpim_size_value,1))goto done;
 memcpy(cpim,memory(&r,cpim_pointer,cpim_size_value,1),cpim_size_value);result->cpim_size=cpim_size_value;result->session=(uint32_t)session_value;status=0;
 done:result->pc=r.state.cpu.pc;result->fault_address=r.state.cpu.fault_address;result->fault_size=r.state.cpu.fault_size;result->steps=r.steps;
 for(j=0;j<r.count;++j)if(r.regions[j].permissions&2){clear(r.regions[j].data,r.regions[j].size);free(r.regions[j].data);}
 return status;
}

int wrapper_adi_otp(const wrapper_adi_request *r,unsigned char *mid,size_t mc,unsigned char *otp,size_t oc,wrapper_adi_result *result){return generate(r,mid,mc,otp,oc,result,0,0);}
int wrapper_adi_provision_start(const wrapper_adi_request *r,uint64_t ds_id,const unsigned char *spim,size_t spim_size,unsigned char *cpim,size_t cpim_cap,wrapper_adi_provision_result *result){return start_provisioning(r,ds_id,spim,spim_size,cpim,cpim_cap,result);}
/* Offline verifier only: CPU material is delivered in RAM to an explicit caller
 * callback. The production entry never enables or logs this trace. */
int wrapper_adi_otp_trace(const wrapper_adi_request *r,unsigned char *mid,size_t mc,unsigned char *otp,size_t oc,wrapper_adi_result *result,void (*trace)(uint64_t,const uint64_t *,uint64_t,const kg_vec *,void *),void *user){return generate(r,mid,mc,otp,oc,result,trace,user);}
