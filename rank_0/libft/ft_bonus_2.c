/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:57:35 by dprikhod          #+#    #+#             */
/*   Updated: 2025/07/28 16:58:45 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
## Parameters
lst: The beginning of the list.
## Return value
The length of the list.
*/
int	ft_lstsize(t_list *lst)
{
	int	size;

	if (!lst)
		return (0);
	size = 1;
	while ((lst->next))
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

/*
Iterates through the list ’lst’ and applies the
function ’f’ to the content of each node.
## Parameters
lst: The address of a pointer to a node.
f: The address of the function to apply to each
node’s content.
## Return value
None
*/
void ft_lstiter(t_list *lst, void (*f)(void *))
{
}

