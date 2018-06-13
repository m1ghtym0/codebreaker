#include <stdlib.h>
#include <stdio.h>
#include "distribution.h"

/*
	Distribution:
	e.g.: 11 elements and 3 processes:
		1.Process: element index 0-2
		2.Process: element index 3-5
		3.Process: element index 6-10
*/

void distribution(vector* v, vector* dist_vector, int rank, int size) {
	int i, start_index, end_index;
	init_vector(dist_vector);

	if (rank < total_vector(v)) {
		if(size >= total_vector(v)) {
			add_vector(dist_vector, get_vector(v, rank));
		} else {
			start_index = (total_vector(v) / size) * rank;

			if (rank == size - 1) {
				//last process collects last elements
				end_index = total_vector(v);
			} else {
				end_index = start_index + (total_vector(v) / size);
			}

			for (i = start_index; i < end_index; i++) {
        	        	add_vector(dist_vector, get_vector(v, i));
        		}
		}
	}
}
