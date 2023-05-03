/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:38:07 by jeolim            #+#    #+#             */
/*   Updated: 2023/05/03 18:38:08 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"
#include "builtins.h"

int		mini_cd(t_data *data, t_cmds *cmd);
int		specific_path(t_data *data, char *str);
void	add_path_to_env(t_data *data);
char	*find_path_res(char *str, t_data *data);

int	mini_cd(t_data *data, t_cmds *cmd)
{
	int		ret;

	if (!cmd->str[1])
		ret = specific_path(data, "HOME=");
	else if (ft_strncmp(cmd->str[1], "-", 1) == 0)
		ret = specific_path(data, "OLDPWD=");
	else
	{
		ret = chdir(cmd->str[1]);
		if (ret != 0)
		{
			ft_putstr_fd("minishell: ", STDERR_FILENO);
			ft_putstr_fd(cmd->str[1], STDERR_FILENO);
			perror(" ");
		}
	}
	if (ret != 0)
		return (1);
	change_path(data);
	add_path_to_env(data);
	return (0);
}

int	specific_path(t_data *data, char *str)
{
	char	*tmp;
	int		ret;

	tmp = find_path_res(str, data);
	ret = chdir(tmp);
	free(tmp);
	if (ret != 0)
	{
		str = ft_substr(str, 0, ft_strlen(str) - 1);
		ft_putstr_fd(str, STDERR_FILENO);
		free(str);
		ft_putendl_fd(" not set", STDERR_FILENO);
	}
	return (ret);
}

char	*find_path_res(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (data->env[i])
	{
		if (!ft_strncmp(data->env[i], str, ft_strlen(str)))
			return (ft_substr(data->env[i], ft_strlen(str),
					ft_strlen(data->env[i]) - ft_strlen(str)));
		i++;
	}
	return (NULL);
}

void	add_path_to_env(t_data *data)
{
	int		i;
	char	*tmp;

	i = 0;
	while (data->env[i])
	{
		if (!ft_strncmp(data->env[i], "PWD=", 4))
		{
			tmp = ft_strjoin("PWD=", data->pwd);
			free(data->env[i]);
			data->env[i] = tmp;
		}
		else if (!ft_strncmp(data->env[i], "OLDPWD=", 7) && data->old_pwd)
		{
			tmp = ft_strjoin("OLDPWD=", data->old_pwd);
			free(data->env[i]);
			data->env[i] = tmp;
		}
		i++;
	}
}


