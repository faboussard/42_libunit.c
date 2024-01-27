/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguillon <dguillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:09:51 by dguillon          #+#    #+#             */
/*   Updated: 2023/11/27 15:51:00 by dguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_zero(void *tab, size_t size)
{
	size_t			i;
	unsigned char	*t;

	i = 0;
	t = tab;
	while (i < size)
	{
		t[i] = '\0';
		i++;
	}
	return (tab);
}

void	*ft_calloc(size_t elcnt, size_t elsize)
{
	void	*tab;
	size_t	result;

	result = elcnt * elsize;
	if (result == 0 || result / elcnt != elsize)
		return (malloc(0));
	tab = malloc(result);
	if (!tab)
		return (0);
	tab = ft_zero(tab, result);
	return (tab);
}
