/*
** cmd_connect_nbr.c for zappy in /home/work/work/projects/PSU_2015_zappy_doc/PSU_2015_zappy/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Thu Jun 16 15:54:36 2016 Bastien DHIVER
** Last update Sun Jun 26 18:46:24 2016 Bastien DHIVER
*/

#include "server.h"
#include "cmd_user.h"
#include "send_msg.h"
#include "msg.h"

int	cmd_connect_nbr(_S_CMD_USER_ARGS)
{
  send_msg(args->client_fd, "%ld%s", g_args.allowed_users
	   - g_avail_team_slot[get_team_idx_from_fd(args->client_fd)], LF);
  free_t_user_args_struct(args);
  return (0);
}
