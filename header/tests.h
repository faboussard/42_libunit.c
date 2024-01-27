
#ifndef LIBUNIT_FONCTIONS_FANNY_H
#define LIBUNIT_FONCTIONS_FANNY_H

#include <stddef.h>
#include "../libft/libft.h"
#include <limits.h>

/***** STRLEN *****/

void strlen_launcher(int i);
int basic_test_strlen(size_t (*my_function)(const char *), size_t (*your_function)(const char *));
int null_test_strlen(size_t (*your_function)(const char *));
int bigger_str_test_strlen(size_t (*your_function)(const char *));

/***** ATOI *****/

void atoi_launcher(int i);
int basic_test_atoi(int (*my_function)(char *), int (*your_function)(char *));
int null_test_atoi(int (*my_function)(char *), int (*your_function)(char *));
int int_MIN_atoi(int (*my_function)(char *), int (*your_function)(char *));

/***** ITOA *****/

void itoa_launcher(int i);
int basic_test_itoa(char *(*my_function)(int), char *(*your_function)(int));
int null_test_itoa(char *(*my_function)(int), char *(*your_function)(int));
int int_MIN_itoa(char *(*my_function)(int), char *(*your_function)(int));

/***** LSTSIZE *****/

void lst_size_launcher(int i);
int basic_test_lstsize(int (*my_function)(t_list *lst), int (*your_function)(t_list *lst));
int null_test_lstsize(int (*my_function)(t_list *lst), int (*your_function)(t_list *lst));
int other_test_lstsize(int (*my_function)(t_list *lst), int (*your_function)(t_list *lst))

/***** WRONG *****/
size_t	ft_strlen_KO(const char *string);
char *ft_itoa_KO(int i);

#endif //LIBUNIT_FONCTIONS_FANNY_H
