/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niel <niel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 01:03:42 by niel              #+#    #+#             */
/*   Updated: 2025/06/06 01:21:26 by niel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *s, int c, int n)
{
	unsigned char	*value;
	int				i;

	value = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		value[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
