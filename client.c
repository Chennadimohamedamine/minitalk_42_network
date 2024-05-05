/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 01:56:02 by mochenna          #+#    #+#             */
/*   Updated: 2024/05/05 01:15:44 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int ac, char **av)
{
    int r;
     
    if (ac != 3)
    {
        write(1,"write like this [pid server] [message]\n",40);
        exit(1);
    }
    r = convertint(av[1]);
    return 0;
}

