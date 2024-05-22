/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:25:24 by mochenna          #+#    #+#             */
/*   Updated: 2024/05/22 16:23:14 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	convertint(char *str)
{
	int		i;
	long	r;
	int		s;

	i = 0;
	s = 1;
	r = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r *= 10;
		r += str[i++] - 48;
	}
	return (r * s);
}

void	check(int c, char *s)
{
	int	i;

	if (c != 3)
		handling_error("error : write like this [pid server] [message]\n");
	i = 0;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9') && s[i] != '-')
			handling_error("illegal pid [please inter correct pid] \n");
		i++;
	}
}

void	handling(int sig)
{
	(void)sig;
	printstr(">>============ message send ============<<\n");
}

int	main(int ac, char **av)
{
	int	pid;

	check(ac, av[1]);
	pid = convertint(av[1]);
	signal(SIGUSR1, handling);
	if (pid > MAX_PID)
		handling_error("illegal pid [please inter correct pid] \n");
	send_message(av[2], pid);
	return (0);
}
