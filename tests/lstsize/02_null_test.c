#include "../../header/tests.h"
#include "../../header/libunit.h"

int null_test_lstsize(int (*my_function)(t_list *lst), int (*your_function)(t_list *lst))
{
    t_list *mylist;
    int my_result;
    int your_result;
    int i;

    mylist = NULL;
    i = 0;
    while (i < 3)
    {
        ft_lstadd_front(&mylist, ft_lstnew(""));
        i++;
    }
    my_result = my_function(mylist);
    your_result = your_function(mylist);
    if (my_result - your_result == 0)
        return (0);
    else
        return (-1);
}