#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>
#include <sys/wait.h>

#include "mpi-layer.h"
#include "../input/input.h"
#include "../distribution/distribution.h"
#include "../cracker/cracker.h"

int mpi_start (int argc, char* argv[], char *wlist, char *plist) {
	int rank, size;

	MPI_Init(&argc, &argv);		 /* starts MPI */
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);		 /* get current process id */
	MPI_Comm_size(MPI_COMM_WORLD, &size);		 /* get number of processes */

	node_logic(rank, size, wlist, plist);

	//TODO: Signal handler for soft abort
	//MPI_Abort(MPI_COMM_WORLD, 0);

	MPI_Finalize();
	return 0;
}

void node_logic (int rank, int size, char *wlist, char *plist) {
	FILE *word_fp, *pass_fp;
	vector *words, words_dist, *pass;
	size_t file_size;
	int hash_size, w, h;
	hash_element *hashes;

	word_fp = open_file(wlist, &file_size);
	words = index_file(word_fp, file_size);
	distribution(words, &words_dist, rank, size);

	pass_fp = open_file(plist, &file_size);
	pass = index_file(pass_fp, file_size);

	 if ((hashes = parse_passfile(pass, &hash_size)) == NULL ) {
		exit(EXIT_FAILURE);
	}

	for (w = 0; w < total_vector(&words_dist); w++) {
		for (h = 0; h < hash_size; h++) {
			if (hashes[h].done) {
				continue;
			}
			if (check_pass (&hashes[h].ctx, get_vector(&words_dist, w), hashes[h].salt, hashes[h].hash)) {
				hashes[h].done = 1;
				printf("PID[%d]: (%s)%s == %s.\n", rank, hashes[h].salt, get_vector(&words_dist, w), hashes[h].hash);
			}
		}
	}


	//DEBUGGIN info
	printf("Prozess %d hat %d Woerter.\n", rank, total_vector(&words_dist));
}
