/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:19:40 by niel              #+#    #+#             */
/*   Updated: 2025/05/19 14:46:00 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	res;

	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
	{
		res = 1;
		while (power-- != 0)
		{
			res *= nb;
		}
		return (res);
	}
}

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while ((*str >= '0' && *str <= '9'))
	{
		n++;
		str++;
	}
	return (n);
}

int	ft_isspace(char *str)
{
	char	c;

	c = *str;
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int		neg;
	int		res;
	int		i;
	int		size;

	neg = 1;
	i = 0;
	while (ft_isspace(str) == 1)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	size = ft_strlen(str);
	res = 0;
	while (i < size)
	{
		res = res + (str[i] - '0') * ft_iterative_power(10, size - i - 1);
		i++;
	}
	res *= neg;
	return (res);
}

// int	main(void)
// {
// 	char	str[] = "  \n\v\r\t\f  --2147483647";
// 	int		res;
// 	char	*ptr = str;

// 	res = ft_atoi(ptr);
// 	printf("%d\n", res);
// 	return (0);
// }
