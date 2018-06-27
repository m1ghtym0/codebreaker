#ifndef PERMUTATION_H_
#define PERMUTATION_H_

#include "../../src/input/input.h"

struct perm_list {
	char *str;
	struct perm_list *next;
};
typedef struct perm_list perm_list;


vector *permute(char*, vector*);
#endif
