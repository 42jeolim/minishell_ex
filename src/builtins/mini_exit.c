/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:38:14 by jeolim            #+#    #+#             */
/*   Updated: 2023/05/05 02:01:10 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		mini_exit(t_data *data, t_cmds *cmd);
void	free_data(t_data *data);
void	determine_exit_code(char **str);
int		is_str_digit(char *str);

int	mini_exit(t_data *data, t_cmds *cmd)
{
	char	**str;

	ft_putendl_fd("exit", STDERR_FILENO);
	if (cmd->str[1] && cmd->str[2])
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
		return (1);
	}
	str = ft_arrdup(cmd->str);
	free_data(data);
	determine_exit_code(str);
	return (0);
}

void	free_data(t_data *data)
{
	free_arr(data->paths);
	free_arr(data->env);
	free(data->args);
	cmdclear(&data->cmd);
	free(data->pwd);
	free(data->old_pwd);
	if (data->pipes)
		free(data->pid);
}

void	determine_exit_code(char **str)
{
	int	exit_code;

	if (!str[1])
		exit_code = 0;
	else if (is_str_digit(str[1]))
		exit_code = ft_atoi(str[1]);
	else
	{
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(str[1], STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
		exit_code = 255;
	}
	free_arr(str);
	exit(exit_code);
}

int	is_str_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}