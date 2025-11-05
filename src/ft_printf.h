#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
#include <stdarg.h>
int ft_putchar(char c);
int ft_putstr(char *s);
int ft_putnbr(int n);
int ft_printf(const char *format, ...);
int ft_putptr(void *ptr);
int ft_put_nbr_hex(unsigned long long num);
int ft_putnbr_hex(int num,int upercase);

#endif
