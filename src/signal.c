#include "../include/minishell.h"

void signal_handle(int no)
{
    pid_t   pid;
    int     status;

    pid = waitpid(-1, &status, WNOHANG);
    // -1: 자식프로세스를 기다림
    // status : 자식 프로세스가 종료되면 자식 pid값이 할당
    // WNOHANG : 자식프로세스가 종료되지 않아서 pid를 회수할 수 없는 경우 반환값으로 0

    if (no == SIGINT)
    {
        if (pid == -1)
        {
            rl_on_new_line(); //엔터역할
            rl_redisplay();
            ft_putstr_fd("  \n",STDOUT); //개행
            rl_on_new_line();
            // rl_replace_line("", 1);
            rl_redisplay();
        }
        else
            ft_putstr_fd("\n", STDOUT); //다시 출력해서 커서가 글자의 끝에 위치
    }
    else if(no == SIGQUIT)
    {
        rl_on_new_line();
        rl_redisplay();
        ft_putstr_fd("  \b\b", STDOUT);
    }
    else
        ft_putstr_fd("Quit: 3\n", STDOUT);
}

void set_signal(void)
{
    signal(SIGINT, signal_handle); //ctrl+c
    signal(SIGQUIT, signal_handle); //ctrl+'\'
}