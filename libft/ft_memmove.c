/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguillon <dguillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:18:19 by dguillon          #+#    #+#             */
/*   Updated: 2023/11/27 16:35:30 by dguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_puts(unsigned char *d, unsigned char *s, size_t size)
{
	unsigned long	i;

	i = 0;
	while (i < size)
	{
		d[i] = s[i];
		i++;
	}
}

static void	ft_rputs(unsigned char *d, unsigned char *s, size_t size)
{
	unsigned long	i;

	i = size;
	while (i-- > 0)
		d[i] = s[i];
}

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char *) src;
	d = (unsigned char *) dest;
	if (size == 0 || (dest == 0 && src == 0))
		return (dest);
	if (dest > src)
		ft_rputs(d, s, size);
	else
		ft_puts(d, s, size);
	return (dest);
}
