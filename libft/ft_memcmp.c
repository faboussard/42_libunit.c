/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguillon <dguillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:43:29 by dguillon          #+#    #+#             */
/*   Updated: 2023/11/27 16:42:49 by dguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *p1, const void *p2, size_t size)
{
	size_t				i;
	const unsigned char	*tab1;
	const unsigned char	*tab2;

	i = 0;
	if (!p1 && !p2)
		return (0);
	tab1 = p1;
	tab2 = p2;
	while (i < size)
	{
		if (tab1[i] != tab2[i])
			return (tab1[i] - tab2[i]);
		i++;
	}
	return (0);
}
