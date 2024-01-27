/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguillon <dguillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:20:34 by dguillon          #+#    #+#             */
/*   Updated: 2023/11/27 16:44:41 by dguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strl(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	size_t	i;
	size_t	j;
	char	*cln;

	i = 0;
	j = ft_strl(src);
	cln = malloc((j + 1) * sizeof(char));
	if (!cln)
		return (0);
	while (src[i])
	{
		cln[i] = src[i];
		i++;
	}
	cln[i] = '\0';
	return (cln);
}
