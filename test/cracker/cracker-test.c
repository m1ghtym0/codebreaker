#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../src/cracker/cracker.h"



int main (int argc, char *argv[]) {
    hash_ctx c;
    char *salt, *data, *hash, *format;
    int algo;
    
     
    if (argc < 6) {
        return EXIT_FAILURE;
    }
    
    algo = atoi(argv[1]);
    salt = argv[2];
    data = argv[3];
    hash = argv[4];
    format = argv[5];
   
    
    if (set_hash_algo(&c, algo, format) == -1) {
        return EXIT_FAILURE;
    }
    
    if (!check_pass (&c, data, salt, hash)) {
        fprintf(stderr, "Bad check");
        return EXIT_FAILURE;
    } else {
        return EXIT_SUCCESS;
    }
}
