/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:58:30 by dprikhod          #+#    #+#             */
/*   Updated: 2026/01/19 17:04:56 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_get_path(char **path, char *arg)
{
	char	*new_path;
	int		i;

	i = 0;
	while (path[i])
	{
		new_path = ft_pathjoin(path[i], arg);
		if (!access(new_path, X_OK))
			return (new_path);
		free(new_path);
		i++;
	}
	return (NULL);
}

void	ft_handle_child(int *fd, t_pipex *data, char **argv, int unused_end)
{
	char	*new_path;

	close(unused_end);
	if (dup2(fd[0], STDIN_FILENO) < 0)
		return (ft_putstr_fd("CHANGING_INTPUT_ERROR", 2), exit(EXIT_FAILURE));
	close(fd[0]);
	if (dup2(fd[1], STDOUT_FILENO) < 0)
		return (ft_putstr_fd("CHANGING_OUTPUT_ERROR", 2), exit(EXIT_FAILURE));
	close(fd[1]);
	new_path = ft_get_path(data->path, argv[0]);
	if (new_path == NULL)
		return (ft_putstr_fd("COMMAND_NOT_FOUND", 2), exit(EXIT_FAILURE));
	if (execve(new_path, argv, data->env) == -1)
		return (ft_putstr_fd("EXEC_ERROR", 2), exit(EXIT_FAILURE));
}

bool	create_pipe(t_pipex *data, int cmd_pipe[2][2])
{
	int	fd[2];

	if (pipe(fd) == -1)
		return (ft_putstr_fd("PIPE_ERROR", 2), false);
	cmd_pipe[0][0] = data->infile;
	cmd_pipe[0][1] = fd[1];
	cmd_pipe[1][1] = data->outfile;
	cmd_pipe[1][0] = fd[0];
	return (true);
}

int	good_father(int *pid)
{
	int	exit_code;
	int	i;
	int	status[2];

	exit_code = 0;
	i = 0;
	while (i < 2)
	{
		waitpid(pid[i], &status[i], 0);
		if (WIFEXITED(status[i]) && WEXITSTATUS(status[i]) != 0)
			exit_code = WEXITSTATUS(status[i]);
		i++;
	}
	return (exit_code);
}

int	ft_pipes_handler(t_pipex *data)
{
	int		pid[2];
	int		cmd_pipe[2][2];
	int		i;
	t_list	*command;

	if (!create_pipe(data, cmd_pipe))
		return (EXIT_FAILURE);
	command = data->cmd;
	i = 0;
	while (i < 2)
	{
		pid[i] = fork();
		if (pid[i] < 0)
			return (ft_putstr_fd("FORK_ERROR", 2), EXIT_FAILURE);
		if (pid[i] == 0)
			ft_handle_child(cmd_pipe[i], data, command->content, cmd_pipe[(i
					+ 1) % 2][i]);
		command = command->next;
		i++;
	}
	close(cmd_pipe[0][1]);
	close(cmd_pipe[1][0]);
	return (good_father(pid));
}
