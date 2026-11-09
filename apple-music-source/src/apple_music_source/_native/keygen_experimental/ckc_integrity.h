#ifndef WRAPPER_CKC_INTEGRITY_H
#define WRAPPER_CKC_INTEGRITY_H
#include <stdint.h>
/* Evaluates the recovered paired-byte function, never individual code bytes. */
int wrapper_kg_ckc_integrity_pair(uint64_t a,uint64_t b,uint8_t *out);
int wrapper_kg_ckc_integrity_word(uint64_t a,uint64_t b,unsigned width,uint64_t *out);
#endif
