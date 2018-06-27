
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../src/cracker/cracker.h"



int main (int argc, char *argv[]) {
	char *wlist, *plist, *format;
	int w;
	FILE *words_fp, *pass_fp;
	vector *words, *pass;
	size_t file_size, hash_size, h;
	hash_element *hashes;
	int *done;


	if (argc < 4) {
		return EXIT_FAILURE;
	}

	wlist = argv[1];
	plist = argv[2];
	format = argv[3];



	words_fp = open_file(wlist, &file_size);
	words = index_file(words_fp, file_size);

	pass_fp = open_file(plist, &file_size);
	pass = index_file(pass_fp, file_size);

	if ((hashes = parse_passfile(pass, format, &hash_size)) == NULL ) {
		return EXIT_FAILURE;
	}

	if ((done = calloc(hash_size, sizeof(int))) == NULL) {
		perror("calloc");
		return EXIT_FAILURE;
	}

	for (w = 0; w < total_vector(words); w++) {
		for (h = 0; h < hash_size; h++) {
			if (check_pass (&hashes[h].ctx, get_vector(words, w), hashes[h].salt, hashes[h].hash)) {
				done[h] = 1;
			}
		}
	}

	for (h = 0; h < hash_size; h++) {
		if (!done[h]) {
			return EXIT_FAILURE;
		}
	}

	return EXIT_SUCCESS;
}
