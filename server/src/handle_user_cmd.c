/*
** handle_user_cmd.c for zappy in /home/work/work/projects/PSU_2015_zappy_doc/PSU_2015_zappy/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Wed Jun 15 18:15:14 2016 Bastien DHIVER
** Last update Sun Jun 26 20:41:52 2016 Bastien DHIVER
*/

#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include "server.h"
#include "network.h"
#include "cmd_user.h"
#include "cmd_user_init.h"
#include "send_msg.h"
#include "msg.h"
#include "cmd_user_actions.h"
#include "types/user.h"
#include "types/box.h"
#include "graphics.h"

t_user_args	*generate_t_user_args(int client_fd, char **cmd)
{
  t_user_args	*args;

  if ((args = malloc(sizeof(*args))) == NULL)
    {
      print_err(ERR_MALLOC);
      exit(1);
    }
  args->client_fd = client_fd;
  args->cmd = cmd;
  args->ft_p = NULL;
  return (args);
}

int		exec_given_command(int client_fd, char **cmd)
{
  int		i;
  t_user_args	*args;

  if ((args = generate_t_user_args(client_fd, cmd)) == NULL)
    return (1);
  i = -1;
  while (++i < MAX_USER_CMD)
    if (strcmp(g_cmd_user_tab[i].name, cmd[0]) == 0)
      return (g_cmd_user_tab[i].ft_p(args));
  free_t_user_args_struct(args);
  return (0);
}

int	look_for_right_action_part_two(int client_fd, char **cmd)
{
  int	team_idx;

  if (__is_a_command(cmd[0]))
    return (__ko_kick_user(client_fd, cmd), 0);
  else
    {
      if ((team_idx = is_team_name(cmd[0])) != -1)
	{
	  if (__team_slot_available(team_idx))
	    {
	      __add_new_client(client_fd, cmd[0], team_idx);
	      return (free_user_split_cmd(cmd), 0);
	    }
	}
      else
	if (__is_graphic_welcome(cmd[0]))
	  {
	    add_new_graph_client(client_fd);
	    return (free_user_split_cmd(cmd), 0);
	  }
      return (__ko_kick_user(client_fd, cmd), 0);
    }
  return (0);
}

int	look_for_right_action(int client_fd, char **cmd)
{
  assert(cmd[0]);
  if (is_user_on_map(client_fd))
    {
      if (__is_a_command(cmd[0]))
	return (exec_given_command(client_fd, cmd));
      else
	return (__ko_msg(client_fd, cmd), 0);
    }
  else
    look_for_right_action_part_two(client_fd, cmd);
  return (0);
}

int	execute_client_cmds(int client_fd, char *input)
{
  char	**cmds;
  int	i;
  char	**cmd_split;
  char	*tmp;

  if ((cmds = str_split(input, "\n")) == NULL)
    return (1);
  i = -1;
  while (cmds[++i])
    {
      tmp = strdup(cmds[i]);
      printf("Receiving : '%s' from fd %d\n", tmp, client_fd);
      if (((cmd_split = str_split(tmp, " ")) == NULL)
	  || look_for_right_action(client_fd, cmd_split))
	return (1);
    }
  free(input);
  free(cmds);
  return (0);
}
