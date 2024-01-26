/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:51:27 by mbrousse          #+#    #+#             */
/*   Updated: 2023/11/15 10:57:38 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char)c == s[i])
			return (&((char *)s)[i]);
		i++;
	}
	if ((unsigned char)c == 0)
	{
		return (((char *)s) + i);
	}
	return (0);
}
