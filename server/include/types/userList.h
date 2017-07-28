/*
** userList.h for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Tue Jun 14 13:02:44 2016 Florian Videau
** Last update Sat Jun 25 17:49:02 2016 Florian Videau
*/

#ifndef USERLIST_H_
# define USERLIST_H_

typedef	struct s_box t_box;
typedef	struct s_user t_user;

typedef struct		s_userList
{
  t_user		*user;
  struct s_userList	*prev;
  struct s_userList	*next;
  void			(*append)(struct s_userList *, struct s_userList *);
  struct s_userList	*(*delete)(struct s_userList *);
  struct s_userList	*(*take_apart)(struct s_userList *);
  void			(*put_in_map)(struct s_userList *);
}			t_userList;

t_userList	*init_userList(t_user *user);

#endif /*!USERLIST_H_*/
