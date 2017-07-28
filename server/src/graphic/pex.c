/*
** pex.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src/graphic
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Fri Jun 24 21:41:04 2016 Florian Videau
** Last update Fri Jun 24 22:16:14 2016 Florian Videau
*/

#include "graphics.h"
#include "send_msg.h"

int	my_pex(S_CMD_GRAPH_P_ARGS)
{
  (void) more;
  send_msg(client_fd, "pex %d\n", player->id);
  return (0);
}
