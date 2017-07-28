/*
** remove_time_actions_from_fd.c for zappy in /home/work/work/projects/PSU_2015_zappy_doc/PSU_2015_zappy/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Wed Jun 22 18:35:15 2016 Bastien DHIVER
** Last update Sun Jun 26 09:36:52 2016 Bastien DHIVER
*/

#include <stdlib.h>
#include "server.h"
#include "zappy_time.h"

void		remove_time_actions_from_fd(int fd)
{
  struct s_time	*tmp_time;
  struct s_time	*tmp_time_sav;

  tmp_time = TAILQ_FIRST(&g_time_listq);
  while (tmp_time)
    {
      tmp_time_sav = TAILQ_NEXT(tmp_time, tailq);
      if (tmp_time->args->client_fd == fd
	  && tmp_time->args->ft_p != hatched_an_egg)
	{
	  TAILQ_REMOVE(&g_time_listq, tmp_time, tailq);
	  free_time_capsule(tmp_time);
	}
      tmp_time = tmp_time_sav;
    }
}
