/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguillon <dguillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:52:21 by dguillon          #+#    #+#             */
/*   Updated: 2023/11/27 16:37:07 by dguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int srchc)
{
	size_t	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == (unsigned char)srchc)
			return (((char *)string) + i);
		i++;
	}
	if (string[i] == (unsigned char)srchc)
		return (((char *)string) + i);
	return (0);
}
