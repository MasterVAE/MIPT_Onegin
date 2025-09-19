#include <ctype.h>
#include <stdlib.h>
#include <assert.h>

#include "array.h"

void print(char** text, size_t size, FILE* file)
{ 
    assert(text != NULL);
    assert(file != NULL);

    for(size_t y = 0; y < size; y++)
    {
        fprintf(file, "[%lu] ", y);
        int i = 0;
        char c;
        while((c = text[y][i++]) != '\n' && c != '\0') putc(c, file);

        putc('\n', file);

    }
    putc('\n', file);
}

void initialize_buffer(char** buffer, size_t* size, FILE* input_file, size_t file_size)
{
    assert(buffer != NULL);
    assert(size != NULL);
    assert(input_file != NULL);

    char* buff = (char*)calloc(file_size + 1, sizeof(char));
    size_t len = fread(buff, sizeof(char), file_size, input_file);

    buff[len] = '\0';

    printf("File size: %lld\n", (long long)file_size);
    printf("Buffer size: %lu\n", len);

    *size = len;
    *buffer = buff;
}

size_t initialize_text(char*** text, char* buffer, size_t size)
{
    assert(text != NULL);
    assert(buffer != NULL);
    
    size_t count = 1;
    for(size_t i = 0; i < size-1; i++)
    {
        if(buffer[i] == '\n')
        {
            count++;
        }
    }

    *text = (char**)calloc(count, sizeof(char*));
    assert(*text != NULL);

    (*text)[0] = buffer;

    size_t j = 1;
    for(size_t i = 0; i < size-1; i++)
    {
        if(buffer[i] == '\n')
        {       
            (*text)[j++] = buffer+i+1;
        }
    }

    return count;
}