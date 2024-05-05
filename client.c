/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 01:56:02 by mochenna          #+#    #+#             */
/*   Updated: 2024/05/05 02:42:54 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_message(int pid, int c)
{
    int i;
    int k;

    i = 0;
    while (i < 8)
    {
        if ((c << 1) && 1)
            k = kill(pid,SIGUSR1);
        else 
            k = kill(pid,SIGUSR2);  
        i++;
    }
}

int main(int ac, char **av)
{
    int i;
    int pid;
     
    if (ac != 3)
    {
        printstr("write like this [pid server] [message]\n");
        exit(1);
    }
    pid = convertint(av[1]);
    i = 0;
    while (av[2][i])
        send_message(pid, av[2][i++]);
    return 0;
}

