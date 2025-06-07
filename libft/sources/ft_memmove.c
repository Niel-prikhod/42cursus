/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niel <niel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:08:55 by niel              #+#    #+#             */
/*   Updated: 2025/06/06 23:15:59 by niel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, int n)
{
	unsigned char	*temp;

	temp = '\0';
	ft_memcpy(temp, src, n);
	ft_memcpy(dest, temp, n);
	return (dest);
}
