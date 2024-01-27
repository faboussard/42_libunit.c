/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguillon <dguillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:24:10 by dguillon          #+#    #+#             */
/*   Updated: 2023/11/27 16:38:52 by dguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strl(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strrchr(const char *string, int srchc)
{
	size_t	i;

	i = ft_strl(string) + 1;
	while (i-- > 0)
	{
		if (string[i] == (unsigned char)srchc)
			return (((char *) string) + i);
	}
	return (0);
}
