/*
** EPITECH PROJECT, 2017
** CPE_getnextline_2017
** File description:
** gnl
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

void my_memset(void *dst,
		   int val,
		   size_t size)
{
	char *p;

	if (dst == NULL)
		return;
	p = (char *)dst;
	while (size > 0)
	{
		*p++ = (char)val;
		--size;
	}
}

char *xrealloc(char *p, size_t size)
{
	char *ret;
	size_t c;

	ret = (char*)malloc(size);
	if (ret == NULL)
		return (NULL);
	my_memset(ret, 0, size);
	if (p != NULL)
	{
		c = 0;
		while (p[c])
		{
				ret[c] = p[c];
				c++;
		}
		free(p);
	}
	return (ret);
}

inline int read_more(const int *fd,
		     char *buffer)
{
	int ret;

	my_memset(buffer, 0, READ_SIZE + 1);
	ret = read((*fd), buffer, READ_SIZE);
	return (ret);
}

char *get_next_line(int fd)
{
	static char buffer[READ_SIZE + 1];
	static int j;
	register int i = 0;
	char *line = NULL;

	while (fd >= 0)
	{
		if (!buffer[j])
			j ^= j;
		if (!j && (read_more(&fd, buffer) < 1))
			return (line);
		if ((!line || !j) &&
		    !(line =
		  	xrealloc(line, READ_SIZE + i + 1)))
				return (0);
		if ((buffer[j] == '\n') && (++j))
			return (line);
		line[i++] = buffer[j++];
	}
	return (0);
}
