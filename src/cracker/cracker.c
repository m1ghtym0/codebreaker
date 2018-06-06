#include <stdlib.h>
#include <string.h>
#include "cracker.h"
#include "md5.h"
#include "sha256.h"
#include "sha512.h"

int set_hash_algo (hash_ctx *c, int algo) {
	switch (algo) {
		case 0:
			c->digest_len = MD5_DIGEST_LENGTH;
			c->compute_hash = md5_hash;
			c->encode_hash = md5_encode_hex;
			return 0;
		case 1:
			c->digest_len = SHA256_DIGEST_LENGTH;
			c->compute_hash = sha256_hash;
			c->encode_hash = sha256_encode_hex;
			return 0;
		case 2:
			c->digest_len = SHA512_DIGEST_LENGTH;
			c->compute_hash = sha512_hash;
			c->encode_hash = sha512_encode_hex;
			return 0;
		default:
			return -1;
	}
}

int check_pass (hash_ctx *c, char *pass, char *salt, char *hash) {
	char md[c->digest_len];
	char out[c->digest_len*2];
	
	if (c->compute_hash(pass, strlen(pass), salt, strlen(salt), (unsigned char*) md) == NULL) {
		return -1;
	}
	
	c->encode_hash(out, md);
	
	if (!strncmp(out, hash, c->digest_len*2)) {
		return 1;
	} else {
		return 0;
	}
}

