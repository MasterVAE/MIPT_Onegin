#ifndef ARRAY
#define ARRAY

#include <stdio.h>

void initialize_buffer(char** buffer, size_t* size, FILE* input_file, size_t file_size);
size_t initialize_text(char*** text, char* buffer, size_t size);
void print(char** matrix, size_t sizeY, FILE* file);

#endif