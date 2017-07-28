/*
** pnw.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src/graphic
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Fri Jun 24 17:21:16 2016 Florian Videau
** Last update Sun Jun 26 07:32:52 2016 Bastien DHIVER
*/

#include "graphics.h"
#include "send_msg.h"
#include "msg.h"

int	my_pnw(S_CMD_GRAPH_P_ARGS)
{
  (void)more;
  send_msg(client_fd, "pnw %d %ld %ld %d %d %s%s", player->id, player->x,
	   player->y, player->orientation + 1, player->level,
	   player->team_name, LF);
  return (0);
}
