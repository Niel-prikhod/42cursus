/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_normalization.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:05:33 by dprikhod          #+#    #+#             */
/*   Updated: 2025/09/28 19:06:24 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_ints(int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

static int	partition(int *arr, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[end];
	i = start - 1;
	j = start;
	while (j < end)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap_ints(&arr[i], &arr[j]);
		}
		j++;
	}
	swap_ints(&arr[i + 1], &arr[end]);
	return (i + 1);
}

static void	quick_sort(int *arr, int start, int end)
{
	int	pivot;

	if (start < end)
	{
		pivot = partition(arr, start, end);
		quick_sort(arr, start, pivot - 1);
		quick_sort(arr, pivot + 1, end);
	}
}

static int	get_index(int *arr, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (0);
}

void	normalize(t_stack **a, int size)
{
	t_stack	*tmp;
	int		*arr;
	int		i;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return ;
	tmp = *a;
	i = 0;
	while (tmp)
	{
		arr[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	quick_sort(arr, 0, size - 1);
	tmp = *a;
	while (tmp)
	{
		tmp->value = get_index(arr, size, tmp->value);
		if (i == -1) // Should not happen with valid input
		{
			free(arr);
			return ; // Or handle error
		}
		tmp = tmp->next;
	}
	free(arr);
	arr = NULL;
}
