/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_motions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:24:55 by dprikhod          #+#    #+#             */
/*   Updated: 2025/09/29 12:30:44 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **src, t_stack **dest, char c)
{
	t_stack	*tmp;

	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
	ft_printf("p%c\n", c);
}

void	swap(t_stack **list, char c)
{
	t_stack	*tmp;

	tmp = *list;
	*list = (*list)->next;
	tmp->next = (*list)->next;
	(*list)->next = tmp;
	ft_printf("s%c\n", c);
}

void	rotate(t_stack **list, char c)
{
	t_stack	*tmp;

	tmp = (*list)->next;
	(*list)->next = NULL;
	ft_stack_add_back(&tmp, *list);
	*list = tmp;
	ft_printf("r%c\n", c);
}

/*
void	reverse_rotate(t_stack **list)
{
	t_stack	*tmp;
	t_stack	*prelast;

	prelast = ft_lstprelast(*list);
	tmp = prelast->next;
	prelast->next = NULL;
	tmp->next = *list;
	*list = tmp;
}
*/

void	reverse_rotate(t_stack **list, char c)
{
	t_stack	*last;
	t_stack	*prelast;

	if (!list || !*list || !(*list)->next)
		return ;
	prelast = *list;
	last = prelast->next;
	while (last->next)
	{
		prelast = prelast->next;
		last = last->next;
	}
	prelast->next = NULL;
	last->next = *list;
	*list = last;
	ft_printf("rr%c\n", c);
}
/*

temporary operations

void	sa(t_stack **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	rb(t_stack **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	ra(t_stack **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_printf("pb\n");
}

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_printf("pa\n");
}
*/
