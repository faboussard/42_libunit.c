/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguillon <dguillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:35:57 by dguillon          #+#    #+#             */
/*   Updated: 2023/11/28 14:59:24 by dguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	p = *lst;
	while (p)
	{
		(*del)(p->content);
		tmp = p->next;
		free(p);
		p = tmp;
	}
	*lst = 0;
}
