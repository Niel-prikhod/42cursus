/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:10:21 by dprikhod          #+#    #+#             */
/*   Updated: 2025/06/19 15:22:43 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*res;

	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = malloc(i);
	if (!res)
		return (NULL);
	ft_strlcat(res, s1, ft_strlen(s1));
	ft_strlcat(res, s2, ft_strlen(s2));
	return (res);
}
