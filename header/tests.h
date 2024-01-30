/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguillon <dguillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:55:53 by faboussa          #+#    #+#             */
/*   Updated: 2024/01/28 18:41:18 by dguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <stddef.h>
# include "../libft/libft.h"
# include <limits.h>

/***** STRLEN *****/

int		strlen_launcher(char flags);
int		basic_test_strlen(size_t (*my_function)(const char *),
			size_t (*your_function)(const char *));
int		bigger_str_test_strlen(size_t (*my_function)(const char *),
			size_t (*your_function)(const char *));
int		null_test_strlen(size_t (*my_function)(const char *),
			size_t (*your_function)(const char *));

/***** ATOI *****/

int		atoi_launcher(char flags);
int		basic_test_atoi(int (*my_function)(const char *),
			int (*your_function)(const char *));
int		null_test_atoi(int (*my_function)(const char *),
			int (*your_function)(const char *));
int		int_min_atoi(int (*my_function)(const char *),
			int (*your_function)(const char *));

/***** ITOA *****/

int		itoa_launcher(char flags);
int		basic_test_itoa(char *(*my_function)(int), char *(*your_function)(int));
int		null_test_itoa(char *(*my_function)(int), char *(*your_function)(int));
int		int_min_itoa(char *(*my_function)(int), char *(*your_function)(int));

/***** is_alpha *****/

int		isalpha_launcher(char flags);
int		basic_test_isalpha(int (*my_function)(int), int (*your_function)(int));
int		null_test_isalpha(int (*my_function)(int), int (*your_function)(int));
int		other_test_isalpha(int (*my_function)(int), int (*your_function)(int));

/***** LSTSIZE *****/

int		lstsize_launcher(char flags);
int		basic_test_lstsize(int (*my_function)(t_list *lst),
			int (*your_function)(t_list *lst));
int		null_test_lstsize(int (*my_function)(t_list *lst),
			int (*your_function)(t_list *lst));
int		other_test_lstsize(int (*my_function)(t_list *lst),
			int (*your_function)(t_list *lst));

/***** WRONG *****/
size_t	ft_strlen_ko(const char *string);
char	*ft_itoa_ko(int i);
int		ft_lstsize_ko(t_list *lst);
int		ft_isalpha_ko(int c);

#endif
