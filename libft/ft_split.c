/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:55:55 by mbrousse          #+#    #+#             */
/*   Updated: 2023/11/15 10:46:27 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

static int	ft_charcmp(char c, char ca)
{
	if (c == ca)
		return (1);
	return (0);
}

static void	ft_strncpy_c(char *dest, char const *src, int n)
{
	int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static int	ft_countword(char const *str, char ca)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (str[i])
	{
		if (ft_charcmp(str[i], ca) == 0)
		{
			c++;
			i++;
			while (ft_charcmp(str[i], ca) == 0 && str[i])
				i++;
		}
		else
			i++;
	}
	return (c);
}

static int	ft_mallloc_com(char const *s, int *arg, char **tab, char c)
{
	while (s[arg[2]] && ft_charcmp(s[arg[2]], c) == 0)
		arg[2] += 1;
	tab[arg[0]] = malloc(sizeof(char) * (arg[2] - arg[1] + 1));
	if (!tab[arg[0]])
	{
		arg[1] = 0;
		while (arg[1] != arg[0])
		{
			free(tab[arg[1]]);
			arg[1]++;
		}
		free(tab);
		return (0);
	}
	ft_strncpy_c(tab[arg[0]++], &s[arg[1]], arg[2] - arg[1]);
	arg[1] = arg[2];
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		arg[3];
	char	**tab;

	if (!s)
		return (NULL);
	arg[0] = 0;
	arg[1] = 0;
	arg[2] = ft_countword(s, c);
	tab = malloc(sizeof(char *) * (arg[2] + 1));
	if (!tab)
		return (NULL);
	while (s[arg[1]])
	{
		arg[2] = arg[1];
		if (ft_charcmp(s[arg[1]], c) == 0)
		{
			if (ft_mallloc_com(s, arg, tab, c) == 0)
				return (NULL);
		}
		else
			arg[1]++;
	}
	tab[arg[0]] = NULL;
	return (tab);
}
