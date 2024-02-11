/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:47:55 by mbrousse          #+#    #+#             */
/*   Updated: 2024/02/11 01:52:08 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

char	*g_str = NULL;

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

static int	ft_addchar(char c)
{
	char	*new;

	if (!g_str)
	{
		g_str = ft_calloc(sizeof(char), 2);
		if (!g_str)
			return (1);
		g_str[0] = c;
	}
	else
	{
		new = ft_calloc(sizeof(char), ft_strlen(g_str) + 2);
		if (!g_str)
			return (1);
		ft_memcpy(new, g_str, ft_strlen(g_str));
		free(g_str);
		g_str = new;
		g_str[ft_strlen(g_str)] = c;
	}
	return (0);
}

static int	ft_putbin(int *tab, pid_t pid_client)
{
	int				i;
	int				r;

	i = 0;
	r = 0;
	while (i < 8)
	{
		r += ft_recursive_power(2, 7 - i) * tab[i];
		i++;
	}
	if (r == '\0')
	{
		kill(pid_client, SIGUSR2);
		ft_printf("%s", g_str);
		free(g_str);
		g_str = NULL;
	}
	else
	{
		if (ft_addchar(r) != 0)
			return (1);
	}
	return (0);
}

void	handler(int signal, siginfo_t *info, void *ucontext)
{
	static size_t	i = 0;
	static int		tab[8];
	pid_t			pid_client;

	(void) ucontext;
	pid_client = info->si_pid;
	if (signal == SIGUSR1)
		tab[i++] = 0;
	if (signal == SIGUSR2)
		tab[i++] = 1;
	usleep(SLEEPTIME);
	kill(pid_client, SIGUSR1);
	if (i == 8)
	{
		if ((ft_putbin(tab, pid_client) != 0))
			return ;
		while (i > 0)
			tab[i--] = 0;
		tab[i] = 0;
	}
}
