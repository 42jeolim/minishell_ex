#include "minishell.h"

int		find_pwd(t_data *data);
void	parse_env(t_data *data);
char	**find_path(char **env);

int	find_pwd(t_data *data)
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
	return (1);
}

void	parse_env(t_data *data)
{
	char	*tmp;
	int		i;

	data->paths = find_path(data->env);
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

char	**find_path(char **env)
{
	// int	i;
	char *tmp;

	// i = 0;
	while (ft_strncmp("PATH", *env, 4))
		env++;
	tmp = *env + 5;
	return (ft_split(tmp, ':'));
	// while (env[i])
	// {
	// 	if (!ft_strncmp(env[i], "PATH=", 5))
	// 		return (ft_substr(env[i], 5, ft_strlen(env[i]) - 5));
	// 	i++;
	// }
	// return (ft_strdup("\0"));
}
