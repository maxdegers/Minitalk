/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 22:34:49 by mbrousse          #+#    #+#             */
/*   Updated: 2023/11/08 14:40:10 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i_s;
	unsigned int	i;
	unsigned int	length_dest;
	unsigned int	length_src;

	i_s = 0;
	length_dest = ft_strlen(dest);
	length_src = ft_strlen(src);
	i = length_dest;
	if (size == 0)
		return (length_src);
	while (src[i_s] && i < size - 1)
	{
		dest[i] = src[i_s];
		i++;
		i_s++;
	}
	dest[i] = '\0';
	if (size < length_dest)
		return (length_src + size);
	return (length_src + length_dest);
}
