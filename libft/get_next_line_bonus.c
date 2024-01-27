/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguillon <dguillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:43:53 by dguillon          #+#    #+#             */
/*   Updated: 2024/01/11 13:09:30 by dguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strjoin_gnl(char *line, char *buff, t_bool *b);
size_t	ft_strlen_gnl(char *str, t_bool *b);
void	ft_bzero_gnl(char *str, size_t size);
char	*ft_calloc_gnl(size_t size);
void	ft_memmove_gnl(char	*buff);
void	ft_strcat_gnl(char *dest, char *src);
t_bool	checkread_gnl(char *buff, int fd, t_bool *b);
char	*searchline_gnl(char *buff, char *line, t_bool *b, int fd);

char	*get_next_line(int fd)
{
	static char	buff[1024][BUFFER_SIZE + 1] = {"\0"};
	char		*p;
	char		*line;
	t_bool		b;

	line = NULL;
	b = TRUE;
	if (fd == -1)
		return (NULL);
	p = buff[fd];
	if (checkread_gnl(p, fd, &b) < 1)
		return (NULL);
	line = ft_calloc_gnl(ft_strlen_gnl(p, &b));
	if (!line)
		return (NULL);
	ft_strcat_gnl(line, p);
	ft_memmove_gnl(p);
	if (b)
		return (searchline_gnl(p, line, &b, fd));
	return (line);
}

char	*strjoin_gnl(char *line, char *buff, t_bool *b)
{
	char	*newline;

	newline = ft_calloc_gnl((ft_strlen_gnl(line, b) + ft_strlen_gnl(buff, b))
			* sizeof (char));
	if (!newline)
	{
		b = FALSE;
		return (NULL);
	}
	ft_strcat_gnl(newline, line);
	ft_strcat_gnl(newline, buff);
	return (newline);
}

int	checkread_gnl(char *buff, int fd, t_bool *b)
{
	ssize_t		i;

	if (buff[0] == '\0')
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == 0)
		{
			*b = FALSE;
			return (0);
		}
		if (i == -1)
			return (-1);
	}
	return (1);
}

char	*searchline_gnl(char *buff, char *line, t_bool *b, int fd)
{
	char	*tmp;
	char	*newline;

	newline = strjoin_gnl(line, buff, b);
	free(line);
	while (*b)
	{
		tmp = ft_calloc_gnl(ft_strlen_gnl(newline, b));
		ft_strcat_gnl(tmp, newline);
		free(newline);
		ft_memmove_gnl(buff);
		if (checkread_gnl(buff, fd, b) == -1)
			return (NULL);
		newline = strjoin_gnl(tmp, buff, b);
		free(tmp);
	}
	ft_memmove_gnl(buff);
	return (newline);
}
