#include "../../header/tests.h"
#include "../../header/libunit.h"

//to erase
#include <stdio.h>

int basic_test_strlen(size_t (*my_function)(const char *), size_t (*your_function)(const char *))
{
    char *test = "Hello, World!";
    size_t my_result;
    size_t your_result;

    my_result = my_function(test);
    your_result = your_function(test);

    if (my_result - your_result == 0)
        return (0);
    else
        return (-1);
}