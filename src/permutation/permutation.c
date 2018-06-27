#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "permutation.h"

int expand_int(perm_list *list, char *str) {
	int i;
	perm_list *cur, *next;

	cur = list;

	for (i = 0; i < 9; i++) {
		if ((next = calloc(1, sizeof(perm_list))) == NULL) {
			perror("calloc");
			return EXIT_FAILURE;
		}
		next->next = NULL;
		cur->next = next;
		cur = next;

		if (asprintf(&cur->str, "%s%d", str, i) < 0) {
			perror("asprintf");
			return EXIT_FAILURE;
		}
	}
	return EXIT_SUCCESS;
}

int expand_str(perm_list *list, char *str, vector *wordlist) {
	int i;
	perm_list *cur, *next;

	cur = list;
	for (i = 0; i < total_vector(wordlist); i++) {
		
		if ((next = calloc(1, sizeof(perm_list))) == NULL) {
			perror("calloc");
			return EXIT_FAILURE;
		}
		next->next = NULL;
		cur->next = next;
		cur = next;

		if (asprintf(&cur->str, "%s%s", str, get_vector(wordlist, i)) < 0) {
			perror("asprintf");
			return EXIT_FAILURE;
		}
	}
	return EXIT_SUCCESS;
}

int expand_chr(perm_list *list, char *str, char c) {
	perm_list *next;

	if ((next = calloc(1, sizeof(perm_list))) == NULL) {
		perror("calloc");
		return EXIT_FAILURE;
	}
	next->next = NULL;
	list->next = next;

	if (asprintf(&next->str, "%s%c", str, c) < 0) {
		perror("asprintf");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}


perm_list *rec_perm (perm_list *list, char *fmt, vector *wordlist) {
	perm_list *cur, *prev, *new_list;
	char *new_fmt;

	if (!strlen(fmt)) {
		return list;
	}

	if ((new_list = calloc(1, sizeof(perm_list))) == NULL) {
		perror("calloc");
		return NULL;
	}
	new_list->next = NULL;

	if (strlen(fmt) == 1 || fmt[0] != '%' || (fmt[1] != 's' && fmt[1] != 'd')) {
		cur = list;
		while  (cur) {
			if (expand_chr(new_list, cur->str, fmt[1]) != EXIT_SUCCESS) {
				return NULL;
			}
			prev = cur;
			cur = cur->next;
			free(prev->str);
			free(prev);
		}
		new_fmt = fmt + 1;
	} else if (fmt[1] == 'd') {
		cur = list;
		while  (cur) {
			if (expand_int(new_list, cur->str) != EXIT_SUCCESS) {
				return NULL;
			}
			prev = cur;
			cur = cur->next;
			free(prev->str);
			free(prev);
		}	
		new_fmt = fmt + 2;
	} else if (fmt[1] == 's') {
		cur = list;
		while  (cur) {
			if (expand_str(new_list, cur->str, wordlist) != EXIT_SUCCESS) {
				return NULL;
			}
			prev = cur;
			cur = cur->next;
			free(prev->str);
			free(prev);
		}
		new_fmt = fmt + 2;
	} else {
		/* This should never happen! */
		return NULL;
	}
	return rec_perm(new_list, new_fmt, wordlist);

}

vector *permute (char* fmt, vector *wordlist) {
	perm_list *cur, *prev;
	vector *perm_words;

	if ((perm_words = calloc(1, sizeof(vector))) == NULL) {
		perror("calloc");
		return NULL;
	}
	init_vector(perm_words);
	
	if ((cur = calloc(1, sizeof(perm_list))) == NULL) {
		perror("calloc");
		return NULL;
	}

	cur = rec_perm(cur, fmt, wordlist);

	while (cur) {
		add_vector(perm_words, cur->str);
		prev = cur;
		cur = cur->next;
		free(prev->str);
		free(prev);
	}
	return perm_words;
}
