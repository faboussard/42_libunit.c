/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguillon <dguillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:53:09 by dguillon          #+#    #+#             */
/*   Updated: 2023/11/28 16:02:11 by dguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*tmp;

	if (!lst || !(*f) || !(*del))
		return (NULL);
	newlst = malloc(sizeof (t_list));
	if (!newlst)
		return (NULL);
	newlst->content = (*f)(lst->content);
	tmp = newlst;
	while (lst->next)
	{
		lst = lst->next;
		tmp->next = malloc (sizeof (t_list));
		if (!tmp->next)
			return (ft_lstclear(&newlst, del), NULL);
		tmp = tmp->next;
		tmp->content = (*f)(lst->content);
	}
	tmp->next = 0;
	return (newlst);
}
