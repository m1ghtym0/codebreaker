#ifndef VECTOR_H
#define VECTOR_H

typedef struct vector {
	char** items;
	int capacity;
	int total;
} vector;

void init_vector(vector*);
int total_vector(vector*);
void resize_vector(vector*, int);
void add_vector(vector*, char*);
char* get_vector(vector*, int);
void free_vector(vector*);
void print_vector(vector*);
#endif
