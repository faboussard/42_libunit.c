/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrong_ft_lstsize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:56:36 by faboussa          #+#    #+#             */
/*   Updated: 2024/01/28 17:56:40 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libunit.h"

int	ft_lstsize_ko(t_list *lst)
{
	int		i;
	t_list	*p;

	i = 0;
	if (lst == 0)
		return (0);
	p = lst;
	while (p)
	{
		i += 20;
		p = p->next;
	}
	return (i);
}
