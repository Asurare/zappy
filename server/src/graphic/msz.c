/*
** msz.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src/graphic
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Fri Jun 24 03:19:03 2016 Florian Videau
** Last update Sun Jun 26 03:37:22 2016 Florian Videau
*/

#include "cmd_user.h"
#include "graphics.h"
#include "send_msg.h"
#include "server.h"

int	my_msz(S_CMD_GRAPH_MST_ARGS)
{
  send_msg(client_fd, "msz %ld %ld\n", g_args.x, g_args.y);
  return (0);
}

int	msz(S_CMD_USER_ARGS)
{
  (void)cmd;
  return (my_msz(client_fd));
}
