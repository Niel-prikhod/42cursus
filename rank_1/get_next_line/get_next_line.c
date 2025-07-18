/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:50:13 by dprikhod          #+#    #+#             */
/*   Updated: 2025/07/18 17:37:21 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*fetch_line(int fd, char *stash, char *buf)
{
	ssize_t	check;
	
	check = 1;
	while (check > 0)
	{
		check = read(fd, buf, BUFFER_SIZE);
		if (check < 0)
		{
			free(stash);
			return (NULL);
		}
		buf[check] = '\0';
		if (!stash)
			stash = "";
		stash = ft_strjoin(stash, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (stash);
}

static char	*_set_line(char *line)
{
	char	*stash;
	ssize_t	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == 0 || line[1] == 0)
		return (NULL);
	if (line_buffer[i] == 0 || line_buffer[1] == 0)
        return (NULL);
    stash = ft_substr(line, i + 1, ft_strlen(line) - i);
    if (*stash == 0)
    {
        free(stash);
        stash = NULL;
    }   
    line[i + 1] = 0;
    return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buf;
	int			i;

	buf = malloc(BUFFER_SIZE + 1);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(stash);
		free(buf);
		stash = NULL;
		buf = NULL;
		return (NULL);
	}
	if (!buf)
		return (NULL);
	line = fetch_line(fd, stash, buf);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	stash = _set_line(line);
	return (line);
}
