#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "code/sorting.h"
#include "code/array.h"

typedef struct Data{
    char *buffer;
    size_t size;
    Line* text;
    size_t count;
} Data;

int main()
{
    const char *input_file_name = "files/hamlet.txt";
    const char *output_file_name = "files/output.txt";

    printf("Starting...\n");

    Data data = {NULL, 0, NULL, 0};
    
    printf("Initializing...\n");

    FILE *input_file = fopen(input_file_name, "r");
    assert(input_file != NULL);
    data.size = file_len(input_file);

    initialize_buffer(&data.buffer, &data.size, input_file);
    fclose(input_file);
    data.count = initialize_text(&data.text, data.buffer, data.size);

    printf("Sorting...\n");
    // вставляем str_cmp или str_rcmp
    sort((void*)data.text, data.count, sizeof(Line), str_rcmp);

    printf("Printing...\n");
    FILE *output_file = fopen(output_file_name, "w");
    print(data.text, data.count, output_file);
    fclose(output_file);

    printf("Freeing...\n");
    free(data.text);
    free(data.buffer);
    printf("Ended...\n");

    return 0;
}