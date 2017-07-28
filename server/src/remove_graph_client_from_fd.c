/*
** remove_graph_client_from_fd.c for zappy in /home/work/work/projects/PSU_2015_zappy_doc/PSU_2015_zappy/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Sun Jun 26 05:02:08 2016 Bastien DHIVER
** Last update Sun Jun 26 05:13:28 2016 Bastien DHIVER
*/

#include <stdlib.h>
#include "server.h"
#include "graphics.h"

void			flush_graph_client_list(void)
{
  struct s_graph_listq	*tmp_graph;
  struct s_graph_listq	*tmp_graph_sav;

  tmp_graph = TAILQ_FIRST(&g_graph_listq);
  while (tmp_graph)
    {
      tmp_graph_sav = TAILQ_NEXT(tmp_graph, tailq);
      TAILQ_REMOVE(&g_graph_listq, tmp_graph, tailq);
      free(tmp_graph);
      tmp_graph = tmp_graph_sav;
    }
}

void			remove_graph_client_from_fd(int client_fd)
{
  struct s_graph_listq	*tmp_graph;
  struct s_graph_listq	*tmp_graph_sav;

  tmp_graph = TAILQ_FIRST(&g_graph_listq);
  while (tmp_graph)
    {
      tmp_graph_sav = TAILQ_NEXT(tmp_graph, tailq);
      if (tmp_graph->client_fd == client_fd)
	{
	  TAILQ_REMOVE(&g_graph_listq, tmp_graph, tailq);
	  free(tmp_graph);
	}
      tmp_graph = tmp_graph_sav;
    }
}
