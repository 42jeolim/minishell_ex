/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:32:59 by jeolim            #+#    #+#             */
/*   Updated: 2023/05/05 14:13:28 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	single_cmd(t_cmds *cmd, t_data *data);
int		find_cmd(t_cmds *cmd, t_data *data);
void	handle_cmd(t_cmds *cmd, t_data *data);
void	dup_cmd(t_cmds *cmd, t_data *data, int end[2], int fd_in);

void	single_cmd(t_cmds *cmd, t_data *data)
{
	int	pid;
	int	status;

	data->cmd = call_expander(data, data->cmd);
	if (cmd->builtin == mini_cd || cmd->builtin == mini_exit
		|| cmd->builtin == mini_export || cmd->builtin == mini_unset)
	{
		g_mini.error_num = cmd->builtin(data, cmd);
		return ;
	}
	send_heredoc(data, cmd);
	pid = fork();
	if (pid < 0)
		ft_error(5, data);
	if (pid == 0)
		handle_cmd(cmd, data);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_mini.error_num = WEXITSTATUS(status);
}

int	find_cmd(t_cmds *cmd, t_data *data)
{
	int		i;
	char	*mycmd;

	i = 0;
	cmd->str = resplit_str(cmd->str);
	if (!access(cmd->str[0], F_OK))
		execve(cmd->str[0], cmd->str, data->env);
	while (data->paths[i])
	{
		mycmd = ft_strjoin(data->paths[i], cmd->str[0]);
		if (!access(mycmd, F_OK))
			execve(mycmd, cmd->str, data->env);
		free(mycmd);
		i++;
	}
	return (cmd_not_found(cmd->str[0]));
}

void	handle_cmd(t_cmds *cmd, t_data *data)
{
	int	exit_code;

	exit_code = 0;
	if (cmd->redi)
		if (check_redirections(cmd))
			exit(1);
	if (cmd->builtin != NULL)
	{
		exit_code = cmd->builtin(data, cmd);
		exit(exit_code);
	}
	else if (cmd->str[0][0] != '\0')
		exit_code = find_cmd(cmd, data);
	exit(exit_code);
}

void	dup_cmd(t_cmds *cmd, t_data *data, int end[2], int fd_in)
{
	if (cmd->prev && dup2(fd_in, STDIN_FILENO) < 0)
		ft_error(4, data);
	close(end[0]);
	if (cmd->next && dup2(end[1], STDOUT_FILENO) < 0)
		ft_error(4, data);
	close(end[1]);
	if (cmd->prev)
		close(fd_in);
	handle_cmd(cmd, data);
}
