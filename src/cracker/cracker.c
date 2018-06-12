#include <stdlib.h>
#include <string.h>
#include "cracker.h"
#include "md5.h"
#include "sha256.h"
#include "sha512.h"

int set_hash_algo (hash_ctx *c, int algo) {
	switch (algo) {
		case 1:
			c->digest_len = MD5_DIGEST_LENGTH;
			c->compute_hash = md5_hash;
			c->encode_hash = md5_encode_hex;
			return 0;
		case 5:
			c->digest_len = SHA256_DIGEST_LENGTH;
			c->compute_hash = sha256_hash;
			c->encode_hash = sha256_encode_hex;
			return 0;
		case 6:
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

hash_element *parse_passfile (vector *pass_file, int *size) {
	int i, algo;
	char *hash_type, *hash, *salt;
	hash_element *hashes;
	
	if ((hashes = calloc(total_vector(pass_file), sizeof(hash_element))) == NULL) {
		perror("calloc");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < total_vector(pass_file); i++) {
		hash_type = strtok(get_vector(pass_file, i), "$");
		salt = strtok(NULL, "$");
		hash = strtok(NULL, "$");

		if (hash_type == NULL || hash == NULL) {
			fprintf(stderr, "ERROR: Passfile has a bad format\nShould be: type$salt$hash\\n\n");
			return NULL;
		}
		if (!strcmp(salt, " ")) {
			salt = "";
		}

		algo = atoi(hash_type);
		if (set_hash_algo(&hashes[i].ctx, algo) != 0) {
			fprintf(stderr, "ERROR: Unsupported hash-algorithm\n");
			return NULL;
		}
		hashes[i].salt = salt;
		hashes[i].hash = hash;
	}
	*size = i;

	return hashes;
}
