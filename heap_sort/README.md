Description:

Sorts an array of integers in ascending order using the Heap Sort algorithm.
Algorithm:

    Build a max heap from the array.
    Repeatedly extract the maximum element from the heap and swap it with the last unsorted element.
    Heapify the reduced heap.

Example:

c

#include <stdio.h>

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    heap_sort(arr, size);

    printf("\nSorted array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
