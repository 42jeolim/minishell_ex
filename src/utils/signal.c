/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:25:38 by jeolim            #+#    #+#             */
/*   Updated: 2023/05/05 11:44:10 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_signal(void);
int		event(void);
void	sigint_handler(int sig);
void	sigquit_handler(int sig);

void	init_signal(void)
{
	rl_event_hook = event;
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}

int	event(void)
{
	return (0);
}

void	sigint_handler(int sig)
{
	if (!g_mini.in_heredoc)
		ft_putstr_fd("\n", STDOUT_FILENO);
	if (g_mini.cmd)
	{
		g_mini.stop_heredoc = 1;
		rl_replace_line("", 0);
		rl_redisplay();
		rl_done = 1;
		return ;
	}
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	(void) sig;
}

void	sigquit_handler(int sig)
{
	(void) sig;
	printf("Quit: %d\n", sig);
}
