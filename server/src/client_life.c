/*
** client_life.c for zappy in /home/work/work/projects/PSU_2015_zappy_doc/PSU_2015_zappy/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Fri Jun 24 00:12:35 2016 Bastien DHIVER
** Last update Sun Jun 26 20:12:57 2016 Bastien DHIVER
*/

#include <sys/queue.h>
#include <stdlib.h>
#include <string.h>
#include "server.h"
#include "zappy_time.h"
#include "cmd_user_actions.h"
#include "types/user.h"
#include "msg.h"

int		decrease_life_unit(int client_fd)
{
  t_userList	*user;

  if (!(user = find_user(client_fd)))
    return (0);
  user->user->inventory[NOURRITURE] -= 1;
  printf("%d life unit : %d\n", client_fd, user->user->inventory[NOURRITURE]);
  if (user->user->inventory[NOURRITURE] < 0)
    {
      send(client_fd, PLAYER_DEATH, strlen(PLAYER_DEATH), 0);
      client_leaving(client_fd);
      return (1);
    }
  return (0);
}

int		clients_will_eat(S_CMD_USER_ARGS)
{
  t_user_args	*args;
  struct s_time	*tmp;

  (void)cmd;
  TAILQ_FOREACH(tmp, &g_time_listq, tailq)
    if (tmp->args->client_fd == client_fd
	&& tmp->args->ft_p == clients_will_eat)
      return (0);
  if (decrease_life_unit(client_fd))
    return (0);
  if ((args = malloc(sizeof(*args))) == NULL)
    {
      print_err(ERR_MALLOC);
      exit(1);
    }
  args->client_fd = client_fd;
  args->cmd = NULL;
  args->ft_p = clients_will_eat;
  insert_in_time(FOOD_UNIT_VALUE / g_args.delay, args);
  return (0);
}
