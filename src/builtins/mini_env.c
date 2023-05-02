#include "builtins.h"

int	mini_env(t_data *data, t_cmds *cmd);

int	mini_env(t_data *data, t_cmds *cmd)
{
	int		i;

	(void) cmd;
	i = 0;
	while (data->env[i])
	{
		ft_putendl_fd(data->env[i], STDOUT_FILENO);
		i++;
	}
	return (0);
}
