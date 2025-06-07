/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niel <niel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 00:35:13 by niel              #+#    #+#             */
/*   Updated: 2025/06/07 01:05:41 by niel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	temp;

	temp = ft_strlen(dest);
	if (size >= temp)
	{
		ft_strlcpy(dest + temp, src, size - temp);
	}
	return (temp + ft_strlen(src));
}
