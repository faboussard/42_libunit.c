/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguillon <dguillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:43:05 by dguillon          #+#    #+#             */
/*   Updated: 2024/01/14 18:01:21 by dguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	str(char *s)
{
	ssize_t	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		if (write(1, s + i, 1) == -1)
			return (-1);
		i++;
		if (i < 0)
			return (-1);
	}
	return (i);
}

int	ft_put_char(unsigned char c)
{
	return (write(1, &c, 1));
}
