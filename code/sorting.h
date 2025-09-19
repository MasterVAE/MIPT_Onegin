#ifndef SORTING_H_
#define SORTING_H_

#include <stdio.h>

// FIXME typedef compare
void sort(void* data, size_t num, size_t size, int (*compare)(const void*, const void*));
void swap(char** matrix, size_t y1, size_t y2);
void bubble_sort(char** text, size_t count);
int str_cmp(const void* str1, const void* str2);
int str_rcmp(const void* str1, const void* str2);

#endif