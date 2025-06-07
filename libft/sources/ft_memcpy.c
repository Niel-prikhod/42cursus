/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niel <niel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 01:32:41 by niel              #+#    #+#             */
/*   Updated: 2025/06/06 01:43:52 by niel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dest, const void *src, int n)
{
	unsigned char	*ptr;
	const unsigned char	*s;
	int		i;

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
