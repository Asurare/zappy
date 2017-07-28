/*
** xmalloc.c for zappy in /home/work/work/projects/PSU_2015_zappy_doc/PSU_2015_zappy/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Tue Jun 14 17:08:00 2016 Bastien DHIVER
** Last update Sun Jun 26 15:08:23 2016 Bastien DHIVER
*/

#include <stdlib.h>
#include <string.h>
#include "server.h"
#include "msg.h"

void	*xmalloc(size_t size)
{
  void	*rv;

  if ((rv = malloc(size)) == NULL)
    {
      print_err(ERR_MALLOC);
      exit(1);
    }
  bzero(rv, size);
  return (rv);
}
