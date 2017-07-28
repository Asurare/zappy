/*
** port_in_range.c for zappy in /home/work/work/projects/PSU_2015_zappy_doc/PSU_2015_zappy/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Tue Jun 14 14:06:36 2016 Bastien DHIVER
** Last update Tue Jun 14 14:06:44 2016 Bastien DHIVER
*/

#include <limits.h>

int     port_in_range(int port)
{
  return ((port >= 0 && port <= USHRT_MAX) ? 1 : 0);
}
