/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:00:12 by jeolim            #+#    #+#             */
/*   Updated: 2022/07/11 14:34:35 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			count++;
			while (*s != c && *s)
				s++;
		}
	}
	return (count);
}

static char	**free_malloc(char **ret)
{
	int	i;

	i = 0;
	while (ret[i])
	{
		free(ret[i]);
		i++;
	}
	free(ret);
	return (NULL);
}

static void	ft_strcpy(char *dst, const char *src, int j, int k)
{
	j -= k;
	while (j < j + k)
	{
		*dst = src[j];
		j++;
		dst++;
		k--;
	}
	*dst = '\0';
}

static char	**get_word(const char *s, char c, char **new, int len)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (i < len)
	{
		while (s[j] && s[j] == c)
			j++;
		k = 0;
		while (s[j] && s[j] != c)
		{
			j++;
			k++;
		}
		new[i] = (char *)malloc(sizeof(char) * (k + 1));
		if (!new)
			return (free_malloc(new));
		ft_strcpy(new[i++], s, j, k);
	}
	new[i] = NULL;
	return (new);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	int		len;

	if (!s)
		return (0);
	len = word_count(s, c);
	result = (char **)malloc(sizeof(char *) * (len + 1));
	if (!result)
		return (NULL);
	result = get_word(s, c, result, len);
	return (result);
}
