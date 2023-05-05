/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:26:34 by jeolim            #+#    #+#             */
/*   Updated: 2023/05/05 11:38:15 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	tokenizer(t_data *data);
int	read_words(int i, char *str, t_lexer **lex);
int	is_spaces(char *str, int i);
int	is_whitespace(char c);
int	add_node(char *str, t_tokens token, t_lexer **lex);

int	tokenizer(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (data->args[i])
	{
		j = 0;
		i += is_spaces(data->args, i);
		if (check_token(data->args[i]))
			j = handle_token(data->args, i, &data->lexer_list);
		else
			j = read_words(i, data->args, &data->lexer_list);
		if (j < 0)
			return (0);
		i += j;
	}
	return (1);
}

int	read_words(int i, char *str, t_lexer **lex)
{
	int	j;

	j = 0;
	while (str[i + j] && !(check_token(str[i + j])))
	{
		j += handle_quotes(i + j, str, 34);
		j += handle_quotes(i + j, str, 39);
		if (is_whitespace(str[i + j]))
			break ;
		else
			j++;
	}
	if (!add_node(ft_substr(str, i, j), 0, lex))
		return (-1);
	return (j);
}

int	is_spaces(char *str, int i)
{
	int	j;

	j = 0;
	while (is_whitespace(str[i + j]))
		j++;
	return (j);
}

int	is_whitespace(char c)
{
	return (c == ' ' || (c > 8 && c < 14));
}

int	add_node(char *str, t_tokens token, t_lexer **lex)
{
	t_lexer	*node;

	node = lexernew(str, token);
	if (!node)
		return (0);
	lexeradd_back(lex, node);
	return (1);
}
