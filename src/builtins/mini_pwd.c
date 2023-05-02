#include "builtins.h"

int	mini_pwd(t_data *data, t_cmds *cmd);

int	mini_pwd(t_data *data, t_cmds *cmd)
{
	(void) cmd;
	ft_putendl_fd(data->pwd, STDOUT_FILENO);
	return (0);
}
