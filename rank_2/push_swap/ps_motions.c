/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_motions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:24:55 by dprikhod          #+#    #+#             */
/*   Updated: 2025/08/16 16:48:59 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **src, t_list **dest)
{
	t_list	*tmp;

	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

void	swap(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	*list = (*list)->next;
	tmp->next = (*list)->next;
	(*list)->next = tmp;
}

void	rotate(t_list **list)
{
	t_list	*tmp;
	
	tmp = (*list)->next;	//store the 2nd node
	(*list)->next = NULL;
	ft_lstadd_back(&tmp, *list);
	*list = tmp;
}

void	reverse_rotate(t_list **list)
{
	t_list	*tmp;
	t_list	*prelast;

	prelast = ft_lstprelast(*list);
	tmp = prelast->next;
	prelast->next = NULL;
	tmp->next = *list;
	*list = tmp;
}
