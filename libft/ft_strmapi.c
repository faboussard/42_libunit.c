/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguillon <dguillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:22:06 by dguillon          #+#    #+#             */
/*   Updated: 2023/11/27 14:40:29 by dguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strl(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			j;
	char			*scpy;

	i = 0;
	j = ft_strl(s);
	if (f == 0 || s == 0)
		return (0);
	scpy = malloc((j + 1) * sizeof(char));
	if (!scpy)
		return (0);
	while (s[i])
	{
		scpy[i] = (*f)(i, s[i]);
		i++;
	}
	scpy[i] = '\0';
	return (scpy);
}
