/*
** lin.c for zappy in /home/biteau_j/rendu/tek2/PSU/PSU_2015_zappy/src
**
** Made by Jonathan BITEAU
** Login biteau_j <jonathan.biteau@epitech.eu>
**
** Started on  Jul Jun 25 21:44:22 2016 Jonathan BITEAU
** Last update Jan Jun 26 03:55:41 2016 Jonathan BITEAU
*/

# include "lin.h"

int lin(t_client *cl)
{
  int cmp;
  t_inv *tmp;

  cmp = 0;
  tmp = cl->inv;
  while (tmp && tmp->next)
  {
    if (strcmp(tmp->name, "linemate") == 0 && tmp->nbr >= 1)
      cmp += 1;
    tmp = tmp->next;
  }
  if (cmp >= 1 && cl->lvl == 1)
  {
    cb_write(cl->buff, "pose linemate\n");
    cb_write(cl->buff, "incantation\n");
    return (0);
  }
  return (-1);
}
