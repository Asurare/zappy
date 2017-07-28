/*
** loop.c for join in /home/biteau_j/rendu/tek2/PSU/PSU_2015_zappy/src
**
** Made by biteau_j
** Login   <biteau_j@epitech.net>
**
** Started on  Tue Jun  7 18:15:09 2016 biteau_j
** Last update Jan Jun 26 18:04:20 2016 Jonathan BITEAU
*/

# include "client.h"

t_client  *g_cl;

void	free_clt()
{
  t_inv *tmp;

  printf("\b\bClosing the client.\n");
  if (g_cl->ip != NULL)
    free(g_cl->ip);
  if (g_cl->seeing != NULL)
    free_tab(g_cl->seeing);
  while (g_cl->inv != NULL)
  {
    tmp = g_cl->inv;
    g_cl->inv = g_cl->inv->next;
    free(tmp);
  }
  free(g_cl->inv);
  cb_destroy(g_cl->buff);
  cb_destroy(g_cl->recv);
  free(g_cl);
  exit(0);
}

static void	select_right_fd(t_client *cl, fd_set rfd, fd_set wfd)
{
  if (FD_ISSET(cl->fd, &rfd))
    read_srv(cl);
  else if (FD_ISSET(cl->fd, &wfd))
    write_srv(cl);
}

static void init_vars(t_client *cl, struct timeval *tv)
{
  g_cl = cl;
  tv->tv_usec = 0;
  tv->tv_sec = 2;
}

int			loop(t_client *cl, int err)
{
  fd_set		rfd;
  fd_set		wfd;
  struct timeval tv;

  init_vars(cl, &tv);
  if (err < 0)
    {
      free_clt();
      return (-1);
    }
  signal(SIGINT, free_clt);
  while (cl->run == true)
    {
      set_fds(&rfd, &wfd, cl);
      if (cl->run == true)
        if (select((cl->fd + 1), &rfd, &wfd, NULL, &tv) == -1)
        {
          perror("Select function error: ");
          return (-1);
        }
      if (cl->run == true)
        select_right_fd(cl, rfd, wfd);
    }
  free_clt();
  return (-1);
}
