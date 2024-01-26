/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:23:44 by mbrousse          #+#    #+#             */
/*   Updated: 2023/11/15 10:45:53 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sizetot(char const *s1, char const *s2)
{
	int	size_tot;

	size_tot = ft_strlen(s1) + ft_strlen(s2);
	return (size_tot);
}

static void	ft_join(int *j, char const *str, char *des)
{
	int	i;

	i = 0;
	while (str[i])
	{
		des[*j] = str[i];
		*j += 1;
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	int		i;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_sizetot(s1, s2);
	tab = malloc(sizeof(char) * len + 1);
	if (!tab)
		return (tab);
	i = 0;
	ft_join(&i, s1, tab);
	ft_join(&i, s2, tab);
	tab[i] = '\0';
	return (tab);
}
