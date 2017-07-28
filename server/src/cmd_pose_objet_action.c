/*
** cmd_pose_objet_action.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Wed Jun 22 10:14:01 2016 Florian Videau
** Last update Sun Jun 26 20:08:42 2016 Florian Videau
*/

#include <strings.h>
#include "graphics.h"
#include "types/ressources.h"
#include "send_msg.h"
#include "server.h"
#include "types/user.h"
#include "cmd_user_actions.h"
#include "msg.h"

int		cmd_pose_objet_action(S_CMD_USER_ARGS)
{
  t_userList	*user;
  char		*ressources[MAX_RESS];
  size_t	i;

  (void)cmd;
  user = find_user(client_fd);
  ressources[NOURRITURE] = "nourriture";
  ressources[LINEMATE] = "linemate";
  ressources[DERAUMERE] = "deraumere";
  ressources[SIBUR] = "sibur";
  ressources[MENDIANE] = "mendiane";
  ressources[PHIRAS] = "phiras";
  ressources[THYSTAME] = "thystame";
  i = -1;
  while (++i  < MAX_RESS && strcasecmp(cmd[1], ressources[i]));
  if (i == MAX_RESS || !(user->user->inventory[i]))
    return (send_msg(client_fd, KO_MSG), 0);
  user->user->inventory[i]--;
  g_map[user->user->y][user->user->x].ressources[i]++;
  send_msg(client_fd, OK_MSG);
  send_all_graph_p(user->user, (void *)i, my_pdr);
  send_all_graph_p(user->user, NULL, my_pin);
  send_all_graph_b(&(t_vect){.x = user->user->x, .y = user->user->y}, my_bct);
  return (0);
}
