/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:26:04 by dprikhod          #+#    #+#             */
/*   Updated: 2025/09/29 12:41:43 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_3(t_stack **a)
{
	while (!ft_is_sorted(*a))
	{
		if ((*a)->value > (*a)->next->value)
			swap(a, 'a');
		else
			reverse_rotate(a, 'a');
	}
}

static void	find_smallest(t_stack **a, t_stack **b, int size)
{
	int		i;
	int		smallest_pos;
	int		smallest;
	t_stack	*tmp;

	tmp = *a;
	i = 0;
	smallest = (*a)->value;
	smallest_pos = 0;
	while (tmp != NULL)
	{
		if (tmp->value < smallest)
		{
			smallest = tmp->value;
			smallest_pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	i = 0;
	if (smallest_pos <= (size - smallest_pos))
	{
		while (i++ < smallest_pos)
			rotate(a, 'a');
	}
	else
	{
		while (i++ <= (size - smallest_pos))
			reverse_rotate(a, 'a');
	}
	push(a, b, 'b');
}

void	ft_sort_small(t_stack **a, t_stack **b, int size)
{
	if (size <= 1 || ft_is_sorted(*a))
		return ;
	if (size == 2)
		swap(a, 'a');
	else if (size == 3)
		ft_sort_3(a);
	else
	{
		while (size-- > 3)
			find_smallest(a, b, size);
		ft_sort_3(a);
		while (*b)
			push(b, a, 'a');
	}
}

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
