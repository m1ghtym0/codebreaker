#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

void init_vector (vector* v) {
	v->capacity = 1;
	v->total = 0;
	v->items = malloc(sizeof(char*) * v->capacity);
}

int total_vector (vector* v) {
	return v->total;
}

void resize_vector (vector* v, int capacity) {
    char **items;

	if ((items = realloc(v->items, sizeof(char*) * capacity)) != NULL) {
		v->items = items;
		v->capacity = capacity;
	} else {
		perror("realloc");
		exit(EXIT_FAILURE);
	}
}

void add_vector (vector* v, char* item) {
	size_t ln;

	//remove \n from string
	ln = strlen(item)-1;
	if (item[ln] == '\n') {
		item[ln] = '\0';
	}

	//store string in vector
	if (v->capacity == v->total) {
		resize_vector(v, v->capacity + 1);
	}
	v->items[v->total++] = item;
}

char* get_vector (vector* v, int index) {
	if (index >= 0 && index < v->total) {
		return v->items[index];
	}
	return NULL;
}

void free_vector (vector* v) {
	int i;

	for (i = 0; i < total_vector(v); i++) {
		free(get_vector(v, i));
	}
	free(v->items);
}

void print_vector(vector* v) {
	int i;

	for (i = 0; i < total_vector(v); i++) {
		printf("%s\n", get_vector(v, i));
	}
}

