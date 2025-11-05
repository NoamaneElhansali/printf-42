#include "ft_printf.h"

int ft_putchar(char c)
{
    return (write(1, &c, 1));
}

int ft_putstr(char *s)
{
    if (!s)
        return write(1, "(null)", 6);
    int i = 0;
    while (s[i])
        write(1, &s[i++], 1);
    return (i);
}