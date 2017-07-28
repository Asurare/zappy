/*
** init_map.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Wed Jun 15 10:29:08 2016 Florian Videau
** Last update Sun Jun 26 15:48:55 2016 Florian Videau
*/

#include <stdlib.h>
#include "server.h"
#include "msg.h"
#include "types/box.h"
#include "types/user.h"
#include "types/eggList.h"
#include "graphics.h"

void		add_user_on_map(int client_fd, char *team_name)
{
  t_userList	*user;
  char		*glob_team_name;
  t_eggList	*egg;

  if ((egg = find_egg(team_name)))
    {
      egg->egg->spawn(egg->egg, client_fd);
      return ;
    }
    glob_team_name = get_team_name_glob_ptr(team_name);
    user = init_userList(init_user(client_fd, glob_team_name));
    user->put_in_map(user);
    send_all_graph_p(user->user, NULL, my_pnw);
}

void	free_map(void)
{
  long	i;
  long	j;

  i = -1;
  while (g_map[++i])
    {
      j = -1;
      while (++j < g_args.x)
	{
	  while (g_map[i][j].users
		 && (g_map[i][j].users
		     = g_map[i][j].users->delete(g_map[i][j].users)));
	  while (g_map[i][j].eggs
		 && (g_map[i][j].eggs
		     = g_map[i][j].eggs->delete(g_map[i][j].eggs)));
	}
      free(g_map[i]);
    }
  free(g_map);
}

static void	free_partially_allocated_map(const int end)
{
  int		i;
  int		j;

  i = -1;
  while (++i != end)
    {
      j = -1;
      while (++j < g_args.x)
	g_map[i][j].delete(&g_map[i][j]);
      free(g_map[i]);
    }
  free(g_map);
}

void	init_map(void)
{
  int	i;
  int	j;

  if (!(g_map = malloc((g_args.y + 1) * sizeof(*g_map))))
    {
      print_err(ERR_MALLOC);
      exit(1);
    }
  i = -1;
  while (++i < g_args.y)
    {
      if (!(g_map[i] = malloc((g_args.x) * sizeof(*g_map[i]))))
	{
	  print_err(ERR_MALLOC);
	  free_partially_allocated_map(i);
	  exit(1);
	}
      j = -1;
      while (++j < g_args.x)
	init_box(g_map[i] + j);
    }
  g_map[i] = NULL;
}
