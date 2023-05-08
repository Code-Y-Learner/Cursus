/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjyu <seungjyu@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:13:15 by seungjyu          #+#    #+#             */
/*   Updated: 2023/04/01 23:34:00 by seungjyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		tail;
	int		head;

	head = 0;
	if (!s1 || !set)
		return (0);
	while (s1[head] != '\0' && ft_strchr(set, s1[head]))
		head++;
	tail = ft_strlen(s1);
	while (tail != 0 && ft_strchr(set, s1[tail - 1]))
		tail--;
	if (head > tail)
		return (ft_strdup("\0"));
	str = ft_substr(s1, head, tail - head);
	if (!str)
		return (0);
	return (str);
}
