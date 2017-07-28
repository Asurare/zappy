/*
** cmd_droite_action.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Sat Jun 18 14:44:25 2016 Florian Videau
** Last update Sun Jun 26 20:08:08 2016 Florian Videau
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cmd_user.h"
#include "send_msg.h"
#include "server.h"
#include "cmd_user_actions.h"
#include "types/user.h"
#include "msg.h"

int		cmd_inventaire_action(S_CMD_USER_ARGS)
{
  t_userList	*user;
  char		*inventaire;

  (void)cmd;
  if (!(user = find_user(client_fd)))
    return (0);
  asprintf(&inventaire,
	   "{nourriture %d, linemate %d, deraumere %d, sibur %d, \
mendiane %d, phiras %d, thystame %d}%s",
	   user->user->inventory[NOURRITURE], user->user->inventory[LINEMATE],
	   user->user->inventory[DERAUMERE], user->user->inventory[SIBUR],
	   user->user->inventory[MENDIANE], user->user->inventory[PHIRAS],
	   user->user->inventory[THYSTAME], LF);
  send_msg(client_fd, inventaire);
  free(inventaire);
  return (0);
}
