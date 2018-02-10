/*
** EPITECH PROJECT, 2017
** GetNextLine
** File description:
** gnl
*/

#include <unistd.h>

#ifndef GET_NEXT_LINE_H
	#define GET_NEXT_LINE_H
	#ifndef READ_SIZE
		#define READ_SIZE 32
	#endif

char *get_next_line(int fd);
void my_memset(void *buffer, int val, size_t size);
char *xrealloc(char *p, size_t size);
int read_more(const int *fd, char *buffer);

#endif
