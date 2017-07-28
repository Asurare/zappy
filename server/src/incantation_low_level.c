/*
** incantation_low_level.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Thu Jun 23 23:34:47 2016 Florian Videau
** Last update Sun Jun 26 18:05:32 2016 Florian Videau
*/

#include "server.h"
#include "cmd_user_actions.h"
#include "types/userList.h"
#include "types/user.h"

_Bool	incantation_level_1(t_userList *user)
{
  t_box box;

  box = g_map[user->user->y][user->user->x];
  return (get_nb_elem_in_userList(user) == 1 && check_levels(1, user)
	  &&box.ressources[LINEMATE] == 1
	  && !box.ressources[DERAUMERE] && !box.ressources[SIBUR]
	  && !box.ressources[MENDIANE] && !box.ressources[PHIRAS]
	  && !box.ressources[THYSTAME]);
}

_Bool	incantation_level_2(t_userList *user)
{
  t_box box;

  box = g_map[user->user->y][user->user->x];
  return (get_nb_elem_in_userList(user) == 2 && check_levels(2, user)
	  && box.ressources[LINEMATE] == 1
	  && box.ressources[DERAUMERE] == 1 && box.ressources[SIBUR] == 1
	  && !box.ressources[MENDIANE] && !box.ressources[PHIRAS]
	  && !box.ressources[THYSTAME]);
}

_Bool	incantation_level_3(t_userList *user)
{
  t_box box;

  box = g_map[user->user->y][user->user->x];
  return (get_nb_elem_in_userList(user) == 2 && check_levels(3, user)
	  && box.ressources[LINEMATE] == 2
	  && !box.ressources[DERAUMERE] && box.ressources[SIBUR] == 1
	  && !box.ressources[MENDIANE] && box.ressources[PHIRAS] == 2
	  && !box.ressources[THYSTAME]);
}

_Bool	incantation_level_4(t_userList *user)
{
  t_box box;

  box = g_map[user->user->y][user->user->x];
  return (get_nb_elem_in_userList(user) == 4 && check_levels(4, user)
	  && box.ressources[LINEMATE] == 1
	  && box.ressources[DERAUMERE] == 1 && box.ressources[SIBUR] == 2
	  && !box.ressources[MENDIANE] && box.ressources[PHIRAS] == 1
	  && !box.ressources[THYSTAME]);
}
