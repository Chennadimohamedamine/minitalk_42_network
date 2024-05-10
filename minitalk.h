/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 01:59:03 by mochenna          #+#    #+#             */
/*   Updated: 2024/05/10 15:44:22 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <signal.h>

# define MAX_PID 99998
// #define MAX_PID 99998

int		convertint(char *str);
void	printstr(char *str);
void	printint(int i);
void	send_message(char *s, int pid);
void	handling_error(char *s);
#endif