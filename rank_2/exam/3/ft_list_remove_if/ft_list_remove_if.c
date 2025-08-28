/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:05:45 by dprikhod          #+#    #+#             */
/*   Updated: 2025/08/28 18:20:22 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	tmp;

	if (!begin_list || !data_ref)
		return ;
	if (!cmp((*begin_list)->data, data_ref))
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	else
	{
		ft_list_remove_if(&(*begin_list)->next, data_ref, cmp);
	}
}
