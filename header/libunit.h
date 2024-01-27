/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguillon <dguillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:02:20 by dguillon          #+#    #+#             */
/*   Updated: 2024/01/27 17:40:09 by dguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

#include <stddef.h>
#include "../libft/libft.h"
#include <sys/wait.h>

//#include "libft.h"
#include <sys/wait.h>

#define RESULT(res) if (res == 0)\
						 printf("\033[32m[OK]\033[0m\n");\
						 else if (res == 1)\
						 printf("\033[31m[KO]\033[0m\n");\
						 else if (res == 7)\
						 printf("\033[31m[SEGBUS]\033[0m\n");\
						 else if (res == 11)\
						 printf("[SEGV]\n");

/*typedef enum
{
	ft_strlen,
	ft_atoi,
	ft_,

}e_fonctions;*/

#endif