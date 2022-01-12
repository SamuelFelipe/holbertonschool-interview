#include <stdio.h>
#include <stdlib.h>

#include "sandpiles.h"

/**
 * print_grids - print the grid
 * @grid: <-
 *
 * Return: none
 */

void print_grids(int grid[3][3])
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
 * sandpile_balance - balance a sandpile
 * @sandpile: <-
 * @max_cel: cell with the highest value
 *
 * Return: none
 */

void sandpile_balance(int sandpile[3][3], int max_cel)
{
	int i, j;
	int **aux = (int **)malloc(3 * sizeof(int *));

	for (i = 0; i < 3; i++)
		aux[i] = (int *)malloc(3 * sizeof(int));
	while (max_cel > 3)
	{
		printf("=\n");
		print_grid(sandpile);
		max_cel = sandpile[0][0];
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				aux[i][j] = 0;
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				if (sandpile[i][j] > 3)
				{
					aux[i][j] -= 4;

					if (i + 1 <= 2)
						aux[i + 1][j] += 1;
					if (i - 1 >= 0)
						aux[i - 1][j] += 1;
					if (j + 1 <= 2)
						aux[i][j + 1] += 1;
					if (j - 1 >= 0)
						aux[i][j - 1] += 1;
				}
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
			{
				sandpile[i][j] += aux[i][j];
				if (sandpile[i][j] > max_cel)
					max_cel = sandpile[i][j];
			}
	}
	for (i = 0; i < 3; i++)
		free(aux[i]);
	free(aux);
}

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: first grid
 * @grid2: second grid
 *
 * Return: none
 */


void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, stable, max_cel;

	stable = 1;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
			if (grid1[i][j] > 3 && stable == 1)
				max_cel = grid1[i][j];
			if (grid1[i][j] > 3)
				stable = 0;
			else if (stable == 0 && grid1[i][j] > max_cel)
				max_cel = grid1[i][j];
		}

	if (stable == 0)
		sandpile_balance(grid1, max_cel);
}
