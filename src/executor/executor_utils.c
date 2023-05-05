/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:34:53 by jeolim            #+#    #+#             */
/*   Updated: 2023/05/05 14:10:00 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**resplit_str(char **double_arr);
char	*join_split_str(char **split_str, char *new_str);

char	**resplit_str(char **double_arr)
{
	char	**res;
	char	*joined_str;

	joined_str = join_split_str(double_arr, NULL);
	free_arr(double_arr);
	res = ft_split(joined_str, ' ');
	free(joined_str);
	joined_str = join_split_str(res, NULL);
	free_arr(res);
	res = ft_split(joined_str, ' ');
	free(joined_str);
	return (res);
}

char	*join_split_str(char **split_str, char *new_str)
{
	char	*tmp;
	char	*space;
	int		i;

	tmp = ft_strdup(split_str[0]);
	i = 1;
	while (split_str[i])
	{
		new_str = tmp;
		space = ft_strjoin(new_str, " ");
		free(new_str);
		tmp = ft_strjoin(space, split_str[i]);
		free(space);
		i++;
	}
	new_str = tmp;
	return (new_str);
}
