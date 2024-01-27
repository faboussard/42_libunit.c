#include "../../header/tests.h"
#include "../../header/libunit.h"

int null_test_strlen(size_t (*your_function)(const char *))
{
    char *test = "";
    size_t my_result;
    size_t your_result;

    my_result = my_function(test);
    your_result = your_function(test);

    if (my_result - your_result == 0)
        return (0);
    else
        return (-1);
}