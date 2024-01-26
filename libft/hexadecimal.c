/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:42:33 by mbrousse          #+#    #+#             */
/*   Updated: 2024/01/09 13:53:55 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lenhex(unsigned	int nbr)
{
	int	len;

	len = 0;
	while (nbr != 0)
	{
		len++;
		nbr = nbr / 16;
	}
	return (len);
}

static void	ft_rec(unsigned int nbr, char *base)
{
	if (nbr >= 16)
	{
		ft_rec(nbr / 16, base);
		ft_rec(nbr % 16, base);
	}
	else
		ft_putchar(base[nbr]);
}

int	ft_puthexadecimal(unsigned int nbr, char *base)
{
	if (nbr == 0)
		return (ft_putchar('0'));
	else
		ft_rec(nbr, base);
	return (ft_lenhex(nbr));
}
