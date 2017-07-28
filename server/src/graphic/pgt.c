/*
** pgt.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src/graphic
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Sat Jun 25 03:23:41 2016 Florian Videau
** Last update Sat Jun 25 03:34:18 2016 Florian Videau
*/

#include "graphics.h"
#include "send_msg.h"

int	my_pgt(S_CMD_GRAPH_P_ARGS)
{
  send_msg(client_fd, "pgt %d %lu\n", player->id, (unsigned long int) more);
  return (0);
}
