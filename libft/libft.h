/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niel <niel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:34:56 by dprikhod          #+#    #+#             */
/*   Updated: 2025/06/07 12:48:08 by niel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <stddef.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_atoi(const char *str);
int		ft_strlen(const char *str);
void	*ft_memset(void *s, int c, int n);
void	*ft_bzero(void *s, int n);
void	*ft_memcpy(void *dest, const void *src, int n);
void	*ft_memmove(void *dest, const void *src, int n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
// int		ft_strncmp(const char *s1, const char *s2, int n);
// void	*ft_memchr(const void *s, int c, int n);
// int		ft_memcmp(const void *s1, const void *s2, int n);
// char	*ft_strnstr(const char *haystack, const char *needle, int len);
// int		ft_atoi(const char *str);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

#endif
