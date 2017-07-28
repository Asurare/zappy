/*
** egg.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src/types
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Sat Jun 25 20:47:31 2016 Florian Videau
** Last update Sun Jun 26 14:52:04 2016 Bastien DHIVER
*/

#include <stdlib.h>
#include "server.h"
#include "graphics.h"
#include "types/egg.h"
#include "types/userList.h"
#include "types/user.h"
#include "msg.h"

static void	delete_egg(t_egg *this)
{
  free(this);
}

static int	spawn_player(t_egg *this, int fd)
{
  t_userList	*user;

  if (!this->hatched)
    return (0);
  user = init_userList(init_user(fd, this->team_name));
  user->user->x = this->x;
  user->user->y = this->y;
  user->put_in_map(user);
  send_all_graph_e(this, my_ebo);
  send_all_graph_p(user->user, NULL, my_pnw);
  return (1);
}

t_egg		*init_egg(long x, long y, char *team_name, size_t parent_id)
{
  static size_t	id = 0;
  t_egg		*egg;

  if (!(egg = malloc(sizeof(*egg))))
    {
      print_err(ERR_MALLOC);
      exit(1);
    }
  egg->id = id++;
  egg->parent_id = parent_id;
  egg->x = x;
  egg->y = y;
  egg->hatched = 0;
  egg->team_name = team_name;
  egg->delete = delete_egg;
  egg->spawn = spawn_player;
  return (egg);
}
