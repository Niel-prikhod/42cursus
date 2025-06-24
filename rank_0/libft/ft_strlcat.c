/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 00:35:13 by niel              #+#    #+#             */
/*   Updated: 2025/06/23 18:17:56 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	temp;
	size_t	src_len;

	temp = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size <= temp)
		return (size + src_len);
	if (size > temp)
		ft_strlcpy(dest + temp, src, size - temp);
	return (temp + src_len);
}
