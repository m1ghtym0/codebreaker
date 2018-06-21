#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../src/cracker/sha512.h"



int main (int argc, char *argv[]) {
	size_t len;
	char *hashed, *encoded;
   
   
	if (argc < 4) {
		return EXIT_FAILURE;
	}
	
	char *salt = argv[1];
	char *data = argv[2];
	char *hash = argv[3];
	
	if ((hashed = (char *) sha512_hash(data, strlen(data), salt, strlen(salt), &len)) == NULL) {
		return EXIT_FAILURE;
	}
	
	if ((encoded = sha512_encode_hex(hashed, &len)) == NULL) {
		return EXIT_FAILURE;
	}
	
	if (!strncmp(encoded, hash, len)) {
		return EXIT_SUCCESS;
	} else {
		return EXIT_FAILURE;
	}
}
