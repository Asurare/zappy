/*
** user.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src/types
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Tue Jun 14 16:06:24 2016 Florian Videau
** Last update Sun Jun 26 14:57:02 2016 Bastien DHIVER
*/

#include <stdlib.h>
#include <strings.h>
#include <sys/socket.h>
#include <unistd.h>
#include "types/ressources.h"
#include "server.h"
#include "types/user.h"
#include "types/userList.h"
#include "msg.h"

static	void	delete_user(t_user *this)
{
  shutdown(this->fd, SHUT_RDWR);
  close(this->fd);
  free(this);
}

t_user		*init_user(int fd, char *team_name)
{
  static size_t	max_id = 1;
  t_user	*user;

  if (!(user = malloc(sizeof(*user))))
    {
      print_err(ERR_MALLOC);
      exit(1);
    }
  user->fd = fd;
  user->id = max_id++;
  user->team_name = team_name;
  user->level = 1;
  bzero(user->inventory, MAX_RESS  * sizeof(*user->inventory));
  user->inventory[NOURRITURE] = 10;
  user->x = rand() % g_args.x;
  user->y = rand() % g_args.y;
  user->orientation = rand() % MAX_ORIENTATION;
  user->delete = delete_user;
  return (user);
}
