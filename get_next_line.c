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
	char		*buffer;
	static char	*line;
	ssize_t		bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	//bytes = read(fd, buffer, BUFFER_SIZE);
	//line = "";
	while (!ft_strchr(buffer, '\n') && (bytes > 0))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes] = '\0';
		ft_strjoin(line, buffer);
	}

	return (ft_substr);
}
