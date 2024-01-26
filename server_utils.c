/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:47:55 by mbrousse          #+#    #+#             */
/*   Updated: 2024/01/26 18:17:09 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

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
	if (i == 7)
	{
		ft_putbin(tab, 8);
        while (i > 0)
            tab[i--] = -1;
	}
	
}