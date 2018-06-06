#ifndef CRACKER_H
#define CRACKER_H

typedef unsigned char* (*compute_hash) (const void *data, unsigned long data_len, const void *salt, unsigned long salt_len, unsigned char *md);
typedef char* (*encode_hash) (char *out, const char *in);

struct hash_ctx {
	unsigned long digest_len;
	compute_hash compute_hash;
	encode_hash encode_hash;
};
typedef struct hash_ctx hash_ctx;

/*
 * algo:
 *	- 0: md5
 *	- 1: sha256
 *	- 2: sha512
 */
int set_hash_algo(hash_ctx *c, int algo);
int check_pass (hash_ctx *c, char *pass, char *salt, char *hash);

#endif
