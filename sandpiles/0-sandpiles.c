# include <stdlib.h>
# include <stdio.h>

# include "sandpiles.h"

/**
* print_grid - Print a 3 x 3 grid
* @grid: The grid to print
**/

static void print_grid(int grid[3][3])
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
 * sandpile_topple - Redistributes grains in grid1, stabilizing pile in grid2
 * @grid2: Right 3x3 grid
 * Return: a pointer to grid2
**/

int (*sandpile_topple(int grid1[3][3], int grid2[3][3]))[3]
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				if (i - 1 >= 0)
				{
					if (grid1[i - 1][j] <= 3)
					{
						grid2[i][j] -= 1;
						grid2[i - 1][j] += 1;
					}
				}
				else
				{
					grid2[i][j] -= 1;
				}
				if (j - 1 >= 0)
				{
					if (grid1[i][j - 1] <= 3)
					{
						grid2[i][j] -= 1;
						grid2[i][j - 1] += 1;
					}
				}
				else
				{
					grid2[i][j] -= 1;
				}
				if (i + 1 < 3)
				{
					if (grid1[i + 1][j] <= 3)
					{
						grid2[i][j] -= 1;
						grid2[i + 1][j] += 1;
					}
				}
				else
				{
					grid2[i][j] -= 1;
				}
				if (j + 1 < 3)
				{
					if (grid1[i][j + 1] <= 3)
					{
						grid2[i][j] -= 1;
						grid2[i][j + 1] += 1;
					}
				}
				else
				{
					grid2[i][j] -= 1;
				}
			}
		}
	}
	return (grid2);
}

/**
	* sandpiles_sum - computes 2 sandpiles
	* @grid1: first grid
	* @grid2: second grid
	* Return: void
**/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	int print = 0;
	int stable = 1;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid2[i][j] != 0)
			{
				stable = 0;
				grid1[i][j] += grid2[i][j];
				grid2[i][j] = 0;
			}

			if (grid1[i][j] > 3)
			{
				print = 1;
			}
		}
	}

	if (!stable)
	{
		if (print)
		{
			printf("=\n");
			print_grid(grid1);
		}
		sandpiles_sum(grid1, sandpile_topple(grid1, grid2));
	}
}
