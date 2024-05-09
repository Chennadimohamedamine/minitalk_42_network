/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:25:24 by mochenna          #+#    #+#             */
/*   Updated: 2024/05/09 11:50:36 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	check(int c, char *s)
{
	int	i;

	if (c != 3)
	{
		printstr("error : write like this [pid server] [message]\n");
		exit(1);
	}
	i = 0;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9') && s[i] != '-')
		{
			printstr("illegal pid [please inter correct pid] \n");
			exit(1);
		}
		i++;
	}
}

void	handling(int sig)
{
	(void)sig;
	printstr("all good\n");
}

int	main(int ac, char **av)
{
	int	pid;

	check(ac, av[1]);
	pid = convertint(av[1]);
	signal(SIGUSR1, handling);
	if (pid > MAX_PID)
		return (1);
	send_message(av[2], pid);
	return (0);
}
