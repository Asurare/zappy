/*
** box.h for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/include/types
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Tue Jun 14 14:10:31 2016 Florian Videau
** Last update Sat Jun 25 22:43:41 2016 Florian Videau
*/

#ifndef BOX_H_
# define BOX_H_

# include "ressources.h"
# include "eggList.h"
# include "userList.h"

struct			s_box
{
  int			ressources[MAX_RESS];
  t_userList		*users;
  t_eggList		*eggs;
  char			*(*get_content)(struct s_box *);
  void			(*delete)(struct s_box *);
};

t_box			*init_box(t_box *box);

void			init_map(void);
void			free_map(void);

void			add_user_on_map(int, char *);

void			kick_client_from_fd(const int);

#endif /* !BOX_H_ */
