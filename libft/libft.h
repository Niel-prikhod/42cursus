/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:34:56 by dprikhod          #+#    #+#             */
/*   Updated: 2025/05/19 15:17:24 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

int	ft_isalpha(char *str);
int	ft_isdigit(char *str);
int	ft_isalnum(char *str);
int	ft_isascii(char *str);
int	ft_isprint(char *str);
int	ft_atoi(char *str);
int	ft_strlen(char *str);

//  isalpha
// •isdigit
// •isalnum
// •isascii
// •isprint
// •strlen
// •memset
// •bzero
// •memcpy
// •memmove
// •strlcpy
// •strlcat
// •toupper
// •tolower
// •strchr
// •strrchr
// •strncmp
// •memchr
// •memcmp
// •strnstr
// •atoi

typedef struct	s_list
{
void	*content;
struct s_list	*next;
}	t_list;

#endif


