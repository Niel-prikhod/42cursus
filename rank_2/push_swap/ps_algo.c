/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:26:04 by dprikhod          #+#    #+#             */
/*   Updated: 2025/10/05 19:41:38 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isbit_one(t_stack *a, int bit)
{
	int	ones;

	ones = 0;
	while (a)
	{
		if ((a->value >> bit) & 1)
			ones++;
		a = a->next;
	}
	return (ones);
}

static int	sort_bit(t_stack **a, t_stack **b, int bit, int ones)
{
	if ((((*a)->value >> bit) & 1) == 0)
		push(a, b, 'b');
	else
	{
		rotate(a, 'a');
		ones--;
	}
	return (ones);
}

void	ft_radix_sort(t_stack **a, t_stack **b, int size)
{
	int	i;
	int	j;
	int	bit_size;
	int	ones;

	if (!a || !b || !*a || size < 6)
		return ;
	bit_size = 0;
	while ((size - 1) >> bit_size)
		bit_size++;
	i = 0;
	while (i < (bit_size + 1))
	{
		j = 0;
		ones = ft_isbit_one(*a, i);
		while (j++ < (size) && ones)
			ones = sort_bit(a, b, i, ones);
		while (*b)
			push(b, a, 'a');
		i++;
	}
}
