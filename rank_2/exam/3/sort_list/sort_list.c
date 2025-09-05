#include "list.h"
#include <stdlib.h>

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	first;
	int		tmp;

	if (!lst)
		return (NULL);
	first = lst;
	while (lst)
	{
		if (cmp(lst->data, lst->next->data) == 0)
		{
			tmp = lst->data;
			lst->data = lst->next->data;
			lst->next->data = tmp;
			lst = tmp
		}
		else
			lst = lst->next;
	}
	return (first);
}
