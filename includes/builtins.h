#ifndef BUILTINS_H
# define BUILTINS_H

# include <dirent.h>
# include "minishell.h"

//builtins
int	(*builtin_type(char *str))(t_data *data, t_cmds *cmd);

// builtins_utils;
void	change_path(t_data *data);
size_t	equal_sign(char *str);
int		check_valid_identifier(char c);

int		mini_echo(t_data *data, t_cmds *cmd);

int		mini_cd(t_data *data, t_cmds *cmd);

int		mini_pwd(t_data *data, t_cmds *cmd);

int		mini_export(t_data *data, t_cmds *cmd);

int		mini_unset(t_data *data, t_cmds *cmd);

int		mini_env(t_data *data, t_cmds *cmd);

int		mini_exit(t_data *data, t_cmds *cmd);

int		mini_continue(t_data *data, t_cmds *cmd);

#endif