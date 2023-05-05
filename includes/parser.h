/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:37:11 by jeolim            #+#    #+#             */
/*   Updated: 2023/05/05 11:25:42 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "minishell.h"

typedef enum s_tokens
{
	PIPE = 1,
	GREAT,
	DGREAT,
	LESS,
	DLESS,
}	t_tokens;

typedef struct s_lexer
{
	char					*str;
	t_tokens				token;
	int						i;
	struct s_lexer			*next;
	struct s_lexer			*prev;
}	t_lexer;

typedef struct s_data
{
	char					*args;
	char					**paths;
	char					**env;
	struct s_cmds			*cmd;
	t_lexer					*lexer_list;
	char					*pwd;
	char					*old_pwd;
	int						pipes;
	int						*pid;
	int						heredoc;
	int						reset;
}	t_data;

typedef struct s_cmds
{
	char					**str;
	int						(*builtin)(t_data *, struct s_cmds *);
	int						num_redi;
	char					*file_name;
	t_lexer					*redi;
	struct s_cmds			*next;
	struct s_cmds			*prev;
}	t_cmds;

typedef struct s_parser
{
	t_lexer				*lexer_list;
	t_lexer				*redi;
	int					num_redi;
	struct s_data		*data;
}	t_parser;

// parser
int					parser(t_data *data);

//parser_utils
void				count_pipes(t_lexer *lex, t_data *data);
t_parser			init_parser_data(t_lexer *lex, t_data *data);
int					count_args(t_lexer *lex);

t_lexer				*find_next_cmd(t_lexer *lex);

//handle_redirections
void				rm_redirections(t_parser *parser);

int					add_new_redirection(t_lexer *tmp, t_parser *parser);

#endif
