/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:41:11 by mbrousse          #+#    #+#             */
/*   Updated: 2024/01/26 19:21:16 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

static int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power < 2)
		return (nb);
	return (nb * ft_recursive_power(nb, power - 1));
}

void	ft_fillzero(int nbr, pid_t pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (ft_recursive_power(2, i) > nbr)
		{
			kill(pid, SIGUSR1);
			usleep(SLEEPTIME);
		}
		i--;
	}
}

void	ft_convert_client(int nbr, pid_t pid)
{
	static char *base = "01";

	if (nbr >= 2)
	{
		ft_convert_client(nbr / 2, pid);
		ft_convert_client(nbr % 2, pid);
	}
	else
	{
		if (base[nbr] == '0')
		{
			kill(pid, SIGUSR1);
			usleep(SLEEPTIME);
		}
		else if (base[nbr] == '1')
		{
			kill(pid, SIGUSR2);
			usleep(SLEEPTIME);
		}
	}
}
