/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 01:03:36 by marvin            #+#    #+#             */
/*   Updated: 2025/06/21 01:03:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_len(int nb)
{
	size_t	len;

	len = 1;
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*c;
	long	nb1;
	size_t	len;
	int		neg;
	int		i;

	nb1 = n;
	neg = (nb1 < 0);
	if (neg)
		nb1 = -nb1;
	len = ft_count_len(nb1);
	c = (char *)malloc(len + neg + 1);
	if (!c)
		return (NULL);
	c[len + neg] = '\0';
	i = len + neg - 1;
	while (i >= neg)
	{
		c[i] = '0' + (nb1 % 10);
		nb1 /= 10;
		i--;
	}
	if (neg)
		c[0] = '-';
	return (c);
}
