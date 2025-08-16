/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 22:13:53 by dprikhod          #+#    #+#             */
/*   Updated: 2025/08/15 14:55:46 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *list)
{
	if (!list)
		return ;
	while (list)
	{
		ft_printf("	%c\n", *(int*)list->content);
		list = list->next;
	}
	write(1, "\n",1);
}

void free_str_ptr(void *str)
{
	free(*((void **)str));
}
