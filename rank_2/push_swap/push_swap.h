/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 20:29:12 by dprikhod          #+#    #+#             */
/*   Updated: 2025/08/19 15:36:15 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

void	print_stack(t_stack *list);
void	push(t_stack **src, t_stack **dest);
void	swap(t_stack **list);
void	rotate(t_stack **list);
void	reverse_rotate(t_stack **list);
t_stack	*parser(int argc, char	**argv);
void	ft_stack_add_back(t_stack **lst, t_stack *new);
t_stack *ft_stack_new(int value);
void	ft_stack_clear(t_stack **stack);

#endif
