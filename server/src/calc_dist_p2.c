/*
** calc_dist_p2.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Thu Jun 23 21:27:18 2016 Florian Videau
** Last update Sun Jun 26 15:46:52 2016 Florian Videau
*/

#include <math.h>
#include "server.h"
#include "types/userList.h"
#include "types/user.h"
#include "types/vector.h"
#include "cmd_user_actions.h"

double		rylttyrxlttx(t_user *transmitter, t_vect *receiver)
{
  double	dist[3];
  double	shortest;

  dist[0] = sqrt(pow(transmitter->x - receiver->x, 2)
		 + pow(transmitter->y - receiver->y, 2));
  dist[1] = sqrt(pow(transmitter->x - receiver->x, 2)
		 + pow((g_args.y - transmitter->y) + receiver->y, 2));
  dist[2] = sqrt(pow((g_args.x - transmitter->x) + receiver->x, 2)
		 + pow(transmitter->y - receiver->y, 2));
  shortest = find_shortest_dist(dist);
  return (shortest == dist[0] ? 6 : (shortest == dist[1] ? 8 : 4));
}

double		tyltryrxlttx(t_user *transmitter, t_vect *receiver)
{
  double	dist[3];
  double	shortest;

  dist[0] = sqrt(pow(transmitter->x - receiver->x, 2)
		 + pow(receiver->y - transmitter->y, 2));
  dist[1] = sqrt(pow(transmitter->x - receiver->x, 2)
		 + pow((g_args.y - receiver->y) + transmitter->y, 2));
  dist[2] = sqrt(pow((g_args.x - transmitter->x) + receiver->x, 2)
		 + pow(receiver->y - transmitter->y, 2));
  shortest = find_shortest_dist(dist);
  return (shortest == dist[0] ? 8 : (shortest == dist[1] ? 6 : 2));
}

double		rylttytxltrx(t_user *transmitter, t_vect *receiver)
{
  double	dist[3];
  double	shortest;

  dist[0] = sqrt(pow(receiver->x - transmitter->x, 2)
		 + pow(transmitter->y - receiver->y, 2));
  dist[1] = sqrt(pow(receiver->x - transmitter->x, 2)
		 + pow((g_args.y - transmitter->y) + receiver->y, 2));
  dist[2] = sqrt(pow((g_args.x - receiver->x) + transmitter->x, 2)
		 + pow(transmitter->y - receiver->y, 2));
  shortest = find_shortest_dist(dist);
  return (shortest == dist[0] ? 4 : (shortest == dist[1] ? 2 : 6));
}

double		tyltrytxltrx(t_user *transmitter, t_vect *receiver)
{
  double	dist[3];
  double	shortest;

  dist[0] = sqrt(pow(receiver->x - transmitter->x, 2)
		 + pow(receiver->y - transmitter->y, 2));
  dist[1] = sqrt(pow(receiver->x - transmitter->x, 2)
		 + pow((g_args.y - receiver->y) + transmitter->y, 2));
  dist[2] = sqrt(pow((g_args.x - receiver->x) + transmitter->x, 2)
		 + pow(receiver->y - transmitter->y, 2));
  shortest = find_shortest_dist(dist);
  return (shortest == dist[0] ? 2 : (shortest == dist[1] ? 4 : 8));
}

