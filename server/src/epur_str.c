/*
** epur_str.c for zappy in /home/work/work/projects/PSU_2015_zappy_doc/PSU_2015_zappy/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Sat Jun 18 09:02:26 2016 Bastien DHIVER
** Last update Sat Jun 18 16:11:33 2016 Bastien DHIVER
*/

#include <stddef.h>

char	*epur_str(char *str)
{
  int	i;
  int	j;

  if (!str)
    return (NULL);
  if (*str == '\0')
    return (str);
  i = -1;
  j = 0;
  while (str[++i])
    if (str[i] != ' ' && str[i] != '\t')
      {
	str[j++] = str[i];
	if (str[i + 1] == ' ' || str[i + 1] == '\t')
	  str[j++] = ' ';
      }
  if (j > 0 && (str[j - 1] == ' ' || str[j - 1] == '\t'))
    str[j - 1] = '\0';
  else
    str[j] = '\0';
  return (str);
}
