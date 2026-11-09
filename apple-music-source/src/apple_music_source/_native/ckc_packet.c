#include "ckc_packet.h"
#include <string.h>

static void word(unsigned char *output, size_t index, uint64_t value) {
    unsigned j;
    for(j=0;j<8;++j)output[index*8+j]=(unsigned char)(value>>(56-j*8));
}
static int begin(unsigned char *output,size_t capacity,uint64_t argument_count) {
    if(!output || capacity<WRAPPER_KG_CKC_PACKET_SIZE)return -1;
    memset(output,0,WRAPPER_KG_CKC_PACKET_SIZE);
    word(output,0,argument_count);
    word(output,2,1);
    return 0;
}
static uint64_t read_word(const unsigned char *packet,size_t index) {
    unsigned j;uint64_t value=0;
    for(j=0;j<8;++j)value=(value<<8)|packet[index*8+j];
    return value;
}
int wrapper_kg_ckc_packet_status(const unsigned char *packet,size_t size,uint32_t *status) {
    uint64_t value;
    if(!packet || !status || size<24 || read_word(packet,0)!=1 || read_word(packet,1)!=0)return -1;
    value=read_word(packet,2);
    if(value>UINT32_MAX)return -1;
    *status=(uint32_t)value;
    return 0;
}
int wrapper_kg_ckc_persistent_packet(unsigned char *output,size_t capacity,
    uint64_t exchange,uint64_t ckc,uint32_t ckc_size,
    uint64_t persistent_output,uint64_t size_output) {
    if(begin(output,capacity,6))return -1;
    word(output,3,exchange);word(output,4,ckc);word(output,5,ckc_size);
    word(output,6,persistent_output);word(output,7,size_output);
    return 0;
}
int wrapper_kg_ckc_context_packet(unsigned char *output,size_t capacity,
    uint64_t exchange,uint64_t ckc,uint32_t ckc_size,uint64_t context_output) {
    if(begin(output,capacity,5))return -1;
    word(output,3,exchange);word(output,4,ckc);word(output,5,ckc_size);
    word(output,6,context_output);
    return 0;
}
int wrapper_kg_context_finalize_packet(unsigned char *output,size_t capacity,
    uint64_t context) {
    if(begin(output,capacity,2))return -1;
    word(output,3,context);
    return 0;
}
int wrapper_kg_context_decrypt_packet(unsigned char *output,size_t capacity,
    uint64_t context,uint32_t mode,uint64_t input,uint64_t decrypted_output,
    uint32_t size) {
    if(begin(output,capacity,6))return -1;
    word(output,3,context);word(output,4,mode);word(output,5,input);
    word(output,6,decrypted_output);word(output,7,size);
    return 0;
}
