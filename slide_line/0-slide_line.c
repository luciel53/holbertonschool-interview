#include <stdlib.h>
#include <stdio.h>

#include "slide_line.h"

/**
 * slide_line -
 *
 */

int slide_line(int *line, size_t size, int direction)
{
	int number;
	unsigned int i, k, m;
	int j;
	int list[size];

	for (i = 0; i < size; i++)
	{
		list[i] = 0;
	}

	j = 0;
	for (i = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			number = line[i];
			for (k = i+1; k < size; k++)
			{
				i++;
				if (line[k] == number)
				{
					list[j] = number * 2;
					j++;
					break;
				}
				else if (line[k] == 0)
				{
					continue;
				}
				else
				{
					i--;
					break;
				}
			}
		}

	}


	for (m = 0; m < size; m++)
	{

		printf("%d ", line[m]);
	}
	printf("\n");
	for (m = 0; m < size; m++)
	{
		printf("%d ", list[m]);
	}
	printf("\n");
	for (m = 0; m < size; m++)
	{
		line[m] = list[m];
		i = direction;
	}
	return(1);
}
