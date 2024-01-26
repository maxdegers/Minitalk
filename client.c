/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:26:56 by mbrousse          #+#    #+#             */
/*   Updated: 2024/01/26 14:14:05 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

int main(int argc, char const **argv)
{
    if (argc < 2)
        return (1);
    ft_printf("%s\n", argv[1]);
    return 0;
}
