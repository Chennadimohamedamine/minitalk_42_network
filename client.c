/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 01:56:02 by mochenna          #+#    #+#             */
/*   Updated: 2024/05/08 16:05:03 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void  check(int c, char *s)
{
    int i;

    if (c != 3)
    {
        printstr("write like this [pid server] [message]\n");
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
void send_message(int pid, int c)
{
    int i;
    int k;

    i = 7;
    while (i >= 0)
    {
        if ((c >> i) & 1)
            k = kill(pid,SIGUSR1);
        else 
            k = kill(pid,SIGUSR2);
        if (k == -1)
        {
            printstr("we have error int kill function \n");
            exit(1);
        }
        usleep(450);
        i--;
    }
}

int main(int ac, char **av)
{
    int i;
    int pid;
    
    check(ac, av[1]);
    pid = convertint(av[1]);
    if (pid > MAX_PID)
        return (1);
    i = 0;
    while (av[2][i])
        send_message(pid, av[2][i++]);
    send_message(pid, '\0');

    return 0;
}

