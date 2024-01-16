#include <stdio.h>

/**
 * advanced_binary - Searches for a value in a sorted array of integers.
 * @array: A pointer to the first element of the array to search in.
 * @size: number of elements in array.
 * @value: value we re search for.
 *
 * Return: The index where value is located, or -1 if not present.
 */
int advanced_binary(int *array, size_t size, int value)
{
    size_t i, mid;
    int result;

    if (array == NULL || size == 0)
        return -1;

    printf("Searching in array: ");
    for (i = 0; i < size; i++)
    {
        printf("%d", array[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("\n");

    mid = (size - 1) / 2;
    if (array[mid] == value)
    {
        if (size == 1 || array[mid - 1] < value)
            return mid;
    }

    if (array[mid] < value)
    {
        result = advanced_binary(array + mid + 1, size - (mid + 1), value);
        if (result == -1)
            return -1;
        return mid + 1 + result;
    }

    return advanced_binary(array, mid, value);
}
