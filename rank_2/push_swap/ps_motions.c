/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_motions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:24:55 by dprikhod          #+#    #+#             */
/*   Updated: 2025/08/19 15:27:46 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

void	swap(t_stack **list)
{
	t_stack	*tmp;

	tmp = *list;
	*list = (*list)->next;
	tmp->next = (*list)->next;
	(*list)->next = tmp;
}

void	rotate(t_stack **list)
{
	t_stack	*tmp;
	
	tmp = (*list)->next;	//store the 2nd node
	(*list)->next = NULL;
	ft_stack_add_back(&tmp, *list);
	*list = tmp;
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

void reverse_rotate(t_stack **list)
{
    t_stack *last;
    t_stack *prelast;

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
}
