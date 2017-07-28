/*
** pie.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src/graphic
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Sat Jun 25 02:18:57 2016 Florian Videau
** Last update Sat Jun 25 02:23:36 2016 Florian Videau
*/

#include "graphics.h"
#include "send_msg.h"

int	my_pie(S_CMD_GRAPH_P_ARGS)
{
  send_msg(client_fd, "pie %ld %ld %d\n", player->x, player->y,
	   more ? 1 : 0);
  return (0);
}
