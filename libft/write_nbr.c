/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguillon <dguillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:55:05 by dguillon          #+#    #+#             */
/*   Updated: 2024/01/14 18:03:05 by dguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_len(long u)
{
	int	i;

	i = 0;
	while (u != 0)
	{
		u /= 10;
		i++;
	}
	return (i);
}

static long	div_nbr(long u, size_t len)
{
	while (len-- > 0)
		u /= 10;
	return (u);
}

static int	wr_nbr(long u, size_t len)
{
	char		c;
	long int	i;

	while (len > 0)
	{
		i = div_nbr(u, len - 1);
		if (i < 0)
			c = ((i % 10) * -1) + 48;
		else
			c = (i % 10) + 48;
		if (write(1, &c, 1) == -1)
			return (-1);
		len--;
	}
	return (0);
}

int	put_nbr(long u)
{
	int	len;

	if (u == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	len = nb_len(u);
	if (u < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		if (wr_nbr(u, len) == -1)
			return (-1);
		len++;
	}
	else
		if (wr_nbr(u, len) == -1)
			return (-1);
	return (len);
}
