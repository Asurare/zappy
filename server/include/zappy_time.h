/*
** zappy_time.h for zappy in /home/work/work/projects/PSU_2015_zappy_doc/PSU_2015_zappy/include
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Sat Jun 18 13:03:35 2016 Bastien DHIVER
** Last update Fri Jun 24 23:59:54 2016 Bastien DHIVER
*/

#ifndef ZAPPY_TIME_H_
# define ZAPPY_TIME_H_

# include <stddef.h>
# include <sys/queue.h>
# include <sys/time.h>
# include "cmd_user.h"

TAILQ_HEAD(time_listq, s_time);

struct				s_time
{
  struct timeval		until;
  t_user_args			*args;
  TAILQ_ENTRY(s_time)		tailq;
};

void				insert_in_time(size_t, t_user_args *);
void				execute_if_time(void);

void				free_time_list(void);

void				remove_time_actions_from_fd(int);

void				free_time_capsule(struct s_time *);
void				free_t_user_args_struct(t_user_args *);

#endif /* ZAPPY_TIME_H_ */
