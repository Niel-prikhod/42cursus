/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:41:53 by dprikhod          #+#    #+#             */
/*   Updated: 2025/06/19 17:01:40 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;

	count = 1;
	while (*s)
	{
		if (*s == c)
			count++;
	}
	return (count);
}

static char	*next_word(char const **s, char c)
{
	char	*start;
	size_t	len;

	while (**s && **s == c)
		(*s)++;
	start = (char *)*s;
	len = 0;
	while (*s[len] && (*s)[len] != c)
		len++;
	*s += len;
	return (ft_substr(start, 0, len));
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		words;
	char	**res;

	i = 0;
	words = count_words(s, c);
	res = (char **)ft_calloc(words + 1, sizeof(char *));
	if (!res)
		return (NULL);
	while (i < words)
	{
		res[i] = next_word(&s, c);
		if (!res[i])
		{
			while (i)
			{
				free(res[i]);
				i--;
			}
			free(res);
			return (NULL);
		}
		i++;
	}
	return (res);
}
