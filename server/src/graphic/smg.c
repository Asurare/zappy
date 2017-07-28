/*
** smg.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src/graphic
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Sun Jun 26 00:19:06 2016 Florian Videau
** Last update Sun Jun 26 17:12:56 2016 Florian Videau
*/

#include "send_msg.h"
#include "server.h"
#include "graphics.h"
#include "types/vector.h"

int	my_smg(char *msg)
{
  struct s_graph_listq	*tmp_graph;

  TAILQ_FOREACH(tmp_graph, &g_graph_listq, tailq)
    send_msg(tmp_graph->client_fd, "smg %s\n", msg);
  return (1);
}
