/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguillon <dguillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:02:20 by dguillon          #+#    #+#             */
/*   Updated: 2024/01/28 19:50:48 by dguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# include "../libft/libft.h"
# include <ctype.h>
# include <stddef.h>
# include <string.h>
# include <sys/wait.h>

int		to_launch(const int action, char flags);
void	result(int res, int b);

# define ATOI "atoi"
# define ITOA "itoa"
# define LSTSIZE "lstsize"
# define STRLEN "strlen"
# define BASIC "basic"
# define NILL "NULL"
# define BIG "big"
# define STRLEN_LAUNCH 1
# define LSTSIZE_LAUNCH 2
# define ITOA_LAUNCH 3
# define ATOI_LAUNCH 4
# define IS_ALPHA_LAUNCH 5

#endif