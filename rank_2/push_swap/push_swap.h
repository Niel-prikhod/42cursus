/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 20:29:12 by dprikhod          #+#    #+#             */
/*   Updated: 2025/08/16 16:28:36 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

void	print_list(t_list *list);
void do_nothing(void *content);
void	push(t_list **src, t_list **dest);
void	swap(t_list **list);
void	rotate(t_list **list);
void	reverse_rotate(t_list **list);

#endif
