/*
** set_fds.c for set in /home/biteau_j/rendu/tek2/PSU/PSU_2015_zappy/src
**
** Made by biteau_j
** Login   <biteau_j@epitech.net>
**
** Started on  Tue Jun  7 18:15:26 2016 biteau_j
** Last update Feb Jun 20 14:24:07 2016 Jonathan BITEAU
*/

# include "client.h"

void	set_fds(fd_set *rfd, fd_set *wfd, t_client *cl)
{
  FD_ZERO(&(*rfd));
  FD_ZERO(&(*wfd));
  FD_SET(cl->fd, (cl->read == true ? &(*rfd) : &(*wfd)));
}
