/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:58:30 by dprikhod          #+#    #+#             */
/*   Updated: 2025/11/11 11:54:02 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_get_path(char **path, char *arg)
{
	char	*new_path;
	int		i;

	i = 0;
	while (path)
	{
		new_path = ft_pathjoin(path[i], arg);
		if (!access(new_path, X_OK))
			return (free(arg), new_path);
		i++;
	}
	return (NULL);
}

bool	ft_exec_cmd(int *fd, char **path, char **argv, char **envp)
{
	char	*new_path;

	if (dup2(fd[0], STDIN_FILENO) < 0)
		return (perror("CHANGING_INTPUT_ERROR"), false);
	close(fd[0]);
	if (dup2(fd[1], STDOUT_FILENO) < 0)
		return (perror("CHANGING_OUTPUT_ERROR"), false);
	close(fd[1]);
	new_path = ft_get_path(path, argv[0]);
	if (execve(new_path, argv, envp))
		return (perror("EXEC_ERROR"), false);
	return (true);
}

bool	ft_pipes_handler(t_pipex *data, char **envp)
{
	int	pid1;
	int	pid2;
	int	fd[2];
	int	cmd1_pipe[2];
	int	cmd2_pipe[2];

	if (pipe(fd) == -1)
		return (perror("PIPE_ERROR"), false);
	pid1 = fork();
	if (pid1 < 0)
		return (perror("FORK_ERROR"), false);
	cmd1_pipe[0] = data->infile;
	cmd1_pipe[1] = fd[0];
	cmd2_pipe[1] = data->outfile;
	cmd2_pipe[0] = fd[1];
	if (pid1 == 0)
	{
		close(fd[1]);
		ft_exec_cmd(cmd1_pipe, data->path, data->cmd->content, envp);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		close(fd[0]);
		ft_exec_cmd(cmd2_pipe, data->path, data->cmd->next->content, envp);
	}
	close(fd[1]);
	close(fd[0]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (true);
}
