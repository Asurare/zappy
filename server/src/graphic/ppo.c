/*
** ppo.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src/graphic
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Fri Jun 24 18:03:24 2016 Florian Videau
** Last update Sun Jun 26 07:33:11 2016 Bastien DHIVER
*/

#include <stdlib.h>
#include "graphics.h"
#include "send_msg.h"

int	my_ppo(S_CMD_GRAPH_P_ARGS)
{
  (void) more;
  send_msg(client_fd, "ppo %d %ld %ld %d\n", player->id, player->x,
	   player->y, player->orientation + 1);
  return (0);
}

int		ppo(S_CMD_USER_ARGS)
{
  t_userList	*user;

  user = find_user_from_id(atoi(cmd[1]));
  return (my_ppo(client_fd, user->user, NULL));
}
