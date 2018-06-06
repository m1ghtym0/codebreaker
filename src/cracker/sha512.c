#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "sha512.h"



unsigned char *sha512_hash(const void *data, unsigned long data_len, const void *salt, unsigned long salt_len, unsigned char *md) {
	SHA512_CTX c;
   
	if (SHA512_Init(&c) != 1) {
		return NULL;
	}
	if (SHA512_Update(&c, salt, salt_len) != 1) {
		return NULL;
	}
	if (SHA512_Update(&c, data, data_len) != 1) {
		return NULL;
	}
	if (SHA512_Final(md, &c) != 1) {
        return NULL;
    }
    return md;
        
}


char *sha512_encode_hex(char *out, const char *in) {
    int i; 
    
    for (i = 0; i < SHA512_DIGEST_LENGTH; ++i) {
        sprintf(&out[i*2], "%02x", (uint8_t) in[i]);
    }
    return out;
}
