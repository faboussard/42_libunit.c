#include "../../header/tests.h"
#include <stdio.h>

size_t	ft_strlen(const char *tab)
{
    size_t	i;

    i = 0;
    while (tab[i])
        i++;
    return (i);
}

void strlen_launcher(int i)
{
    int j;
    j = 3;


    if (i == 0)
        j = basic_test_strlen(ft_strlen, ft_strlen_KO);
    else if (i == 1)
        j = null_test_strlen(ft_strlen_KO);
    printf("%d", j);
}
