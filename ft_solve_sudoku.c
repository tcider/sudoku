int	check_num(int **table, int x, int y, int n)
{
	int	i;
	int	j;
	int	xs;
	int	ys;

	i = -1;
	while (++i < 9)
		if (table[x][i] == n || table[i][y] == n)
			return (0);
	xs = (x / 3) * 3;
	ys = (y / 3) * 3;
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (table[xs + i][ys + j] == n)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	solve_table(int **table, int position)
{
	int	n;
	int	x;
	int	y;

	x = position % 9;
	y = position / 9;
	n = 1;
	if (position == 81)
		return (1);
	if (table[x][y] != 0)
		return (solve_table(table, position + 1));
	while (n <= 9)
	{
		if (check_num(table, x, y, n))
		{
			table[x][y] = n;
			if (solve_table(table, position + 1))
				return (1);
			else
				table[x][y] = 0;
		}
		n++;
	}
	return (0);
}
