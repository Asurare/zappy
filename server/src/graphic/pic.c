/*
** pic.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src/graphic
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Sat Jun 25 01:24:35 2016 Florian Videau
** Last update Sun Jun 26 18:46:47 2016 Florian Videau
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cmd_user.h"
#include "cmd_user_actions.h"
#include "graphics.h"
#include "send_msg.h"

static char	*wordtab_to_str(char **tab, int tablen)
{
  int		len;
  char		*str;
  int		i;

  len = 0;
  i = -1;
  while (++i < tablen)
    len += strlen(tab[i]);
  if (!(str = calloc(len + 1, 1)))
    return (NULL);
  i = -1;
  len = 0;
  while (++i < tablen)
    {
      strcat(str + len, tab[i]);
      len += strlen(tab[i]);
      free(tab[i]);
    }
  return (str);
}

int	my_pic(S_CMD_GRAPH_P_ARGS)
{
  t_userList	*elem;
  char	*ids[get_nb_elem_in_userList(more)];
  char	*ids_str;
  int	nb_ids;
  int	i;

  elem = more;
  nb_ids = get_nb_elem_in_userList(more);
  i = -1;
  while (++i < nb_ids)
    {
      asprintf(&ids[i], " %ld", elem->user->id);
      elem = elem->next;
    }
  if (!(ids_str = wordtab_to_str(ids, nb_ids)))
    return (-1);
  send_msg(client_fd, "pic %ld %ld %d%s\n", player->x, player->y,
	   player->level, ids_str);
  free(ids_str);
  return (0);
}
