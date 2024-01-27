/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguillon <dguillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:43:33 by dguillon          #+#    #+#             */
/*   Updated: 2024/01/11 13:12:37 by dguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_gnl(char *str, t_bool *b)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
	{
		*b = FALSE;
		i++;
	}
	return (i);
}

void	ft_bzero_gnl(char *str, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
}

char	*ft_calloc_gnl(size_t size)
{
	char	*str;

	str = malloc((size + 1) * sizeof (char));
	if (!str)
		return (NULL);
	ft_bzero_gnl(str, size + 1);
	return (str);
}

void	ft_memmove_gnl(char	*buff)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	while (buff[i])
	{
		buff[j] = buff[i];
		i++;
		j++;
	}
	ft_bzero_gnl(&buff[j], i - j);
}

void	ft_strcat_gnl(char *dest, char *src)
{
	size_t	dest_len;
	size_t	k;

	if (!src || !dest)
		return ;
	dest_len = 0;
	while (dest[dest_len])
		dest_len++;
	k = 0;
	while (src[k] && src[k] != '\n')
	{
		dest[dest_len] = src[k];
		dest_len++;
		k++;
	}
	if (src[k] == '\n')
	{
		dest[dest_len] = '\n';
		dest_len++;
	}
	dest[dest_len] = '\0';
}
