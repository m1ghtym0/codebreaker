#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "permutation.h"

vector *expand_int (vector *v, char *str) {
	int i;
	char *new_str;

	for (i = 0; i < 10; i++) {
		if (asprintf(&new_str, "%s%d", str, i) < 0) {
			perror("asprintf");
			return NULL;
		}
		add_vector(v, new_str);
	}
	return v;
}

vector *expand_str (vector *v, char *str, vector *wordlist) {
	int i;
	char *new_str;
	
	for (i = 0; i < total_vector(wordlist); i++) {
		if (asprintf(&new_str, "%s%s", str, get_vector(wordlist, i)) < 0) {
			perror("asprintf");
			return NULL;
		}
		add_vector (v, new_str);
	}
	return v;
}

vector *expand_chr (vector *v, char *str, char c) {
	char *new_str;
	
	if (asprintf(&new_str, "%s%c", str, c) < 0) {
		perror("asprintf");
		return NULL;
	}
	add_vector(v, new_str);
	return v;
}


vector *rec_perm (vector *in, char *fmt, vector *wordlist) {
	int i;
	vector *out, *ret;
	char *new_fmt;
	
	if (!strlen(fmt)) {
		return in;
	}

	if ((out = calloc(1, sizeof(vector))) == NULL) {
		perror("calloc");
		return NULL;
	}
	
	init_vector(out);
	
	if (strlen(fmt) == 1 || fmt[0] != '%' || (fmt[1] != 's' && fmt[1] != 'd')) {
		for (i = 0; i < total_vector(in); i++) {
			if ((ret = expand_chr(out, get_vector(in, i), fmt[0])) == NULL) {
				return NULL;
			}
		}
		new_fmt = fmt + 1;
	} else if (fmt[1] == 'd') {
		for (i = 0; i < total_vector(in); i++) {
			if ((ret = expand_int(out, get_vector(in, i))) == NULL) {
				return NULL;
			}
		}	
		new_fmt = fmt + 2;
	} else if (fmt[1] == 's') {
		for (i = 0; i < total_vector(in); i++) {
			if ((ret = expand_str(out, get_vector(in, i), wordlist)) == NULL) {
				return NULL;
			}
		}
		new_fmt = fmt + 2;
	} else {
		/* This should never happen! */
		return NULL;
	}
	free_vector(in);
	return rec_perm(out, new_fmt, wordlist);

}

vector *permute (char* fmt, vector *wordlist) {
	vector *init, *perm_words;

	if ((init = calloc(1, sizeof(vector))) == NULL) {
		perror("calloc");
		return NULL;
	}

	init_vector(init);
	add_vector(init, strdup(""));
	perm_words = rec_perm(init, fmt, wordlist);

	return perm_words;
}
