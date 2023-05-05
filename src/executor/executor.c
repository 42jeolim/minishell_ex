/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:35:05 by jeolim            #+#    #+#             */
/*   Updated: 2023/05/05 11:47:08 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmds	*call_expander(t_data *data, t_cmds *cmd);
int		pipe_wait(int *pid, int amount);
int		ft_fork(t_data *data, int end[2], int fd_in, t_cmds *cmd);
int		check_fd_heredoc(t_data *data, int end[2], t_cmds *cmd);
int		executor(t_data *data);

t_cmds	*call_expander(t_data *data, t_cmds *cmd)
{
	t_lexer	*start;

	cmd->str = expander(data, cmd->str);
	start = cmd->redi;
	while (cmd->redi)
	{
		if (cmd->redi->token != DLESS)
			cmd->redi->str
				= expander_str(data, cmd->redi->str);
		cmd->redi = cmd->redi->next;
	}
	cmd->redi = start;
	return (cmd);
}

int	pipe_wait(int *pid, int amount)
{
	int	i;
	int	status;

	i = 0;
	while (i < amount)
	{
		waitpid(pid[i], &status, 0);
		i++;
	}
	waitpid(pid[i], &status, 0);
	if (WIFEXITED(status))
		g_mini.error_num = WEXITSTATUS(status);
	return (0);
}

int	ft_fork(t_data *data, int end[2], int fd_in, t_cmds *cmd)
{
	static int	i = 0;

	if (data->reset == TRUE)
	{
		i = 0;
		data->reset = FALSE;
	}
	data->pid[i] = fork();
	if (data->pid[i] < 0)
		ft_error(5, data);
	if (data->pid[i] == 0)
		dup_cmd(cmd, data, end, fd_in);
	i++;
	return (0);
}

int	check_fd_heredoc(t_data *data, int end[2], t_cmds *cmd)
{
	int	fd_in;

	if (data->heredoc)
	{
		close(end[0]);
		fd_in = open(cmd->file_name, O_RDONLY);
	}
	else
		fd_in = end[0];
	return (fd_in);
}

int	executor(t_data *data)
{
	int		end[2];
	int		fd_in;

	fd_in = STDIN_FILENO;
	while (data->cmd)
	{
		data->cmd = call_expander(data, data->cmd);
		if (data->cmd->next)
			pipe(end);
		send_heredoc(data, data->cmd);
		ft_fork(data, end, fd_in, data->cmd);
		close(end[1]);
		if (data->cmd->prev)
			close(fd_in);
		fd_in = check_fd_heredoc(data, end, data->cmd);
		if (data->cmd->next)
			data->cmd = data->cmd->next;
		else
			break ;
	}
	pipe_wait(data->pid, data->pipes);
	data->cmd = cmdsfirst(data->cmd);
	return (0);
}
