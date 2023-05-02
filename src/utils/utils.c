#include "minishell.h"

void	free_arr(char **arr);
char	**ft_arrdup(char **arr);
int		count_quotes(char *line);
int		find_matching_quote(char *line, int i, int *num, int tarket);

char	**ft_arrdup(char **arr)
{
	char	**res;
	size_t	i;

	i = 0;
	while (arr[i]) //arr[i] != NULL
		i++;
	res = ft_calloc(sizeof(char *), i + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (arr[i]) //arr[i] != NULL
	{
		res[i] = ft_strdup(arr[i]);
		if (!res[i]) //res[i] == NULL
		{
			free_arr(res);
			return (res);
		}
		i++;
	}
	return (res);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	find_matching_quote(char *line, int i, int *num, int target)
{
	int	j;

	j = i + 1;
	*num += 1;
	while (line[j] && line[j] != target)
		j++;
	if (line[j] == target)
		*num += 1;
	return (j - i);
}

int	count_quotes(char *line)
{
	int	i;
	int	s; //samll_quote
	int	d; //double_quote

	s = 0;
	d = 0;
	i = -1;
	while (line[++i])
	{
		if (line[i] == 34)
			i += find_matching_quote(line, i, &d, 34); // ""
		if (line[i] == 39)
			i += find_matching_quote(line, i, &s, 39); // ''
	}
	if ((d > 0 && d % 2 != 0) || (s > 0 && s % 2 != 0))
		return (0);
	return (1);
}
