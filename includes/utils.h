#ifndef UTILS_H
# define UTILS_H
# include "minishell.h"

// parse_pwd
int					find_pwd(t_data *data);
void				parse_env(t_data *data);

// utils
char			    **ft_arrdup(char **arr);
void			    free_arr(char **arr);
int				    count_quotes(char *line);

// minishell_loop
int					minishell_init(t_data *data);
void				print_minishell(void);
int					minishell_loop(t_data *data);
int					data_reset(t_data *data);

// signal
void				init_signal(void);
void				sigquit_handler(int sig);

// lexer_clear
void				lexerclear(t_lexer **lex);
void				lexer_delone(t_lexer **lex, int key);

// cmds_utils
void	            cmdclear(t_cmds **cmd);
t_cmds	            *cmdsnew(char **str, int num_redi, t_lexer *redi);
void	            cmdsadd_back(t_cmds **lst, t_cmds *new);
t_cmds	            *cmdsfirst(t_cmds *map);

// lexer_utils
t_lexer	            *lexernew(char *str, int token);
void	            lexeradd_back(t_lexer **lst, t_lexer *new);

#endif
