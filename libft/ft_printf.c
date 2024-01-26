/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:35:48 by mbrousse          #+#    #+#             */
/*   Updated: 2024/01/09 13:53:49 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	table(const char c, va_list args)
{
	int	print_c;

	print_c = 0;
	if (c == 'c')
		print_c += ft_putchar(va_arg(args, int));
	else if (c == 's')
		print_c += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		print_c += ft_putpoint(va_arg(args, unsigned long long) \
		, "0123456789abcdef");
	else if (c == 'd' || c == 'i')
		print_c += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		print_c += ft_putunsigned(va_arg(args, unsigned int));
	else if (c == 'x')
		print_c += ft_puthexadecimal(va_arg(args, unsigned int) \
		, "0123456789abcdef");
	else if (c == 'X')
		print_c += ft_puthexadecimal(va_arg(args, unsigned int) \
		, "0123456789ABCDEF");
	else if (c == '%')
		print_c += ft_putchar('%');
	return (print_c);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_c;
	int		tmp;

	i = 0;
	print_c = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			tmp = table(str[i + 1], args);
			if (tmp == -1)
				return (-1);
			print_c += tmp;
			i++;
		}
		else
			print_c += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (print_c);
}
