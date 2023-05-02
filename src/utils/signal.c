#include "minishell.h"

void	init_signal(void);
int		event(void);
void	sigint_handler(int sig);
void	sigquit_handler(int sig);

void	init_signal(void)
{
	rl_event_hook = event; // 0이 아닌 경우 readline이 터미널 입력을 기다릴 때 주기적으로 호출할 함수의 주소
							// 암것두 입력인 됐을 때 반복해서 readline 출력
	signal(SIGINT, sigint_handler); // CTRL + C
	signal(SIGQUIT, SIG_IGN); // CTRL + /
}

int	event(void)
{
	return (0);
}

void	sigint_handler(int sig)
{
	if (!g_mini.in_heredoc)
		ft_putstr_fd("\n", STDOUT_FILENO);
	if (g_mini.in_cmd)
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
