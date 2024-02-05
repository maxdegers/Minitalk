/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:26:56 by mbrousse          #+#    #+#             */
/*   Updated: 2024/02/05 14:28:53 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

static void	handler_client(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_printf(".");
	}
	if (signal == SIGUSR2)
	{
		ft_printf("\nMessage Recive\n");
	}
	
	
}

int	main(int argc, char const **argv)
{
	int					i;
	struct sigaction	action;

	if (argc < 3)
		return (1);
	action.sa_handler = &handler_client;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	i = 0;
	while (argv[2][i])
	{
		ft_fillzero(argv[2][i], ft_atoi(argv[1]));
		ft_convert_client(argv[2][i], ft_atoi(argv[1]));
		i++;
	}
	i = 0;
	ft_fillzero(0, ft_atoi(argv[1]));
	return (0);
}
