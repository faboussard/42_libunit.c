/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguillon <dguillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:13:50 by dguillon          #+#    #+#             */
/*   Updated: 2023/11/27 14:09:20 by dguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *_new)
{
	t_list	*p;

	if (lst == 0 || _new == 0)
		return ;
	p = ft_lstlast(*lst);
	if (p)
		p->next = _new;
	else
		*lst = _new;
}
