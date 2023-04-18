/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjyu <seungjyu@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:38:00 by seungjyu          #+#    #+#             */
/*   Updated: 2023/04/16 11:14:36 by seungjyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str);
char	*ft_strchr(char *s, int c);
void	*ft_memmove(void *dest, const void *src, size_t n);

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
	size_t	i;
	int		j;

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
	else
	{
		j = n;
		while (--j >= 0)
			((unsigned char *)dest)[j] = ((unsigned char *)src)[j];
		return (dest);
	}
}
