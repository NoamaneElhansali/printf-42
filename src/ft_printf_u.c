/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelhansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 20:33:19 by nelhansa          #+#    #+#             */
/*   Updated: 2025/11/06 20:34:23 by nelhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(long int a, int base)
{
	int	len;

	len = (a <= 0);
	if (a < 0)
		a = -a;
	while (a > 0)
	{
		a /= base;
		len++;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	int			len;
	long int	c;
	char		num[15];

	c = n;
	len = ft_numlen(c, 10);
	num[len--] = '\0';
	if (c < 0)
	{
		num[0] = '-';
		c = -c;
	}
	if (c == 0)
		num[len--] = '0';
	while (c > 0)
	{
		num[len--] = (c % 10) + 48;
		c /= 10;
	}
	len = 0;
	while (num[len])
	{
		write(1, &num[len++], 1);
	}
	return (ft_numlen(n, 10));
}

int	ft_put_nbr_hex(unsigned long long num)
{
	char	*hex_forma;
	int		count;

	hex_forma = "0123456789abcdef";
	count = 0;
	if (num >= 16)
		count += ft_put_nbr_hex(num / 16);
	count += write(1, &hex_forma[num % 16], 1);
	return (count);
}

int	ft_putnbr_hex(int num, int upercase)
{
	char	*hex_forma;
	char	*hex_forma_u;
	int		count;
	int		posi;

	hex_forma = "0123456789abcdef";
	hex_forma_u = "0123456789ABCDEF";
	count = 0;
	posi = 1;
	if (num < 0)
	{
		posi = 0;
		num = -num;
	}
	if (num >= 16)
		count += ft_putnbr_hex(num / 16, upercase);
	if (!posi)
		count += write(1, "-", 1);
	if (upercase)
		count += write(1, &hex_forma_u[num % 16], 1);
	else
		count += write(1, &hex_forma[num % 16], 1);
	return (count);
}

int	ft_putptr(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	count += ft_put_nbr_hex((unsigned long long)ptr);
	return (count);
}
