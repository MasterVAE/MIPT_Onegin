#ifndef ARRAY_H_
#define ARRAY_H_

#include <stdio.h>

typedef struct Line{

    char* str;
    size_t lenght;
} Line;

void initialize_buffer(char** buffer, size_t* size, FILE* input_file);
size_t initialize_text(Line**text, char* buffer, size_t size);
void print(Line* matrix, size_t sizeY, FILE* file);
size_t file_len(FILE* file);

#endif