/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:25:32 by jeolim            #+#    #+#             */
/*   Updated: 2023/05/04 23:38:59 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	**ft_arrdup(char **arr);
void	free_arr(char **arr);
int		check_quotes(char *line);
int		find_quote(char *line, int i, int *num, int tarket);

char	**ft_arrdup(char **arr)
{
	char	**res;
	size_t	i;

	i = 0;
	while (arr[i])
		i++;
	res = ft_calloc(sizeof(char *), i + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		res[i] = ft_strdup(arr[i]);
		if (!res[i])
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

int	check_quotes(char *line)
{
	int	i;
	int	s;
	int	d;

	s = 0;
	d = 0;
	i = -1;
	while (line[++i])
	{
		if (line[i] == 34)
			i += find_quote(line, i, &d, 34);
		if (line[i] == 39)
			i += find_quote(line, i, &s, 39);
	}
	if ((d > 0 && d % 2 != 0) || (s > 0 && s % 2 != 0))
		return (0);
	return (1);
}

int	find_quote(char *line, int i, int *num, int target)
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