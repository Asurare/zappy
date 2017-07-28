/*
** userList.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src/types
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Tue Jun 14 17:35:52 2016 Florian Videau
** Last update Sun Jun 26 14:58:50 2016 Bastien DHIVER
*/

#include <stdlib.h>
#include "server.h"
#include "types/box.h"
#include "types/user.h"
#include "msg.h"

static t_userList	*delete_userList(t_userList *this)
{
  t_userList		*tmp;

  tmp = (this->next == this ? NULL : this->next);
  this->prev->next = this->next;
  this->next->prev = this->prev;
  this->user->delete(this->user);
  free(this);
  return (tmp);
}

static void	append(t_userList *this, t_userList *to_append)
{
  to_append->next = this->next;
  to_append->prev = this;
  this->next->prev = to_append;
  this->next = to_append;
}

static t_userList	*take_apart(t_userList *this)
{
  if (this->next == this)
    return (NULL);
  this->prev->next = this->next;
  this->next->prev = this->prev;
  return (this->next);
}

static void	put_in_map(t_userList *this)
{
  long		x;
  long		y;

  x = this->user->x;
  y = this->user->y;
  if (!g_map[y][x].users)
    {
      g_map[y][x].users = this;
      this->prev = this;
      this->next = this;
    }
  else
    g_map[y][x].users->append(g_map[y][x].users, this);
}

t_userList	*init_userList(t_user *user)
{
  t_userList	*userList;

  if (!(userList = malloc(sizeof(*userList))))
    {
      print_err(ERR_MALLOC);
      exit(1);
    }
  userList->user = user;
  userList->prev = userList;
  userList->next = userList;
  userList->append = append;
  userList->delete = delete_userList;
  userList->take_apart = take_apart;
  userList->put_in_map = put_in_map;
  return (userList);
}
