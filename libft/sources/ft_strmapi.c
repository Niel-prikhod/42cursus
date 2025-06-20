/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 01:46:41 by marvin            #+#    #+#             */
/*   Updated: 2025/06/21 01:46:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	res = malloc(ft_strlen(s));
	if (!res)
		return (NULL);
	i = 0;
	while (*s)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	return (res);
}
