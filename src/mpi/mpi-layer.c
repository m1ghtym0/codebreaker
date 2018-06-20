#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

#include "mpi-layer.h"
#include "../input/input.h"
#include "../distribution/distribution.h"
#include "../cracker/cracker.h"

#define ROOT 0
#define DONE_MSG 1

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
	int hash_size, w, h, done_cnt;
	hash_element *hashes;
	
	MPI_Request request;
	MPI_Status status;
	int status_flag;
	
	int *done_map, *found_win;

	word_fp = open_file(wlist, &file_size);
	words = index_file(word_fp, file_size);
	distribution(words, &words_dist, rank, size);

	pass_fp = open_file(plist, &file_size);
	pass = index_file(pass_fp, file_size);

	if ((hashes = parse_passfile(pass, &hash_size)) == NULL ) {
		exit(EXIT_FAILURE);
	}
   
	// Flag for each hash indicating that it was already found
	if ((done_map = calloc(hash_size, sizeof(int))) == NULL) {
		perror("calloc");
		MPI_Abort(MPI_COMM_WORLD, errno);
	}
	
	// Window for found hashes, so we never have to wait
	if ((found_win = calloc(hash_size, sizeof(int))) == NULL) {
		perror("calloc");
		MPI_Abort(MPI_COMM_WORLD, errno);
	}
	
	for (w = 0; w < total_vector(&words_dist); w++) {
		if (rank == ROOT) { // check if new hash was found
			while (MPI_Iprobe(MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status_flag, &status) == 0 && status_flag) {
				//printf("NODE[%d]: Got msg!\n", rank);
				MPI_Irecv(&done_map[status.MPI_TAG], 1, MPI_INTEGER, status.MPI_SOURCE, status.MPI_TAG, MPI_COMM_WORLD, &request);
				//printf("NODE[%d]: Received: hash[%d] is done!\n", rank, status.MPI_TAG);
				MPI_Ibcast(done_map, hash_size, MPI_INTEGER, ROOT, MPI_COMM_WORLD, &request); 
			}
		} else {
			MPI_Ibcast(done_map, hash_size, MPI_INTEGER, ROOT, MPI_COMM_WORLD, &request);
			
			//if (MPI_Ibcast(done_map, hash_size, MPI_INTEGER, ROOT, MPI_COMM_WORLD, &request) != MPI_SUCCESS) {
			//	  printf("NODE[%d]: Broadcast-Recv Error\n", rank);
			//}
			//MPI_Test(&request, &status_flag, &status);
			//if (status_flag) {
			//	  printf("NODE[%d]: Received Broadcast\n", rank);
			//}
		}
		done_cnt = 0;
		for (h = 0; h < hash_size; h++) {
			if (done_map[h]) {
				//printf("NODE[%d]: hashes[%d] already done!\n", rank, h);
				done_cnt++;
				if (done_cnt == hash_size) {
					return;
				}
				continue;
			}
			done_cnt = 0;
			if (check_pass (&hashes[h].ctx, get_vector(&words_dist, w), hashes[h].salt, hashes[h].hash)) {
				found_win[h] = 1;
				done_map[h] = 1;
				MPI_Ibsend(&found_win[h], 1, MPI_INTEGER, ROOT, h, MPI_COMM_WORLD, &request); 
				printf("NODE[%d]: |%s|%s|%s|\n", rank, hashes[h].salt, get_vector(&words_dist, w), hashes[h].hash);
			}
		}
	}


	//DEBUGGIN info
	//printf("Prozess %d hat %d Woerter.\n", rank, total_vector(&words_dist));
}
