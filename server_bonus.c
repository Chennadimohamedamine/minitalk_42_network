/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:25:27 by mochenna          #+#    #+#             */
/*   Updated: 2024/05/27 23:26:03 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handling_signal(int signal, siginfo_t *info, void *m)
{
	static pid_t	pid;
	static int		c;
	static int		bit;

	(void)m;
	if (pid != info->si_pid)
	{
		c = 0;
		bit = 0;
	}
	c |= (signal == SIGUSR1);
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
		if (c == 0)
			if (kill(info->si_pid, SIGUSR1) == -1)
				handling_error("illegal pid [please inter correct pid] \n");
		bit = 0;
		c = 0;
	}
	else
		c <<= 1;
	pid = info->si_pid;
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	sa.sa_sigaction = handling_signal;
	sa.sa_flags = SA_SIGINFO;
	printstr("pid ==> ");
	printint(pid);
	write(1, "\n", 1);
	printstr("waiting for your message...\n");
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
