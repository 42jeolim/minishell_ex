/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:27:12 by jeolim            #+#    #+#             */
/*   Updated: 2023/05/03 18:31:26 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H
# include "minishell.h"

// expander
char	**expander(t_data *data, char **str);
char	*expander_str(t_data *data, char *str);

//expander_utils1
size_t	dollar_sign(char *str);
char	*char_to_str(char c);
int	after_dol_lenght(char *str, int j);
char	*delete_quotes(char *str, char c);

//expander_utils2
int	question_mark(char **tmp);
#endif