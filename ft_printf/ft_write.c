/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjyu <seungjyu@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:39:43 by seungjyu          #+#    #+#             */
/*   Updated: 2023/05/05 16:39:43 by seungjyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_swrite(char *str)
{
	int		i;
	char	*ptr;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	return (0);
}

int	ft_cwrite(int c)
{
	write(1, &c, 1);
}
