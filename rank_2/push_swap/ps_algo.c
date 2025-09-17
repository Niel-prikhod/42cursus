/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:26:04 by dprikhod          #+#    #+#             */
/*   Updated: 2025/09/17 22:36:20 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (!(stack->value < stack->next->value))
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	ft_sort_3(t_stack **a)
{
	while (!ft_is_sorted(*a))
	{
		if ((*a)->value > (*a)->next->value)
			sa(a);
		else
			rra(a);
	}
}

void	ft_sort_small(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_stack_size(*a);
	if (size <= 1 || ft_is_sorted(*a))
		return ;
	if (size == 2)
		sa(a);
	else if (size == 3)
		ft_sort_3(a);
	else
	{
		while (!ft_is_sorted(*a))
		{
			if ((*a)->value > (*a)->next->value)
				sa(a);
			else if (ft_stack_size(*b) < 2)
				pb(a, b);
			else
			{
				pa(a, b);
				if ((*a)->value > (*a)->next->value)
					sa(a);
			}
		}
	}
}

// static int	sort_bit(t_stack **a, t_stack **b, int size)

void	ft_radix_sort(t_stack **a, t_stack **b, int size)
{
	int	i;
	int	j;
	int	bit_size;

	if (!a || !b || !*a || !*b || size < 6)
		return ;
	bit_size = 0;
	while ((size - 1) >> bit_size)
		bit_size++;
	i = 0;
	while (i++ < (bit_size + 1))
	{
		j = 0;
		while (j++ < (size))
		{
			if ((((*a)->value >> (i - 1)) & 1) == 0)
				pb(a, b);
			else
				ra(a);
		}
		while (*b)
			pa(a, b);
	}
}
