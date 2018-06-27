#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "md5.h"

static unsigned char hash[MD5_DIGEST_LENGTH];
static char encoded[MD5_DIGEST_LENGTH*2];

unsigned char *md5_hash (const void *data, unsigned long data_len, const void *salt, unsigned long salt_len, size_t *len) {
    MD5_CTX c;

    *len = MD5_DIGEST_LENGTH;

    if (MD5_Init(&c) != 1) {
        return NULL;
    }
    if (MD5_Update(&c, salt, salt_len) != 1) {
        return NULL;
    }
    if (MD5_Update(&c, data, data_len) != 1) {
        return NULL;
    }
    if (MD5_Final(hash, &c) != 1) {
        return NULL;
    }
    return hash;

}


char *md5_encode_hex (char *in, size_t *len) {
    int i;

    *len = MD5_DIGEST_LENGTH * 2;

    for (i = 0; i < MD5_DIGEST_LENGTH; ++i) {
        sprintf(&encoded[i*2], "%02x", (uint8_t) in[i]);
    }
    return encoded;
}
