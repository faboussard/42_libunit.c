/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguillon <dguillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:41:30 by dguillon          #+#    #+#             */
/*   Updated: 2023/11/27 16:41:05 by dguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *first, const char *sec, size_t len)
{
	size_t			i;
	unsigned char	*f;
	unsigned char	*s;

	i = 0;
	f = (unsigned char *) first;
	s = (unsigned char *) sec;
	if (len == 0 || (!first && !sec))
		return (0);
	while (first[i] && sec[i] && i < len - 1 && first[i] == sec[i])
		i++;
	return (f[i] - s[i]);
}
