/*
** cmd_droite_action.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Sat Jun 18 14:44:25 2016 Florian Videau
** Last update Sun Jun 26 19:50:55 2016 Florian Videau
*/

#include <stdlib.h>
#include <string.h>
#include "cmd_user.h"
#include "cmd_user_actions.h"
#include "send_msg.h"
#include "server.h"
#include "types/user.h"
#include "types/vector.h"

static char	*parkour_yp(t_user *user)
{
  t_vect	pos;
  char		*boxes_content[calc_nb_box(user->level)];
  int		line_len;
  int		i;
  int		j;
  int		k;

  k = 0;
  boxes_content[k] = g_map[user->y][user->x].get_content(g_map[user->y]
							 + user->x);
  i = -1;
  line_len = 1;
  while (++i < user->level && (line_len += 2) && ((j = -1))
	 && ((pos.x = user->x) || 1) && ((pos.y = user->y) || 1))
    {
      pos.x = get_real_x(pos.x + (line_len / 2));
      pos.y = get_real_y(pos.y + (i + 1));
      while (++j < line_len)
	{
	  boxes_content[++k] = g_map[pos.y][pos.x].get_content(g_map[pos.y]
							       + pos.x);
	  pos.x = get_real_x(pos.x - 1);
	}
    }
  return (assemble_response(boxes_content, calc_nb_box(user->level)));
}

static char	*parkour_xp(t_user *user)
{
  t_vect	pos;
  char		*boxes_content[calc_nb_box(user->level)];
  int		line_len;
  int		i;
  int		j;
  int		k;

  k = 0;
  boxes_content[k] = g_map[user->y][user->x].get_content(g_map[user->y]
							 + user->x);
  i = -1;
  line_len = 1;
  while (++i < user->level && (line_len +=2) && ((j = -1))
	 && ((pos.x = user->x) || 1) && ((pos.y = user->y) || 1))
    {
      pos.y = get_real_y(pos.y - (line_len / 2));
      pos.x = get_real_x(pos.x + (i + 1));
      while (++j < line_len)
	{
	  boxes_content[++k] = g_map[pos.y][pos.x].get_content(g_map[pos.y]
							       + pos.x);
	  pos.y = get_real_y(pos.y + 1);
	}
    }
  return (assemble_response(boxes_content, calc_nb_box(user->level)));
}

static char	*parkour_yn(t_user *user)
{
  t_vect	pos;
  char		*boxes_content[calc_nb_box(user->level)];
  int		line_len;
  int		i;
  int		j;
  int		k;

  k = 0;
  boxes_content[k] = g_map[user->y][user->x].get_content(g_map[user->y]
							 + user->x);
  i = -1;
  line_len = 1;
  while (++i < user->level && (line_len +=2) && ((j = -1))
	 && ((pos.x = user->x) || 1) && ((pos.y = user->y) ||1))
    {
      pos.x = get_real_x(pos.x - (line_len / 2));
      pos.y = get_real_y(pos.y - (i + 1));
      while (++j < line_len)
	{
	  boxes_content[++k] = g_map[pos.y][pos.x].get_content(g_map[pos.y]
							       + pos.x);
	  pos.x = get_real_x(pos.x + 1);
	}
    }
  return (assemble_response(boxes_content, calc_nb_box(user->level)));
}

static char	*parkour_xn(t_user *user)
{
  t_vect	pos;
  char		*boxes_content[calc_nb_box(user->level)];
  int		line_len;
  int		i;
  int		j;
  int		k;

  k = 0;
  boxes_content[k] = g_map[user->y][user->x].get_content(g_map[user->y]
							 + user->x);
  i = -1;
  line_len = 1;
  while (++i < user->level && (line_len +=2) && ((j = -1))
	 && ((pos.x = user->x) || 1) && ((pos.y = user->y) || 1))
    {
      pos.y = get_real_y(pos.y + (line_len / 2));
      pos.x = get_real_x(pos.x - (i + 1));
      while (++j < line_len)
	{
	  boxes_content[++k] = g_map[pos.y][pos.x].get_content(g_map[pos.y]
							       + pos.x);
	  pos.y = get_real_y(pos.y - 1);
	}
    }
  return (assemble_response(boxes_content, calc_nb_box(user->level)));
}

int		cmd_voir_action(S_CMD_USER_ARGS)
{
  char		*(*parkours[MAX_ORIENTATION])(t_user *);
  char		*to_send;
  t_userList	*user;

  (void)cmd;
  user = find_user(client_fd);
  parkours[YP] = parkour_yp;
  parkours[XP] = parkour_xp;
  parkours[YN] = parkour_yn;
  parkours[XN] = parkour_xn;
  to_send = parkours[user->user->orientation](user->user);
  send_msg(client_fd, to_send);
  free(to_send);
  return (0);
}
