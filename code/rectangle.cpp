#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void initialize_rectangle(char *matrix, size_t sizeY, size_t sizeX);
void print_rectangle(char *matrix, size_t sizeY, size_t sizeX);
void swap_rectangle(char *matrix, size_t sizeY, size_t sizeX, int y1, int y2);

int main()
{
    const size_t sizeX = 10, sizeY = 10;
    char text[sizeY][sizeX];

    print_rectangle((char *)text, sizeY, sizeX);
    initialize_rectangle((char *)text, sizeY, sizeX);
    print_rectangle((char *)text, sizeY, sizeX);
    printf("strcmp: %d\n\n", strcmp(text[2], text[4]));
    swap_rectangle((char *)text, sizeY, sizeX, 2, 4);
    print_rectangle((char *)text, sizeY, sizeX);

    return 0;
}

void print_rectangle(char *matrix, size_t sizeY, size_t sizeX)
{
    assert(matrix != NULL);

    char c;
    for(int y = 0; y < sizeY; y++)
    {
        printf("[%d]", y);
        for(int x = 0; x < sizeX; x++)
        {
            c = matrix[y * sizeX + x];
            if(c != '\0')
            {
                putc(c, stdout);
            }
            else
            {
                break;
            }
            
        }
        printf("\n");
    }
    printf("\n");
}

void initialize_rectangle(char *matrix, size_t sizeY, size_t sizeX)
{
    assert(matrix != NULL);

    int c = 0;
    for(int y = 0; y < sizeY; y++)
    {
        for(int x = 0; x < sizeX-1; x++)
        {
            matrix[y* sizeX + x] = c + 'a';
            c++;
            c %= 25;
        }
        matrix[y * sizeX + sizeX-1] = '\0';
    }
}

void swap_rectangle(char *matrix, size_t sizeY, size_t sizeX, int y1, int y2)
{
    assert(matrix != NULL);

    char buffer;
    for(int x = 0; x < sizeX; x++)
    {
        buffer = matrix[y1 * sizeX + x];
        matrix[y1 * sizeX + x] = matrix[y2 * sizeX + x];
        matrix[y2 * sizeX + x] = buffer;
    }
}