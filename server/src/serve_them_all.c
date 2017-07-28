/*
** serve_them_all.c for zappy in /home/work/work/projects/PSU_2015_zappy_doc/PSU_2015_zappy/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Wed Jun 15 17:53:20 2016 Bastien DHIVER
** Last update Sat Jun 25 03:20:12 2016 Bastien DHIVER
*/

#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "server.h"
#include "network.h"
#include "msg.h"
#include "send_msg.h"

int				handle_new_connections(void)
{
  struct sockaddr_storage	remoteaddr;
  socklen_t			addrlen;
  int				new_fd;
  char				remoteIP[INET6_ADDRSTRLEN];

  addrlen = sizeof(remoteaddr);
  if ((new_fd = accept(g_servInfo->listener, (struct sockaddr *)&remoteaddr,
		       &addrlen)) == -1)
    return (print_err("accept() failed: %s\n", strerror(errno)), 1);
  FD_SET(new_fd, &g_servInfo->master);
  if (new_fd > g_servInfo->fd_max)
    g_servInfo->fd_max = new_fd;
  printf("Server : new connection from %s on socket %d\n",
	 inet_ntop(remoteaddr.ss_family,
		   get_in_addr((struct sockaddr *)&remoteaddr),
		   remoteIP, INET6_ADDRSTRLEN), new_fd);
  send_msg(new_fd, WELCOME_MSG_1);
  return (0);
}

int	handle_client_data(int i)
{
  int	size_in_fd;
  char	*raw_cmd;
  int	rv;

  if ((size_in_fd = how_many_data_in_fd(i)) == 0)
    return (client_leaving(i), 0);
  if ((raw_cmd = malloc(sizeof(*raw_cmd) * (size_in_fd + 1))) == NULL)
      return (print_err(ERR_MALLOC), 1);
  bzero(raw_cmd, size_in_fd + 1);
  if (recv(i, raw_cmd, size_in_fd, 0) != size_in_fd)
    return (print_err("recv() failed: %s\n", strerror(errno)), 1);
  raw_cmd = epur_str(raw_cmd);
  rv = execute_client_cmds(i, raw_cmd);
  return (rv);
}
