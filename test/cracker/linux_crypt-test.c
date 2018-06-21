#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../src/cracker/linux_crypt.h"



int main (int argc, char *argv[]) {
	size_t len;
	char *hashed, *encoded;
   
   
	if (argc < 5) {
		return EXIT_FAILURE;
	}
	
	char *salt = argv[1];
	char *data = argv[2];
	char *hash = argv[3];
	char *type = argv[4];

	if (!strcmp(type, "md5")) {
			if ((hashed = (char *) md5_crypt(data, strlen(data), salt, strlen(salt), &len)) == NULL) {
				return EXIT_FAILURE;
			}
    } else if (!strcmp(type, "sha256")) {
			if ((hashed = (char *) sha256_crypt(data, strlen(data), salt, strlen(salt), &len)) == NULL) {
				return EXIT_FAILURE;
			}
    } else if (!strcmp(type, "sha512")) {
			if ((hashed = (char *) sha512_crypt(data, strlen(data), salt, strlen(salt), &len)) == NULL) {
				return EXIT_FAILURE;
			}
    } else {
			return EXIT_FAILURE;
	}
	
	if ((encoded = encode_crypt(hashed, &len)) == NULL) {
		return EXIT_FAILURE;
	}
	
	if (!strncmp(encoded, hash, len)) {
		return EXIT_SUCCESS;
	} else {
		return EXIT_FAILURE;
	}
}
