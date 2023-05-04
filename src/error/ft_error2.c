/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:37:29 by jeolim            #+#    #+#             */
/*   Updated: 2023/05/05 02:00:58 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_error(int error, t_data *data);

int	ft_error(int error, t_data *data)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	if (error == 0)
		ft_putstr_fd("syntax error near unexpected token 'newline'\n",
			STDERR_FILENO);
	else if (error == 1)
		ft_putstr_fd("Memory Assign Error\n", STDERR_FILENO);
	else if (error == 2)
		ft_putstr_fd("Unmatching quotation\n",
			STDERR_FILENO);
	else if (error == 3)
		ft_putstr_fd("Parser Error\n", STDERR_FILENO);
	else if (error == 4)
		ft_putstr_fd("Pipe Error\n", STDERR_FILENO);
	else if (error == 5)
		ft_putstr_fd("Fork Error\n", STDERR_FILENO);
	else if (error == 6)
		ft_putstr_fd("outfile: Error\n", STDERR_FILENO);
	else if (error == 7)
		ft_putstr_fd("infile: No such file or directory\n", STDERR_FILENO);
	else if (error == 8)
		ft_putendl_fd("Path does not exist", STDERR_FILENO);
	data_reset(data);
	return (1);
}
