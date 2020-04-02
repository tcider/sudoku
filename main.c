#include "ft_sudoku.h"

int	**make_table(char **argv)
{
	int	i;
	int	j;
	int	**table;

	table = (int**)malloc(sizeof(int*) * 9);
	i = 0;
	while (argv[i + 1])
	{
		if (ft_strlen(argv[i + 1]) != 9)
			return (0);
		table[i] = (int*)malloc(sizeof(int) * 9);
		j = 0;
		while (argv[i + 1][j])
		{
			if (argv[i + 1][j] == '.')
				table[i][j] = 0;
			else if (argv[i + 1][j] >= '1' && argv[i + 1][j] <= '9')
				table[i][j] = argv[i + 1][j] - '0';
			else
				return (0);
			j++;
		}
		i++;
	}
	return (table);
}

void	print_table(int **table)
{
	int	i;
	int	j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			ft_putchar(table[i][j] + '0');
			if (j != 8)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	**table;

	if (argc == 10)
	{
		table = make_table(argv);
		if (!table || !check_table(table) || !check_sq(table))
		{
			ft_putstr("Error\n");
			return (0);
		}
		if (solve_table(table, 0))
			print_table(table);
		else
			ft_putstr("Error\n");
	}
	else
		ft_putstr("Error\n");
	return (0);
}
