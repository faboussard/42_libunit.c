/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa  <faboussa@student.42lyon.f>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:02:35 by faboussa          #+#    #+#             */
/*   Updated: 2024/01/27 13:02:35 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:27:47 by marvin            #+#    #+#             */
/*   Updated: 2023/11/27 14:30:16 by dguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cnt(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	ft_convchar(int n, int size)
{
	char	c;

	while (size - 1 > 0)
	{
		n /= 10;
		size --;
	}
	if (n >= 0)
		c = (n % 10) + 48;
	else
		c = ((n % 10) * -1) + 48;
	return (c);
}

static void	ft_wrnbr(int n, int fd, int size)
{
	char	c;

	c = 0;
	while (size > 0)
	{
		c = ft_convchar(n, size);
		write(fd, &c, 1);
		size--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int	i;

	if (n == 0)
		write(fd, "0", 1);
	else
	{
		i = ft_cnt(n);
		if (n < 0)
			write(fd, "-", 1);
		ft_wrnbr(n, fd, i);
	}
}
