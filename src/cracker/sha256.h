#ifndef SHA256_H
#define SHA256_H

#include <openssl/sha.h>
    
unsigned char *sha256_hash (const void *data, unsigned long data_len, const void *salt, unsigned long salt_len, size_t *len);
char *sha256_encode_hex (char *in, size_t *len);
#endif
