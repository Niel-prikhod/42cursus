/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niel <niel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:50:13 by dprikhod          #+#    #+#             */
/*   Updated: 2025/07/18 01:33:13 by niel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extraction(char	**stash)
{
	char	*line;
	char	*new_stash;
	char	*newline_pos;
	size_t	len;

	if (!*stash || !**stash)
		return (NULL);
	newline_pos = ft_strchr(*stash, '\n');
	if (newline_pos)
		len = newline_pos - *stash + 1;
	else
		len = ft_strlen(*stash);
	line = ft_substr(*stash, 0, len); // allocate line to return
	new_stash = ft_strdup(*stash + len); // allocate leftover
	free(*stash); // free old stash
	*stash = (*new_stash && newline_pos) ? new_stash : NULL;
	if (!*stash)
		free(new_stash);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		buf[BUFFER_SIZE];
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!ft_strchr(stash, '\n'))
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i < 0)
			return (NULL);
		if (i == 0)
			break ;
		buf[i] = '\0';
		stash = ft_strjoin(stash, buf);
	}
	return (extraction(&stash));
}
