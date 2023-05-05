/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:25:07 by jeolim            #+#    #+#             */
/*   Updated: 2023/05/05 11:42:19 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_data	data;

	if (ac != 1 || av[1])
	{
		printf("Program cannot executed\n");
		exit(0);
	}
	data.env = ft_arrdup(env);
	find_pwd(&data);
	minishell_init(&data);
	print_minishell();
	minishell_loop(&data);
	return (0);
}
