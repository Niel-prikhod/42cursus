/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:39:20 by dprikhod          #+#    #+#             */
/*   Updated: 2025/10/27 19:41:39 by dprikhod         ###   ########.fr       */
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
	// ft_printf("%s\n", new_path);
	free(path);
	return (new_path);
}
