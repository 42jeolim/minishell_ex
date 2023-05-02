#ifndef EXECUTOR_H
# define EXECUTOR_H
# include "minishell.h"

// check_redirections
// int				check_outfile(t_lexer *redirections);
// int				check_infile(t_lexer *redirections);
// int				handle_redirections(t_simple_cmds *cmd, t_tools *tools);
int				check_redirections(t_cmds *cmd);

// executor
int				executor(t_data *data);
t_cmds	*call_expander(t_data *data, t_cmds *cmd);
int				pipe_wait(int *pid, int amount);

// handle_cmd
int				find_cmd(t_cmds *cmd, t_data *data);
void			handle_cmd(t_cmds *cmd, t_data *data);
void			dup_cmd(t_cmds *cmd, t_data *data,
					int end[2], int fd_in);
void			single_cmd(t_cmds *cmd, t_data *data);

// heredoc
int				send_heredoc(t_data *data, t_cmds *cmd);

#endif