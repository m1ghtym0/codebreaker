#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../src/permutation/permutation.h"

int main (void) {
	vector wordlist, *perms;

	init_vector(&wordlist);
	add_vector(&wordlist, "Anton");
	add_vector(&wordlist, "Bastian");
	add_vector(&wordlist, "Christoph");
	add_vector(&wordlist, "Dieter");
	add_vector(&wordlist, "Emil");
	add_vector(&wordlist, "Fritz");
	add_vector(&wordlist, "Gustaf");
	add_vector(&wordlist, "Hans");
	add_vector(&wordlist, "Peter");

	if ((perms = permute("%s.%d.%s", &wordlist)) == NULL) {
        return EXIT_FAILURE;
    }
	print_vector(perms);
	return EXIT_SUCCESS;
}
