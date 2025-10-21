/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 06:01:59 by dprikhod          #+#    #+#             */
/*   Updated: 2025/10/21 17:39:53 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <fcntl.h>

typedef enum e_error_code
{
	INVALID_FILE = 2,
	INVALID_ARGS = 3,
}	t_error_code;

typedef struct s_pipex
{
	char	**cmd;
	int		infile;
	int		outfile;
}	t_pipex;

#endif
