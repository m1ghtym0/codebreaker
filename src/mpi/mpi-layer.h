#ifndef MPI_INIT_H_
#define MPI_INIT_H_

#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>
#include <sys/wait.h>

int mpi_start(int, char*[]);
void node_logic(int);
#endif
