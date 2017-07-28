/*
** cmd_avance.c for zappy in /home/work/work/projects/PSU_2015_zappy_doc/PSU_2015_zappy/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Thu Jun 16 15:38:54 2016 Bastien DHIVER
** Last update Sun Jun 26 21:02:41 2016 Bastien DHIVER
*/

#include "graphics.h"
#include "cmd_user.h"
#include "send_msg.h"
#include "server.h"
#include "cmd_user_actions.h"
#include "types/orientation.h"
#include "types/user.h"
#include "msg.h"

static void move_yp(t_user *user)
{
  user->y += 1;
  if (user->y == g_args.y)
    user->y = 0;
}

static void move_xp(t_user *user)
{
  user->x += 1;
  if (user->x == g_args.x)
    user->x = 0;
}

static void move_yn(t_user *user)
{
  if (!user->y)
    user->y = g_args.y;
  user->y -= 1;
}

static void move_xn(t_user *user)
{
  if (!user->x)
    user->x = g_args.x;
  user->x -= 1;
}

int		cmd_avance_action(S_CMD_USER_ARGS)
{
  void		(*moves[MAX_ORIENTATION])(t_user *);
  t_userList	*user;

  (void)cmd;
  moves[YP] = move_yp;
  moves[XP] = move_xp;
  moves[YN] = move_yn;
  moves[XN] = move_xn;
  user = find_user(client_fd);
  g_map[user->user->y][user->user->x].users = user->take_apart(user);
  moves[user->user->orientation](user->user);
  user->put_in_map(user);
  send_msg(client_fd, OK_MSG);
  send_all_graph_p(user->user, NULL, my_ppo);
  return (0);
}
