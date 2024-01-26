/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:11:38 by mbrousse          #+#    #+#             */
/*   Updated: 2023/11/15 13:08:59 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_nb_len(long int nb, long int *cont)
{
	if (nb < 0)
	{
		*cont += 1;
		ft_nb_len(nb * -1, cont);
	}
	else if (nb >= 10)
	{
		ft_nb_len(nb / 10, cont);
		ft_nb_len(nb % 10, cont);
	}
	else
	{
		*cont += 1;
	}
}

static void	ft_rec(long int nb, char *str, long int *i)
{
	if (nb < 0)
	{
		str[*i] = '-';
		*i += 1;
		ft_rec(nb * -1, str, i);
	}
	else if (nb >= 10)
	{
		ft_rec(nb / 10, str, i);
		ft_rec(nb % 10, str, i);
	}
	else
	{
		str[*i] = nb + '0';
		*i += 1;
	}
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	cont;

	cont = 0;
	ft_nb_len(n, &cont);
	str = malloc(sizeof(char) * cont + 1);
	if (!str)
		return (NULL);
	cont = 0;
	ft_rec(n, str, &cont);
	str[cont] = 0;
	return (str);
}
