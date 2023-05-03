/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:26:42 by jeolim            #+#    #+#             */
/*   Updated: 2023/05/03 18:26:44 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tokens	check_token(int c);
int			handle_token(char *str, int i, t_lexer **lex);
int			handle_quotes(int i, char *str, char tarket);

t_tokens	check_token(int c)
{
	static int	token_type[3][2] = {
	{'|', PIPE},
	{'>', GREAT},
	{'<', LESS},
	};
	int			i;

	i = 0;
	while (i < 3)
	{
		if (token_type[i][0] == c)
			return (token_type[i][1]);
		i++;
	}
	return (0);
}

int	handle_token(char *str, int i, t_lexer **lex)
{
	t_tokens	token;

	token = check_token(str[i]);
	if (token == GREAT && check_token(str[i + 1]) == GREAT)
	{
		if (!add_node(NULL, DGREAT, lex))
			return (-1);
		return (2);
	}
	else if (token == LESS && check_token(str[i + 1]) == LESS)
	{
		if (!add_node(NULL, DLESS, lex))
			return (-1);
		return (2);
	}
	else if (token)
	{
		if (!add_node(NULL, token, lex))
			return (-1);
		return (1);
	}	
	return (0);
}

int	handle_quotes(int i, char *str, char tarket)
{
	int	j;

	j = 0;
	if (str[i + j] == tarket)
	{
		j++;
		while (str[i + j] != tarket && str[i + j])
			j++;
		j++;
	}
	return (j);
}