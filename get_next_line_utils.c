#include "get_next_line.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cinaquiz <cinaquiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:57:59 by cinaquiz          #+#    #+#             */
/*   Updated: 2023/06/26 21:14:45 by cinaquiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdint.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
char	*ft_strdup(const char *old)
{
	size_t	i;
	char	*new;

	i = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(old) + 1);
	if (new == NULL)
		return (NULL);
	while (old[i])
	{
		new[i] = old[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cadena;
	size_t	inicio;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	inicio = ft_strlen(s + start);
	if (inicio < len)
		len = inicio;
	cadena = (char *)malloc(sizeof(char) * (len + 1));
	if (!cadena)
		return (NULL);
	ft_strlcpy(cadena, s + start, len + 1);
	return (cadena);
}

char	*ft_strchr(const char *s, int c)
{
	char	find;
	int		i;

	find = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == find)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == find)
		return ((char *)s + i);
	return (0);
}

void	*ft_memset(void *s, int c, size_t l)
{
	char	*pos;

	pos = (char *)s;
	while (l > 0)
	{
		pos[l - 1] = c;
		l--;
	}
	return (pos);
}
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
void	*ft_calloc(size_t nitems, size_t size)
{
	void	*memoria;

	if ((nitems == SIZE_MAX) || (size == SIZE_MAX))
		return (NULL);
	memoria = (void *)malloc(nitems * size);
	if (!memoria)
		return (NULL);
	ft_bzero(memoria, (nitems * size));
	return ((void *)memoria);
}

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	if (dstsize == 0 && dest == NULL)
		return (ft_strlen(src));
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	if (dstsize < dest_len + 1)
		return (dstsize + src_len);
	if (dstsize > dest_len + 1)
	{
		while (src[i] != '\0' && dest_len + 1 + i < dstsize)
		{
			dest[dest_len + i] = src[i];
			i++;
		}
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
/* char	*ft_strjoin(const char *s1, const char *s2) */
char	*ft_strjoin( char *s1,  char *s2)
{
	char	*cadena;
	int		s1_len;
	int		s2_len;
	if (!(s1) && !(s2))
		return (NULL);
	else if (!(s1))
		return (ft_strdup(s2));
	else if (!(s2))
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
		cadena = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!cadena)
		return (NULL);
	ft_strlcpy(cadena, s1, s1_len + 1);
	ft_strlcat(cadena + (s1_len), s2, s2_len + 1);
	

	return (cadena);
}

static int	ft_start(const char *s1, const char *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

static int	ft_end(const char *s1, const char *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[len - i - 1]) == 0)
			break ;
		i++;
	}
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*newstr;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	newstr = (char *)malloc(sizeof(char) * (end - start + 1));
	if (newstr == NULL)
		return (NULL);
	ft_strlcpy(newstr, s1 + start, end - start + 1);
	return (newstr);
}