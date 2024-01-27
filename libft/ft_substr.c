/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguillon <dguillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:20:48 by dguillon          #+#    #+#             */
/*   Updated: 2023/11/27 14:48:50 by dguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strl(const char *s)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*cln;

	i = start;
	j = 0;
	if (i >= ft_strl(s))
		len = 0;
	else if (len + i > ft_strl(s))
		len = ft_strl(s) - start;
	cln = malloc((len + 1) * sizeof (char));
	if (!cln)
		return (0);
	while (j < len && s[i])
	{
		cln[j] = s[i];
		j++;
		i++;
	}
	cln[j] = '\0';
	return (cln);
}
