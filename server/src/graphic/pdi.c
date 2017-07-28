/*
** pdi.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src/graphic
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Sat Jun 25 02:59:52 2016 Florian Videau
** Last update Sun Jun 26 10:23:14 2016 Florian Videau
*/

#include "graphics.h"
#include "send_msg.h"
#include "msg.h"

int	my_pdi(S_CMD_GRAPH_P_ARGS)
{
  (void)more;
  send_msg(client_fd, "pdi %d%s", player->id, LF);
  return (0);
}
