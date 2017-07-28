/*
** pfk.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src/graphic
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Sat Jun 25 02:59:52 2016 Florian Videau
** Last update Sun Jun 26 10:53:39 2016 Florian Videau
*/

#include "graphics.h"
#include "send_msg.h"

int	my_pfk(S_CMD_GRAPH_P_ARGS)
{
  (void)more;
  send_msg(client_fd, "pfk %d\n", player->id);
  return (0);
}
