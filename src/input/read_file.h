#ifndef READ_FILE_H_
#define READ_FILE_H_

#include <stdio.h>
#include"vector.h"

FILE* open_file (char *file_name, size_t *size);
vector *index_file (FILE* fp, size_t size);

#endif
