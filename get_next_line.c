#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*line;
	ssize_t		bytes;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	bytes = read(fd, buf, BUFFER_SIZE);
	buf[bytes] = '\0';
	line = "";
	while (!ft_strchr(buf, '\n') && (bytes > 0))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		ft_strjoin(line, buf);
	}	
	return(ft_substr);
}
