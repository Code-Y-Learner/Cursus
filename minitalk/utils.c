/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjyu <seungjyu@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:30:25 by seungjyu          #+#    #+#             */
/*   Updated: 2023/10/19 16:24:46 by seungjyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_cwrite(int c)
{
	char	letter;

	letter = (char)c;
	return (write(1, &letter, 1));
}

int	ft_dwrite(int c)
{
	int		i;
	long	nb;

	i = 0;
	nb = c;
	if (nb < 0)
	{
		i += ft_cwrite('-');
		nb *= -1;
	}
	if (nb > 9)
	{
		i += ft_dwrite(nb / 10);
		i += ft_cwrite(nb % 10 + '0');
	}
	else
		i += ft_cwrite(nb + '0');
	return (i);
}

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

int	check_format(const char *str, va_list *ap)
{
	int	i;

	i = 0;
	if (str[i] == 's')
		i += ft_swrite(va_arg(*ap, char *));
	else if (str[i] == 'c')
		i += ft_cwrite(va_arg(*ap, int));
	else if (str[i] == 'd')
		i += ft_dwrite(va_arg(*ap, int));
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		buffer;
	va_list	ap;

	i = 0;
	buffer = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
			buffer += check_format(&format[++i], &ap);
		else
			buffer += ft_cwrite(format[i]);
		i++;
	}
	va_end(ap);
	return (buffer);
}
