#ifndef LINUX_CRYPT_H
#define LINUX_CRYPT_H

//#define _XOPEN_SOURCE
#include <unistd.h>

unsigned char *md5_crypt (const void *data, unsigned long data_len, const void *salt, unsigned long salt_len, size_t *len);
unsigned char *sha256_crypt (const void *data, unsigned long data_len, const void *salt, unsigned long salt_len, size_t *len);
unsigned char *sha512_crypt (const void *data, unsigned long data_len, const void *salt, unsigned long salt_len, size_t *len);

char *encode_crypt (char *in, size_t *len);
#endif
