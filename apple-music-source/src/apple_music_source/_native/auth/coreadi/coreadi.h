#ifndef WRAPPER_AUTH_COREADI_H
#define WRAPPER_AUTH_COREADI_H
#include <stddef.h>
#include <stdint.h>
typedef int (*wrapper_adi_entropy)(void *,unsigned char *,size_t);
typedef int (*wrapper_adi_time)(void *,int64_t *,int64_t *);
typedef struct wrapper_adi_request {
 const unsigned char *provision;size_t provision_size;
 const unsigned char *android_id;size_t android_id_size;
 wrapper_adi_entropy entropy;wrapper_adi_time time;void *user;
} wrapper_adi_request;
typedef struct wrapper_adi_result {
 int32_t status;uint64_t pc,fault_address,steps;unsigned fault_size;
 size_t mid_size,otp_size;
} wrapper_adi_result;
typedef struct wrapper_adi_provision_result {
 int32_t status;uint64_t pc,fault_address,steps;unsigned fault_size;
 uint32_t session;size_t cpim_size;
} wrapper_adi_provision_result;
/* Generate anonymous (-1) CoreADI machine data from caller provisioning state.
 * Source operations only: no SDK binary, emulator or network is loaded.
 * Returns zero on success; output and diagnostic buffers are caller owned. */
int wrapper_adi_otp(const wrapper_adi_request *,unsigned char *,size_t,unsigned char *,size_t,wrapper_adi_result *);
int wrapper_adi_provision_start(const wrapper_adi_request *,uint64_t,const unsigned char *,size_t,unsigned char *,size_t,wrapper_adi_provision_result *);
#endif
