#include <ctype.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/stat.h>

#include "array.h"

void print(Line* text, size_t size, FILE* file)
{ 
    assert(text != NULL);
    assert(file != NULL);

    for(size_t y = 0; y < size; y++)
    {
        fprintf(file, "[%lu] [%lu] ", y, text[y].lenght);
        int i = 0;
        char c;
        short unspace = 0;
        while((c = text[y].str[i++]) != '\n' && c != '\0')
        { 
            if(c != ' ')
            {
                unspace = 1;
                putc(c, file);
            }
            else
            {
                if(unspace)
                {
                    putc(c, file);
                }
            }
            
        }

        putc('\n', file);

    }
    putc('\n', file);
}

void initialize_buffer(char** buffer, size_t* size, FILE* input_file)
{
    assert(buffer != NULL);
    assert(size != NULL);
    assert(input_file != NULL);

    char* buff = (char*)calloc(*size + 1, sizeof(char));
    size_t len = fread(buff, sizeof(char), *size, input_file);

    buff[len] = '\0';

    printf("File size: %lu\n", *size);
    printf("Buffer size: %lu\n", len);

    *size = len;
    *buffer = buff;
}

size_t initialize_text(Line** text, char* buffer, size_t size)
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

    *text = (Line*)calloc(count, sizeof(Line));
    assert(*text != NULL);

    (*text)[0].str = buffer;

    size_t j = 1;
    for(size_t i = 0; i < size-1; i++)
    {
        if(buffer[i] == '\n')
        {       
            (*text)[j].str = buffer+i+1;
            (*text)[j-1].lenght = (size_t)((*text)[j].str - (*text)[j-1].str)-1;
            j++;
        }
    }
    (*text)[count-1].lenght = size - (size_t)((*text)[count-1].str - (*text)[0].str);

    return count;
}

size_t file_len(FILE* file)
{
    struct stat file_info;
    fstat(fileno(file), &file_info);
    return (size_t)file_info.st_size;
}