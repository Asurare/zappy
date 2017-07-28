/*
** mct.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src/graphic
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Fri Jun 24 04:38:39 2016 Florian Videau
** Last update Sun Jun 26 02:23:51 2016 Bastien DHIVER
*/

#include "cmd_user.h"
#include "graphics.h"
#include "server.h"

int		my_mct(S_CMD_GRAPH_MST_ARGS)
{
  t_vect	pos;

  pos.y = -1;
  while (++pos.y < g_args.y)
    {
      pos.x = -1;
      while (++pos.x < g_args.x)
	my_bct(client_fd, &pos);
    }
  return (0);
}

int		mct(S_CMD_USER_ARGS)
{
  (void)cmd;
  return (my_mct(client_fd));
}
