/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 06:01:59 by dprikhod          #+#    #+#             */
/*   Updated: 2025/10/27 11:05:09 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <curses.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef enum e_error_code
{
	INVALID_FILE = 2,
	INVALID_ARGS = 3,
}			t_error_code;

typedef struct s_pipex
{
	t_list	*cmd;
	int		infile;
	int		outfile;
	char	**path;
}			t_pipex;

// pipex_execution.c
bool		ft_exec_cmd(t_pipex data);

#endif
