/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguillon <dguillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:03:29 by dguillon          #+#    #+#             */
/*   Updated: 2023/11/27 16:41:37 by dguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memblck, int srchc, size_t size)
{
	size_t			i;
	unsigned char	*m;

	i = 0;
	m = (unsigned char *)memblck;
	while (size > 0)
	{
		if (m[i] == (unsigned char) srchc)
			return (((void *)memblck) + i);
		size--;
		i++;
	}
	return (0);
}
