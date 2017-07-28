/*
** tna.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src/graphic
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Fri Jun 24 10:12:07 2016 Florian Videau
** Last update Sun Jun 26 03:16:55 2016 Florian Videau
*/

#include "cmd_user.h"
#include "graphics.h"
#include "send_msg.h"
#include "server.h"

int		my_tna(S_CMD_GRAPH_MST_ARGS)
{
  size_t	i;

  i = -1;
  while (++i < g_args.nb_teams)
    send_msg(client_fd, "tna %s\n", g_args.team_names[i]);
  return (0);
}

int	tna(S_CMD_USER_ARGS)
{
  (void)cmd;
  return (my_tna(client_fd));
}
