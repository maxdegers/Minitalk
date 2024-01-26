/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:23:35 by mbrousse          #+#    #+#             */
/*   Updated: 2023/11/13 17:02:40 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*pt;
	t_list	*npt;

	if (!lst || !*lst || !del)
		return ;
	pt = *lst;
	while (pt)
	{
		npt = pt->next;
		del(pt->content);
		free(pt);
		pt = npt;
	}
	*lst = NULL;
}
