/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 12:56:25 by dprikhod          #+#    #+#             */
/*   Updated: 2025/07/01 02:00:16 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	c_handle(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

static int	s_handle(char *s)
{
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

static int	p_handle(void *p)
{
	unsigned long addr = (unsigned long)p;
	int len = 0;

	ft_putstr_fd("0x", 1);
	len += 2;

	if (addr == 0)
	{
		ft_putchar_fd('0', 1);
		len += 1;
	}
	else
	{
		char hex[17];
		int i = 0;

		while (addr)
		{
			unsigned long digit = addr % 16;
			hex[i++] = "0123456789abcdef"[digit];
			addr /= 16;
		}
		while (i--)
		{
			ft_putchar_fd(hex[i], 1);
			len++;
		}
	}
	return len;
}

static int	i_handle(int n)
{
	unsigned int	num;
	int				sign;
	int				res;

	sign = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		num = -(unsigned int)n;
		sign = 1;
	}
	res = u_handle(num);
	return (res + sign);
}

static int	u_handle(unsigned int u)
{
	char	buf[12];
	int		i;
	int		temp;

	i = 0;
	if (u == 0)
		buf[i++] = '0';
	while (u > 0)
	{
		buf[i++] = (u % 10) + '0';
		u /= 10;
	}
	temp = i;
	while (i > 0)
		write(1, &buf[--i], 1);
	return (temp);
}

static int	x_handle(unsigned int x, char *base)
{
	char	hex[9];
	int		i;
	int		temp;

	i = 0;
	if (x == 0)
		hex[i++] = '0';
	while (x > 0)
	{
		hex[i++] = base[x % 16];
		x /= 16;
	}
	temp = i;
	while (i > 0)
		write(1, &hex[--i], 1);
	return (temp);
}

int	ft_printf(const char *format, ...)
/*
c - char
s - string
p - pointer
d - decimal
i - integer in base 10
u - unsigned decimal
x - lowercase hexidecimal
X - uppercase hexidecimal
% - percentage sign
*/
{
	va_list	args;
	int		i;
	int		temp;

	va_start(args, format);
	i = 0;
	temp = 0;
	while (format[i])
	{
		if (format[i] == '%')
			{
				if (format[i+1] == 'c')
					temp += c_handle(va_arg(args, int));
				else if (format[i+1] == 's')
					temp += s_handle(va_arg(args, char *));
				else if (format[i+1] == 'p')
					temp += p_handle(va_arg(args, void *));
				else if (format[i+1] == 'd' || format[i+1] == 'i')
					temp += i_handle(va_arg(args, int));
				else if (format[i+1] == 'u')
					temp += u_handle(va_arg(args, unsigned int));
				else if (format[i+1] == 'x')
					temp += x_handle(va_arg(args, unsigned int), "0123456789abcdef");
				else if (format[i+1] == 'X')
					temp += x_handle(va_arg(args, unsigned int), "0123456789ABCDEF");
				else if (format[i+1] == '%')
					ft_putchar_fd( '%', 1);
				i = i + temp;
			}
		else
			ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
	return (i + temp - 1);
}
