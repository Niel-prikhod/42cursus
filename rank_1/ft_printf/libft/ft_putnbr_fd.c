/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:46:28 by dprikhod          #+#    #+#             */
/*   Updated: 2025/06/23 18:02:08 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	buf[12];
	int		i;
	long	num;

	num = n;
	i = 0;
	if (num == 0)
		buf[i++] = '0';
	if (num < 0)
	{
		write(fd, "-", 1);
		num = -num;
	}
	while (num > 0)
	{
		buf[i++] = (num % 10) + '0';
		num /= 10;
	}
	while (i > 0)
		write(fd, &buf[--i], 1);
}
