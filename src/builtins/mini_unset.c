/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:37:49 by jeolim            #+#    #+#             */
/*   Updated: 2023/05/05 01:51:33 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int		mini_unset(t_data *data, t_cmds *cmd);
int		unset_error(t_cmds *cmd);
char	**del_var(char **arr, char *str);
char	**del_var_loop(char **arr, char **res, char *str);

int	mini_unset(t_data *data, t_cmds *cmd)
{
	char	**tmp;

	if (unset_error(cmd) == 1)
		return (1);
	else
	{
		tmp = del_var(data->env, cmd->str[1]);
		free_arr(data->env);
		data->env = tmp;
	}
	return (0);
}

int	unset_error(t_cmds *cmd)
{
	int		i;

	i = 0;
	if (!cmd->str[1])
	{
		ft_putendl_fd("minishell: unset: not enough arguments", STDERR_FILENO);
		return (1);
	}
	while (cmd->str[1][i])
	{
		if (cmd->str[1][i++] == '/')
		{
			ft_putstr_fd("minishell: unset: `", STDERR_FILENO);
			ft_putstr_fd(cmd->str[1], STDERR_FILENO);
			ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
			return (1);
		}
	}
	if (equal_sign(cmd->str[1]) != 0)
	{
		ft_putendl_fd("minishell: unset: not a valid identifier",
			STDERR_FILENO);
		return (1);
	}
	return (0);
}

char	**del_var(char **arr, char *str)
{
	char	**res;
	size_t	i;

	i = 0;
	while (arr[i])
		i++;
	res = ft_calloc(sizeof(char *), i + 1);
	if (!res)
		return (NULL);
	res = del_var_loop(arr, res, str);
	return (res);
}

char	**del_var_loop(char **arr, char **res, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arr[i])
	{
		if (!(ft_strncmp(arr[i], str, equal_sign(arr[i]) - 1) == 0
				&& str[equal_sign(arr[i])] == '\0'
				&& arr[i][ft_strlen(str)] == '='))
		{
			res[j] = ft_strdup(arr[i]);
			if (!res[j])
			{
				free_arr(res);
				return (res);
			}
			j++;
		}	
		i++;
	}
	return (res);
}