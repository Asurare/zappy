/*
** send_msg.c for zappy in /home/work/work/projects/PSU_2015_zappy_doc/PSU_2015_zappy/src
**
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
**
** Started on  Wed Jun 22 16:32:18 2016 Bastien DHIVER
** Last update Fri Jun 24 22:27:03 2016 Bastien DHIVER
*/

#define _GNU_SOURCE
#include <sys/queue.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "server.h"
#include "send_msg.h"
#include "msg.h"
#include "network.h"

void	concat_msg(char **dst, char *src)
{
  char	*tmp;

  if (!*dst)
    {
      *dst = strdup(src);
      free(src);
      return ;
    }
  tmp = *dst;
  if (asprintf(dst, "%s%s", tmp, src) == -1)
    {
      print_err(ERR_MALLOC);
      exit(1);
    }
  free(tmp);
  free(src);
}

struct s_send_msg	*create_new_msg_entry(int fd, char *msg)
{
  struct s_send_msg	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    {
      print_err(ERR_MALLOC);
      exit(1);
    }
  memset(new, 0, sizeof(*new));
  new->fd = fd;
  new->msg = msg;
  return (new);
}

void			send_msg(int fd, const char *fmt, ...)
{
  struct s_send_msg	*tmp_send_msg;
  char			*msg;
  va_list		ap;

  assert(fmt);
  va_start(ap, fmt);
  if (vasprintf(&msg, fmt, ap) == -1)
    {
      print_err(ERR_MALLOC);
      exit(1);
    }
  TAILQ_FOREACH(tmp_send_msg, &g_msg_listq, tailq)
    if (tmp_send_msg->fd == fd)
      {
	concat_msg(&tmp_send_msg->msg, msg);
	FD_SET(fd, &g_servInfo->write_fds);
	return ;
      }
  FD_SET(fd, &g_servInfo->write_fds);
  tmp_send_msg = create_new_msg_entry(fd, msg);
  TAILQ_INSERT_TAIL(&g_msg_listq, tmp_send_msg, tailq);
  va_end(ap);
}

void			try_send_msgs_to_client(void)
{
  struct s_send_msg	*tmp_send_msg;
  ssize_t		len_to_send;
  ssize_t		bytes_sent;
  char			*tmp;

  TAILQ_FOREACH(tmp_send_msg, &g_msg_listq, tailq)
    if (FD_ISSET(tmp_send_msg->fd, &g_servInfo->write_fds))
      {
	if (!tmp_send_msg->msg)
	  continue;
	if ((len_to_send = strlen(tmp_send_msg->msg))
	    && (bytes_sent = send(tmp_send_msg->fd, tmp_send_msg->msg,
				  len_to_send, 0)) < len_to_send)
	  {
	    tmp = strdup(&tmp_send_msg->msg[bytes_sent - 1]);
	    free(tmp_send_msg->msg);
	    tmp_send_msg->msg = tmp;
	    return ;
	  }
	FD_CLR(tmp_send_msg->fd, &g_servInfo->write_fds);
	free(tmp_send_msg->msg);
	tmp_send_msg->msg = NULL;
      }
}
