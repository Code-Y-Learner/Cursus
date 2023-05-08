/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjyu <seungjyu@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:59:33 by seungjyu          #+#    #+#             */
/*   Updated: 2023/04/01 22:30:39 by seungjyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	if (src == 0 && dest == 0)
		return (0);
	if (src >= dest)
		return (ft_memcpy(dest, src, n));
	i = (int)n;
	while (--i >= 0)
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
	return (dest);
}
