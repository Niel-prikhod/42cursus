/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 20:28:23 by dprikhod          #+#    #+#             */
/*   Updated: 2025/08/16 16:58:32 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

void	free_str_ptr(void *str);
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
	ft_printf("pa\n");
	ft_printf("stack a:\n");
	print_list(a);
	ft_printf("stack b:\n");
	print_list(b);
	swap(&b);
	ft_printf("sb\n");
	ft_printf("stack b:\n");
	print_list(b);
	rotate(&b);
	ft_printf("rb\n");
	ft_printf("stack b:\n");
	print_list(b);
	reverse_rotate(&b);
	ft_printf("rrb\n");
	ft_printf("stack b:\n");
	print_list(b);

	ft_lstclear(&a, do_nothing);
	ft_lstclear(&b, do_nothing);
	
	return (0);
}
