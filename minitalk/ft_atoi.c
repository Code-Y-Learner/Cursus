/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjyu <seungjyu@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:30:02 by seungjyu          #+#    #+#             */
/*   Updated: 2023/10/19 16:01:28 by seungjyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_check(int pm, unsigned long long num)
{
	if (num >= 9223372036854775807)
	{
		if (pm == 1)
			return (-1);
		else if (num > 9223372036854775807 && pm == -1)
			return (0);
	}
	return ((int)(num * pm));
}

int	ft_atoi(const char *str)
{
	int					pm;
	unsigned long long	nb;

	pm = 1;
	nb = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			pm *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb *= 10;
		nb += *str - '0';
		str++;
	}
	return (ft_check(pm, nb));
}
