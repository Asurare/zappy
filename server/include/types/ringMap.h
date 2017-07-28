/*
** ringMap.h for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/include/types
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Tue Jun 14 15:44:05 2016 Florian Videau
** Last update Tue Jun 14 15:58:18 2016 Florian Videau
*/

#ifndef RINGMAP_H_
# define RINGMAP_H_

# include "box.h"

typedef struct	s_ringMap
{
  t_box		*box;
  void		(*broadcast) (struct s_ringMap **, int, int, char *);
}		t_ringMap;

#endif /*!RINGMAP_H_*/
