/*
** der.c for zappy in /home/biteau_j/rendu/tek2/PSU/PSU_2015_zappy/src
**
** Made by Jonathan BITEAU
** Login biteau_j <jonathan.biteau@epitech.eu>
**
** Started on  Jan Jun 26 03:32:09 2016 Jonathan BITEAU
** Last update Jan Jun 26 07:43:16 2016 Jonathan BITEAU
*/

# include "der.h"

int  get_level(char *str)
{
  int ct;

  ct = -1;
  while (str[++ct])
    if (isdigit(str[ct]) != 0)
      return (str[ct] - 48);
  return (1);
}

int  count_players(char **tab)
{
  int ct;
  int nbr;

  ct = -1;
  nbr = 0;
  while (tab[++ct])
    if (strcmp(tab[ct], "joueur") == 0)
      nbr += 1;
  return (nbr);
}

static int  count_ress(char **tab, char *ress)
{
  int ct;
  int nbr;

  ct = -1;
  nbr = 0;
  while (tab[++ct])
  {
    if (strcmp(tab[ct], ress) == 0)
      nbr += 1;
  }
  free(tab);
  return (nbr);
}

static void init_vars(t_client *cl, int *lin, int *der, t_inv **tmp)
{
  *lin = 0;
  *der = 0;
  *tmp = cl->inv;
}

int der(t_client *cl)
{
  int lin;
  int der;
  t_inv *tmp;

  init_vars(cl, &lin, &der, &tmp);
  while (tmp && tmp->next)
  {
    if (strcmp(tmp->name, "linemate") == 0 && tmp->nbr >= 1)
      lin += 1;
    if (strcmp(tmp->name, "deraumere") == 0 && tmp->nbr >= 1)
      der += 1;
    if (strcmp(tmp->name, "sibur") == 0 && tmp->nbr >= 1)
      der += 1;
    tmp = tmp->next;
  }
  if (lin >= 1 && der >= 1 && cl->lvl == 2 &&
    count_ress(str_to_wordtab(cl->seeing[0], ' '), "joueur") == 2)
  {
    cb_write(cl->buff, "pose linemate\n");
    cb_write(cl->buff, "pose deraumere\n");
    cb_write(cl->buff, "pose sibur\n");
    return (0);
  }
  return (-1);
}
