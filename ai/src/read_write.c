/*
** read_write.c for read in /home/biteau_j/rendu/tek2/PSU/PSU_2015_zappy/src
**
** Made by biteau_j
** Login   <biteau_j@epitech.net>
**
** Started on  Tue Jun  7 18:15:18 2016 biteau_j
** Last update Jul Jun 25 22:00:08 2016 Jonathan BITEAU
*/

# include "client.h"

static void ck_running(t_client *cl, int *sent)
{
  if (cl->run == true)
    if (do_actions(cl, cl->recv->buff) > 0
	      || (cl->map[0] != 0 && cl->map[1] != 0))
      {
	      cb_reset(cl->recv);
	      if (strlen(cl->buff->buff) > 0)
	       if (write(cl->fd, cl->buff->buff,
		        strlen(cl->buff->buff)) == -1)
	             return;
      }
  *sent = count_lines(cl->buff->buff);
  printf(GREEN BOLD"Sending:\n%s\n\n"RESET, cl->buff->buff);
}

void	read_srv(t_client *cl)
{
  char  buff[CIRC_BUFF_SIZE];
  static int sent;

  bzero(buff, CIRC_BUFF_SIZE);
  if (recv(cl->fd, buff, CIRC_BUFF_SIZE, 0) <= 0)
      cl->run = false;
  else
    cb_write(cl->recv, buff);
  printf(BLUE BOLD"Receiving:\n%s\n\n"RESET, cl->recv->buff);
  if (sent > 0 && count_lines(cl->recv->buff) - sent < 0)
    return;
  cb_reset(cl->buff);
  if (cl->connected == true)
    ck_running(cl, &sent);
}

void write_srv(t_client *cl)
{
  if (write(cl->fd, cl->buff->buff, strlen(cl->buff->buff)) == -1)
    return;
}
