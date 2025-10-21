/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 06:00:34 by dprikhod          #+#    #+#             */
/*   Updated: 2025/10/21 18:27:59 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pi_parse(int argc, char **argv, t_pipex *data)
{
	int	i;

	i = 1;
	while (i < argc - 1)
	{
	}
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	*data;

	if (argc < 5)
		return (INVALID_ARGS);
	data->infile = open(argv[0], O_RDONLY);
	data->outfile = open(argv[argc - 1], O_TRUNC | O_WRONLY | O_CREAT);
	if (!data->infile || !data->outfile)
		return (INVALID_FILE);
	pi_parse(argc, argv, data);
	return (0);
}
