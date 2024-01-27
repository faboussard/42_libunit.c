/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguillon <dguillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:11:50 by dguillon          #+#    #+#             */
/*   Updated: 2024/01/14 18:08:10 by dguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	manage(const char *format, ssize_t *i, va_list var)
{
	if (format[*i + 1])
		*i += 1;
	else
		return (ft_put_char(format[*i]));
	if (format[*i] == 'c')
		return (ft_put_char((unsigned char)va_arg(var, int)));
	if (format[*i] == 's')
		return (str(va_arg(var, char *)));
	if (format[*i] == 'd' || format[*i] == 'i')
		return (put_nbr(va_arg(var, int)));
	if (format[*i] == 'u')
		return (put_nbr((size_t)va_arg(var, unsigned int)));
	if (format[*i] == 'x' || format[*i] == 'X')
		return (put_hexa((long long)va_arg(var, unsigned int), format[*i]));
	if (format[*i] == 'p')
		return (put_ptr(va_arg(var, unsigned long long)));
	if (format[*i] == '%')
		return (ft_put_char(format[*i]));
	if (*i > 0)
		return (write(1, format + (*i - 1), 1) + write(1, format + *i, 1));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	ssize_t	i;
	int		j;
	int		k;
	va_list	var;

	i = 0;
	j = 0;
	k = 0;
	if (!format)
		return (write(1, "(nil)", 5));
	va_start(var, format);
	while (i >= 0 && format[i])
	{
		if (format[i] != '%')
			j += ft_put_char(format[i]);
		else
			j += manage(format, &i, var);
		if (k > j || k == -1 || j < 0)
			return (va_end(var), -1);
		k = j;
		i++;
	}
	va_end(var);
	return (j);
}
