/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjyu <seungjyu@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 01:33:16 by seungjyu          #+#    #+#             */
/*   Updated: 2023/03/27 15:14:50 by seungjyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size);

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_d;
	size_t	len_s;
	size_t	i;

	len_d = 0;
	len_s = 0;
	i = 0;
	while (dest[len_d])
		len_d++;
	while (src[len_s])
		len_s++;
	if (size < len_d)
		return (size + len_s);
	while (len_d + i + 1 < size && src[i] != '\0')
	{
		dest[len_d + i] = src[i];
		i++;
	}
	dest[len_d + i] = '\0';
	return (len_s + len_d);
}
