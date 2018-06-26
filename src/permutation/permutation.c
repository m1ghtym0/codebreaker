#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "permutation.h"

//void permute (char* string_format, vector* wordlist) {
void permute (char* string_format) {
	int num_of_strings = count_string("%s", string_format);
	int num_of_numbers = count_string("%d", string_format);
	int num_all = num_of_strings + num_of_numbers;
	int len = (int) strlen(string_format);
	int i;
	int counter = 0;
	char string_structure[num_all];



//////////////START WHY????????
vector* v;
init_vector(v);
add_vector(v, "f");
print_vector(v);



//////////////END


//	vector** vector_group = NULL;

	//Store the sequence of occured letter/string in array
	for (i = 0; i < len; i++){
		if(string_format[i] == '%' && ((i + 1) < len) ) {

//			vector* v;
//			init_vector(v);
//			vector_group = realloc(vector_group, sizeof(v));

			if(string_format[i + 1] == 's') {
//				store_numbers_in_vector(v);

			} else if(string_format[i + 1] == 'd') {
//				store_numbers_in_vector(v);
//				store_words_in_vector(v, wordlist);
			} else {
//				free_vector(v);
//				free(vector_group);
			}


			string_structure[counter] = string_format[i + 1];
			counter++;
		}
	}

	//START: Debug Print
	printf("strings: %d and numbers: %d\n",
                num_of_strings, num_of_numbers);

	for(i = 0; i < num_all; i++)
		printf("%c, ", string_structure[i]);
	printf("\n");

	//print_vector(wordlist);
	//END: Debug Print

//	for(i = 0; i < 3; i++)
//		print_vector(vector_group[i]);

}

void store_numbers_in_vector(vector* v) {
	int i;
	char* str=NULL;
	for(i = 0; i < 10; i++) {
		sprintf(str, "%d", i);
		add_vector(v, str);
	}
}

void store_words_in_vector(vector* v, vector* words) {
	int i;
	for(i = 0; i < total_vector(words); i++)
		add_vector(v, get_vector(words, i));
}

int count_string (char* string_to_find, char* string) {
	int count = 0;
	char * tmp = string;

	while( (tmp = strstr(tmp, string_to_find)) != NULL ) {
		count++;
		tmp++;
	}

	return count;
}
/*
void rec_perm (int all_num, int pos, vector v, 
char* word_structure


) {
	if(all_num == pos) {
		print_vector(&v);
		return;
	}

	int k;
	//TODO 2 to number of strings or numbers=10
	for(k = 0; k < ; k++) {
		rec_perm(all_num, pos + 1, v + )
	}
}


*/


/*
char* concat_words_from_vector(vector* v) {
	int i;
	char* string;
	for(i = 0; i < total_vector(v); i++) {
		concat(string, get_vector(v, i));
	}

	return string;
}
*/
