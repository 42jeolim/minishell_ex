/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:22:05 by jeolim            #+#    #+#             */
/*   Updated: 2023/03/21 19:24:00 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// void print_minishell(void)
// {
//     int     fd;
//     char    *line;

//     fd = open("ascii.txt", O_RDONLY);
//     while (get_next_line(fd, &line) > 0)
// 	{
// 		printf("%s\n", line);
// 		free(line);
// 	}
// 	free(line);
// }

int main(int ac, char **av)
{
    // , char **envp
    if (ac != 1 || av[1])
    {
        printf("Program cannot executed\n");
        exit (0);
    }
    print_minishell();
    // set_signal();

    // while (1)
    // {
        print_prompt();
    // }
    return (0);
}