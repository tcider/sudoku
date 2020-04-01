#ifndef FT_SUDOKU_H
# define FT_SUDOKU_H

# include <stdlib.h>
# include <unistd.h>

void	ft_putstr(char *str);
int	ft_strlen(char *str);
void	ft_putchar(char c);
int	check_table(int **table);
int	check_sq(int **table);
int	solve_table(int **table, int position);
#endif
