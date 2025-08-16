/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 20:28:23 by dprikhod          #+#    #+#             */
/*   Updated: 2025/08/16 15:24:24 by dprikhod         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	if (argc < 2)
		return (ft_printf("Error\n"), 1);
	a = ft_lstnew(argv[1]);
	a->next = ft_lstnew(argv[2]);

	b = ft_lstnew(argv[3]);
	b->next = ft_lstnew(argv[4]);
	ft_printf("stack a:\n");
	print_list(a);
	ft_printf("stack b:\n");
	print_list(b);
	push(&a, &b);
	ft_printf("stack a:\n");
	print_list(a);
	ft_printf("stack b:\n");
	print_list(b);
	swap(&b);
	ft_printf("stack b:\n");
	print_list(b);

	ft_lstclear(&a, do_nothing);
	ft_lstclear(&b, do_nothing);
	
	return (0);
}
