#ifndef CRACKER_H
#define CRACKER_H

#include "../input/input.h"

typedef unsigned char* (*compute_hash) (const void *data, unsigned long data_len, const void *salt, unsigned long salt_len, size_t *len);
typedef char* (*encode_hash) (char *in, size_t *len);

struct hash_ctx {
    compute_hash compute_hash;
    encode_hash encode_hash;
};
typedef struct hash_ctx hash_ctx;

struct hash_element {
    hash_ctx ctx;
    char *salt;
    char *hash;
};
typedef struct hash_element hash_element;

/*
 * algo:
 *  - 1: md5
 *  - 2: blowfish (not implemented)
 *  - 5: sha256
 *  - 6: sha512
 */
int set_hash_algo(hash_ctx *c, int algo, char *hash_format);
int check_pass (hash_ctx *c, char *pass, char *salt, char *hash);
hash_element *parse_passfile (vector *pass_file, char *hash_format, size_t *size);

#endif
