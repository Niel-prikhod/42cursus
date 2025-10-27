/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:58:30 by dprikhod          #+#    #+#             */
/*   Updated: 2025/10/27 11:34:01 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	ft_exec_cmd(t_pipex data)
{
	int	fd[2];
	int	pid;

	if (!pipe(fd))
		return (perror("PIPE_ERROR"), false);
	pid = fork();
	if (!pid)
	{
		dup2(data.infile, 1);
		execve(data.path[0], data.cmd->content, 0);
	}
	waitpid(pid, NULL, 0);
	return (true);
}
