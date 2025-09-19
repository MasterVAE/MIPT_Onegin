#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void initialize(char **matrix, size_t sizeY, size_t sizeX);
void print(char **matrix, size_t sizeY);
void swap(char **matrix, int y1, int y2);

int main()
{
    const size_t sizeX = 10, sizeY = 10;
    char **text = (char **)calloc(sizeY, sizeof(char *));
    print(text, sizeY);
    initialize(text, sizeY, sizeX);
    print(text, sizeY);
    printf("strcmp: %d\n\n", strcmp(text[2], text[4]));
    swap(text, 2, 4);
    print(text, sizeY);

    return 0;
}

void print(char **matrix, size_t sizeY)
{
    assert(matrix != NULL);

    for(int y = 0; y < sizeY; y++)
    {
        printf("[%d] %s \n", y, matrix[y]);
    }
    printf("\n");
}

void initialize(char **matrix, size_t sizeY, size_t sizeX)
{
    assert(matrix != NULL);

    int c = 0;
    for(int y = 0; y < sizeY; y++)
    {
        matrix[y] = (char *)calloc(sizeX, sizeof(char));

        assert(matrix[y] != NULL);

        for(int x = 0; x < sizeX-1; x++)
        {
            matrix[y][x] = c + 'a';
            c++;
            c %= 25;
        }
        matrix[y][sizeX - 1] = '\0';
    }
}

void swap(char **matrix, int y1, int y2)
{
    assert(matrix != NULL);

    char *buffer;
    buffer = matrix[y1];
    matrix[y1] = matrix[y2];
    matrix[y2] = buffer;
}