#include "ft_printf.h"

#include <stdio.h>
int main()
{
    // ft_printf("%r",10);
    printf("%d",ft_printf(NULL,NULL));
    printf("%d",printf(NULL,NULL));
    // printf("%d",printf("=> p 35 => %h  ",10));
}