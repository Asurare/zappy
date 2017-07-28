/*
** cmd_user_hi_and_add.c for zappy in /home/work/work/projects/PSU_2015_zappy_doc/PSU_2015_zappy/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Sun Jun 26 02:10:17 2016 Bastien DHIVER
** Last update Sun Jun 26 02:12:24 2016 Bastien DHIVER
*/

#include <stdlib.h>
#include "server.h"
#include "cmd_user.h"
#include "send_msg.h"
#include "msg.h"
#include "graphics.h"

void	__say_hi_to_new_client(int fd, int team_idx)
{
  send_msg(fd, "%ld%s", g_avail_team_slot[team_idx], LF);
  send_msg(fd, "%ld %ld%s", g_args.x, g_args.y, LF);
}

void	__add_new_client(int fd, char *team_name, int team_idx)
{
  __reduce_avail_team_slot(team_idx);
  __say_hi_to_new_client(fd, team_idx);
  add_user_on_map(fd, team_name);
  clients_will_eat(fd, NULL);
}

void	__say_hi_to_new_graph_client(int fd)
{
  say_hi_to_graph_client(fd);
}

void			__add_graph_client_in_list(int fd)
{
  struct s_graph_listq	*tmp_graph;

  if ((tmp_graph = malloc(sizeof(*tmp_graph))) == NULL)
    {
      print_err(ERR_MALLOC);
      exit(1);
    }
  tmp_graph->client_fd = fd;
  TAILQ_INSERT_TAIL(&g_graph_listq, tmp_graph, tailq);
}

void	add_new_graph_client(int fd)
{
  __add_graph_client_in_list(fd);
  __say_hi_to_new_graph_client(fd);
}
