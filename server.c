/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:26:59 by mbrousse          #+#    #+#             */
/*   Updated: 2024/02/06 19:42:45 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	action;

	(void) argv;
	if (argc != 1)
	{
		ft_printf("Error: wrong format\n");
		ft_printf("Try: ./server\n");
		return (1);
	}
	action.sa_sigaction = &handler;
	action.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_printf("PID : %d\n", pid);
	ft_printf("Waiting for a message...\n");
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
