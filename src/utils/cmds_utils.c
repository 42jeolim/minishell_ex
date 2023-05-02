#include "utils.h"

void	cmdclear(t_cmds **cmd);
t_cmds	*cmdsnew(char **str, int num_redi, t_lexer *redi);
void	cmdsadd_back(t_cmds **lst, t_cmds *new);
t_cmds	*cmdsfirst(t_cmds *map);

void	cmdclear(t_cmds **cmd)
{
	t_cmds	*tmp;
	t_lexer	*redi_tmp;

	if (!*cmd)
		return ;
	while (*cmd)
	{
		tmp = (*cmd)->next;
		redi_tmp = (*cmd)->redi;
		lexerclear(&redi_tmp);
		if ((*cmd)->str)
			free_arr((*cmd)->str);
		if ((*cmd)->file_name)
			free((*cmd)->file_name);
		free(*cmd);
		*cmd = tmp;
	}	
	*cmd = NULL;
}

t_cmds	*cmdsnew(char **str, int num_redi, t_lexer *redi)
{
	t_cmds	*new_element;

	new_element = (t_cmds *)malloc(sizeof(t_cmds));
	if (!new_element)
		return (0);
	new_element->str = str;
	new_element->builtin = builtin_type(str[0]);
	new_element->file_name = NULL;
	new_element->num_redi = num_redi;
	new_element->redi = redi;
	new_element->next = NULL;
	new_element->prev = NULL;
	return (new_element);
}

void	cmdsadd_back(t_cmds **lst, t_cmds *new)
{
	t_cmds	*tmp;

	tmp = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

void	ft_simple_cmds_rm_first(t_cmds **lst)
{
	t_cmds	*tmp;

	if (!*lst)
		return ;
	tmp = (*lst)->next;
	lexerclear(&(*lst)->redi);
	free(*lst);
	*lst = tmp;
}

t_cmds	*cmdsfirst(t_cmds *map)
{
	int	i;

	i = 0;
	if (!map)
		return (NULL);
	while (map->prev != NULL)
	{
		map = map->prev;
		i++;
	}
	return (map);
}
