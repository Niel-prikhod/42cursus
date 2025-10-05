/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 19:41:00 by dprikhod          #+#    #+#             */
/*   Updated: 2025/10/05 19:41:22 by dprikhod         ###   ########.fr       */
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

static void	move_smallest(t_stack **a, int size, int pos)
{
	int	i;

	i = 0;
	if (pos <= (size - pos))
	{
		while (i++ < pos)
			rotate(a, 'a');
	}
	else
	{
		while (i++ <= (size - pos))
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
	move_smallest(a, size, smallest_pos);
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
