/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa  <faboussa@student.42lyon.f>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:34:45 by faboussa          #+#    #+#             */
/*   Updated: 2024/01/28 17:52:26 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libunit.h"
#include "../../header/tests.h"

int	basic_test_isalpha(int (*my_function)(int), int (*your_function)(int))
{
	int	c;
	int	my_result;
	int	your_result;

	c = 'a';
	your_result = your_function(c);
	my_result = my_function(c);
	if (my_result - your_result == 0)
		return (0);
	else
		return (-1);
}
