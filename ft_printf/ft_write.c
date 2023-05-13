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
#include <stdio.h>
#include "ft_printf.h"

int	ft_swrite(char *str)
{
	int		i;

	i = 0;
	if (str == 0)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	ft_cwrite(int c)
{
	char	letter;

	letter = (char)c;
	write(1, &letter, 1);
	return (1);
}

int	ft_pwrite(void *ptr)
{
	int					i;
	unsigned long long	add;
	char				address[17];

	i = 15;
	add = (unsigned long long)ptr;
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
	write(1, "0x", ++i + 2);
	while (address[i] == '0')
		i++;
	write(1, address + i, 16 - i);
	if (ptr == 0)
		write(1, address, --i - 14);
	return (18 - i);
}

int	ft_dwrite(int c)
{
	int		i;
	long	nb;

	i = -1;
	nb = c;
	if (nb < 0)
	{
		i += ft_cwrite('-');
		nb *= -1;
	}
	if (!c)
		i++;
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
