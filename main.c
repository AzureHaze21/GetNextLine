/*
** main.c for  in /home/paul/epitech/CPE_getnextline_2017
** 
** Made by paul
** Login   <paul.young@epitech.eu>
** 
** Started on  Tue Nov 14 17:42:18 2017 paul
** Last update Wed Nov 15 17:37:44 2017 paul
*/

#include <malloc.h>
#include <stdio.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
  char *line = NULL;
  while (line = get_next_line(0))
	{
	  printf("%s\n", line);
	  free(line);
	}
  return 0;
}
