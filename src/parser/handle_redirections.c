/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:26:27 by jeolim            #+#    #+#             */
/*   Updated: 2023/05/05 14:23:06 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	rm_redirections(t_parser *parser);
int		add_new_redirection(t_lexer *tmp, t_parser *parser);

void	rm_redirections(t_parser *parser)
{
	t_lexer	*tmp;

	tmp = parser->lexer_list;
	while (tmp && !tmp->token)
		tmp = tmp->next;
	if (!tmp || tmp->token == PIPE)
		return ;
	if (!tmp->next)
		parser_error(0, parser->data, parser->lexer_list);
	if (tmp->next->token)
		token_error(parser->data,
			parser->lexer_list, tmp->next->token);
	if ((tmp->token >= GREAT
			&& tmp->token <= DLESS))
		add_new_redirection(tmp, parser);
	rm_redirections(parser);
}

int	add_new_redirection(t_lexer *tmp, t_parser *parser)
{
	t_lexer	*node;
	int		index_1;
	int		index_2;

	node = lexernew(ft_strdup(tmp->next->str), tmp->token);
	if (!node)
		parser_error(1, parser->data, parser->lexer_list);
	lexeradd_back(&parser->redi, node);
	index_1 = tmp->i;
	index_2 = tmp->next->i;
	lexer_delone(&parser->lexer_list, index_1);
	lexer_delone(&parser->lexer_list, index_2);
	parser->num_redi++;
	return (0);
}
