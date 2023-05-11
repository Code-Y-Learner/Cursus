/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjyu <seungjyu@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:02:53 by seungjyu          #+#    #+#             */
/*   Updated: 2023/04/17 19:02:53 by seungjyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...);
int	check_format(const char *str, va_list ap);

int	check_format(const char *str, va_list ap)
{
	int	i;

	i = 0;
	if (str[i] == 's')
		i += ft_swrite(va_arg(ap, char *));
	else if (str[i] == 'c')
		i += ft_cwrite(va_arg(ap, int));
	else if (str[i] == '%')
		i += ft_cwrite('%');
	else if (str[i] == 'p')
		i += ft_pwrite(va_arg(ap, void *));
	else if (str[i] == 'i' || str[i] == 'd')
		i += ft_dwrite(va_arg(ap, int));
	else if (str[i] == 'u')
		i += ft_uwrite(va_arg(ap, int));
	else if (str[i] == 'x')
		i += ft_xwrite(va_arg(ap, int), 0);
	else if (str[i] == 'X')
		i += ft_xwrite(va_arg(ap, int), 1);
	return (i);
}

int ft_printf(const char *format, ...)
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
			buffer += check_format(&format[++i], ap);
		else
			buffer += ft_cwrite(format[i]);
		i++;
	}
	return (buffer);
}

int	ft_xwrite(int c, int case_x)
{
	int				i;
	unsigned int	nb;

	i = 0;
	nb = (unsigned) c;
	while (c)
	{
		c /= 16;
		i++;
	}
	if (nb > 15)
	{
		ft_xwrite(nb / 16, case_x);
		if (case_x == 0)
			ft_cwrite("0123456789abcdef"[nb % 16]);
		else
			ft_cwrite("0123456789ABCDEF"[nb % 16]);
	}
	else
		i += ft_cwrite(nb + '0');
	return (i);
}
