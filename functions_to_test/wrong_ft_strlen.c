/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrong_ft_strlen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:56:44 by faboussa          #+#    #+#             */
/*   Updated: 2024/01/28 17:56:46 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libunit.h"
#include "../header/tests.h"

size_t	ft_strlen_ko(const char *string)
{
	size_t	i;

	string = NULL;
	i = 1;
	return (i);
}
