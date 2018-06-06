#ifndef MD5_H
#define MD5_H

#include <openssl/md5.h>
    
unsigned char *md5_hash (const void *data, unsigned long data_len, const void *salt, unsigned long salt_len, unsigned char *md);
char *md5_encode_hex (char *out, const char *in);
#endif
