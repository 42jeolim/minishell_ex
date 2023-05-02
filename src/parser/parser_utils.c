#include "minishell.h"

void		count_pipes(t_lexer *lex, t_data *data);
t_parser	init_parser_data(t_lexer *lex, t_data *data);
int			count_args(t_lexer *lex);
t_lexer		*find_next_cmd(t_lexer *lex);

void	count_pipes(t_lexer *lex, t_data *data)
{
	t_lexer	*tmp;

	tmp = lex;
	data->pipes = 0;
	while (tmp)
	{
		if (tmp->token == PIPE)
			data->pipes++;
		tmp = tmp->next;
	}
}

t_parser	init_parser_data(t_lexer *lex, t_data *data)
{
	t_parser	parser;

	parser.lexer_list = lex;
	parser.redi = NULL;
	parser.num_redi = 0;
	parser.data = data;
	return (parser);
}

int	count_args(t_lexer *lex)
{
	t_lexer	*tmp;
	int		i;

	i = 0;
	tmp = lex;
	while (tmp && tmp->token != PIPE)
	{
		if (tmp->i >= 0)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

t_lexer	*find_next_cmd(t_lexer *lex)
{
	while (lex && lex->token != PIPE)
		lex = lex->next;
	return (lex);
}
