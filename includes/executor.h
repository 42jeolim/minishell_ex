/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:32:37 by jeolim            #+#    #+#             */
/*   Updated: 2023/05/05 01:31:24 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H
# include "minishell.h"

// executor
int				executor(t_data *data);
t_cmds			*call_expander(t_data *data, t_cmds *cmd);
int				pipe_wait(int *pid, int amount);

// executor_utils
char			*join_split_str(char **split_str, char *new_str);
char			**resplit_str(char **double_arr);

// handle_cmd
int				find_cmd(t_cmds *cmd, t_data *data);
void			handle_cmd(t_cmds *cmd, t_data *data);
void			dup_cmd(t_cmds *cmd, t_data *data,
					int end[2], int fd_in);
void			single_cmd(t_cmds *cmd, t_data *data);

// heredoc
int				send_heredoc(t_data *data, t_cmds *cmd);

// check_redirections
int				check_redirections(t_cmds *cmd);

#endif