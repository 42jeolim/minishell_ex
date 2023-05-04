/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:38:12 by jeolim            #+#    #+#             */
/*   Updated: 2023/05/05 02:01:16 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	mini_env(t_data *data, t_cmds *cmd);

int	mini_env(t_data *data, t_cmds *cmd)
{
	int		i;

	(void) cmd;
	i = 0;
	while (data->env[i])
	{
		ft_putendl_fd(data->env[i], STDOUT_FILENO);
		i++;
	}
	return (0);
}
