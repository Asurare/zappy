/*
** zappy_time.c for zappy in /home/work/work/projects/PSU_2015_zappy_doc/PSU_2015_zappy/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Sat Jun 18 13:06:27 2016 Bastien DHIVER
** Last update Sun Jun 26 09:37:22 2016 Bastien DHIVER
*/

# define _GNU_SOURCE
#include <stddef.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/select.h>
#include "server.h"
#include "zappy_time.h"
#include "cmd_user.h"
#include "msg.h"

void			execute_if_time(void)
{
  struct s_time		*tmp_time;
  struct s_time		*tmp_time_sav;
  struct timespec	ts_now;
  struct timeval	now;
  int			alive;

  clock_gettime(CLOCK_REALTIME, &ts_now);
  TIMESPEC_TO_TIMEVAL(&now, &ts_now);
  tmp_time = TAILQ_FIRST(&g_time_listq);
  while (tmp_time)
    {
      alive = 1;
      tmp_time_sav = TAILQ_NEXT(tmp_time, tailq);
      if (timercmp(&tmp_time->until, &now, <=))
	{
	  TAILQ_REMOVE(&g_time_listq, tmp_time, tailq);
	  tmp_time->args->ft_p(tmp_time->args->client_fd, tmp_time->args->cmd);
	  if (!FD_ISSET(tmp_time->args->client_fd, &g_servInfo->read_fds)
	      && tmp_time->args->ft_p != hatched_an_egg)
	    alive = 0;
	  free_time_capsule(tmp_time);
	}
      tmp_time = alive ? tmp_time_sav : NULL;
    }
}

void			insert_in_time(size_t delay, t_user_args *args)
{
  struct s_time		*future_action;
  struct timeval	to_add;
  struct timespec	ts_now;
  struct timeval	now;
  double		integral;

  if ((future_action = malloc(sizeof(*future_action))) == NULL)
    {
      print_err(ERR_MALLOC);
      exit(1);
    }
  bzero(&to_add, sizeof(to_add));
  to_add.tv_usec = modf((double)delay / g_args.delay, &integral);
  to_add.tv_sec += integral;
  to_add.tv_usec *= 10e5;
  clock_gettime(CLOCK_REALTIME, &ts_now);
  TIMESPEC_TO_TIMEVAL(&now, &ts_now);
  timeradd(&now, &to_add, &future_action->until);
  future_action->args = args;
  TAILQ_INSERT_TAIL(&g_time_listq, future_action, tailq);
}
