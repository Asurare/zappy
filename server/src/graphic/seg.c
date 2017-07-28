/*
** seg.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src/graphic
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Fri Jun 24 17:21:16 2016 Florian Videau
** Last update Sat Jun 25 23:55:09 2016 Florian Videau
*/

#include "graphics.h"
#include "send_msg.h"

int	my_seg(S_CMD_GRAPH_P_ARGS)
{
  send_msg(client_fd, "seg %s\n", player->team_name);
  return (0);
}
