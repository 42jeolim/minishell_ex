/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:35:53 by jeolim            #+#    #+#             */
/*   Updated: 2023/05/03 18:36:32 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	check_append_outfile(t_lexer *redi);
int	handle_infile(char *file);
int	check_redirections(t_cmds *cmd);
int	handle_outfile(t_lexer *redi);
int	check_redirections(t_cmds *cmd);

int	check_append_outfile(t_lexer *redi)
{
	int	fd;

	if (redi->token == DGREAT)
		fd = open(redi->str,
				O_CREAT | O_RDWR | O_APPEND, 0644);
	else
		fd = open(redi->str,
				O_CREAT | O_RDWR | O_TRUNC, 0644);
	return (fd);
}

int	handle_infile(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("minishell: infile: No such file or directory\n",
			STDERR_FILENO);
		return (1);
	}
	if (fd > 0 && dup2(fd, STDIN_FILENO) < 0)
	{
		ft_putstr_fd("minishell: pipe error\n", STDERR_FILENO);
		return (1);
	}
	if (fd > 0)
		close(fd);
	return (0);
}

int	handle_outfile(t_lexer *redi)
{
	int	fd;

	fd = check_append_outfile(redi);
	if (fd < 0)
	{
		ft_putstr_fd("minishell: outfile: Error\n", STDERR_FILENO);
		return (1);
	}
	if (fd > 0 && dup2(fd, STDOUT_FILENO) < 0)
	{
		ft_putstr_fd("minishell: pipe error\n", STDERR_FILENO);
		return (1);
	}
	if (fd > 0)
		close(fd);
	return (0);
}

int	check_redirections(t_cmds *cmd)
{
	t_lexer	*start;

	start = cmd->redi;
	while (cmd->redi)
	{
		if (cmd->redi->token == LESS)
		{
			if (handle_infile(cmd->redi->str))
				return (1);
		}
		else if (cmd->redi->token == GREAT
			|| cmd->redi->token == DGREAT)
		{
			if (handle_outfile(cmd->redi))
				return (1);
		}
		else if (cmd->redi->token == DLESS)
		{
			if (handle_infile(cmd->file_name))
				return (1);
		}
		cmd->redi = cmd->redi->next;
	}
	cmd->redi = start;
	return (0);
}
