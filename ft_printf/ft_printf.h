/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjyu <seungjyu@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 21:02:01 by seungjyu          #+#    #+#             */
/*   Updated: 2023/05/15 01:58:31 by seungjyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		check_format(const char *str, va_list *ap);
int		ft_swrite(char *str);
size_t	ft_cwrite(int c);
int		ft_pwrite(void *ptr);
int		ft_dwrite(int c);
int		ft_xwrite(int c, int case_x);
int		ft_uwrite(int c);

#endif
