#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../src/cracker/cracker.h"



int main (int argc, char *argv[]) {
    hash_ctx c;
    char *salt, *data, *hash;
    int algo;
    
     
    if (argc < 5) {
        return EXIT_FAILURE;
    }
    
    algo = atoi(argv[1]);
    salt = argv[2];
    data = argv[3];
    hash = argv[4];
   
    
    if (set_hash_algo(&c, algo) == -1) {
        return EXIT_FAILURE;
    }
    
    if (!check_pass (&c, data, salt, hash)) {
        return EXIT_FAILURE;
    } else {
        return EXIT_SUCCESS;
    }
}
