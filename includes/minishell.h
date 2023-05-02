#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include "parser.h"
# include "utils.h"
# include "error.h"
# include "lexer.h"
# include "builtins.h"
# include "executor.h"

# define READLINE_MSG	"\033[1;35mminishell\033[34m$ \033[0m"
# define HEREDOC_MSG	"\033[1;34m> \033[0m"
# define False			0
# define True			1

// int		parse_envp(t_data *data);
// int		find_pwd(t_data *data);

void	init_stri(int i, int j, t_data *data);
char	**expander(t_data *data, char **str);
char	*expander_str(t_data *data, char *str);
size_t	dollar_sign(char *str);
char	*char_to_str(char c);
int		after_dol_lenght(char *str, int j);
void	free_things(char *tmp2, t_data *data, int i);
void	print_parser(t_cmds cmd);
char	*delete_quotes_value(char *str);
char	*delete_quotes(char *str, char c);
char	*delete_quotes_export(char *str, char c);
int		question_mark(char **tmp);

typedef struct s_mini
{
	int	error_num;
	int	stop_heredoc;
	int	in_cmd;
	int	in_heredoc;
}	t_mini;

t_mini				g_mini; //global 변수 사용 이유 설명

#endif