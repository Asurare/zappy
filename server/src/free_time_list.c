/*
** free_time_list.c for zappy in /home/work/work/projects/PSU_2015_zappy_doc/PSU_2015_zappy/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Sun Jun 19 17:31:48 2016 Bastien DHIVER
** Last update Fri Jun 24 23:59:42 2016 Bastien DHIVER
*/

#include <sys/queue.h>
#include <stdlib.h>
#include "server.h"
#include "zappy_time.h"

void	free_t_user_args_struct(t_user_args *args)
{
  if (args->cmd)
    {
      free(*args->cmd);
      free(args->cmd);
    }
  free(args);
}

void	free_time_capsule(struct s_time *tmp_time)
{
  free_t_user_args_struct(tmp_time->args);
  free(tmp_time);
}

void		free_time_list(void)
{
  struct s_time	*tmp_time;
  struct s_time	*tmp_time_sav;

  tmp_time = TAILQ_FIRST(&g_time_listq);
  while (tmp_time && !TAILQ_EMPTY(&g_time_listq))
    {
      tmp_time_sav = TAILQ_NEXT(tmp_time, tailq);
      TAILQ_REMOVE(&g_time_listq, tmp_time, tailq);
      free_time_capsule(tmp_time);
      tmp_time = tmp_time_sav;
    }
}
