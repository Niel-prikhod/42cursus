/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 12:56:25 by dprikhod          #+#    #+#             */
/*   Updated: 2025/06/28 17:20:38 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	c_handle(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_printf(const char *format, ...)
/*cspdiuxX%*/
{
	va_list	args;
	int		i;
	int		temp;

	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			{
				if (format[i+1] == 'c')
					temp = c_handle(va_arg(args, int));
				// else if (format[i+1] == 's')
				// 	ft
				// else if (format[i+1] == 'p')
				// else if (format[i+1] == 'd')
				// else if (format[i+1] == 'i')
				// else if (format[i+1] == 'u')
				// else if (format[i+1] == 'x')
				// else if (format[i+1] == 'X')
				else if (format[i+1] == '%')
					ft_putchar_fd( '%', 1);
				i = i + temp;
			}
		else
			ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
	return 1;
}

