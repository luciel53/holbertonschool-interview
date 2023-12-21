#include <stdio.h>
#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
size_t n;
/**
 * heapify - Heapify a subtree rooted at index 'root' in the array
 * @array: Array to be sorted
 * @size: Size of the array
 * @root: Index of the root of the subtree
 */
void heapify(int *array, size_t size, size_t root) {
    size_t largest = root;
    size_t left = 2 * root + 1;
    size_t right = 2 * root + 2;

    if (left < size && array[left] > array[largest])
        largest = left;

    if (right < size && array[right] > array[largest])
        largest = right;

    if (largest != root) {
        swap(&array[root], &array[largest]);
        print_array(array, n);
        heapify(array, size, largest);
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap Sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size) {
    size_t i;

	n = size;

	if (array == NULL)
		return;

    /* Build heap (rearrange array) */
    for (i = size / 2; i > 0; i--) {
        heapify(array, size, i - 1);
    }

    /* One by one extract an element from heap */
    for (i = size - 1; i > 0; i--) {
        /* Move current root to end */
        swap(&array[0], &array[i]);
        print_array(array, n);
        /* Call max heapify on the reduced heap */
        heapify(array, i, 0);
    }
}
