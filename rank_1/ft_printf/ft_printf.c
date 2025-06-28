/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 12:56:25 by dprikhod          #+#    #+#             */
/*   Updated: 2025/06/28 15:25:07 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
/*cspdiuxX%*/
{
	va_list	args;
	int		i;

	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
			{
				if (format[i+1] == 'c')

				else if (format[i+1] == 's')
				else if (format[i+1] == 'p')
				else if (format[i+1] == 'd')

				else if (format[i+1] == 'i')
				else if (format[i+1] == 'u')
				else if (format[i+1] == 'x')
				else if (format[i+1] == 'X')
				else if (format[i+1] == '%')

				i = i + 1;
			}
		else
			ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
}

