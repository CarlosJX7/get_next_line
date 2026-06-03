#ifndef GET_NEXT_LINE_H
 #define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 2
#endif

#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd);
char    *get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t  ft_strlcpy(char *dst, const char *src, size_t size);
char    *ft_strdup(const char *old);
size_t  ft_strlen(const char *s);
void	*ft_calloc(size_t nitems, size_t size);
char	*ft_strjoin( char  *s1,  char  *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcat(char *dest, const char *src, size_t dstsize);

#endif 