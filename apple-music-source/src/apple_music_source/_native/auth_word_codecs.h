#ifndef AMS_AUTH_WORD_CODECS_H
#define AMS_AUTH_WORD_CODECS_H
#include <stdint.h>
/* Source instruction word decoders only. No table initialization, complete
 * cipher, device proof, session or authentication provider is implemented.
 * Success returns 1; unsupported IDs/null output return 0 without writing. */
enum ams_auth_word_decoder {
    AMS_AUTH_WORD_COREFP_3BD265 = 0,
    AMS_AUTH_WORD_COREFP_3BD4A0 = 1,
    AMS_AUTH_WORD_COREFP_655AEF = 2,
    AMS_AUTH_WORD_COREFP_6523CC = 3,
    AMS_AUTH_WORD_STORESERVICES_1F82D6 = 4,
};
int ams_auth_word_decode(unsigned decoder,uint32_t word,uint32_t *output);
#endif
