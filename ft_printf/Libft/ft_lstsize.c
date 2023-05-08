/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjyu <seungjyu@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:53:31 by seungjyu          #+#    #+#             */
/*   Updated: 2023/03/25 17:53:31 by seungjyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst);

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*tmp;

	if (!lst)
		return (0);
	i = 0;
	tmp = lst;
	while (tmp != 0)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
