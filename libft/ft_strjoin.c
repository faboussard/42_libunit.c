/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguillon <dguillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:00:03 by dguillon          #+#    #+#             */
/*   Updated: 2023/11/27 14:36:11 by dguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strl(char const *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

static char	*ft_strcat(char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = ft_strl(s1);
	j = 0;
	while (s2[j])
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}

static void	ft_zero(char *s, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		s[j] = '\0';
		j++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*sct;
	char	*str1;
	char	*str2;

	i = ft_strl(s1) + ft_strl(s2);
	str1 = (char *)s1;
	str2 = (char *)s2;
	sct = malloc((i + 1) * sizeof(char));
	if (!sct)
		return (0);
	ft_zero(sct, i + 1);
	ft_strcat(sct, str1);
	ft_strcat(sct, str2);
	return (sct);
}
