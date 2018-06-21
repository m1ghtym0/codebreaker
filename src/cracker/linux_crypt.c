#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linux_crypt.h"

#define UNUSED(x)   ((void)(x))

char *hash_crypt (const char *data, const char *salt_prefix, const char *salt, size_t *len) {
    char *in;
    char *out;

    if (asprintf(&in, "$%s$%s", salt_prefix, salt) == -1) {
        return NULL;
    }

    out = crypt(data, in);
    *len = strlen(out);
    return out;
}

unsigned char *md5_crypt (const void *data, unsigned long data_len, const void *salt, unsigned long salt_len, size_t *len) {
    UNUSED(data_len);
    UNUSED(salt_len);
    return (unsigned char *) hash_crypt ((const char *)data, "1", (const char *)salt, len);
}

unsigned char *sha256_crypt (const void *data, unsigned long data_len, const void *salt, unsigned long salt_len, size_t *len) {
    UNUSED(data_len);
    UNUSED(salt_len);
    return (unsigned char *) hash_crypt ((const char *)data, "5", (const char *)salt, len);
}

unsigned char *sha512_crypt (const void *data, unsigned long data_len, const void *salt, unsigned long salt_len, size_t *len) {
    UNUSED(data_len);
    UNUSED(salt_len);
    return (unsigned char *) hash_crypt ((const char *)data, "6", (const char *)salt, len);
}

char *encode_crypt (char *in, size_t *len) {
    char *tok;

    tok = strtok(in+1, "$"); // $id$salt$encrypted
    tok = strtok(NULL, "$"); // salt$encrypted
    tok = strtok(NULL, "$"); // encrypted

    *len = strlen(tok);
    return tok;
}

