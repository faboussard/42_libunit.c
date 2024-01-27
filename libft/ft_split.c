/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguillon <dguillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:18:41 by dguillon          #+#    #+#             */
/*   Updated: 2023/11/27 14:34:09 by dguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cntw(const char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			j++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (j);
}

static size_t	ft_sz(const char *str, char c, size_t *start, size_t *end)
{
	size_t	size;

	size = 0;
	while (str[*end] && str[*end] == c)
		*end += 1;
	*start = *end;
	while (str[*end] && str[*end] != c)
		*end += 1;
	size = *end - *start;
	return (size);
}

static void	ft_puts(char *strspl, const char *s, size_t start, size_t end)
{
	size_t	i;

	i = 0;
	while (start < end)
	{
		strspl[i] = s[start];
		i++;
		start++;
	}
	strspl[i] = '\0';
}

static int	ft_puttab(char **strs, size_t len)
{
	if (!strs[len])
	{
		while (len > 0)
		{
			if (strs[len])
				free(strs[len]);
			len--;
		}
		free (strs[len]);
		free (strs);
		return (1);
	}
	return (0);
}

char	**ft_split(const char *s, char c)
{
	size_t	len;
	size_t	i;
	size_t	st;
	size_t	nd;
	char	**strs;

	len = ft_cntw(s, c);
	i = 0;
	st = 0;
	nd = 0;
	strs = malloc((len + 1) * sizeof (char *));
	if (!strs)
		return (0);
	while (i < len)
	{
		strs[i] = malloc((ft_sz(s, c, &st, &nd) + 1) * sizeof (char));
		if (ft_puttab(strs, i))
			return (0);
		ft_puts(strs[i], s, st, nd);
		i++;
	}
	strs[i] = 0;
	return (strs);
}
