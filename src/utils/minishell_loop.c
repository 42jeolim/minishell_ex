/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:25:51 by jeolim            #+#    #+#             */
/*   Updated: 2023/05/03 18:25:54 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		minishell_loop(t_data *data);
int		minishell_init(t_data *data);
void	print_minishell(void);
int		data_reset(t_data *data);
int		executor_init(t_data *data);

int	minishell_loop(t_data *data)
{
	char	*tmp;

	data->args = readline(READLINE_MSG);
	tmp = ft_strtrim(data->args, " ");
	free(data->args);
	data->args = tmp;
	if (!data->args)
	{
		ft_putendl_fd("exit", STDOUT_FILENO);
		exit(0);
	}
	if (data->args[0] == '\0')
		return (data_reset(data));
	add_history(data->args); // 명령어 기록 남기기
	if (!count_quotes(data->args)) //quote counting
		return (ft_error(2, data));
	if (!tokenizer(data))
		return (ft_error(1, data));
	parser(data);
	executor_init(data);
	data_reset(data); // loop
	return (1);
}

int	minishell_init(t_data *data)
{
	data->cmd = NULL;
	data->lexer_list = NULL;
	data->pid = NULL;
	data->heredoc = False;
	data->reset = False;
	g_mini.stop_heredoc = 0;
	g_mini.in_cmd = 0;
	g_mini.in_heredoc = 0;
	parse_env(data); //환경변수 처리
	init_signal();
	return (1);
}

int	data_reset(t_data *data)
{
	cmdclear(&data->cmd);
	free(data->args);
	if (data->pid)
		free(data->pid);
	free_arr(data->paths);
	minishell_init(data);
	data->reset = True;
	minishell_loop(data);
	return (1);
}

int	prepare_executor(t_data *data)
{
	signal(SIGQUIT, sigquit_handler);
	g_mini.in_cmd = 1;
	if (data->pipes == 0)
		single_cmd(data->cmd, data);
	else
	{
		data->pid = ft_calloc(sizeof(int), data->pipes + 2);
		if (!data->pid)
			return (ft_error(1, data));
		executor(data);
	}
	g_mini.in_cmd = 0;
	return (0);
}

int	executor_init(t_data *data)
{
	signal(SIGQUIT, sigquit_handler);
	g_mini.in_cmd = 1;
	if (data->pipes == 0)
		single_cmd(data->cmd, data);
	else
	{
		data->pid = ft_calloc(sizeof(int), data->pipes + 2);
		if (!data->pid)
			return (ft_error(1, data));
		executor(data);
	}
	g_mini.in_cmd = 0;
	return (0);
}

void	print_minishell(void)
{
	printf("\n\
───▄▀▀▀▄▄▄▄▄▄▄▀▀▀▄───minishell\n\
───█▒▒░░░░░░░░░▒▒█───\n\
────█░░█░░░░░█░░█────\n\
─▄▄──█░░░▀█▀░░░█──▄▄─\n\
█░░█─▀▄░░░░░░░▄▀─█░░█\n\
█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█\n\
█░░╦ ╦╔╗╦ ╔╗╔╗╔╦╗╔╗░░█\n\
█░░║║║╠ ║ ║ ║║║║║╠ ░░█\n\
█░░╚╩╝╚╝╚╝╚╝╚╝╩ ╩╚╝░░█\n\
█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n\
\n");
}
