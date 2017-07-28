/*
** str_split.c for zappy in /home/work/work/projects/PSU_2015_zappy_doc/PSU_2015_zappy/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Tue Jun 14 17:04:41 2016 Bastien DHIVER
** Last update Sat Jun 25 01:31:27 2016 Bastien DHIVER
*/

#include <string.h>
#include "server.h"

char		**str_split(char *raw_str, char *delims)
{
  char		**rv;
  char		*saveptr;
  char		*tok;
  int		i;

  i = -1;
  if ((rv = xmalloc(sizeof(*rv) * (how_many_str_in(delims, raw_str) + 2)))
      == NULL)
    return (NULL);
  while ((tok = strtok_r(raw_str, delims, &saveptr)) != NULL)
    {
      rv[++i] = tok;
      raw_str = NULL;
    }
  rv[++i] = NULL;
  return (rv);
}

char		**str_split_str(char *raw_str, char *delim)
{
  char		**rv;
  char		*tok;
  int		i;

  i = -1;
  if ((rv = xmalloc(sizeof(*rv) * (how_many_str_in(delim, raw_str) + 2)))
      == NULL)
    return (NULL);
  while ((tok = strstr(raw_str, delim)) != NULL)
    {
      rv[++i] = raw_str;
      memset(tok, 0, strlen(delim));
      raw_str = tok + strlen(delim);
    }
  rv[++i] = raw_str;
  rv[++i] = NULL;
  return (rv);
}

void	str_join(char **strs, char *sep, char *buf)
{
  int	i;

  i = -1;
  while (strs[++i])
    {
      strcat(buf, strs[i]);
      if (strs[i + 1])
	strcat(buf, sep);
    }
}
