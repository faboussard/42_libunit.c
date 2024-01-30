/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_null_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa  <faboussa@student.42lyon.f>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:45:27 by faboussa          #+#    #+#             */
/*   Updated: 2024/01/28 17:52:38 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libunit.h"
#include "../../header/tests.h"

int	null_test_lstsize(int (*my_function)(t_list *lst),
		int (*your_function)(t_list *lst))
{
	t_list	*newlist;
	void	*newcontent;
	int		my_result;
	int		your_result;
	int		i;

	i = 0;
	while (i++ < 3)
	{
		newcontent = NULL;
		if (newcontent == NULL)
			return (0);
		ft_lstadd_front(&newlist, newcontent);
	}
	your_result = your_function(newlist);
	my_result = my_function(newlist);
	if (my_result - your_result == 0)
		return (0);
	else
		return (-1);
}
