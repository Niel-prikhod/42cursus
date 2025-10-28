/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:58:30 by dprikhod          #+#    #+#             */
/*   Updated: 2025/10/28 13:43:48 by dprikhod         ###   ########.fr       */
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
	// char	*arr[] = {"/usr/bin/cat", NULL};
	if (dup2(fd[0], STDIN_FILENO) < 0)
		return (perror("CHANGING_INTPUT_ERROR"), false);
	close(fd[0]);
	ft_printf("%d\n", STDIN_FILENO);
	if (dup2(fd[1], STDOUT_FILENO) < 0)
		return (perror("CHANGING_OUTPUT_ERROR"), false);
	close(fd[1]);
	argv[0] = ft_get_path(path, argv[0]);
	// ft_print_split(argv);
	if (execve(argv[0], argv, envp))
		// if (execve("/usr/bin/cat", "usr/bin/cat", envp)
		return (perror("EXEC_ERROR"), false);
	return (true);
}

bool	ft_pipes_handler(t_pipex *data, char **envp)
{
	int	pid;
	int	fd[2];

	fd[0] = data->infile;
	fd[1] = data->outfile;
	// if (pipe(fd) == -1)
	//	return (perror("PIPE_ERROR"), false);
	pid = fork();
	if (pid < 0)
		return (perror("FORK_ERROR"), false);
	if (pid == 0)
		ft_exec_cmd(fd, data->path, data->cmd->content, envp);
	waitpid(pid, NULL, 0);
	return (true);
}
