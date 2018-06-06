#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "md5.h"


unsigned char *md5_hash (const void *data, unsigned long data_len, const void *salt, unsigned long salt_len, unsigned char *md) {
	MD5_CTX c;
   
    
	if (MD5_Init(&c) != 1) {
		return NULL;
	}
	if (MD5_Update(&c, salt, salt_len) != 1) {
		return NULL;
	}
	if (MD5_Update(&c, data, data_len) != 1) {
		return NULL;
	}
	if (MD5_Final(md, &c) != 1) {
        return NULL;
    }
    return md;
        
}


char *md5_encode_hex (char *out, const char *in) {
    int i; 
    
    for (i = 0; i < MD5_DIGEST_LENGTH; ++i) {
        sprintf(&out[i*2], "%02x", (uint8_t) in[i]);
    }
    return out;
}
