/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 22:13:53 by dprikhod          #+#    #+#             */
/*   Updated: 2025/10/07 17:51:06 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *list)
{
	if (!list)
		return ;
	while (list)
	{
		ft_printf("	%i\n", list->value);
		list = list->next;
	}
	ft_printf("\n");
}

void	print_err(void)
{
	ft_putstr_fd("Error\n", 2);
}
