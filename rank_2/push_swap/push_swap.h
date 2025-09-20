/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 20:29:12 by dprikhod          #+#    #+#             */
/*   Updated: 2025/09/20 18:38:30 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int					value;
	struct s_stack		*next;
}						t_stack;

typedef struct s_stack	t_hash_node;

# define HASH_SIZE 10

typedef enum e_parse_status
{
	PARSE_SUCCESS = 1,
	PARSE_FAILED = 2,
}						t_parse;

void					print_stack(t_stack *list);
void					push(t_stack **src, t_stack **dest);
void					swap(t_stack **list);
void					rotate(t_stack **list);
void					reverse_rotate(t_stack **list);
t_stack					*parser(int argc, char **argv);
void					ft_stack_add_back(t_stack **lst, t_stack *new);
t_stack					*ft_stack_new(int value);
void					ft_stack_clear(t_stack **stack);
int						ft_hash_insert(t_hash_node **table, int to_check);
int						ft_hash(int value);
t_hash_node				**ft_hash_init(void);
void					ft_hash_clear(t_hash_node **table);
int						ft_stack_size(t_stack *stack);
int						ft_is_sorted(t_stack *stack);
void					ft_sort_small(t_stack **a, t_stack **b, int size);
void					ft_radix_sort(t_stack **a, t_stack **b, int size);

void					sa(t_stack **a);
void					sb(t_stack **b);
void					rb(t_stack **b);
void					ra(t_stack **a);
void					rra(t_stack **a);
void					rrb(t_stack **b);
void					pb(t_stack **a, t_stack **b);
void					pa(t_stack **a, t_stack **b);

#endif
