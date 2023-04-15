/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:37:06 by jeolim            #+#    #+#             */
/*   Updated: 2022/07/08 13:57:35 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t len)
{
	size_t	idx;
	char	*tmp;

	tmp = (char *)ptr;
	idx = 0;
	while (idx < len)
		tmp[idx++] = (unsigned char)value;
	return (ptr);
}
