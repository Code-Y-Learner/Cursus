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

#include <stdarg.h>
#include <stdio.h>
#include "ft_write.c"

int	ft_printf(const char *format, ...);
int	check_format(const char *str, va_list ap);

int	check_format(const char *str, va_list ap)
{
	int	i;

	i = 0;
	if (str[i] == 's')
		ft_swrite(va_arg(ap, char *));
	else if (str[i] == 'c')
		ft_cwrite(va_arg(ap, int));
	else if (str[i] == '%')
	return (0);
}

int ft_printf(const char *format, ...)
{
	int		i;
	va_list	ap;

	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
			check_format(&format[++i], ap);
		i++;
	}
	return (-1);
}


int	main(void)
{
	ft_printf("%c\n %s %s %c\n", 'a', "this is first\n", "this is second\n" , 'c');
}

