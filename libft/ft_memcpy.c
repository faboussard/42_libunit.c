/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguillon <dguillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:34:32 by dguillon          #+#    #+#             */
/*   Updated: 2023/11/27 16:30:51 by dguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, void *src, size_t size)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	i = 0;
	s = src;
	d = dest;
	if (d == 0 && s == 0)
		return (0);
	while (i < size)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
