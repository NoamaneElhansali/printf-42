#include "ft_printf.h"

static int format_speci(char c,va_list args)
{
    if (c == 'c')
        return (ft_putchar(va_arg(args,int)));
    else if (c == 's')
        return (ft_putstr(va_arg(args,char *)));
    else if (c == 'd' || c == 'i')
        return (ft_putnbr(va_arg(args,int)));
    else if (c == 'u')
        return (ft_putnbr(va_arg(args,unsigned int)));
    else if (c == 'p')
        return (ft_putptr(va_arg(args,void *)));
    else if (c == 'x')
        return (ft_putnbr_hex(va_arg(args,int),0));
    else if (c == 'X')
        return (ft_putnbr_hex(va_arg(args,int),1));
    else if (c == '%')
        return (ft_putchar('%'));
    return (ft_putchar('%') + ft_putchar(c));
}
int ft_printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    if (!format)
        return (-1);
    va_start(args,format);
    int i = 0;
    while (format[i])
    {
        if (format[i] == '%' && format[i + 1])
        {
            i++;
            count += format_speci(format[i],args);
        }
        else{
            count += write(1,&format[i],1);
        }
        i++;
    }
    va_end(args);
    return (count);
}