/*
** sbp.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src/graphic
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Sat Jun 25 02:59:52 2016 Florian Videau
** Last update Sun Jun 26 00:06:37 2016 Florian Videau
*/

#include "graphics.h"
#include "send_msg.h"

int	my_sbp(S_CMD_GRAPH_MST_ARGS)
{
  send_msg(client_fd, "sbp\n");
  return (0);
}
