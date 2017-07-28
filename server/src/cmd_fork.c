/*
** cmd_fork.c for zappy in /home/work/work/projects/PSU_2015_zappy_doc/PSU_2015_zappy/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Thu Jun 16 15:53:49 2016 Bastien DHIVER
** Last update Sun Jun 26 10:52:49 2016 Florian Videau
*/

#include "graphics.h"
#include "cmd_user.h"
#include "cmd_user_actions.h"
#include "zappy_time.h"

int		cmd_fork(_S_CMD_USER_ARGS)
{
  t_userList	*user;

  user = find_user(args->client_fd);
  send_all_graph_p(user->user, NULL, my_pfk);
  args->ft_p = cmd_fork_action;
  insert_in_time(42, args);
  return (0);
}
