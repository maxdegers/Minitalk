/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 22:06:07 by mbrousse          #+#    #+#             */
/*   Updated: 2024/01/18 17:36:28 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_printtf_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_printtf_strlen(str)));
}

int	ft_putnbr(int n)
{
	int				c;
	unsigned int	nbr;

	c = 0;
	if (n < 0)
	{
		c += ft_putchar('-');
		n *= -1;
	}
	nbr = n;
	if (nbr > 9)
		c += ft_putnbr(nbr / 10);
	return (c + ft_putchar(nbr % 10 + '0'));
}

int	ft_putunsigned(unsigned int n)
{
	int	c;

	c = 0;
	if (n > 9)
	{
		c += ft_putnbr(n / 10);
		c += ft_putnbr(n % 10);
	}
	else
	{
		c += ft_putchar(n + '0');
	}
	return (c);
}
