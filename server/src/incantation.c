/*
** incantation.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Thu Jun 23 22:58:04 2016 Florian Videau
** Last update Sun Jun 26 18:08:30 2016 Florian Videau
*/

#include "incantation.h"
#include "types/levels.h"
#include "types/user.h"
#include "cmd_user.h"
#include "cmd_user_actions.h"

int		incantation(int fd)
{
  t_userList	*user;
  _Bool		(*incantation_possible[LEVEL_MAX])(t_userList *);

  user = find_user(fd);
  incantation_possible[LEVEL_1] = incantation_level_1;
  incantation_possible[LEVEL_2] = incantation_level_2;
  incantation_possible[LEVEL_3] = incantation_level_3;
  incantation_possible[LEVEL_4] = incantation_level_4;
  incantation_possible[LEVEL_5] = incantation_level_5;
  incantation_possible[LEVEL_6] = incantation_level_6;
  incantation_possible[LEVEL_7] = incantation_level_7;
  return (incantation_possible[user->user->level - 1](user)
	  ? user->user->level + 1 : 0);
}
