/*
** cmd_incantation.c for zappy in /home/work/work/projects/PSU_2015_zappy_doc/PSU_2015_zappy/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Thu Jun 16 15:52:49 2016 Bastien DHIVER
** Last update Sun Jun 26 10:23:16 2016 Florian Videau
*/

#include "graphics.h"
#include "cmd_user.h"
#include "cmd_user_actions.h"
#include "zappy_time.h"
#include "send_msg.h"
#include "msg.h"

int		cmd_incantation(_S_CMD_USER_ARGS)
{
  t_userList	*user;

  if (!incantation(args->client_fd))
    {
      send_msg(args->client_fd, KO_MSG);
      free_t_user_args_struct(args);
      return (0);
    }
  send_msg(args->client_fd, ELEVATION_IN_PROGRESS);
  user = find_user(args->client_fd);
  send_all_graph_p(user->user, user, my_pic);
  args->ft_p = cmd_incantation_action;
  insert_in_time(300, args);
  return (0);
}
