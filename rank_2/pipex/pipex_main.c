/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 06:00:34 by dprikhod          #+#    #+#             */
/*   Updated: 2025/10/28 13:48:32 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parse_cmd(int argc, char **argv, t_pipex *data)
{
	int		i;
	t_list	*fts;

	data->cmd = NULL;
	i = 2;
	while (i < argc - 1)
	{
		fts = malloc(sizeof(t_list));
		fts->content = ft_split(argv[i], ' ');
		fts->next = NULL;
		ft_lstadd_back(&(data->cmd), fts);
		i++;
	}
}

void	ft_pipex_clear(t_pipex **data)
{
	ft_lstclear(&((*data)->cmd), ft_clr_split);
	ft_clr_split((*data)->path);
	close((*data)->infile);
	close((*data)->outfile);
	free(*data);
}

void	ft_print_cmd(t_list *cmd)
{
	t_list	*node;

	node = cmd;
	while (node)
	{
		ft_print_split(node->content);
		node = node->next;
	}
}

bool	parse_path(char **env, t_pipex *data)
{
	char	*str;

	str = NULL;
	while (env)
	{
		if (ft_strnstr(*env, "PATH", 4) == *env)
		{
			str = *env + 5;
			break ;
		}
		env++;
	}
	if (!str)
		return (false);
	data->path = ft_split(str, ':');
	// ft_print_split(data->path);
	return (true);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	*data;

	if (argc < 5)
		return (perror("INVALID ARGUMENT"), EXIT_FAILURE);
	data = malloc(sizeof(t_pipex));
	data->infile = open(argv[1], O_RDONLY);
	if (data->infile < 0)
		return (perror("INFILE ERROR"), EXIT_FAILURE);
	data->outfile = open(argv[argc - 1], O_TRUNC | O_WRONLY | O_CREAT, 0777);
	if (data->outfile < 0)
		return (perror("OUTFILE ERROR"), EXIT_FAILURE);
	parse_cmd(argc, argv, data);
	if (!parse_path(env, data))
		return (perror("ENVIRONMENT ERROR"), EXIT_FAILURE);
	if (!ft_pipes_handler(data, env))
		return (ft_pipex_clear(&data), EXIT_FAILURE);
	// ft_print_cmd(data->cmd);
	ft_pipex_clear(&data);
	return (EXIT_SUCCESS);
}
