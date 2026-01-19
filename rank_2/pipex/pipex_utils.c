/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:39:20 by dprikhod          #+#    #+#             */
/*   Updated: 2026/01/19 13:50:00 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_pathjoin(char *path, char *cmd)
{
	char	*new_path;
	int		path_size;
	int		cmd_size;

	path_size = ft_strlen(path);
	cmd_size = ft_strlen(cmd);
	new_path = malloc((path_size + cmd_size + 2) * sizeof(char *));
	if (!new_path)
		return (NULL);
	ft_strlcpy(new_path, path, path_size + 1);
	new_path[path_size] = '/';
	ft_strlcpy(&new_path[path_size + 1], cmd, cmd_size + 1);
	free(path);
	return (new_path);
}

void	ft_pipex_clear(t_pipex **data)
{
	if ((*data)->cmd != NULL)
		ft_lstclear(&((*data)->cmd), ft_clr_split);
	if ((*data)->path)
		ft_clr_split((*data)->path);
	close((*data)->infile);
	close((*data)->outfile);
	free(*data);
}

int	failure_close(char *msg, t_pipex **data, int exit_code)
{
	if (msg)
		ft_putstr_fd(msg, 2);
	ft_pipex_clear(data);
	return (exit_code);
}
