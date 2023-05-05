/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:38:10 by jeolim            #+#    #+#             */
/*   Updated: 2023/05/05 11:47:22 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		mini_echo(t_data *data, t_cmds *cmd);
void	print_lines(int i, char **str, int out);

int	mini_echo(t_data *data, t_cmds *cmd)
{
	int		i;
	int		j;
	int		n_option;

	i = 1;
	n_option = FALSE;
	(void) data;
	while (cmd->str[i] && cmd->str[i][0] == '-'
		&& cmd->str[i][1] == 'n')
	{
		j = 1;
		while (cmd->str[i][j] == 'n')
			j++;
		if (cmd->str[i][j] == '\0')
			n_option = TRUE;
		else
			break ;
		i++;
	}
	print_lines(i, cmd->str, STDOUT_FILENO);
	if (n_option == FALSE)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (0);
}

void	print_lines(int i, char **str, int out)
{
	while (str[i])
	{
		ft_putstr_fd(str[i++], out);
		if (str[i])
			ft_putchar_fd(' ', out);
	}
}
