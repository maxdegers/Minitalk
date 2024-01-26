/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:59:43 by mbrousse          #+#    #+#             */
/*   Updated: 2023/11/15 10:43:26 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static void	ft_movstart(int *start, char const *s1, char const *set)
{
	while (ft_is(s1[*start], set) == 1)
		*start += 1;
}

static void	ft_movend(int *end, char const *s1, char const *set)
{
	while (ft_is(s1[*end], set) == 1)
		*end -= 1;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*f;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	i = 0;
	end = ft_strlen(s1) - 1;
	ft_movstart(&start, s1, set);
	if (start != end + 1)
		ft_movend(&end, s1, set);
	f = malloc(sizeof(char) * ((end - start) + 2));
	if (!f)
		return (NULL);
	while (start <= end)
	{
		f[i] = s1[start];
		i++;
		start++;
	}
	f[i] = 0;
	return (f);
}
