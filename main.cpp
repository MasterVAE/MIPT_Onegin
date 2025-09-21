#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "code/sorting.h"
#include "code/array.h"


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

    printf("Sorting...\n");
    // вставляем str_cmp или str_rcmp
    sort((void*)text, count, sizeof(Line), str_rcmp);

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