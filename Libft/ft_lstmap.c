/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjyu <seungjyu@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:34:33 by seungjyu          #+#    #+#             */
/*   Updated: 2023/03/29 17:34:33 by seungjyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*mapped_lst;
	void	*ptr;

	if (!lst || !f)
		return (0);
	mapped_lst = 0;
	while (lst != 0)
	{
		ptr = f(lst->content);
		new = ft_lstnew(ptr);
		if (!new)
		{
			del(ptr);
			ft_lstclear(&mapped_lst, del);
			return (0);
		}
		ft_lstadd_back(&mapped_lst, new);
		lst = lst->next;
	}
	return (mapped_lst);
}
