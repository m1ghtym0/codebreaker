#include <stdlib.h>
#include <stdio.h>
#include "input/vector.h"
#include "permutation.h"

/*
	Permutation:
	e.g.: 11 elements and 3 processes:
		1.Process: element index 0-2
		2.Process: element index 3-5
		3.Process: element index 6-10
*/

void permutation(vector* v, vector* perm_vector, int rank, int size) {
	int i;
	int start_index = (total_vector(v) / size) * rank;
	int end_index;

	if(rank == size - 1) {
		//last process collects last elements
		end_index = total_vector(v);
	} else {
		end_index = start_index + (total_vector(v) / size);
	}

	init_vector(perm_vector);

	for(i = start_index; i < end_index; i++) {
		add_vector(perm_vector, get_vector(v, i));
	}
}
