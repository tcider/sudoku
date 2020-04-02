#include "ft_sudoku.h"

int	ft_n_words(char *str)
{
	int	i;
	int	counter;
	char	spaceflag;

	counter = 0;
	i = 0;
	spaceflag = 0;
	while (str[i])
	{
		if (str[i] != '"' && str[i] != ' ' && str[i] != '\n')
		{
			if (spaceflag == 0)
				counter ++;
			spaceflag = 1;
		}
		else
			spaceflag = 0;
		i++;
	}
	return (counter);
}

int	ft_l_word(char *w)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (w[i] == '"' || w[i] == ' ' || w[i] == '\n')
		i++;
	while (w[i] && w[i] != '"' && w[i] != ' ' && w[i++] != '\n')
		l++;
	return (l);
}

char	**ft_split_whitespaces(char *s)
{
	int	i;
	int	j;
	int	k;
	char	**p;

	i = 0;
	k = 0;
	p = (char **)malloc(sizeof(char*) * (ft_n_words(s) + 1));
	while (i < ft_n_words(s))
	{
		p[i] = (char*)malloc(sizeof(char) * (ft_l_word(&s[k]) + 1));
		j = 0;
		while (s[k] == '"' || s[k] == ' ' || s[k] == '\n')
			k++;
		while (s[k] && s[k] != '"' && s[k] != ' ' && s[k] != '\n')
			p[i][j++] = s[k++];
		p[i][j] = '\0';
		i++;
	}
	p[i] = 0;
	return (p);
}
