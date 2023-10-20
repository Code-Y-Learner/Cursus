/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjyu <seungjyu@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:29:11 by seungjyu          #+#    #+#             */
/*   Updated: 2023/10/19 15:41:37 by seungjyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	get_pid(void)
{
	int	i;

	i = getpid();
	ft_printf("Server PID number : %d\n", i);
}

void	take_bit(int sig)
{
	static int	bit;
	static int	bit_count;

	bit <<= 1;
	if (sig == SIGUSR1)
		bit |= 1;
	bit_count++;
	if (bit_count == 8)
	{
		ft_printf("%c", bit);
		bit = 0;
		bit_count = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sig;

	(void)argc;
	(void)argv;
	sig.sa_handler = take_bit;
	if (sigaction(SIGUSR1, &sig, NULL) == -1)
		ft_printf("Sigaction Error");
	if (sigaction(SIGUSR2, &sig, NULL) == -1)
		ft_printf("Sigaction Error");
	get_pid();
	while (1)
		continue ;
}
