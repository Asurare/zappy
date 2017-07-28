/*
** pin.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src/graphic
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Fri Jun 24 20:32:59 2016 Florian Videau
** Last update Sun Jun 26 08:15:15 2016 Bastien DHIVER
*/

#include <stdlib.h>
#include "graphics.h"
#include "types/ressources.h"
#include "send_msg.h"

int	my_pin(S_CMD_GRAPH_P_ARGS)
{
  (void)more;
  send_msg(client_fd, "pin %d %ld %ld %d %d %d %d %d %d %d\n", player->id,
	   player->x, player->y, player->inventory[NOURRITURE],
	   player->inventory[LINEMATE], player->inventory[DERAUMERE],
	   player->inventory[SIBUR], player->inventory[MENDIANE],
	   player->inventory[PHIRAS], player->inventory[THYSTAME]);
  return (0);
}

int		pin(S_CMD_USER_ARGS)
{
  t_userList	*user;

  user = find_user_from_id(atoi(cmd[1]));
  return (my_pin(client_fd, user->user, NULL));
}
