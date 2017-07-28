/*
** cmd_prend_objet_action.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Wed Jun 22 10:14:01 2016 Florian Videau
** Last update Sun Jun 26 19:05:49 2016 Florian Videau
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "graphics.h"
#include "types/ressources.h"
#include "send_msg.h"
#include "server.h"
#include "types/user.h"
#include "cmd_user_actions.h"
#include "msg.h"

static void	expulse_yp(t_userList *user)
{
  t_userList	*elem;
  char		*msg;

  elem = user->next;
  while (elem != user)
    {
      g_map[elem->user->y][elem->user->x].users = elem->take_apart(elem);
      elem->user->y = get_real_y(elem->user->y + 1);
      elem->put_in_map(elem);
      asprintf(&msg, "deplacement: %d\n", (elem->user->orientation == YP ? 5 :
					   (elem->user->orientation == XP ? 3 :
					    (elem->user->orientation == YN ? 1
					     : 7))));
      send_msg(elem->user->fd, msg);
      send_all_graph_p(elem->user, NULL, my_ppo);
      free(msg);
      elem = user->next;
    }
}

static void	expulse_xp(t_userList *user)
{
  t_userList	*elem;
  char		*msg;

  elem = user->next;
  while (elem != user)
    {
      g_map[elem->user->y][elem->user->x].users = elem->take_apart(elem);
      elem->user->x = get_real_x(elem->user->x + 1);
      elem->put_in_map(elem);
      asprintf(&msg, "deplacement: %d\n", (elem->user->orientation == YP ? 3 :
					   (elem->user->orientation == XP ? 5 :
					    (elem->user->orientation == YN ? 7
					     : 1))));
      send_msg(elem->user->fd, msg);
      send_all_graph_p(elem->user, NULL, my_ppo);
      free(msg);
      elem = user->next;
    }
}

static void	expulse_yn(t_userList *user)
{
  t_userList	*elem;
  char		*msg;

  elem = user->next;
  while (elem != user)
    {
      g_map[elem->user->y][elem->user->x].users = elem->take_apart(elem);
      elem->user->y = get_real_y(elem->user->y - 1);
      elem->put_in_map(elem);
      asprintf(&msg, "deplacement: %d\n", (elem->user->orientation == YP ? 1 :
					   (elem->user->orientation == XP ? 7 :
					    (elem->user->orientation == YN ? 5
					     : 3))));
      send_msg(elem->user->fd, msg);
      send_all_graph_p(elem->user, NULL, my_ppo);
      free(msg);
      elem = user->next;
    }
}

static void	expulse_xn(t_userList *user)
{
  t_userList	*elem;
  char		*msg;

  elem = user->next;
  while (elem != user)
    {
      g_map[elem->user->y][elem->user->x].users = elem->take_apart(elem);
      elem->user->x = get_real_x(elem->user->x - 1);
      elem->put_in_map(elem);
      asprintf(&msg, "deplacement: %d\n", (elem->user->orientation == YP ? 7 :
					   (elem->user->orientation == XP ? 1 :
					    (elem->user->orientation == YN ? 3
					     : 5))));
      send_msg(elem->user->fd, msg);
      send_all_graph_p(elem->user, NULL, my_ppo);
      free(msg);
      elem = user->next;
    }
}

int		cmd_expulse_action(S_CMD_USER_ARGS)
{
  void		(*expulse[MAX_ORIENTATION])(t_userList *);
  t_userList	*user;

  (void)cmd;
  expulse[YP] = expulse_yp;
  expulse[XP] = expulse_xp;
  expulse[YN] = expulse_yn;
  expulse[XN] = expulse_xn;
  user = find_user(client_fd);
  if (user->next == user)
    return (send_msg(client_fd, KO_MSG), 0);
  send_all_graph_p(user->user, NULL, my_pex);
  expulse[user->user->orientation](user);
  send_msg(client_fd, OK_MSG);
  return (0);
}
