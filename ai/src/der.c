/*
** der.c for zappy in /home/biteau_j/rendu/tek2/PSU/PSU_2015_zappy/src
**
** Made by Jonathan BITEAU
** Login biteau_j <jonathan.biteau@epitech.eu>
**
** Started on  Jan Jun 26 03:32:09 2016 Jonathan BITEAU
** Last update Jan Jun 26 21:43:19 2016 Jonathan BITEAU
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

static void init_vars(t_client *cl, int *lin, int *der, t_inv **tmp)
{
  *lin = 0;
  *der = 0;
  *tmp = cl->inv;
}

static void search_for_elems(int *lin, int *der, int *sib, t_inv *tmp)
{
  while (tmp && tmp->next)
  {
    if (strcmp(tmp->name, "linemate") == 0 && tmp->nbr >= 1)
      *lin += 1;
    if (strcmp(tmp->name, "deraumere") == 0 && tmp->nbr >= 1)
      *der += 1;
    if (strcmp(tmp->name, "sibur") == 0 && tmp->nbr >= 1)
      *sib += 1;
    tmp = tmp->next;
  }
}

int der(t_client *cl)
{
  int lin;
  int der;
  int sib;
  t_inv *tmp;

  sib = 0;
  init_vars(cl, &lin, &der, &tmp);
  search_for_elems(&lin, &der, &sib, tmp);
  if (lin >= 1 && der >= 1 && sib >= 1 && cl->lvl == 2)
  {
    if (count_ress(str_to_wordtab(cl->seeing[0], ' '), "joueur") == 2)
    {
      if (count_ress(str_to_wordtab(cl->seeing[0], ' '), "linemate") == 0)
        cb_write(cl->buff, "pose linemate\n");
      if (count_ress(str_to_wordtab(cl->seeing[0], ' '), "deraumere") == 0)
        cb_write(cl->buff, "pose deraumere\n");
      if (count_ress(str_to_wordtab(cl->seeing[0], ' '), "sibur") == 0)
        cb_write(cl->buff, "pose sibur\n");
      cb_write(cl->buff, "incantation\n");
    }
    return (0);
  }
  return (-1);
}
