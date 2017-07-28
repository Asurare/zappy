/*
** cmd_droite_action.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Sat Jun 18 14:44:25 2016 Florian Videau
** Last update Sun Jun 26 15:48:08 2016 Florian Videau
*/

#define _GNU_SOURCE
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"
#include "cmd_user.h"
#include "send_msg.h"
#include "server.h"
#include "cmd_user_actions.h"
#include "types/user.h"
#include "types/vector.h"
#include "msg.h"

static void	broadcast_same_box(t_userList *actual, char *msg)
{
  t_userList	*elem;
  char		*new_msg;

  elem = actual->next;
  while (elem !=actual)
    {
      asprintf(&new_msg, "message 0,%s\n", msg);
      send_msg(elem->user->fd, new_msg);
      free(new_msg);
      elem = elem->next;
    }
}

static void	broadcast_other_box(t_userList *users, int abs_orientation,
				    char *msg)
{
  t_userList	*elem;
  int		first;

  elem = users;
  first = 1;
  while (first == 1 || elem != users)
    {
      first = 0;
      if (elem->user->orientation == YP)
	send_msg(elem->user->fd, "message %d,%s\n",
		 (abs_orientation + 4) % 8, msg);
      if (elem->user->orientation == XP)
	send_msg(elem->user->fd, "message %d,%s\n",
		 (abs_orientation + 2) % 8, msg);
      if (elem->user->orientation == YN)
	send_msg(elem->user->fd, "message %d,%s\n",
		 abs_orientation, msg);
      if (elem->user->orientation == XN)
	send_msg(elem->user->fd, "message %d,%s\n",
		 (abs_orientation + 6) % 8, msg);
      elem = elem->next;
    }
}

double	find_shortest_dist(double dists[3])
{
  double	shortest;

  shortest = dists[0];
  if (shortest > dists[1])
    shortest = dists[1];
  if (shortest > dists[2])
    shortest = dists[2];
  return (shortest);
}

int		cmd_broadcast_action(S_CMD_USER_ARGS)
{
  t_userList	*user;
  long		x;
  long		y;

  user = find_user(client_fd);
  send_all_graph_p(user->user, cmd[1], my_pbc);
  broadcast_same_box(user, cmd[1]);
  y = -1;
  while (++y < g_args.y)
    {
      x = -1;
      while (++x < g_args.x)
	if (g_map[y][x].users && (y != user->user->y || x != user->user->x))
	  broadcast_other_box(g_map[y][x].users,
			      calc_absolute_income(user->user,
						   &(t_vect){.x = x, .y = y}),
			      cmd[1]);
    }
  send_msg(client_fd, OK_MSG);
  return (0);
}
