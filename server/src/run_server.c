/*
** run_server.c for zappy in /home/work/work/projects/PSU_2015_zappy_doc/PSU_2015_zappy/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Wed Jun 15 16:39:07 2016 Bastien DHIVER
** Last update Sun Jun 26 05:41:29 2016 Bastien DHIVER
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "server.h"
#include "network.h"
#include "zappy_time.h"
#include "types/box.h"
#include "send_msg.h"
#include "graphics.h"

int			start_server_net(int port, struct addrinfo **ai)
{
  int			rv;
  struct addrinfo	hints;
  char			port_str[MAX_STR_PORT_LEN];

  bzero(port_str, MAX_STR_PORT_LEN);
  snprintf(port_str, MAX_STR_PORT_LEN, "%d", port);
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET6;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;
  if ((rv = getaddrinfo(NULL, port_str, &hints, ai)) != 0)
    return (print_err("getaddrinfo() failed: %s\n", gai_strerror(rv)), 1);
  return (0);
}

int			get_socket_and_bind(struct addrinfo *ai,
					    int *listener)
{
  struct addrinfo	*tmp;

  tmp = ai;
  while (tmp != NULL)
    {
      if ((*listener = socket(tmp->ai_family, tmp->ai_socktype,
			      tmp->ai_protocol)) < 0)
	  {
	    tmp = tmp->ai_next;
	    continue;
	  }
      setsockopt(*listener, SOL_SOCKET, SO_REUSEADDR,
		 &(int){1}, sizeof(int));
      if (bind(*listener, tmp->ai_addr, tmp->ai_addrlen) < 0)
	{
	  tmp = tmp->ai_next;
	  close(*listener);
	  continue;
	}
      break;
    }
  if (tmp == NULL)
    return (freeaddrinfo(ai), print_err("Server: failed to bind\n"), 1);
  freeaddrinfo(ai);
  return (0);
}

int	receiving_data_from_client(void)
{
  int	i;

  i = -1;
  while (++i <= g_servInfo->fd_max)
    if (FD_ISSET(i, &g_servInfo->read_fds))
      {
	if (i == g_servInfo->listener)
	  {
	    if (handle_new_connections())
	      return (1);
	  }
	else
	  if (handle_client_data(i))
	    return (1);
      }
  return (0);
}

int			loop_forever(void)
{
  struct timeval	tv;

  tv.tv_sec = 0;
  while (1)
    {
      tv.tv_usec = SELECT_WAIT_USEC;
      g_servInfo->read_fds = g_servInfo->master;
      if (select(g_servInfo->fd_max + 1, &g_servInfo->read_fds,
		 &g_servInfo->write_fds, NULL, &tv) == -1)
	return (print_err("select() failed: %s\n", strerror(errno)), 1);
      if (receiving_data_from_client())
	return (1);
      execute_if_time();
      try_send_msgs_to_client();
    }
  return (0);
}

int			run_server(void)
{
  struct addrinfo	*ai;
  t_servInfo		servInfo;
  int			rv;
  int			avail_team_slot[g_args.nb_teams];
  int			i;

  g_servInfo = &servInfo;
  g_avail_team_slot = avail_team_slot;
  if (start_server_net(g_args.port, &ai)
      || (get_socket_and_bind(ai, &g_servInfo->listener)))
    return (1);
  if (listen(g_servInfo->listener, SOMAXCONN) == -1)
    return (print_err("listen() failed: %s\n", strerror(errno)), 1);
  init_select_use();
  init_map();
  i = -1;
  while (++i < (int)g_args.nb_teams)
    g_avail_team_slot[i] = g_args.allowed_users;
  TAILQ_INIT(&g_time_listq);
  TAILQ_INIT(&g_msg_listq);
  TAILQ_INIT(&g_graph_listq);
  rv = loop_forever();
  return (rv);
}
