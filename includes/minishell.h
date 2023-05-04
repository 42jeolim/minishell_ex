/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:30:22 by jeolim            #+#    #+#             */
/*   Updated: 2023/05/05 01:50:39 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include "parser.h"
# include "utils.h"
# include "error.h"
# include "lexer.h"
# include "builtins.h"
# include "executor.h"
# include "expander.h"

# define READLINE_MSG	"\033[1;35mminishell\033[34m$ \033[0m"
# define HEREDOC_MSG	"\033[1;34mheredoc> \033[0m"
# define False			0
# define True			1

typedef struct	s_mini
{
	int	error_num;
	int	stop_heredoc;
	int	cmd;
	int	in_heredoc;
}	t_mini;

t_mini			g_mini;

#endif