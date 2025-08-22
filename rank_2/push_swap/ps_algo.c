/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:26:04 by dprikhod          #+#    #+#             */
/*   Updated: 2025/08/22 17:28:16 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (!(stack->value < stack->next->value))
			return (0);
		stack = stack->next;
	}
	return (1);
}
