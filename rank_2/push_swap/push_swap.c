/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 17:10:31 by dprikhod          #+#    #+#             */
/*   Updated: 2025/08/22 17:10:43 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;

	//	t_stack	*b;
	if (argc < 2)
		return (ft_printf("Error\n"), 1);
	a = parser(argc, argv);
	if (!a)
		return (ft_printf("Error\n"), 1);
	ft_printf("stack a:\n");
	print_stack(a);
	/*
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
*/
	ft_printf("is_sorted: %d\n", ft_is_sorted(a));
	ft_stack_clear(&a);
	return (0);
}
