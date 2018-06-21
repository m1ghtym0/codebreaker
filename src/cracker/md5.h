#ifndef MD5_H
#define MD5_H

#include <openssl/md5.h>
    
unsigned char *md5_hash (const void *data, unsigned long data_len, const void *salt, unsigned long salt_len, size_t *len);
char *md5_encode_hex (char *in, size_t *len);
#endif
