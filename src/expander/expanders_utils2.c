/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanders_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:27:49 by jeolim            #+#    #+#             */
/*   Updated: 2023/05/05 02:00:07 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	question_mark(char **tmp);

int	question_mark(char **tmp)
{
	free(*tmp);
	*tmp = ft_itoa(g_mini.error_num);
	return (ft_strlen(*tmp) + 1);
}
