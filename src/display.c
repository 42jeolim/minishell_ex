#include "../include/minishell.h"

void print_minishell(void)
{
    ft_putstr_fd("\033[96m╔═══════════════════════════════════════════════════════════════════════════════════════╗\n", 2);
    ft_putstr_fd("\033[96m║  ____    __  ____  ____   _  ____  ______  __   _  ______  ____    ____               ║\n", 2);
    ft_putstr_fd("\033[96m║ |    \\  /  ||    ||    \\ | ||    ||   ___||  |_| ||   ___||    |  |    |              ║  \n", 2);
    ft_putstr_fd("\033[96m║ |     \\/   ||    ||     \\| ||    | `-.`-. |   _  ||   ___||    |_ |    |_             ║  \n", 2);
    ft_putstr_fd("\033[96m║ |__/\\__/|__||____||__/\\____||____||______||__| |_||______||______||______| ... jeolim ║\n", 2);
    ft_putstr_fd("\033[96m╚═══════════════════════════════════════════════════════════════════════════════════════╝\n", 2);
    ft_putstr_fd("\033[96m                                                                                      \n", 2);
}

void	print_prompt()
{
	// char *home;
	// char *path;
	// char cwd[4097];

	// home = get_env(envp, "HOME");
	// getcwd(cwd, 4096);
	// if (ft_memcmp(cwd, home, ft_strlen(home)))
	// 	path = ft_strdup(cwd);
	// else
	// 	path = ft_strjoin("~", cwd + ft_strlen(home));
	write(2, "\033[1;35mminishell\033[0;0m", 38);
	// ft_putstrs_fd(":\033[1;34m", path, "\033[0;0m$ ", 2);
	// free(path);
}
