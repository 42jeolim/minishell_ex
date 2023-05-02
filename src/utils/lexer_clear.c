#include "utils.h"

void	lexerclear(t_lexer **lex);
void	lexer_delone(t_lexer **lst, int key);
void	lexerdel_first(t_lexer **lst);
t_lexer	*lexerclear_one(t_lexer **lst);

void	lexerclear(t_lexer **lex)
{
	t_lexer	*tmp;

	if (!*lex)
		return ;
	while (*lex)
	{
		tmp = (*lex)->next;
		if ((*lex)->str)
			free((*lex)->str);
		free(*lex);
		*lex = tmp;
	}
	*lex = NULL;
}

void	lexer_delone(t_lexer **lst, int key)
{
	t_lexer	*node;
	t_lexer	*prev;
	t_lexer	*start;

	start = *lst;
	node = start;
	if ((*lst)->i == key)
	{
		lexerdel_first(lst);
		return ;
	}
	while (node && node->i != key)
	{
		prev = node;
		node = node->next;
	}
	if (node)
		prev->next = node->next;
	else
		prev->next = NULL;
	if (prev->next)
		prev->next->prev = prev;
	lexerclear_one(&node);
	*lst = start;
}

void	lexerdel_first(t_lexer **lst)
{
	t_lexer	*node;

	node = *lst;
	*lst = node->next;
	lexerclear_one(&node);
	if (*lst)
		(*lst)->prev = NULL;
}

t_lexer	*lexerclear_one(t_lexer **lst)
{
	if ((*lst)->str)
	{
		free((*lst)->str);
		(*lst)->str = NULL;
	}
	free(*lst);
	*lst = NULL;
	return (NULL);
}