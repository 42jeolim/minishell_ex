/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:47:14 by jeolim            #+#    #+#             */
/*   Updated: 2022/07/08 14:15:07 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	idx;
	size_t	j;

	idx = 0;
	if (!ft_strlen(needle))
		return ((char *)haystack);
	while (haystack[idx] && idx < len)
	{
		j = 0;
		while (needle[j] == haystack[idx + j] && idx + j < len)
		{
			j++;
			if (!needle[j])
				return (&((char *)haystack)[idx]);
		}
		idx++;
	}
	return ((void *)0);
}
