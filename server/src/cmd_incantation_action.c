/*
** cmd_droite_action.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Sat Jun 18 14:44:25 2016 Florian Videau
** Last update Sun Jun 26 21:00:27 2016 Bastien DHIVER
*/

#include <strings.h>
#include "graphics.h"
#include "cmd_user.h"
#include "send_msg.h"
#include "server.h"
#include "cmd_user_actions.h"
#include "types/ressources.h"
#include "types/user.h"
#include "types/vector.h"
#include "incantation.h"
#include "msg.h"

void		clear_box(t_vect *pos)
{
  bzero(g_map[pos->y][pos->x].ressources, MAX_RESS *
	sizeof(*g_map[pos->y][pos->x].ressources));
  send_all_graph_b(pos, my_bct);
}

int		cmd_incantation_action(S_CMD_USER_ARGS)
{
  int		level;
  t_userList	*user;
  t_userList	*elem;

  (void)cmd;
  user = find_user(client_fd);
  if ((level = incantation(client_fd)))
    {
      send_all_graph_p(user->user, (void *) 1, my_pie);
      elem = user->next;
      while (elem != user)
	{
	  elem->user->level = level;
	  send_msg(elem->user->fd, "niveau actuel : %d%s", level, LF);
	  send_all_graph_p(elem->user, NULL, my_plv);
	  elem = elem->next;
	}
      elem->user->level = level;
      send_msg(elem->user->fd, "niveau actuel : %d%s", level, LF);
      send_all_graph_p(elem->user, NULL, my_plv);
      clear_box(&(t_vect){.x = user->user->x, .y = user->user->y});
      return (level != MAX_LEVEL ? 0 : my_smg(user->user->team_name));
    }
  send_all_graph_p(user->user, NULL, my_pie);
  return (send_msg(client_fd, KO_MSG), 0);
}
