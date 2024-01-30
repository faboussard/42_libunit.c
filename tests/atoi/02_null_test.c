/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_null_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguillon <dguillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:45:27 by faboussa          #+#    #+#             */
/*   Updated: 2024/01/28 20:02:48 by dguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libunit.h"
#include "../../header/tests.h"

int	null_test_atoi(int (*my_function)(const char *),
		int (*your_function)(const char *))
{
	char	*test;
	int		my_result;
	int		your_result;

	test = NULL;
	my_result = my_function("-2147483648");
	your_result = your_function(test);
	if (my_result <= your_result)
		return (0);
	else
		return (-1);
}
