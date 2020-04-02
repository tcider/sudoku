#ifndef FT_SUDOKU_H
# define FT_SUDOKU_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define BUF_SIZE 150

typedef struct	s_color
{
	char	*color;
	char	*code;
}		t_color;

int	ft_strlen(char *str);
int	ft_strcmp(char *s1, char *s2);
int	ft_n_words(char *str);
char	**ft_split_whitespaces(char *str);
int	check_table(int **table);
int	check_sq(int **table);
int	**make_table(char **argv, int argc);
int	solve_table(int **table, int position);
void	print_table(int **table, int fd);
char	**read_table(char *path);
int	write_table(char *path, int **table);
void	print_color_table(int **table, char *color);

#endif
