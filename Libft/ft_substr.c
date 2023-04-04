/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjyu <seungjyu@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:18:28 by seungjyu          #+#    #+#             */
/*   Updated: 2023/04/01 23:31:51 by seungjyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	size_t			len_s;

	if (!s)
		return (0);
	len_s = ft_strlen(s);
	if (len_s < start)
		return (ft_strdup("\0"));
	if (len + (size_t)start > len_s)
		len = len_s - (size_t)start;
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	i = 0;
	while ((size_t)i < len && s[i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
