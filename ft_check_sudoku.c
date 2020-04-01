#include "ft_sudoku.h"

int	check_9num(int *num)
{
	int	i;
	int	n;

	i = 0;
	while (i < 9)
	{
		n = 0;
		while (n < 9)
		{
			if (n != i && num[i] == num[n] && num[n] != 0)
				return (0);
			n++;
		}
		i++;
	}
	return (1);
}

int	check_table(int **table)
{
	int	i;
	int	j;
	int	*num_row;
	int	*num_col;

	i = 0;
	while (i < 9)
	{
		num_row = (int*)malloc(sizeof(int) * 9);
		num_col = (int*)malloc(sizeof(int) * 9);
		j = 0;
		while (j < 9)
		{
			num_row[j] = table[i][j];
			num_col[j] = table[j][i];
			j++;
		}
		if (!check_9num(num_row) || !check_9num(num_col))
			return (0);
		free(num_col);
		free(num_row);
		i++;
	}
	return (1);
}

int	check_sq(int **table)
{
	int	n;
	int	i;
	int	j;
	int	*num_sq;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			n = -1;
			num_sq = (int*)malloc(sizeof(int) * 9);
			while (++n < 9)
				num_sq[n] = table[3 * i + n / 3][3 * j + n % 3];
			if (!check_9num(num_sq))
				return (0);
			free(num_sq);
			j++;
		}
		i++;
	}
	return (1);
}
