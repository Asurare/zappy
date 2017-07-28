/*
** calc_dist.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Thu Jun 23 18:08:03 2016 Florian Videau
** Last update Thu Jun 23 21:48:36 2016 Florian Videau
*/

#include <math.h>
#include "types/userList.h"
#include "types/user.h"
#include "server.h"
#include "types/vector.h"
#include "cmd_user_actions.h"

static int	broadcast_same_x(t_user *transmitter, t_vect *receiver)
{
  double	dist[2];

  if (receiver->y > transmitter->y)
    {
      dist[0] = receiver->y - transmitter->y;
      dist[1] = (g_args.y - receiver->y) + transmitter->y;
      return ((dist[0] < dist[1]) ? 1 : 5);
    }
  dist[0] = transmitter->y - receiver->y;
  dist[1] = (g_args.y - transmitter->y) + receiver->y;
  return ((dist[0] < dist[1]) ? 5 : 1);
}

static int	broadcast_same_y(t_user *transmitter, t_vect *receiver)
{
  double	dist[2];

  if (receiver->x > transmitter->x)
    {
      dist[0] = receiver->x - transmitter->x;
      dist[1] = (g_args.x - receiver->x) + transmitter->x;
      return ((dist[0] < dist[1]) ? 3 : 7);
    }
  dist[0] = transmitter->x - receiver->x;
  dist[1] = (g_args.x - transmitter->x) + receiver->x;
  return ((dist[0] < dist[1]) ? 7 : 3);
}

static int	broadcast_other_coords(t_user *transmitter, t_vect *receiver)
{
  if (receiver->x < transmitter->x)
    {
      if (receiver->y < transmitter->y)
	return (rylttyrxlttx(transmitter, receiver));
      else
	return (tyltryrxlttx(transmitter, receiver));
    }
  else
    {
      if (receiver->y < transmitter->y)
	return (rylttyrxlttx(transmitter, receiver));
      else
	return (tyltryrxlttx(transmitter, receiver));
    }
}

int	calc_absolute_income(t_user *transmitter, t_vect *receiver)
{
  if (receiver->x == transmitter->x)
    return (broadcast_same_x(transmitter, receiver));
  else if (receiver->y == transmitter->y)
    return (broadcast_same_y(transmitter, receiver));
  else
    return (broadcast_other_coords(transmitter, receiver));
}

