/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 01:56:08 by mochenna          #+#    #+#             */
/*   Updated: 2024/05/08 15:51:58 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
void handling_signal(int signal, siginfo_t *info, void *m)
{
    static pid_t    pid;
    static int      c;
    static int      bit;

    (void)m;
    c |= (signal == SIGUSR1);
    if (pid != info->si_pid)
    {
        c = 0;
        bit = 0;
    }
    if (++bit == 8)
    {
        write(1, &c, 1);
        bit = 0;
        c = 0;
    }
    else
        c <<= 1;
    pid = info->si_pid; 
}

int main(void)
{
    pid_t pid;

    pid = getpid();
    struct sigaction sa;
    sa.sa_sigaction = handling_signal;
    sa.sa_flags = SA_SIGINFO;
    printstr("pid ==> ");
    printint(pid);
    write(1,"\n",1);
    printstr("waiting for your message...\n");
    sigaction(SIGUSR1, &sa,NULL);
    sigaction(SIGUSR2, &sa,NULL);
    while (1)
        pause();
    return 0;
}