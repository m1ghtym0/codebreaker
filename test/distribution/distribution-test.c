#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../src/distribution/distribution.h"
#include "../../src/distribution/input/read_file.h"
#include "../../src/distribution/input/vector.h"

#define NODES 5

int main (int argc, char *argv[]) {
	char *wordlist;
	FILE *fp;
	size_t size;
	vector *words;
	vector dist_words;
	int i;

	if (argc < 2) {
		return EXIT_FAILURE;
	}

	wordlist = argv[1];

	fp = open_file(wordlist, &size);

	words = index_file(fp, size);
	

	for (i = 0; i < NODES; i++) {
		distribution(words, &dist_words, i, NODES);
        printf("NODE[%d]:\n", i);
		print_vector(&dist_words);
	}
    return EXIT_SUCCESS;
}
