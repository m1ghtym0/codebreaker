#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "read_file.h"
#include "vector.h"

FILE* reading (char file_name[]) {
	FILE *fp;
	fp = fopen(file_name, "r");

	if (fp == NULL) {
		perror("Error while opening the wordlist.\n");
      		exit(EXIT_FAILURE);
   	}

	return fp;
}

vector indexing (FILE* fp) {
	vector v;
	init_vector(&v);

	while(1) {
		char* word = (char*)malloc(20);
		if(fgets(word, 20, fp) == NULL) {
			break;
		}
		add_vector(&v, word);
	}
	return v;
}

/*
int length_file() {
	fseek(f, 0, SEEK_END);
	size = ftell(f);
	fseek(f, 0, SEEK_SET);
	return size;
}
*/
