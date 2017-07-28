/*
** init_select_use.c for zappy in /home/work/work/projects/PSU_2015_zappy_doc/PSU_2015_zappy/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Sat Jun 18 09:40:52 2016 Bastien DHIVER
** Last update Thu Jun 23 21:33:43 2016 Bastien DHIVER
*/

#include "server.h"
#include "network.h"

void	init_select_use(void)
{
  FD_ZERO(&g_servInfo->master);
  FD_ZERO(&g_servInfo->read_fds);
  FD_ZERO(&g_servInfo->write_fds);
  FD_SET(g_servInfo->listener, &g_servInfo->master);
  g_servInfo->fd_max = g_servInfo->listener;
}

