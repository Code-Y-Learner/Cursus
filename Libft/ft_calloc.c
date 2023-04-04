/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjyu <seungjyu@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:49:50 by seungjyu          #+#    #+#             */
/*   Updated: 2023/04/01 22:36:31 by seungjyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t elt_count, size_t elt_size);

void	*ft_calloc(size_t elt_count, size_t elt_size)
{
	void	*ptr;

	ptr = malloc(elt_count * elt_size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, elt_count * elt_size);
	return (ptr);
}
