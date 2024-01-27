#include "../../header/tests.h"
#include "../../header/libunit.h"

int null_test_itoa(char *(*my_function)(int), char *(*your_function)(int))
{
    int i;

    i = 0;
    char *my_result;
    char *your_result;

    my_result = my_function(i);
    your_result = your_function(i);

    if (my_result - your_result == 0)
        return (0);
    else
        return (-1);
}