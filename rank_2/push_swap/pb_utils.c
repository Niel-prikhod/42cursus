/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 22:13:53 by dprikhod          #+#    #+#             */
/*   Updated: 2025/08/15 00:44:29 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *list)
{
	if (!list)
		return ;
	while (list->next)
	{
		ft_printf("%d\n", *(int*)list->content);
		list = list->next;
	}
}

void free_str_ptr(void *str)
{
	free(*((void **)str));
}
