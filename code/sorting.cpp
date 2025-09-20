#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

#include "sorting.h"
#include "array.h"

int str_cmp(const void* s1, const void* s2)
{
    assert(s1 != NULL);
    assert(s2 != NULL);

    const Line* line1 = (const Line*)s1;
    const Line* line2 = (const Line*)s2;

    const char* str1 = line1->str;
    const char* str2 = line2->str;

    size_t i1 = 0;
    size_t i2 = 0;
    while(str1[i1] == ' ')
    {
        i1++;
    }
    while(str2[i2] == ' ')
    {
        i2++;
    }
    while(1)
    {
        while(!isalnum(str1[i1]) && str1[i1] != ' ' && str1[i1] != '\n')
        {
            i1++;
        }
        while(!isalnum(str2[i2]) && str2[i2] != ' ' && str2[i2] != '\n')
        {
            i2++;
        }
        if(str1[i1] == '\n' || str2[i2] == '\n')
        {
            return str1[i1] - str2[i2];
        }
        else
        {
            char c1 = str1[i1];
            char c2 = str2[i2];

            if(isalpha(c1)) c1 = tolower(c1);
            if(isalpha(c2)) c2 = tolower(c2);

            if(c1 != c2)
            {
                return c1-c2;
            }
            else
            {
                i1++;
                i2++;
            }
        }
    }
}

int str_rcmp(const void* s1, const void* s2)
{
    assert(s1 != NULL);
    assert(s2 != NULL);

    const Line* line1 = (const Line*)s1;
    const Line* line2 = (const Line*)s2;

    const char* str1 = line1->str;
    const char* str2 = line2->str;

    int i1 = line1->lenght - 1;
    int i2 = line2->lenght - 1;


    if(i1 < 0)
    {
        if(i2 < 0)
        {
            return 0;
        } 
        return -1;
    }
    if(i2 < 0)
    {
        return 1;
    } 

    while(str1[i1] == ' ' && i1 > 0)
    {
        i1--;
    }
    while(str2[i2] == ' ' && i2 > 0)
    {
        i2--;
    }
    while(1)
    {
        while(!isalnum(str1[i1]) && str1[i1] != ' ' && i1 > 0)
        {
            i1--;
        }
        while(!isalnum(str2[i2]) && str2[i2] != ' ' && i2 > 0)
        {
            i2--;
        }

        if(i1 < 0)
        {
            if(i2 < 0)
            {
                return 0;
            } 
            return -1;
        }
        if(i2 < 0)
        {
            return 1;
        } 

        if(i1 == 0 || i2 == 0)
        {
            return str1[i1] - str2[i2];
        }
        else
        {
            char c1 = str1[i1];
            char c2 = str2[i2];

            if(isalpha(c1)) c1 = tolower(c1);
            if(isalpha(c2)) c2 = tolower(c2);

            if(c1 != c2)
            {
                return c1-c2;
            }
            else
            {
                i1--;
                i2--;
            }
        }
    }
}

void bubble_sort(char** text, size_t count)
{
    assert(text != NULL);

    for(size_t iter = 0; iter < count-1; iter++)
    {
        for(size_t i = 0; i < iter; i++)
        {
            if(str_cmp((void*)(text[i]), (void*)(text[i+1])) > 0)
            {
                swap(text, i, i+1);
            }
        }
    }
}

void swap(char** matrix, size_t y1, size_t y2)
{
    assert(matrix != NULL);

    char* buffer;
    buffer = matrix[y1];
    matrix[y1] = matrix[y2];
    matrix[y2] = buffer;
}

void sort(void* data, size_t num, size_t size, int (*compare)(const void*, const void*))
{
    assert(data != NULL);

    if(num == 0 || num == 1)
    {
        return;
    }

    void* data_sm = (void*)calloc(num-1, size);
    void* data_bg = (void*)calloc(num-1, size); 

    assert(data_sm != NULL);
    assert(data_bg != NULL);

    size_t num_sm = 0;
    size_t num_bg = 0;

    void* middle = (void*)calloc(1, size);

    memcpy(middle, data, size);

    for(size_t i = 1; i < num; i++)
    {
        if(compare(data + i * size, middle) < 0)
        {       
            memcpy(data_sm + num_sm * size, data + i * size, size);
            num_sm++;
        }
        else
        {
            memcpy(data_bg + num_bg * size, data + i * size, size);
            num_bg++;
        }
    }

    sort(data_sm, num_sm, size, compare);
    sort(data_bg, num_bg, size, compare);

    size_t global_counter = 0;

    for(size_t i = 0; i < num_sm; i++)
    {
        memcpy(data + global_counter * size, data_sm+i * size, size);
        global_counter++;
    }
    memcpy(data + global_counter * size, middle, size);
    global_counter++;
    for(size_t i = 0; i < num_bg; i++)
    {
        memcpy(data + global_counter * size, data_bg + i * size, size);
        global_counter++;
    }

    free(data_sm);
    free(data_bg);
}