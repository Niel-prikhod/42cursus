/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:44:32 by dprikhod          #+#    #+#             */
/*   Updated: 2025/08/19 15:53:35 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// check if string is correctly formatted and contains only digits and max one 
// sign, is within integer limits
int	ft_atoi_plus(char	*num)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	i = 0;
	sign = 1;
	if (num[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (num[i] == '+')
		i++;
	while (num[i] && ft_isdigit(num[i]))
	{
		result = result * 10 + (num[i] - '0');
		if (result > INT_MAX || (sign == -1 && result > (long)INT_MAX + 1))
			return (0);
		i++;
	}
	return (sign * result);
}

void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

// spliting the string and processing each part.
// Similar to ft_lstmap but with array from ft_split
t_stack	*parse_string(char	*str)
{
	char	**arr;
	int		i;
	t_stack	*stack;
	t_stack	*last;

	arr = ft_split(str, ' ');
	stack = malloc(sizeof(t_list));
	stack->value = ft_atoi_plus(arr[0]);
	i = 1;
	last = stack;
	while (arr[i])
	{
		last->next = ft_stack_new(ft_atoi_plus(arr[i]));
		last = last->next;
		if (!last->value)
		{
			return (free_split(arr), ft_stack_clear(&stack), NULL);
		}
		i++;
	}
	free_split(arr);
	return (stack);
}

// choosing correct argv
t_stack	*parser(int argc, char	**argv)
{
	t_stack	*stack;
	//int		i;
	
	if (argc != 2)
	{
		ft_printf("WORK IN PROGRES!!!");
		exit(1);
	}
	stack = parse_string(argv[1]);
	return (stack);
}
