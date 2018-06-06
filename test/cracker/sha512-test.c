#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../src/cracker/sha512.h"



int main (int argc, char *argv[]) {
    char md[SHA512_DIGEST_LENGTH];  
    char out[SHA512_DIGEST_LENGTH*2];  
   
    if (argc < 4) {
        return EXIT_FAILURE;
    }
    
    char *salt = argv[1];
    char *data = argv[2];
    char *hash = argv[3];
    
    if (sha512_hash(data, strlen(data), salt, strlen(salt), (unsigned char *) md) == NULL) {
        return EXIT_FAILURE;
    }
    
    if (sha512_encode_hex(out, md) == NULL) {
        return EXIT_FAILURE;
    }
    
    if (!strncmp(out, hash, SHA512_DIGEST_LENGTH*2)) {
        return EXIT_SUCCESS;
    } else {
        return EXIT_FAILURE;
    }
}
