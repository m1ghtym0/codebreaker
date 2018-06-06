#include "mpi-layer.h"

int mpi_start (int argc, char* argv[]) {
	int rank, size;

  	MPI_Init(&argc, &argv);      /* starts MPI */
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);        /* get current process id */
	MPI_Comm_size(MPI_COMM_WORLD, &size);        /* get number of processes */

	printf("Process %d of %d: Hello!\n", rank, size);
	node_logic(rank);

	//TODO: Signal handler for soft abort
	MPI_Abort(MPI_COMM_WORLD, 0);

	MPI_Finalize();
  	return 0;
}

void node_logic (int rank) {
	
	return;
}
