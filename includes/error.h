#ifndef ERROR_H
# define ERROR_H
# include "minishell.h"

// ft_error1
int		token_error(t_data *data, t_lexer *lex, t_tokens token);
void	parser_error(int error, t_data *data, t_lexer *lex);
int		export_error(char *c);
int		cmd_not_found(char *str);
void	lexer_error(int error, t_data *data);

// ft_error2
int	ft_error(int error, t_data *data);

#endif