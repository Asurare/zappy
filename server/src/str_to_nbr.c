/*
** str_to_nbr.c for zappy in /home/work/work/projects/PSU_2015_zappy_doc/PSU_2015_zappy/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Tue Jun 14 13:53:32 2016 Bastien DHIVER
** Last update Tue Jun 14 13:59:44 2016 Bastien DHIVER
*/

#include <limits.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int	str_to_long(char *str, long int *val)
{
  char	*endptr;

  errno = 0;
  *val = strtol(str, &endptr, 10);
  if ((errno == ERANGE && (*val == LONG_MAX || *val == LONG_MIN))
      || (errno != 0 && *val == 0)
      || (endptr == str || *endptr != '\0'))
    return (1);
  return (0);
}

int		str_to_int(char *str, int *val)
{
  long int	l_val;

  if (str_to_long(str, &l_val)
      || (l_val < INT_MIN || l_val > INT_MAX))
    return (1);
  *val = (int)l_val;
  return (0);
}
