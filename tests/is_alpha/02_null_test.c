/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_null_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguillon <dguillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:34:45 by faboussa          #+#    #+#             */
/*   Updated: 2024/01/28 20:01:43 by dguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libunit.h"
#include "../../header/tests.h"

int	null_test_isalpha(int (*my_function)(int), int (*your_function)(int))
{
	int	*c;
	int	my_result;
	int	your_result;

	c = NULL;
	your_result = your_function(*c);
	my_result = my_function(INT_MIN);
	if (my_result <= your_result)
		return (0);
	else
		return (-1);
}
