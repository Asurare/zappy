/*
** pbc.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src/graphic
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Fri Jun 24 22:21:46 2016 Florian Videau
** Last update Fri Jun 24 22:37:57 2016 Florian Videau
*/

#include "graphics.h"
#include "send_msg.h"

int	my_pbc(S_CMD_GRAPH_P_ARGS)
{
  send_msg(client_fd, "pbc %d %s\n", player->id, (char *) more);
  return (0);
}
