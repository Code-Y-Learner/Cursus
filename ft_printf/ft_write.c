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

#include <unistd.h>
#include "ft_printf.h"

int	ft_swrite(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	ft_cwrite(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_pwrite(void *ptr)
{
	int			i;
	long long	add;
	char		address[17];

	i = 15;
	add = (long long)ptr;
	address[16] = '\0';
	while (i >= 0)
	{
		if (add % 16 <= 9)
			address[i] = add % 16 + 48;
		else
			address[i] = add % 16 + 87;
		add /= 16;
		i--;
	}
	write(1, "0x", 2);
	i++;
	while (address[i] == '0')
		i++;
	write(1, address + i, 16 - i);
	return (2 + i);
}

int	ft_dwrite(int c)
{
	int		i;
	long	nb;

	i = 0;
	nb = c;
	if (nb < 0)
	{
		ft_cwrite('-');
		nb *= -1;
		i++;
	}
	while (c)
	{
		c /= 10;
		i++;
	}
	if (nb > 9)
	{
		ft_dwrite(nb / 10);
		ft_cwrite(nb % 10 + '0');
	}
	else
		i += ft_cwrite(nb + '0');
	return (i);
}

int	ft_uwrite(int c)
{
	int				i;
	unsigned int	nb;

	i = 0;
	nb = (unsigned) c;
	while (c)
	{
		c /= 10;
		i++;
	}
	if (nb > 9)
	{
		ft_uwrite(nb / 10);
		ft_cwrite(nb % 10 + '0');
	}
	else
		i += ft_cwrite(nb + '0');
	return (i);
}
