#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "sha256.h"


unsigned char *sha256_hash(const void *data, unsigned long data_len, const void *salt, unsigned long salt_len, unsigned char *md) {
	SHA256_CTX c;
   
	if (SHA256_Init(&c) != 1) {
		return NULL;
	}
	if (SHA256_Update(&c, salt, salt_len) != 1) {
		return NULL;
	}
	if (SHA256_Update(&c, data, data_len) != 1) {
		return NULL;
	}
	if (SHA256_Final(md, &c) != 1) {
        return NULL;
    }
    return md;
        
}


char *sha256_encode_hex(char *out, const char *in) {
    int i; 
    
    for (i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        sprintf(&out[i*2], "%02x", (uint8_t) in[i]);
    }
    return out;
}
