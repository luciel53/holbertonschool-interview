#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stdlib.h>
#include <stdio.h>

void print_array(const int *array, size_t size);
void heapify(int *array, size_t size, size_t root);
void swap(int *a, int *b);
void heap_sort(int *array, size_t size);

#endif /* _BINARY_TREES_H_ */
