/*
** find_user.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Fri Jun 17 15:41:33 2016 Florian Videau
** Last update Sun Jun 26 05:46:50 2016 Florian Videau
*/

#include <stddef.h>
#include "server.h"
#include "types/box.h"
#include "types/user.h"
#include "types/vector.h"

static t_userList	*is_user_here(const size_t id, t_userList *userList)
{
  t_userList		*tmp;
  int			i;

  tmp = userList;
  i = 0;
  while (tmp && (tmp != userList || i == 0))
    {
      i = 1;
      if (tmp->user->id == id)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

t_userList	*find_user_from_id(const size_t id)
{
  t_userList	*ret;
  long		i;
  long		j;

  i = -1;
  while (g_map[++i])
    {
      j = -1;
      while (++j < g_args.x)
	if ((ret = is_user_here(id, g_map[i][j].users)))
	  return (ret);
    }
  return (NULL);
}
