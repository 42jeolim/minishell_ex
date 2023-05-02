/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:55:24 by jeolim            #+#    #+#             */
/*   Updated: 2023/01/23 10:52:35 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	if (!count)
		return (NULL);
	if ((count >= SIZE_MAX || size >= SIZE_MAX || size >= SIZE_MAX / count))
		return (NULL);
	return (ft_memset(ptr, 0, (size * count)));
}
