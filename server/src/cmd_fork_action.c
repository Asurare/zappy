/*
** cmd_fork_action.c for zappy in /home/work/work/projects/PSU_2015_zappy_doc/PSU_2015_zappy/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Sat Jun 25 20:35:44 2016 Bastien DHIVER
** Last update Sun Jun 26 21:12:53 2016 Florian Videau
*/

#define _GNU_SOURCE
#include <stdlib.h>
#include "server.h"
#include "types/userList.h"
#include "types/user.h"
#include "cmd_user.h"
#include "cmd_user_actions.h"
#include "types/eggList.h"
#include "send_msg.h"
#include "zappy_time.h"
#include "msg.h"
#include "graphics.h"

int		hatched_an_egg(S_CMD_USER_ARGS)
{
  t_eggList	*egg;
  ssize_t	team_idx;

  (void)client_fd;
  if ((egg = find_egg_from_id(atoll(cmd[0]))))
    egg->egg->hatched = 1;
  if ((team_idx = atoi(cmd[1])) != -1)
    g_avail_team_slot[team_idx] += 1;
  free(cmd[1]);
  printf("Egg hatched!\n");
  send_all_graph_e(egg->egg, my_eht);
  return (0);
}

int		cmd_fork_action(S_CMD_USER_ARGS)
{
  t_userList	*user;
  t_eggList	*egg;
  t_user_args	*args;

  (void)cmd;
  user = find_user(client_fd);
  egg = init_eggList(init_egg(user->user->x, user->user->y,
			      user->user->team_name, user->user->id));
  egg->put_in_map(egg);
  send_msg(client_fd, OK_MSG);
  send_all_graph_e(egg->egg, my_enw);
  args = generate_t_user_args(client_fd, (char **)egg->egg);
  args->client_fd = client_fd;
  args->ft_p = hatched_an_egg;
  if ((args->cmd = malloc(sizeof(char *) * 2)) == NULL
      || asprintf(&args->cmd[0], "%ld", egg->egg->id) == -1
      || asprintf(&args->cmd[1], "%ld", get_team_idx_from_fd(client_fd)) == -1)
    {
      print_err(ERR_MALLOC);
      exit(1);
    }
  insert_in_time(600, args);
  return (0);
}
