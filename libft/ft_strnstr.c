/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguillon <dguillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:10:01 by dguillon          #+#    #+#             */
/*   Updated: 2023/11/27 15:56:36 by dguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cmp(const char *big, const char *ltl, size_t i, size_t size)
{
	size_t	j;

	j = 0;
	while (big[i] && ltl[j] && i < size)
	{
		if (big[i] == ltl[j])
			j++;
		else
			return (0);
		if (ltl[j] == '\0')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *big, const char *ltl, size_t size)
{
	size_t	i;

	i = 0;
	if (ltl[i] == '\0')
		return ((char *)big);
	while (big[i] && i < size)
	{
		if (ft_cmp(big, ltl, i, size))
			return (((char *)big) + i);
		i++;
	}
	return (0);
}
