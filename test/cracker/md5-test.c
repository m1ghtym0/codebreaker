#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../src/cracker/md5.h"



int main (int argc, char *argv[]) {
    char md[MD5_DIGEST_LENGTH];  
    char out[MD5_DIGEST_LENGTH*2];  
   
    if (argc < 4) {
        return EXIT_FAILURE;
    }
    
    char *salt = argv[1];
    char *data = argv[2];
    char *hash = argv[3];
    
    if (md5_hash(data, strlen(data), salt, strlen(salt), (unsigned char *) md) == NULL) {
        return EXIT_FAILURE;
    }
    
    if (md5_encode_hex(out, md) == NULL) {
        return EXIT_FAILURE;
    }
    
    if (!strncmp(out, hash, MD5_DIGEST_LENGTH*2)) {
        return EXIT_SUCCESS;
    } else {
        return EXIT_FAILURE;
    }
}
