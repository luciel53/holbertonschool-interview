#include <stdio.h>
#include <stdlib.h>
#include "menger.h"

/**
 * menger - function that draws a 2D Menger Sponge
 * @level: the level
 * Return: a sponge
 */

void menger(int level)
{
	int i, j, n, espace, k, itemp, jtemp;

	n = level;
	level = 1;

	for (i = 0; i < n; i++)
	{
		level *= 3;
	}

	for (i = 0; i < level; i++)
	{
		for (j = 0; j < level; j++)
		{
			espace = 0;
			itemp = i;
			jtemp = j;
			for (k = 0; k < n; k++)
			{
				if (itemp % 3 == 1 && jtemp % 3 == 1 && espace == 0)
				{
					putchar(' ');
					espace = 1;
				}
				itemp /= 3;
				jtemp /= 3;
			}
			if (espace == 0)
			{
				putchar(35);
			}
		}
		putchar(10);
	}
}
