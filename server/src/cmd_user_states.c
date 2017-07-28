/*
** cmd_user_states.c for zappy in /home/work/work/projects/PSU_2015_zappy_doc/PSU_2015_zappy/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Sun Jun 26 02:12:42 2016 Bastien DHIVER
** Last update Sun Jun 26 02:15:08 2016 Bastien DHIVER
*/

#include <string.h>
#include "server.h"
#include "cmd_user.h"
#include "cmd_user_actions.h"
#include "cmd_user_init.h"
#include "msg.h"

int	is_team_name(char *team_name)
{
  int	i;

  i = -1;
  while (g_args.team_names[++i])
    if (strcmp(g_args.team_names[i], team_name) == 0)
      return (i);
  return (-1);
}

int	is_user_on_map(int fd)
{
  return (find_user(fd) ? 1 : 0);
}

int	__is_a_command(char *input)
{
  int	i;

  i = -1;
  while (++i < MAX_USER_CMD)
    if (strcmp(g_cmd_user_tab[i].name, input) == 0)
      return (1);
  return (0);
}

int	__is_graphic_welcome(char *input)
{
  return (strcmp(input, WELCOME_GRAPH_MSG) == 0);
}

int	__team_slot_available(int team_idx)
{
  return (g_avail_team_slot[team_idx] - 1 >= 0);
}

