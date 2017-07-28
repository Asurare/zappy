/*
** box.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src/types
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Tue Jun 14 18:26:52 2016 Florian Videau
** Last update Sat Jun 25 21:36:28 2016 Florian Videau
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cmd_user.h"
#include "cmd_user_actions.h"
#include "types/box.h"

static void	init_box_ressources(t_box *box)
{
  int		i;

  i = -1;
  while (++i < MAX_RESS)
    box->ressources[i] = rand() % MAX_RESS_ON_BOX;
}

static void	delete_box(t_box *this)
{
  while (this->users && this->users->delete(this->users));
  this->users = NULL;
}

static char	*get_ress(int nb, char *str)
{
  char		*ressources;
  int		i;

  ressources = calloc((strlen(str) * nb) + 1, 1);
  i = -1;
  while (++i < nb)
    strcat(ressources + (i * strlen(str)), str);
  return (ressources);
}

static char	*get_content(t_box *this)
{
  char		*contents[MAX_RESS + 1];
  char		*content;
  int		i;

  contents[MAX_RESS] = get_ress(get_nb_elem_in_userList(this->users),
				"joueur ");
  contents[NOURRITURE] = get_ress(this->ressources[NOURRITURE],
				  "nourriture ");
  contents[LINEMATE] = get_ress(this->ressources[LINEMATE], "linemate ");
  contents[DERAUMERE] = get_ress(this->ressources[DERAUMERE], "deraumere ");
  contents[SIBUR] = get_ress(this->ressources[SIBUR], "sibur ");
  contents[MENDIANE] = get_ress(this->ressources[MENDIANE], "mendiane ");
  contents[PHIRAS] = get_ress(this->ressources[PHIRAS], "phiras ");
  contents[THYSTAME] = get_ress(this->ressources[THYSTAME], "thystame ");
  asprintf(&content, " %s%s%s%s%s%s%s%s", contents[MAX_RESS],
	   contents[NOURRITURE], contents[LINEMATE],
	   contents[DERAUMERE], contents[SIBUR],
	   contents[MENDIANE], contents[PHIRAS],
	   contents[THYSTAME]);
  content[strlen(content) - 1] = 0;
  i = -1;
  while (++i < MAX_RESS + 1)
    free(contents[i]);
  return (content);
}

t_box	*init_box(t_box *box)
{
  init_box_ressources(box);
  box->eggs = NULL;
  box->users = NULL;
  box->get_content = get_content;
  box->delete = delete_box;
  return (box);
}
