/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:43:43 by dprikhod          #+#    #+#             */
/*   Updated: 2025/09/29 12:24:10 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_hash(int value)
{
	if (value < 0)
		return ((-value) % HASH_SIZE);
	else
		return (value % HASH_SIZE);
}

t_hash_node	**ft_hash_init(void)
{
	t_hash_node	**table;
	int			i;

	table = malloc(sizeof(t_hash_node) * HASH_SIZE);
	if (!table)
		return (NULL);
	i = 0;
	while (i < HASH_SIZE)
	{
		table[i] = NULL;
		i++;
	}
	return (table);
}

int	ft_hash_insert(t_hash_node **table, int to_check)
{
	int			hash;
	t_hash_node	*current;
	t_hash_node	*new;

	hash = ft_hash(to_check);
	current = table[hash];
	while (current)
	{
		if (current->value == to_check)
			return (1);
		current = current->next;
	}
	new = malloc(sizeof(t_hash_node));
	if (!new)
		return (1);
	new->value = to_check;
	new->next = table[hash];
	table[hash] = new;
	return (0);
}

void	ft_hash_clear(t_hash_node **table)
{
	t_hash_node	*current;
	t_hash_node	*next;
	int			i;

	i = 0;
	while (i < HASH_SIZE)
	{
		current = table[i];
		while (current)
		{
			next = current->next;
			free(current);
			current = next;
		}
		table[i] = NULL;
		i++;
	}
	free(table);
}
