/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 06:28:21 by mochenna          #+#    #+#             */
/*   Updated: 2024/05/27 23:06:53 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handling_error(char *s)
{
	printstr(s);
	exit(1);
}

void	printstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	printint(int i)
{
	if (i > 9)
		printint(i / 10);
	write(1, &"0123456789"[i % 10], 1);
}

void	send(int pid, int c)
{
	int	i;
	int	k;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			k = kill(pid, SIGUSR1);
		else
			k = kill(pid, SIGUSR2);
		if (k == -1)
			handling_error("illegal pid [please inter correct pid] \n");
		usleep(450);
		i--;
	}
}

void	send_message(char *s, int pid)
{
	int	i;

	i = 0;
	while (s[i])
		send(pid, s[i++]);
	send(pid, '\0');
}
