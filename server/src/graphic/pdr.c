/*
** pdr.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src/graphic
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Sat Jun 25 03:23:41 2016 Florian Videau
** Last update Sat Jun 25 03:31:31 2016 Florian Videau
*/

#include "graphics.h"
#include "send_msg.h"

int	my_pdr(S_CMD_GRAPH_P_ARGS)
{
  send_msg(client_fd, "pdr %d %lu\n", player->id, (unsigned long int) more);
  return (0);
}
