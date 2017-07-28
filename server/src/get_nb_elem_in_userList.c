/*
** get_nb_elem_in_userList.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Fri Jun 24 00:06:43 2016 Florian Videau
** Last update Sat Jun 25 00:16:17 2016 Florian Videau
*/

#include "types/userList.h"

int		get_nb_elem_in_userList(t_userList *actual)
{
  int		i;
  t_userList	*elem;

  i = 1;
  if (!actual)
    return (0);
  elem = actual->next;
  while (elem != actual)
    {
      i++;
      elem = elem->next;
    }
  return (i);
}
