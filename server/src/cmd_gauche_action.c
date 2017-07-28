/*
** cmd_droite_action.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Sat Jun 18 14:44:25 2016 Florian Videau
** Last update Sun Jun 26 05:53:15 2016 Florian Videau
*/

#include "graphics.h"
#include "cmd_user.h"
#include "send_msg.h"
#include "server.h"
#include "cmd_user_actions.h"
#include "types/user.h"
#include "msg.h"

int		cmd_gauche_action(S_CMD_USER_ARGS)
{
  t_userList	*user;

  (void)cmd;
  user = find_user(client_fd);
  if (!user->user->orientation)
    user->user->orientation = MAX_ORIENTATION;
  user->user->orientation -= 1;
  send_msg(client_fd, OK_MSG);
  send_all_graph_p(user->user, NULL, my_ppo);
  return (0);
}
