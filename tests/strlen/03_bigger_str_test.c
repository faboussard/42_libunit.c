/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_bigger_str_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa  <faboussa@student.42lyon.f>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:45:27 by faboussa          #+#    #+#             */
/*   Updated: 2024/01/28 17:52:44 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libunit.h"
#include "../../header/tests.h"

int	bigger_str_test_strlen(size_t (*my_function)(const char *),
							size_t (*your_function)(const char *))
{
	char	*test;
	size_t	your_result;
	size_t	my_result;

	test = "une_ligne_longue_amettre_ici";
	your_result = your_function(test);
	my_result = my_function(test);
	if (my_result - your_result == 0)
		return (0);
	else
		return (-1);
}
