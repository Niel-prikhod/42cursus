/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 13:48:18 by dprikhod          #+#    #+#             */
/*   Updated: 2025/07/02 17:06:32 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

// int	ft_var_handle(const char *format, va_list args, int i);
int	s_handle(char *s);
int	u_handle(unsigned int u);
int	i_handle(int n);
int	x_handle(unsigned long x, char *base);
int	p_handle(void *p);
int	ft_printf(const char *format, ...);

#endif
