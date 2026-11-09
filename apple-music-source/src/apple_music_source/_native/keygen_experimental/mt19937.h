#ifndef WRAPPER_KEYGEN_EXPERIMENTAL_MT19937_H
#define WRAPPER_KEYGEN_EXPERIMENTAL_MT19937_H
#include <stdint.h>
/* Recovered internal compatibility primitive. Not a cryptographic entropy source. */
void wrapper_kg_mt19937_twist(uint32_t state[624]);
uint32_t wrapper_kg_mt19937_temper(uint32_t value);
void wrapper_kg_mt19937_encode_word(uint32_t value, uint8_t output[4]);
#endif
