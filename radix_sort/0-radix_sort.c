#include "sort.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * getMax - Utility function to get the maximum value in an array
 * @array: The array to find the maximum value from
 * @size: Size of the array
 * Return: The maximum value in the array
 */
int getMax(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * countSort - A function to do counting sort of array according to
 * the digit represented by exp.
 * @array: The array to be sorted
 * @size: Size of the array
 * @exp: The exponent representing the significant digit
 */
void countSort(int *array, size_t size, int exp)
{
	int *output = malloc(sizeof(int) * size);
	int count[10] = {0};
	size_t i;
	int j;

	/* Store count of occurrences in count[] */
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;
	/* Change count[i] so that count[i] now contains */
	/* actual position of this digit in output[] */
	for (j = 1; j < 10; j++)
		count[j] += count[j - 1];
	/* Build the output array */
	for (j = size - 1; j >= 0; j--)
	{
		output[count[(array[j] / exp) % 10] - 1] = array[j];
		count[(array[j] / exp) % 10]--;
	}

	/* Copy the output array to array[], so that array[] now */
	/* contains sorted numbers according to the current digit */
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(output);
}

/**
* radix_sort - sorts an array of integers in ascending order
* using the Radix sort algorithm
* @array: The array to be sorted
* @size: Size of the array
*/
void radix_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	int max = getMax(array, size);
	/* Do counting sort for every digit */
	for (int exp = 1; max / exp > 0; exp *= 10)
	{
		countSort(array, size, exp);
		print_array(array, size); /* Print array after each significant digit*/
	}
}
