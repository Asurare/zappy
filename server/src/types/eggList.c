/*
** eggList.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src/types
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Sat Jun 25 21:40:01 2016 Florian Videau
** Last update Sun Jun 26 14:56:21 2016 Bastien DHIVER
*/

#include <stdlib.h>
#include "server.h"
#include "types/box.h"
#include "types/egg.h"
#include "msg.h"

static t_eggList	*delete_eggList(t_eggList *this)
{
  t_eggList		*tmp;

  tmp = (this->next == this ? NULL : this->next);
  this->prev->next = this->next;
  this->next->prev = this->prev;
  this->egg->delete(this->egg);
  free(this);
  return (tmp);
}

static void	append(t_eggList *this, t_eggList *to_append)
{
  to_append->next = this->next;
  to_append->prev = this;
  this->next->prev = to_append;
  this->next = to_append;
}

static void	put_in_map(t_eggList *this)
{
  long		x;
  long		y;

  x = this->egg->x;
  y = this->egg->y;
  if (!g_map[y][x].eggs)
    {
      g_map[y][x].eggs = this;
      this->prev = this;
      this->next = this;
    }
  else
    g_map[y][x].eggs->append(g_map[y][x].eggs, this);
}

t_eggList	*init_eggList(t_egg *egg)
{
  t_eggList	*eggList;

  if (!(eggList = malloc(sizeof(*eggList))))
    {
      print_err(ERR_MALLOC);
      exit(1);
    }
  eggList->egg = egg;
  eggList->prev = eggList;
  eggList->next = eggList;
  eggList->append = append;
  eggList->delete = delete_eggList;
  eggList->put_in_map = put_in_map;
  return (eggList);
}
