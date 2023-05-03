/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:25:07 by jeolim            #+#    #+#             */
/*   Updated: 2023/05/03 18:25:09 by jeolim           ###   ########.fr       */
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
	data.env = ft_arrdup(env); //환경변수 dup
	find_pwd(&data); //pwd 처리
	minishell_init(&data); //signal, env 처리
	print_minishell(); // minishell 꾸미기
	minishell_loop(&data); //loop
	return (0);
}
