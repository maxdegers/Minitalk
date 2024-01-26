/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:47:55 by mbrousse          #+#    #+#             */
/*   Updated: 2024/01/26 19:30:01 by mbrousse         ###   ########.fr       */
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
static void    ft_putbin(int *tab)
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
    ft_printf("%c", r);
}

void    handler(int signal)
{
	static size_t   i = 0;
	static int  tab[8];
	if (signal == SIGUSR1)
	{
		tab[i++] = 0;
	}
	if (signal == SIGUSR2)
	{
		tab[i++] = 1;
	}
	if (i == 8)
	{
		ft_putbin(tab);
        while (i > 0)
            tab[i--] = 0;
        tab[i] = 0;
    }
}