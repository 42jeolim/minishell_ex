/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:37:14 by jeolim            #+#    #+#             */
/*   Updated: 2023/05/05 01:58:09 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "minishell.h"
# include "parser.h"

// parse_pwd
void				find_pwd(t_data *data);
void				parse_env(t_data *data);

// utils
char			    **ft_arrdup(char **arr);
void			    free_arr(char **arr);
int				    check_quotes(char *line);

// minishell_loop
void				minishell_init(t_data *data);
void				print_minishell(void);
int 				minishell_loop(t_data *data);
int					data_reset(t_data *data);

// signal
void				init_signal(void);
void				sigquit_handler(int sig);

// lexer_clear
void				lexerclear(t_lexer **lex);
void				lexer_delone(t_lexer **lex, int key);

// cmds_utils
void	            cmdclear(t_cmds **cmd);
t_cmds	            *cmdsnew(char **str, int num_redi, t_lexer *redi);
void	            cmdsadd_back(t_cmds **lst, t_cmds *new);
t_cmds	            *cmdsfirst(t_cmds *map);

// lexer_utils
t_lexer	            *lexernew(char *str, int token);
void	            lexeradd_back(t_lexer **lst, t_lexer *new);

#endif
