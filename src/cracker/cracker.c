#include <stdlib.h>
#include <string.h>
#include "cracker.h"
#include "md5.h"
#include "sha256.h"
#include "sha512.h"
#include "linux_crypt.h"

int set_hash_algo (hash_ctx *c, int algo, char *hash_format) {
    if (!strcmp(hash_format, "regular")) {
        switch (algo) {
            case 1:
                c->compute_hash = md5_hash;
                c->encode_hash = md5_encode_hex;
                return 0;
            case 5:
                c->compute_hash = sha256_hash;
                c->encode_hash = sha256_encode_hex;
                return 0;
            case 6:
                c->compute_hash = sha512_hash;
                c->encode_hash = sha512_encode_hex;
                return 0;
            default:
                return -1;
        }
    } else if  (!strcmp(hash_format, "linux-crypt")) {
         switch (algo) {
            case 1:
                c->compute_hash = md5_crypt;
                c->encode_hash = encode_crypt;
                return 0;
            case 5:
                c->compute_hash = sha256_crypt;
                c->encode_hash = encode_crypt;
                return 0;
            case 6:
                c->compute_hash = sha512_crypt;
                c->encode_hash = encode_crypt;
                return 0;
            default:
                return -1;
        }
    } else {
        return -1;
    }
}

int check_pass (hash_ctx *c, char *pass, char *salt, char *hash) {
    unsigned char *hashed;
    char *encoded;
    size_t len;

    if ((hashed = c->compute_hash(pass, strlen(pass), salt, strlen(salt), &len)) == NULL) {
        return -1;
    }

    if ((encoded = c->encode_hash((char *) hashed, &len)) == NULL) {
        free(hashed);
        return -1;
    }

    if (!strncmp(encoded, hash, len)) {
        free(hashed);
        return 1;
    } else {
        free(hashed);
        return 0;
    }
}

hash_element *parse_passfile (vector *pass_file, char *hash_format, size_t *size) {
    int algo;
    ssize_t i;
    char *hash_type, *hash, *salt;
    hash_element *hashes;

    if ((hashes = calloc(total_vector(pass_file), sizeof(hash_element))) == NULL) {
        perror("calloc");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < total_vector(pass_file); i++) {
        hash_type = strtok(get_vector(pass_file, i), "$");
        salt = strtok(NULL, "$");
        hash = strtok(NULL, "\n");

        if (hash_type == NULL || hash == NULL) {
            fprintf(stderr, "ERROR: Passfile has a bad format\nShould be: type$salt$hash\\n\n");
            return NULL;
        }
        if (!strcmp(salt, " ")) {
            salt = "";
        }

        algo = atoi(hash_type);
        if (set_hash_algo(&hashes[i].ctx, algo, hash_format) != 0) {
            fprintf(stderr, "ERROR: Unsupported hash-algorithm\n");
            return NULL;
        }
        hashes[i].salt = salt;
        hashes[i].hash = hash;
    }
    *size = (size_t) i;

    return hashes;
}
