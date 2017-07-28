/*
** kick_client.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Wed Jun 15 18:07:28 2016 Florian Videau
** Last update Sat Jun 25 17:26:45 2016 Florian Videau
*/

#include <stddef.h>
#include <server.h>
#include "types/box.h"
#include "types/user.h"
#include "cmd_user_actions.h"

void		kick_client_from_fd(const int fd)
{
  t_userList	*user;
  long		x;
  long		y;

  if ((user = find_user(fd)))
    {
      x = user->user->x;
      y = user->user->y;
      g_map[y][x].users = user->delete(user);
      return ;
    }
}
