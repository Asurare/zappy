/*
** how_many_data_in_fd.c for zappy in /home/work/work/projects/PSU_2015_zappy_doc/PSU_2015_zappy/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Wed Jun 15 18:08:33 2016 Bastien DHIVER
** Last update Wed Jun 15 18:09:02 2016 Bastien DHIVER
*/

#include <sys/ioctl.h>

int	how_many_data_in_fd(int fd)
{
  int	tmp;

  return ((ioctl(fd, FIONREAD, &tmp) == -1) ? 0 : tmp);
}
