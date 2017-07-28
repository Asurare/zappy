/*
** user.h for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/include/types
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Tue Jun 14 12:40:48 2016 Florian Videau
** Last update Sun Jun 26 01:04:59 2016 Florian Videau
*/

#ifndef USER_H_
# define USER_H_

# include <stddef.h>
# include "orientation.h"
# include "ressources.h"

struct	s_user
{
  int		fd;
  size_t	id;
  char		*team_name;
  int		level;
  int		inventory[MAX_RESS];
  int		life;
  long		x;
  long		y;
  t_orientation	orientation;
  void		(*delete)(struct s_user *);
};

t_user		*init_user(int, char *);

#endif /*!USER_H_*/
