/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:25:47 by jeolim            #+#    #+#             */
/*   Updated: 2023/05/05 15:03:37 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	find_pwd(t_data *data);
void	parse_env(t_data *data);
char	*find_path(char **env);

void	find_pwd(t_data *data)
{
	int	i;

	i = 0;
	while (data->env[i])
	{
		if (!ft_strncmp(data->env[i], "PWD=", 4))
			data->pwd = ft_substr(data->env[i],
					4, ft_strlen(data->env[i]) - 4);
		if (!ft_strncmp(data->env[i], "OLDPWD=", 7))
			data->old_pwd = ft_substr(data->env[i],
					7, ft_strlen(data->env[i]) - 7);
		i++;
	}
}

void	parse_env(t_data *data)
{
	char	*tmp;
	char	*path_from_env;
	int		i;

	path_from_env = find_path(data->env);
    data->paths = ft_split(path_from_env, ':');
    free(path_from_env);
	i = 0;
	while (data->paths[i])
	{
		if (ft_strncmp(&data->paths[i][ft_strlen(data->paths[i]) - 1], \
					"/", 1))
		{
			tmp = ft_strjoin(data->paths[i], "/");
			free(data->paths[i]);
			data->paths[i] = tmp;
		}
		i++;
	}
}

char	*find_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
    {
        if (!ft_strncmp(env[i], "PATH=", 5))
            return (ft_substr(env[i], 5, ft_strlen(env[i]) - 5));
        i++;
    }
    return (ft_strdup("\0"));
}
