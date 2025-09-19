#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/stat.h>

#include "code/sorting.h"
#include "code/array.h"

int main()
{
    const char *input_file_name = "files/hamlet.txt";
    const char *output_file_name = "files/output.txt";

    printf("Starting...\n");

    char *buffer;
    size_t size;
    char **text;
    size_t count;

    printf("Initializing...\n");
    struct stat file_info;
    FILE *input_file = fopen(input_file_name, "r");
    stat(input_file_name, &file_info);

    assert(input_file != NULL);

    initialize_buffer(&buffer, &size, input_file, (size_t)file_info.st_size);
    fclose(input_file);
    count = initialize_text(&text, buffer, size);

    printf("Sorting...\n");
    // вставляем str_cmp или str_rcmp
    sort(text, count, str_cmp);

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