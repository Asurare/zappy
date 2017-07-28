/*
** say_hi.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src/graphic
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Sun Jun 26 00:33:05 2016 Florian Videau
** Last update Sun Jun 26 03:24:57 2016 Florian Videau
*/

#include <stdio.h>
#include "graphics.h"
#include "server.h"

static void	aff_userList(int fd, t_userList *users)
{
  t_userList	*elem;

  elem = users->next;
  while (elem != users)
    {
      my_pnw(fd, elem->user, NULL);
      elem = elem->next;
    }
  my_pnw(fd, elem->user, NULL);
}

static void	aff_players(int fd)
{
  long		x;
  long		y;

  y = -1;
  while (++y < g_args.y && (x = -1))
    while (++x < g_args.x)
      if (g_map[y][x].users)
	aff_userList(fd, g_map[y][x].users);
}

static void	aff_eggList(int fd, t_eggList *eggs)
{
  t_eggList	*elem;

  elem = eggs->next;
  while (elem != eggs)
    {
      my_enw(fd, elem->egg);
      elem = elem->next;
    }
  my_enw(fd, elem->egg);
}

static void	aff_eggs(int fd)
{
  long		x;
  long		y;

  y = -1;
  while (++y < g_args.y && (x = -1))
    while (++x < g_args.x)
      if (g_map[y][x].eggs)
	aff_eggList(fd, g_map[y][x].eggs);
}

void	say_hi_to_graph_client(int fd)
{
  my_msz(fd);
  my_sgt(fd);
  my_mct(fd);
  my_tna(fd);
  aff_players(fd);
  aff_eggs(fd);
}
