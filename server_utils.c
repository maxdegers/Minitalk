/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:47:55 by mbrousse          #+#    #+#             */
/*   Updated: 2024/02/06 17:24:03 by mbrousse         ###   ########.fr       */
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
static int    ft_putbin(int *tab, pid_t pid_client)
{
    int i;
    int r;

    i = 0;
    r = 0;
    while (i < 8)
    {
        r += ft_recursive_power(2, 7 - i) * tab[i];
        i++;
    }
	if (r == '\0')
		kill(pid_client, SIGUSR2);
    ft_printf("%c", r);
	return (1);
}

void	handler(int signal, siginfo_t *info, void *ucontext)
{
	static size_t   i = 0;
	static int  	tab[8];
	pid_t			pid_client;

	(void) ucontext;
	pid_client = info->si_pid;
	if (signal == SIGUSR1)
	{
		tab[i++] = 0;
		kill(pid_client, SIGUSR1);
	}
	if (signal == SIGUSR2)
	{
		tab[i++] = 1;
		kill(pid_client, SIGUSR1);
	}
	if (i == 8)
	{
		
		if ((ft_putbin(tab, pid_client) != 1))
			return ;
        while (i > 0)
            tab[i--] = 0;
        tab[i] = 0;
    }
}