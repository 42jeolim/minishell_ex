/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:48:19 by jeolim            #+#    #+#             */
/*   Updated: 2022/07/08 16:05:07 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dest_len;

	dest_len = ft_strlen(dst);
	if (dest_len >= dstsize)
		return (ft_strlen(src) + dstsize);
	while (dest_len + 1 < dstsize && *src)
	{
		dst[dest_len] = *src;
		dest_len++;
		src++;
	}
	dst[dest_len] = '\0';
	return (ft_strlen(dst) + ft_strlen(src));
}
