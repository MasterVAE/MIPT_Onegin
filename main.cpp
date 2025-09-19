#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "code/sorting.h"
#include "code/array.h"

int int_cmp(const void* s1, const void* s2)
{
    assert(s1 != NULL);
    assert(s2 != NULL);

    const int* ip1 = (const int*)s1;
    const int* ip2 = (const int*)s2;

    return *ip1 - *ip2;
}

int main()
{
    const char *input_file_name = "files/hamlet.txt";
    const char *output_file_name = "files/output.txt";

    printf("Starting...\n");

    // FIXME struct + init
    char *buffer;
    size_t size;
    Line* text;
    size_t count;

    printf("Initializing...\n");

    FILE *input_file = fopen(input_file_name, "r");
    assert(input_file != NULL);
    size = file_len(input_file);

    initialize_buffer(&buffer, &size, input_file);
    fclose(input_file);
    count = initialize_text(&text, buffer, size);

    // int to_sort[6] = {10, 15, 13, 14, 7, 676};
    // printf("%d %d %d %d %d %d\n", to_sort[0], to_sort[1], to_sort[2], to_sort[3], to_sort[4], to_sort[5]);
    // sort(to_sort, 6, sizeof(int), int_cmp);
    // printf("%d %d %d %d %d %d\n", to_sort[0], to_sort[1], to_sort[2], to_sort[3], to_sort[4], to_sort[5]);


    printf("Sorting...\n");
    // вставляем str_cmp или str_rcmp
    sort((void*)text, count, sizeof(Line), str_cmp);

    printf("Printing...\n");
    FILE *output_file = fopen(output_file_name, "w");
    print(text, count, output_file);
    fclose(output_file);

    printf("Freeing...\n");
    free(text);
    free(buffer);

    printf("Ended...\n");

    return 0;
}