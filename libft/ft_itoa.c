/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:41:33 by jeolim            #+#    #+#             */
/*   Updated: 2022/07/08 14:30:32 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_numlen(int n)
{
	int		len;
	long	num;

	num = (long)n;
	len = 0;
	if (num == 0)
		return (1);
	else if (num < 0)
	{
		num = -num;
		len++;
	}
	while (num)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*result;
	long	num;

	result = NULL;
	len = get_numlen(n);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	num = (long)n;
	if (num == 0)
		result[0] = '0';
	else if (num < 0)
	{
		num = -num;
		result[0] = '-';
	}
	result[len] = '\0';
	while (num)
	{
		result[--len] = num % 10 + '0';
		num = num / 10;
	}
	return (result);
}
