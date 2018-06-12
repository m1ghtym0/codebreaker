#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "read_file.h"
#include "vector.h"

FILE* open_file (char *file_name, size_t *size) {
	FILE *fp;
	struct stat statbuf;

	fp = fopen(file_name, "r");
	if (fp == NULL) {
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	if (stat(file_name, &statbuf) == -1) {
		perror("stat");
	}
	
	*size = statbuf.st_size;
	return fp;
}

vector *index_file (FILE* fp, size_t size) {
	vector *v;
	char *wordlist, *word;

	if ((wordlist = calloc(size, 1)) == NULL) {
		perror("calloc");
	}

	if ((v = calloc(sizeof(vector), 1)) == NULL) {
		perror("calloc");
	}

	init_vector(v);

	if (fread(wordlist, 1, size, fp) < size) {
		if (ferror(fp)) {
			perror("fread");
		} else {
			fprintf(stderr, "ERROR: EOF while reading from wordlist");
			exit(EXIT_FAILURE);
		}
	}
	
	word = strtok(wordlist, "\n");
	while (word != NULL) {
		add_vector(v, word);
		word = strtok(NULL, "\n");
	}
	return v;
}
