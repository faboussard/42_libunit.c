/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguillon <dguillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:38:40 by dguillon          #+#    #+#             */
/*   Updated: 2023/11/27 14:47:32 by dguillon         ###   ########.fr       */
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

static size_t	ft_lcmp(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	int		b;

	i = 0;
	j = 0;
	b = 1;
	while (b && s1[i])
	{
		while ((s1[i] != set[j] && set[j]))
			j++;
		if (s1[i] == set[j])
			i++;
		else
			b = 0;
		j = 0;
	}
	return (i);
}

static size_t	ft_rcmp(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	int		b;

	i = ft_strl(s1) - 1;
	j = 0;
	b = 1;
	if (s1 == 0)
		b = 0;
	while (b)
	{
		while ((s1[i] != set[j] && set[j]))
			j++;
		if (s1[i] == set[j])
			i--;
		else if (s1[i] != set[j] || i == 0)
			b = 0;
		j = 0;
	}
	if (i != 0)
		i += 1;
	return (i);
}

static size_t	ft_cmp(char const *s1, char const *set, size_t *start)
{
	size_t		i;
	size_t		j;
	long long	result;

	i = ft_lcmp(s1, set);
	j = ft_rcmp(s1, set);
	result = j - i;
	if (result < 0)
		result = 0;
	*start = i;
	return (result);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	len;
	size_t	i;
	char	*strt;

	start = 0;
	len = ft_cmp(s1, set, &start);
	i = 0;
	strt = malloc((len + 1) * sizeof(char));
	if (!strt)
		return (0);
	while (i < len)
	{
		strt[i] = s1[start];
		start++;
		i++;
	}
	strt[i] = '\0';
	return (strt);
}
