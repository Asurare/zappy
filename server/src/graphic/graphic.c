/*
** graphic.c for zappy in /home/work/work/projects/PSU_2015_zappy_doc/PSU_2015_zappy/src/graphic
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Sat Jun 25 21:15:01 2016 Bastien DHIVER
** Last update Sat Jun 25 21:19:13 2016 Bastien DHIVER
*/

#include <sys/queue.h>
#include "server.h"
#include "graphics.h"

int			is_graph_client(int fd)
{
  struct s_graph_listq	*tmp_graph;

  TAILQ_FOREACH(tmp_graph, &g_graph_listq, tailq)
    if (tmp_graph->client_fd == fd)
      return (1);
  return (0);
}
