/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 17:10:31 by dprikhod          #+#    #+#             */
/*   Updated: 2025/09/28 18:48:00 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_main(t_stack **a)
{
	int		size;
	t_stack	*b;

	b = NULL;
	size = ft_stack_size(*a);
	if (size < 2)
		return ;
	else if (size <= 5)
		ft_sort_small(a, &b, size);
	else if (size >= 6)
		ft_radix_sort(a, &b, size);
	if (b)
		ft_stack_clear(&b);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	int		size;

	if (argc < 2)
		return (ft_printf("Error\n"), 1);
	a = parser(argc, argv);
	if (!a)
		return (ft_printf("Error\n"), 1);
	size = ft_stack_size(a);
	normalize(&a, size);
	sort_main(&a);
	ft_stack_clear(&a);
	return (0);
}
