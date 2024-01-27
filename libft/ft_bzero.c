/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguillon <dguillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:06:49 by dguillon          #+#    #+#             */
/*   Updated: 2023/11/27 16:28:38 by dguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *pointer, size_t size)
{
	size_t			i;
	unsigned char	*p1;

	i = 0;
	p1 = pointer;
	while (i < size)
	{
		p1[i] = '\0';
		i++;
	}
	return (pointer);
}
