/*
** find_team.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Thu Jun 23 17:40:51 2016 Florian Videau
** Last update Thu Jun 23 23:25:42 2016 Bastien DHIVER
*/

#include <unistd.h>
#include <string.h>
#include "cmd_user.h"
#include "cmd_user_actions.h"
#include "types/userList.h"
#include "types/user.h"
#include "server.h"

char		*get_team_name_glob_ptr(char *team_name)
{
  ssize_t	i;

  i = -1;
  while (g_args.team_names[++i])
    if (strcmp(g_args.team_names[i], team_name) == 0)
      return (g_args.team_names[i]);
  return (NULL);
}

ssize_t		get_team_idx_from_fd(int fd)
{
  t_userList	*user;
  ssize_t	i;

  i = -1;
  if (!(user = find_user(fd)))
    return (i);
  while (g_args.team_names[++i])
    if (strcmp(g_args.team_names[i], user->user->team_name) == 0)
      return (i);
  return (-1);
}
