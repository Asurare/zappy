/*
** remove_msgs_to_send_from_fd.c for zappy in /home/work/work/projects/PSU_2015_zappy_doc/PSU_2015_zappy/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Wed Jun 22 23:04:39 2016 Bastien DHIVER
** Last update Thu Jun 23 15:22:56 2016 Bastien DHIVER
*/

#include <stdlib.h>
#include "server.h"
#include "send_msg.h"

void			remove_msgs_to_send_from_fd(int fd)
{
  struct s_send_msg	*tmp_msg;
  struct s_send_msg	*tmp_msg_sav;

  tmp_msg = TAILQ_FIRST(&g_msg_listq);
  while (tmp_msg && !TAILQ_EMPTY(&g_msg_listq))
    {
      tmp_msg_sav = TAILQ_NEXT(tmp_msg, tailq);
      if (tmp_msg->fd == fd)
	{
	  TAILQ_REMOVE(&g_msg_listq, tmp_msg, tailq);
	  free(tmp_msg->msg);
	  free(tmp_msg);
	}
      tmp_msg = tmp_msg_sav;
    }
}

void			flush_msgs_struct_to_send(void)
{
  struct s_send_msg	*tmp_msg;
  struct s_send_msg	*tmp_msg_sav;

  tmp_msg = TAILQ_FIRST(&g_msg_listq);
  while (tmp_msg && !TAILQ_EMPTY(&g_msg_listq))
    {
      tmp_msg_sav = TAILQ_NEXT(tmp_msg, tailq);
      TAILQ_REMOVE(&g_msg_listq, tmp_msg, tailq);
      free(tmp_msg);
      tmp_msg = tmp_msg_sav;
    }
}
