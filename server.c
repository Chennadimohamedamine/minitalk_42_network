/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 01:56:08 by mochenna          #+#    #+#             */
/*   Updated: 2024/05/05 01:30:18 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(void)
{
    int pid;

    pid = getpid();
    printstr("pid ==> ");
    printint(pid);
    write(1,"\n",1);
    printstr("waiting for your message...\n");
    while (1)
        pause();
    return 0;
}