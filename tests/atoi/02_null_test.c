#include "../../header/tests.h"
#include "../../header/libunit.h"

int null_test_atoi(int (*my_function)(char *), int (*your_function)(char *))
{
    char *test;

    test = "";
    int my_result;
    int your_result;

    my_result = my_function(test);
    your_result = your_function(test);

    if (my_result - your_result == 0)
        return (0);
    else
        return (-1);
}