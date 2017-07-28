/*
** client_leaving.c for zappy in /home/work/work/projects/PSU_2015_zappy_doc/PSU_2015_zappy/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Wed Jun 15 18:12:31 2016 Bastien DHIVER
** Last update Sun Jun 26 07:45:57 2016 Bastien DHIVER
*/

#include <sys/select.h>
#include <stdlib.h>
#include <unistd.h>
#include "server.h"
#include "network.h"
#include "types/box.h"
#include "zappy_time.h"
#include "send_msg.h"
#include "cmd_user.h"
#include "graphics.h"
#include "cmd_user_actions.h"

int		client_leaving(int client_fd)
{
  ssize_t	team_idx;
  t_userList	*user;

  printf("Server: socket %d hung up\n", client_fd);
  if ((user = find_user(client_fd)))
    send_all_graph_p(user->user, NULL, my_pdi);
  FD_CLR(client_fd, &g_servInfo->master);
  FD_CLR(client_fd, &g_servInfo->read_fds);
  FD_CLR(client_fd, &g_servInfo->write_fds);
  close(client_fd);
  if (is_graph_client(client_fd))
    return (remove_graph_client_from_fd(client_fd), 0);
  if ((team_idx = get_team_idx_from_fd(client_fd)) != -1)
    g_avail_team_slot[team_idx] += 1;
  kick_client_from_fd(client_fd);
  remove_time_actions_from_fd(client_fd);
  remove_msgs_to_send_from_fd(client_fd);
  return (0);
}
