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

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	return (NULL);
	//bytes = read(fd, buffer, BUFFER_SIZE);
	if (!remain)
		remain = ft_strdup("");
	else
		line = ft_strjoin(remain, line);
	bytes = read(fd, buffer, BUFFER_SIZE);
	buffer[bytes] = '\0';
	while (bytes > 0)
	{
		printf("1: buffer=>%s<, line = >%s<\n", buffer, line);
		line = ft_strjoin(line, buffer);
		printf("2: buffer=>%s<, line = >%s<\n", buffer, line);
		bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes] = '\0';
		if (ft_strchr(buffer, '\n'))
		{
			line = ft_strjoin(line, buffer);
			free(buffer);
			return ft_substr(line, 0, ft_strchr(line, '\n') - line);
		}
	}
	free(buffer);
	return (line);
}
