/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa  <faboussa@student.42lyon.f>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:52:56 by faboussa          #+#    #+#             */
/*   Updated: 2024/01/28 17:52:20 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libunit.h"
#include "../../header/tests.h"

int	basic_test_atoi(int (*my_function)(const char *),
		int (*your_function)(const char *))
{
	char	*test;
	int		my_result;
	int		your_result;

	test = "+1234";
	my_result = my_function(test);
	your_result = your_function(test);
	if (my_result - your_result == 0)
		return (0);
	else
		return (-1);
}
