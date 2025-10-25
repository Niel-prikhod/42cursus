/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 06:00:34 by dprikhod          #+#    #+#             */
/*   Updated: 2025/10/25 19:34:41 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>

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
		ft_printf("%d\n", i);
		i++;
	}
}

void	ft_pipclr(t_pipex **data)
{
	ft_lstclear(&((*data)->cmd), ft_clr_split);
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

int	main(int argc, char **argv, char **env)
{
	t_pipex	*data;

	if (argc < 5)
		return (INVALID_ARGS);
	data = malloc(sizeof(t_pipex));
	data->infile = open(argv[0], O_RDONLY);
	if (data->infile < 0)
		return (perror("INFILE ERROR"), EXIT_FAILURE);
	data->outfile = open(argv[argc - 1], O_TRUNC | O_WRONLY | O_CREAT);
	if (data->outfile < 0)
		return (perror("OUTFILE ERROR"), EXIT_FAILURE);
	parse_cmd(argc, argv, data);
	ft_print_cmd(data->cmd);
	ft_pipclr(&data);
	ft_printf("env: %s\n", *env);
	return (EXIT_SUCCESS);
}
