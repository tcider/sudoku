#include "ft_sudoku.h"
#include "ft_color.h"

void	print_table(int **table, int fd)
{
	int	i;
	int	j;
	char	c;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			c = table[i][j] + '0';
			write(fd, &c, 1);
			if (j != 8)
				write(fd, " ", 1);
			j++;
		}
		write(fd, "\n", 1);
		i++;
	}
}

char	**read_table(char *path)
{
	char	str[BUF_SIZE + 1];
	int	fd;
	int	k;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	k = read(fd, str, BUF_SIZE);
	str[k] = '\0';
	close(fd);
	if (ft_n_words(str) != 9)
		return (NULL);
	return (ft_split_whitespaces(str));
}

int	write_table(char *path, int **table)
{
	int	fd;

	if (path[0] == '-')
		return (0);
	fd = open(path, O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (0);
	print_table(table, fd);
	close(fd);
	return (1);
}

void	print_color_table(int **table, char *color)
{
	int	i;
	int	j;
	char	*clr;

	i = -1;
	clr = color_arr[0].code;
	while (color_arr[++i].color)
		if (ft_strcmp(color, color_arr[i].color) == 0)
			clr = color_arr[i].code;
	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			printf("%s%d", clr, table[i][j]);
			if (j != 8)
				printf(" ");
			j++;
		}
		printf("%s\n", color_arr[0].code);
		i++;
	}
}
