/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:22:35 by mbrousse          #+#    #+#             */
/*   Updated: 2023/11/13 16:08:05 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	int		i_b;

	i = 0;
	if (len == 0 && !*s2)
		return ((char *)s1);
	while (s1[i] != '\0' && i < len)
	{
		i_b = 0;
		while (s1[i + i_b] == s2[i_b] && s2[i_b] != '\0')
		{
			if (i_b + i >= len)
				return (0);
			i_b++;
		}
		if (s2[i_b] == '\0')
			return (((char *)s1) + i);
		i++;
	}
	if (s1[0] == '\0' && s2[0] == '\0')
		return (((char *)s1));
	return (0);
}
