/*
** check_levels.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Sun Jun 26 17:58:06 2016 Florian Videau
** Last update Sun Jun 26 18:03:09 2016 Florian Videau
*/

#include "types/userList.h"
#include "types/user.h"

int		check_levels(int level, t_userList *user)
{
  t_userList	*elem;

  if (user->user->level != level)
    return (0);
  elem = user->next;
  while (elem != user)
    {
      if (elem->user->level != level)
	return (0);
      elem = elem->next;
    }
  return (1);
}
