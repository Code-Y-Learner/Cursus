/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjyu <seungjyu@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:26:22 by seungjyu          #+#    #+#             */
/*   Updated: 2023/03/29 03:04:15 by seungjyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa(int n);
int		ft_len(long nb);

int	ft_len(long nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		len;

	nb = n;
	len = ft_len(nb);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	str[len--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		nb = (long)n * -1;
	}
	if (n == 0)
		str[0] = '0';
	while (nb)
	{
		str[len--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
