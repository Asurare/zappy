/*
** inv_and_see.c for zappy in /home/biteau_j/rendu/tek2/PSU/PSU_2015_zappy/src
**
** Made by Jonathan BITEAU
** Login biteau_j <jonathan.biteau@epitech.eu>
**
** Started on  May Jun 23 13:38:39 2016 Jonathan BITEAU
** Last update Jul Jun 25 22:06:12 2016 Jonathan BITEAU
*/

# include "inv_and_see.h"

static t_inv *reset_inventory(t_client *cl, t_inv *tmp)
{
  while (cl->inv)
  {
    tmp = cl->inv;
    cl->inv = cl->inv->next;
    free (tmp);
  }
  if (!(cl->inv = malloc(sizeof(t_inv))))
    return (NULL);
  tmp = cl->inv;
  return (tmp);
}

static void fill_inventory(t_client *cl, char **params)
{
  int ct;
  char  **tab;
  t_inv *tmp;

  ct = -1;
  tmp = NULL;
  if ((tmp = reset_inventory(cl, tmp)) == NULL)
    return;
  while (params[++ct])
  {
    tab = str_to_wordtab(params[ct], ' ');
    bzero(tmp->name, sizeof(tmp->name));
    strcpy(tmp->name, tab[0]);
    if (tab_size(tab) >= 1)
      tmp->nbr = atoi(tab[1]);
    free_tab(tab);
    if (!(tmp->next = malloc(sizeof(t_inv))))
      return;
    tmp = tmp->next;
  }
  tmp->next = NULL;
  free_tab(params);
}

void get_inv_or_see(t_client *cl, char *cmds)
{
  int ct;

  ct = -1;
  cl->size_seen = 0;
  if (find_nbr(cmds) == 1)
    fill_inventory(cl, get_params(cmds));
  else
  {
    if (cl->seeing != NULL)
      free_tab(cl->seeing);
    cl->seeing = get_params(cmds);
  }
  while (cl->seeing[++ct])
    cl->size_seen += 1;
}
