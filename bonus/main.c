#include "ft_sudoku.h"

void	make_result(char **argv, char *path, char *color, int argc)
{
	int	**table;

	table = NULL;
	if (argc >= 9 && argv)
		table = make_table(argv, argc);
	if (table && check_table(table) && check_sq(table))
	{
		if (solve_table(table, 0))
		{
			if (path)
				if (!write_table(path, table))
					printf("Error\n");
			if (!path && !color)
				print_table(table, 1);
			if (!path && color)
				print_color_table(table, color);
		}
		else
			printf("Error\n");
	}
	else
		printf("Error\n");
}

int	main(int argc, char **argv)
{
	int	i;
	char	*path;
	char	*color;
	char	**tmp;

	i = 0;
	path = NULL;
	color = NULL;
	tmp = argv;
	while (argv[i])
	{
		if (ft_strcmp("-r\0", argv[i]) == 0 && argv[i + 1])
		{
			tmp = read_table(argv[i + 1]);
			argc = 9;
		}
		if (ft_strcmp("-w\0", argv[i]) == 0)
			path = argv[i + 1];
		if (ft_strcmp("-c\0", argv[i]) == 0 && argv[i + 1])
			color = argv[i + 1];
		i++;
	}
	make_result(tmp, path, color, argc);
	return (0);
}
