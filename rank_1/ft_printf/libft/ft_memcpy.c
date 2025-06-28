/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 01:32:41 by niel              #+#    #+#             */
/*   Updated: 2025/06/23 18:05:55 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr;
	const unsigned char	*s;
	size_t				i;

	if (!dest && !src)
		return (dest);
	i = 0;
	ptr = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (i < n)
	{
		ptr[i] = s[i];
		i++;
	}
	return (dest);
}
