/*
** egg.h for zappy in /home/work/work/projects/PSU_2015_zappy_doc/PSU_2015_zappy/include
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Sat Jun 25 20:39:08 2016 Bastien DHIVER
** Last update Sun Jun 26 03:12:04 2016 Florian Videau
*/

#ifndef EGG_H_
# define EGG_H_

# include <stddef.h>

typedef struct	s_egg
{
  size_t	id;
  size_t	parent_id;
  long		x;
  long		y;
  _Bool		hatched;
  char		*team_name;
  void		(*delete)(struct s_egg *);
  int		(*spawn)(struct s_egg *, int);
}		t_egg;

t_egg		*init_egg(long, long, char *, size_t);

#endif /* !EGG_H_ */
