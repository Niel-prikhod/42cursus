/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:44:32 by dprikhod          #+#    #+#             */
/*   Updated: 2025/09/28 19:24:16 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdint.h>

/*
	Check if string is correctly formatted and contains only digits and max one
	sign, is within integer limits use t_parse to send status,
	change value by reference
*/
t_parse	parse_int(char *num, int *value)
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
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (PARSE_FAILED);
		result = result * 10 + (num[i] - '0');
		if (result > INT_MAX || (sign == -1 && result > (long)INT_MAX + 1))
			return (PARSE_FAILED);
		i++;
	}
	*value = sign * result;
	return (PARSE_SUCCESS);
}

// spliting the string and processing each part.
// Similar to ft_lstmap but with array from ft_split
t_stack	*parse_string(char *str, t_hash_node **table)
{
	char	**arr;
	int		i;
	t_stack	*stack;
	t_stack	*last;

	stack = NULL;
	arr = ft_split(str, ' ');
	if (!arr)
		return (free_split(arr), NULL);
	i = 0;
	while (arr[i])
	{
		last = malloc(sizeof(t_stack));
		last->next = NULL;
		if (!last || parse_int(arr[i], &last->value) == PARSE_FAILED
			|| ft_hash_insert(table, last->value) == 1)
			return (free(last), free_split(arr), ft_stack_clear(&stack), NULL);
		ft_stack_add_back(&stack, last);
		i++;
	}
	return (free_split(arr), stack);
}

// choosing correct argv
t_stack	*parser(int argc, char **argv)
{
	t_stack		*stack;
	t_stack		*last;
	t_hash_node	**table;
	int			i;

	table = ft_hash_init();
	if (!table)
		return (ft_hash_clear(table), NULL);
	i = 0;
	stack = NULL;
	while (++i < argc)
	{
		last = parse_string(argv[i], table);
		if (!last)
			return (ft_stack_clear(&stack), ft_hash_clear(table), NULL);
		ft_stack_add_back(&stack, last);
	}
	return (ft_hash_clear(table), stack);
}
