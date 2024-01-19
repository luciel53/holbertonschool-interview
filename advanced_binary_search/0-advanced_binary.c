#include <stdio.h>
#include "search_algos.h"

/*
* advanced_binary - search value in the array
* @array: pointer to the first element of the array to search in
* @size: number of elements in the array
* @value: the value we're searching for
* Return: index where value is located
*/

int advanced_binary(int *array, size_t size, int value)
{
	size_t i;
	int mid;
	int res;

	if (array == NULL)
		return (-1);

	printf("Searching in array:");
	for (i = 0; i < size - 1; i++)
		printf(" %d,", array[i]);
	printf(" %d\n", array[i]);
	mid = (size + 1) / 2;
	if (array[0] == value)
		return (0);

	if (array[mid - 1] >= value)
	{
		res = advanced_binary(array, mid, value);
		if (res == -1)
			return (-1);
		return (res);
	}

	else
	{
		if (size == 1)
			return (-1);
		res = advanced_binary((array + mid), size - mid, value);
		if (res == -1)
			return (-1);
		return (res + mid);
	}

}
