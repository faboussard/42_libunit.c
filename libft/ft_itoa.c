/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguillon <dguillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:24:15 by dguillon          #+#    #+#             */
/*   Updated: 2023/11/22 15:53:19 by dguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcnt(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	ft_putzero(char *str, int n)
{
	char	c;

	c = 0;
	if (n == 0)
		str[0] = '-';
	else if (n < 0)
	{
		c = (n * -1) + 48;
		str[0] = c;
	}
	else
	{
		c = n + 48;
		str[0] = c;
	}
}

static void	ft_putn(char *str, int n, int i)
{
	char	c;

	c = 0;
	str[i] = '\0';
	i--;
	while (i > 0)
	{
		if (n < 0)
			c = ((n % 10) * -1) + 48;
		else
			c = (n % 10) + 48;
		n /= 10;
		str[i] = c;
		i--;
	}
	ft_putzero(str, n);
}

static void	ft_putstr(char *str, int n, int i)
{
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	else
		ft_putn(str, n, i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*tab;

	i = ft_strcnt(n);
	if (n <= 0)
	{
		tab = malloc((i + 2) * sizeof(char));
		if (!tab)
			return (0);
		ft_putstr(tab, n, i + 1);
	}
	else
	{
		tab = malloc(i + 1 * sizeof(char));
		if (!tab)
			return (0);
		ft_putstr(tab, n, i);
	}
	return (tab);
}
