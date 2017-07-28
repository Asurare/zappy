/*
** sgt.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src/graphic
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Sat Jun 25 02:59:52 2016 Florian Videau
** Last update Sat Jun 25 10:19:12 2016 Florian Videau
*/

#include "graphics.h"
#include "send_msg.h"
#include "server.h"

int	my_sgt(S_CMD_GRAPH_MST_ARGS)
{
  send_msg(client_fd, "sgt %ld\n", g_args.delay);
  return (0);
}
