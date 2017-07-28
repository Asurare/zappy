/*
** send_msg.h for zappy in /home/work/work/projects/PSU_2015_zappy_doc/PSU_2015_zappy/include
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Wed Jun 22 15:55:49 2016 Bastien DHIVER
** Last update Thu Jun 23 21:38:23 2016 Bastien DHIVER
*/

#ifndef SEND_MSG_H_
# define SEND_MSG_H_

# include <stddef.h>
# include <sys/types.h>
# include <sys/queue.h>
# include "network.h"

TAILQ_HEAD(msg_listq, s_send_msg);

struct				s_send_msg
{
  int				fd;
  char				*msg;
  TAILQ_ENTRY(s_send_msg)	tailq;
};

void				send_msg(int fd, const char *fmt, ...);
void				try_send_msgs_to_client(void);
void				remove_msgs_to_send_from_fd(int);
void				flush_msgs_struct_to_send(void);

#endif /* !SEND_MSG_H_ */
