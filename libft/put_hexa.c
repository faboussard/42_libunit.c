/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hexa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguillon <dguillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:58:31 by dguillon          #+#    #+#             */
/*   Updated: 2024/01/11 13:10:14 by dguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_hexa_len(unsigned long long n)
{
	size_t	i;

	i = 0;
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

static unsigned long long	div_long(unsigned long long u, size_t len)
{
	while (len-- > 0)
		u /= 16;
	return (u);
}

int	put_hexa(unsigned long long n, char x)
{
	size_t			len;
	char			c;
	unsigned long	i;
	int				j;

	if (n == 0)
		return (write(1, "0", 1));
	len = ft_hexa_len(n);
	j = len;
	c = 0;
	while (len-- > 0)
	{
		i = div_long(n, len);
		if (x == 'x')
			c = HEXA_LOW[i % 16];
		else
			c = HEXA_UP[i % 16];
		if (write(1, &c, 1) == -1)
			return (-1);
	}
	return (j);
}

int	put_ptr(unsigned long long p)
{
	size_t			len;
	char			c;
	unsigned long	i;
	int				j;

	if (p == 0)
		return (write(1, "(nil)", 5));
	len = ft_hexa_len(p);
	j = len + 2;
	c = 0;
	if (write(1, "0x", 2) == -1)
		return (-1);
	while (len-- > 0)
	{
		i = div_long(p, len);
		c = HEXA_LOW[i % 16];
		if (write(1, &c, 1) == -1)
			return (-1);
	}
	return (j);
}
