#ifndef lexer_H
# define lexer_H
# include "minishell.h"

// tokenizer
int	tokenizer(t_data *data);
int	add_node(char *str, t_tokens token, t_lexer **lex);

// handle_token
t_tokens	check_token(int c);
int			handle_token(char *str, int i, t_lexer **lex);
int			handle_quotes(int i, char *str, char tarket);

#endif