/*
** eggList.h for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/include/types
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Sat Jun 25 21:31:26 2016 Florian Videau
** Last update Sun Jun 26 13:25:45 2016 Florian Videau
*/

#ifndef EGGLIST_H_
# define EGGLIST_H_

#include "egg.h"

typedef struct		s_eggList
{
  struct s_eggList	*prev;
  struct s_eggList	*next;
  t_egg			*egg;
  void			(*append)(struct s_eggList *, struct s_eggList *);
  struct s_eggList	*(*delete)(struct s_eggList *);
  void			(*put_in_map)(struct s_eggList *);
}			t_eggList;

t_eggList		*init_eggList(t_egg *);
t_eggList		*find_egg(const char *);
t_eggList		*find_egg_from_id(const size_t);

#endif /*!EGGLIST_H_*/
