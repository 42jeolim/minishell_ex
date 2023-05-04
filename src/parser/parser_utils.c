/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:26:24 by jeolim            #+#    #+#             */
/*   Updated: 2023/05/05 01:54:38 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
