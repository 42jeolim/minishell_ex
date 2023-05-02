
#include "minishell.h"
#include "builtins.h"

int	question_mark(char **tmp)
{
	free(*tmp);
	*tmp = ft_itoa(g_mini.error_num);
	return (ft_strlen(*tmp) + 1);
}
