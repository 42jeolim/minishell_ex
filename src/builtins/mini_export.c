/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:38:18 by jeolim            #+#    #+#             */
/*   Updated: 2023/05/03 18:38:18 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int		mini_export(t_data *data, t_cmds *cmd);
int		check_parameter(char *str);
int		variable_exist(t_data *data, char *str);
char	**add_var(char **arr, char *str);
char	**add_var_loop(char **arr, char **rtn, char *str);

int	mini_export(t_data *data, t_cmds *cmd)
{
	char	**tmp;
	int		i;

	i = 1;
	if (!cmd->str[1] || cmd->str[1][0] == '\0')
		mini_env(data, cmd);
	else
	{
		while (cmd->str[i])
		{
			if (check_parameter(cmd->str[i]) == 0
				&& variable_exist(data, cmd->str[i]) == 0)
			{
				if (cmd->str[i])
				{
					tmp = add_var(data->env, cmd->str[i]);
					free_arr(data->env);
					data->env = tmp;
				}
			}
			i++;
		}
	}
	return (0);
}

int	check_parameter(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[0]))
		return (export_error(str));
	if (equal_sign(str) == 0)
		return (1);
	if (str[0] == '=')
		return (export_error(str));
	while (str[i] != '=')
	{
		if (check_valid_identifier(str[i]))
			return (export_error(str));
		i++;
	}
	return (0);
}

int	variable_exist(t_data *data, char *str)
{
	int	i;

	i = 0;
	if (str[equal_sign(str)] == '\"')
		delete_quotes(str, '\"');
	if (str[equal_sign(str)] == '\'')
		delete_quotes(str, '\'');
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i],
				str, equal_sign(data->env[i])) == 0)
		{
			free(data->env[i]);
			data->env[i] = ft_strdup(str);
			return (1);
		}
		i++;
	}
	return (0);
}

char	**add_var(char **arr, char *str)
{
	char	**res;
	size_t	i;

	i = 0;
	if (str[equal_sign(str)] == '\"')
		delete_quotes(str, '\"');
	if (str[equal_sign(str)] == '\'')
		delete_quotes(str, '\'');
	while (arr[i] != NULL)
		i++;
	res = ft_calloc(sizeof(char *), i + 2);
	if (!res)
		return (NULL);
	i = 0;
	add_var_loop(arr, res, str);
	return (res);
}

char	**add_var_loop(char **arr, char **res, char *str)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		if (arr[i + 1] == NULL)
		{
			res[i] = ft_strdup(str);
			res[i + 1] = ft_strdup(arr[i]);
		}
		else
			res[i] = ft_strdup(arr[i]);
		if (res[i] == NULL)
		{
			free_arr(res);
			return (res);
		}
		i++;
	}
	return (res);
}

