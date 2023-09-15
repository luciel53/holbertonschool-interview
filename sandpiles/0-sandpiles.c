#include <stdlib.h>
#include <stdio.h>

#include "sandpiles.h"

void print_grid(int grid[3][3])
	{
		int i, j;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (j)
					printf(" ");
				printf("%d", grid[i][j]);
			}
			printf("\n");
		}
	}


/**
 * sandpiles_sum - function that computes the sum of two sandpiles
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 * Return: sum of two sandpiles
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	int result_grid[3][3];

	/* add the grids */
	for (i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			result_grid[i][j] = grid1[i][j] += grid2[i][j];
		}
	}

	int not_stable = 1;

	while (not_stable)
	{
		not_stable = 0;

		/* checks if result grid is stable */
		for(i = 0; i < 3; i++) {
			for(j = 0; j < 3; j++)
			{
				/* checks the neighbours */
				if(result_grid[i][j] > 3)
				{
					not_stable = 1;
					result_grid[i][j] -= 4;

					if (i - 1 >= 0)
						result_grid[i - 1][j]++;
					if (i + 1 < 3)
						result_grid[i + 1][j]++;
					if (j - 1 >= 0)
						result_grid[i][j - 1]++;
					if (j + 1 < 3)
						result_grid[i][j + 1]++;
				}
			}
		}
		if (not_stable)
		{
			printf("=\n");
			print_grid(result_grid);
		}

	};
}
