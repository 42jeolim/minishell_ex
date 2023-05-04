/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:38:20 by jeolim            #+#    #+#             */
/*   Updated: 2023/05/05 02:01:06 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	mini_pwd(t_data *data, t_cmds *cmd);

int	mini_pwd(t_data *data, t_cmds *cmd)
{
	(void) cmd;
	ft_putendl_fd(data->pwd, STDOUT_FILENO);
	return (0);
}
