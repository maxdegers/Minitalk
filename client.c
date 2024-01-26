/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:26:56 by mbrousse          #+#    #+#             */
/*   Updated: 2024/01/26 17:57:49 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

int	main(int argc, char const **argv)
{
	int	i;

	if (argc < 3)
		return (1);
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
