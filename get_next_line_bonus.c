/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlinaq <carlinaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 20:36:02 by carlinaq          #+#    #+#             */
/*   Updated: 2026/06/05 20:36:04 by carlinaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_and_join(int fd, char *remain)
{
	char	*buffer;
	char	*temp;
	ssize_t	bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes = read(fd, buffer, BUFFER_SIZE);
	while (bytes > 0)
	{
		buffer[bytes] = '\0';
		temp = remain;
		remain = ft_strjoin(remain, buffer);
		free(temp);
		if (!remain)
			return (free(buffer), NULL);
		if (ft_strchr(remain, '\n'))
			break ;
		bytes = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (bytes < 0)
		return (free(remain), NULL);
	return (remain);
}

static char	*extract_line(char *remain)
{
	char	*line;
	size_t	i;

	if (!remain || remain[0] == '\0')
		return (NULL);
	i = 0;
	while (remain[i] && remain[i] != '\n')
		i++;
	if (remain[i] == '\n')
		i++;
	line = ft_substr(remain, 0, i);
	return (line);
}

static char	*update_remain(char *remain)
{
	char	*new_remain;
	size_t	i;

	i = 0;
	while (remain[i] && remain[i] != '\n')
		i++;
	if (remain[i] == '\0')
	{
		free(remain);
		return (NULL);
	}
	new_remain = ft_substr(remain, i + 1, ft_strlen(remain) - i);
	free(remain);
	return (new_remain);
}

char	*get_next_line(int fd)
{
	static char	*remain[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	if (!remain[fd])
	{
		remain[fd] = ft_strdup("");
		if (!remain[fd])
			return (NULL);
	}
	remain[fd] = read_and_join(fd, remain[fd]);
	if (!remain[fd])
		return (NULL);
	line = extract_line(remain[fd]);
	remain[fd] = update_remain(remain[fd]);
	return (line);
}
