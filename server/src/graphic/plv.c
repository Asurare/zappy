/*
** plv.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src/graphic
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Fri Jun 24 18:31:38 2016 Florian Videau
** Last update Sun Jun 26 10:46:51 2016 Florian Videau
*/

#include <stdlib.h>
#include "graphics.h"
#include "send_msg.h"

int	my_plv(S_CMD_GRAPH_P_ARGS)
{
  (void) more;
  send_msg(client_fd, "plv %d %d\n", player->id, player->level);
  return (0);
}

int	plv(S_CMD_USER_ARGS)
{
  t_userList	*user;

  user = find_user_from_id(atoi(cmd[1]));
  return (my_plv(client_fd, user->user, NULL));
}
