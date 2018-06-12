#include <stdio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include"mpi/mpi-layer.h"

void usage(char *argv[]) {
    fprintf(stderr, "Usage: %s -w <wordlist> -p <passlist>\n", argv[0]);
}
int main(int argc, char* argv[]) {
	char *wordlist = NULL;
	char *passlist = NULL;
	char c;

	opterr = 0;

	while ((c = getopt (argc, argv, "w:p:")) != -1) {
		switch (c) {
			case 'w':
				wordlist = optarg;
				break;
			case 'p':
				passlist = optarg;
				break;
			case '?':
				if (optopt == 'w' || optopt == 'p') {
					fprintf (stderr, "Option -%c requires an argument.\n", optopt);
				} else if (isprint (optopt)) {
					fprintf (stderr, "Unknown option `-%c'.\n", optopt);
				} else {
					fprintf (stderr,"Unknown option character `\\x%x'.\n", optopt);
				}
			exit(EXIT_FAILURE);
			break;
			default:
				exit(EXIT_FAILURE);
		}
	}

	if (wordlist == NULL || passlist == NULL) {
		usage(argv);
		exit(EXIT_FAILURE);
	}

	//MPI TESTER
	mpi_start(argc, argv, wordlist, passlist);
	return 0;
}
