#ifndef SHA512_H
#define SHA512_H

#include <openssl/sha.h>
    
unsigned char *sha512_hash (const void *data, unsigned long data_len, const void *salt, unsigned long salt_len, size_t *len);
char *sha512_encode_hex (char *in, size_t *len);
#endif
