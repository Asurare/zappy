/*
** enw.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src/graphic
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Sat Jun 25 23:28:44 2016 Florian Videau
** Last update Sun Jun 26 02:08:44 2016 Florian Videau
*/

#include "graphics.h"
#include "send_msg.h"

int	my_enw(S_CMD_GRAPH_E_ARGS)
{
  send_msg(client_fd, "enw %d %d %ld %ld\n", egg->id, egg->parent_id, egg->x,
	   egg->y);
  return (0);
}
