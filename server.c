/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:26:59 by mbrousse          #+#    #+#             */
/*   Updated: 2024/01/26 19:29:40 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"
//kill -TERM 0000


int main()
{
	pid_t   pid;

	pid = getpid();
	ft_printf("The PID is : %d\n", pid);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	
	while (1)
		pause();
	
	return 0;
}
