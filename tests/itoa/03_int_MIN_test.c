/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_int_MIN_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguillon <dguillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:45:27 by faboussa          #+#    #+#             */
/*   Updated: 2024/01/28 20:32:35 by dguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libunit.h"
#include "../../header/tests.h"

int	int_min_itoa(char *(*my_function)(int), char *(*your_function)(int))
{
	int		i;
	char	*my_result;
	char	*your_result;

	i = INT_MIN;
	my_result = my_function(i);
	your_result = your_function(i);
	if (my_result - your_result == 0)
	{
		free(my_result);
		free(your_result);
		return (0);
	}
	else
	{
		free(my_result);
		free(your_result);
		return (-1);
	}
}
