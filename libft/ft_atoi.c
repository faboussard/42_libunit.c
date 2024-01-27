/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguillon <dguillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:57:07 by dguillon          #+#    #+#             */
/*   Updated: 2023/11/27 16:48:09 by dguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_skipspace(char *str, size_t *i)
{
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		*i += 1;
}

static int	ft_calc(char *str, size_t i, int sign)
{
	long int	result;

	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((result * 10 + (sign * (str[i] - 48)) >= result && sign > 0)
			|| ((result * 10 + (sign * (str[i] - 48)) <= result && sign < 0)))
			result = result * 10 + (sign * (str[i] - 48));
		else
		{
			if (sign > 0)
				return (-1);
			return (0);
		}
		i++;
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;

	i = 0;
	sign = 1;
	ft_skipspace((char *)str, &i);
	if (((char *)str)[i] == '-' || ((char *)str)[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	return (ft_calc((char *)str, i, sign));
}
