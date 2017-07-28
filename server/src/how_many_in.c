/*
** how_many_in.c for zappy in /home/work/work/projects/PSU_2015_zappy_doc/PSU_2015_zappy/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Tue Jun 14 17:12:06 2016 Bastien DHIVER
** Last update Tue Jun 14 17:12:15 2016 Bastien DHIVER
*/

#include <stddef.h>
#include <string.h>

size_t		how_many_in(char c, char *str)
{
  size_t	rv;

  rv = 0;
  while (*str)
    {
      if (*str == c)
	rv++;
      str++;
    }
  return (rv);
}

size_t		how_many_str_in(char *delim, char *str)
{
  size_t	rv;
  char		*tmp;

  rv = 0;
  while ((tmp = strstr(str, delim)))
    {
      rv++;
      str = tmp + 1;
    }
  return (rv);
}
