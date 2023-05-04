/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:26:18 by jeolim            #+#    #+#             */
/*   Updated: 2023/05/05 01:59:24 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		parser(t_data *data);
int		pipe_error(t_data *data, t_tokens token);
t_cmds	*init_cmd(t_parser *parser);

int	parser(t_data *data)
{
	t_cmds		*node;
	t_parser	parser;

	data->cmd = NULL;
	count_pipes(data->lexer_list, data);
	if (data->lexer_list->token == PIPE)
		return (token_error(data, data->lexer_list,
				data->lexer_list->token));
	while (data->lexer_list)
	{
		if (data->lexer_list && data->lexer_list->token == PIPE)
			lexer_delone(&data->lexer_list, data->lexer_list->i);
		if (pipe_error(data, data->lexer_list->token))
			return (1);
		parser = init_parser_data(data->lexer_list, data);
		node = init_cmd(&parser);
		if (!node)
			parser_error(0, data, parser.lexer_list);
		if (!data->cmd)
			data->cmd = node;
		else
			cmdsadd_back(&data->cmd, node);
		data->lexer_list = parser.lexer_list;
	}
	return (0);
}

t_cmds	*init_cmd(t_parser *parser)
{
	char	**str;
	int		i;
	int		arg_size;
	t_lexer	*tmp;

	i = 0;
	rm_redirections(parser);
	arg_size = count_args(parser->lexer_list);
	str = ft_calloc(arg_size + 1, sizeof(char *));
	if (!str)
		parser_error(1, parser->data, parser->lexer_list);
	tmp = parser->lexer_list;
	while (arg_size > 0)
	{
		if (tmp->str)
		{
			str[i++] = ft_strdup(tmp->str);
			lexer_delone(&parser->lexer_list, tmp->i);
			tmp = parser->lexer_list;
		}
		arg_size--;
	}
	return (cmdsnew(str,
			parser->num_redi, parser->redi));
}

int	pipe_error(t_data *data, t_tokens token)
{
	if (token == PIPE)
	{
		token_error(data, data->lexer_list,
			data->lexer_list->token);
		return (1);
	}
	if (!data->lexer_list)
	{
		parser_error(0, data, data->lexer_list);
		return (1);
	}
	return (0);
}


