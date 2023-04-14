/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjyu <seungjyu@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:38:00 by seungjyu          #+#    #+#             */
/*   Updated: 2023/04/09 00:24:45 by seungjyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return (&((char *)s)[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i++;
	}
	return (0);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	if (src == 0 && dest == 0)
		return (0);
	if (src >= dest)
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
		return (dest);
	}
	i = (int)n;
	while (--i >= 0)
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
	return (dest);
}

char	*ft_strjoin_expand(char *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*str;
	size_t	i;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = (char *)malloc(len_s1 + len_s2 + 1);
	if (!str)
		return (0);
	i = 0;
	while (i < len_s1)
	{
		str[i] = s1[i];
		i++;
	}
	while (i < len_s1 + len_s2)
	{
		str[i] = s2[i - len_s1];
		i++;
	}
	str[i] = '\0';
	if (s1)
		free(s1);
	return (str);
}
