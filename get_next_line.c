/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlinaq <carlinaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 20:36:20 by carlinaq          #+#    #+#             */
/*   Updated: 2026/06/05 20:36:22 by carlinaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*buffer;
	static char		*remain;
	char			*line;
	ssize_t			bytes;
	char			*new_line_pos;
	char			*tmp;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return(NULL);
	if (remain)
		line = ft_strdup(remain);
	else
		line = ft_strdup("");
	if (!line)
	{
		free(buffer);
		return(NULL);
	}
	bytes = read(fd, buffer, BUFFER_SIZE);
	buffer[bytes] = '\0';
	while (bytes > 0)
	{
		printf("1: buffer=>%s<, line = >%s<\n", buffer, line);
		tmp = line;
		line = ft_strjoin(line, buffer);
		free(tmp);
		printf("2: buffer=>%s<, line = >%s<\n", buffer, line);
		bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes] = '\0';
		new_line_pos = ft_strchr(buffer, '\n');
		if (new_line_pos)
		{
			line = ft_strjoin(line, buffer);
			remain = ft_strdup(new_line_pos + 1);
			free(buffer);
			return ft_substr(line, 0, new_line_pos - line);
		}
	}
	free(line);
	return (NULL);
}
